#define MAX 10
#include<stdio.h>
int main()
{
	int key,hash[MAX],i,j,k,prime;
	for(i=0;i<MAX;i++)
	    hash[i]=-999;
	printf("Enter the prime number within 0 and %d: ",MAX-1);
	scanf("%d",&prime);
	i=0;
	printf("Enter the 1st key: ");
	scanf("%d",&key);
	while(key!=-1 && i<MAX)
	{
		j=key%prime;
		if(hash[j]==-999)
		{
			hash[j]=key;
			printf("Allocation succesfull in proper space.");
		}
	    else
	    {
	    	j=j+1;
	    	while(hash[j]!=-999)
	    	    j++;
	    	hash[j]=key;
	    	printf("Allocation succesfull after collision resolution.");
		}
		i++;
		printf("\nEnter the next key");
		scanf("%d",&key);
	}
	printf("\nThe hash table is\n");
	printf("Format: key[index]\n");
	for(i=0;i<MAX;i++)
	    printf("%d[%d]\t",hash[i],i);
}
