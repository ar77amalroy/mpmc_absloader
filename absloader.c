#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void main()
{
    FILE *fp1,*fp2;
    int i,j,address;
    char ch,line[50],addr[10],name[50],pgmName[50];
    
    printf("Enter program name: ");
    scanf("%s",name);
    
    fp1=fopen("objcode.txt","r");
    
    do
    {	
    	if(line[0] == 'H'){
    		for(i=2,j=0; i<=5 ;i++,j++){
    			pgmName[j] = line[i];
    		}
    		pgmName[j]='\0';
    		
    		if (strcmp(pgmName, name) != 0) return;
    	}
    	
    	
    	
    	
        fscanf(fp1,"%s",line);
	if(line[0]=='T')
	{
	    for(i=2,j=0;i<=7;i++,j++)
	        addr[j]=line[i];
	    addr[j]='\0';
	    address = atoi(addr);
	    

	    fp2=fopen("memory.txt","w");

	    i=12;
	    while(line[i]!='\0')
	    {
	        printf("%d \t %c%c\n",address,line[i],line[i+1]);
	        fprintf(fp2,"%d \t %c%c\n",address,line[i],line[i+1]);
	        address=address+1;
	        i=i+2;
	        if(line[i] == '^')
	        	++i;
	    }
	}
    }
    while(!feof(fp1));
    fclose(fp1);
}
