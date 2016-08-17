#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 10
typedef char Elemtype;
typedef struct Qnode{
	Elemtype *base;
	int front;
	int rear;
}Qnode,quen;

void initQUen(quen *q){
	q->base=(Elemtype *)malloc(sizeof(Elemtype)* MAX_SIZE);
	if(!q->base)return ;
	q->rear=q->front=0;
}
void insertquen(quen *q,Elemtype e)
{
	if(((q->rear)+1)%MAX_SIZE==q->front) return;
	q->base[q->rear]=e;
	q->rear=((q->rear)+1)%MAX_SIZE;
}
void outquen(quen *q,Elemtype *e){
	if(q->rear==q->front)return;
	*e=q->base[q->front];
	q->front=((q->front)+1)%MAX_SIZE;
}
int isimpty(quen *s)
{
	if(s->front==s->rear)return 0;
	else return 1;
	
	
}
int main()
{
	Elemtype c;
	quen q;
	initQUen(&q);
	printf("请输入队列：以#结束： ");
	scanf("%c",&c);
	while(c!='#'){
		insertquen(&q,c);
		scanf("%c",&c);
	}
	printf("结果如下:\n");
	while(isimpty(&q))
	{
		outquen(&q,&c);
		printf("%c",c);
	}
	printf("\n");







	return 0;
}
