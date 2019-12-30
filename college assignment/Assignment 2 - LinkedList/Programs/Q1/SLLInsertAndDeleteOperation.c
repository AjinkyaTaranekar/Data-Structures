#include<stdio.h>
#include<stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
        int data;
        struct node *next;
} Node ;

Node *start=NULL;

void createSLL()
{
        Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->data);
        temp->next=NULL;
        
        if(start==NULL)
                start=temp;
        
        else{
                ptr=start;
                while(ptr->next){
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

void displaySLL(){
        Node *ptr;
        if(start==NULL){
                printf("\nList is empty:\n");
                return;
        }
        else{
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr->next){
                        printf("%d -> ",ptr->data );
                        ptr=ptr->next ;
                }
                printf("%d -> NULL",ptr->data );
        }
}

void insertAtTheBegining(){
        Node *temp;
        temp=(Node *)malloc(sizeof(Node));
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                return;
        }

        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->data);
        temp->next =NULL;
        if(start==NULL)
                start=temp;
        
        else{
                temp->next=start;
                start=temp;
        }
}

void insertAtTheEnd(){
        Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                return;
        }

        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->data );
        temp->next =NULL;
        if(start==NULL)
                start=temp;
        
        else{
                ptr=start;
                while(ptr->next){
                        ptr=ptr->next ;
                }
                ptr->next =temp;
        }
}

void insertWRTPosition(){
        Node *temp;
        temp=(Node *)malloc(sizeof(Node));
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                return;
        }
        
        int pos;
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
        printf("\nEnter the data value of the node:\t");
        scanf("%d",&temp->data) ;
 
        temp->next=NULL;
        if(pos==0){
                temp->next=start;
                start=temp;
        }

        else{
                Node *ptr=start;
                f(i,0,pos-1){
                        ptr=ptr->next;
                        if(ptr==NULL){
                                printf("\nPosition not found:[Handle with care]\n");
                                return;
                        }
                }
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}

void deleteFromTheBegining(){
        Node *ptr;
        if(ptr==NULL){
                printf("\nList is Empty:\n");
                return;
        }
        else{
                ptr=start;
                start=start->next ;
                printf("\nThe deleted element is :%d\t",ptr->data);
                free(ptr);
        }
}

void deleteFromTheEnd(){
        Node *temp,*ptr;
        if(start==NULL){
                printf("\nList is Empty:");
                exit(0);
        }
        else if(start->next ==NULL){
                ptr=start;
                start=NULL;
                printf("\nThe deleted element is:%d\t",ptr->data);
                free(ptr);
        }
        else{
                ptr=start;
                while(ptr->next){
                        temp=ptr;
                        ptr=ptr->next;
                }

                temp->next=NULL;
                printf("\nThe deleted element is:%d\t",ptr->data);
                free(ptr);
        }
}

void deleteWRTPosition(){
        Node *temp;
        if(start==NULL){
                printf("\nThe List is Empty:\n");
                exit(0);
        }
        else{
                int pos;
                printf("\nEnter the position of the node to be deleted:\t");
                scanf("%d",&pos);
                Node *ptr;
                if(pos==0){
                        ptr=start;
                        start=start->next ;
                        printf("\nThe deleted element is:%d\t",ptr->data  );
                        free(ptr);
                }
                
                else{
                        ptr=start;
                        f(i,0,pos){
                                temp=ptr;
                                ptr=ptr->next ;
                                if(ptr==NULL){
                                        printf("\nPosition not Found:\n");
                                        return;
                                }
                        }
                        temp->next =ptr->next ;
                        printf("\nThe deleted element is:%d\t",ptr->data );
                        free(ptr);
                }
        }
}

int main(){
        int choice;
        while(1){
                printf("\n***SINGLE LINKED LIST OPERATIONS:****\n");
                printf("\n                MENU                           \n");
                printf("---------------------------------------\n");
                printf("\n 1.create     \n");
                printf("\n 2.display    \n");
                printf("\n 3.Insert at the beginning    \n");
                printf("\n 4.Insert at the end  \n");
                printf("\n 5.Insert at specified position       \n");
                printf("\n 6.Delete from beginning      \n");
                printf("\n 7.Delete from the end        \n");
                printf("\n 8.Delete from specified position     \n");
                printf("\n 9.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         createSLL();
                                        break;
                        case 2:         displaySLL();
                                        break;
                        case 3:         insertAtTheBegining();
                                        break;
                        case 4:         insertAtTheEnd();
                                        break;
                        case 5:         insertWRTPosition();
                                        break;
                        case 6:         deleteFromTheBegining();
                                        break;
                        case 7:         deleteFromTheEnd();
                                        break;
                        case 8:         deleteWRTPosition();
                                        break;
                        case 9:         exit(0);
                                        break;
                        default:        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}