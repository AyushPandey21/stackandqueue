#include <stdio.h>
#include<stdlib.h>
struct node
{
  int data;
  struct node *next;
}*top=NULL,*front=NULL,*rear=NULL;

void insertbegin(void)
{
  struct node *t=(struct node *)malloc(sizeof(struct node));
  if(t==NULL)
     printf("stack full\n");
  else
  {
    printf("enter data \n");
    scanf("%d",&t->data);
      t->next=top;
      top=t;
  }

}

int deletebegin(struct node **p)
{
  int x=-1;
  if(*p==NULL)
  {
   printf("empty\n");

  }
  else
 {
    struct node *t=*p;
    (*p)=(*p)->next;
    x=t->data;
    free(t);
  }
  return x;
}
void displaystack(struct node *t)
{
  if(t==NULL)
  printf("stack empty\n");
  else
    while(t!=NULL)
    {
      printf("%d\n",t->data);
      t=t->next;
    }

}

void insertend(void)
{
    struct node *t=(struct node *)malloc(sizeof(struct node));
    if(t==NULL)
    printf("queue full\n");
    else
    {
      printf("enter data\n");
      scanf("%d",&t->data);
      t->next=NULL;
      if(rear==NULL)
        front=rear=t;
      else
      {


        rear->next=t;
        rear=rear->next;
      }

    }

}


void displayqueue(void)
{
  if(front==NULL)
  printf("queue empty\n");
  else
  {
    struct node *t=front;
    while(t)
    {
      printf("%d\n",t->data);
      t=t->next;
    }
  }
}
int main()
{
  int ch,ch2,ch3,n;
  do
  {
   printf("1.Stack\n2.Queue\n3.exit\n");
   printf("enter your choice\n");
   scanf("%d",&ch);
   switch(ch)
   {
     case 1:
       do
       {
         printf("1.push\n2.pop\n3.exit\n");
         printf("enter your choice\n");
         scanf("%d",&ch2);
         switch(ch2)
          {
           case 1:
             insertbegin();
             printf("stack is: \n");
             displaystack(top);
             break;
           case 2:
             n=deletebegin(&top);
             if(n!=-1)
             {printf("the elemet is %d\n",n);
              printf("stack is: \n");
             displaystack(top);
             }
             break;
           case 3:
             break;
           default : printf("wrong choice..plz see carefully\n");
          }
        }while(ch2!=3);

       break;
     case 2:

       do
       {
         printf("1.enqueue\n2.dequeue\n3.exit\n");
         printf("enter your choice\n");
         scanf("%d",&ch3);
         switch(ch3)
          {
           case 1:
             insertend();
              printf("queue is: \n");
             displayqueue();
             break;
           case 2:
             n=deletebegin(&front);
             if(n!=-1)
             {
             printf("elemet is %d\n",n);
             printf("queue is: \n");
             displayqueue();
             }
             break;
           case 3:
             break;
           default : printf("wrong choice..plz see carefully\n");
         }
       }while(ch3!=3);
      break;
     case 3:
           break;
     default : printf("wrong choice..plz see carefully\n");
  }
  }while(ch!=3);
  return 0;
}
