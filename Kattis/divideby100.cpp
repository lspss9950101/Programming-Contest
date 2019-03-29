#include<iostream>
using namespace std;

int main(){
	string N, M;
	cin >> N >> M;
	long zeroIndex = N.length();
	bool traillingZero = false;
	for(long i = 0; i < N.length(); i++)
		if(N[i] == '0' && !traillingZero){
			zeroIndex = i;
			traillingZero = true;
		}else if(N[i] != '0'){
			traillingZero = false;
			zeroIndex = N.length();
		}
	if(N.length() == M.length() - 1){
		cout << "0.";
		for(long i = 0; i < N.length() && i < zeroIndex; i++)cout << N[i];
	}
	else if(N.length() < M.length() - 1){
		cout << "0.";
		for(long i = 0; i < M.length() - N.length() - 1; i++)cout << 0;
		for(long i = 0; i < N.length() && i < zeroIndex; i++)cout << N[i];
	}else{
		long i;
		for(i = 0; i < N.length() - M.length() + 1; i++)cout << N[i];
		if(i < zeroIndex)cout << '.';
		for(; i < N.length() && i < zeroIndex; i++)cout << N[i];
	}
}
