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
	printf("�����뺺ŵ�������� ��");
	scanf("%d",&n);
	printf("�ƶ���������: \n");
	f(n,'X','Y','Z');
	return 0;
}
