#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *LINK;
};

struct node *top=NULL;
void push()
{
    struct node *ptr;
    
    ptr=(struct node *)malloc(sizeof(struct node *));   
    if(ptr==NULL)
        printf("\nNo space available ");
    else{
        printf("\nEnter the data to be inserted : ");
        scanf("%d",&ptr->data);
        ptr->LINK=NULL;
        if(top==NULL)
            top=ptr;
        else{   
            ptr->LINK=top;
            top=ptr;
        }
        printf("\n%d inserted into the stack : ",ptr->data);
        
    }

}
void display()
{
    struct node *temp;
    temp=top;
    if(top==NULL)
        printf("\nUnderflow");
    else{
        printf("\nElements in the Stack are :");
        while(temp!=NULL){
            printf("\t%d",temp->data);
            temp=temp->LINK;
        }
    }
}
void pop(){
  
  printf("\n%d popped from stack",top->data);
  top=top->LINK;
}
int main()
{
    int choice;
    
    do
    {   
        printf("\n\n1.Push\n2.Pop\n3.Display\n4.Exit");
        printf("\nEnter a choice ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:push();break;
            case 2:pop();break;
            case 3:display();break;
            case 4:exit(0);
            default: printf("\nChoosen an invalid number");
        }
    }while(choice!=4);
}

