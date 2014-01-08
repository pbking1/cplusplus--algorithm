//string shorten(string m) 把 string m 由中缀式变为右缀式，double calculate(string s) 计算右缀式的表达式值。
//数字写入右缀式m很简单，不过别忘了用个符号把数字分开。我选择的是$。
//比较难的地方是shorten函数，分析怎样把 string m 变为右缀式。可能的计算有这么几种：+，-，*，/，（）。
//
//其实列表的原则挺简单的：
//    1. 把“(”看做开辟一次新的栈（从“(”开始算，忽视之前的元素，直到“）”被取消）；
//    2. 元素a遇到相同或更高优先级的，栈顶元素c出栈，给右缀表达式m；再次对比；直到遇到更高优先级的，元素a入栈；
//    3. “）”出现的时候，之前所有元素依次出栈，写入m，直到“（”；
//    4. 在数字都加入右缀表达式之后，栈中所有元素依次出栈，写入m，直到栈为空。

//然后进行右缀表达式的计算，这个比较简单：数字依次入栈，遇到操作符后对栈顶的两个元素进行顺序操作
//（倒数第二个 +-*/ 倒数第一个），然后把这两个元素换成新的结果。如此循环即可。

#include<iostream>
#include<string>
#include<stack>
//1+2*3
//successfully excuted ! The right hand operator expression is: 
//1$2$3$*+
//The result is : 7
using namespace std;
bool isone(char c){
	return (c == '+' || c == '-');
}

bool istwo(char c){
	return (c == '*' || c == '/');
}

string shorten(string m){
	stack<char> s;
	string current;
	int i;
	char w;
	string sur;
	
	for(i = 0; i < m.size(); i++){
		if(isdigit(m[i]) || m[i] == '.'){
			while(isdigit(m[i]) || m[i] == '.')
				sur += m[i++];
			i--;
			sur += '$';
		}else if(isone(m[i])){
			while(s.size() && (isone(s.top()) || istwo(s.top()))){
				sur += s.top();
				s.pop();
			}
			s.push(m[i]);
		}else if(m[i] == ')'){
			while(s.top() != '('){
				sur += s.top();
				s.pop();
			}
			s.pop();
		}else if(istwo(m[i])){
			while(s.size() && istwo(s.top())){
				sur += s.top();
				s.pop();
			}
			s.push(m[i]);
		}else
			s.push(m[i]);
	}
	while(s.size()){
		sur += s.top();
		s.pop();
	}
	return sur;
}

double tentimes(int n){
	double res = 1;
	for(int i = 0 ; i < n; i++)
		res *= 10;
	return res;
}

double str2double(string s){
	double res = 0;
	char c;
	int dec = 0;
	for(int i = 1; i <= s.size(); i++){
		c = s[i - 1];
		if(c == '.')
			dec = i;
		else if(!dec)
			res = res * 10 + c - '0';
		else
			res += (c - '0')/tentimes(i - dec);
	}
	return res;
}

double calculate(string s){
	double res, t;
	stack<double> num;
	string temp;
	int i;
	for(int i = 0; i < s.size(); i++){
		temp = "";
		if(isdigit(s[i]) || s[i] == '.'){
			while(isdigit(s[i]) || s[i] == '.')
				temp += s[i++];//如果最后一位是数字，这样做会出错
				num.push(str2double(temp));
		}else{
			switch(s[i]){
				case '+':
					t = num.top(); 
					num.pop();
					t += num.top();
					num.pop();
					num.push(t);
					break;
				case '-':
					t = num.top();
					num.pop();
					t = num.top()-t;
					num.pop();
					num.push(t);
					break;
				case '*':
					t = num.top();                                                                                                           
					num.pop();                                                                                                               
					t *= num.top();                                                                                                          
					num.pop();                                                                                                               
					num.push(t);                                                                                                             
					break;
				case '/':
					t = num.top();
					num.pop();
					t = num.top()/t;
					num.pop();
					num.push(t);
					break;
				default:
					cerr<<"Fatal Error! Result is wrong!"<<endl;
			}
		}
	}
	res = num.top();
	return res;
}

int main(){
	string mid, sur;
	cin>>mid;
	sur = shorten(mid);
	cout<<"successfully excuted ! The right hand operator expression is: " << endl;
	cout<<sur<<endl;
	cout<<"The result is : "<<calculate(sur)<<endl;
	return 0;
}

