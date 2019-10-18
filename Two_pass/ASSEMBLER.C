#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void refresh(){
	FILE *a,*b;
	a=fopen("OUTPUT.DAT","w");
	b=fopen("SYMTAB.DAT","w");
	fprintf(a,"");
	fprintf(b,"");
	fclose(a);
	fclose(b);	
}

int main(){
	char opcode[10],label[10],operand[20],symbol[10],op[10];
	FILE *f1,*f2,*f3,*f4;
	int start,LOCCTR=0,flag=0;
	refresh();
	f1=fopen("INPUT.DAT","r");
	f2=fopen("OUTPUT.DAT","a");
	f3=fopen("OPTAB.DAT","r");
	f4=fopen("SYMTAB.DAT","a");	
	fscanf(f1,"%s%s%s",label,opcode,operand);
	
	if(strcmp(opcode,"START")==0){
		start=atoi(operand);
		printf("\nSTARTING ADDRESS= %d\n",start);		
		if(start>0)
			LOCCTR=start;
		else 
			LOCCTR=start=0;
		fprintf(f2,"\t\t%s\t%s\t%s\n",label,opcode,operand);
		fscanf(f1,"%s%s%s",label,opcode,operand);
		do{
			
			flag=0;
			if(strcmp(label,"**")!=0){
				LOCCTR+=3;
				do{
					fscanf(f4,"%s",symbol);
					if(strcmp(label,symbol)==0)
						printf("\n\tDUPLICATE KEY FOUND - PROGRAM TERMINATED\t\n");
					else 
						fprintf(f4,"%s\t%d\n",label,LOCCTR);
				}while(!EOF);
				rewind(f4);
				
			}else{
				do{
					fscanf(f3,"%s",op);
					if(strcmp(opcode,op)==0){
						flag=1;
						break;
					}else
						continue;
				}while(!EOF);
				rewind(f3);
				if(flag==1){
					if(strcmp(opcode,"WORD")==0)
						LOCCTR+=3;
					else if(strcmp(opcode,"BYTE")==0)
						LOCCTR+=1;
					else if(strcmp(opcode,"RESW")==0)
						LOCCTR+=3*atoi(operand);
					else if(strcmp(opcode,"RESB")==0)
						LOCCTR+=atoi(operand);	
					else
					{
						printf("\n\tINVLAID OPCODE\t\n");
					}
				}
					
			}fprintf(f2,"%d\t%s\t%s\n",LOCCTR,label,opcode,operand);
			fscanf(f1,"%s%s%s",label,opcode,operand);
		}while(strcmp(opcode,"END")!=0);
		
		printf("\nPROGRAM LENGTH= %d\n\n",LOCCTR-start);
	}	
	return 0;
}
