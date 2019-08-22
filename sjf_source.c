#include<stdio.h>
int arrTime=0,burTime[10],turnTime[10],waitTime[10],i,j,k,n,totTime=0,temp=0,totBurst=0,order[10]={0,1,2,3,4,5,6,7,8,9},tempx=0;
float avgWT=0.0,avgTT=0.0;
void main(){
	printf("Enter n : number of processes = ");
	scanf("%d",&n);
	printf("Enter the burst time of processes : \n\n");
	for(i=0;i<n;i++){
		printf("Burst time of process %d = ",i);
		scanf("%d",&burTime[i]);
		totBurst+=burTime[i];
		printf("\n");
	}for(i=0;i<n;i++){
		for(j=i;j<n;j++){
			if(burTime[i]>burTime[j]){
				temp=burTime[i];
				tempx=order[i];
				order[i]=order[j];
				order[j]=tempx;
				burTime[i]=burTime[j];
				burTime[j]=temp;
			}
		}
	}for(i=0;i<n;i++){
		waitTime[i]+=totTime;
		turnTime[i]+=waitTime[i]+burTime[i];
		totTime+=burTime[i];
	}printf("Process   Arrival-Time   Burst-Time    Waiting-Time   Turnaround-Time\n");
	for(i=0;i<n;i++){
		printf("%d \t\t%d \t\t%d \t\t%d \t\t%d\n",order[i],arrTime,burTime[i],waitTime[i],turnTime[i]);
		
	}	

	for(i=0;i<n;i++){
		avgWT+=waitTime[i]/n;
		avgTT+=turnTime[i]/n;
	}
	printf("The average waiting time is : %5.2f\n",avgWT);	
	printf("The average turnaround time is : %5.2f\n",avgTT);
	printf("\n -- Gantt Chart -- \n");
	for(i=0;i<totBurst;i++){
		printf("%d   ",i);
	}printf("\n");
	for(i=0;i<n;i++){
		while(burTime[i]>0){
			printf("p[%d] ",order[i]);
			burTime[i]-=1;
		}
	}
	printf("\n");
}
