#include<stdio.h>
int arrTime=0,burTime[10],turnTime[10],waitTime[10],i,j,k,n,totTime=0,temp=0,totBurst=0,order[10]={0,1,2,3,4,5,6,7,8,9},prio[10];
int *x,*y;
float avgWT=0.0,avgTT=0.0;
void swap(int *x, int *y){
	temp=*x;
	*x=*y;
	*y=temp;
}void main(){
	printf("Enter n : number of processes = ");
	scanf("%d",&n);
	printf("Enter the burst time of processes : \n\n");
	for(i=0;i<n;i++){
		printf("Burst time of process %d = ",i);
		scanf("%d",&burTime[i]);
		totBurst+=burTime[i];
		printf("Priority of process %d = ",i);
		scanf("%d",&prio[i]);
		printf("\n");
	}for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(prio[i]>prio[j]){
				swap(&burTime[i],&burTime[j]);
				swap(&order[i],&order[j]);
				swap(&prio[i],&prio[j]);
			}
		}
	}for(i=0;i<n;i++){
		waitTime[i]+=totTime;
		avgWT+=waitTime[i];
		turnTime[i]+=waitTime[i]+burTime[i];
		avgTT+=turnTime[i];
		totTime+=burTime[i];
	}printf("Process   Arrival-Time   Burst-Time    Priority    Waiting-Time   Turnaround-Time\n");
	for(i=0;i<n;i++){
		printf("%d \t\t%d \t\t%d \t   %d \t\t%d \t\t%d\n",order[i],arrTime,burTime[i],prio[i],waitTime[i],turnTime[i]);
		
	}avgWT/=n;
	avgTT/=n;	
	printf("The average waiting time is : %5.2f\n",avgWT);	
	printf("The average turnaround time is : %5.2f\n",avgTT);
	printf("\n -- Gantt Chart -- \n");
	for(i=0;i<totBurst;i++){
		printf("  %d  ",i);
	}printf("\n");
	for(i=0;i<n;i++){
		while(burTime[i]>0){
			printf("p[%d] ",order[i]);
			burTime[i]-=1;
		}
	}printf("\n");
}

