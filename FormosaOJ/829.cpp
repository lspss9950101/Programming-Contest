#include<iostream>
#include<stdio.h>
#include<vector>
#include<map>
#include<set>
using namespace std;

string generalizeString(string s){
	string t = "";
	for(unsigned long long i = 0; i < s.length(); i++){
		if(s[i] >= 'a' && s[i] <= 'z')t += s[i];
		else if(s[i] >= 'A' && s[i] <= 'Z')t += (s[i] - 'A' + 'a');
	}
	return t;
}

int main(){
	string s;
	set<string> exist;
	vector<string> order;
	map<string, unsigned long long> count;
	while(cin >> s){
		s = generalizeString(s);
		if(s.empty())continue;
		if(exist.count(s)){
			count[s]++;
		}else{
			exist.insert(s);
			order.push_back(s);
			count[s] = 1;
		}
	}
	for(unsigned long long i = 0; i < order.size(); i++)cout << order[i] << " " << count[order[i]] << endl;
}
