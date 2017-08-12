#define _CRT_SECURE_NO_WARNINGS 1
#include"CommentCovert.h"
#include<stdlib.h>
enum STATE sta = { 0 };
void commentcovert(FILE* pfIn, FILE* pfOut)
{
	while (sta != END_STATE)
	{
		switch (sta)
		{
		case C_STATE:
			cstatecovert(pfIn, pfOut);
			break;
		case CPP_STATE:
			cppstatecovert(pfIn, pfOut);
			break;
		case NUL_STATE:
			nulstatecovert(pfIn, pfOut);
			break;
		default:
			break;
		}
	}
}
void nulstatecovert(FILE* pfIn, FILE* pfOut)
{
	char first = 0;
	char second = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '/':
	{
			second = fgetc(pfIn);
			switch (second)
			{
			case '*':
				fputc("/", pfOut);
				fputc("/", pfOut);
				sta = C_STATE;
				break;
			case '/':
				fputc(first, pfOut);
				fputc(second, pfOut);
				sta = CPP_STATE;
				break;
			case EOF:
				sta = END_STATE;
				break;
			default:
				fputc(first, pfOut);
				fputc(second, pfOut);
				break;
			}
	}
	break;
	case EOF:
		sta = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
	/*}*/
}
void cstatecovert(FILE* pfIn, FILE* pfOut)
{
	char first = 0;
	char second = 0;
	char third = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '*':
	{
				second = fgetc(pfIn); 
				switch (second)
				{
				case '/':
				{
					third = fgetc(pfIn);
					if (third != '\n')
						fputc('\n', pfOut);
					if (third == '/')
					{
						ungetc(third, pfIn);
						sta = NUL_STATE;
						break;
					}
					fputc(third, pfOut);
					sta = NUL_STATE;
					break;
				}
				case '*':
					third = fgetc(pfIn);
					fputc(first, pfOut);
					if (third == '/')
					{
						sta = NUL_STATE;
					}
					break;
				default:
					fputc(first, pfOut);
					fputc(second, pfOut);
					break;
				}
	}
		break;
	case '\n':
		fputc(first, pfOut);
		fputc('/', pfOut);
		fputc('/', pfOut);
		break;
	case EOF:
		sta = END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}
void cppstatecovert(FILE* pfIn, FILE* pfOut)
{
	char first = 0;
	first = fgetc(pfIn);
	switch (first)
	{
	case '\n':
		fputc(first, pfOut);
		break;
	case EOF:
		sta=END_STATE;
		break;
	default:
		fputc(first, pfOut);
		break;
	}
}