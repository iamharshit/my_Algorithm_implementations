#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second
string STR(int _a){stringstream ss; ss<<_a; return ss.str();}

int sz;
vector<pair<int,int> > v;
int min_cost;
vector<vector<int> > path;

void matrix_chain_multiplication(){
    path.resize(sz,vector<int>(sz) );
    for(int i=0;i<=sz-1;i++) path[i][i]=i;

    vector<vector<int> > tmp(sz,vector<int>(sz) );
    int mini, cost;
    for(int gap=1; gap<=sz-1; gap++)
        for(int i=0; i<=sz-1-gap; i++){
                int j=i+gap;
                mini=INT_MAX;
                for(int k=i; k<=j-1; k++){
                    cost=tmp[i][k]+tmp[k+1][j]+v[i].X*v[k].Y*v[j].Y;
                    if(mini>cost)
                        mini=cost, path[i][j]=k;
                }
                tmp[i][j]=mini;
        }

    min_cost=tmp[0][sz-1];
}

string path_trace(int i,int j){
    if(i==j) return STR(i);
    return "(" +path_trace(i,path[i][j]) +")*(" +path_trace(path[i][j]+1,j) +")";
}

int main(){
    sz=4;
    v.push_back( {2,3} );
    v.push_back( {3,6} );
    v.push_back( {6,4} );
    v.push_back( {4,5} );

    matrix_chain_multiplication();

    cout<<"minimum cost of multipling matrices is: "<<min_cost<<endl;
    // output: minimum cost of multipling matrices is: 124

    cout<<"order of multiplication is: ";
    cout<<path_trace(0,sz-1);
    // output: order of multiplication is: (((0)*(1))*(2))*(3)

    return 0;
}
