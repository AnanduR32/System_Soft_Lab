    #include<stdio.h>
    #include<string.h>
    #include<stdlib.h>
    void main()
    {
      FILE *f1,*f2;
      int i,addr1,l,j,staddr1;
      char name[10],line[50],name1[10],addr[10],rec[10],ch,staddr[10];
      printf("enter program name:" );
      scanf("%s",name);
      f1=fopen("INPUT.txt","r");
      f2=fopen("OUTPUT.txt","w");
      fscanf(f1,"%s",line);
      for(i=2,j=0;i<8,j<6;i++,j++)
       {
        name1[j]=line[i];
       }
        name1[j]='\0';
      fprintf(f2,"name from object code :%s\n",name1);
      if(strcmp(name,name1)==0)
       {
        do
        {
        fscanf(f1,"%s",line);
        if(line[0]=='T')
        {
        for(i=2,j=0;i<8,j<6;i++,j++)
        staddr[j]=line[i];
        staddr[j]='\0';
        staddr1=atoi(staddr);
        i=12;
        while(line[i]!='$')
        {
          if(line[i]!='^')
          {
            fprintf(f2,"00%d \t %c%c\n", staddr1,line[i],line[i+1]);
            staddr1++;
            i=i+2;
          }
          else i++;
        }
        }
        else if(line[0]='E')
         {
           break;
          }
    
        }while(!feof(f1));
      fclose(f1);
        }

    }