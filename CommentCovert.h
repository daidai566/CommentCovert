#define _CRT_SECURE_NO_WARNINGS 1
#ifndef __COMMENTCOVERT_H__
#define __COMMENTCOVERT_H__

#define FILENAME "input.c"
#define FILENAME1 "output.c"
#include<stdio.h>
enum STATE
{
	NUL_STATE,
	C_STATE,
	CPP_STATE,
	END_STATE
};
void commentcovert(FILE* pfIn, FILE* pfOut);
void cstatecovert(FILE* pfIn, FILE* pfOut);
void cppstatecovert(FILE* pfIn, FILE* pfOut);
void nulstatecovert(FILE* pfIn, FILE* pfOut);
#endif//__COMMENTCOVERT_H__