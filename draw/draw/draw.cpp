// draw.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include"view.h"
#include"words.h"
#include"program.h"
using namespace std;
int main()
{
	view();
	match(Get_words());
	draw();
	return 0;
}

