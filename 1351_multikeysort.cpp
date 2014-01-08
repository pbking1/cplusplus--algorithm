#include<iostream>
#include<cstdio>
#include<string>
#include<stack>
#include<algorithm>
#include<vector>
using namespace std;
bool visited[1000001];

int main(){
	int C, N;
	while(cin>>C>>N){
		vector<int> sequence;
		int pre = 0, now = 0;
		for(int i = 0 ;i < N; i++){
			cin>>now;
			if(pre == now)
				continue;
			else{
				pre = now;
				sequence.push_back(now);
			}
		}//先筛选一遍重复的
		memset(visited, false, sizeof(visited));
		stack<int> min;
		for(int i = sequence.size() - 1; i >= 0; i--){
			if(!visited[sequence[i]]){
				min.push(sequence[i]);
				visited[sequence[i]] = true;
			}
		}
		cout<<min.size()<<endl;
		while(!min.empty()){
			cout<<min.top();
			min.pop();
			if(min.empty())
				;
			else
				cout<<" ";
		}
		cout<<endl;

	}

	return 0;
}
