#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<time.h>
int main()
{
int n,i,rn;
int seq[50]={1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0,1,0};
srand(time(0));
printf("Enter the number of frames to be transmitted select within 30\n");
scanf("%d",&n);
srand(time(0));
for(i=1;i<=n;i++)
{
srand(time(0));
printf("\tTRANSMITTER: Frame %d is transmitted \n",seq[i]);
sleep(4);
rn=rand()%4;
if(rn==0)
{
printf("\tRECEIVER: No ack for FRAME %d \n",seq[i]);
printf("\tTRANSMITTER: Frame %d \n",seq[i]);
sleep(5);
printf("\tRECEIVER: Ack %d \n",seq[i+1]);
printf("---------------------------------------------------------------\n");
}
else if(rn==1)
{
printf("\tRECEIVER: Ack %d \n",seq[i+1]);
printf("---------------------------------------------------------------\n");
}
else if(rn==2)
{
printf("\tTRANSMITTER: Time out frame %d \n",seq[i]);
sleep(5);
printf("---------------------------------------------------------------\n");
printf("\tTRANSMITTER : Frame %d retransmitted \n",seq[i]);
printf("\tRECEIVER: Ack%d \n",seq[i+1]);
printf("---------------------------------------------------------------\n");
}
else
{
printf("\tFRAME %d is lost in the network \n",seq[i]);
printf("\tTRANSMITTER :Frame %d retransmitted \n",seq[i]);
sleep(5);
printf("\tRECEIVER: Ack %d \n",seq[i+1]);
printf("---------------------------------------------------------------\n");
}
}
printf("%d frames transmitted successfully \n",i-1);
}
