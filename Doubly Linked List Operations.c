# include <stdio.h>
# include <stdlib.h>
struct node
{
    int data;
    struct node *rlink;
    struct node *llink;
};
struct node *head;

void insertion_begin()
{
    int item;
    struct node *ptr;
    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr==NULL)
        printf("\n No Enough Space!\n");
    else
    {
        printf("\nEnter the value for the Node : ");
        scanf("%d", &item);
    
        if(head==NULL)
        {
            ptr->rlink=NULL;
            ptr->llink=NULL;
            ptr->data=item;
            head=ptr;
        }
        else
        {
            ptr->data=item;
            ptr->rlink=head;
            ptr->llink=NULL;
            head->llink=ptr;
            head=ptr;
        }
        printf("\nNew Node Inserted at Begin.\n");
    }
}

void display()
{
    struct node *temp;
    if (head==NULL)
        printf("\nList is Empty!\n");
    else
    {
        temp=head;
        printf("\nThe elements are :");
        while(temp!=NULL)
        {
            printf("\t%d",temp->data);
            temp=temp->rlink;
        }
    }
        
}

void insertion_last()
{
    
    int item;
    struct  node *ptr,*temp;
    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr==NULL)
        printf("\nNo Enough Space!\n");
    else
    {
        printf("\nEnter the value for the Node : ");
        scanf("%d",&item);
        if (head==NULL)
        {
            ptr->data=item;
            ptr->rlink=NULL;
            ptr->llink=NULL;
            head=ptr;
        }
        else
        {
            temp=head;
            while(temp->rlink!=NULL)
            {
                temp=temp->rlink;
            }
            temp->rlink=ptr;
            ptr->llink=temp;
            ptr->data=item;
            ptr->rlink=NULL;
            
        }
        printf("\nNew Node Inserted at Last.\n");
        
    }
    
}
void insert_at_random()
{
    int item,loctn;
    struct  node *ptr,*temp;
    ptr = (struct node*) malloc(sizeof(struct node));
    if (ptr==NULL)
        printf("\n No Enough Space!\n");
    else
    {
        printf("\nEnter the location : ");
        scanf("%d",&loctn);
        temp=head;
        
        for(int i=1;i<loctn-1;i++)
        {
            temp=temp->rlink;
         
            if(temp==NULL)
            {
                printf("\nList does not have %d elements!\n",loctn);
                return;
            }
        } 
        printf("\nEnter the value for the Node : ");
        scanf("%d",&item);
        ptr->rlink=temp->rlink;
        ptr->data=item;
        ptr->llink=temp;
        if(temp->rlink!=NULL)
            temp->rlink->llink=ptr;
        temp->rlink=ptr;
        printf("\nNew Node Inserted.\n");
    }
    
}

void deletion_begin()
{
    if(head==NULL)
        printf("\nList is Empty!\n");
    else if(head->rlink==NULL)
    {
        printf("\n%d Deleted from List. \n",head->data);
        head=NULL;
        free(head);
    }
    else
    {
        struct node *temp;
        temp=head;
        printf("\n%d Deleted from List. \n",head->data);
        head=head->rlink;
        head->llink=NULL;
        free(temp);
    }
}

void deletion_at_end()
{
    
    if(head==NULL)
    printf("\nList is Empty!\n");
    else if(head->rlink==NULL)
    {
        printf("\n%d Deleted from List. \n",head->data);
        head=NULL;
        free(head);
    }
    else
    {
        struct node *temp;
        temp=head;
        while(temp->rlink!=NULL)
            temp=temp->rlink;
        printf("\n%d Deleted from List. \n",temp->data);
        temp->llink->rlink=NULL;
        free(temp);
    }
}    
void deletion_at_random()
{
    int key;
    struct node *temp,*temp1,*temp2;
    if(head==NULL)
    
        printf("\nList is Empty!\n");
    
    else
    {
        printf("\nEnter the value to be Deleted : ");
        scanf("%d",&key);
        temp=head;
        
        while(temp->data!=key)
        {
            if(temp->rlink==NULL)
            break;
            temp=temp->rlink;
        }
        
        if(temp->data==key)
        {
            if(temp->rlink==NULL && temp->llink==NULL)
            {
                printf("\n%d Deleted from List. \n",temp->data);
                free(temp);
                head=NULL;
            }
            else
            {
                if(temp==head)
                {
                    head=head->rlink;
                    head->llink=NULL;
                    printf("\n%d Deleted from List. \n",temp->data);
                    temp=NULL;
                    free(temp);
                }
                else if(temp->rlink==NULL)
                    temp->llink->rlink=NULL;
                else
                {
                    temp->llink->rlink=temp->rlink;
                    temp->rlink->llink=temp->llink;
                    printf("\n%d Deleted from List. \n",temp->data);
                    temp=NULL;
                    free(temp);
                }
            }
    }
    else
        printf("\n%d is not present in the List!\n",key);   
    
    }
}

void search()
{
    struct node *temp;
    int key,c=1;
    if(head==NULL)
        printf("\nList is Empty!\n");
    else
    {
        printf("\nEnter the data you want to Search : ");
        scanf("%d",&key);
        temp=head;
        while(temp!=NULL)
        {   
            if(temp->data==key)
                break;
            temp=temp->rlink;
            c++;
        }
        if(temp==NULL)
            printf("\nThe Data %d is not present in the List!\n",key);
        else
            printf("\nThe Data %d is  present in the Llocation : %d\n",key,c);
    }
}
int main()
{
    int choice=0;
    while(choice != 9)  
    {  
        printf("\n\n         *********Main Menu*********\n");  
        printf("\n     Choose one option from the following list\n");  
        printf("\n  --------------------------------------------------\n");  
        printf("\n    1.Insert in begining\n    2.Insert at last\n    3.Insert at any random location\n    4.Delete from Beginning\n    5.Delete from last\n    6.Delete the node after the given data\n    7.Search\n    8.Show\n    9.Exit\n");  
        printf("\nEnter your choice : ");  
        scanf("\n%d",&choice);  
        switch(choice)
        {
            case 1: insertion_begin();break;
            case 2: insertion_last();break;
            case 3: insert_at_random();break;
            case 4: deletion_begin();break;
            case 5: deletion_at_end();break;
            case 6: deletion_at_random();break;
            case 7: search();break;
            case 8: display();break;
            case 9: exit(0);
            default : printf("\nIt's an Invalid Choice!\n");
        }
    
    }

}

