#include<iostream>
#include<ctime>
using namespace std;
void quick_sort(int a[], int start, int end){
	int i = start;
	int j = end;
	int temp = a[start];

	while(i < j){
		while(i < j && a[j] >= temp) //compare to the start data, 右边的下标左移
			j--;
		a[i] = a[j];
		while(i < j && a[i] < temp) //compare to the start data, 左边的下标右移
			i++;
		a[j] = a[i];
	}
	a[i] = temp; //put start data into i = j;
	if(start < i - 1)
		quick_sort(a, start, i - 1);
	if(end > i + 1)
		quick_sort(a, i + 1, end);

}
int main(){
	srand(unsigned(time(NULL)));
	int array[10];
	for(int i = 0; i < 10; i++)
		array[i] = rand() % 100;
	for(int i = 0; i < 10; i++)
		cout<<array[i]<<" ";
	cout<<endl;
	quick_sort(array, 0, 9);
	for(int i = 0; i < 10; i++)
		cout<<array[i]<<" ";
	return 0;
}
