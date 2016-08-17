/*
 * 写一个逆波兰计算器
 * 实现对逆波兰表达输入计算
 * 支持小数
 * 仅仅支持波兰式的输入
*/
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <ctype.h>

#define stack_init_size 20
#define stack_increase 10
#define MAXBUFF 10
typedef double ElemType;
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

void push(SqStatic *s,ElemType e){
    if(s->top-s->base==s->StackSize)
    {
        s->base=(ElemType *)realloc(s->base,(s->StackSize+stack_increase)*sizeof(ElemType));
        if(!s)return ;
        s->top=s->base+s->StackSize;
    }
    *(s->top)=e;
    s->top++;
}
void pop(SqStatic *s,ElemType *e)
{
    if(s->base==s->top) {printf("error,the stack is empty\n");exit(1) ;}
    *e=*--(s->top);
}
int stacklen(SqStatic *s)
{
    return s->top-s->base;
}


int main()
{
    SqStatic s;
    char c,str[MAXBUFF];
    double d,e;
    int i=0;
    initstack(&s);

        printf("输入逆波兰式，以#结尾 ：\n");
        scanf("%c",&c);
        while(c != '#')
        {

            while ( isdigit(c) || c=='.' ){
                str[i++]=c;
                str[i]='\0';
                if(i>=MAXBUFF)
                {
                    printf("数据过大\n");
                    return -1;
                }
                scanf("%c",&c);
                    if(c== ' ')
                    {
                        d=atof(str);
                        push(&s, d);
                        i=0;
                        break;
                    }
            }

  switch (c) {
            case '+':
                pop(&s,&e);
                pop(&s,&d);
                push(&s,d+e);
                break;
               case '-':
                     pop(&s,&e);
                     pop(&s,&d);
                     push(&s,d-e);
                break;
                case '*':
                pop(&s,&e);
                pop(&s,&d);
                push(&s,d*e);
                break;
            case '/':

                pop(&s,&e);
                pop(&s,&d);
                if(e!=0)
                push(&s,d/e);
                else printf("\n除数为0\n");
                break;
            }
            scanf("%c",&c);
        }
            pop(&s,&d);
            printf("结果为 :%f\n",d);
    return 0;
}
