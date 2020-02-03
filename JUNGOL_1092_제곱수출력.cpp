#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>
#define MOD 20091024
 
using namespace std;
 
 
long long gegob(long long x, long long y) {
    if (y == 1) {
        return x;
    }
    else if (y == 0) {
        return 1;
    }
    if (y % 2 == 0) {
        //y = y / 2;
        return (((gegob(x,y/2)%MOD)*(gegob(x, y/2) % MOD))%MOD);
    }
    else {
        //y = y / 2;
        return (((gegob(x, (y-1)/2) % MOD)*(gegob(x, (y-1)/2) % MOD)%MOD*x) % MOD);
    }
}
 
int main() {
    long long x, y;
    long long ans = 0;
    scanf("%lld %lld", &x, &y);
     
    ans = gegob(x, y);
 
    ans = ans % MOD;
    printf("%lld",ans);
    //system("pause");
    return 0;
}
