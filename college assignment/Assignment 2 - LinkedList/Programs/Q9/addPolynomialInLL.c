
#include<stdio.h>
#include <stdlib.h>

typedef struct node 
{ 
	int coefficient; 
	int power; 
	struct node *next; 
}Node; 
			
void create_node(int coefficient, int power, Node **poly) 
{ 
	Node *r, *z; 
	z = *poly; 
	if(z == NULL) 
	{ 
		r =(Node*)malloc(sizeof(Node)); 
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
		r->next = (Node*)malloc(sizeof(Node)); 
		r = r->next; 
		r->next = NULL; 
	} 
} 

void polyadd(Node *poly1, Node *poly2, Node *poly) 
{ 
while(poly1->next && poly2->next) 
	{ 
		if(poly1->power > poly2->power) 
		{ 
			poly->power = poly1->power; 
			poly->coefficient = poly1->coefficient; 
			poly1 = poly1->next; 
		} 
		
		else if(poly1->power < poly2->power) 
		{ 
			poly->power = poly2->power; 
			poly->coefficient = poly2->coefficient; 
			poly2 = poly2->next; 
		} 
		
		else
		{ 
			poly->power = poly1->power; 
			poly->coefficient = poly1->coefficient+poly2->coefficient; 
			poly1 = poly1->next; 
			poly2 = poly2->next; 
		} 
		
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

void show(Node *node) 
{ 
while(node->next != NULL) 
	{ 
	printf("%dx^%d", node->coefficient, node->power); 
	node = node->next; 
	if(node->next != NULL) 
		printf(" + "); 
	} 
} 

int main() 
{ 
	Node *poly1 = NULL, *poly2 = NULL, *poly = NULL; 
	
	create_node(5,4,&poly1); 
	create_node(6,3,&poly1); 
	create_node(1,2,&poly1); 
	
	create_node(3,1,&poly2); 
	create_node(5,4,&poly2); 
	
	printf("1st Number: "); 
	show(poly1); 
	
	printf("\n2nd Number: "); 
	show(poly2); 
	
	poly = (Node *)malloc(sizeof(Node)); 
	
	polyadd(poly1, poly2, poly); 
	
	printf("\nAdded polynomial: "); 
	show(poly); 

return 0; 
} 
