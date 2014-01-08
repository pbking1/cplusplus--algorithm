#include<iostream>
#include<algorithm>
using namespace std;
int cmp(const void* a, const void* b){
	return ((long*)a)[1] - ((long*)b)[1];
}

int main(){
	int n,s;
	while(cin>>n>>s, n != 0 || s != 0){
		int a[10000][2];
		for(int i = 0; i < n; i++)
			cin>>a[i][0]>>a[i][1];

		qsort(a, n, sizeof(a[0]), cmp);

		int count = 1;
		for(int i = 0; i < n; i++)
			if(s >= a[i][1])
				s += a[i][0];
			else
				count = 0;
		if(count == 0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
