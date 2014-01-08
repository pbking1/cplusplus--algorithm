#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<cctype>
using namespace std;

int main(){
	int n = 0;
	int m = 0;
	string str, sender;
	set<string> friends;
	set<string>::iterator it;
	while(true){
	if(cin>>n)
		break;
	cin>>m;

	for(int i = 0; i < n; ++i){
		cin>>str;
		transform(str.begin(), str.end(), str.begin(), ::toupper);
		friends.insert(str);
	}
	for(int j = 0; j < m; ++j){
		cin>>sender;
		transform(sender.begin(), sender.end(), sender.begin(), ::toupper);
		it = friends.find(sender);
		if(it != friends.end())	
			friends.erase(it);
	}
	cout<<friends.size()<<endl;
	friends.clear();
	}
	return 0;
}
