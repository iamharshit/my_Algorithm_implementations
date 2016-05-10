#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

#define INPUT(_x) int _x;cin>>_x;
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define TCASE int _t;cin>>_t;FOR(i,1,_t)
#define VECTORFILL(_vec) int _x;cin>>_x;while(_x!=-1){vec.push_back(_x);cin>>_x;}
#define VECTORPRINT(_vec) int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<" ";}

void bubbleSort(vector<int> _vec){
	FOR(i,1,vec.size()-1 ){
		int last=vec.size()-i;
		FOR(j,1,last)
			if(vec[j-1]>vec[j]){
				int temp=vec[j-1];
			  	vec[j-1]=vec[j];
			  	vec[j]=temp;
			}
	}
}

int main()
{
	VECTORFILL(vec);      //assuming -1 is the breaking point

	bubbleSort(vec);

	return 0;
}
