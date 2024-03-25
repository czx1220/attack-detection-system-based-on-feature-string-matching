#include "show_detection.h"
#include "ui_show_detection.h"

#include "choose_patternfile.h"
#include "ui_choose_patternfile.h"


extern show_detection* detection;
extern int level;
extern Node* typeofattack;
extern ACNode* root;
extern int maxpattern_len;
extern Attackpattern* pPatternHeader;


void workThread::run()
{
	nids_run();
}



show_detection::show_detection(QWidget* parent) :
	QWidget(parent),
	ui(new Ui::show_detection),
	flag(1)
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
	ui->detection_output->setColumnWidth(0, 201);
	ui->detection_output->setColumnWidth(1, 210);
	ui->detection_output->setColumnWidth(2, 210);

}

show_detection::~show_detection()
{
	delete ui;
}


// 求三个数最小值
int min(int x, int y, int z) {
	int m = x;
	if (m > y) m = y;
	if (m > z) m = z;
	return m;
}



// Level1 输出函数，用于在GUI界面的检测输出中展示检测到的攻击
void output_alert_1(int category, const struct tcp_stream* const tcp_connection, int direction) {
	struct in_addr addr_1, addr_2;
	QTreeWidgetItem* item = new QTreeWidgetItem(detection->ui->detection_output); // 创建一个新的QTreeWidgetItem，添加到检测输出界面的输出列表中
	QFont font("Jamrul", 15);
	item->setFont(0, font); // 将第0列的字体设置为Arial 12号字体
	item->setFont(1, font); // 将第1列的字体设置为Arial 12号字体
	item->setFont(2, font); // 将第1列的字体设置为Arial 12号字体
	item->setText(0, find_attackcontent(typeofattack, category)); // 在第0列中显示攻击类型
	if (direction == 1) {
		// 如果是服务器向客户端的流量，分别在第1列和第2列中显示源IP和目的IP
		addr_1.s_addr = (tcp_connection->addr).saddr;
		item->setText(1, inet_ntoa(addr_1));
		addr_2.s_addr = (tcp_connection->addr).daddr;
		item->setText(2, inet_ntoa(addr_2));
	}
	else {
		// 如果是客户端向服务器的流量，分别在第1列和第2列中显示目的IP和源IP
		addr_2.s_addr = (tcp_connection->addr).daddr;
		item->setText(1, inet_ntoa(addr_2));
		addr_1.s_addr = (tcp_connection->addr).saddr;
		item->setText(2, inet_ntoa(addr_1));
	}
}


// Level2、3输出函数，用于在GUI界面的检测输出中展示检测到的攻击
void output_alert_2_3(const Attackpattern* const pOnepattern, const struct tcp_stream* const tcp_connection, int direction) {
	struct in_addr addr_1, addr_2;
	QTreeWidgetItem* item = new QTreeWidgetItem(detection->ui->detection_output);
	QFont font("Jamrul", 15);
	item->setFont(0, font);
	item->setFont(1, font);
	item->setFont(2, font);
	item->setText(0, pOnepattern->attackdes);
	if (direction == 1) {
		addr_1.s_addr = (tcp_connection->addr).saddr;
		item->setText(1, inet_ntoa(addr_1));
		addr_2.s_addr = (tcp_connection->addr).daddr;
		item->setText(2, QString::fromUtf8(inet_ntoa(addr_2)));
	}
	else {
		addr_2.s_addr = (tcp_connection->addr).daddr;
		item->setText(1, QString::fromUtf8(inet_ntoa(addr_2)));
		addr_1.s_addr = (tcp_connection->addr).saddr;
		item->setText(2, inet_ntoa(addr_1));
	}
}




