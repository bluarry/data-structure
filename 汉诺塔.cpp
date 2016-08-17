#include <stdio.h>

void f(int n,char x,char y,char z)
{
	if(1==n) printf("%c-->%c\n",x,z);
	else{
		f(n-1,x,z,y);
		printf("%c-->%c\n",x,z);
		f(n-1,y,x,z);
	}
}
int main()
{
	int n;
	printf("请输入汉诺塔盘子数 ：");
	scanf("%d",&n);
	printf("移动过程如下: \n");
	f(n,'X','Y','Z');
	return 0;
}
