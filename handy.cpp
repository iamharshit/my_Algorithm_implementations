#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
//using namespace pb_ds; //for older c++ version
using namespace __gnu_pbds; 
 
#define input(_x) int _x;_x=getint();
#define input_s(_x) string _x;cin>>_x;
#define input_lli(_x) lli _x;cin>>_x;
#define input_ulli(_x) ulli _x;cin>>_x;
#define TCASE int _t;scanf("%d",&_t);FOR(_i,1,_t)
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define FORauto(_it,_vec) for(auto _it=vec.begin();_it!=_vec.end();++_it)
#define nFOR(_i,_a,_b) for(int _i=_a;_i>=_b;_i--)
#define REPEAT(_i,_b) for(int _i=1;_i<=_b;_i++)
#define VECTORFILL(_vec) int _x;_x=getint();while(_x!=-1){vec.push_back(_x);_x=getint();}
#define VECTOR_FILL(_vec,size) {int _x;FOR(_,1,size){_x=getint(); _vec.pb(_x);}}
#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}}
#define delete_repeat(_v) sort(all(_v)); _v.erase(unique(all(_v)),_v.end())
#define in(_item,_vec) (_vec.find(_item)!=_vec.end())
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define mp make_pair
#define all(_vec) _vec.begin(),_vec.end()
#define rall(_vec) _vec.rbegin(),_vec.rend()
#define X first
#define Y second
#define ARR_SIZE(_arr) sizeof(_arr)/sizeof(_arr[0])
int ARRSIZE(int arr[]){int index=0;while(arr[index]!=-1){index++;}return index;}
#define ARRFILL(_arr) int _index=0,_x;cin>>_x;while(_x!=-1){_arr[_index++]=_x;cin>>_x;}arr[_index]=-1;
#define ARR_FILL(_arr,_size) REPEAT(_i,_size){ input(_x); _arr[_i-1]=_x; }
#define ARRPRINT(_arr) FOR(i,0,ARRSIZE(_arr)-1) cout<<_arr[i]<<endl;
#define arr_clear(_arr,x) memset(_arr, x,sizeof _arr)
#define INT(_s) stoi(_s)
#define LLint(_s) stoi(_s)
#define ULLint(_s) stoull(_s)
string STR(int _a){stringstream ss; ss<<_a; return ss.str();}
#define LOWER(_s) transform(_s.begin(), _s.end(), _s.begin(), ::tolower);
#define UPPER(_s) transform(_s.begin(), _s.end(), _s.begin(), ::toupper);
#define bit(x,i) (1&(x>>i))
#define bitcount(x) __builtin_popcount(x)
#define most_significant(x) (63-__builtin_clzll(x))
#define pi 3.141592653589 //7932384626433832795028
#define INF (int)1e9
# define INF2 0x3f3f3f3f
#define MOD 1000000007
#define maxx(a,b) (a>b?a:b)
#define abss(a) (a>0?a:-a)
#define minn(a,b) (a<b?a:b)
#define READ(x) freopen(x,"r",stdin);
#define WRITE(x) freopen(x,"w",stdout);
#define boost ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define whatis(x) cout<<#x<<"= "<<x<<endl;
#define S(x) scanf("%d",&x);
#define S2(x,y) scanf("%d%d",&x,&y);
#define P(x) printf("%d\n",x);
#define endl '\n'
#define getx getchar_unlocked
#define putx putchar_unlocked

inline int getint(){
    char _c;
    int _x=0;
    _c=getx();
    while (_c<=' ') _c=getx();
    while (_c>='0'){ _x=10*_x+(_c-'0'); _c=getx();}
    return _x;
}
inline void getll(long long &a){
    register int c;
    a = 0;
    do c = getx(); while (c < '0');
    do{
        a = (a << 1) + (a << 3) + c - '0';
        c = getx();
    } while (c >= '0');
}
inline void outint(int _x){
    char _str[16];
    int _i=0;
    if (_x==0) putx('0');
    else{
    while (_x>0){ _str[_i++]=(_x%10)+'0'; _x=_x/10; }
    while (_i) putx(_str[--_i]);}
    putx('\n');
}
inline void outp(int a) {
  char c;
  char snum[20];
  int i=0;
  int sign = 0;
  if(a < 0) sign = 1;
  a = abs(a);
  do {
    snum[i++]=a%10+48;
    a=a/10;
  } while(a!=0);
  i=i-1;
  if(sign) putchar_unlocked('-');
  while(i>=0)
    putchar_unlocked(snum[i--]);
  putchar_unlocked('\n');
}
inline void outll(long long a){
    int s[25], t = -1;
    do{
        s[++t] = a % 10 + '0';
        a /= 10;
    }while (a > 0);
    while (t >= 0)putx(s[t--]);
    putchar_unlocked('\n');
}
inline int getstring(char s[]){
    register int i = 0, c;
    do c = getchar_unlocked(); while (c < '0');
    do{
        s[i++] = c;
        c = getchar_unlocked();
    } while (c >= '0');
    s[i] = '\0';
    return i;
} 
int readline(char *str) {
    int i = 0;
    char ch;
    while ((ch = getchar()) != '\n') str[i++] = ch;
    str[i] = '\0';
    return i;
}
void outstring(string s){
    register int i,sz=s.size();
    for(i=0;i<=sz-1;i++) putx(s[i]);
    putx('\n');
}

double tick() { 
    static clock_t oldticks;
    clock_t newticks = clock();
    double diff = 1.0 * (newticks - oldticks) / CLOCKS_PER_SEC; 
    oldticks = newticks;
    return diff;
} // writing cout<<tick(); at the end(just before return 0;) gives exec.time

typedef long long lli;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<lli> vlli;
typedef pair<int,int> pii;
typedef vector<pair<int,int> > vpii;
typedef set<string> si; 
typedef list<pair<int,int> > lpii;
typedef vector<vector<ll> > matrix;
typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;
 
#define TRACE
 
#ifdef TRACE
template<class T, class U>
ostream& operator<<(ostream& out, const pair<T, U>& a) {out << "[" << a.first << " " << a.second << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const vector<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const set<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T>
ostream& operator<<(ostream& out, const multiset<T>& a) {out << "[ "; for (auto &it : a)out << it << " "; out << "]"; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const map<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}
template<class T, class U>
ostream& operator<<(ostream& out, const multimap<T, U>& a) {for (auto &it : a)out << it.first << " -> " << it.second << " | "; return out;}

#define pr(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {
    cerr << name << " : " << arg1 << endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ','); cerr.write(names, comma - names) << " : " << arg1 << " | "; __f(comma + 1, args...);
}

#endif

 
int main(){
#ifndef ONLINE_JUDGE
    READ("in.txt");
#endif
TCASE{
    
}
return 0;
} 
