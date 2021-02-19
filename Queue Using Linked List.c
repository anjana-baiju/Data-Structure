#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *LINK;
};

struct node *front=NULL,*rear=NULL;

void enqueue()
{
    struct node *ptr;
    
    ptr=(struct node *)malloc(sizeof(struct node *));   
    if(ptr==NULL)
        printf("\nNo space available ");
    else{
        printf("\nEnter the data to be inserted : ");
        scanf("%d",&ptr->data);
        ptr->LINK=NULL;
        if(front==NULL){
            front=ptr;
            rear=ptr;
        }
        else{   
            rear->LINK=ptr;
            rear=ptr;
        }
        printf("\n%d inserted into the queue. ",ptr->data);
        
    }

}
void display()
{
    struct node *temp;
    temp=front;
    if(rear==NULL)
        printf("\nUnderflow");
    else if (rear->LINK==front)
        printf("\nUnderflow");
    else{
        printf("\nElements in the Queue are :");
        while(temp!=NULL){
            printf("\t%d",temp->data);
            temp=temp->LINK;
        }
    }
}
void dequeue(){
  struct node *temp;
    temp=front;
    if(rear==NULL){
        printf("\nUnderflow");
        return;}
    else if (rear->LINK==front){
        printf("\nUnderflow");
        return;
    }
  printf("\n%d deleted from Queue",front->data);
  front=front->LINK;
  free(temp);
}
int main()
{
    int choice;
    
    do
    {   
        printf("\n\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit");
        printf("\nEnter a choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:enqueue();break;
            case 2:dequeue();break;
            case 3:display();break;
            case 4:exit(0);
            default: printf("\nChoosen an invalid number");
        }
    }while(choice!=4);
}

