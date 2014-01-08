#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Test{
	int a, b;
};

bool cmp(const Test &v1, const Test &v2){
	return v1.a < v2.a;//升序
}

bool cmp2(const Test &v1, const Test &v2){
	return v1.b > v2.b;
}

void pushback(vector<Test> &v, const int& a1, const int& b1){
	Test t;
	t.a = a1;
	t.b = b1;
	v.push_back(t);
}

void printVector(vector<Test> &v){
	for(vector<Test>::iterator it = v.begin(); it != v.end(); it++)
		cout<<it -> a<<'\t'<<it -> b<<endl;
}

int main(){
	vector<Test> array;
	pushback(array, 9, 3);
	pushback(array, 3, 0);
	pushback(array, 4, 8);
	pushback(array, 5, 3);
	pushback(array, 3, 3);
	pushback(array, 1, 7);
	pushback(array, 7, 2);
	pushback(array, 4, 3);
	pushback(array, 9, 4);
	pushback(array, 9, 1);
	cout<<"before sort:";
	printVector(array);
	cout<<"sort the a in up";
	sort(array.begin(), array.end(), cmp2);
	printVector(array);

	cout<<"sort the b in down";                                                 
	sort(array.begin(), array.end(), cmp);                                                         
	printVector(array); 

	cout<<"sort the 3th to end";
	sort(array.begin() + 3, array.end(), cmp2);
	printVector(array);
	return 0;
}

