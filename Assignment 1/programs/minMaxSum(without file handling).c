#include <stdio.h>
#define ll long long int
#define f(i,a,b) for(register ll i=a ; i<b ; i++)

void swap(ll *xp, ll *yp)  
{  
    ll temp = *xp;  
    *xp = *yp;  
    *yp = temp;  
}  
  
void bubbleSort(ll a[], ll n)  
{  
    f(i,0,n-1)      
      f(j,0,n-i-1)  
        if (a[j] > a[j+1])  
            swap(&a[j], &a[j+1]);  
}

int main() {
    ll size;
    scanf("%lld",&size);
    ll a[size];
    ll n;
    scanf("%lld",&n);
    ll sum=0;
    f(i,0,size)
    { 
        scanf("%lld",&a[i]);
        sum+=a[i];
    }
    
    bubbleSort(a,size);

    ll minSum=0,maxSum=0;
    f(i,n,size)
        maxSum+=a[i];
    f(i,0,size-n)
        minSum+=a[i];

    printf("%lld %lld", minSum, maxSum);
    
    return 0;
}
