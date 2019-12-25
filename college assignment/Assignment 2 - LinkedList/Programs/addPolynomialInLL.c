#include <stdio.h>
#include <stdlib.h>
#define f(i,a,b) for(register int i=a; i<b; i++)

typedef struct node{
	int coefficient;
	int power;
	struct node *next;	
}Node;


void addPolynomialToLL(int coefficient, int power,Node **poly)
{
    Node *temp,*ptr;
        temp=(Node *)malloc(sizeof(Node));
        
        if(temp==NULL){
                printf("\nOut of Memory Space:\n");
                exit(0);
        }

        temp->coefficient=coefficient;
        temp->power=power;
        temp->next=NULL;
        
        if(*poly==NULL)
                *poly=temp;
        
        else{
                ptr=*poly;
                while(ptr->next){
                        ptr=ptr->next;
                }
                ptr->next=temp;
        } 
}

void displayPolynomialInLL(Node *poly){
    Node *ptr = poly;
	while(ptr->next){
			printf("| %d | %d | -> ",ptr->coefficient, ptr->power);
			ptr=ptr->next; 
		}
        printf("| %d | %d | -> NULL\n",ptr->coefficient, ptr->power);	
}

void displayPolynomial(Node *poly){
    Node *ptr = poly;
	while(ptr->next){
			printf("%d X %d + ",ptr->coefficient, ptr->power);
			ptr=ptr->next; 
		}
        printf("%d X %d = 0\n",ptr->coefficient, ptr->power);	
}

void addPolynomial(Node *poly1, Node *poly2 , Node *poly){
    while(poly1->next && poly2->next){ 
        if(poly1->power > poly2->power){ 
            poly->power = poly1->power; 
            poly->coefficient = poly1->coefficient; 
            poly1 = poly1->next; 
        } 
          
        else if(poly1->power < poly2->power){ 
            poly->power = poly2->power; 
            poly->coefficient = poly2->coefficient; 
            poly2 = poly2->next; 
        } 
          
        else{ 
            poly->power = poly1->power; 
            poly->coefficient = poly1->coefficient+poly2->coefficient; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        poly->next = (Node *)malloc(sizeof(Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
    while(poly1->next || poly2->next){ 
        if(poly1->next){ 
            poly->power = poly1->power; 
            poly->coefficient = poly1->coefficient; 
            poly1 = poly1->next; 
        } 
        if(poly2->next){ 
            poly->power = poly2->power; 
            poly->coefficient = poly2->coefficient; 
            poly2 = poly2->next; 
        } 
        poly->next = (Node *)malloc(sizeof(Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
}


int main()
{
    Node *Poly[2];
    printf("Enter polynomials\n");
    f(i,0,2){
        int noOfX=0;
        printf("\nEnter polynomial %d\n", (i+1));
        printf("How many X will it have? ");
        scanf("%d",&noOfX);
        f(j,0,noOfX){
            int coefficient=0, power=0;
            printf("\nCoefficient \t");
            scanf("%d",&coefficient);
            printf("\nPower \t");
            scanf("%d",&power);
            addPolynomialToLL(coefficient,power,&(Poly[i]));
        }
        printf("Entered Polynomial is :-\n");
	    displayPolynomialInLL(Poly[i]);
        displayPolynomial(Poly[i]);
    }
	
	Node * addedPoly = (Node *)malloc(sizeof(Node));
	addPolynomial(Poly[0],Poly[1],addedPoly);
    printf("Entered Polynomial is :-\n");
    displayPolynomialInLL(addedPoly);
    displayPolynomial(addedPoly);
    
	return 0;
}