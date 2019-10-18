#include<stdio.h>
int work[10],finish[10]={1,1,1,1,1,1,1,1,1,1},used[10]={0,0,0,0,0,0,0,0,0,0},out,max[10],need[10][10],allocated[10][10],available[10],n,m,i,j,k,flag=1,sflag=1,lock[10]={0,0,0,0,0,0,0,0,0,0},copyFinish[10];
void input(){
	printf("\n**Entered input**\n");
	printf("Enter the number of processes : ");
	scanf("%d",&n);
	printf("Enter the number of resourse types : ");
	scanf("%d",&m);
	for(i=0;i<m;i++){
		printf("Enter the max instances of resource type R[%d] : ",i);
		scanf("%d",&max[i]);
	}for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Enter the instances of resource type R[%d] allocated to processes P[%d] : ",j,i);
			scanf("%d",&allocated[i][j]);
		}
	}for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf("Enter the instances of resource type R[%d] needed by processes P[%d] : ",j,i);
			scanf("%d",&need[i][j]);
		}
		
	}
}void calcAvail(){
	printf("\n**Entered calcAvail**\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			used[i]+=allocated[i][j];
		}available[i]=max[i]-used[i];
	}
}void aCPy(){
	for(i=0;i<n;i++){
		work[i]=available[i];
	}
}void sCPy(){
	for(i=0;i<n;i++){
		copyFinish[i]=finish[i];
	}
}int check(int l){
	for(j=0;j<m;j++){
		if(need[l][j]<work[j])
			flag=0;
	}
	if(flag==0)
		return(0);
	else 
		return(1);
}int checkFinish(){
	int l;	
	for(l=0;l<n;l++){ 	
		if(finish[l]==0)
			flag=0;
	}
	if(flag==0)
		return(0);
	else 
		return(1);
}int checkStatus(){
	int l;	
	for(l=0;l<n;l++){
		if(copyFinish[l]==finish[l])
			sflag=0;
	}
	if(sflag==0)
		return(0);
	else 
		return(1);
}void init_finish(){
	int l;
	for(l=0;l<n;l++)
		finish[l]=1;
}int banker(){
	aCPy();
	init_finish();
	do{
		sCPy();
		for(i=0;i<n;i++){
			if((finish[i]==1)&&(check(i)==0)){
				for(k=0;k<m;k++){
					allocated[i][k]-=need[i][k];
					available[k]+=work[k];
					finish[i]=0;
				}
			}
		}	
		if(checkStatus()==1)
			return(0);
		else 
			return(1);
	}while(1);
}void display(){
	printf("Process allocated  need\n");
	for(i=0;i<n;i++){
		for(j=0;j<m;j++){
			printf(" %d\t %d\t \t%d\t\n",i,allocated[i][j],need[i][j]);
		}
	}
	printf("\nMax resources of the processes -\n");
	for(i=0;i<m;i++){
		printf("process %d : %d\n",i,max[i]);
	}
	printf("\nAvailable resources of the processes -\n");
	for(i=0;i<m;i++){
		printf("process %d : %d\n",i,available[i]);
	}
}void main(){
	input();
	calcAvail();
	display();
	out=banker();
	if(out==0){
		printf("\n***The system is in safe state***\n");
	}	
	else if(out==1){
		printf("\n***The system is in not safe state***\n");
	}
	printf("\n");	
}
