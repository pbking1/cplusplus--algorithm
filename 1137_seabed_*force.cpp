#include<iostream>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	int deep[40000];
	for(int i = 0; i < n; i++)
		cin>>deep[i];
	int i, j, _max, _min;
	int keep, count = 1;
	for(i = 0; i < n - 1; i++){
		_max = i;
		_min = i;
		keep = 1; //记录每次算的长度
		for(j = i + 1; j < n; j++){
			//拓展长度
			if(deep[j] > deep[_max])
				_max = j;
			if(deep[j] < deep[_min])
				_min = j;
			if((deep[_max] - deep[_min]) > m)
				break;
			else
				keep++;
		}
		if(keep > count)
			count = keep; //选择最大的长度
		i = ( _max == j ? _min : _max);
	}
	cout<<count<<endl;
	return 0;
}
