/*
设计函数分别求两个一元多项式的乘积与和。
输入格式:
输入分2行，每行分别先给出多项式非零项的个数，再以指数递降方式输入
一个多项式非零项系数和指数
（绝对值均为不超过1000的整数）。数字间以空格分隔。
输出格式:
输出分2行，分别以指数递降方式输出乘积多项式以及和多项式非零项的系数和指数。
数字间以空格分隔，但
结尾不能有多余空格。零多项式应输出0 0。
输入样例:

4 3 4 -5 2 6 1 -2 0
3 5 20 -7 4 3 1
输出样例:

15 24 -25 22 30 21 -10 20 -21 8 35 6 -33 5 14 4 -15 3 18 2 -6 1
5 20 -4 4 -5 2 9 1 -2 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node *lnode;
typedef struct node{
	int base;
	int pow;
	node *next;
}node;


void multiplication(lnode ta,int n,lnode tb,int m);
void addition(lnode ta,int n,lnode tb,int m);
int main()
{
	lnode ta=(lnode )malloc(sizeof(node)),tb=(lnode )malloc(sizeof(node)),tta,ttb,head_ta,head_tb;
	int n,m,i=0,j=0,k=0;
	scanf("%d",&n);
	for(i=0,head_ta=ta;i<n;i++)
	{
		tta=(lnode )malloc(sizeof(node));
		scanf("%d %d",&tta->base,&tta->pow);
		ta->next=tta;
		ta=ta->next;
		if(i==n-1)ta->next=NULL;
	}
/*
	for(i=0,ta=head_ta->next;ta;i++)
	{
		printf("%d %d ",ta->base,ta->pow);
		ta=ta->next;
	}
*/
	fflush(stdin);
	scanf("%d",&m);
	for(i=0,head_tb=tb;i<m;i++)
	{
		ttb=(lnode )malloc(sizeof(node));
		scanf("%d %d",&ttb->base,&ttb->pow);
		tb->next=ttb;
		tb=tb->next;
		if(i==m-1)tb->next=NULL;
	}
/*	for(i=0,tb=head_tb->next;tb;i++)
	{
		printf("%d %d ",tb->base,tb->pow);
		tb=tb->next;
	}
*/	
	if(m==0 && n == 0 ){printf("0 0\n0 0\n");return 0;}
	multiplication(head_ta->next,n,head_tb->next,m);
	addition(head_ta->next,n,head_tb->next,m);

	
	
	
	
	
	return 0;
}
void multiplication(lnode ta,int n,lnode tb,int m)
{
	lnode result=(lnode)malloc(sizeof(node)),ta_max,tb_min,result_head,head_ta,head_tb,temp=NULL;
	result_head=result;
	int i=0,j=0,k=0,max,min,flag=0;
	ta->pow >= tb->pow ? (ta_max=ta,tb_min=tb,max=n,min=m) : (ta_max=tb,tb_min=ta,max=m,min=n);
	head_ta=ta_max;head_tb=tb_min;
	for(i=0,ta_max=head_ta;i<max;i++)
	{
		for(j=0,tb_min=head_tb;j<min;j++)
		{
			temp=(lnode)malloc(sizeof(node));
			temp->base=ta_max->base * tb_min->base;
			temp->pow=ta_max->pow + tb_min->pow;
			result->next=temp;
			result=result->next;
			
			tb_min=tb_min->next;
		}
		ta_max=ta_max->next;
	}
	result->next=NULL;
/*	
	for(result=result_head->next;result;)
	{
		printf("%d %d \n",result->base,result->pow);
		result=result->next;
	} printf("\n");
*/
//	tb_min=ta_max;
	result=result_head->next;
	ta_max=result->next;
///*	
	for(i=0;ta_max&&result;)
	{
		for(tb_min=result;ta_max;)
		{
			if(ta_max->pow==result->pow)
			{
				result->base=ta_max->base + result->base;
				temp=ta_max;
				ta_max=ta_max->next;
				tb_min->next=ta_max;
				free(temp);
			}
			if(ta_max != NULL)ta_max=ta_max->next;
			if(tb_min != NULL)tb_min=tb_min->next;
		}
		if(result->next != NULL)
		{	result=result->next;ta_max=result->next;}
	}
//*/

	for(i=0,result=result_head->next;result;i++)
	{
		if(result->base==0&&result->pow==0){printf("0 0\n");return ;}
		else if(i==0)printf("%d %d",result->base,result->pow);
		else printf(" %d %d",result->base,result->pow);
		result=result->next;
	}
	printf("\n");
}
void addition(lnode ta,int n,lnode tb,int m)
{
	lnode result=(lnode)malloc(sizeof(node)),result_head,temp,ta_h=ta,tb_h=tb;
	result_head=result;
	int i=0,max=0,min=0,j=0,k=0;
	while(ta_h!=NULL&&tb_h!=NULL)
	{
		if(ta_h->pow > tb_h->pow) k=1;
		else if(ta_h->pow == tb_h->pow) k=2;
		else k=3;
		
		switch(k)
		{
			case 1:
					//
					temp=(lnode)malloc(sizeof(node));
					temp->base = ta_h->base;
					temp->pow = ta_h->pow;
					result->next=temp;
					result=temp;
					//
					ta_h=ta_h->next;
			case 2:
					j=ta_h->base + tb_h->base;
					if(j != 0)
					{
						//
					temp=(lnode)malloc(sizeof(node));
					temp->base = j;
					temp->pow = ta_h->pow;
					result->next=temp;
					result=temp;
					//
					}
					ta_h=ta_h->next;
					tb_h=tb_h->next;
					break;
			case 3:
					//
					temp=(lnode)malloc(sizeof(node));
					temp->base = tb_h->base;
					temp->pow = tb_h->pow;
					result->next=temp;
					result=temp;
					//
					tb_h=tb_h->next;
					break;
		}
	}	
		while(tb_h!=NULL)
		{
			
			temp=(lnode)malloc(sizeof(node));
			temp->base = tb_h->base;
			temp->pow = tb_h->pow;
			result->next=temp;
			result=temp;
			//
			tb_h=tb_h->next;
		}
		while(ta_h!=NULL)
		{
			
			temp=(lnode)malloc(sizeof(node));
			temp->base = ta_h->base;
			temp->pow = ta_h->pow;
			result->next=temp;
			result=temp;
			//
			ta_h=ta_h->next;
		}
		result->next=NULL;
	
	//输出结果
		for(i=0,result=result_head->next;result;i++)
	{
		if(i==0)printf("%d %d",result->base,result->pow);
		else printf(" %d %d",result->base,result->pow);
		result=result->next;
	}
		printf("\n");
}
