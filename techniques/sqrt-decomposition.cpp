#include <bits/stdc++.h>
using namespace std;

int n;
int rootn;
vector<int> arr;
vector<long long int> bsum;
vector<long long int> bchange;

void initialise(){
    for(int i=0;i<=n-1;i+=rootn)
        for(int j=i;j<=i+rootn-1;j++)
            if(j<=n-1)
                bsum[(int)i/rootn]+=arr[j];
}

void update(int first, int last, int k){
    int c_l=first/rootn,  c_r=last/rootn;
    if(c_l==c_r){
        for(int i=first; i<=last; i++)
            arr[i]+=k;
        bsum[c_l]+=(last-first+1)*k;
    }
    else{
        for(int i=first; i<=(c_l+1)*rootn-1; i++)
            arr[i]+=k;
        bsum[c_l]+=((c_l+1)*rootn-1-first+1)*k;

        for(int i=c_l+1 ; i<=c_r-1; i++){
            bsum[i]+=rootn*k;
            bchange[i]+= k;
        }

        for(int i=c_r*rootn; i<=last; i++)
             arr[i]+=k;
        bsum[c_r]+=(last-c_r*rootn+1)*k;
    }
}

long long int getsum(int first, int last){
    int c_l=first/rootn, c_r=last/rootn;
    long long int sum=0;
    if(c_l==c_r)
        for(int i=first; i<=last; i++)
            sum+=arr[i]+bchange[c_l];
    else{
        for(int i=first; i<=(c_l+1)*rootn-1; i++)
            sum+=arr[i]+bchange[c_l];
        for(int i=c_l+1; i<=c_r-1; i++)
            sum+=bsum[i];
        for(int i=c_r*rootn; i<=last; i++)
            sum+=arr[i]+bchange[c_r];
    }
    return sum;
}

int main(){
    n=8;
    arr.resize(n);
    arr[0]=3, arr[1]=2, arr[2]=6, arr[3]=1, arr[4]=9, arr[5]=4, arr[6]=2, arr[7]=7;

    rootn=floor(sqrt(n))+1;
    bsum.resize(rootn);
    bchange.resize(rootn);

    initialise();
    update(0, 7, 2);
    cout<<getsum(1,4);
    // output: 26
    
    return 0;
}
