#include <stdio.h>
#include <string.h>
void get_next(char T[],int next[]){
	int j=0,i=1;
	while(i<(strlen(T)-1)){
		if(j==0||T[i]==T[j])
		{
			i++;
			j++;
			if(T[i]!=T[j])
				next[i]=j;
			else
				next[i]=next[j];
		}
		else
			j=next[j];
	} //while
	printf("next:");
	for(i=0;i<(strlen(T)-1);i++)printf("%d ",next[i]); printf("\n");
}//get_next
int index_kmp(char S[],char T[],int pos)
{
	int next[255]={0},i=pos,j=1;
	get_next(T,next);
	
	while(i<=(strlen(S)-1) && j<=(strlen(T)-1)){
		if(S[i]==T[j]||j==0)
		{
			i++;j++;
		}
		else{
			j=next[j];
		}
	}
	if(j>(strlen(T)-1))
		return i-(strlen(T)-1);
	else 
		return -1;
}
int main(){
	fflush(stdin);
	char S[100],T[40];	
	printf("请输入主串以#开头:");
	fflush(stdin);
	scanf("%s",&S);
	fflush(stdin);
	printf("请输入匹配串以#开头:"); 
	scanf("%s",&T); 
	printf("位置为: %d",index_kmp(S,T,1));
	return 0;
}


//测试数据：9ababaaaba
//第二次  ： 3aab
//预期答案: 6 
