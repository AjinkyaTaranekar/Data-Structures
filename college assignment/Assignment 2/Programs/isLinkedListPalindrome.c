#include <stdio.h>
#include <stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
	int data;
	struct node *next;	
}Node;

Node* head = NULL;

void insertAtBeginning(int data)
{
	Node* temp=(Node *)malloc(sizeof(Node));
		
    temp->data=data;
    temp->next=NULL;

    if(head==NULL)
            head=temp;
    
    else{
            while(head->next){
                    head=head->next ;
            }
            head->next =temp;
    }
}

void display(){

	Node *temp= head;
	while(temp->next){
			printf("%d -> ",temp->data);
			temp=temp->next; 
		}
        printf("%d -> NULL",temp->data);	
}

void reverseListIteratively()
{
	Node *temp=NULL,*prev=NULL,*ptr=head;
	while(ptr!=NULL){
        temp=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=temp;
	}
    head=prev;
}

Node* middleOfList(){
	
	Node*slow=head,*fast=head;
	while(fast&&fast->next){
			slow=slow->next;
			fast=fast->next->next;
		}
	return slow;
}

int isPalin(Node *middle){
	
	while(middle != NULL){
		if(middle->data != head->data)
			return 0;
		head = head->next;
		middle = middle->next;
	}
	return 1;
}


int main()
{
	int size;
    printf("Enter size :-\n");
	scanf("%d", &size);

    int data;
    printf("Enter elements:-\n");
    f(i,0,size){
        scanf("%d", &data); 
        insertAtBeginning(data);
    }
	
	printf("Given List is :-\n");
	display();
	
	Node * middle = middleOfList();
	reverseListIteratively(middle);
	
	if(isPalin(middle))
		printf("\nGiven list is a palindrome\n");
	
	else
		printf("\nGiven list is not a palindrome \n");
	
	return 0;
}