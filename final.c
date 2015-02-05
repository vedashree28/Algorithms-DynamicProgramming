#include<stdio.h>
#include<stdlib.h>

void wis(int arr[],int weight [],int n)
{

	int *we=(int*)malloc((n+1)* sizeof(int));
	int *path=(int*)malloc((n+1) * sizeof(int));
	int *result=(int*)malloc((n+1) * sizeof(int));
	arr[0]=-9999;
	weight[0]=0;
	int max=0,i,j,max_i,k,max_index,length;
	for(i=0;i<=n;i++)
		we[i]=weight[i];
	for(i=1;i<=n;i++)
	{
		for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && we[i]<we[j]+weight[i])
			{
				we[i]=we[j]+weight[i];
				path[i]=j;

			}
			if(max<we[i])
			{
				max=we[i];
				max_i=i;
			}
		}
	}
	printf("\n");
	printf("\nmax=> %d",max);
	k=max_i;;
	length=0;
	for(i=0;i<=n;i++)
		result[i]=0;
	/*for(i=0;i<=n;i++)
		printf("%d ",path[i]);*/
	result[length++]=max_i;
	while(path[k]!=0)
	{
		k=path[k];
		result[length++]=k;
	}
	printf("\nIndices=> ");
	for(i=length;i>=0;i--)
	{
		if(result[i]!=0)
			printf("%d ",result[i]);
	}
	printf("\nElements=> ");
	for(i=length;i>=0;i--)
	{
		if(result[i]!=0)
			printf("%d ",arr[result[i]]);
	
	}

			
}
void variations_weight(int arr[],int weight[],int n,int c)
{
	 int i,k,j,l,m,max=0,max_i=0,max_j=0,length;
	 int *path=(int*)malloc((n+1)*sizeof(int*));
	 int * pathway=(int*)malloc((n+1)*sizeof(int *));
	 int *w=(int*)malloc((n+1)*sizeof(int*));
	 int a[n];
	 int *result=(int*)malloc((n+1)*sizeof(int*));
	 int **mis=(int**)malloc((n+1)*sizeof(int*));
	 for(i=0;i<=n;i++)
	 {
		mis[i]=(int*)malloc((c+1)*sizeof(int));
	 }

	 int **mis_indices=(int**)malloc((n+1)*sizeof(int *));
	 for(i=0;i<=(n+1);i++)
	 {
	 	mis_indices[i]=(int*)malloc((c+1)*sizeof(int));
	
	 }

	 for(i=0;i<=n;i++)
	 	for(k=0;k<=c;k++)
			mis[i][k]=0;
	arr[0]=-9999;
	weight[0]=0;
	for(l=0;l<=n;l++)
	{
		for(m=0;m<=n;m++)
		{
			mis_indices[l][m]=0;
		}
	}
	for(i=1;i<=c;i++)
		mis[0][i]=-9999;
	 for(i=1;i<=n;i++)
	 {
	 	for(j=0;j<i;j++)
		{
			if(arr[i]>arr[j] && w[i]<w[j]+weight[i])
			{
				w[i]=w[j]+weight[i];
				path[i]=j;
			}
		}
	}
	for(k=1;k<=n;k++)
		mis[k][0]=w[k];
	for(k=1;k<=c;k++)
	{
		for(i=1;i<=n;i++)
		{
			for(j=0;j<i;j++)
			{

				if(arr[i]>arr[j] && mis[i][k]<mis[j][k]+weight[i])
				{		
					mis[i][k]=mis[j][k]+weight[i];
					mis_indices[i][k]=j;

				}
				
				if(arr[i]<=arr[j] && mis[i][k]< (mis[j][k-1]+weight[i]-((arr[j]-arr[i])*weight[i])))
				{
					mis[i][k]=mis[j][k-1]+weight[i]-((arr[j]-arr[i])*weight[i]);
					mis_indices[i][k]=j;
				}
			}
		}
	}

	for(i=1;i<=n;i++)
		mis_indices[i][0]=path[i];
	max=mis[0][0];
	for(i=0;i<=n;i++)
	{
		for(k=0;k<=c;k++)
		{
			
			if(max<mis[i][k])
			{
				max=mis[i][k];
				max_i=i;
				max_j=k;
			}
		}
	}
	printf("\n\n");
	printf("max=> %d",max);
	/*for(i=0;i<=n;i++)
	{
		printf("\n");
		for(j=0;j<=n;j++)
		{
			printf("mis[%d][%d]=%d ",i,j,mis_indices[i][j]);
		}
	}*/
	//printf("\n max_i=%d",max_i);
	//printf("\n max_j=%d",max_j);
	for(i=0;i<=n;i++)
		pathway[i]=0;
	i=max_i;

	while(i>0)
	{
		l=mis_indices[i][max_j];
		pathway[i]=l;
		i=l;
		if(i==0)
			break;
	}
	length=0;
	for(i=0;i<=n;i++)
		result[i]=0;
	for(i=0;i<=n;i++)
	{
		if(pathway[i]!=0)
		{
			//printf("%d ",pathway[i]);
			result[length++]=pathway[i];
		}
	}
	//printf("%d",max_i);
	result[length]=max_i;
	/*for(i=0;i<=n;i++)
	{

		printf("\npathway[%d]=%d arr[%d]=%d ",i,pathway[i],i,arr[i]);
	}*/
	/*for(i=0;i<=n;i++)
	{
		if(pathway[i]!=0)
			printf("%d ",arr[i]);
	}*/
	printf("\nIndices=> ");
	for(i=0;i<=n;i++)
	{
		if(result[i]!=0)
			printf("%d ",result[i]);
	}
	printf("\nElements=> ");
	for(i=0;i<=n;i++)
	{
		if(result[i]!=0)
			printf("%d ",arr[result[i]]);
	}

}


void main()
{
	 int n,i,k;
	 scanf("%d",&n);
	 scanf("%d",&k);

	 int *arr=(int*)malloc((n+1)*sizeof(int));
	 int *weight=(int*)malloc((n+1)*sizeof(int));

	 for(i=1;i<=n;i++)
	 { 	
	 	scanf("%d",&arr[i]);
		scanf("%d",&weight[i]);
	 }
	 printf("\n part a");
	 wis(arr,weight,n);
	 printf("\n");
	 printf("\n part b");
	 variations_weight(arr,weight,n,k);
	 exit(0);
}
