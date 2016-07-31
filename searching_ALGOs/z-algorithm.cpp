#include<bits/stdc++.h>
using namespace std;

vector<int> z_values(string str){
    vector<int> temp(str.size() );
    int i=1;
    while(i<str.size() ){
        if(str[0]!=str[i]){
            i++; continue;
        }
        int cnt=0;
        while(str[cnt]==str[i+cnt])
            cnt++;
        temp[i]=cnt;
        int j;
        for(j=1;j<=cnt-1;j++)
            if(temp[j]>=cnt-j) break;
            else temp[i+j]=temp[j];
        i+=j;
    }

    return temp;
}

bool z_algorithm(string substring, string pattern){
    int n=substring.size(), m=pattern.size();

    string str=pattern+'$'+substring;
    vector<int> temp=z_values(str);
    for(int i=m+1;i<=m+n;i++)
        if(temp[i]==m)
            return true;

    return false;
}

int main(){
    string substring="abcabc";
    string pattern="bca";

    bool exists=z_algorithm(substring,pattern);
    
    if(exists)
        cout<<"pattern does exists";
    else
        cout<<"pattern does not exists";

    //output: pattern does exists

    return 0;
}
