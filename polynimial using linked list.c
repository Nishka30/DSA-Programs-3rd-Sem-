#include<stdio.h>
#include<stdlib.h>
struct node
{
	int coef;
	int exp;
	struct node* link;
};
typedef struct node S; 
S *start1=NULL,*start2=NULL,*newnode,*ptr,*loc;
S* create(S *start)
{
	char c;
	int flag=1;
	do
	{
		newnode=(S*)malloc(sizeof(S));
		if(newnode==NULL)
		{
			printf("Memory space could not be allocated.");
			break;
		}
		if(start==NULL)
    	{
    		start=newnode;
    		newnode->link=NULL;
    		printf("Enter coefficient for 1st polynomial: ");
    		scanf("%d",&newnode->coef);
    		printf("Enter exponent for 1st polynomial: ");
    		scanf("%d",&newnode->exp);
    		printf("\n");
    		++flag;
		}
		else
		{
			ptr=start;
			while(ptr->link!=NULL)
			    ptr=ptr->link;
			ptr->link=newnode;
		    newnode->link=NULL;
		    printf("Enter coefficient for %dth polynomial: ",flag);
    		scanf("%d",&newnode->coef);
    		printf("Enter exponent for %dth polynomial: ",flag);
    		scanf("%d",&newnode->exp);
    		printf("\n");
    		++flag;
		}
		printf("Do you want to insert another polynomial(Y/N)?");
		scanf(" %c",&c);
	}while(c=='Y'||c=='y');
	return start;
}
void display(S *start)
{
	ptr=start;
	while(ptr!=NULL)
	{
		if(ptr->exp!=0)
		    printf("%dx^%d",ptr->coef,ptr->exp);
		else
		    printf("%d",ptr->coef);
		ptr=ptr->link;
		if(ptr!=NULL)
		    printf("+");
	}
}
void add()
{
	
}
int main()
{
	printf("Enter data for 1st expression:\n");
	start1=create(start1);
    printf("\nEnter data for 2nd expression:\n");
	start2=create(start2);
	printf("\nThe 1st polynomial is:\n");
	display(start1);
	printf("\nThe 2nd polynomial is:\n");
	display(start2);
	
	
	
	
	
	
	
	
	
}
