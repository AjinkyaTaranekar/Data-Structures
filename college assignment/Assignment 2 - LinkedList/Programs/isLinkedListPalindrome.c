#include <stdio.h>
#include <stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
	int data;
	struct node *next;	
}Node;

Node *start=NULL;

void create()
{
        Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

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

void display(){
    Node *ptr = start;
	while(ptr->next){
			printf("%d -> ",ptr->data);
			ptr=ptr->next; 
		}
        printf("%d -> NULL\n",ptr->data);	
}

void reverseListIteratively()
{
	Node *temp=NULL,*prev=NULL,*ptr=start;
	while(ptr!=NULL){
        temp=ptr->next;
        ptr->next=prev;
        prev=ptr;
        ptr=temp;
	}
    start=prev;
}

Node* middleOfList(){
	
	Node*slow=start,*fast=start;
	while(fast&&fast->next){
			slow=slow->next;
			fast=fast->next->next;
		}
	return slow;
}

int isPalin(Node *middle){
	
	while(middle != NULL){
		if(middle->data != start->data)
			return 0;
		start = start->next;
		middle = middle->next;
	}
	return 1;
}


int main()
{
	int size;
    printf("Enter size :-\n");
	scanf("%d", &size);

    printf("Enter elements:-\n");
    f(i,0,size){
        create();
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