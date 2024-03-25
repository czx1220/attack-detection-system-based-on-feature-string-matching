#include "choose_patternfile.h"
#include "ui_choose_patternfile.h"

#include "show_detection.h"
#include "ui_show_detection.h"

#include "wait.h"
#include "ui_wait.h"

#include <queue>


Attackpattern* pPatternHeader = NULL;
ACNode* root = NULL;
int maxpattern_len = 0;
Node* typeofattack = NULL;


extern int level;
show_detection* detection = NULL;


// 查找节点函数，输入是一个指向链表头部的指针head和一个类别category，返回一个指向该类别对应节点的指针。
char* find_attackcontent(Node* const head, int category) {
	Node* current = head;
	for (int i = 0; i < category; i++) {
		current = current->next;
	}
	return current->attackcontent;
}


// 通过attackcontent反推category的函数，输入是一个指向链表头部的指针head和一个特征串attackcontent，返回该特征串对应的类别。
int find_category(Node* const head, const char* const attackcontent) {
	Node* current = head;
	while (current != NULL) {
		if (strcmp(current->attackcontent, attackcontent) == 0) {
			return current->category;
		}
		current = current->next;
	}
	return -1;
}


// 插入一个模式串到Trie树的函数，输入是一个字符串、字符串长度len和攻击类别attackdes。
void insert(const char* const pattern, int len, const char* const attackdes) {
	// 从根节点开始
	ACNode* p = root;
	// 使用传入的长度，而不是调用strlen函数
	for (int i = 0; i < len; i++) {
		// 计算当前字符对应的索引
		int index = pattern[i] + 128;
		// 如果没有对应的子节点，创建一个新节点
		if (p->children[index] == NULL) {
			ACNode* new_node = new ACNode;
			for (int i = 0; i < 256; i++)
				new_node->children[i] = new ACNode;
			p->children[index] = new_node;
		}
		// 移动到子节点
		p = p->children[index];
	}
	// 标记模式串的结尾
	p->isEnd = find_category(typeofattack, attackdes);
}


// 构造失配指针的函数，无输入
void construct_fail() {
	// 使用一个队列来进行广度优先遍历
	// Queue *q = init_queue(); // 初始化一个空队列
	// 根节点的失配指针指向自己

	std::queue<ACNode*> q;
	root->fail = root;
	// 将根节点的所有非空子节点入队，并将它们的失配指针指向根节点
	for (int i = 0; i < 256; i++) {
		if (root->children[i]) {
			root->children[i]->fail = root;
			q.push(root->children[i]);
		}
	}
	// 当队列不为空时，循环以下操作
	while (!q.empty()) {
		// 出队头部节点，记为u
		//ACNode *u = dequeue(q);
		ACNode* u = q.front();
		q.pop();
		// 遍历u的所有非空子节点，记为v
		for (int i = 0; i < 256; i++) {
			if (u->children[i]) {
				ACNode* v = u->children[i];
				// 从u的失配指针开始，沿着失配指针回溯，直到找到一个节点w，使得w有一个与v相同字符的子节点x，或者回溯到根节点
				ACNode* w = u->fail;
				while (w != root && w->children[i] == NULL) {
					w = w->fail;
				}
				// 如果找到了这样的节点w，那么将v的失配指针指向x；否则，将v的失配指针指向根节点
				if (w->children[i]) {
					v->fail = w->children[i];
				}
				else {
					v->fail = root;
				}
				// 将v入队，继续遍历
				q.push(v);
			}
		}
	}
}


// 链表增加节点函数
void add_node(Node* const head, int category, const char* const attackcontent) {
	Node* current = head;
	while (current->next != NULL) {
		current = current->next;
	}

	current->next = new Node;
	current = current->next;
	current->category = category;
	bzero(current->attackcontent, 256);
	strcpy(current->attackcontent, attackcontent);
}


