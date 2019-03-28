#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;

struct Node{
	int amount;
	Node *left, *right;
};

class BST{
	private:
		Node* root;
	public:
		BST(){
			root = new Node;
			root->left = root->right = 0;
		}
		void insert(string key){
			Node* node = root;
			for(int i = 0; i < key.length(); i++){
				if(key[i] == '0'){
					if(!node->left){
						node->left = new Node;
						node->left->amount = 0;
						node->left->left = node->left->right = 0;
					}
					node = node->left;
					node->amount++;
				}else{
					if(!node->right){
						node->right = new Node;
						node->right->amount = 0;
						node->right->left = node->right->right = 0;
					}
					node = node->right;
					node->amount++;
				}
			}
		}
		int count(string key){
			Node* node = root;
			for(int i = 0; i < key.length(); i++){
				if(key[i] == '0'){
					if(!node->left)return 0;
					node = node->left;
				}else{
					if(!node->right)return 0;
					node = node->right;
				}
			}
			return node->amount;
		}
};

int main(){
	BST bst;
	int n;
	char s[100000000];
	string t;
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		t = s;
		bst.insert(t);
	}
	scanf("%d", &n);
	while(n--){
		scanf("%s", s);
		t = s;
		printf("%d\n", bst.count(t));
	}
}
