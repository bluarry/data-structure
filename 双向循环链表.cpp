#include <stdio.h>
#include <stdlib.h>

#define    OK             1
#define ERROR       -1
typedef int Status;
typedef char ElemType;
typedef    struct Dualnode{
        ElemType data;
        struct Dualnode *prior;
        struct Dualnode *next;
}Dualnode,*DuaLinklList;

Status initlist(DuaLinklList &L)
{
    int i=0;
    DuaLinklList q , p;
    q=L;
    for(i=0;i<26;i++)
    {
        p=(DuaLinklList)malloc(sizeof(Dualnode));
        if(!p) return ERROR;
        p->data='A'+i;

        p->next=q->next;
        q->next=p;
        p->prior=q;
        q=p;
    }

    q->next=L->next;
    L->next->prior=q;


    return OK;
}
void caesar(DuaLinklList &L,int i){
    if(i>0)
    {
        do
        {
            L=L->next;
        }while(--i);
    }
    else if(i<0)
    {
        do
        {
            L=L->prior;
        }while(++i);
    }
}

int main()
{
    int i;
    DuaLinklList L=(DuaLinklList)malloc(sizeof(Dualnode));
    if(!L) return ERROR;
    L->next=NULL;
    L->prior=NULL;
        initlist(L);
        for(i=0;i<26;i++)
        {
             L=L->next;
            printf("%c",L->data);
        }
        printf("\n");
       printf("请输入数字 ：");scanf("%d",&i);
        caesar(L,i);
        for(i=0;i<26;i++)
        {
             L=L->next;
            printf("%c",L->data);
        }
        printf("\n");
    return 0 ;
}
