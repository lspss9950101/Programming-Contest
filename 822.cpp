#include<iostream>
#include<stdio.h>
#define MIN(x, y) ((x) < (y) ? (x) : (y))
using namespace std;

int main(){
	long long t;
	scanf("%lld", &t);
	while(t--){
		long long n, n1, l, r, a;
		scanf("%lld %lld %lld", &n, &l, &r);
		n1 = n;
		if(!n){
			cout << l << endl;
			continue;
		}
		bool ap[n];
		for(int i = 0; i < n; i++)ap[i] = true;
		while(n1--){
			scanf("%lld", &a);
			if(l <= a && a <= l+n - 1)ap[a-l] = false;
		}
		bool ans = true;
		for(int i = 0; i < MIN(n, r-l+1); i++)
			if(ap[i]){
				cout << l+i << endl;
				ans = false;
				break;
			}
		if(ans){
			if(n < r-l+1)cout << l+n << endl;
			else cout << "^v^" << endl;
		}
	}
}
