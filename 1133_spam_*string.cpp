#include<iostream>
#include<string>
#include<cstring>
#include<cctype>
using namespace std;

int main(){
	char str[1000];
	while(cin.getline(str, 1000)){
		int n = strlen(str);
		for(int i = 1; i < n - 1; ++i){
			if(str[i] != '@')
				continue;
			int pos = i, tmp = i;
			if(str[i - 1] == ' ' || str[i - 1] == '.' || str[i - 1] == '@' || str[i + 1] == ' ' || str[i + 1] == '.' || str[i + 1] == '@')
				continue;
			while(pos - 1 >= 0 && str[pos - 1] != ' ' && !(pos - 2 >= 0 && str[pos - 1] == '.' && str[pos - 2] == '.') && str[pos - 1] != '@')
				pos--;
			if(str[pos] == '.')
				pos++;
			while(pos != i){
				cout<<str[pos];
				pos++;
			}
			while(pos + 1 <= n - 1 && str[pos + 1] != ' ' && !(pos + 2 <= n -1 && str[pos + 1] == '.' && str[pos + 2] == '.') && str[pos + 1] != '@')
					pos++;
			if(str[pos] == '.')
				pos--;
			while(tmp <= pos){
				cout<<str[tmp];
				++tmp;
			}
			cout<<endl;
		}
	}
	return 0;
}



