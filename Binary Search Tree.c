#include<stdio.h>
#include<stdlib.h>

struct node
{
        int key;
        struct node *left;
        struct node *right;
        struct node *p;
};

struct node *root=NULL;

void insertion()
{
        int key;
        struct node *ptr,*temp,*temp1;
        ptr=(struct node*)malloc(sizeof(struct node));
        if(ptr==NULL)
                printf("\nNo Space is Available");
        else
        {
                printf("\nEnter the data to be inserted : ");
                scanf("%d",&key);
                ptr->key=key;
                ptr->left=NULL;
                ptr->right=NULL;
                if(root==NULL)
                {
                        ptr->p=NULL;
                        root=ptr;
                }
                else
                {
                        temp=root;
                        while(temp!=NULL)
                        {
                                temp1=temp;
                                if(key < temp->key)
                                        temp=temp->left;
                                else
                                        temp=temp->right;
                        }
                        ptr->p=temp1;
                        if(key< temp1->key)
                            temp1->left=ptr;
                        else
                                temp1->right=ptr;
                }
        }
}

void inorder(struct node *temp)
{
        if(root == NULL)
        {       printf("\nTree is Empty..!!");
                return;
        }
        if (temp==NULL)
        return;
        inorder(temp -> left);
        printf("%d ",temp->key);
        inorder(temp -> right);
}
void transplant(struct node *x,struct node *y)
{
        if(x->p==NULL)
                root=y;
         else if(x==x->p->left)
                x->p->left=y;
        else
                x->p->right=y;
        if(y!=NULL)
                y->p=x->p;
        

}
struct node* tree_minimum(struct node *x)
{
        while (x->left!=NULL)
                x=x->left;
        return x;
}
void deletion()
{
        int  key;
        struct node *temp,*successor;;
        if (root==NULL)
                printf("\nTree is Empty..!!");
        else
        {
            printf("\nEnter the Key to be Deleted : ");
                scanf("%d",&key);
                temp=root;
                while(temp!=NULL && temp->key!=key)
                {       
                        if(key < temp->key)
                                temp=temp->left;
                        else
                                temp=temp->right;
                }

                if(temp==NULL)
                        printf("\nKey is Not Found in the Tree");
                else
                {       if(temp->right==NULL && temp->left==NULL)
                        {   if(temp->p==NULL)
                                root=NULL;
                            else{
                                if(temp==temp->p->left)
                                        temp->p->left=NULL;
                                if(temp==temp->p->right)
                                        temp->p->right=NULL;
                            }

                        }
                        else if(temp->left==NULL)
                            transplant(temp,temp->right);
                        else if(temp->right==NULL)
                                transplant(temp,temp->left);
                        else
                        {
                                successor=tree_minimum(temp->right);
                                if(successor->p!=temp)
                                {
                                        transplant(successor,successor->right);
                                        successor->right=temp->right;
                                        successor->right->p=successor;
                                }
                                transplant(temp,successor);
                                successor->left=temp->left;
                                successor->left->p=successor;
                        }
                        printf("\n%d Deleted from Tree",temp->key);

                }

        }
}

void search()
{
        struct node *temp;
        int item,flag=0;
        temp=root;
        if(root==NULL)
                printf("\nTree is Empty");
        else
        {
                printf("\nEnter the Value to be Searched");
                scanf("%d",&item);
                while(temp!=NULL)
                {
                        if(temp->key==item)
                                flag=1;
                        if(item < temp->key)
                                temp=temp->left;
                        else
                                temp=temp->right;
                }
                if(flag==1)
                        printf("\nElement is Found");
                else
                     printf("\nElement not Found");
        }
}
void main()
{
        int choice=0;
        while(choice!=5)
        {
                printf("\n\n1.Insertion\n2.Deletion\n3.Search\n4.Display\n5.Exit");
                printf("\nEnter the Choice : ");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:insertion();break;
                        case 2:deletion();break;
                        case 3:search();break;
                        case 4:inorder(root);break;
                        case 5:exit(0);break;
                        default:printf("\n Choosen an Invalid Choice..!!");
                }
        }
}
