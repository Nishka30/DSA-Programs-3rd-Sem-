
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
typedef struct nodes
{
 int stack;
 struct nodes *next;
}node;
node *top=NULL;
void push();
void pop();
void display();
 
int main()
{
 
 int ch;
 printf("\n Enter 1 to push or insert");
 printf("\n Enter 2 to pop or delete");
 printf("\n Enter 3 to display");
 printf("\n Enter 4 to exit");
 
 while(ch!=4)
 {
 printf("\n Enter your choice ::");
 scanf(" %d",&ch);
 switch(ch)
 {
 case 1:
 push();
break;
 case 2:
 pop();
 break;
 case 3:
 display();
 break;
 case 4:
 exit(0);
 default:
 printf("INVALID CHOICE\n");
 }
 }
 return 0;
}
void push()
 {
 node *temp;
 temp=(node*)malloc(sizeof(node));
 printf("Enter the number you want to insert ::");
 scanf("%d",&temp->stack);
 temp->next=top;
 top=temp;
 display();
 }
 void pop()
 {
 node *temp;
 if(top==NULL)
 printf("Stack is empty\n");
 else
 {
 temp=top;
 top=top->next;
 printf("Deleted element is %d",temp->stack);
 temp->next=NULL;
 free(temp);
 }
 }
 void display()
 {
 node *temp;
 if(top==NULL)
 printf("Stack is empty\n");
 else
 {
 temp=top;
while(temp!=NULL)
 {
 printf("%d ",temp->stack);
 temp=temp->next;
 }
 }
 }
