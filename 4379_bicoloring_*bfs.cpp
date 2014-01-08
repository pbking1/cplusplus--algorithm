#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
//输入一个简单(无多重边和自环)的连通无向图,判断该图是否能用黑白两种颜色对顶点染 色,使得每条边的两个端点为不同颜色。
/*Input
输入的第一行包含两个整数 n 和 m,n 是图的顶点数,m 是边数。1<=n<=1000,0<=m<=10000。 以下 m 行,每行是一个数对 u v,表示存在边(u,v)。顶点编号从 1 开始。
Output 如果能做到双着色,输出"yes",否则输出"no"。*/
#define MAXN 1010
int visited[MAXN];
int color[MAXN];//0 is not-colored, 1 is colored red, -1 is colored black
int n, m;
int u, v;
vector<int> graph[MAXN];

bool bfs(int i){
	queue<int> cq;
	visited[i] = 1;
	color[i] = 1;
	cq.push(i); //search from i
	while(!cq.empty()){
		u = cq.front();
		cq.pop();
		for(int i = 0; i < graph[u].size(); i++){
			v = graph[u][i];
			if(visited[v] == 1){
				if(color[v] == color[u])
					continue;
				else
					return false;
			}
			visited[v] = 1;
			color[v] = -color[u];
			cq.push(v);
		}
	}
	return true;
}

int main(){
	memset(visited, 0, sizeof(visited));
	memset(color, 0, sizeof(color));

	cin>>n>>m;
	for(int i = 1; i <= m; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	cout<<(bfs(1) ? "yes" : "no")<<endl;
	return 0;
}
