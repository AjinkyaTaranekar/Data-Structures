#include <stdio.h>
#include <stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
	int data;
	struct node *next;	
}Node;


void create(Node **original)
{
        Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

        scanf("%d",&temp->data);
        temp->next=NULL;
        
        if(*original==NULL)
                *original=temp;
        
        else{
                ptr=*original;
                while(ptr->next){
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

void swap(int *a, int *b)
{
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void pairWiseSwapping(Node *first)
{
    Node *temp = first;
    while (temp != NULL && temp->next != NULL){
        swap(&temp->data, &temp->next->data);
        temp = temp->next->next;
    }
}

void altNode(Node *first){
    Node *temp = first, *p;
    while (temp != NULL && temp->next != NULL){
        p = temp->next;
        temp->next = p->next;
        temp = p->next;
    }
 }

void mergeTwoLLInAlt(Node *first,Node *second){

    Node *p_curr = first, *q_curr = second;  
    Node *p_next, *q_next;  
  
    while (p_curr != NULL && q_curr != NULL)  
    {  
        p_next = p_curr->next;  
        q_next = q_curr->next;  
  
        q_curr->next = p_next; // Change next pointer of q_curr  
        p_curr->next = q_curr; // Change next pointer of p_curr  
  
        p_curr = p_next;  
        q_curr = q_next;  
    }  
  
    second = q_curr; // Update head pointer of second list  
}  

void display(Node *first){
    Node *ptr = first;
	while(ptr->next){
			printf("%d -> ",ptr->data);
			ptr=ptr->next; 
		}
        printf("%d -> NULL\n",ptr->data);	
}

Node * duplicateLL(Node *original){
    Node* ptr = (Node*)malloc(sizeof(Node));
    ptr->data=original->data;
    ptr->next=original->next;
    return ptr;
}

int main()
{
	Node *original=NULL;
    int size;

    printf("Enter size :-\n");
	scanf("%d", &size);

    printf("Enter elements:-\n");
    f(i,0,size)
        create(&original);
	
	printf("Given List is :-\n");
	display(original);
    
    Node *temp = NULL;
    int choice;
    while(1){
                printf("\n***SINGLE LINKED LIST OPERATIONS:****\n");
                printf("\n                MENU                           \n");
                printf("---------------------------------------\n");
                printf("\n 1. Pair wise swapping     \n");
                printf("\n 2. Remove alternate nodes    \n");
                printf("\n 3. Merge two LL in alternate manner    \n");
                printf("\n 4.Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         temp = duplicateLL(original);
                                        pairWiseSwapping(temp);
                                        display(temp);
                                        temp=NULL;
                                        break;

                        case 2:         temp = duplicateLL(original);
                                        altNode(temp);
                                        display(temp);
                                        temp=NULL;
                                        break;

                        case 3:         temp = duplicateLL(original);
                                        printf("Another list :-\n");
                                        Node *anotherList=NULL;
                                        printf("Enter size :-\n");
                                        scanf("%d", &size);

                                        printf("Enter elements:-\n");
                                        f(i,0,size)
                                            create(&anotherList);
                                        
                                        printf("Given Another List is :-\n");
                                        display(anotherList);
                                        
                                        mergeTwoLLInAlt(temp,anotherList);
                                        display(temp);
                                        temp=NULL;
                                        break;

                        case 4:         exit(0);
                                        break;

                        default:        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
	return 0;
}