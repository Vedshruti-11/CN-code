#include<stdio.h>
#include<string.h>
char data[20],div[20],temp[40],total[100];
int i,j,datalen,divlen,len,flag=1;
void check();
int main()
{
 	printf("\nEnter the data:");
 	scanf("%s",data);		      
    printf("\nEnter the divisor:");
    scanf("%s",div); 
   datalen=strlen(data);
   divlen=strlen(div);
   len=datalen+divlen-1;
	for(i=0;i<datalen;i++)
	{
		total[i]=data[i]; 
		temp[i]=data[i]; 		
	}	  
	for(i=datalen;i<len;i++)			 
        total[i]='0';   
	check();								
 	for(i=0;i<divlen;i++)	 			
	  	temp[i+datalen]=data[i];
 	printf("\ntransmitted Code Word: %s",temp);	  	
	printf("\n\nEnter the received code word: ");
    scanf("%s",total); 
 	check();		 	  
	for(i=0;i<divlen-1;i++)
		if(data[i]=='1')
		{
			flag=0;
			break;
		}		
	if(flag==1)
	printf("\nsuccessful!!");
	else
	printf("\nreceived code word contains errors...\n");	
}
void check()
{
    for(j=0;j<divlen;j++)
        data[j]=total[j];
    while(j<=len)
	{
        if(data[0]=='1')				
            for(i = 1;i <divlen ; i++)
   				data[i] = (( data[i] == div[i])?'0':'1');
        for(i=0;i<divlen-1;i++)		
            data[i]=data[i+1];
        data[i]=total[j++];			
    }
}
