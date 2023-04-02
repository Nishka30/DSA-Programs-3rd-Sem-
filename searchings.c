#include<stdio.h>
#include<stdlib.h>
int a[100],N;
void linear_search()
{
	int i,key,c=0;
	printf("\nEnter the key value to be searched for: ");
	scanf("%d",&key);
	for(i=0;i<N;i++)
	{
		if(a[i]==key)
		{
			c=1;
			break;
		}
	}
	if(c==0)
	    printf("Key value %d dosen't exists in array.",key);
	else
	    printf("Key value %d is found at position: %d.",key,i+1);
}
void binary_search()
{
	int i,l,u,mid,key,c=0;
	printf("\nEnter the key value to be searched for: ");
	scanf("%d",&key);	
	l=0;
	u=N-1;
	while(l<=u)
	{
		mid=(l+u)/2;
		c++;
		if(a[mid]==key)
		    break;
		else if(a[mid]>key)
		    u=mid-1;
		else
		    l=mid+1;
	}
	if(l>u)
	    printf("Key value %d dosen't exists in array.",key);
	else
	    printf("Key value %d is found at position: %d, passes=%d",key,mid+1,c);
}
void interpolation_search()
{
	int i,l,u,mid,key,c=0;
	printf("\nEnter the key value to be searched for: ");
	scanf("%d",&key);	
	l=0;
	u=N-1;
	while(l<=u)
	{
		mid=l+(((double)(u-l)/(a[u]-a[l]))*(key-a[l]));
		c++;
		if(a[mid]==key)
		    break;
		else if(a[mid]>key)
		    u=mid-1;
		else
		    l=mid+1;
	}
	if(l>u)
	    printf("Key value %d dosen't exists in array.",key);
	else
	    printf("Key value %d is found at position: %d, passes=%d",key,mid+1,c);
}
int main()
{
	int i,choice;
	while(1)
	{
		printf("\nEnter the size of the array: ");
	    scanf("%d",&N);
	    for(i=0;i<N;i++)  //input of array
	    {
			printf("Enter element %d: ",(i+1));
			scanf("%d",&a[i]);
		}
		printf("\nThe array is:-\n");
		for(i=0;i<N;i++)
			printf("%d ",a[i]);
		printf("\nUSER'S CHOICE:\nEnter 1 for linear search\nEnter 2 for binary search\nEnter 3 for interpolation search\nEnter 4 to exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: linear_search();
			        break;
			        
			case 2: binary_search();
			        break;
			        
			case 3: interpolation_search();
			        break;
			        
			case 4: exit(0);
			
			default: printf("Inappropriate Choice");
		}
    }
    return 1;
}
