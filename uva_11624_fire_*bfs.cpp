#include<iostream>
#include<queue>
#include<cstdio>
#include<cstdlib>
//bfs，稍复杂的bfs，将火和人的位置分别bfs（先火再人），直到人到达边界或是被火围住无路可走时结束。
static char **map, **visited;
static int **f;
int dx[] = { 0, 0, 1, -1};
int dy[] = { 1, -1, 0, 0};
using namespace std;

int bfs(int row, int col){
	queue<int> Q1;
	queue<int> Q2;
	int t;
	for(int i = 0; i < row; i++)
		for(int j = 0; j < col; j++){
			f[i][j] = -1;
			visited[i][j] = 0;
			if(map[i][j] == 'F'){
				Q1.push(i);
				Q1.push(j);
				f[i][j] = 0;
			}else if(map[i][j] == 'J'){
				Q2.push(i);
				Q2.push(j);
				Q2.push(0);
				visited[i][j] = 1;
			}
		}
	while(!Q1.empty()){
		int temp_x = Q1.front();
		Q1.pop();
		int temp_y = Q1.front();
		Q1.pop();
		for(int d = 0; d < 4; d++){
			int x = temp_x + dx[d];
			int y = temp_y + dy[d];
			if(x >= 0 && x < row && y >= 0 && y < col && map[x][y] != '#' && f[x][y] == -1){
				f[x][y] = f[temp_x][temp_y] + 1;
				Q1.push(x);
				Q1.push(y);
			}
		}
	}
	while(!Q2.empty()){
			int temp_x = Q2.front();
			Q2.pop();
			int temp_y = Q2.front();
			Q2.pop();
			t = Q2.front();
			Q2.pop();
			if(temp_x == 0 || temp_y == 0 || temp_x == row - 1 || temp_y == col - 1)
				return t + 1;
			else
				for(int d = 0; d < 4; d++){
					int x = temp_x + dx[d];
					int y = temp_y + dy[d];
					if(x >= 0 && x < row && y >= 0 && y < col && map[x][y] != '#' && !visited[x][y] && 
							(f[x][y] == -1 || f[x][y] > t + 1)){
						visited[x][y] = 1;
						Q2.push(x);
						Q2.push(y);
						Q2.push(t + 1);
					}
				}
	}
	return -1;
}

int main(){
	int cases;
	f = (int **)malloc(1200 * sizeof(int *));
	map = (char **)malloc(1200 * sizeof(char *));
	visited = (char **)malloc(1200 * sizeof(char *));
	for(int i = 0; i < 1200; i++){
		f[i] = (int *)malloc(1200 * sizeof(int));
		map[i] =(char *)malloc(1200);
		visited[i] = (char *)malloc(1200);
	}
	int row, col;
	cin>>cases;
	while(cases--){
		cin>>row>>col;
		for(int i = 0; i < row; i++){
			for(int j = 0; j < col; j++)
				map[i][j] = getchar();
			getchar();
		}
		int result = bfs(row, col);
		if(result == -1)
			cout<<"IMPOSSIBLE"<<endl;
		else
			cout<<result<<endl;
	}
	return 0;
}




