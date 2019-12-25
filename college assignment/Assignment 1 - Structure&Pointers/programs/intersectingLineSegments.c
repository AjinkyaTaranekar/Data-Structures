#include <stdio.h>
#include <stdlib.h>

#define f(i,a,b) for(register int i=a;i<b;i++)
#define px(i) point[(i)].x
#define py(i) point[(i)].y

struct Point {
 int x,y;
};

struct LineSeg {
 struct Point point[2];
};

int SegIntersect(struct LineSeg l1,struct LineSeg l2) { 
    int a1 = l1.py(1)-l1.py(0);
    int a2 = l2.py(1)-l2.py(0);
    
    int b1 = l1.px(1)-l1.px(0);
    int b2 = l2.px(1)-l2.px(0);
    
    int c1 = l1.px(0)*l1.py(1)-l1.px(1)*l1.py(0);
    int c2 = l1.px(0)*l1.py(1)-l1.px(1)*l1.py(0);
    
    if(b1==b2 || a1==a2)
        return 2;
    float y = (c1*a2 - c2*a1)/(a1*b2+a2*b1);
    float x = (c1+b1*y)/a1;
    
    if(l1.px(0)>=x && x<=l1.px(1) && l1.py(0)>=y && y<=l1.py(1) && l2.px(0)>=x && x<=l2.px(1) && l2.py(0)>=y && y<=l2.py(1)){
        if( a1*b2!= a2*b1)
            return 1;
        else if( a1*b2== a2*b1 && b1*c2== b2*c1)
            return 2;
        else if( a1*b2== a2*b1 && b1*c2!= b2*c1)
            return 0;
    }
    
    return -1;
} 

int main() {
	struct LineSeg line1;
	struct LineSeg line2;
	
	f(i,0,2)
	    scanf("%d%d",&line1.px(i),&line1.py(i));
	f(i,0,2)
	    scanf("%d%d",&line2.px(i),&line2.py(i));
	
    
    if(SegIntersect(line1,line2)==1)
        printf("Intersecting");
    else if(SegIntersect(line1,line2)==2)
        printf("Overlapping");
    else if(SegIntersect(line1,line2)==0)
        printf("Parallel");
	else
	    printf("Line Segments doesn't intersect and are not parallel");
	return 0;
}
