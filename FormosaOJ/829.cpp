#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

struct Node{
	long long count;
	Node* child[26];
};

class TrieTree{
	private:
		Node* root;
	public:
		TrieTree(){
			root = new Node;
			for(int i = 0; i < 26; i++)root->child[i] = 0;
		}
		long long* insert(string s){
			Node* node = root;
			for(int i = 0; i < s.length(); i++){
				char c = s[i];
				if(!node->child[c - 'a']){
					node->child[c - 'a'] = new Node;
					for(int j = 0; j < 26; j++)node->child[c - 'a']->child[j] = 0;
					node->child[c - 'a']->count = 0;
				}
				node = node->child[c - 'a'];
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
	char cs[1000000];
	TrieTree tt;
	vector<string> list_s;
	vector<long long*> list_i;
	while(scanf("%s", cs) != EOF){
		string s = cs;
		s = generalizeString(s);
		if(contains(list_s, s)){
			tt.insert(s);
		}else{
			list_s.push_back(s);
			list_i.push_back(tt.insert(s));
		}
	}
	for(long long i = 0; i < list_s.size(); i++)printf("%s %lld\n", list_s[i].c_str(), *list_i[i]);
}
