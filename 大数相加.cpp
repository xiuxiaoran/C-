#include<stdio.h>
#include<string.h>
#define MAX 1000
int main() 
{
    int k,n; 
	scanf("%d",&n);
	getchar();
	for(k=1;k<=n;k++)
{	
    char a[MAX];
	char b[MAX];
	char tempa[MAX];
	char tempb[MAX];
	char SUM[MAX+2];
	int lena;
	int lenb;
	int i,j;
	int sum=0;
	int maxlen;
	int carrybit=0;
	int overbit=0;	
    scanf("%s %s",a,b);
    getchar(); 
	lena=strlen(a);
	lenb=strlen(b);
	maxlen=lena>lenb?lena:lenb;
	printf("Case %d:\n",k);
	for(i=0;i<lena;i++)
	putchar(a[i]);
	printf("+");
	for(i=0;i<lenb;i++)
	putchar(b[i]);
	printf("=");
	for(j=0,i=lena-1;i>=0;i--,j++)
	  tempa[j]=a[i];
	  tempa[lena]='\0';
	   for(j=0,i=lenb-1;i>=0;i--,j++)
	  tempb[j]=b[i];
	  tempb[lenb]='\0';
	  //1.×Ö·û´®Äæ×ª 
	 if(lena<lenb)
	 {
	 for(i=lena;i<lenb;i++)
	    tempa[i]='0';
	    tempa[lenb]='\0';
	 }
	if(lena>lenb)
	{
	 for(i=lenb;i<lena;i++)
	    tempb[i]='0';
	    tempb[lena]='\0';
	}
	//2.µÍÎ»²¹Áã 
	if(lena<lenb)
	{
		for(i=0;i<lenb;i++)
		{
			sum=tempa[i]-'0'+tempb[i]-'0'+carrybit;
			if(sum>9)
			{ 
			  if(i==(maxlen-1))
			{
				overbit=1;
	
			}
				SUM[i]=sum-10+'0';
				carrybit=1;
			}
			else
			{
			SUM[i]=sum+'0';
			carrybit=0;
		    }
		}
		
			
	}
	else if(lena>lenb)
	{
				for(i=0;i<lena;i++)
		{
			sum=tempa[i]-'0'+tempb[i]-'0'+carrybit; 
			if(sum>9)
			{     if(i==(maxlen-1))
			{
				overbit=1;
			
			}
				SUM[i]=sum-10+'0';
				carrybit=1;
			}
			else
			{
			SUM[i]=sum+'0';
			carrybit=0;
		    }
		}
		 
	}
	else
	 {
	 		for(i=0;i<lena;i++)
		{
			sum=tempa[i]-'0'+tempb[i]-'0'+carrybit; 
			if(sum>9)
			{  if(i==(maxlen-1))
			{
				overbit=1;
				
			}
				SUM[i]=sum-10+'0';
				carrybit=1;
			}
			else
			{
			SUM[i]=sum+'0';
			carrybit=0;
		    }
		}
		 
	} 
	if(overbit==1)
	{
		SUM[maxlen++]=overbit+'0';//×ª³É×Ö·ûÊý×Ö 
	}
	for(i=maxlen-1;i>=0;i--)
	putchar(SUM[i]);
	printf("\n");
	
}
	
	
	//ÔËËã
	
       return 0; 
}
