#include<iostream>
using namespace std;

int main(){
	int n, m, t, sum = 0;
	cin >> n;
	m = n;
	while(n--){
		cin >> t;
		if(t == -1)m--;
		else sum += t;
	}
	cout << sum / (m + 0.f);
}
