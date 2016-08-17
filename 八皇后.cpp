#include <stdio.h>
int count=0;
int notdanger(int row , int j , int (*chess)[8]){
	int i=0,k=0;
	int flag1=0,flag2=0,flag3=0,flag4=0,flag5=0;
	for(i=0;i<8;i++)//�ж��з���
	{
		if(i==row) continue;
		if(*(*(chess+i)+j)!=0) 
		{
			flag1=1; break;
		}
	}
	for(i=row,k=j;i >= 0 && k >= 0;i--,k--)//����
	{
		if(i==row) continue;
		if(*(*(chess+i)+k)!=0){flag2=1; break;}
	}
	for(i=row,k=j;i <8  && k < 8;i++,k++)//����
	{
		if(i==row) continue;
		if(*(*(chess+i)+k)!=0){flag3=1; break;}
	}
	for(i=row,k=j;i <8  && k >= 0;i++,k--)//����
	{
		if(i==row) continue;
			if(*(*(chess+i)+k)!=0){flag4=1; break;}
	}
	for(i=row,k=j;i >=0  && k < 8;i--,k++)//����
	{
		if(i==row) continue;
		if(*(*(chess+i)+k)!=0){flag5=1; break;}
	}
	if(flag1||flag2||flag3||flag4||flag5)
	{
		return 0;
	}
	else return 1;
}


void Eightqueen(int row , int n , int (*chess)[8]){
	int chess2[8][8], i=0 , j =0;
	
	for (i=0;i<8;i++)
		for(j=0;j<8;j++) chess2[i][j]=chess[i][j];
	
	if(row == 8){
		printf("�� %d ��\n",count+1);
		for (i=0;i<8;i++)
		{
			for(j=0;j<8;j++)
			{
				printf("%d ",*(*(chess2+i)+j));
			}
			printf("\n");
		}
		printf("\n");
		count++;
	}
	else 
	{
		for(j=0;j<n;j++)
		{
			if(notdanger(row , j ,chess )) //�ж��Ƿ�Σ��
			{
				for(i=0;i<8;i++)
				{
					*(*(chess2+row)+i)=0;
				}
				
				
				*(*(chess2+row)+j)=1;
				
				Eightqueen(row+1 , n , chess2);
			}
		}
		
		
	}
}



int main()
{
	freopen ("D:\\output.txt", "w", stdout);
	int chess[8][8], i=0 ,j=0 ;
	
	for (i=0;i<8;i++)
		for(j=0;j<8;j++) chess[i][j]=0;
	
	Eightqueen(0,8,chess);
	printf("�ܹ��� %d �ַ���\n",count);
	
	return 0;
}
