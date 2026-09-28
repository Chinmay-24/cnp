#include <stdio.h>
int main()
{
    int next_hop[20][20];
    int cost[20][20], n;
    int i,j,k;
    printf("Enter no of nodes.\n");
    scanf("%d",&n);
    printf("Enter the distance(cost or weight) matrix:\n");
    printf("enter zero for same node connection and 100 for no direct connection\n");
    for (i = 1; i <= n; i++)
        printf("\t%d",i); // print column nos.
    for (i = 1; i <= n; i++)
    {
        printf("\n%d\t",i); // print row nos.
        for (j = 1; j <= n; j++)
        {
            scanf("%d",&cost[i][j]); // accept cost matrix from user
            next_hop[i][j]=j; // initialize the next hop matrix
        }
    }
    for (k = 1; k <= n; k++)
    {
        for (i = 1; i <= n; i++)
        {
            for (j = 1; j <= n; j++)
            {
                if(cost[i][j]>cost[i][k]+cost[k][j])
                {
                    cost[i][j]=(cost[i][k]+cost[k][j]); // update cost matrix
                    next_hop[i][j]=k; // update the next hop matrix
                }
            }
        }
    }
    //print cost matrix
    printf(" cost matrix: \n");
    for (i = 1; i <= n; i++)
        printf("\t%d",i);
    for(i=1;i<=n;i++)
    {
        printf("\n%d\t",i);
        for (j = 1; j <= n; j++)
        {
            printf("%d\t",cost[i][j]);
        }
        printf("\n");
    }
    //print next hop matrix
    printf(" Next hop matrix: \n");
    for (i = 1; i <= n; i++)
        printf("\t%d",i);
    for(i=1;i<=n;i++)
    {
        printf("\n%d\t",i);
        for (j = 1; j <= n; j++)
        {
            printf("%d\t",next_hop[i][j]);
        }
        printf("\n");
    }
    for (i = 1; i <= n; i++)
    {
        printf("Routing table info for router:%d \n", i);
        printf("Dest\tNext Hop\tDist\n");
        for (j = 1; j <= n; j++)
            printf("%d\t%d\t\t%d\n", j,next_hop[i][j],cost[i][j]);
    }
}
