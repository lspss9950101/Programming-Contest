#include<iostream>
using namespace std;

int main(){
	int n, s, t, ans = 0;
	cin >> n >> s;
	for(int i = 0; i < n; i++){
		cin >> t;
		if(t > s)ans++;
		else break;
	}
	if(ans < n)cout << "It hadn't snowed this early in " << ans << " years!";
	else cout << "It had never snowed this early!";
}
