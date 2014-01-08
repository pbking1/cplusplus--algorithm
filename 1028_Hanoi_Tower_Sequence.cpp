///* 
//【题目大意】 
//汉诺塔，将其移动的每一步的盘号列出作为序列，求第p步需要移动的盘的盘号 
//序列如下：1, 2, 1, 3, 1, 2, 1, 4, 1, 2, 1, 3, 1, 2, 1....  
//【解决方案】 
//输入的p将达到10^100，使用string接收  
//注意每个case之间要多一个空行  
//1、移动盘子的规律：把前n-1个盘子移到二号柱子，移动n号盘，然后再移动前n-1个盘到三好柱子即可 
//移动一个盘子要1步，移动k（k>1）个盘子要f(k)=f(k-1)+1+f(k-1)=2^k-1步 
//也即在序列中，当p=2^k时，f(p)=k+1，并且这是k+1号盘子的第一次出现；  
//2、直观上看，如果某一位数字是k，那么它的前2^(k-1)-1个数和后2^(k-1)-1个数是一样的 
//3、根据第二条，对于某个p，如果2^k < p < 2(k+1)，那么f(p)和f(p-2^k)是相等的 
//这里如果根据二进制来看：把p化成二进制数，假设现在p里有超过1个位为1，设最高位为k， 
//则在2^k步前和2^k步后对称，因此第p步移的盘子与第p-2^k步移的盘子一样。 
//4、根据第三条，一直往前循环，从二进制的角度看，p排在高位的1一个个被减掉，直到p里只有1个位为1， 
//设此时p=2^m，对应的二进制数是1后面跟着m个0，则此步移动的是第m+1个盘子。 
//直观上看，这是第m+1号盘子的第一次移动（结合第一条），而这个m+1就是我们想要的结果 
//5、可以得知：如果p1=11010101011101010110111000，根据第三条，可以一直往前追朔到p2=1000，并且f(p1)=f(p2) 
// 从第一条我们可以知道f(p1)=f(p2)=f(2^3)=3+1=4 
//6、由以上可得：对于p，如果其二进制表示时结尾0的数量为m，那么第p位就是m+1， 
//我们知道，一个整数除以2时表现为二进制右移一位， 
//所以：对于p，求得其可整除2的次数m，即可得结果为m+1 
//7、于是这一题就变成了吃果果的大数求余了。 
#include<iostream>
#include<string>
using namespace std;
//大数求模
inline int Mod(const string& a, const int& b){
	int result = 0;
	for(int i = 0; i < a.length(); i++){
		int num = result * 10 + (a[i] - '0');
		result = num % b;
	}
	return result;
}

//大数除法
inline string Div(const string& a, const int& b){
	int buf = 0;
	string result = "";
	for(int i = 0; i < a.length(); i++){
		int num = buf * 10 + (a[i] - '0');
		buf = num % b;
		result += (num/b + '0'); //可以肯定只有一位所以可以直接用这种方法得到char
		}
	return result;
}

int compute(string num){
	int result = 1;
	while(1){
		if(Mod(num, 2) == 0){
			result++;
			num = Div(num, 2);
		}else{
			return result;
		}
	}
}

int main(){
	int cases;
	cin>>cases;
	int m = cases;
	string num;
	while(cases--){
		cin>>num;
		if(m - cases != 1)
			cout<<endl;
		cout<<"Case "<<m - cases<<": "<<compute(num)<<endl;
	}
	return 0;
}




