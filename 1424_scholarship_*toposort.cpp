#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
//拓扑排序:选取一个入度为0的点，把他从图中拿到序列中,然后不停地重复这样的操作,直到图中没有点,先选大的
//用拓扑排序，来确定大小关系，并且逐一递加奖金值，并且记录能够进行排序的总数。如果和n相等，则表示合法方案存在，计算奖金总数，否则不存在
const int MAX = 10005;
vector<int> e[MAX]; //用来存邻接表
int cost[MAX];//每个节点的工资
int inDegree[MAX];//入度
queue<int> q;
int ans;

int main(){
	int n, m;
	int u, v;
	int sum = 0;
	cin>>n>>m;
	memset(cost, 0, sizeof(cost));
	memset(inDegree, 0, sizeof(inDegree));
	int sorted = 0;//已经成功拓扑排序的数目
	int ring = 1;	
	while(m--){
		cin>>u>>v;
		e[v].push_back(u);//从v -> u建图
		inDegree[u]++;//入度+1
	}
	for(int i = 1; i <= n; i++){
		if(inDegree[i] == 0){ //拓扑排序从入读为0的点开始
			ring = 0;
			cost[i] = 100;
			q.push(i);
		}
	}
	int temp;
	while(!q.empty()){
		temp = q.front();
		q.pop();
		++sorted;//每从队列丢掉一个，则说明成功一个
		ans += cost[temp];
		for(int j = 0; j < e[temp].size(); j++){
			if(--inDegree[e[temp][j]] == 0)
				q.push(e[temp][j]);   //如果入度-1后等于0， 加入队列
			cost[e[temp][j]] = cost[temp] + 1;
		}
	}
	if(sorted == n)  //如果数目结果为n， 说明DAG中无环
		cout<<ans<<endl;
	else
		cout<<"Poor Xed"<<endl;
	return 0;
}
