#include <stdio.h>
#include <stdlib.h>

#define f(i,a,b) for(register int i=a;i<b;i++)
#define tvx(i) Triangle.vertices[(i)].x
#define tvy(i) Triangle.vertices[(i)].y

struct vertex{
 float x;
 float y;
};

struct triangle{
 struct vertex vertices[3];
};

float cal_area(struct triangle Triangle) {

    float area = 0.5*(tvx(0)*(tvy(1)-tvy(2))+tvx(1)*(tvy(2)-tvy(0))+tvx(2)*(tvy(0)-tvy(1)));
    return abs(area);
}

int main() {
	struct triangle Triangle;
	f(i,0,3)
	    scanf("%f%f",&tvx(i),&tvy(i));
	
	printf("%f",cal_area(Triangle));
	return 0;
}
