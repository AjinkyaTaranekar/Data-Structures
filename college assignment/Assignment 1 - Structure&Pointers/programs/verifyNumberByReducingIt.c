#include <stdio.h>
#include <stdbool.h> 

struct rational {
 int numerator;
 int denominator;
};

int gcd(int a, int b){
    if (b != 0)
        return gcd(b, a % b);
    else
        return a;
}

void reduce(struct rational *inputRational, struct rational *outputRational) { 
        outputRational->numerator = inputRational->numerator/gcd(inputRational->numerator,inputRational->denominator);
        outputRational->denominator = inputRational->denominator/gcd(inputRational->numerator,inputRational->denominator) ;
} 

bool isEqual (struct rational num1, struct rational num2){ 
    if(num1.numerator==num2.numerator && num1.denominator == num2.denominator)
        return true;
    return false;
}

int main() {
	struct rational r1,r2;

    scanf("%d/%d",&r1.numerator,&r1.denominator);
    scanf("%d/%d",&r2.numerator,&r2.denominator);

    struct rational outputR1,outputR2;
    reduce(&r1,&outputR1);
    reduce(&r2,&outputR2);
    
    bool result = isEqual(outputR1,outputR2);
    
    if(result==true)
        printf("equal");
    else
        printf("not equal");
    return 0;
}
