/*
 * 建立循环链表，从1开始，每洗取得加1，使得最后从1 到 Cardnumber按次序取出
*/
#include <stdio.h>
#include<stdlib.h>
int Cardnumber;
typedef struct node {
    int data;
    struct node *next;
}*pnode,node;
/*
//算法描述：
//1.建立循环链表
//2.利用链表发牌
//3.打印出排序
*/
pnode creat() //建立一个有13个结点的循环链表
{
      pnode p=(pnode)malloc(sizeof(node)),q,head;
      head=p;
      int i=0;
      for(i=1;i<=Cardnumber;i++){
          q=(pnode)malloc(sizeof(node));
          q->data=0;
          p->next=q;
            p=q;
      }
        p->next=head->next;
        free(head);
        return p->next;
}
void magic(pnode head)
{
    int i=0,count=2;
    pnode qq=head;
    qq->data=1;
    while(1){
        for(i=0 ; i<count ; i++)
        {
            qq=qq->next;
            if(qq->data!=0)
                i--;
        }
        if(qq->data==0){
            qq->data=count;
            count++;
            if(count==Cardnumber) break;
        }

    }



}
int main()
{
    int i=0;
   pnode head=(node *)malloc(sizeof(node)),q;
   printf("请输入牌的最大数 ：");scanf("%d",&Cardnumber);fflush(stdin);
    head=creat();
    magic(head);
    printf("纸牌排序如下：\n");
    for(i=0;i<Cardnumber;i++)
    {
        printf("黑桃%d\n",head->data);
        head=head->next;
    }
  return 0;
}
