#include <stdio.h>
int stack[10], top=-1,n,choice,a;
void push(){
    if(top>=n-1)
    {
        printf("\nAlert : Stack Overflow");
    }
    else{
        printf("\nEnter the element to be inserted ");
        scanf("%d",&a);
        top++;
        stack[top]=a;
        printf("\nElement inserted successfully ");
    }
}
void pop(){
    if(top==-1)
    {
        printf("\nAlert : Stack Underflow");
    }
    else{
        
        printf("\n%d deleted from Stack",stack[top]);
        top--;
    }
}
void display()
{
    if(top==-1)
    printf("Stack is Empty");
    else{
        printf("Stack Elements are :\n");
        for(int i=0;i<=top;i++)
        {
            printf("\t%d",stack[i]);
            
        }
    }
}
void main() {
    
    printf("\nEnter the size of the stack (Max : 100) ");
    scanf("%d",&n);
    
    do
    {   printf("\n\n ****Choose the Operation  ***");
        printf("\n 1.Push \t 2.Pop \t 3.Display \t 4.Exit ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: push();break;
            case 2:pop();break;
            case 3: display();break;
            case 4 : printf("Exits");break;
            default: printf("\nPlease enter a valid choice");break;
        }
    }while(choice!=4);
    
}
