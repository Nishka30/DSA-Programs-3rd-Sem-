#include<stdio.h>
#include<stdlib.h>
int a[100],N;
void bubble_sort()
{
	int i,j,temp;
	for(i=0;i<(N-1);i++)  //no. of passes=(total no. of elements - 1)
	{
		for(j=0;j<(N-i-1);j++)  //no. of comparisons=(total no. of elements - i - 1)
	    {
	    	if(a[j]>a[j+1])
		    {
			    temp=a[j];
			    a[j]=a[j+1];
			    a[j+1]=temp;
		    }
		}
	}
	printf("\nThe sorted array after bubble sort is:-\n");
	for(i=0;i<=(N-1);i++)
	{
		printf("%d ",a[i]);
	}
}
void selection_sort()
{
	int i,j,min_pos,temp;
	for(i=0;i<N-1;i++)
	{
		min_pos=i;
		for(j=i+1;j<N;j++)
		{
			if(a[j]<a[min_pos])
				min_pos=j;
		}
		if(min_pos!=i)
		{
			temp=a[i];
			a[i]=a[min_pos];
			a[min_pos]=temp;
		}
	}
	printf("\nThe sorted array after selection sort is:-\n");
	for(i=0;i<N;i++)
		printf("%d ",a[i]);
}
void insertion_sort()
{
	int i,j,temp;
	for(i=1;i<N;i++)
	{
		temp=a[i];
		j=i-1;
		while(temp<a[j] && j>=0)
		{
			a[j+1]=a[j];
			--j;
		}
		a[j+1]=temp;
	}
	printf("\nThe sorted array after insertion sort is:-\n");
    for(i=0;i<N;i++)
		printf("%d ",a[i]);
}
void merge(int low, int mid, int high)
{
	int i=low,j=mid+1,k=low;
	int b[20];
	while((i<=mid)&&(j<=high))
	{
		if(a[i]<a[j])
	        b[k++]=a[i++];
	    else
	        b[k++]=a[j++];
	}
	while(i<=mid)
		b[k++]=a[i++];
	while(j<=high)
	    b[k++]=a[j++];
	for(k=low;k<=high;k++)
	    a[k]=b[k];
}
void merge_sort(int low, int high)
{
	int mid,i;
	if(low<high)
	{
		mid=(low+high)/2;
		merge_sort(low,mid);
		merge_sort(mid+1,high);
		merge(low,mid,high);
	}
}
int partition(int low, int high)
{
	int i=low,j=high,p=low,temp,temp1;
	while(i<j)
	{
		while(a[p]>=a[i])
		    i++;
		while(a[p]<a[j])
		    j--;
		if(i<j)
		{
			temp=a[i];
			a[i]=a[j];
			a[j]=temp;
		}
	}
	temp1=a[p];
	a[p]=a[j];
	a[j]=temp1;
	return j;
}
void quick_sort(int low,int high)
{
	int j,i;
	if(low<high)
	{
		j=partition(low,high);
		quick_sort(low,j-1);
		quick_sort(j+1,high);
	}
}
int main()
{
	int i,choice;
	while(1)
	{
		printf("\nEnter the size of the array: ");
	    scanf("%d",&N);
	    printf("Enter elements in array:\n");
	    for(i=0;i<N;i++)  //input of array
			scanf("%d",&a[i]);
		printf("\nThe array before sorting is:-\n");
		for(i=0;i<N;i++)
			printf("%d ",a[i]);
		printf("\nUSER'S CHOICE:\nEnter 1 for bubble sort\nEnter 2 for selection sort\nEnter 3 for insertion sort\nEnter 4 for merge sort\nEnter 5 for quick sort\nEnter 6 to exit\nEnter your choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: bubble_sort();
			        break;
			        
			case 2: selection_sort();
			        break;
			        
			case 3: insertion_sort();
			        break;
			        
			case 4: merge_sort(0,N-1);
					printf("\nThe sorted array after merge sort is:-\n");
					for(i=0;i<=(N-1);i++)
					{
						printf("%d ",a[i]);
					}
			        break;
			        
			case 5: quick_sort(0,N-1);
					printf("\nThe sorted array after quick sort is:-\n");
					for(i=0;i<=(N-1);i++)
					{
						printf("%d ",a[i]);
					}
			        break;
			        
			case 6: exit(0);
			        
			default: printf("Inappropriate Choice");
		}
    }
    return 1;
}

	
	
