#include<iostream>
#include<string>
#include<cstdio>
#include<queue>
#include<map>
using namespace std;
//from the beginning mode ,use breadth sort to get all the result, and find the input in the result generated.
void changeA( const string &s, string &t ) {   //upside down the up row and down row 
	    t[ 0 ] = s[ 4 ];  
	    t[ 1 ] = s[ 5 ];  
	    t[ 2 ] = s[ 6 ];  
	    t[ 3 ] = s[ 7 ];  
	    t[ 4 ] = s[ 0 ];  
	    t[ 5 ] = s[ 1 ];  
	    t[ 6 ] = s[ 2 ];  
	    t[ 7 ] = s[ 3 ];  
}  
  
void changeB( const string &s, string &t ) {    //cycle right one charactor
	    t[ 0 ] = s[ 3 ];  
	    t[ 1 ] = s[ 0 ];  
	    t[ 2 ] = s[ 1 ];  
	    t[ 3 ] = s[ 2 ];  
	    t[ 4 ] = s[ 7 ];  
	    t[ 5 ] = s[ 4 ];  
	    t[ 6 ] = s[ 5 ];  
	    t[ 7 ] = s[ 6 ];  
}  
  
void changeC( const string &s, string &t ) {  //the four charactor in the middle clockwise
	    t[ 0 ] = s[ 0 ];  
	    t[ 1 ] = s[ 5 ];  
	    t[ 2 ] = s[ 1 ];  
	    t[ 3 ] = s[ 3 ];  
		t[ 4 ] = s[ 4 ];  
	    t[ 5 ] = s[ 6 ];  
		t[ 6 ] = s[ 2 ];  
	    t[ 7 ] = s[ 7 ];  
}     

int main(){
	string now, target = "12348765";
	queue<string> q;   //the queue used in storing the operation
	map<string, string> m;   //store the matrix
	m[target].clear();   //clear the matrix 
	q.push(target);   //put the target in the queue first
	int j, i;
	for(j = 1; j <= 10; j++){  //get all the result
		i = q.size();   //get size of the queue
		while(i--){
			now = q.front();
			
			changeA(now, target);
			if(m.find(target) == m.end()){  //if the target is the as the string now
				m[target] = m[now] + 'A';
				q.push(target);
			}
			
			changeB(now, target);
			if(m.find(target) == m.end()){
				m[target] = m[now] + 'B';
				q.push(target);
			}

			changeC(now, target);
			if(m.find(target) == m.end()){
				m[target] = m[now] + 'C';
				q.push(target);
			}
		q.pop();
		}
	}
	int M;
	while(cin>>M, M != -1){
		for(int i = 0; i < 8; i++){
			cin>>j;
			target[i] = '0' + j;   //transfer the number into string
		}

		if(m.find(target) == m.end() || m[target].size() > M)
			cout<<-1<<endl;
		else
			cout<<m[target].size()<<" "<<m[target].c_str()<<endl;
	}
	return 0;
}

