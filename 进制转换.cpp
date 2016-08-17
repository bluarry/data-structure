#include <stdlib.h>
#include <stdio.h>
#include <math.h>

//denfine Stack
#define stack_init_size 20
#define stack_increase 10
typedef char ElemType;
typedef struct node{
    ElemType *top;
    ElemType *base;
    int StackSize;
}SqStatic;
void initstack(SqStatic *s)
{
    s->base=(ElemType *)malloc(stack_init_size*sizeof(ElemType));
    if(!s) return ;
    s->top=s->base;
    s->StackSize=stack_init_size;
}

void push(SqStatic *s,ElemType *e){
    if(s->top-s->base==s->StackSize)
    {
        s->base=(ElemType *)realloc(s->base,(s->StackSize+stack_increase)*sizeof(ElemType));
        if(!s)return ;
        s->top=s->base+s->StackSize;
    }
    *(s->top)=*e;
    s->top++;
}
void pop(SqStatic *s,ElemType *e)
{
    if(s->base==s->top) {printf("error,the stack is empty\n");return ;}
    *e=*--(s->top);
}
int stacklen(SqStatic *s)
{
    return s->top-s->base;
}

int main()
{
    ElemType c;
    SqStatic s,eight;
    int i,j,len,k=0,sum=0,tem=0,seemstack[100]={0};
    initstack(&s);initstack(&eight);
   printf("intput a binary number,when it's # means input over :: ");
            c=getchar();
            fflush(stdin);
           while(c!='#')
           {
                push(&s,&c);
                 scanf("%c",&c);
            }
       getchar();

    printf("The stack size is %d\n",len=stacklen(&s));

    for(i=0,j=1; i<len; i++,j++)
    {
        pop(&s,&c);
        sum+=(c-48)*pow(2,i);
    }

    printf("To binary :The result =%d\n",sum);
    return 0;
}
