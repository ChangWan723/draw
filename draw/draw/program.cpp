#include "stdafx.h"
#include "program.h"
#include"words.h"
using namespace std;
extern double tva = 0;
int n = 0, j, p, q;
double X, Y;
double ox=0,oy=0,r=0, sx=1, sy=1,start=0,tail=0,st=1,x, y;
Token * Get_token(char * buffer)
{
	Token *t;
	t = new Token[9999];
	char *buf, word[99] = { "\0" };
	buf = new char[99];
	int n = 1, i, j, num,index=0;
	for (i = 0;; i++) {						
		if (buffer[i] == '\0')break;
		if (buffer[i] >= 97 && buffer[i] <= 122)
			buffer[i] = buffer[i] - 32;
	}
	for (num = 0;; num++) {
		if (buffer[num] == '\0')break;
	}
	for (i = 0; i<num; i++) {
		if (buffer[i] == '\n') {
			n++;
		}
		else  if (!no_letter(buffer[i])) {         //匹配单词
			for (j = 0;; j++) {
				if (no_letter(buffer[i])) {
					i--;
					break;
				}
				else 
					word[j] = buffer[i++];

			}
			for (j = 0; j <= 18; j++) {
				if (j == 18) {
					t[index].type = ERRTOKEN;
					t[index].lexeme = "error";
					t[index].value = 0;
					t[index].FuncPtr = 0;
					t[index].line = n;
					index++;
					memset(word, 0, 99);
				}
				if (!strcmp(word, TokenTab[j].lexeme)) {
					t[index].type = TokenTab[j].type;
					t[index].lexeme = TokenTab[j].lexeme;
					t[index].value = TokenTab[j].value;
					t[index].FuncPtr = TokenTab[j].FuncPtr;
					t[index].line = n;
					index++;
					memset(word, 0, 99);
					break;
				}
			}
		}
		else  if (!no_digit(buffer[i]) || (buffer[i] == '-'&&buffer[i - 1] != ')'&&no_digit(buffer[i - 1]) && buffer[i - 1] != '.'&&buffer[i + 1] != '-'&&buffer[i-1]!='T'))    //匹配数字
		{
			if (buffer[i] == '-') {
				t[index].type = TokenTab[29].type;
				t[index].lexeme = TokenTab[29].lexeme;
				t[index].value = TokenTab[29].value;
				t[index].FuncPtr = TokenTab[29].FuncPtr;
				t[index].line = n;
				index++;
				continue;
			}
			for (int j = 0;; j++) {
				word[j] = buffer[i++];
				if (no_digit(buffer[i]) && buffer[i] != '.') {
					i--;
					break;
				}
			}

			t[index].type = CONST_ID;
			t[index].lexeme = "const";
			t[index].value = atof(word);
			t[index].FuncPtr = 0;
			t[index].line = n;
			index++;
			memset(word, 0, 99);
		}
		else  if (buffer[i] == '+') {
			t[index].type = TokenTab[18].type;
			t[index].lexeme = TokenTab[18].lexeme;
			t[index].value = TokenTab[18].value;
			t[index].FuncPtr = TokenTab[18].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == '-'&&buffer[i + 1] != '-') {
			t[index].type = TokenTab[19].type;
			t[index].lexeme = TokenTab[19].lexeme;
			t[index].value = TokenTab[19].value;
			t[index].FuncPtr = TokenTab[19].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == '*'&&buffer[i + 1] != '*') {
			t[index].type = TokenTab[20].type;
			t[index].lexeme = TokenTab[20].lexeme;
			t[index].value = TokenTab[20].value;
			t[index].FuncPtr = TokenTab[20].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == '/'&&buffer[i + 1] != '/') {
			t[index].type = TokenTab[21].type;
			t[index].lexeme = TokenTab[21].lexeme;
			t[index].value = TokenTab[21].value;
			t[index].FuncPtr = TokenTab[21].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == '*'&&buffer[i + 1] == '*') {
			t[index].type = TokenTab[22].type;
			t[index].lexeme = TokenTab[22].lexeme;
			t[index].value = TokenTab[22].value;
			t[index].FuncPtr = TokenTab[22].FuncPtr;
			t[index].line = n;
			index++;
			i++;
		}
		else  if (buffer[i] == ';') {
			t[index].type = TokenTab[23].type;
			t[index].lexeme = TokenTab[23].lexeme;
			t[index].value = TokenTab[23].value;
			t[index].FuncPtr = TokenTab[23].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == '(') {
			t[index].type = TokenTab[24].type;
			t[index].lexeme = TokenTab[24].lexeme;
			t[index].value = TokenTab[24].value;
			t[index].FuncPtr = TokenTab[24].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == ')') {
			t[index].type = TokenTab[25].type;
			t[index].lexeme = TokenTab[25].lexeme;
			t[index].value = TokenTab[25].value;
			t[index].FuncPtr = TokenTab[25].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == ',') {
			t[index].type = TokenTab[26].type;
			t[index].lexeme = TokenTab[26].lexeme;
			t[index].value = TokenTab[26].value;
			t[index].FuncPtr = TokenTab[26].FuncPtr;
			t[index].line = n;
			index++;
		}
		else  if (buffer[i] == '-'&&buffer[i + 1] == '-') {
			t[index].type = TokenTab[27].type;
			t[index].lexeme = TokenTab[27].lexeme;
			t[index].value = TokenTab[27].value;
			t[index].FuncPtr = TokenTab[27].FuncPtr;
			t[index].line = n;
			index++;
			i++;
			for (;; i++) {
				if (buffer[i + 1] == '\n'|| i>num)
					break;
			}
		}
		else  if (buffer[i] == '/'&&buffer[i + 1] == '/') {
			t[index].type = TokenTab[28].type;
			t[index].lexeme = TokenTab[28].lexeme;
			t[index].value = TokenTab[28].value;
			t[index].FuncPtr = TokenTab[28].FuncPtr;
			t[index].line = n;
			index++;
			i++;
			for (;; i++) {
				if (buffer[i + 1] == '\n')
					break;
			}
		}
		else  if (buffer[i] != '\n'&& buffer[i] != '\t'&&buffer[i] != ' '&&buffer[i] != '\0') {
			t[index].type = ERRTOKEN;
			t[index].lexeme = "error";
			t[index].value = 0;
			t[index].FuncPtr = 0;
			t[index].line = n;
			index++;
		}
	}
	t[index].type = END;
	j = index;
	return t;
}
Token *t; //定义t
double expr(Token* tt, int p, int q) {
	Token ts[999];
	int num=0;
	if (p > q) {
		exit(0);
	}
	for (int a = p; a <= q; a++) {
		if (tt[a].type != DEL) {
			ts[num] = tt[a];
			num++;
		}
	}
	for (int a = 0; a < num; a++) {
		if (ts[a].type == T)
			ts[a].value = tva;
	}
	if (num==1) {
		if (ts[0].type != CONST_ID&&ts[0].type != T) {
			exit(0);
		}
		else {
			if (ts[0].type == CONST_ID)
				return ts[0].value;
			else
				return tva;
		}
	}
	else {
		for (int a = 0; a < num; a++) {
			if (ts[a].type == R_BRACKET) {
				int b = a-1;
				for (;; b--) {
					if (ts[b].type == L_BRACKET) {
						ts[b].value = expr(ts, b + 1, a - 1);
						ts[b].type = CONST_ID;
						for (b=b+1; b <= a; b++) 
							ts[b].type = DEL;
						return expr(ts, 0, num-1);
					}
				}
			}
		}
		for (int a = 0; a < num; a++) {    //消除 数学函数
			if (ts[a].type == FUNC) {
				if (ts[a + 1].type != CONST_ID &&  ts[a + 1].type != T) {

					system("pause");
					exit(0);
				}
				else {
					if (!strcmp(ts[a].lexeme, "SIN"))
					{
						ts[a].value = sin(ts[a + 1].value);
						ts[a].type = CONST_ID;
						ts[a + 1].type = DEL;
						return expr(ts, 0, num - 1);
					}
					if (!strcmp(ts[a].lexeme, "COS"))
					{
						ts[a].value = cos(ts[a + 1].value);
						ts[a].type = CONST_ID;
						ts[a + 1].type = DEL;
						return expr(ts, 0, num - 1);
					}
					if (!strcmp(ts[a].lexeme, "TAN"))
					{
						ts[a].value = tan(ts[a + 1].value);
						ts[a].type = CONST_ID;
						ts[a + 1].type = DEL;
						return expr(ts, 0, num - 1);
					}
					if (!strcmp(ts[a].lexeme, "LN"))
					{
						ts[a].value = log(ts[a + 1].value);
						ts[a].type = CONST_ID;
						ts[a + 1].type = DEL;
						return expr(ts, 0, num - 1);
					}
					if (!strcmp(ts[a].lexeme, "EXP"))
					{
						ts[a].value = exp(ts[a + 1].value);
						ts[a].type = CONST_ID;
						ts[a + 1].type = DEL;
						return expr(ts, 0, num - 1);
					}
					if (!strcmp(ts[a].lexeme, "SQRT"))
					{
						ts[a].value = sqrt(ts[a + 1].value);
						ts[a].type = CONST_ID;
						ts[a + 1].type = DEL;
						return expr(ts, 0, num - 1);
					}
				}
			}
		}
		for (int a = 0; a < num; a++) {    //消除 次方
			if (ts[a].type == POWER) {
				if ((ts[a - 1].type != CONST_ID&& ts[a - 1].type != T) || (ts[a + 1].type != CONST_ID &&  ts[a + 1].type != T)) {

					system("pause");
					exit(0);
				}
				else {
					ts[a - 1].value =pow(ts[a-1].value,ts[a+1].value);
					ts[a].type = DEL;
					ts[a + 1].type = DEL;
					return expr(ts, 0, num - 1);
				}
			}
		}
		for (int a = 0; a < num; a++) {    //消除 负号
			if (ts[a].type == NEGA) {
				if (ts[a + 1].type != CONST_ID &&  ts[a + 1].type != T) {

					system("pause");
					exit(0);
				}
				else {
					ts[a].value = 0 - ts[a + 1].value;
					ts[a].type = CONST_ID;
					ts[a + 1].type = DEL;
					return expr(ts, 0, num - 1);
				}
			}
		}
		for (int a = 0; a < num; a++) {   //消除 乘除
			if (ts[a].type == MUL) {
				if ((ts[a - 1].type != CONST_ID&& ts[a - 1].type != T) || (ts[a + 1].type != CONST_ID &&  ts[a + 1].type != T)) {

					exit(0);
				}
				else {
					ts[a - 1].value = ts[a - 1].value * ts[a + 1].value;
					ts[a].type = DEL;
					ts[a + 1].type = DEL;
					return expr(ts, 0, num - 1);
				}
			}
			if (ts[a].type == DIV) {
				if ((ts[a - 1].type != CONST_ID&& ts[a - 1].type != T) || (ts[a + 1].type != CONST_ID &&  ts[a + 1].type != T)) {

					exit(0);
				}
				else {
					ts[a - 1].value = ts[a - 1].value / ts[a + 1].value;
					ts[a].type = DEL;
					ts[a + 1].type = DEL;
					return expr(ts, 0, num - 1);
				}
			}
		}
		for (int a = 0; a < num; a++) {   //消除 加减
			if (ts[a].type == PLUS) {
				if ((ts[a - 1].type != CONST_ID&& ts[a - 1].type != T) || (ts[a + 1].type != CONST_ID &&  ts[a + 1].type != T)) {

					exit(0);
				}
				else {
					ts[a - 1].value = ts[a - 1].value + ts[a + 1].value;
					ts[a].type = DEL;
					ts[a + 1].type = DEL;
					return expr(ts,0,num-1);
				}
			}
			if (ts[a].type == MINUS) {
				if ((ts[a - 1].type != CONST_ID&& ts[a - 1].type != T) || (ts[a + 1].type != CONST_ID &&  ts[a + 1].type != T)) {

					exit(0);
				}
				else {
					ts[a - 1].value = ts[a - 1].value - ts[a + 1].value;
					ts[a].type = DEL;
					ts[a + 1].type = DEL;
					return expr(ts, 0, num - 1);
				}
			}
		}
	}
}
void get(double ox, double oy, double r, double sx, double sy, double x, double y, double &X, double &Y) {
	double lx,ly, temp;
	lx = x;
	ly = y;
	lx *= sx;
	ly *= sy;
	temp = lx*cos(r) + ly*sin(r);
	ly = ly + cos(r) - lx*sin(r);
	lx = temp;
	lx += ox;
	ly += oy;
	X = lx;
	Y = ly;
}
void draw() {
	t = Get_token(Get_words());
	int B_num;
	ofstream outf("txt\\analysis.txt", ios::out);
	for (;; n++) {
		if (t[n].type == END)break;
		else if (t[n].type == ORIGIN) {
			n++;
			if (t[n].type != IS) {
				outf << "第" << t[n].line << "行：\t IS 匹配失败\n";
				exit(0);
			}
			else
			{
				n++;
				if (t[n].type != L_BRACKET) {
					outf << "第" << t[n].line << "行：\t ( 匹配失败\n";
					exit(0);
				}
				else {
					n++;
					p = n;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == COMMA) {
							q = n - 1;
							n++;
							break;
						}
						n++;
					}
					ox = expr(t, p, q);
	
					p = n;
					B_num = 0;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == L_BRACKET) {
							B_num++;
						}
						if (t[n].type == R_BRACKET) {
							B_num--;
							if (B_num == -1) {
								q = n - 1;
								n++;
								break;
							}
						}
						n++;
					}
					oy = expr(t, p, q);

					if (t[n].type != SEMICO) {
						outf << "第" << t[n - 1].line << "行：缺少;\n";
						exit(0);
					}
					else
						continue;
				}
			}
		}
		else if (t[n].type == ROT) {
			n++;
			if (t[n].type != IS) {
				outf << "第" << t[n].line << "行：\t IS 匹配失败\n";
				exit(0);
			}
			else
			{
					n++;
					p = n;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == SEMICO) {
							q = n - 1;
							break;
						}
						n++;
					}
					r = expr(t, p, q);

					continue;
			}
		}
		else if (t[n].type == SCALE) {
			n++;
			if (t[n].type != IS) {
				outf << "第" << t[n].line << "行：\t IS 匹配失败\n";
				exit(0);
			}
			else
			{
				n++;
				if (t[n].type != L_BRACKET) {
					outf << "第" << t[n].line << "行：\t ( 匹配失败\n";
					exit(0);
				}
				else {
					n++;
					p = n;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == COMMA) {
							q = n - 1;
							n++;
							break;
						}
						n++;
					}
					sx = expr(t, p, q);

					p = n;
					B_num = 0;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == L_BRACKET) {
							B_num++;
						}
						if (t[n].type == R_BRACKET) {
							B_num--;
							if (B_num == -1) {
								q = n - 1;
								n++;
								break;
							}
						}
						n++;
					}
					sy = expr(t, p, q);

					if (t[n].type != SEMICO) {
						outf << "第" << t[n - 1].line << "行：缺少;\n";
						exit(0);
					}
					else
						continue;
				}
			}
		}
		else if (t[n].type == FOR) {
			n++;
			if (t[n].type != T) {
				outf << "第" << t[n].line << "行：\t T 匹配失败\n";
				exit(0);
			}
			else {
				n++;
				if (t[n].type != FROM) {
					outf << "第" << t[n].line << "行：\t FROM 匹配失败\n";
					exit(0);
				}
				else {
					n++;
					p = n;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == TO) {
							q = n - 1;
							n++;
							break;
						}
						n++;
					}
					start = expr(t, p, q);

					p = n;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == STEP) {
							q = n - 1;
							n++;
							break;
						}
						n++;
					}
					tail = expr(t, p, q);


					p = n;
					for (;;) {
						if (n == j) {
							outf << "第" << t[n - 1].line << "行：表达式溢出\n";
							break;
						}
						if (t[n].type == DRAW) {
							q = n - 1;
							n++;
							break;
						}
						n++;
					}
					st = expr(t, p, q);

					
					int p1, q1, p2, q2;
					if (t[n].type != L_BRACKET) {
						outf << "第" << t[n].line << "行：\t ( 匹配失败\n";
						exit(0);
					}
					else {
						n++;
						p1 = n;
						for (;;) {
							if (n == j) {
								outf << "第" << t[n - 1].line << "行：表达式溢出\n";
								break;
							}
							if (t[n].type == COMMA) {
								q1 = n - 1;
								n++;
								break;
							}
							n++;
						}
						p2 = n;
						B_num = 0;
						for (;;) {
							if (n == j) {
								outf << "第" << t[n - 1].line << "行：表达式溢出\n";
								break;
							}
							if (t[n].type == L_BRACKET) {
								B_num++;
							}
							if (t[n].type == R_BRACKET) {
								B_num--;
								if (B_num == -1) {
									q2 = n - 1;
									n++;
									break;
								}
							}
							n++;
						}
						if (t[n].type != SEMICO) {
							outf << "第" << t[n - 1].line << "行：缺少;\n";
							exit(0);
						}
						else {
							for (tva = start; tva <= tail; tva += st) {
								x = expr(t, p1, q1);
								y = expr(t, p2, q2);
								get(ox, oy, r, sx, sy, x, y, X, Y);
								fillellipse(X, Y, 2, 2);
							}
							continue;
						}
					}
				}
			}
		}
		else {
			if (t[n].type != NOTE) {
				outf << "第" << t[n].line << "行：错误语句\n";
				exit(0);
			}
			else
				continue;
		}
	}
	outf << "分析成功。\n";
	getch();
	closegraph();
	outf.close();
}