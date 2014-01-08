#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

struct invest{
	int month;
	double money;
}invest[20];

double rate[20];

double fun(int n, double x){ //秦九韶算法
	double ret;
	ret = rate[n];
	for(int i = n - 1; i >= 0; i--)
		ret = rate[i] + x * ret;
	return ret;
}

int main(){
	int final_month;
	double total_money;
	int m, n;
	int count = 0;
	double ans;
	double a,b;
	while(cin>>m , m != -1){
		count++;
		for(int i = 0; i < m; i++)
			scanf("%d%lf",&invest[i].month, &invest[i].money);
		scanf("%d%lf", &final_month,&total_money);
		memset(rate, 0, sizeof(rate));
		for(int j = 0; j < m; j++)
			rate[final_month - invest[j].month + 1] = invest[j].money;
		rate[0] = -total_money;
		
		n = final_month - invest[0].month + 1;
		a = 1;
		b = 2;
		while(true){  //binary search to find the solution of the equation
			ans = (a + b) / 2;
			if(fabs(fun(n, ans)) < 1e-6)
				break;
			if(fun(n, a) * fun(n, ans) > 0)
				a = ans;
			else
				b = ans;
		}
		if(count == 1)
			printf("Case %d: %.5lf\n", count, ans - 1);
		else
			printf("\nCase %d: %.5lf\n", count, ans - 1); 
	}
	return 0;
}
