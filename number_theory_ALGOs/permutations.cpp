/*
    equivalent code:
        do{
            cout<<s<<endl;
        }while(next_permutation(s.begin(),s.end()) );
*/

#include <bits/stdc++.h>
using namespace std;

#define input_s(_x) string _x;cin>>_x;
#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

void permutation(string arr,int start,int endd){
    if(start==endd){
        FOR(i,0,endd)
            cout<<arr[i];
        cout<<endl;
    }
    else 
        FOR(k,start,endd){
            swap(arr[start],arr[k]);
            permutation(arr,start+1,endd);
            swap(arr[start],arr[k]);
        }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    input_s(s);
    permutation(s,0,s.length()-1);
    
    return 0;
}
