#include<iostream>
#include<cmath>
//顺推法
int s[1000][1000];//用来存放子问题的解
using namespace std;
int main(){
	int T, M; //T为时间上限(背包容量)， M为药草份数(物品总数)
	int _max = -1;
	int t, v;
	cin>>T>>M;
	for(int i = 1; i <= M; i++){
		cin>>t>>v;
		for(int j = 0; j <= T; j++){
			s[i][j] = s[i - 1][j]; //先把前一个状态的值赋给当前状态
			if(j >= t)  //动态规划过程，当有足够时间采当前药时
				s[i][j] = max(s[i - 1][j - t] + v, s[i - 1][j]);
				//把采这份药后的价值(必须预留出j-t时间让我们可以采这份药)和不采这份药(上一个状态)相比哪个价值更大？
			if(s[i][j] > _max) //如果现在的总值大于最大值
				_max = s[i][j];  //赋值
		}
	}
	cout<<_max<<endl;
}