//一个字符串通过增添、替换、删除变成另一个字符串所需最少步数
int stringDistance(const char* const str1, const char* const str2) {
	int len1 = strlen(str1); // 获取字符串1的长度
	int len2 = strlen(str2); // 获取字符串2的长度
	const char* longStr, * shortStr; // 定义指向长字符串和短字符串的指针
	int longLen, shortLen; // 定义长字符串和短字符串的长度
	// 将较长的字符串作为“长字符串”，较短的字符串作为“短字符串”
	if (len1 > len2) {
		longStr = str1;
		shortStr = str2;
		longLen = len1;
		shortLen = len2;
	}
	else {
		longStr = str2;
		shortStr = str1;
		longLen = len2;
		shortLen = len1;
	}
	int* dist1 = (int*)malloc((longLen + 1) * sizeof(int)); // 创建大小为长字符串长度加一的整型数组 dist1 和 newdist
	int* newdist = (int*)malloc((longLen + 1) * sizeof(int));
	for (int i = 1; i <= longLen; i++) { // 对 dist1 数组进行初始化，将第一个元素设为零，其余元素设为对应的下标值
		dist1[i] = i;
	}
	dist1[0] = 0;


	for (int i = 1; i <= shortLen; i++) { // 从短字符串开始逐个字符进行匹配
		newdist[0] = i;

		for (int j = 1; j <= longLen; j++) {
			newdist[j] = min(
				(longStr[j - 1] == shortStr[i - 1]) ? dist1[j - 1] : dist1[j - 1] + 1,
				newdist[j - 1] + 1, dist1[j] + 1); // 根据长字符串和短字符串的当前字符是否相等，决定选择增加、替换还是删除操作

		}

		memcpy(dist1, newdist, (longLen + 1) * sizeof(int)); // 将新计算出来的编辑距离存储在 newdist 数组中，并将其复制回 dist1 数组，以便下一次计算时使用
	}
	int result = dist1[longLen]; // 返回 dist1 数组的最后一个元素，即为两个字符串之间的编辑距离
	free(dist1);
	free(newdist);
	return result;
}


//Level1,AC树匹配字符串,匹配度100%
int matchpattern_1(const struct half_stream* const data_stream) {
	// 计算剩余长度
	int leftlen;
	// 记录剩余内容
	char* leftcontent;

	leftlen = data_stream->count - data_stream->offset;
	// 剩余内容等于数据流的数据加上偏移量
	leftcontent = data_stream->data; //+ data_stream->offset;
	// 从根节点开始匹配
	ACNode* p = root;
	// 当剩余长度大于0时，循环以下操作
	while (leftlen > 0) {
		// 找到当前字符对应的子节点的索引
		int index = leftcontent[0] + 128;
		// 如果没有匹配到，沿着失败指针回溯，直到找到一个有对应子节点的节点或者回溯到根节点
		while (p->children[index] == NULL && p != root) {
			p = p->fail;
		}
		// 如果匹配到了，移动到子节点；如果没有匹配到，从根节点重新开始
		p = p->children[index];
		if (p == NULL)
			p = root;
		// 检查当前节点是否是一个模式串的结尾
		if (p->isEnd > 0) {
			return p->isEnd;
		}
		// 继续匹配下一个字符
		leftlen--;
		leftcontent++;
	}
	// 如果没有匹配到任何模式串，返回0表示匹配失败
	return 0;
}


//Level2,相似度>85%
int matchpattern_2(const Attackpattern* const pOnepattern, const struct half_stream* const data_stream) {
	char* leftcontent = data_stream->data; // 获取 TCP 流数据的左半部分
	int leftlen = data_stream->count - data_stream->offset; // 获取 TCP 流数据的左半部分长度
	int len1 = strlen(pOnepattern->patterncontent); // 获取攻击模式的内容长度
	char* pchar = new char[len1]; // 创建一个 char 类型的数组，用于存储 TCP 流数据的一个子串
	while (leftlen > 0) { // 在 TCP 流数据的左半部分中逐个字符地匹配攻击模式
		bzero(pchar, len1);
		strncpy(pchar, leftcontent, len1); // 将 TCP 流数据的一个子串复制到 pchar 数组中
		double distance = stringDistance(pOnepattern->patterncontent, pchar); // 计算攻击模式内容和 TCP 流数据子串之间的编辑距离
		double similarity = 1.0 - distance / len1;//定义两字符串相似度
		if (similarity > 0.85) return 1; // 如果相似度大于 0.85，则认为匹配成功，返回 1
		leftlen--; // 继续匹配下一个字符
		leftcontent++;
	}
	delete[] pchar;
	return 0;
}


