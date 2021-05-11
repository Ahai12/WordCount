#include<stdio.h>
#include<string.h>

void charsCount(FILE *fp)		//�ַ�����
{
	int  countc = 0;
	while (fgetc(fp) != EOF)
	{
		countc++;
	}
	printf("���ļ����ַ��ĸ���Ϊ��%d\n", countc);
}

void wordsCount(FILE* fp)		//���ʼ���
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
	printf("���ļ��е��ʵĸ���Ϊ��%d\n", countw);
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
		printf("�ļ���ʧ�ܣ������ļ����Ƿ���ȷ���߸��ļ��Ƿ��ڵ�ǰĿ¼��\n");
		exit(1);
	}
	if (strcmp(method, "-c") == 0)
		charsCount(fp);
	else if (strcmp(method, "-w") == 0)
		wordsCount(fp);
	else
		printf("����ָ����������������-c��-w\n");
	fclose(fp);
	return 0;
}