#include<stdio.h>
#include<stdlib.h>
struct node
{
int data;
struct Node *next;
};
struct node *first=NULL;
struct node *second=NULL;

void create(int arr[],int n)
{
    struct node *last=NULL,*t=NULL;
    int i;
    first=(struct node* )malloc(sizeof(struct node *));
    first->data=arr[0];
    first->next=NULL;
    last=first;
    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node *));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}//end of the create function
void create1(int arr[],int n){
    struct node *last=NULL,*t=NULL;
    int i;
    second=(struct node* )malloc(sizeof(struct node *));
    second->data=arr[0];
    second->next=NULL;
    last=second;

    for(int i=1;i<n;i++)
    {
        t=(struct node *)malloc(sizeof(struct node *));
        t->data=arr[i];
        t->next=NULL;
        last->next=t;
        last=t;
    }
}//end of the create function
int countnoofnodes()
{
    struct node *temp=first;
    int count=0;
    if(first==NULL)
    {
        return 0;
    }
    else
    {
        while(temp!=NULL)
        {
            count++;
            temp=temp->next;
        }
    }
    return count;
}//end of the function
void insert(int pos,int data)
{
    int count=countnoofnodes(first);
    struct node *t,*temp=first,*temp1=first;
    if(pos<1 ||pos>(count+1))
    return;
    t=(struct node * )malloc(sizeof(struct node));
    t->data=data;
    t->next=NULL;
    if(pos==1)
    {
    t->next=first;
    first=t;
    }
    else if(pos==(count+1))
    {
    while(temp->next!=NULL)
    {
    temp=temp->next;
    }
    temp->next=t;
    }
    else
    {
    for(int i=1;i<pos-1;i++)
    {
    temp1=temp1->next;
    }
    t->next=temp1->next;
    temp1->next=t;
    }
}//end of the insert function
void display(struct node *t)
{
    printf("\n the linked list is being given by as follows");
    if(t==NULL)
    {
        printf("the linked list is empty");
    }
    else
    {
        while(t!=NULL)
        {
            printf(" %d-> ",t->data);
            t=t->next;
        }
    }
}//end of the display function
int count(struct node *t,int number)
{
    int counting=0;
    if(t==NULL)
        return 0;
    else
    {
        while(t!=NULL)
        {
            if(t->data==number)
            {
                counting++;
            }
            t=t->next;
            }//end of the while loop
    }//else
    return counting;
}
int main()
{
    int a[]={1,2,4,11,15};
    int num;
    create(a,5);
    insert(3,55);
    insert(1,13);
    display(first);
    printf("\nEnter the number you want\n");
    scanf("%d",&num);
    int result=count(first,num);
    printf("\nThe number of times the number %d occurs is %d",num,result);
}