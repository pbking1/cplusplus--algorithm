#include<iostream>
#include<cmath>
using namespace std;
int s[1000];
//将结果映射到一维数组
int main(){
	memset(s, 0, sizeof(s));
	int T, M;
	int v, t, _max = -1;
	cin>>T>>M;
	for(int i = 1; i <= M; i++){
		cin>>t>>v;
		for(int j = T; j >= 0; j--){ //逆序枚举
			if(j >= t)  // 因为是逆序枚举，所以s[j]保存的值就是s(i-1, j)的结果
				//而s[j-t]保存的是s(i-1, j-t)的结果
				s[j] = max(s[j], s[j - t] + v);
			if(s[j] > _max)
				_max = s[j];
		}
	}
	cout<<_max<<endl;
	return 0;
}
