#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

// only addition done 
typedef struct node{
	int data;
	struct node *next;	
}Node;

void display(Node *first){
    Node *ptr = first;
	while(ptr->next){
			printf("%d -> ",ptr->data);
			ptr=ptr->next; 
		}
        printf("%d -> NULL\n",ptr->data);	
}

void create(Node **list, int data){
        Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

        temp->data=data;
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

Node * duplicateLL(Node *original){
    Node* ptr = NULL;
	while(original){
		create(&ptr,original->data);
		original=original->next;
	}
	return ptr;
}
int noOfNodes(Node * list){
        int size =0;
        Node *temp = list;
        while(temp){
                size++;
                temp=temp->next;
        }        
        return size;
}
Node * add(Node *first, Node *second){
    Node* res = NULL; 
    int carry = 0, sum;  
    while (first || second )  
    {  
        sum = carry + (first? first->data: 0) + (second? second->data: 0);  
  
        carry = (sum >= 10)? 1 : 0;  
  
        sum = sum % 10;  
  
        create(&res,sum);  
  
        if (first) first = first->next;  
        if (second) second = second->next;  
    }  
  
    if (carry > 0)  
        create(&res,carry);  
    return res;  
}

Node * subtract(Node *first, Node *second){
    Node* res = NULL; 
    int borrow = 0, diff;  
    while (first || second )  
    {  
        diff = (first? first->data: 0) - borrow - (second? second->data: 0);  
  
        borrow = (diff < 0)? 1 : 0;  
  
        create(&res,diff);  
  
        if (first) first = first->next;  
        if (second) second = second->next;  
    }  
  
    if (borrow > 0)  
        create(&res,-1);  
    return res;  
}

Node * multiply(Node *first, Node *second){
                   
    Node* result = NULL; 
    Node *second_ptr = second, *result_ptr1 = result, *result_ptr2, *first_ptr; 
   
    while (second_ptr) { 
        int carry = 0; 
        result_ptr2 = result_ptr1; 
        first_ptr = first; 
  
        while (first_ptr) { 
            int mul = first_ptr->data * second_ptr->data 
                      + carry; 
            result_ptr2->data += mul % 10; 
            carry = mul / 10 + result_ptr2->data / 10; 
            result_ptr2->data = result_ptr2->data % 10; 
  
            first_ptr = first_ptr->next; 
            result_ptr2 = result_ptr2->next; 
        } 
        if (carry > 0)
            result_ptr2->data += carry; 
  
        result_ptr1 = result_ptr1->next; 
        second_ptr = second_ptr->next; 
    } 
    return result;
}

int main(){
    char num1[30];
    printf("Enter number 1: ");
    fgets(num1, sizeof(num1), stdin);  // read string
    
    char num2[30];
    printf("Enter number 2: ");
    fgets(num2, sizeof(num2), stdin);  // read string
    
    Node *number1=NULL, *number2=NULL;
    for (int i=strlen(num1)-2; i>=0; i--)
        create(&number1,num1[i]-'0');
	
    for (int i=strlen(num2)-2; i>=0; i--)
        create(&number2,num2[i]-'0');
	
    Node *t1 = NULL,*t2 = NULL, *result=NULL;
    char res[100];
    int choice,size=0;
    while(1){
                printf("\n***SINGLE LINKED LIST OPERATIONS:****\n");
                printf("\n                MENU                           \n");
                printf("---------------------------------------\n");
                printf("\n 1. Addition     \n");
                printf("\n 2. Subtraction    \n");
                printf("\n 3. Multiplication    \n");
                printf("\n 4. Factorial       \n");
                printf("\n 5. Exit       \n");
                printf("\n--------------------------------------\n");
                printf("Enter your choice:\t");
                scanf("%d",&choice);
                switch(choice)
                {
                        case 1:         t1 = duplicateLL(number1);
                                        t2 = duplicateLL(number2);
                                        result = add(t1,t2);
                                        size = noOfNodes(result);
                                        for(int i=size-1; i>=0; i--){
                                                res[i] = result->data + '0';
                                                result = result->next; 
                                        }
                                        f(i,0,size)
                                                printf("%c",res[i]);
                                        printf("\n");
                                        t1=NULL;
                                        t2=NULL;
                                        result=NULL;
                                        break;

                        case 2:         t1 = duplicateLL(number1);
                                        t2 = duplicateLL(number2);
                                        result = subtract(t1,t2);
                                        display (result);
                                        size = noOfNodes(result);
                                        for(int i=size-1; i>=0; i--){
                                                res[i] = result->data + '0';
                                                result = result->next; 
                                        }
                                        f(i,0,size)
                                                printf("%c",res[i]);
                                        printf("\n");
                                        t1=NULL;
                                        t2=NULL;
                                        result=NULL;
                                        break;

                        case 3:         t1 = duplicateLL(number1);
                                        t2 = duplicateLL(number2);
                                        result = multiply(t1,t2);
                                        display(result);
                                        size = noOfNodes(result);
                                        for(int i=size-1; i>=0; i--){
                                                res[i] = result->data + '0';
                                                result = result->next; 
                                        }
                                        f(i,0,size)
                                                printf("%c",res[i]);
                                        printf("\n");
                                        t1=NULL;
                                        t2=NULL;
                                        result=NULL;
                                        break;

                        case 4:         t1 = duplicateLL(number1);
                                        t2 = duplicateLL(number2);
                                        //result = factorial(t1,t2);
                                        display(result);
                                        t1=NULL;
                                        t2=NULL;
                                        result=NULL;
                                        break;

                        case 5:         exit(0);
                                        break;

                        default:        printf("\n Wrong Choice:\n");
                                        break;
                }
        }
	return 0;
}