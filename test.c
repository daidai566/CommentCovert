#define _CRT_SECURE_NO_WARNINGS 1

#include"CommentCovert.h"
#include<stdlib.h>
int main()
{
	FILE* pfIn = NULL;
	FILE* pfOut = NULL;
    pfIn = fopen(FILENAME,"r");
	if (pfIn == NULL)
	{
		perror("打开失败\n");
		exit(EXIT_FAILURE);
	}
	//commentcovert(pfIn,pfOut);
	pfOut = fopen(FILENAME1, "w");
	if (pfOut == NULL)
	{
		perror("写入失败\n");
		fclose(pfIn);
		exit(EXIT_FAILURE);
	}
 	commentcovert(pfIn, pfOut);
	printf("转换成功\n");
	fclose(pfIn);
	fclose(pfOut);
	system("pause");
	return 0;
}