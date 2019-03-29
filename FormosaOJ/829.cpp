#include<iostream>
#include<stdio.h>
#include<map>
#include<vector>
using namespace std;

struct Node{
	int count;
	map<char, Node*> child;
};

class TrieTree{
	private:
		Node* root;
	public:
		TrieTree(){
			root = new Node;
		}
		int* insert(string s){
			Node* node = root;
			for(int i = 0; i < s.length(); i++){
				char c = s[i];
				if((node->child).find(c) == (node->child).end()){
					Node* t = new Node;
					t->count = 0;
					(node->child).insert(pair<char, Node*>(c, t));
				}
				node = (node->child)[c];
			}
			node->count++;
			return &(node->count);
		}
};

bool contains(vector<string> &vec, string s){
	for(vector<string>::iterator it = vec.begin(); it != vec.end(); it++){
		if(s == *it)return true;
	}
	return false;
}

string generalizeString(string s){
	string t = "";
	for(long long i = 0; i < s.length(); i++){
		if(s[i] >= 'a' && s[i] <= 'z')t += s[i];
		else if(s[i] >= 'A' && s[i] <= 'Z')t += (s[i] - 'A' + 'a');
	}
	return t;
}

int main(){
	string s;
	TrieTree tt;
	vector<string> list_s;
	vector<int*> list_i;
	while(cin >> s){
		s = generalizeString(s);
		if(contains(list_s, s)){
			tt.insert(s);
		}else{
			list_s.push_back(s);
			list_i.push_back(tt.insert(s));
		}
	}
	for(long long i = 0; i < list_s.size(); i++)cout << list_s[i] << " " << *list_i[i] << endl;
}
