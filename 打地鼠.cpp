# define _CRT_SECURE_NO_WARNINGS
# include <cstdio>
# include <graphics.h>//easyX 头文件
# include "location.h"
# include <ctime>
# include <mmsystem.h>//media device interface 头文件
# pragma comment(lib,"winmm.lib")//load media device interface 库文件
# define TEST 1
IMAGE bg11, bg22, bg33, bg44;	//定义图片变量
IMAGE bg111, bg222, bg333, bg444;
IMAGE mou1, mou2, mou3;
IMAGE mou11, mou22, mou33;
IMAGE mallet1, mallet11, arrows1, arrows11;
struct mou {
	int x, y;
	IMAGE jpg0, jpg00;
	bool uod;//move up or down
	void show() {
		putimage(x, y, &jpg00, SRCAND);//与（*）运算，彩色+白色=彩色，彩色+黑色=黑色
		putimage(x, y, &jpg0, SRCPAINT);//或（+）运算，彩色+黑色=彩色
	}
	void mu() {
		y -= step;
	}
	void md() {
		y += step;
	}
};
struct mou mou[mou_num];//地鼠量

struct mallet {
	int x, y;
	IMAGE jpg0, jpg00;
	void show() {
		BeginBatchDraw();
		putimage(x, y, &jpg00, SRCAND);//与（*）运算，彩色+白色=彩色，彩色+黑色=黑色
		putimage(x, y, &jpg0, SRCPAINT);//或（+）运算，彩色+黑色=彩色
		EndBatchDraw();
	}
}mloc;
int m, score = 0;

void mouloc();
void initGame();
void showGame();
void mouMove();
void playMusic();

int main() {
	initGame();
	playMusic();
	while (1) {
		mouloc();
		showGame();
		mouloc();
		mouMove();
		mouloc();
		Sleep(10);
	}
	//mciSendString("close bgm", NULL, NULL, NULL);
	return 0;
}

void mouloc() {
	ExMessage m;
	peekmessage(&m, EM_MOUSE);
	mloc.x = m.x;
	mloc.y = m.y;
	mloc.jpg0 = mallet1;
	mloc.jpg00 = mallet11;
	mloc.show();
}

void initGame() {
	initgraph(win_w, win_h);
	//加载图片
	loadimage(&mou1, "mou1.jpg");
	loadimage(&mou2, "mou2.jpg");
	loadimage(&mou3, "mou3.jpg");
	loadimage(&mou11, "mou11.jpg");
	loadimage(&mou22, "mou22.jpg");
	loadimage(&mou33, "mou33.jpg");
	loadimage(&bg11, "bg11.jpg");
	loadimage(&bg22, "bg22.jpg");
	loadimage(&bg33, "bg33.jpg");
	loadimage(&bg44, "bg44.jpg");
	loadimage(&bg111, "bg111.jpg");
	loadimage(&bg222, "bg222.jpg");
	loadimage(&bg333, "bg333.jpg");
	loadimage(&bg444, "bg444.jpg");
	loadimage(&mallet1, "mallet1.jpg");
	loadimage(&mallet11, "mallet11.jpg");
	loadimage(&arrows1, "arrows1.png");
	loadimage(&arrows11, "arrows11.png");
	//给数据赋初值
	for (int i = 0; i < mou_num; i++) {
		mou[i].uod = true;//move up
		if (i >= 0 && i < 3) {
			mou[i].x = mou_x + i * mou_space;
			mou[i].y = mou_y;
			mou[i].jpg0 = mou1;
			mou[i].jpg00 = mou11;
		}
		if (i >= 3 && i < 6) {
			mou[i].x = mou_x + (i - 3) * mou_space;
			mou[i].y = mou_y + mou_space;
			mou[i].jpg0 = mou2;
			mou[i].jpg00 = mou22;
		}
		if (i >= 6 && i < 9) {
			mou[i].x = mou_x + (i - 6) * mou_space;
			mou[i].y = mou_y + 2 * mou_space;
			mou[i].jpg0 = mou3;
			mou[i].jpg00 = mou33;
		}
	}
	srand(time(NULL));//随机变换
	m = rand() % mou_num;//选地鼠
}

void showGame() {
	BeginBatchDraw();//绘图前解决闪烁问题
	//贴图
	putimage(0, bg1_y, &bg111, SRCAND);//与（*）运算，彩色+白色=彩色，彩色+黑色=黑色
	putimage(0, bg1_y, &bg11, SRCPAINT);//或（+）运算，彩色+黑色=彩色
	for (int i = 0; i < 3; i++)//initGame已经赋过初值，这儿直接拿着用
		mou[i].show();
	void mouloc();

# if TEST
	putimage(0, bg2_y, &bg222, SRCAND);
	putimage(0, bg2_y, &bg22,SRCPAINT);
# endif
	for (int i = 3; i < 6; i++)
		mou[i].show();
	void mouloc();

# if TEST
	putimage(0, bg3_y, &bg333, SRCAND);
	putimage(0, bg3_y, &bg33, SRCPAINT);
# endif
	for (int i = 6; i < 9; i++)
		mou[i].show();
	void mouloc();

# if TEST
	putimage(0, bg4_y, &bg444, SRCAND);
	putimage(0, bg4_y, &bg44, SRCPAINT);
# endif
	EndBatchDraw();//绘图后解决闪烁问题
}

void mouMove() {
	if (m >= 0 && m < 3) {
		if (mou[m].uod) {//move up
			mou[m].mu();
			if (mou[m].y <= mou_y - mou_h) {
				mou[m].uod = false;
			}
		}
		else {//move down
			mou[m].md();
			if (mou[m].y >= mou_y) {
				mou[m].uod = true;
				m = rand() % mou_num;
			}
		}
	}
	if (m >= 3 && m < 6) {
		if (mou[m].uod) {//move up
			mou[m].mu();
			if (mou[m].y <= mou_y + mou_space - mou_h) {
				mou[m].uod = false;
			}
		}
		else {//move down
			mou[m].md();
			if (mou[m].y >= mou_y + mou_space) {
				mou[m].uod = true;
				m = rand() % mou_num;
			}
		}
	}
	if (m >= 6 && m < 9) {
		if (mou[m].uod) {//move up
			mou[m].mu();
			if (mou[m].y <= mou_y + 2 * mou_space - mou_h) {
				mou[m].uod = false;
			}
		}
		else {//move down
			mou[m].md();
			if (mou[m].y >= mou_y + 2 * mou_space) {
				mou[m].uod = true;
				m = rand() % mou_num;
			}
		}
	}
}

void playMusic() {
	//turn on music
	mciSendString("open \"D:/Code Files/C++/打地鼠/Souvenir.mp3\" alias bgm ", NULL, NULL, NULL);
	//play music
	mciSendString("play bgm repeat", NULL, NULL, NULL);
	//turn off musci
	//mciSendString("close bgm", NULL, NULL, NULL);
}




//键盘（地鼠位置对应键盘），音效，分数，（联网），关卡切换，