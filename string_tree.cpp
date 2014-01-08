/*12+345+**
Postorder:  1 2 + 3 4 5 + * * 
Inorder:  1 + 2 * 3 * 4 + 5 
preorder:  * + 1 2 * 3 + 4 5 
*/
#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
#define MAX 100
//
typedef struct node{
	//
	union{
		char op;
		int data;
	};
	struct node *lchild;
	struct node *rchild;
}TreeNode;

//
typedef struct Tree_Stack{
	TreeNode *buf[MAX];
	int n;
}TreeStack;

//create empty stack
TreeStack *create_empty_stack(){
	TreeStack *pstack;
	pstack = (TreeStack*) malloc(sizeof(TreeStack));
	pstack -> n = 1;
	return pstack;
}

//push into stack
int push_stack(TreeStack *p, TreeNode *data){
	p -> n++;
	p -> buf[p -> n] = data;
	return 0;
}

//pop out of the stack
TreeNode *pop_stack(TreeStack *p){
	TreeNode *data;
	data = p -> buf[p -> n];
	p -> n--;
	return data;
}

//judge the empty stack
int is_empty_stack(TreeStack * p){
	if(p -> n == -1)
		return 1;
	else
		return 0;
}

//创建后缀表达式树
TreeNode *create_express_tree(char *str, TreeStack *p){
	int i = 0; 
	TreeNode *current;
	TreeNode *left, *right;
	while(str[i]){
		if(str[i] >= '0' && str[i] <= '9'){
			current = (TreeNode *)malloc(sizeof(TreeNode));
			current -> data = str[i] - '0';
			current -> lchild = NULL;
			current -> rchild = NULL;
			push_stack(p, current);
		}else{
			current = (TreeNode *)malloc(sizeof(TreeNode));
			current -> op = str[i];
			right = pop_stack(p);
			left = pop_stack(p);
			current -> lchild = left;
			current -> rchild = right;
			push_stack(p, current);
		}
		i++;
	}
	return p -> buf[p->n];
}

void print_node(TreeNode *p){
	if(p -> lchild == NULL && p -> rchild == NULL)
		cout<<p -> data<<" ";
	else
		cout<<p -> op<<" ";
}

int visit_node(TreeNode *p){
	print_node(p);
	return 0;
}

void PostOrder(TreeNode *p){
	if(p != NULL){
		PostOrder(p -> lchild);
		PostOrder(p -> rchild);
		visit_node(p);
	}
}

void InOrder(TreeNode *p){
	if(p != NULL){
		InOrder(p -> lchild);
		visit_node(p);
		InOrder(p -> rchild);
		}
}

void PreOrder(TreeNode *p){
	if(p != NULL){
		visit_node(p);
		PreOrder(p -> lchild);
		PreOrder(p -> rchild);
	}
}

int main(){
	TreeNode *thead;
	TreeStack *pstack;
	int i = 0; 
	char buf[100];
	cin>>buf;
	pstack = create_empty_stack();
	thead = create_express_tree(buf, pstack);
	
	cout<<"Postorder:  ";
	PostOrder(thead);
	cout<<"\n";
	
	cout<<"Inorder:  ";
	InOrder(thead);
	cout<<"\n";
	
	cout<<"preorder:  ";
	PreOrder(thead);
	cout<<"\n";
	return 0;
}

