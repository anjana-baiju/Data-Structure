#include <stdio.h>
int queue[10], rear=-1,front=-1,n,choice,a;
void insert(){
    if(rear>=n-1)
    {
        printf("\nAlert : Queue Overflow");
    }
    else if(front=-1)
    {
        printf("\nEnter the element to be inserted ");
        scanf("%d",&a);
        rear++;front++;
        queue[rear]=a;
        printf("\nElement inserted successfully ");
    }
    else{
        printf("\nEnter the element to be inserted ");
        scanf("%d",&a);
        rear++;
        queue[rear]=a;
        printf("\nElement inserted successfully ");
    }
}
void delete(){
    if((front==-1) || (front>rear))
    {
        printf("\nAlert : Queue Underflow");
    }
    
    else{
        
        printf("\n%d deleted from Queue",queue[front]);
        
        front++;
    }
}
void display()
{
    if((front==-1) || (front>rear))
        printf("\nQueue is Empty");
    
    else{
        printf("\nQueue Elements are :\n");
        for(int i=front;i<=rear;i++)
        {
            printf("\t%d",queue[i]);
            
        }
    }
}
void main() {
    
    printf("\nEnter the size of the queue (Max : 100) ");
    scanf("%d",&n);
    
    do
    {   printf("\n\n ****Choose the Operation  ***");
        printf("\n 1.Insert \t 2.Delete \t 3.Display \t 4.Exit ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: insert();break;
            case 2:delete();break;
            case 3: display();break;
            case 4 : printf("Exits");break;
            default: printf("\nPlease enter a valid choice");break;
        }
    }while(choice!=4);
    
}