//Level3,相似度>70%
int matchpattern_3(const Attackpattern* const pOnepattern, const struct half_stream* const data_stream) {
	char* leftcontent = data_stream->data;// + data_stream->offset;
	int leftlen = data_stream->count - data_stream->offset;
	int len1 = strlen(pOnepattern->patterncontent);
	char* pchar = new char[len1];
	while (leftlen > 0) {
		bzero(pchar, len1);
		strncpy(pchar, leftcontent, len1);
		double distance = stringDistance(pOnepattern->patterncontent, pchar);
		double similarity = 1.0 - distance / len1;//定义两字符串相似度
		if (similarity > 0.7) return 1;
		leftlen--;
		leftcontent++;
	}
	delete[] pchar;
	return 0;
}



//Level1回调函数
void tcp_callback_1(struct tcp_stream* const tcp_connection) {
	int category; // 定义变量，用于存储攻击模式的类型
	switch (tcp_connection->nids_state) {
	case NIDS_JUST_EST: // 刚建立连接时，设置 TCP 数据流的收集器
		tcp_connection->server.collect++;
		tcp_connection->client.collect++;
		tcp_connection->server.collect_urg++;
		tcp_connection->client.collect_urg++;
		break;
	case NIDS_DATA: // 收到 TCP 数据时，匹配攻击模式并输出警报
		if (tcp_connection->server.count_new) { // 如果服务器端有新的数据到达
			category = matchpattern_1(&(tcp_connection->server)); // 匹配攻击模式
			if (category > 0) { // 如果匹配成功
				output_alert_1(category, tcp_connection, 1); // 输出警报
			}
			int num = tcp_connection->server.count - tcp_connection->server.offset - maxpattern_len; // 计算应该丢弃的数据长度
			nids_discard(tcp_connection, num > 0 ? num : 0); // 丢弃多余的数据

		}

		if (tcp_connection->client.count_new) {
			category = matchpattern_1(&(tcp_connection->client));
			if (category > 0) {
				output_alert_1(category, tcp_connection, 2);
			}
			int num = tcp_connection->client.count - tcp_connection->client.offset - maxpattern_len;
			nids_discard(tcp_connection, num > 0 ? num : 0);
		}
		break;
	case NIDS_CLOSE: // TCP 连接关闭
		break;
	case NIDS_RESET: // TCP 连接重置
		break;
	case NIDS_TIMED_OUT: // TCP 连接超时
		break;
	case NIDS_EXITING: // NIDS 正在退出
		break;
	default:
		break;
	}
}


//Level2回调函数
void tcp_callback_2(struct tcp_stream* const tcp_connection) {
	Attackpattern* pOnepattern = pPatternHeader;
	switch (tcp_connection->nids_state) {
	case NIDS_JUST_EST:
		tcp_connection->server.collect++;
		tcp_connection->client.collect++;
		tcp_connection->server.collect_urg++;
		tcp_connection->client.collect_urg++;
		break;
	case NIDS_DATA:
		if (tcp_connection->server.count_new) {
			while (pOnepattern != NULL) {
				if (matchpattern_2(pOnepattern, &(tcp_connection->server))) {
					output_alert_2_3(pOnepattern, tcp_connection, 1);
				}
				pOnepattern = pOnepattern->next;
			}
			int num = tcp_connection->server.count - tcp_connection->server.offset - maxpattern_len;
			nids_discard(tcp_connection, num > 0 ? num : 0);

		}
		if (tcp_connection->client.count_new) {
			while (pOnepattern != NULL) {
				if (matchpattern_2(pOnepattern, &(tcp_connection->client))) {
					output_alert_2_3(pOnepattern, tcp_connection, 2);
				}
				pOnepattern = pOnepattern->next;
			}
			int num = tcp_connection->client.count - tcp_connection->client.offset - maxpattern_len;
			nids_discard(tcp_connection, num > 0 ? num : 0);

		}
		break;
	case NIDS_CLOSE:
		break;
	case NIDS_RESET:
		break;
	case NIDS_TIMED_OUT:
		break;
	case NIDS_EXITING:
		break;
	default:
		break;
	}
}


