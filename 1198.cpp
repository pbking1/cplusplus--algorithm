#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

bool cmd(string a, string b){
	return a + b < b + a;
}

int main(){
	int n;
	string a[1000];
	cin>>n;
	for(int i = 0; i <= n; i++){
		int m;
		cin>>m;
		for(int j = 0; j < m; j++){
			cin>>a[j];
		}
		sort(a, a + m, cmd);
		for(int j = 0; j < m; j++){
			cout<<a[j];
		}
		cout<<endl;
	}
	return 0;
}
