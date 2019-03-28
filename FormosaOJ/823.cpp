#include<bits/stdc++.h>

using namespace std;

int cal(int *seq, int *ans, int index, int length){
    for(int i = index + 1; i < length; i++){
    	if(seq[index] < seq[i])return ans[i] + 1;
    }
    return 1;
}

int main(){
    int testcase;
    scanf("%d", &testcase);
    while(testcase--){
        int n;
        scanf("%d",&n);
        int a[n], b[n];
        for(int i = 0 ; i < n ; i++)scanf("%d", &a[i]);
        int ans = 0;
        for(int l = n-1 ; l >= 0 ; l--){
		int i;
   		bool stop = false;
		for(i = l + 1; i < n; i++){
			if(a[l] < a[i])break;
			if(a[l] > a[i] && b[i] == 1){
				stop = true;
				break;
			}
		}
		if(i == n || stop)b[l] = 1;
		else b[l] = b[i] + 1;
		ans = max(b[l], ans);
	}
        printf("%d\n", ans);
    }
    return 0;
}