// 构建AC树，读入文件
int build_AC(const char* const patternfile) {

	root = new ACNode; // 创建 AC 自动机的根节点

	for (int i = 0; i < 256; i++) // 为根节点的每个子节点创建一个新的 AC 节点
		root->children[i] = new ACNode;

	FILE* file;
	char linebuffer[256], attackdes[256], patterncontent[256];
	int count = 1, patternlen = 0;
	file = fopen(patternfile, "r"); // 打开特征文件
	if (file == NULL) {
		return 1;
	}
	bzero(linebuffer, 256); // 清空行缓冲区
	maxpattern_len = 0; // 初始化最大模式长度为 0
	while (fgets(linebuffer, 255, file)) { // 逐行读取文件内容
		int deslen;
		char* pchar;
		pchar = strchr(linebuffer, '#'); // 在行缓冲区中查找井号，获取攻击模式的类别
		if (pchar == NULL) // 如果井号不存在，则跳过该行
			continue;
		deslen = pchar - linebuffer; // 特征串类别长度
		patternlen = strlen(linebuffer) - deslen - 1 - 1; // 获取攻击模式的长度
		pchar++;

		bzero(attackdes, 256); // 清空攻击模式类别缓冲区
		strncpy(attackdes, linebuffer, deslen); // 复制攻击模式类别到缓冲区
		bzero(patterncontent, 256); // 清空攻击模式内容缓冲区
		strncpy(patterncontent, pchar, patternlen); // 复制攻击模式内容到缓冲区

		if (find_category(typeofattack, attackdes) == -1) // 如果攻击模式类别不存在，则在 AC 自动机中添加一个新节点
		{
			add_node(typeofattack, count, attackdes);
			count = count + 1;

		}

		if (patternlen > maxpattern_len)
			maxpattern_len = patternlen; // 更新最大模式长度

		insert(patterncontent, patternlen, attackdes); // 插入攻击模式到 AC 自动机中

		bzero(linebuffer, 256); // 清空行缓冲区
	}

	fclose(file); // 关闭文件

	if (count == 1) // 如果 AC 自动机中只有根节点，则返回 1
		return 1;

	construct_fail(); // 构建 AC 自动机的失败指针

	return 0; // 返回 0 表示 AC 自动机构建成功
}





int readpattern_2_3(const char* const patternfile) {
	FILE* file;
	char linebuffer[256];
	file = fopen(patternfile, "r");
	if (file == NULL) {
		return 1;
	}
	bzero(linebuffer, 256);
	pPatternHeader = NULL;
	maxpattern_len = 0;
	int patternlen;

	while (fgets(linebuffer, 255, file)) {
		Attackpattern* pOnepattern; // 创建一个新的攻击模式节点
		int deslen;
		char* pchar;
		pchar = strchr(linebuffer, '#');
		if (pchar == NULL)
			continue;

		pOnepattern = new Attackpattern; // 为新攻击模式节点分配内存
		deslen = pchar - linebuffer; // 特征串类别长度
		patternlen = strlen(linebuffer) - deslen - 1 - 1;
		pchar++;

		bzero(pOnepattern->attackdes, 256);
		strncpy(pOnepattern->attackdes, linebuffer, deslen);
		bzero(pOnepattern->patterncontent, 256);
		strncpy(pOnepattern->patterncontent, pchar, patternlen);

		if (patternlen > maxpattern_len)
			maxpattern_len = patternlen;

		pOnepattern->next = NULL; // 新攻击模式节点的下一个指针设为空
		if (pPatternHeader == NULL) // 如果攻击模式链表为空，则将新节点设置为链表头
			pPatternHeader = pOnepattern;
		else { // 否则，将新节点添加到链表头
			pOnepattern->next = pPatternHeader;
			pPatternHeader = pOnepattern;
		}
		bzero(linebuffer, 256);
	}

	fclose(file);

	if (pPatternHeader == NULL)
		return 1;

	return 0;
}


// 链表构建函数
Node* create_list(int category, const char* const attackcontent) {
	Node* head = new Node;
	head->category = category;
	strcpy(head->attackcontent, attackcontent);
	head->next = NULL;
	return head;
}


choose_patternfile::choose_patternfile(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::choose_patternfile)
{
	ui->setupUi(this);
	setAutoFillBackground(true);
	QPalette palette = this->palette();
	palette.setBrush(QPalette::Window,
		QBrush(QPixmap(":/new/prefix1/project_resource/picture2.jpg").scaled(    // 缩放背景图.
			this->size(),
			Qt::IgnoreAspectRatio,
			Qt::SmoothTransformation)));    // 使用平滑的缩放方式
	this->setPalette(palette);
	connect(ui->patternfilelineEdit, SIGNAL(returnPressed()), this, SLOT(on_confirmbutton_clicked()));
}


choose_patternfile::~choose_patternfile()
{
	delete ui;
}


void choose_patternfile::on_cancelbutton_clicked()
{
	Widget* w = new Widget;
	w->show();
	this->close();
}


void choose_patternfile::on_confirmbutton_clicked()
{
	FILE* file;
	char patternfile[256];
	QString program = ui->patternfilelineEdit->text();
	bzero(patternfile, 256);
	QByteArray tmp = program.toUtf8();
	const char* charData = tmp.constData();
	qstrncpy(patternfile, charData, 255); // 从用户输入获取特征文件名
	file = fopen(patternfile, "r");
	if (file == NULL) {
		QMessageBox::information(this, tr("Information"), tr("Cannot open the file！"));
	}
	else {
		fclose(file);
		wait* test = new wait;
		test->show();

		QApplication::processEvents();
		//根据Level选择读入文件方式
		if (level == 1) {
			typeofattack = create_list(0, const_cast<char*>("list_head"));
			build_AC(patternfile);
		}
		else {
			readpattern_2_3(patternfile);
		}


		test->close();
		delete test;

		detection = new show_detection;
		detection->show();

		this->close();
	}
}
