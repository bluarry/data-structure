#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int mm;
    int data;
    struct node *next;
}*pnode;
pnode creat(int n)
{
    pnode p=(pnode)malloc(sizeof(node)),head,temp;
    head=p;
    int i;
    if(n==0) exit(0);
    for(i=1 ; i<=n ; i++ )
    {
            temp=(pnode)malloc(sizeof(node));
            temp->data=i;
            if(i==1)
            printf("请输入n个人所持密码，大于0的整数：");scanf("%d",&temp->mm);
            p->next=temp;
            temp->next= head->next;
            p=temp;
    }
    fflush(stdin);
    free(head);
    return p->next;
}
int main()
{
    int m=3,n=41,i=0,j=0;
    printf("请输入人数 N = "); scanf("%d",&n);fflush(stdin);
     printf("请输入人数上限 m = " ); scanf("%d",&m);fflush(stdin);
    m %= n;
    pnode p,tempp;
    p=creat(n);
    while(p->next !=p)
    {
        for(i=1;i< m-1;  i++)
        {
            p=p->next;        
        }
        printf("%d->",p->next->data);
        tempp=p->next;
        p->next=tempp->next;
        m=tempp->mm;
        m%=n;
        free(tempp);
        p=p->next;
    }   
    printf("%d\n",p->data);
    
    
    return 0;
}