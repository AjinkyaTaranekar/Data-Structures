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

void count(int data){
    Node *ptr = start;
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

    printf("Enter elements:-\n");
    f(i,0,size){
        create();
    }
	
	printf("Given List is :-\n");
	display();
    
	int numToBeFound;
    printf("Enter number to be found :-\n");
	scanf("%d", &numToBeFound);
	count(numToBeFound);

	return 0;
}