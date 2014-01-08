#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main(){
	int n, m;
	cin>>n>>m;
	string namelist[1000];
	for(int i = 0; i < n; i++){
		cin>>namelist[i];
	}
	string sendlist[1000];
	int sendcount = 0;
	string temp;
	for(int j = 0;; j++){
		cin>>temp;
		if(temp == "0")
			break;
		sendlist[j] = temp;
		sendcount++;
	}
	sort(namelist, namelist + n);
	sort(sendlist, sendlist + sendcount);
	int result = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < sendcount; j++){
			if(namelist[i] == sendlist[j]){
				result++;
			//	namelist[i] = "$";
			}
		}
	}
	cout<<result<<endl;
	return 0;
}
