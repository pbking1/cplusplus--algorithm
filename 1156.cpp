#include<iostream>
using namespace std;

struct Node{
	char c;
	int left_node;
	int right_node;
};
int n;
Node node[1001];

void preorder(int temp){
	cout<<node[temp].c;  //print the head ,only the first one is the root
	if(node[temp].left_node != 0)
		preorder(node[temp].left_node);  //preorder the left tree
	if(node[temp].right_node != 0)
		preorder(node[temp].right_node);  //preorder the right tree
}

int main(){
	int n;
	int index;
	int head = 0;
	while(cin>>n){
		head = 0;
		for(int j = 0; j < n; j++){
			cin>>index;
			cin>>node[index].c>>node[index].left_node>>node[index].right_node;
			//find the root
			head = head ^ index ^ node[index].left_node ^ node[index].right_node;
		}
		preorder(head);
		cout<<endl;
	}
	return 0;
}
