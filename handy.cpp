#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef long long ll;

vector<int> vec;

#define input(_x) int _x;cin>>_x;
#define TCASE int _t;cin>>_t;FOR(_i,1,_t)
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define REPEAT(_i,_b) for(int _i=1;_i<=_b;_i++)
#define VECTORFILL(_vec) int _x;cin>>_x;while(_x!=-1){vec.push_back(_x);cin>>_x;}
#define VECTORPRINT(_vec) int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<endl;}
#define ARR_SIZE(_arr) sizeof(_arr)/sizeof(_arr[0])
int ARRSIZE(int arr[]){int index=0;while(arr[index]!=-1){index++;}return index;}
#define ARRFILL(_arr) int _index=0,_x;cin>>_x;while(_x!=-1){_arr[_index++]=_x;cin>>_x;}arr[_index]=-1;
#define ARR_FILL(_arr,_size) REPEAT(_i,_size){ input(_x); _arr[_i-1]=_x; } 
#define ARRPRINT(_arr) FOR(i,0,ARRSIZE(_arr)-1) cout<<_arr[i]<<endl;
#define INT(_s) stoi(_s)
string STR(int _a){stringstream ss; ss<<_a; return ss.str();}


int main()
{
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	
    return 0;
}
