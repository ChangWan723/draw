#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
enum Token_Type								// �Ǻ�����
{
	ORIGIN, SCALE, ROT, IS, TO,			// ������
	STEP, DRAW, FOR, FROM,				// ������
	T,										// ����
	SEMICO, L_BRACKET, R_BRACKET, COMMA,		// �ָ�����
	PLUS, MINUS, MUL, DIV, POWER,			// �����
	FUNC,									// ����
	CONST_ID,								// ����
	NONTOKEN,								// �ռǺ�
	ERRTOKEN,								// ����Ǻ�
	NOTE,						//ע��
	NEGA,
	END,
	DEL
};

typedef double(*MathFuncPtr) (double);
struct Token 								// �Ǻ�����ű�ṹ
{
	Token_Type  type;						// �Ǻŵ����
	char		* lexeme;					// ���ɼǺŵ��ַ���
	double		value;						// ��Ϊ���������ǳ�����ֵ
	double(*FuncPtr)(double);		// ��Ϊ���������Ǻ�����ָ��
	int line;
};
static Token TokenTab[] =					// ���ű�����
{ 
{ CONST_ID,	"PI",		3.1415926,	NULL },//0
{ CONST_ID,	"E",		2.71828,	NULL },//1
{ T,		"T",		0.0,		NULL },//2
{ FUNC,		"SIN",		0.0,		sin },//3
{ FUNC,		"COS",		0.0,		cos },//4
{ FUNC,		"TAN",		0.0,		tan },//5
{ FUNC,		"LN",		0.0,		log },//6
{ FUNC,		"EXP",		0.0,		exp },//7
{ FUNC,		"SQRT",		0.0,		sqrt },//8
{ ORIGIN,	"ORIGIN",	0.0,		NULL },//9
{ SCALE,		"SCALE",	0.0,		NULL },//10
{ ROT,		"ROT",		0.0,		NULL },//11
{ IS,		"IS",		0.0,		NULL },//12
{ FOR,		"FOR",		0.0,		NULL },//13
{ FROM,		"FROM",		0.0,		NULL },//14
{ TO,		"TO",		0.0,		NULL },//15
{ STEP,		"STEP",		0.0,		NULL },//16
{ DRAW,		"DRAW",		0.0,		NULL },//17
{PLUS,	"+",	0.0,	NULL},//18
{ MINUS,	"-",	0.0,	NULL },//19
{ MUL,	"*",	0.0,	NULL },//20
{ DIV,	"/",	0.0,	NULL },//21
{POWER,	"**",	0.0,	NULL},//22
{SEMICO,	";",	0.0,	NULL},//23
{L_BRACKET,	"(",	0.0,	NULL},//24
{R_BRACKET,	")",	0.0,	NULL},//25
{COMMA,	",",	0.0,	NULL},//26
{NOTE,	"--",	0.0,	NULL},//27
{NOTE,	"//",	0.0,	NULL},//28
{NEGA,"-0",0.0,NULL}//29
};

#endif