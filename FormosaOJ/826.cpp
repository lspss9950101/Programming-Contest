#include<iostream>
#include<stdio.h>
#define MAX(X, Y) ((X) > (Y) ? (X) : (Y))

using namespace std;

int main(){
	int n, m, q, total = 0;
	scanf("%d %d %d", &n, &m, &q);
	int max_row[n];
	for(int i = 0; i < n; i++)max_row[i] = 0;
	while(q--){
		int x, y, ans = 0;
		scanf("%d %d", &y, &x);
		for(int i = y-1; i >= 0; i--){
			if(max_row[i] >= x)break;
			ans += (x - max_row[i]);
		}
		if(ans > 0){
			total += ans;
			printf("%d\n", ans);
			for(int i = y-1; i >= 0; i--)max_row[i] = MAX(max_row[i], x);
		}
		else printf("QAQ\n");
	}
	printf("%d\n", m*n-total);
}
