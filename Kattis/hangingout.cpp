#include<iostream>
using namespace std;

int main(){
	int L, n, p = 0, ans = 0;
	cin >> L >> n;
	while(n--){
		string s;
		int g;
		cin >> s >> g;
		if(s[0] == 'e'){
			if(p + g > L)ans++;
			else p += g;
		}else{
			p -= g;
		}
	}
	cout << ans;
}
