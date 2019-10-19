#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
void refresh(){
	FILE *a,*b;
	a=fopen("OUTPUT.DAT","w");
	b=fopen("SYMTAB.DAT","w");
	fprintf(a,"");
	fprintf(b,"");
	fclose(a);
	fclose(b);	
}int main(){
	char opcode[100],label[100],operand[200],symbol[100],op[100];
	FILE *f1,*f2,*f3,*f4;
	int start,LOCCTR=0,flag=0,len=0,loc=0;
	refresh();
	f1=fopen("INPUT.DAT","r");
	f2=fopen("OUTPUT.DAT","a");
	f3=fopen("OPTAB.DAT","r");
	f4=fopen("SYMTAB.DAT","a");	
	fscanf(f1,"%s%s%s",label,opcode,operand);
	if(strcmp(opcode,"START")==0){
		if(atoi(operand)>0)
			loc=LOCCTR=start=atoi(operand);
		printf("\nSTARTING ADDRESS= %d\n",start);		
		fprintf(f2,"\t\t%s\t%s\t%s\n",label,opcode,operand);
	
		fscanf(f1,"%s%s%s",label,opcode,operand);
		do{
			
			flag=0;
			if(strcmp(label,"**")!=0){
				do{
					fscanf(f4,"%s",symbol);
					if(strcmp(label,symbol)==0)
						printf("\n\tDUPLICATE KEY FOUND - PROGRAM TERMINATED\t\n");
					else 
						fprintf(f4,"%s\t%d\n",label,loc);
				}while(!EOF);
				if(strcmp(opcode,"WORD")==0)
					LOCCTR+=3;
				else if(strcmp(opcode,"BYTE")==0){
					if(op[0]=='X'){
						len=strlen(opcode)-2;
						LOCCTR+=len;
					}else
						LOCCTR+=1;
				}
				else if(strcmp(opcode,"RESW")==0)
					LOCCTR+=3*atoi(operand);
				else if(strcmp(opcode,"RESB")==0)
					LOCCTR+=atoi(operand);	
				else
					printf("\n\tINVLAID OPCODE\t%d\n",LOCCTR);
				rewind(f4);
			}else{
				do{
					fscanf(f3,"%s",op);
					if(strcmp(opcode,op)==0){
						LOCCTR+=3;
						break;
					}
				}while(!feof(f3));
				rewind(f3);
			}
			fprintf(f2,"%d\t%s\t%s\t%s\n",loc,label,opcode,operand);
			loc=LOCCTR;
			strcpy(opcode,"");
			fscanf(f1,"%s%s%s",label,opcode,operand);
		}while(strcmp(opcode,"END")!=0);
		fprintf(f2,"%d",LOCCTR);		
		printf("\nPROGRAM LENGTH= %d\n\n",LOCCTR-start);
	}return 0;
}
