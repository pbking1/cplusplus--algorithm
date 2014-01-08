#include<iostream>
//找到河流中符合不超过k的最长的一段，输出这个长度的大小
//也就是这一段的最大值和最小值的差不超过k
using namespace std;
int maxlength(int deep[], int size, int index, int k){
	int length = 2;
	int min = (deep[index] < deep[index + 1]) ? deep[index] : deep[index + 1]; //选择最小值
	int max = (deep[index] > deep[index + 1]) ? deep[index] : deep[index + 1]; //选择最大值
	if(max - min > k)//如果不满足条件
		return 1;
	for(int i = index + 2; i < size; i++){
		//如果满足条件
		if(deep[i] - max >= -k && deep[i] - max <= k && deep[i] - min <= k && deep[i] - min >= -k){
			length++;
			//不断项两边拓展长度
			if(deep[i] > max)
				max = deep[i];
			if(deep[i] < min)
				min = deep[i];
		}else{
			break;
		}
	}
	return length;
}

int main(){
	int deep[32767], k;
	int size;
	cin>>size>>k;
	for(int i = 0; i < size; i++){
		cin>>deep[i];
	}
	int max = 0;
	for(int i = 0; i < size; i++){
		int temp = maxlength(deep, size, i, k);
		if(temp > max)
			max = temp;
	}
	cout<<max<<endl;
	return 0;
}
