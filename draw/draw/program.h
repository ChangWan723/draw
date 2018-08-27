#pragma once
Token* Get_token(char* buffer);
double expr(Token* tt, int p, int q);
void get(double ox, double oy, double r, double sx, double sy, double x, double y, double &X, double &Y);
void draw();
