#include <bits/stdc++.h>
using namespace std;

void generate_combination(int n,int r,int pos=0,int ans=0){
    if(r==0)
        cout<<ans<<endl;
    else
        for(int i=pos+1;i<=n-r+1;i++)
            generate_combination(n,r-1,i,ans*10+i);
}

int main(){
    int n,r;
    n=4;
    r=3;
    generate_combination(n,r);
    /*output: 123
              124
              134
              234
    */

    return 0;
}
