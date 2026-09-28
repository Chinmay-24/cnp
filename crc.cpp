#include <stdio.h>
#include <conio.h>
#define degree 16
int res[30];
void crc(int len)
{
int cp[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
int i=0, pos=0, newpos;
while(pos < len - degree)
{
for(i=pos; i<pos+degree+1; i++)
res[i]=mod(res[i],cp[i-pos]);
newpos=getnext(res,pos);
if(newpos>pos+1)
pos=newpos-1;
++pos;
}
}
int getnext(int res[], int pos)
{
int i=pos;
while(res[i]==0)
++i; //count of leading zero's in res[]
return i;
}
int mod(int x, int y)
{
return(x==y?0:1);
}
void main()
{
int array[30], ch;
int len, i=0, j=0;
clrscr();
//to input the data
printf("\nEnter the data stream : ");
while((ch=getche())!='\r')
array[i++]=ch-'0';
len=i;
printf("\n");
for(i=0;i<len;i++)
printf("\n%d",array[i]);
printf("\n");
//appending zeroes
for(i=0;i<degree;++i)
array[i+len]=0;

Page 28 of 43

len += degree;
//duplicating the data
for(i=0;i<len;i++)
res[i]=array[i];
printf("\nTransmitted Frame : ");
for(i=0;i<len-degree;i++)
printf("%d",res[i]);
crc(len); //calculate CRC
for(i=len-degree;i<len;++i)
printf("%d",res[i]);
printf("\nEnter stream for which CRC is to be checked : ");
i=0;
while((ch=getche())!='\r')
array[i++]=ch-'0'; //i/p stream
len=i;
//duplicate the array
for(i=0;i<len;i++)
res[i]=array[i];
crc(len);
printf("\nChecksum : ");
for(i=len-degree;i<len;++i)
printf("%d",res[i]);
//int j=0;
for(i=len-degree;i<len;++i)
if(res[i]==1)
++j; //count of 1's

if(j==0)
else
printf("\n\n\nNO ERROR in the Frame!!");
printf("\n\n\nERROR in the Frame!!");
getch();
}
