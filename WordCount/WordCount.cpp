#include<stdio.h>
#include<string.h> 
char c[100];
int checkbyte(char* p)
{
	return strlen(p)-1;//减去最后一个文件结束符
}
int checkword(char* p)
{
	int count = 0;
	char s[100];
	s[0] = ' ';
	for (int i = 0; i < strlen(p); i++)//统一字符串形状 
	{
		s[i + 1] = p[i];
	}
	s[strlen(p) + 1] = ' ';
	char* ph = s;
	char* pr = s;
	char* pt = s;
	while (*pt != NULL)
	{
		ph++;
		pt = ph;
		pt++;
		if ((*pr == ',' || *pr == ' ') && (*ph != ' ' && *ph != ',')) //如果这个当前字符不等于等于空格或者逗号且前面一个字符不等于空格或者逗号则视为存在一个单词,count+1 
		{
			count++;
		}
		if ((*pt == ',' || *pt == ' ') && (*ph != ' ' && *ph != ',')) //如果这个当前字符不等于空格或者逗号且后面一个字符不等于空格或者逗号则视为存在一个单词,count+1 
		{
			count++;
		}
		pr = ph;
	}
	return count / 2;

}
int main(int argc, char* argv[])
{

	FILE* fp;
	errno_t err = fopen_s(&fp, argv[2], "r");
	fgets(c, 100, fp);
	fclose(fp);
	if (strcmp(argv[1], "-w") == 0)
	{
		printf("单词数:%d\n", checkword(c));
	}
	else if (strcmp(argv[1], "-c") == 0)
	{
		printf("字符数:%d\n", checkbyte(c));
	}
	getchar();
	return 0;

}