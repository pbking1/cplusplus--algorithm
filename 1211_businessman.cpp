#include <iostream>
using namespace std;
//get all the path from two point to another
int main(){
	int mat1[100][100] = { 0 };
	int mat2[100][100] = { 0 };
	int n, m ,l;
	cin>>n>>m>>l;
	while(m--){
		int t1, t2;
		cin>>t1>>t2;
		mat1[t1 - 1][t2 - 1] = 1;   //store the path
		mat2[t1 - 1][t2 - 1] = 1;   //store the point
	}

	int q;
	cin>>q;   //cin the number of the case

	while(q--){
		int begin, end;
		cin>>begin>>end;
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				mat1[i][j] = mat2[i][j];

		for(int k = 0; k < l - 1; k++){
			int line[100] = { 0 };
			for(int i = 0; i < n; i++)
				for(int j = 0; j < n; j++)
					line[i] += mat1[begin - 1][j] * mat2[j][i]; //add a path to the total
			for(int i = 0; i < n; i++)
				mat1[begin - 1][i] = line[i];
		}
		cout<<mat1[begin - 1][end - 1]<<endl;
	}
	return 0;
}
