/*
#include "iostream"
using namespace std;
long long db(long long x);
void lp(long long st);
long long x, y, xx, tmp_x, tmp_mul, mul = 1, AA = 20091024, test;
int main() {
	cin >> x >> y;

	if (x == 0) {
		if (y == 0) {
			cout << 1;
		}
		else {
			cout << 0;
		}

		return 0;
	}

	if (y == 0) {

		cout << 1;
		return 0;
	}

	//long long xx = x;
	long long cnt = 1;

	while (y > 0) {
		mul = 1;
		lp(x);
		cnt = cnt * xx % AA;
		y = y - mul;
	}

	cout << cnt;
	return 0;
}

long long db(long long xxx) {
	return xxx * xxx % AA;
}

void lp(long long st) {
	long long aa = st;
	while (1) {
		tmp_x = aa;
		tmp_mul = mul;
		aa = db(aa);
		mul *= 2;

		if (mul > y) break;
	}

	mul = tmp_mul;
	xx = tmp_x;
}
*/


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


#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
long long pow_divide(long long a, long long b)
{
	if (b == 1) {
		return a;
	}
	else if (b == 0) {
		return 1;
	}
	if (b % 2 == 0) {
		return (pow_divide(a, b / 2) % 20091024 * pow_divide(a, b / 2) % 20091024) % 20091024;
	}
	else {
		return (pow_divide(a, b / 2) % 20091024 * pow_divide(a, b / 2) % 20091024 * a) % 20091024;
	}
}
int main()
{
	long long a;
	long long b;
	scanf("%lld %lld", &a, &b);
	printf("%lld", pow_divide(a, b));
}

