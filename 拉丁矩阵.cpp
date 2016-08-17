#include <stdio.h>
#include<stdlib.h>
/*
 * 1.建立n个结点的循环链表，并从1到n初始化结点
 * 2.循环输出所有结点
*/
typedef struct node{
    int data;
    struct node *next;
}node,*pnode;

pnode creat(int n);
int main()
{
    int n,i=0,j=0,k=0;
    printf("请输入 n ：");scanf("%d",&n);
    pnode p=(pnode)malloc(sizeof(node));
    p=creat(n);

    for(i=1;i<=n;i++)
     {
        for(k=1;p->data!=i;k++)p=p->next;
        for(j=1;j<=n;j++)
        {
            printf("%d ",p->data);
            p=p->next;
        }
        putchar('\n');
    }

    return 0;
}
pnode creat(int n)
{
     pnode p=(pnode)malloc(sizeof(node)),head,temp;
     head=p;
    int i=0;
    for (i=1;i<=n;i++){
        temp=(pnode)malloc(sizeof(node));
        temp->data=i;
        p->next=temp;
        p=p->next;
    }
    p->next=head->next;
    free(head);
    return p->next;
}
