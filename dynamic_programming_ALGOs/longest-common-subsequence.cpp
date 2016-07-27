// space complexity = O(len(s1) * len(s2))
// time complexity  = O(len(s1) * len(s2))

#include <bits/stdc++.h>
using namespace std;

vector<vector<int> > v;
int max_length;
vector<char> sequence;

void LCS(string s1,string s2){
    int l1=s1.size();
    int l2=s2.size();
    v.resize(l1+1,vector<int>(l2+1) );

    for(int i=1;i<=l1;i++)
        for(int j=1;j<=l2;j++)
            if(s1[i-1]==s2[j-1])
                v[i][j] = v[i-1][j-1]+1;
            else
                v[i][j] = max(v[i-1][j], v[i][j-1]);
    max_length=v[l1][l2];

    int i=l1,j=l2;
    while(i!=0 && j!=0){
        if(s1[i-1]==s2[j-1]){
            sequence.push_back(s1[i-1]);
            i--, j--;
            continue;
        }
        if(v[i][j]==v[i-1][j]) i--;
        else j--;
    }
}

int main(){
    string s1="abcdef";
    string s2="acbcf";

    LCS(s1,s2);

    cout<<"length of largest common subsequence: "<<max_length<<endl;
    // output: length of largest common subsequence: 4

    cout<<"largest common subsequence is: ";  // multiple possible answers
    for(int i=(int)sequence.size()-1;i>=0;i--)
        cout<<sequence[i];
    // output: largest common subsequence is: abcf

    return 0;
}
