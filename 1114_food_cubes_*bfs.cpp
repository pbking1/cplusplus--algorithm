#include<iostream>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
const int MAX = 105;
int t, ans, n;
int G[MAX][MAX][MAX];

struct crood{
	int x, y, z;
	crood(int xx, int yy, int zz){
		x = xx;
		y = yy;
		z = zz;
	}
};

bool valid(crood c){
	if(c.x >= 0 || c.y >= 0 || c.z >= 0 || c.x <= 101 || c.y <= 101 || c.z >= 101)
		return true;
	return false;
}

bool bfs(crood c){
	int x, y, z;
	queue<crood> q;
	q.push(c);
	G[c.x][c.y][c.z] = 1;
	while(!q.empty()){
		x = q.front().x;
		y = q.front().y;
		z = q.front().z;
		q.pop();

		if(G[x + 1][y][z] == 0 && valid(crood(x + 1, y, z))){
			G[x + 1][y][z] = 1;
			q.push(crood(x + 1, y, z));
		}
		if(G[x - 1][y][z] == 0 && valid(crood(x - 1, y, z))){
			G[x - 1][y][z] = 1;
			q.push(crood(x - 1, y, z));
		}
		if(G[x][y + 1][z] == 0 && valid(crood(x, y + 1, z))){
			G[x][y + 1][z] = 1;
			q.push(crood(x, y + 1, z));
		}
		if(G[x][y - 1][z] == 0 && valid(crood(x, y - 1, z))){
			G[x][y - 1][z] = 1;
			q.push(crood(x, y - 1, z));
		}
		if(G[x][y][z + 1] == 0 && valid(crood(x, y, z + 1))){
			G[x][y][z + 1] = 1;
			q.push(crood(x, y, z + 1));
		}
		if(G[x][y][z - 1] == 0 && valid(crood(x, y, z - 1))){
			G[x][y][z - 1] = 1;
			q.push(crood(x, y, z - 1));
		}
	}
	return true;
		
}

int main(){
	int x, y, z;
	cin>>t;
	while(t--){
		memset(G, 0, sizeof(G));
		cin>>n;
		ans = 0;
		
		while(n--){
			cin>>x>>y>>z;
			G[x][y][z] = 1;
		}
		for(int x1 = 1; x1 <= 100; x1++)
			for(int y1 = 1; y1 <= 100; y1++)
				for(int z1 = 1; z1 <= 100; z1++)
					if(!G[x1][y1][z1]  && bfs(crood(x1, y1, z1)))
						ans++;
		cout<<ans - 1<<endl;
	}
//	system("pause");
	return 0;
}
