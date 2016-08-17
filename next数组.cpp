#include <stdio.h>

void get_next(){
	int j=0,i=1;
	int next[10]={0};
	char T[]=" ababaaaba";
	while(i<9){
		if(j==0||T[i]==T[j])
		{i++;
		j++;
		next[i]=j;
		}
		else
			j=next[j];
	} //while
	
	
}//get_next


int main(){
	get_next();
	
	
	
	
	
	return 0;
}
