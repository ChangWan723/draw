#include "stdafx.h"
#include"words.h"
using namespace std;
char* Get_words()
{
	char *c, *buffer,*temp;
	c = new char[99];
	temp = new char[999];
	buffer = new char[9999];
	strcpy(c, "txt\\test.txt");
	memset(buffer, 0, 9999);
	ifstream inf(c, ios::in|ios::_Nocreate);
	if (!inf) {
		cout << "open inf failed!" << endl;
		exit(0);
	}
	while (!inf.eof()) {
		inf.getline(temp, 999, '\n');
		strcat(buffer, temp);
		strcat(buffer, "\n");
	}
	for (int i = 0;; i++) {
		if (buffer[i] == '\0') {
			buffer[i - 1] = '\0';
			break;
		}
	}
	inf.close();
	return buffer;
}
int no_letter(char c)
{
	if (c>=65&&c<=90)
		return 0;
	else
		return 1;
}
int no_digit(char c)
{
	if (c >= 48 && c <= 57)
		return 0;
	else
		return 1;
}
void match(char *buffer) 
{
	char *buf, word[99] = {"\0"};
	buf = new char[99];
	char s[99] = { "	   ------------词法分析结果------------\n     记号类别   字符串  常数值  函数指针    所在行号\n" };
	ofstream cf("txt\\out.txt", ios::out);
	cf.close();
	ofstream outf("txt\\out.txt", ios::out | ios::app);
	outf << s;
	int n = 1, i, j,num;
	for ( i=0;;i++) {							//转大写
		if (buffer[i] == '\0')break;
		if (buffer[i] >= 97 && buffer[i] <= 122)
			buffer[i] = buffer[i] - 32;
	}
	for (num = 0;; num++) {
		if (buffer[num] == '\0')break;
	}
	for ( i = 0;i<num; i++) {     
	    if (buffer[i] == '\n') {
			n++;
		}
		else  if (!no_letter(buffer[i])) {         //匹配单词
			for ( j = 0;; j++) {
				if (no_letter(buffer[i])) {
					i--;
					break;
				}
				else
					word[j] = buffer[i++];
			}
			for ( j = 0; j <= 18; j++) {
				if (j == 18) {
					outf <<"\t"<< ERRTOKEN << "\t" << word << "\t0\t00000000\t"<<n<<endl;
					memset(word, 0, 99);
				}
				if (!strcmp(word, TokenTab[j].lexeme)) {
					outf <<"\t"<< TokenTab[j].type << "\t" << TokenTab[j].lexeme << "\t" 
						<< TokenTab[j].value << "\t" << TokenTab[j].FuncPtr << "\t"<<n<<endl;
					memset(word, 0, 99);
					break;
				}
			}
		}
		else  if (!no_digit(buffer[i])||(buffer[i]=='-'&&buffer[i-1] != ')'&&no_digit(buffer[i-1])&&buffer[i-1]!='.'&&buffer[i+1]!='-'&&buffer[i-1]!='T'))    //匹配数字
		{
			if (buffer[i] == '-') {
				outf << "\t" << TokenTab[29].type << "\t" << TokenTab[29].lexeme << "\t"
					<< TokenTab[29].value << "\t" << TokenTab[29].FuncPtr << "\t" << n << endl;
				continue;
			}
			for (int j = 0;; j++) {
				word[j] = buffer[i++];
				if (no_digit(buffer[i]) && buffer[i] != '.') {
					i--;
					break;
				}
			}
			outf <<"\t"<< CONST_ID << "\t" << word << "\t" << word << "\t00000000\t" << n << endl;
			memset(word, 0, 99);
		}	
		else  if (buffer[i] == '+') {
			outf <<"\t"<< TokenTab[18].type << "\t" << TokenTab[18].lexeme << "\t"
				<< TokenTab[18].value << "\t" << TokenTab[18].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == '-'&&buffer[i + 1] != '-') {
			outf <<"\t"<< TokenTab[19].type << "\t" << TokenTab[19].lexeme << "\t"
				<< TokenTab[19].value << "\t" << TokenTab[19].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == '*'&&buffer[i + 1] != '*') {
			outf <<"\t"<< TokenTab[20].type << "\t" << TokenTab[20].lexeme << "\t"
				<< TokenTab[20].value << "\t" << TokenTab[20].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == '/'&&buffer[i + 1] != '/') {
			outf <<"\t"<< TokenTab[21].type << "\t" << TokenTab[21].lexeme << "\t"
				<< TokenTab[21].value << "\t" << TokenTab[21].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == '*'&&buffer[i + 1] == '*') {
			outf <<"\t"<< TokenTab[22].type << "\t" << TokenTab[22].lexeme << "\t"
				<< TokenTab[22].value << "\t" << TokenTab[22].FuncPtr << "\t" << n << endl;
			i++;
		}
		else  if (buffer[i] == ';') {
			outf <<"\t"<< TokenTab[23].type << "\t" << TokenTab[23].lexeme << "\t"
				<< TokenTab[23].value << "\t" << TokenTab[23].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == '(') {
			outf <<"\t"<< TokenTab[24].type << "\t" << TokenTab[24].lexeme << "\t"
				<< TokenTab[24].value << "\t" << TokenTab[24].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == ')') {
			outf <<"\t"<< TokenTab[25].type << "\t" << TokenTab[25].lexeme << "\t"
				<< TokenTab[25].value << "\t" << TokenTab[25].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == ',') {
			outf <<"\t"<< TokenTab[26].type << "\t" << TokenTab[26].lexeme << "\t"
				<< TokenTab[26].value << "\t" << TokenTab[26].FuncPtr << "\t" << n << endl;
		}
		else  if (buffer[i] == '-'&&buffer[i + 1] == '-') {
			outf <<"\t"<< TokenTab[27].type << "\t" << TokenTab[27].lexeme << "\t"
				<< TokenTab[27].value << "\t" << TokenTab[27].FuncPtr << "\t" << n << endl;
			i++;
			for (;; i++) {
				if (buffer[i + 1] == '\n'||i>9999)
					break;
			}
		}
		else  if (buffer[i] == '/'&&buffer[i + 1] == '/') {
			outf <<"\t"<< TokenTab[28].type << "\t" << TokenTab[28].lexeme << "\t"
				<< TokenTab[28].value << "\t" << TokenTab[28].FuncPtr << "\t" << n << endl;
			i++;
			for (;; i++) {
				if (buffer[i + 1] == '\n')
					break;
			}
		}
		else  if (buffer[i] != '\n'&& buffer[i] != '\t'&&buffer[i] != ' '&&buffer[i] != '\0') {
			outf << "\t" << ERRTOKEN << "\t" << buffer[i] << "\t"
				<< "0" << "\t" << "00000000" << "\t" << n << endl;
			memset(word, 0, 99);
		}
	}
	outf.close();
}
	
