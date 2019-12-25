#include <stdio.h>
#include <stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
	int data;
	struct node *next;	
}Node;

void create(Node **head,int data)
{
	Node* temp=(Node *)malloc(sizeof(Node));
		
    temp->data=data;
    temp->next=NULL;

    Node * ptr = *head;
    if(*head==NULL)
            *head=temp;
    else{
            while(ptr){
                    ptr=ptr->next ;
            }
            ptr->next =temp;
    }
    return;
}

void display(Node *head){

	while(head->next){
			printf("%d -> ",head->data);
			head=head->next; 
		}
        printf("%d -> NULL\n",head->data);	
}

void count(Node *head, int data){
    Node *ptr = head;
    int count=0;
    while(ptr){
        if(ptr->data == data)
            count++;
        ptr=ptr->next;
    }
    printf("Given %d occur %d times.",data,count);
}

int main()
{
	int size;
    printf("Enter size :-\n");
	scanf("%d", &size);

    Node *head=NULL;
    int data;
    printf("Enter elements:-\n");
    f(i,0,size){
        scanf("%d", &data); 
        create(&head,data);
    }
	
	printf("Given List is :-\n");
	display(head);
    
	int numToBeFound;
    printf("Enter number to be found :-\n");
	scanf("%d", &numToBeFound);
	count(head,numToBeFound);

	return 0;
}