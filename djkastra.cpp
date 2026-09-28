#include <stdio.h>
#include <conio.h>

	int p[10][10];
	
	int main()
	{
		int i, j ,k,n, t;
		int m[10][10];
		void path(int i, int j);
		
		//to input data
		printf("\n print the no. of nodes:");
		scanf("%d", &n);
		printf("\n Enter the node connection matrix:");
		printf("\n use 100 to indicate no connection b/w two nodes.");
		
		for (i = 1;i<=n;i++)
		{
			printf("\t %d", i); //printing column no.'s
			printf("\n");
			
			for (i =1; i<=n;i++)
			{
				 printf("\n %d \t",i); //printing row no.'s
				 for(j=1;j<=n;j++)
				 {
				 	scanf("%d", &m[i][j]);	// accept cost matrix from the user
				 	p[i][j] = 0;	//initialize path matrix
				 	
				 }
			 
			 }
			 
		}
		
		for (i =1; i<=n; i++)
		{
			m[i][i] = 0;
		}
		
		for (k =1; k<=n; k++)
		{
				for(i =1; i<=n;i++)
				{
					for (j=1;j<=n;j++)
					{
						if(m[i][k]+m[k][j]<m[i][j])
						{
							//update the cost and path matrix
							m[i][j] = m[i][k]+m[k][j];
							p[i][j] = k;
						}
					}
				}
		}
		
		//displaying the result
		printf("/n the final cost matrix is \n");
		for (i =1; i<=n;i++)
		{
			printf("\t %d",i);	//printing columns
			printf("\n");
			
			for (i =1; i<=n;i++)
			{
				printf("\n%d\t",i); //printing rows
				for (j=1;j<=n;j++)
				{
					printf("%d\t",m[i][j]); //printing all the cost elements
					printf("\n");
					
				}
			
			}
		}
		
		printf("/n the final path matrix is \n");
		for (i =1; i<=n;i++)
		{
			printf("\t %d",i);	//printing columns
			printf("\n");
			
			for (i =1; i<=n;i++)
			{
				printf("\n%d\t",i); //printing rows
				for (j=1;j<=n;j++)
				{
					printf("%d\t",p[i][j]); //printing all the cost elements
					printf("\n");
					
				}
			
			}
			
		}
		
		do
		{
			printf("\n enter source and destination nodes \n");
			scanf("%d %d", &i, &j);
			printf("\n weight: %d",m[i][j]);
			printf("\n path: \n");
			printf("\n %d --->", i);
			path(i,j);
			printf("%d",j);
			printf("\n To repeat press r");
		}
		while(getch() == 'r');
	}
	
	void path(int i , int j)
	{
		int k ;
		k = p[i][j];
		if (k!=0)
		{
			path(i,k);
			printf("%d ---> ",k);
			path(k,j);
		}
	}
