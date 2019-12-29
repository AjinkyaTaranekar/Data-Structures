#include <stdio.h>
#include <stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
	int data;
	struct node *next;	
}Node;

void create(Node **list)
{
        Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

        scanf("%d",&temp->data);
        temp->next=NULL;
        
        if(*list==NULL)
                *list=temp;
        
        else{
                ptr=*list;
                while(ptr->next){
                        ptr=ptr->next;
                }
                ptr->next=temp;
        }
}

void display(Node *list){
    Node *ptr = list;
	while(ptr->next){
			printf("%d -> ",ptr->data);
			ptr=ptr->next; 
		}
        printf("%d -> NULL\n",ptr->data);	
}


void reverseListIteratively(Node *list, Node **revList){
	Node* current = list; 
	Node *prev = NULL, *next = NULL; 
	
	while (current != NULL) { 
		next = current->next; 
		current->next = prev; 
		prev = current; 
		current = next; 
	} 
	*revList = prev; 
}

int isPalin(Node *list){
	int len = 0, counter = 0;
	Node *revList = NULL;
	Node *l1 = list;
	Node *l2 = revList;

	reverseListIteratively(l1,&l2);
	printf("Reverse LL:\n");
	display(l2);
	
	if (list == NULL || l2 == NULL)
		return 0;
	
	display(l1);
	
	while(l1){
		len++;
		printf("%d%d",l1->data ,l2->data);
		if (l1->data == l2->data){
			counter++;
			l1 = l1->next;
			l2 = l2->next;
			printf("Hello");
		}
		else
			break;
	}
	return counter == len ? 1 : 0;
}


int main(){
	int size;
    printf("Enter size :-\n");
	scanf("%d", &size);
	
	Node *list=NULL;

    printf("Enter elements:-\n");
    f(i,0,size){
        create(&list);
    }
	
	printf("Given List is :-\n");
	display(list);
	
	if(isPalin(list))
		printf("\nGiven list is a palindrome\n");
	
	else
		printf("\nGiven list is not a palindrome \n");
	
	return 0;
}