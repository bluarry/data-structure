/*此程序可将中缀表达式转化为后缀表达式
 * 运用到栈的性质
 * 算法描述：
 * 首先依次遍历每个输入的字符
 * 若是数字则直接打印
 *若是运算符，并且不是左括号时，判断与栈顶元素优先级的高低（若栈为空，直接入栈），高则打印，相同则入栈。
 *若是左括号，则进栈，并向后遍历，循环同样的操作，当遇到右括号的时候，退栈，并打印，直到遇到左括号，继续
 *遍历，直到结束。
 */
#include<stdio.h>
#include  <stdlib.h>
#include <ctype.h>

#define INI_SIZE 100
#define INCREASE_SIZE 10
typedef char Elemtype;

typedef struct Stack{
    Elemtype *top;
    Elemtype *base;
    int StackSize;
}sqStack;


void initstack( sqStack *s )
{
            s->base=(Elemtype *)malloc(sizeof(Elemtype)*INI_SIZE);
               s->top=s->base;
               s->StackSize=INI_SIZE;
}

void push(sqStack *s, Elemtype  e)
{
    if(s->top - s->base==s->StackSize)
       {
           s->base=(Elemtype *)realloc(s->base,(s->StackSize+INCREASE_SIZE)*sizeof(Elemtype));
           if(!s)return ;
           s->top=s->base+s->StackSize;
       }
       *(s->top)=e;
       s->top++;
}

void pop(sqStack *s, Elemtype  *e){
    if(s->base==s->top) {printf("error,the stack is empty\n");exit(1) ;}
        *e=*--(s->top);
}

int stacklen(sqStack *s)
{
    return s->top -  s->base;
}

int main()
{
        sqStack s;
        initstack(&s);
        char c,e;

        printf("请输入表达式，以#结束：\n");
        scanf("&c",&c);
        while (c != '#'){
             
			 if(isdigit(c)){
				 printf("%c",c);
			 }          
			else if('+' ==c||'-'== c)
			{
				if(!stacklen(&s)) push(&s,c);
				else
				{
					do
					{
						pop(&s,&e);
						if('('!=e) push(&s,e);
						else printf("%c",e);
					}while(stacklen(&s) && '('!= e );
					
				}
			}
			else if(')'== c){
				pop(&s,&e);
				while('('!=c){
					printf("%c",e);
					pop(&s,&e);
				}
				push(&s,c);
			}
			else if('*' ==c||'/'== c||'('==c)push(&s,c);
			else printf("\n输入有误\n");
            scanf("%c",&c);
        }












    return 0;
}
