#include<stdio.h>
#include<dos.h>
#include<stdlib.h>
#include<conio.h>
#define bucketSize 512
void bktInput(int p_size,int oprate) {
if(p_size>bucketSize)
printf("\n\t\tBucket overflow");
else {
delay(500);
while(p_size>oprate){
printf("\n\t\t%d",oprate);
printf(" bytes outputted.");
//a=a-b;
p_size=p_size-oprate;
delay(500);
}
if (p_size>0) printf("\n\t\tLast %d ",p_size);printf(" bytes sent\t");
printf("\n\t\tBucket output successful");
}
}
void main() {
int i, op_rate, pktSize;
clrscr();
randomize();
printf("Enter output rate : "); scanf("%d",&op_rate);
for( i=1;i<=5;i++){
delay(random(1000));
pktSize=random(1000);
printf("\nPacket no %d",i);
printf("\tPacket size = %d",pktSize);

Page 40 of 43

bktInput(pktSize,op_rate);
getch();
}
}
