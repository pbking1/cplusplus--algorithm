#include<iostream>
#include<stack>
#include<cstdio>
using namespace std;

int main(){
	int n;
	while(1){
		cin>>n;
		if(n == 0)
			break;
		int temp;
		while(cin>>temp && temp != 0){
			int k = 1;
			stack<int> in;
			for(int i = 0 ; i < n; i++){
				if( i != 0 )
					cin>>temp;

				if(in.empty())
					in.push(k++);
				while(temp != in.top() && temp > in.top())
					in.push(k++);
				//
				if(!in.empty())
					in.pop();
			}
			if(in.empty())
				cout<<"Yes"<<endl;
			else
				cout<<"No"<<endl;
		}
		cout<<endl;
	}
	return 0;
}
