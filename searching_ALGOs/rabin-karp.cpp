#include <bits/stdc++.h>
using namespace std;

const int prime=101;

long long int create_hash(string s,int first,int last){
    long long int hash=0;
    for(int i=first;i<=last;i++)
        hash+= (s[i])*pow(prime,i);
    return hash;
}

bool is_equal(string substring, string pattern, int start){
    for(int i=0;i<=(int)pattern.size()-1;i++)
        if(substring[start+i] != pattern[i])
            return false;
    return true;
}

bool rabin_karp(string substring, string pattern){
    int m=substring.size(), n=pattern.size();
    if(m<n) return false;

    long long int a = create_hash(substring,0,n-1);
    long long int b = create_hash(pattern,0,n-1);
    for(int i=0;i<=m-n;i++){
        if(a==b && is_equal(substring,pattern,i) )
            return true;
        if(i==m-n) break;
        a = ( a-substring[i] )/prime + substring[i+n]*pow(prime,n-1);
    }
    return false;
}

int main(){
    string substring="abcabc";
    string pattern="bca";

    bool exists=rabin_karp(substring,pattern);
    if(exists)
        cout<<"pattern does exists";
    else
        cout<<"pattern does not exists";

    // output: pattern does exists

    return 0;
}
