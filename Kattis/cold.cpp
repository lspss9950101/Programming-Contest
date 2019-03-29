#include<iostream>
using namespace std;

int main(){
	int n, ans = 0, t;
	cin >> n;
	while(n--){
		cin >> t;
		if(t < 0)ans++;
	}
	cout << ans;
}
