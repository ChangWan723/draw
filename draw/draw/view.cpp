#include "stdafx.h"
#include "view.h"
int br=255, bg=255, bb=255, xr=0, xg=0, xb=0;
int choice()
{
	mouse_msg msg;
	while (1) {
		msg = getmouse();
		if (msg.x < 220 && msg.x>160 && msg.y > 220 && msg.y < 250)
		{
			setbkmode(OPAQUE);
			setfontbkcolor(EGERGB(200,200,255));
			setfont(30, 0, "楷体");
			outtextxy(160, 220, "确定");
		}
		else if (msg.x < 125 && msg.x>55 && msg.y >90 && msg.y < 160)
		{
			setfillcolor(EGERGB(128,128,128));
			fillellipse(90, 125, 40, 40);
		}
		else if (msg.x < 325 && msg.x>255 && msg.y > 90 && msg.y < 160)
		{
			setfillcolor(EGERGB(128, 128, 128));
			fillellipse(290, 125, 40, 40);
		}
		else if (msg.x < 365 && msg.x>280 && msg.y >230 && msg.y < 250)
		{
			setcolor(GREEN);
			setfontbkcolor(EGERGB(0x7A, 0xFE, 0xC6));
			setfont(19, 0, "微软雅黑 light");
			outtextxy(280, 230, "查看/修改源码");
		}
		else {
			setcolor(BLACK);
			setbkmode(OPAQUE);
			setfillcolor(EGERGB(br,bg,bb));
			fillellipse(90, 125, 40, 40);
			setfillcolor(EGERGB(xr, xg, xb));
			fillellipse(290, 125, 40, 40);
			setfontbkcolor(EGERGB(0x99, 0x00, 0x99));
			setfont(30, 0, "楷体");
			outtextxy(160, 220, "确定");
			setfontbkcolor(EGERGB(0x7A, 0xFE, 0xC6));
			setfont(19, 0, "微软雅黑 light");
			outtextxy(280, 230, "查看/修改源码");
		}
		if (msg.is_down()) {
			if (msg.x < 220 && msg.x>160 && msg.y > 220 && msg.y < 250) { return 1; }
			if (msg.x < 125 && msg.x>55 && msg.y >90 && msg.y < 160) { return 2; }
			if (msg.x < 325 && msg.x>255 && msg.y >90 && msg.y < 160) { return 3; }
			if (msg.x < 365 && msg.x>280 && msg.y >230 && msg.y < 250) { return 4; };
		}
	}
}
void C_bcolor() {
	initgraph(300, 500);
A:
	setbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
	setfillcolor(EGERGB(0x4D, 0xFF, 0xFF));
	bar(20, 0, 40, 500);
	setfontbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
	setcolor(BLACK);
	setfont(30, 0, "微软雅黑 light");
	outtextxy(55, 10, "Make Your Choice");
	setfillcolor(WHITE);
	bar(50, 50, 250, 80);
	setfillcolor(RED);
	bar(50, 100, 250, 130);
	setfillcolor(GREEN);
	bar(50, 150, 250, 180);
	setfillcolor(BLUE);
	bar(50, 200, 250, 230);
	setfillcolor(EGERGB(0x00,0xFF,0xFF));
	bar(50, 250, 250, 280);
	setfillcolor(EGERGB(0xFF, 0x00, 0xFF));
	bar(50, 300, 250, 330);
	setfillcolor(EGERGB(0xFF, 0xFF, 0x00));
	bar(50, 350, 250, 380);
	setfillcolor(BLACK);
	bar(50, 400, 250, 430);
	setbkmode(OPAQUE);
	setcolor(BLACK);
	setfontbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
	outtextxy(115, 450, "自定义");
	//bar(115, 450, 180, 480);
	mouse_msg msg;
	while (1) {
		msg = getmouse();
		if (msg.x > 50 && msg.x<250 && msg.y > 50 && msg.y < 80)
		{
			setfillcolor(RED);
			fillellipse(30, 65, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 100 && msg.y < 130)
		{
			setfillcolor(RED);
			fillellipse(30, 115, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 150 && msg.y < 180)
		{
			setfillcolor(RED);
			fillellipse(30, 165, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 200 && msg.y < 230)
		{
			setfillcolor(RED);
			fillellipse(30, 215, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 250 && msg.y < 280)
		{
			setfillcolor(RED);
			fillellipse(30, 265, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 300 && msg.y < 330)
		{
			setfillcolor(RED);
			fillellipse(30, 315, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 350 && msg.y < 380)
		{
			setfillcolor(RED);
			fillellipse(30, 365, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 400 && msg.y < 430)
		{
			setfillcolor(RED);
			fillellipse(30, 415, 5, 5);
		}
		else if (msg.x > 115 && msg.x< 180 && msg.y > 450 && msg.y < 480)
		{
			setbkmode(OPAQUE);
			setcolor(RED);
			setfontbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
			outtextxy(115, 450, "自定义");
		}
		else {
			goto A;
		}
		if (msg.is_down()) {
			if (msg.x > 50 && msg.x<250 && msg.y > 50 && msg.y < 80)
			{
				br = 255;
				bg = 255;
				bb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 100 && msg.y < 130)
			{
				br = 255;
				bg = 0;
				bb = 0;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 150 && msg.y < 180)
			{
				br = 0;
				bg = 255;
				bb = 0;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 200 && msg.y < 230)
			{
				br = 0;
				bg = 0;
				bb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 250 && msg.y < 280)
			{
				br = 0;
				bg = 255;
				bb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 300 && msg.y < 330)
			{
				br = 255;
				bg = 0;
				bb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 350 && msg.y < 380)
			{
				br = 255;
				bg = 255;
				bb = 0;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 400 && msg.y < 430)
			{
				br = 0;
				bg = 0;
				bb = 0;
				break;
			}
			else if (msg.x > 115 && msg.x< 180 && msg.y > 450 && msg.y < 480)
			{
				char str1[4], str2[4], str3[4];
				initgraph(400, 300);
				inputbox_getline("自定义颜色", "请输入R的值", str1, sizeof(str1));
				br = atof(str1);
				inputbox_getline("自定义颜色", "请输入G的值", str2, sizeof(str2));
				bg = atof(str2);
				inputbox_getline("自定义颜色", "请输入B的值", str3, sizeof(str3));
				bb = atof(str3);
				closegraph();
				break;
			}
		}
	}
}
void C_xcolor() {
	initgraph(300, 500);
A:
	setbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
	setfillcolor(EGERGB(0x4D, 0xFF, 0xFF));
	bar(20, 0, 40, 500);
	setfontbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
	setcolor(BLACK);
	setfont(30, 0, "微软雅黑 light");
	outtextxy(55, 10, "Make Your Choice");
	setfillcolor(WHITE);
	bar(50, 50, 250, 80);
	setfillcolor(RED);
	bar(50, 100, 250, 130);
	setfillcolor(GREEN);
	bar(50, 150, 250, 180);
	setfillcolor(BLUE);
	bar(50, 200, 250, 230);
	setfillcolor(EGERGB(0x00, 0xFF, 0xFF));
	bar(50, 250, 250, 280);
	setfillcolor(EGERGB(0xFF, 0x00, 0xFF));
	bar(50, 300, 250, 330);
	setfillcolor(EGERGB(0xFF, 0xFF, 0x00));
	bar(50, 350, 250, 380);
	setfillcolor(BLACK);
	bar(50, 400, 250, 430);
	setbkmode(OPAQUE);
	setcolor(BLACK);
	setfontbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
	outtextxy(115, 450, "自定义");
	//bar(115, 450, 180, 480);
	mouse_msg msg;
	while (1) {
		msg = getmouse();
		if (msg.x > 50 && msg.x<250 && msg.y > 50 && msg.y < 80)
		{
			setfillcolor(RED);
			fillellipse(30, 65, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 100 && msg.y < 130)
		{
			setfillcolor(RED);
			fillellipse(30, 115, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 150 && msg.y < 180)
		{
			setfillcolor(RED);
			fillellipse(30, 165, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 200 && msg.y < 230)
		{
			setfillcolor(RED);
			fillellipse(30, 215, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 250 && msg.y < 280)
		{
			setfillcolor(RED);
			fillellipse(30, 265, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 300 && msg.y < 330)
		{
			setfillcolor(RED);
			fillellipse(30, 315, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 350 && msg.y < 380)
		{
			setfillcolor(RED);
			fillellipse(30, 365, 5, 5);
		}
		else if (msg.x > 50 && msg.x<250 && msg.y > 400 && msg.y < 430)
		{
			setfillcolor(RED);
			fillellipse(30, 415, 5, 5);
		}
		else if (msg.x > 115 && msg.x< 180 && msg.y > 450 && msg.y < 480)
		{
			setbkmode(OPAQUE);
			setcolor(RED);
			setfontbkcolor(EGERGB(0x4D, 0xFF, 0xFF));
			outtextxy(115, 450, "自定义");
		}
		else {
			goto A;
		}
		if (msg.is_down()) {
			if (msg.x > 50 && msg.x<250 && msg.y > 50 && msg.y < 80)
			{
				xr = 255;
				xg = 255;
				xb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 100 && msg.y < 130)
			{
				xr = 255;
				xg = 0;
				xb = 0;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 150 && msg.y < 180)
			{
				xr = 0;
				xg = 255;
				xb = 0;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 200 && msg.y < 230)
			{
				xr = 0;
				xg = 0;
				xb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 250 && msg.y < 280)
			{
				xr = 0;
				xg = 255;
				xb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 300 && msg.y < 330)
			{
				xr = 255;
				xg = 0;
				xb = 255;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 350 && msg.y < 380)
			{
				xr = 255;
				xg = 255;
				xb = 0;
				break;
			}
			else if (msg.x > 50 && msg.x<250 && msg.y > 400 && msg.y < 430)
			{
				xr = 0;
				xg = 0;
				xb = 0;
				break;
			}
			else if (msg.x > 115 && msg.x< 180 && msg.y > 450 && msg.y < 480)
			{
				char str1[4], str2[4], str3[4];
				initgraph(400, 300);
				inputbox_getline("自定义颜色", "请输入R的值", str1, sizeof(str1));
				xr = atof(str1);
				inputbox_getline("自定义颜色", "请输入G的值", str2, sizeof(str2));
				xg = atof(str2);
				inputbox_getline("自定义颜色", "请输入B的值", str3, sizeof(str3));
				xb = atof(str3);
				closegraph();
				break;
			}
		}
	}
}
void view()
{
	int i;
S1:
	initgraph(380, 255);
	setbkcolor(EGERGB(255, 255, 255));
	for (i = 0; i <= 255; i++) {
		setcolor(EGERGB(i, i, 80));
		line(0, i, 400, i);
	}
	setbkmode(TRANSPARENT);
	setcolor(EGERGB(0xFF, 0xC7, 0x8E));
	setfont(50, 0, "李旭科毛笔行书");
	outtextxy(103, 30, "欢迎使用");
	setcolor(BLACK);
	setfont(25, 0, "微软雅黑 light");
	outtextxy(32, 170, "选择背景颜色");
	setfillcolor(EGERGB(br, bg, bb));
	fillellipse(90, 125, 40, 40);
	outtextxy(232, 170, "选择线条颜色");
	setfillcolor(EGERGB(xr, xg, xb));
	fillellipse(290, 125, 40, 40);
	setbkmode(OPAQUE);
	setcolor(EGERGB(0, 0, 0));
	setfontbkcolor(EGERGB(0x99, 0x00, 0x99));
	setfont(30, 0, "楷体");
	outtextxy(160, 220, "确定");
	setfontbkcolor(EGERGB(0x7A, 0xFE, 0xC6));
	setfont(19, 0, "微软雅黑 light");
	outtextxy(280, 230, "查看/修改源码");
	//bar(280, 230, 365, 250);
	int c = choice();
	if (c == 1) {
		goto S;
	}
	if (c == 2) {
		C_bcolor();
		goto S1;
	}
	if (c == 3) {
		C_xcolor();
		goto S1;
	}
	else if (c == 4) {
		system("txt\\test.txt");
		goto S1;
	}

	getch();
S:
	initgraph(1200, 675);
	setbkcolor(EGERGB(br,bg,bb));
	setcolor(EGERGB(xr, xg, xb));
	setfillcolor(EGERGB(xr, xg, xb));
}
