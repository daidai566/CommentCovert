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
		perror("��ʧ��\n");
		exit(EXIT_FAILURE);
	}
	//commentcovert(pfIn,pfOut);
	pfOut = fopen(FILENAME1, "w");
	if (pfOut == NULL)
	{
		perror("д��ʧ��\n");
		fclose(pfIn);
		exit(EXIT_FAILURE);
	}
 	commentcovert(pfIn, pfOut);
	printf("ת���ɹ�\n");
	fclose(pfIn);
	fclose(pfOut);
	system("pause");
	return 0;
}