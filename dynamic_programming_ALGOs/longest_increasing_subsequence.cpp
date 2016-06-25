// complexity = O(n^2)

#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define pb push_back
#define mp make_pair
#define all(_vec) _vec.begin(),_vec.end()
#define X first
#define Y second
#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<' ';}}

typedef vector<int> vi;
typedef vector<pair<int,int> > vpii;

int lis_len;
vi lis_seq;

void LIS(int sz,int seq[]){
    vpii arr(sz,mp(1,-1));
    lis_len=1;
    int lis_last_index=0;
    FOR(i,1,sz-1){
        FOR(j,0,i-1)
            if(seq[j]<seq[i])
                if(arr[j].X+1 > arr[i].X){
                    arr[i].X = arr[j].X+1;
                    arr[i].Y = j;
                }
        if(lis_len<arr[i].X){
            lis_len = arr[i].X;
            lis_last_index = i;
        }
    }
    int index=lis_last_index;
    while(index!=-1){
        lis_seq.pb(seq[index]);
        index=arr[index].Y;
    }
    reverse(all(lis_seq));
}

int main(){
    int sz=10;
    int seq[]={1,2,9,4,7,3,11,8,14,6};
    LIS(sz,seq);
    cout<<"length of longest increasing subsequence= "<<lis_len<<endl;
    cout<<"longest increasing subsequence= ";
    VECTORPRINT(lis_seq); cout<<endl;

    return 0;
}
