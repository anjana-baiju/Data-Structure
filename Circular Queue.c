#include <stdio.h>
#include<stdlib.h>

int queue[100],max;
int front=-1;
int rear=-1;

void enqueue()
{  int x;
    if((rear+1)%max==front)
    {
        printf("Queue is overflow..!!");
    }

    else
    {
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&x);
        if(front==-1 && rear==-1)
    {
        front=0;
        rear=0;
        queue[rear]=x;
    }
    else
    {

        rear=(rear+1)%max;
        queue[rear]=x;
    }
    }
}


void dequeue()
{
    if((front==-1) && (rear==-1))
    {
        printf("\nQueue is underflow..!!");
    }
 else if(front==rear)
{
   printf("\nThe dequeued element is %d", queue[front]);
   front=-1;
   rear=-1;
}
else
{
    printf("\nThe dequeued element is %d", queue[front]);
   front=(front+1)%max;
}
}

void display()
{
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty..!!");
    }
    else
    {
        printf("\nElements in a Queue are :");
        for(int i=front;;i=(i+1)%max)
        {
            printf("%d ", queue[i]);
            if((i+1)%max==rear)
            break;
        }
	 printf("%d.", queue[rear]);
    }
}
void Search()
{
    int key,count=0;
    if(front==-1 && rear==-1)
    {
        printf("\n Queue is empty..!!");
    }
    else
    {
        printf("\nenter the element to be searched : ");
        scanf("%d",&key);
        for(int i=front;i<=rear;i=(i+1)%max)
        {

            if((i+1)%max==rear)
            break;
            if(queue[i]==key)
                count++;
        }
	if(queue[rear]==key)
                count++;


        if(count>0)
            printf("\nElement is found..!!");
        else
            printf("\nElement not found..!!");

    }
}

void main()
{
    int choice=1,x;
    printf("\nEnter the size of array : ");
    scanf("%d",&max);
    while(choice!=5)
    {
    	printf("\nPress 1: Insert an element");
    	printf("\nPress 2: Delete an element");
    	printf("\nPress 3: Display the element");
     	printf("\nPress 4: Search the element");
    	printf("\nPress 5: Exit");
    	printf("\nEnter your choice : ");
    	scanf("%d", &choice);

    	switch(choice)
    	{

        	case 1:enqueue();
        		break;
        	case 2:dequeue();
        		break;
        	case 3:display();
			break;
        	case 4: Search();
			break;
        	case 5:exit(0);
        	default: printf("\nInvalid choice..!!");
	}
    }
}


