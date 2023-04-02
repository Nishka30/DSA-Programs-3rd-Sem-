// QUEUE USING LINKLIST
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct node
{
int queue;
 struct node *next;
}node;
node *f=NULL;
node *r=NULL;
void enque();
void deque();
void display();
int main()
{
printf("\n enter 1 to enque or insertion");
printf("\n enter 2 to deque or delation");
printf("\n enter 3 to display");
printf("\n enter 4 to exit");
char ch;
do
{
printf("\nenetr your choice=");
scanf("%d",&ch);
switch(ch)
{
case 1:
enque();
break;
case 2:
deque();
break;
case 3:
display();
break;
case 4:
 exit(0);
default:
printf(" INVALID CHOICE\n");
}
}
while(ch!=4);
return 0;
}
void enque()
{
node *temp;
temp=(node*)malloc(sizeof(node));
printf("enter the number you ant to insert=");
scanf("%d",&temp->queue);
temp->next=NULL;
if(r==NULL)
{
r=temp;
f=temp;
}
r->next=temp;
r=temp;
}
void deque()
{
node *temp;
if(f==NULL)
printf("queue is empty\n");
else
{
temp=f;
 f=f->next;
printf("dleted element is= %d",temp->queue);
temp->next=NULL;
free(temp);
}
}
void display()
{
node *temp;
if(f==NULL)
printf("queue is empty\n");
else
{
temp=f;
while(temp!=NULL)
{
printf("%d\n",temp->queue);
temp=temp->next;
}
}
}
