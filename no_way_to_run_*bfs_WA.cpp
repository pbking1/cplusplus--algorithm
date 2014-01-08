#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 110;
int maze[MAXN][MAXN];

struct point{
	int x, y;
	point(int a = 0, int b = 0){
		x = a;
		y = b;
	}
};

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int sx, sd, es, ed;
int n, m;
int u, v;

bool isvalid(int x, int y){
	return (x < 0 || x >= n || y < 0 || y >= m) ? false: true;
}

void bfs(int sx1, int sd1, int es1, int ed1){
	cout<<"www";
	queue<point> q;
	cout<<"rrr";
	--sx1; --sd1; --es1; --ed1;
	cout<<"sss ";
	maze[sx1][sd1] = -1;
	q.push(point(sx1, sd1));
	while(!q.empty()){
		point current = q.front();
		q.pop();
		for(int i = 0; i < 4; ++i){
			point temp = current;
			temp.x += dx[i];
			temp.y += dy[i];
			if(isvalid(temp.x, temp.y))
				//if not valid, break
				continue;
			if(maze[temp.x][temp.y] <= 0)
				//if the point is visited
				continue;
			maze[temp.x][temp.y] = -1;
			q.push(temp);
		}
	}	
}

int main(){
	int t;
	cin>>t;
	while(t--){
		cin>>n>>m;
	//	memset(maze, 0, sizeof(maze));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin>>maze[i][j];
			}
		}
		cin>>sx>>sd>>es>>ed;
		cout<<"ppp"<<endl;
		bfs(sx, sd, es, ed);
		cout<<"eee";
		if(maze[es][ed] >= 0)
			//judge if the destination is visited or not
			//if visited then the value is -1 then output 1
			cout<<"0"<<endl;
		else
			cout<<"1"<<endl;
	}
	return 0;
}


