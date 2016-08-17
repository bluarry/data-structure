#include <stdio.h>
#include <stdlib.h>
typedef struct node{
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
            p->next=temp;
            temp->next= head->next;
            p=temp;
    }
    free(head);
    return p->next;
}
int main()
{
    int m=3,n=41,i=0,j=0;
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
        free(tempp);
        p=p->next;
    }   
    printf("%d\n",p->data);
    
    
    return 0;
}