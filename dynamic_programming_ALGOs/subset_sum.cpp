#include <bits/stdc++.h>
using namespace std;

#define input(_x) int _x;cin>>_x;
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define VECTOR_FILL(_vec,size) int _x;FOR(_,1,size){cin>>_x; _vec.push_back(_x);}
#define NFOR(_i,_a,_b) for(int _i=_a;_i>=_b;_i--)

int main()
{
	input(n)
	vector<int> v_input;
	VECTOR_FILL(v_input,n);
	sort(v_input.begin(),v_input.end());

	int m=0;
	FOR(i,0,n-1) m+=v_input[i];

	vector<int> v_ans(m+1);

	v_ans[0]=1;

	FOR(i,0,n-1)
		NFOR(j,m,v_input[i])  
		  v_ans[j]=v_ans[j] || v_ans[j-v_input[i] ];

	input(sum)
	cout<<v_ans[sum]<<endl;

   	return 0;
}
