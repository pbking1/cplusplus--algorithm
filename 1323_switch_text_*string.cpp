#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string s1, s2;
bool checkempty(string str){
	for(int i = 0; i < str.size(); i++)
		if(str > " ")
			return false;
	return true;
}

int main(){
	for(;;){
		getline(cin, s1);
		getline(cin, s2);
		reverse(s1.begin(), s1.end());
		reverse(s2.begin(), s2.end());
		if(s2.size() > 0 && !checkempty(s2)){
			string str1, str2;
			str1.append(s2.begin(), s2.begin() + s2.size()/2); //把前面一半提取出来
			str2.append(s2.begin() + s2.size()/2, s2.end());//把后面一半提取出来
			cout<<str2<<str1<<endl;//逆序数出
		}
		if(s1.size() > 0 && !checkempty(s1)){
			string str3, str4;
			str3.append(s1.begin(), s1.begin() + s1.size()/2);
			str4.append(s1.begin() + s1.size()/2, s1.end());
			cout<<str4<<str3<<endl;
		}
		if(cin.eof())
			break;
	}
	return 0;
}
