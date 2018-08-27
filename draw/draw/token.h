#pragma once
#ifndef TOKEN_H
#define TOKEN_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>
enum Token_Type								// 记号种类
{
	ORIGIN, SCALE, ROT, IS, TO,			// 保留字
	STEP, DRAW, FOR, FROM,				// 保留字
	T,										// 参数
	SEMICO, L_BRACKET, R_BRACKET, COMMA,		// 分隔符号
	PLUS, MINUS, MUL, DIV, POWER,			// 运算符
	FUNC,									// 函数
	CONST_ID,								// 常数
	NONTOKEN,								// 空记号
	ERRTOKEN,								// 出错记号
	NOTE,						//注释
	NEGA,
	END,
	DEL
};

typedef double(*MathFuncPtr) (double);
struct Token 								// 记号与符号表结构
{
	Token_Type  type;						// 记号的类别
	char		* lexeme;					// 构成记号的字符串
	double		value;						// 若为常数，则是常数的值
	double(*FuncPtr)(double);		// 若为函数，则是函数的指针
	int line;
};
static Token TokenTab[] =					// 符号表内容
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