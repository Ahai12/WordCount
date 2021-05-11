#include<stdio.h>
#include<string.h>

void charsCount(FILE *fp)		//字符计数
{
	int  countc = 0;
	while (fgetc(fp) != EOF)
	{
		countc++;
	}
	printf("该文件中字符的个数为：%d\n", countc);
}

void wordsCount(FILE* fp)		//单词计数
{
	char c;
	int flag = 0;
	int countw = 0;
	while ((c = fgetc(fp)) != EOF)
	{
		if (c == ' ' || c == ',' || c == '\n' || c == '\t')
		{
			flag = 0;
		}
		if (flag == 0 && c != ' ' && c != ',')
		{
			flag = 1;
			countw++;
		}
	}
	printf("该文件中单词的个数为：%d\n", countw);
}

int main()
{
	int count = 0;
	char method[128];
	char fname[128];
	FILE* fp;

	scanf("%s", method, 128);
	scanf("%s", fname, 128);
	fp = fopen(fname, "rt");
	if (!fp)
	{
		printf("文件打开失败，请检查文件名是否正确或者该文件是否在当前目录下\n");
		exit(1);
	}
	if (strcmp(method, "-c") == 0)
		charsCount(fp);
	else if (strcmp(method, "-w") == 0)
		wordsCount(fp);
	else
		printf("操作指令输入有误，请输入-c或-w\n");
	fclose(fp);
	return 0;
}