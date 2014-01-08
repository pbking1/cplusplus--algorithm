#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
//方法可用但是内存超过32MB。。爆了。。
struct Node{
	int row, col, hrow, hcol, steps;
}node, temp;
const int N = 19;
char matrix[N][N];
int visited[N][N][N][N], direction[4];
queue<Node> q;
int row_move[4] = {-1, 1, 0, 0};
int col_move[4] = {0, 0, -1, 1};

void bfs(){
	while(!q.empty()){
		temp = q.front();
		q.pop();
		if(temp.steps > 255)
			break;
		for(int i = 0; i < 4; i++){
			node.row = temp.row + row_move[i];
			node.col = temp.col + col_move[i];

			node.hrow = temp.hrow + row_move[direction[i]];
			node.hcol = temp.hcol + col_move[direction[i]];
			node.steps = temp.steps + 1;
			if(matrix[node.hrow][node.hcol] == '#'){
				node.hrow = temp.hrow;
				node.hcol = temp.hcol;
			}
			if(matrix[node.row][node.col] == '.' && matrix[node.hrow][node.hcol] != '!' &&
					!visited[node.row][node.col][node.hrow][node.hcol]){
				if(node.row == node.hrow && node.col == node.hcol || node.row == temp.hrow && node.col == temp.hcol
						&& node.hrow == temp.row && node.hcol == temp.col){
					cout<<node.steps<<endl;
					return ;
				}
				visited[node.row][node.col][node.hrow][node.col] == 1;
				q.push(node);
			}
		}
	}
	cout<<"Impossible"<<endl;
}

int main(){
	int n, m;
	while(cin>>n>>m){
		memset(visited, 0, sizeof(visited));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>matrix[i][j];
				if(matrix[i][j] == 'P'){
					node.row = i;
					node.col = j;
					matrix[i][j] = '.';
				}
				if(matrix[i][j] == 'H'){
					node.hrow = i;
					node.hcol = j;
					matrix[i][j] = '.';
				}
			}
		}
		node.steps = 0;
		q.push(node);
		char ch;
		for(int i = 0; i < 4; i++){
			cin>>ch;
			switch(ch){
				case 'N':
					direction[i] = 0;
					break;
				case 'S':
					direction[i] = 1;
					break;
				case 'W':
					direction[i] = 2;
					break;
				case 'E':
					direction[i] = 3;
					break;
			}
		}
		bfs();
		while(!q.empty())
			q.pop();
	}
	return 0;
}
