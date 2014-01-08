#include<iostream>
#include<queue>
#include<map>
using namespace std;
/*
 Input
 第一行是一个整数n，表示一共有多少组测试数据。
 下面n行每行9个字符，用空格隔开，代表一个初始状态。
 目标状态是 1 2 3 4 5 6 7 8 0。
 
 Output
 最小操作步数，无解时输出-1。
 
 sample input
 4
 1 2 3 4 5 0 7 8 6
 1 2 3 4 0 5 6 7 8
 8 6 7 2 5 4 3 0 1
 6 4 7 8 5 0 3 2 1
 
 sample output
 1
 14
 31
 31
 
 注意在 Release 模式下运行此程序，否则可能会很慢！
 注意优先队列 priority_queue 是最大堆，因此在定义 STATE 结构的比较函数时要让 f 值较小的元素较大，
 而当 f 相等的时候，启发函数 h 较小的状态应该优先考虑，故让该状态较大。
 优先队列中仍然会存在一些 CLOSED 表中的状态，因为在生成新的状态时没有查找删除该新状态是否生成过。
 */

const int ten[9] = {100000000, 10000000, 1000000, 100000, 10000, 1000, 100, 10,1};
int dist[9][9], diff[9][9];
//dist[i][j]为位置i，j的曼哈顿距离，diff[i][j]为交换位置i,j使状态数改变的量
int goalPos[9] = {8, 0, 1, 2, 3, 4, 5, 6, 7};
//goalpos[i]为目标状态中i的位置
int goalNum  = 123456780; //目标状态的状态数
int goallnv = 0;  //目标状态忽略0后的逆序数
int state[9]; //当前状态

struct STATE{
	int num, pos, g, h;  //状态数， 0的位置， 到达此状态的耗费， 到达目标状态的启发函数值
	STATE(int num, int pos, int g, int h):num(num), pos(pos), g(g), h(h){}
	bool operator<(const STATE& other) const{ //状态的评价函数等于耗费加上启发函数值
		if(g + h == other.g + other.h)  //由于查询较少，此句帮助不大
			return h > other.h;
		return g + h > other.g + other.h;
	}
};

void preprocess(){  //预处理 
	for(int i = 0; i < 9; i++){
		dist[i][i] = 0;
		for(int j = 0; j < i; j++){
			dist[i][j] = dist[j][i] = abs(i/3 - j/3) + abs(i%3 - j%3);
			diff[i][j] = diff[j][i] = abs(ten[i] - ten[j]);
		}
	}
}

//检查开始状态忽略0后的逆序数， 如果和目标装填的逆序数奇偶性不一致，则无解
bool noAnswer(int pos){
	int inv = 0;
	for(int i = 0; i < 9; i++)
		for(int j = 0; j < i; j++)
			if(state[j] > state[i])
				inv++;
	return (inv - pos - goallnv) % 2 != 0;
}

int heu(int pos){ //计算启发值
	int h = 0;
	for(int i = 0; i < 9; i++){
		int j = goalPos[state[i]];
		h += dist[i][j];
	}
	return h - dist[pos][goalPos[0]];
}

int astar(){
	int num = 0, pos = 0;
	for(int i = 0; i < 9; i++){
		cin>>state[i];
	}
	for(int i = 0; i < 9; i++){
		num = num * 10 + state[i];
	}
	for(int i = 0; state[i]; i++){
		pos++;
	}
	if(noAnswer(pos))
		return -1;
	map<int, int> ng; //closed表， 已拓展结点（状态数 -》 到达该节点的最少耗费）
	priority_queue<STATE> q; //opened表， 待拓展结点， 但是仍然会存在已拓展节点的记录
	STATE start(num, pos, 1, heu(pos)); //因为map对不存在的key返回0， 故初始状态的耗费应该设为1

	q.push(start);
	while(q.size()){
		STATE top = q.top();  //考察open表里面评价函数值最小的节点
		q.pop();
		int pos = top.pos, num = top.num, g = top.g, h = top.h;
		if(num == goalNum){
			return g - 1;  //找到最优解，注意要减掉1
		}
		if(ng[num])
			continue; //已经拓展过此节点则忽略
		ng[num] = g; //节点加入closed表
		//拓展词节点
		if(pos > 2){
			int p = pos - 3;
			int i = num / ten[p] % 10, n = num - i * diff[pos][p];
			int h2 = h - dist[p][goalPos[i]] + dist[pos][goalPos[i]];
			if(!ng[n])
				q.push(STATE(n, p, g + 1, h2));
		}
		if(pos < 6){
			int p = pos + 3;
			int i = num / ten[p] % 10, n = num + i * diff[pos][p];
			int h2 = h - dist[p][goalPos[i]] + dist[pos][goalPos[i]];
			if(!ng[n])
				q.push(STATE(n, p, g + 1, h2));
		}
        if(pos % 3){
			int p = pos - 1;
			int i = num / ten[p] % 10, n = num - i * diff[pos][p];
			int h2 = h - dist[p][goalPos[i]] + dist[pos][goalPos[i]];
			if(!ng[n])
				q.push(STATE(n, p, g + 1, h2));
		}
        if(pos % 3 != 2){
			int p = pos + 1;
			int i = num / ten[p] % 10, n = num + i * diff[pos][p];
			int h2 = h - dist[p][goalPos[i]] + dist[pos][goalPos[i]];
			if(!ng[n])
				q.push(STATE(n, p, g + 1, h2));
		}
	}
	return 0;
}

int main(){
	preprocess();
	int t;
	cin>>t;
	while(t--){
		cout<<astar();
	}
	return 0;
}




















