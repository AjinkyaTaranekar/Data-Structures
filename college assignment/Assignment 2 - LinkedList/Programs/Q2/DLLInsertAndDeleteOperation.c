#include<stdio.h>
#include<stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
        int data;
        struct node* previous;
        struct node *next;
} Node ;

Node *start=NULL;

void createDLL()
{
        Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

        printf("\nEnter the data value for the node:\t");
        scanf("%d",&temp->data);
        temp->previous=NULL;
        temp->next=NULL;
        
        if(start==NULL)
                start=temp;
        
        else{
                ptr=start;
                while(ptr->next){
                        ptr=ptr->next;
                }
                ptr->previous=ptr->next;
                ptr->next=temp;
        }
}

void displayDLL(){
        Node *ptr;
        if(start==NULL){
                printf("\nList is empty:\n");
                return;
        }
        else{
                ptr=start;
                printf("\nThe List elements are:\n");
                while(ptr->next){
                        printf("%d <-> ",ptr->data );
                        ptr=ptr->next ;
                }
                printf("%d <-> NULL",ptr->data );
        }
}
void insertWRTPosition(Node *temp){
        int pos;
        printf("\nEnter the position for the new node to be inserted:\t");
        scanf("%d",&pos);
 
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
                temp->previous = temp->next;
                temp->next =ptr->next ;
                ptr->next=temp;
        }
}
void insert(int choice){
    Node *temp;
        temp=(Node *)malloc(sizeof(Node));
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                return;
        }

        printf("\nEnter the data value for the node:\t" );
        scanf("%d",&temp->data);
        temp->previous=NULL;
        temp->next =NULL;

        Node *ptr;
        if(start==NULL)
                start=temp;
        
        else{     
                if (choice==3){ //begining
                    temp->previous=temp->next;
                    temp->next=start;
                    start=temp;
                }       
                else if (choice==4){ //create at the end
                    ptr=start;
                    while(ptr->next){
                            ptr=ptr->next;
                    }
                    ptr->previous=ptr->next;
                    ptr->next=temp;
                }
                else if (choice==5) // create wrt position 
                        insertWRTPosition(temp);
            }
}
int countNoOfNodes(){
        int len =0;
        Node * ptr = start;
        while(ptr){
                len++;
                ptr=ptr->next;
        }
        return len;
}
void delete (int pos){
        Node *t = start, *temp = start, *p = NULL, *q = NULL;
        int count = countNoOfNodes();
        if (pos < 1 || pos > count){
                printf("\nPosition %d not found. ",pos);
                return;
        }
        
        else if (pos == 1){
                if(start->next){
                        start = start->next;
                        start->previous = NULL;
                }
                else
                        start=NULL;
                printf("\nDeleted first Node. ");
        }

        else if (pos == count){
                while(temp->next)
                        temp = temp->next;
                temp->next = NULL;
                printf("hi");
                temp=temp->previous;
                printf("\nDeleted last Node. ");
        }
        else{
                for (int i = 1; i < pos; i++)
                        t = t->next;
                p = t->previous;
                p->next = t->next;
                q = t->next;
                q->previous = t->previous;
                printf("\nDeleting Node at position %d. ",pos);
        }
}

int main(){
        int choice,pos;
        while(1){
                printf("\n***DOUBLY LINKED LIST OPERATIONS:****\n");
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
                        case 1:         insert(4);
                                        break;
                        case 2:         displayDLL();
                                        break;
                        case 3:         insert(3);
                                        break;
                        case 4:         insert(4);
                                        break;
                        case 5:         insert(5);
                                        break;
                        case 6:         delete(1);
                                        break;
                        case 7:         delete(countNoOfNodes());
                                        break;
                        case 8:         printf("\n Enter position to be deleted:\n");
                                        scanf("%d",&pos);
                                        delete(pos);
                                        break;
                        case 9:         exit(0);
                                        break;
                        default:        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
        return 0;
}