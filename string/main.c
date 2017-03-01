#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <error.h>
#include <wchar.h>
#include <locale.h>

#include <unistd.h>

void test0()
{
	char *str = "hello";
	char *str1 = "world";

	char *str2 = (char *) malloc (5 * sizeof(char));
	strcat(str2, str);
	strcat(str2, str1);
	printf("%s\n", str2);

	for (int i = 0; i < 1000; i++) {
		char *p = (char *) malloc (1024 * 1024 * sizeof(char));
		sleep(1);
		printf("%d\n", i);
	}
}

void test1()
{
	printf("sizeof wchar_t : %d\n", sizeof(wchar_t));
	setlocale(LC_ALL, "zh_CN.UTF-8");
	size_t len = strlen("hello");
	printf("%u\n", len);
	len = strlen("你好");
	printf("%u\n", len);
	// 下面这样写有问题, "你好" 是 const char * 类型, 
	// 而wcslen()的参数是 const wchar * 类型
	// len = wcslen("你好");
	wchar_t *p = L"你好";
	len = wcslen(p);
	printf("%u\n", len);
	p = L"你好aabb";
	len = wcslen(p);
	printf("%u\n", len);
	// 这样输出 wchar_t 类型的字符串不行
	// printf("%s", p);
	printf("%ls", p);
	printf("\n============\n");
	char *p1 = (char *) malloc (1024 * sizeof(char));
	sprintf(p1, "%ls", p);
	printf("%s\n", p1);
}

void test2()
{
	setlocale(LC_ALL, "zh_CN.UTF-8");
	wchar_t *p = L"你好";
	wchar_t *p1 = L"ab你好";
	wchar_t *p2 = (wchar_t *) malloc (1024 * sizeof(wchar_t));
	wcscat(p2, p);
	wcscat(p2, p1);
	printf("%ls\n", p2);
}

int main(int argc, char *argv[])
{
	test2();
	exit(1);
	test1();	
	test0();
	return 0;
}
