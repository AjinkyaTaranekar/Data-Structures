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
    Node *r, *z; 
    z = *poly; 
    if(z == NULL) 
    { 
        r =( Node*)malloc(sizeof( Node)); 
        r->coefficient = coefficient; 
        r->power = power; 
        *poly = r; 
        r->next = (Node*)malloc(sizeof(Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
    else
    { 
        r->coefficient = coefficient; 
        r->power = power; 
        r->next = (Node*)malloc(sizeof( Node)); 
        r = r->next; 
        r->next = NULL; 
    } 
}

void displayPolynomialInLL(Node *poly){
    Node *ptr = poly;
	while(ptr->next){
			printf("| %d | %d | -> ",ptr->coefficient, ptr->power);
			ptr=ptr->next; 
		}
        printf("| %d | %d | -> NULL",ptr->coefficient, ptr->power);	
}

void displayPolynomial(Node *poly){
    Node *ptr = poly;
	while(ptr->next){
			printf("%d X %d + ",ptr->coefficient, ptr->power);
			ptr=ptr->next; 
		}
        printf("%d X %d = 0",ptr->coefficient, ptr->power);	
}

void addPolynomial(Node *poly1, Node *poly2 , Node *poly){
    while(poly1->next && poly2->next) 
    { 
        // If power of 1st polynomial is greater then 2nd, then store 1st as it is 
        // and move its pointer 
        if(poly1->power > poly2->power) 
        { 
            poly->power = poly1->power; 
            poly->coefficient = poly1->coefficient; 
            poly1 = poly1->next; 
        } 
          
        // If power of 2nd polynomial is greater then 1st, then store 2nd as it is 
        // and move its pointer 
        else if(poly1->power < poly2->power) 
        { 
            poly->power = poly2->power; 
            poly->coefficient = poly2->coefficient; 
            poly2 = poly2->next; 
        } 
          
        // If power of both polynomial numbers is same then add their coefficients 
        else
        { 
            poly->power = poly1->power; 
            poly->coefficient = poly1->coefficient+poly2->coefficient; 
            poly1 = poly1->next; 
            poly2 = poly2->next; 
        } 
          
        // Dynamically create new node 
        poly->next = (Node *)malloc(sizeof(Node)); 
        poly = poly->next; 
        poly->next = NULL; 
    } 
    while(poly1->next || poly2->next) 
    { 
        if(poly1->next) 
        { 
            poly->power = poly1->power; 
            poly->coefficient = poly1->coefficient; 
            poly1 = poly1->next; 
        } 
        if(poly2->next) 
        { 
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
        printf("Enter polynomial %d\n", (i+1));
        printf("How many X will it have? ");
        scanf("%d",&noOfX);
        f(j,0,noOfX){
            int coefficient=0, power=0;
            printf("\nCoefficient \t");
            scanf("%d",&coefficient);
            printf("\nPower \t");
            scanf("%d",&power);
            addPolynomialToLL(coefficient,power,&Poly[i]);
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