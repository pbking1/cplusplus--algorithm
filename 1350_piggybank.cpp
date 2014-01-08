/*题意:有N个存钱罐，标号为1~N，每个存钱罐的钥匙都放在某一个存钱罐当中。
要打开存钱罐，可以用钥匙开或者打烂存钱罐。问要打开所有的存钱罐，至少要打烂多少个存钱罐。

分析样例:n=4,  2 1 2 4, 意思是罐 1 的钥匙放在罐 2 里, 罐 2 的钥匙放在罐 1 里, 罐 3 的钥匙放在罐 2 里,罐 4 的钥匙放在罐 4 里
各有向边: 2->1 ,1->2 , 2->3, 4->4  有向边 s->t 的意思是罐 t 的钥匙放在罐 s 里,要打开罐 t 得先打开 罐 s ,所以 par[t]=s
故par[1]=2,par[2]=1,par[3]=2,par[4]=4 ,每个顶点的入度只能为 1 ,即它的父亲结点唯一,(你无法把钥匙同时放在两个罐子里)
可以看出,每个顶点的状态只能有2种: 自己 或者 它的父亲(祖先)结点 落在环内
所以问要打开所有的存钱罐至少得打烂多少个存钱罐,就相当于求图内存在多少个独立的环
如果一个顶点的父亲(祖先)结点落在环内,那么它也算做是环的一部分而不必另外计数
*/
#include<iostream>
#include<cstring>
using namespace std;
int n;
int next[1000001];  //指向下一个节点的指针
int visited[1000001]; //对每个节点进行不同的标记
int ans, stringID, temp;

void search(){
	for(int i = 1; i <= n; i++){
		if(visited[i] > 0)
			continue;
		temp = i;
		++stringID;  //对每一种环进行一种不同的标记，新的起点必须更换新的染色
		while(visited[temp] == 0){ //当前节点未被染色
			visited[temp] = stringID;//染色
			temp = next[temp]; //指向下个节点
			if(visited[temp] == stringID) //下个一节点的颜色和当前染色相同，则说明存在一个环
				++ans;
		}
	}
}

int main(){
	while(cin>>n){
		ans = 0;
		stringID = 1;
		memset(visited, 0, sizeof(visited));
		for(int i = 1; i <= n; i++){
			cin>>next[i];
			if(next[i] == i){//如果自环
				visited[i] = stringID++; //对自环进行处理
				ans++;
			}
		}
		search();
		cout<<ans<<endl;
	}
	return 0;
}
		
