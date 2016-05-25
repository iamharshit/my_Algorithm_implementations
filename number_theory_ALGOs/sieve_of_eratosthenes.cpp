#include <bits/stdc++.h>
using namespace std;

#define sz 10000000
int sievearr[sz +1];

#define TCASE int _t;cin>>_t;FOR(i,1,_t)
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define VECTORFILL(_vec) int _x;cin>>_x;while(_x!=-1){vec.push_back(_x);cin>>_x;}
#define VECTORPRINT(_vec) int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<endl;}
#define ARR_SIZE(_arr) sizeof(_arr)/sizeof(_arr[0])
int ARRSIZE(int arr[]){int index=0;while(arr[index]!=-1){index++;}return index;}
#define ARRFILL(_arr) int _index=0,_x;cin>>_x;while(_x!=-1){_arr[_index++]=_x;cin>>_x;}arr[_index]=-1;
#define ARRPRINT(_arr) FOR(i,0,ARRSIZE(_arr)-1) cout<<_arr[i]<<endl;

void sieve(int n){
	FOR(i,2,n) sievearr[i]=1;
	FOR(i,2,n)
	 	if(sievearr[i]==1)
			for(int j=2;i*j<=n;j++) sievearr[i*j]=0;
}

int main()
{
	sieve(sz);
  	return 0;
}
