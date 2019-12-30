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


void mergethelinkedlist(struct node *list1, struct node *list2)
{
    Node *temp=NULL, *list3=NULL;
    if (list1->data < list2->data){
        list3 = list1;
        temp = list3;
        list1 = list1->next;
    }
    else{
        list3 = list2;
        temp = list3;
        list2 = list2->next;
    }
    while (list1 != NULL && list2 != NULL){
        if (list1->data < list2->data){
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else{
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }
    if (list1 == NULL)
        temp->next = list2;       
    
    else if (list2 == NULL)
        temp->next = list1;

    printf("Merged linked list is :-\n");
    display(list3);
}

int main(){
    Node *list[2]={NULL}, *list3=NULL;
    f(i,0,2){
        int size;
        printf("Enter size :-\n");
        scanf("%d", &size);

        printf("Enter elements in sorted format:-\n");
        f(j,0,size)
            create(&list[i]);
        
        printf("Given List is :-\n");
        display(list[i]);
    }

    mergethelinkedlist(list[0],list[1]);

    return 0;
}