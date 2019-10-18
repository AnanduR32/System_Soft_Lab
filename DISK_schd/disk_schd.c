#include<stdio.h>
#include<stdlib.h>
int access_seq[10],access=10,i=0;
void sort(int access){
	int temp,i,j;
	for(i=0;i<access;i++)
		for(j=i+1;j<access;j++)
			if(access_seq[i]>access_seq[j]){
				temp=access_seq[i];
				access_seq[i]=access_seq[j];
				access_seq[j]=temp;
			}
}void read_seq(){
	int access;
	printf("\tEnter number of accesses :  ");
	scanf("%d",&access);
	printf("\nEnter the sequence :\n");
	for(i=0;i<access;i++){
		scanf("%d",&access_seq[i]);
	}
}int incr(int access){
	access_seq[++access]=0;
	access_seq[++access]=200;	

}int read_h(){
	int head;
	printf("\n\tEnter the current head position :  ");
	scanf("%d",&head);
	return head;
}int fcfs(){
	int head,seek=0;
	head=read_h();
	read_seq();
	for(i=0;i<access;i++){
		seek+=abs(head-access_seq[i]);
		head=access_seq[i];
	}	
	return seek;
}int sstf(){
	int head,seek=0,x,i,j,temp=0,min_seek=0;
	head=read_h();
	read_seq();
	for(i=0;i<access;i++){
		min_seek=abs(access_seq[i]-head);
		for(j=i+1;j<access;j++){
			if(abs(access_seq[j]-head)<min_seek){
				min_seek=abs(access_seq[j]-head);
				x=j;
			}
		}seek+=abs(head-access_seq[x]);
		head=access_seq[x];
		temp=access_seq[i];
		access_seq[i]=access_seq[x];
		access_seq[x]=temp;
	}	
	return seek;
}int scan(){
	int head,seek=0,x;
	head=read_h();
	read_seq();
	access=incr(access);
	sort(access);
	for(i=0;i<access;i++){
		if(access_seq[i]<head)
			x=i;
			break;
	}
	for(i=x;i<access;i++){
		seek+=abs(head-access_seq[i]);
		head=access_seq[i];
	}	
	return seek;
}void display_r(int result){
	printf(" \n\t The Resultant Seek Time is : %d\n",result);
}void main(){
	int choice=0,result=0;
	do{
		printf("\tEnter your choice : \n\t  1.FCFS \n\t  2.SSTF  \n\t  3.SCAN \tEnter choice (1-3) :  ");								
		scanf("%d",&choice);
		switch(choice){
			case 1:
				result=fcfs();
				break;
			case 2: 
				result=sstf();
				break;
			case 3: 
				result=scan();
				break;
			default:
				printf("\n\tInvalid Entry\t\n");	
		}display_r(result);	
	}while(0);
}		
