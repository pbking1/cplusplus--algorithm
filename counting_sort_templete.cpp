#include<iostream>
using namespace std;
// 计数排序的基本思想为：对每一个输入的元素x，确定出小于x的元素的个数。有了这一信息，那么就可以把x直接放到相应的位置上。
// 特点：
// 1 需要临时的存储空间，如果排序数据范围特别大时，空间开销很大。
// 2 适合于排序0 - 100以内的数据。
// 3 排序的时间复杂度为O(n)
const int size = 100;
void countingsort(int *a, int *b, int k){
	int *c = new int[sizeof(int) * k];
	for(int i = 0; i < k; i++)
		c[i] = 0;
	for(int i = 0; i < size; i++)
		c[a[i]] += 1;
	for(int i = 1; i < k; i++)
		c[i] += c[i - 1];
	for(int j = size - 1; j >= 0; j--){
		b[c[a[j]]-1] = a[j];
		c[a[j]] -= 1;
	}
	delete c;
}
int main(){
	int *A, *B;
	A = new int[sizeof(int) * size];
	B = new int[sizeof(int) * size];
	srand(0);
	for(int i = 0; i < size; i++){
		int num = rand() % size;
		A[i] = num;
	}
	for(int i = 0; i < 100; i++)
		cout<<A[i]<<" ";
	countingsort(A, B, size);
	cout<<endl;
	for(int i = 0; i < 100; i++)
		cout<<B[i]<<" ";
	cout<<endl;
	delete A;
	delete B;
	return 0;
}