//Level3回调函数
void tcp_callback_3(struct tcp_stream* const tcp_connection) {
	Attackpattern* pOnepattern = pPatternHeader;
	switch (tcp_connection->nids_state) {
	case NIDS_JUST_EST:
		tcp_connection->server.collect++;
		tcp_connection->client.collect++;
		tcp_connection->server.collect_urg++;
		tcp_connection->client.collect_urg++;
		break;
	case NIDS_DATA:
		if (tcp_connection->server.count_new) {
			while (pOnepattern != NULL) {
				if (matchpattern_3(pOnepattern, &(tcp_connection->server))) {
					output_alert_2_3(pOnepattern, tcp_connection, 1);
				}
				pOnepattern = pOnepattern->next;
			}
			int num = tcp_connection->server.count - tcp_connection->server.offset - maxpattern_len;
			nids_discard(tcp_connection, num > 0 ? num : 0);

		}
		if (tcp_connection->client.count_new) {
			while (pOnepattern != NULL) {
				if (matchpattern_3(pOnepattern, &(tcp_connection->client))) {
					output_alert_2_3(pOnepattern, tcp_connection, 2);
				}
				pOnepattern = pOnepattern->next;
			}
			int num = tcp_connection->client.count - tcp_connection->client.offset - maxpattern_len;
			nids_discard(tcp_connection, num > 0 ? num : 0);
		}
		break;
	case NIDS_CLOSE:
		break;
	case NIDS_RESET:
		break;
	case NIDS_TIMED_OUT:
		break;
	case NIDS_EXITING:
		break;
	default:
		break;
	}
}



void show_detection::on_start_detection_clicked()
{
	nids_params.multiproc = 2; // 设置 nids 参数

	// 注册校验和控制信息
	struct nids_chksum_ctl temp;
	temp.netaddr = 0;
	temp.mask = 0;
	temp.action = 1;
	nids_register_chksum_ctl(&temp, 1);

	// 初始化 NIDS
	if (!nids_init()) {
		QMessageBox msgBox;
		msgBox.setIcon(QMessageBox::Information);
		msgBox.setFixedSize(600, 360);
		msgBox.setText(tr("Initialization failed！Cannot use the device choosed or run with sudo command"));
		msgBox.setWindowTitle(tr("Information"));
		QFont font0("Arial", 16);
		msgBox.setFont(font0);
		msgBox.exec();
		return;
	}//初始化失败，需要sudo提权

	// 显示提示信息
	QMessageBox msgBox;
	msgBox.setIcon(QMessageBox::Information);
	msgBox.setFixedSize(600, 360);
	msgBox.setText(tr("Startup succeeded!"));
	msgBox.setWindowTitle(tr("Information"));
	QFont font1("Arial", 16);
	msgBox.setFont(font1);
	msgBox.exec();

	// 显示状态信息
	QLabel* label = new QLabel("Detecting attacks......", this);
	label->setGeometry(290, 170, 341, 31);
	QFont font2("Ubuntu", 14);
	QPalette palette;
	palette.setColor(QPalette::WindowText, Qt::white);
	label->setFont(font2);
	label->setPalette(palette);
	label->show();

	// 注册 TCP 回调函数
	switch (level) {
	case 1:
		nids_register_tcp((void*)(tcp_callback_1));
		break;
	case 2:
		nids_register_tcp((void*)(tcp_callback_2));
		break;
	case 3:
		nids_register_tcp((void*)(tcp_callback_3));
		break;
	default:
		break;
	}

	// 开始检测
	this->thread = new workThread();
	thread->start();


	// 处理和图形界面相关的任务
	while (flag) {
		QApplication::processEvents();
	}

}

// 释放 AC 自动机的空间
void rm_ACNode(ACNode* t) {
	if (t == NULL)return;
	for (int i = 0; i < 256; i++) {
		if (t->children[i] != NULL)
			rm_ACNode(t->children[i]);
	}
	delete t;
}

// 窗口关闭事件处理函数，释放空间
void show_detection::closeEvent(QCloseEvent* event) {
	thread->terminate();
	flag = 0;
	Node* tmp1 = typeofattack, * next1 = typeofattack;
	Attackpattern* tmp3 = pPatternHeader, * next3 = pPatternHeader;
	while (tmp1 != NULL) {
		next1 = tmp1->next;
		delete tmp1;
		tmp1 = next1;
	}
	while (tmp3 != NULL) {
		next3 = tmp3->next;
		delete tmp3;
		tmp3 = next3;
	}
	rm_ACNode(root);
}



