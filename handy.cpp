#include <bits/stdc++.h>
using namespace std;
 
#define input(_x) int _x;cin>>_x;
#define input_s(_x) string _x;cin>>_x;
#define input_lli(_x) lli _x;cin>>_x;
#define input_ulli(_x) ulli _x;cin>>_x;
#define TCASE int _t;cin>>_t;FOR(_i,1,_t)
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define nFOR(_i,_a,_b) for(int _i=_a;_i>=_b;_i--)
#define REPEAT(_i,_b) for(int _i=1;_i<=_b;_i++)
#define VECTORFILL(_vec) int _x;cin>>_x;while(_x!=-1){vec.push_back(_x);cin>>_x;}
#define VECTOR_FILL(_vec,size) int _x;FOR(_,1,size){cin>>_x; _vec.push_back(_x);}
#define VECTORPRINT(_vec) int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<endl;}
#define pb push_back
#define mp make_pair
#define all(_vec) _vec.begin(),_vec.end()
#define X first
#define Y second
#define ARR_SIZE(_arr) sizeof(_arr)/sizeof(_arr[0])
int ARRSIZE(int arr[]){int index=0;while(arr[index]!=-1){index++;}return index;}
#define ARRFILL(_arr) int _index=0,_x;cin>>_x;while(_x!=-1){_arr[_index++]=_x;cin>>_x;}arr[_index]=-1;
#define ARR_FILL(_arr,_size) REPEAT(_i,_size){ input(_x); _arr[_i-1]=_x; }
#define ARRPRINT(_arr) FOR(i,0,ARRSIZE(_arr)-1) cout<<_arr[i]<<endl;
#define arr_clear(a,x) memset(a, x, sizeof(a))
#define INT(_s) stoi(_s)
string STR(int _a){stringstream ss; ss<<_a; return ss.str();}
#define LOWER(_s) transform(_s.begin(), _s.end(), _s.begin(), ::tolower);
#define UPPER(_s) transform(_s.begin(), _s.end(), _s.begin(), ::toupper);
#define MAX_INT 2147483647
#define MOD 1e9 + 7
 
typedef long long int lli;
typedef unsigned long long int ulli;
typedef vector<int> vi;
typedef vector<lli> vlli;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef set<string> si; 
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    
	TCASE{
	    
	}
	
    return 0;
} 
