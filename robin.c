#include<stdio.h>
int arrTime=0,burTime[10],turnTime[10],waitTime[10],bkBurst[10],i,j,k,n,totTime=0,temp=0,totBurst=0,quantum=0,status[10]={0,0,0,0,0,0,0,0,0,0},flag=0;
float avgWT=0.0,avgTT=0.0;
void set(int x){
	status[x]=1;
}void reset(int x){
	status[x]=0;
}void save(){
	for(i=0;i<n;i++)
		bkBurst[i]=burTime[i];
}void load(){
	for(i=0;i<n;i++)
		burTime[i]=bkBurst[i];
}void main(){
	printf("Enter n : number of processes = ");
	scanf("%d",&n);
	printf("\n\n");
	for(i=0;i<n;i++){
		printf("Burst time of process %d = ",i);
		scanf("%d",&burTime[i]);
		totBurst+=burTime[i];
		printf("\n");
	}save();
	printf("Enter the quantum number : ");
	scanf("%d",&quantum);
	printf("\n -- Gantt Chart -- \n");
	for(i=0;i<totBurst;i++){
		printf("  %d  ",i+1);
	}printf("\n");
	i=0;
	while(1){
		while(i<totBurst){
			j=0;
			while(burTime[i]>0 && j<quantum){
				printf("p[%d] ",i);
				waitTime[i]+=1;
				avgWT+=waitTime[i];
				turnTime[i]+=waitTime[i]+burTime[i];
				avgTT+=turnTime[i];
				totTime+=burTime[i];
				burTime[i]--;
				j++;
			}if(burTime[i]!=0){
				set(i);
			}else{
				reset(i);
			}
			i++;
		}for(i=0;i<10;i++){
			if(status[i]==1)
				break;
			else 
				flag=1;
		}if(flag==1){
			goto end;
		}
	}end:
	printf("\n");		
	printf("Process   Arrival-Time   Burst-Time    Waiting-Time   Turnaround-Time\n");
	for(i=0;i<n;i++){
		printf("%d \t\t%d \t\t%d \t   %d \t\t%d\n",i,arrTime,bkBurst[i],waitTime[i],turnTime[i]);
		
	}avgWT/=n;
	avgTT/=n;	
	printf("The average waiting time is : %5.2f\n",avgWT);	
	printf("The average turnaround time is : %5.2f\n",avgTT);
	
}

