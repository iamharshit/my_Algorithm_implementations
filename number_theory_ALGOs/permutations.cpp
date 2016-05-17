#include <bits/stdc++.h>
using namespace std;

#define input_s(_x) string _x;cin>>_x;
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

void permutation(string arr,int start,int endd){
    if(start==endd){
        FOR(i,0,endd)
            cout<<arr[i]<<" ";
        cout<<endl;
    }
    else 
        FOR(k,start,endd){
            int t1=arr[start];  arr[start]=arr[k]; arr[k]=t1;
            permutation(arr,start+1,endd);
            int t2=arr[start];  arr[start]=arr[k]; arr[k]=t2;
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input_s(s);
    permutation(s,0,s.length()-1);
    
    return 0;
}
