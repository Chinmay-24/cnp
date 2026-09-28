#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
#include<math.h>

int main()
{
    int i,s,j,no_of_frame,no_of_lost_frames;
    int choice;
    int wsize;
    int lost_frames[100];
    int rn;

    printf("enter no. frames to be transmitted\n");
    printf("enter even number as the no. of frames:\n");
    scanf("%d",&no_of_frame);

    wsize=no_of_frame/2;

    printf("window size is %d\n",wsize);
    printf("---------------------------------------------\n");
    printf("%d frames arrived from network layer\n",no_of_frame);
    printf("out of %d frames %d frames are transmitted in one window\n",
           no_of_frame,wsize);
    printf("Frames transmitted with sequence no.\n");

    srand(time(0));

    for(i=0,s=0;i<wsize;i++)
    {
        printf("frame %d is transmitted with sequence no. %d\n",i,i);
        printf("---------------------------------------------\n");

        sleep(2);

        rn=rand()%2;

        if(rn==1)
        {
            printf("<---------------------------------------------\n");
            printf("acknowledgement for frame %d is received; send frame%d\n",
                   i,i+1);

            sleep(1);
            printf("\n");
        }

        else if(rn==0)
        {
            printf("Timeout : retransmit frame%d\n",i);
            printf("---------------------------------------------\n\n");

            sleep(1);

            printf("frame %d is retransmitted because of timeout\n",i);

            sleep(2);

            printf("ack for frame %d sent; transmit next frame %d\n",
                   i,i+1);

            printf("<---------------------------------------------\n\n");
        }

        else
        {
            lost_frames[s++]=i;
        }
    }

    no_of_lost_frames=s;

    printf("\nThe total no. of lost frames while transmission: %d\n",
           no_of_lost_frames);

    if(no_of_lost_frames!=0)
    {
        printf("checking for arrival of ack for frames in same window\n");

        int k;

        for(i=0;i<no_of_lost_frames;i++)
        {
            printf("frame %d ACKNOWLEDGEMENT is not received\n",
                   lost_frames[i]);

            sleep(1);

            printf("retransmitted frame %d successfully\n",
                   lost_frames[i]);

            printf("---------------------------------------------\n");

            sleep(3);

            printf("ack is received for frame %d\n",
                   lost_frames[i]);

            printf("<---------------------------------------------\n");

            sleep(1);
        }
    }

    printf("\n\nAll frames are transmitted in one window\n");

    printf("\n\nNext, the frame no. in the next set, frame %d, "
           "will be transmitted by the sliding window\n",wsize);

    return 0;
}
