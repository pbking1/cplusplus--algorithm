//输入一个简单无向图,求出图中连通块的数目。
//输入的第一行包含两个整数 n 和 m,n 是图的顶点数,m 是边数。1<=n<=1000,0<=m<=10000。 
//以下 m 行,每行是一个数对 v y,表示存在边(v,y)。顶点编号从 1 开始。
//单独一行输出连通块的数目。
//Sample Input 
//4 3
//1 2
//1 3
//2 4
//Sample Output 2
#include<iostream>
#include<queue>
#include<cstring>
#include<vector>
using namespace std;
const int MAXN = 1001;
vector<int> graph[MAXN];
int c;
bool visited[MAXN];
int n, m;

void bfs(int i){
	queue<int> q;
	visited[i] = 1;
	q.push(i);
	int temp;
	int each_one;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		for(int i = 0; i < graph[temp].size(); i++){
			each_one = graph[temp][i];
			if(visited[each_one] == 1)
				continue;
			visited[each_one] = 1;
			q.push(each_one);
		}
	}
}

void bfs(){
	memset(visited, 0, sizeof(visited));
	c = 0; //初始连通块的数量为0
	for(int i = 1; i <= n; i++){
		if(visited[i] == 0)
			bfs(i);
			++c;
	}

}

int main(){
	int u, v;
	cin>>n>>m;
	for(int i = 1; i <= n; i++){
		cin>>u>>v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	bfs();
	cout<<c<<endl;
	return 0;
}











