#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;

struct Node{
	vector<int> step;
	char x[10];
	int h;
}o;

int chg[12][12] = { {0}, {4,1,2,4,5}, {6,1,2,3,4,5,6},{4,2,3,5,6},
	{6,1,2,4,5,7,8},{9,1,2,3,4,5,6,7,8,9},{6,2,3,5,6,8,9},
	{4,4,5,7,8},{6,4,5,6,7,8,9},{4,5,6,8,9} };
bool visited[1100];

int gethash(const Node &n){
	int res = 0; 
	int two = 1;
	for(int i = 0; i < 9; i++, two <<= 1)
		if(n.x[i] == 'b')
			res += two;
	return res;
}

void bfs(){
	queue<Node> que;
	que.push(o);
	memset(visited, false, sizeof(visited));
	visited[gethash(o)] = true;

	while(!que.empty()){
		Node now = que.front();
		que.pop();
		if(now.h == 0){
			for(int i = 0; i < now.step.size(); i++)
				cout<<now.step[i];
			cout<<endl;
			return ;
		}

		for(int i = 1; i <= 9; i++){
			Node next = now;
			for(int j = 1; j <= chg[i][0]; j++){
				if(next.x[chg[i][j]-1] == 'b')
					next.x[chg[i][j]-1] = 'w';
				else
					next.x[chg[i][j]-1] = 'b';
			}

			next.h = gethash(next);

			if(!visited[next.h]){
				visited[next.h] = true;
				next.step.push_back(i);
				que.push(next);
			}
		}
	}
}

int main(){
	int cas;
	cin>>cas;
	while(cas--){
		cin>>o.x;
		if(strcmp(o.x, "wwwwwwwww") == 0){
			cout<<"11"<<endl;
			continue;;
		}
		o.step = vector<int>();
		o.h = gethash(o);
		bfs();
	}
	return 0;
}


