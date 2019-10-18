#include<stdio.h>
#
int curr=0;
int toExec=0;
int i=0,totTime=0;
int j=0;
int k=0;
int n,c=0,avgWT=0,avgTT=0;
void main()
{
	int arrTime[10];
	int waitTime[10];
	int turnTime[10];
	int burTime[10];
	printf("Enter the number of processes : ");
	scanf("%d",&n);	
	printf("Enter  the arrival time(s) of each processes\n");
	for(i=0;i<n;i++){
		printf("Enter the arrival time(s) : ");		
		scanf("%d",&arrTime[i]);
		printf("Enter  the burst time(s) : ");
		scanf("%d",&burTime[i]);
		printf("\n");
	}
	i=0;
	/*for(i=0;i<n;i++){
		curr=arrTime[i];
		for(j=i+1;j<n;j++){
			if(curr>arrTime[j]){
				curr=arrTime[j];
				toExec=j;
			}
		}
	*/
	totTime=arrTime[0];
	for(i=0;i<n;i++){
		waitTime[i]=totTime-arrTime[i];
		turnTime[i]=totTime+waitTime[i]+burTime[i]-arrTime[i];
		totTime+=burTime[i];
	}	
	printf("Process   Arrival-Time   Waiting-Time   Burst-Time    Turnaround-Time\n");
	for(i=0;i<n;i++){
		printf("%d \t\t%d \t\t%d \t\t%d \t\t%d\n",i,arrTime[i],waitTime[i],burTime[i],turnTime[i]);
		
	}	

	for(i=0;i<n;i++){
		avgWT+=waitTime[i];
		avgTT+=turnTime[i];
	}
	printf("The average waiting time is : %d\n",avgWT);	
	printf("The average turnaround time is : %d\n",avgTT);
	printf("\n -- Gantt Chart -- \n");
	for(i=0;i<n;i++){
		printf("%d",i);
	}
	for(i=0;i<n;i++){
		while(burTime[i]>0){
			printf("p[%d]",i);
			burTime[i]-=1;
		}
	}
	printf("\n");
}
