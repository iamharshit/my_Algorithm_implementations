#include <bits/stdc++.h>
using namespace std;

bool kmp(string substring, string pattern){
    int n=substring.size(), m=pattern.size();

    vector<int> prefix(m);
    int i=0, j=1;
    while(j<m)
        if(pattern[i]==pattern[j]){
            prefix[j]=i+1;
            i++,j++;
        }
        else if(i==0){
            prefix[j]=0;
            j++;
        }
        else{
            i=prefix[i-1];
        }

    i=0, j=0;
    while(i<n){
        if(substring[i]==pattern[j])
            i++,j++;
        else if(j==0)
            i++;
        else
            j=prefix[j-1];
        if(j==m) return true;
    }

    return false;
}

int main(){
    string substring="abcabc";
    string pattern="bca";

    bool exists=kmp(substring,pattern);
    if(exists)
        cout<<"pattern does exists";
    else
        cout<<"pattern does not exists";

    // output: pattern does exists

    return 0;
}
