#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define X first
#define Y second

struct compare{
    bool operator()(const pair<int,int> &left, const pair<int,int> &right) {
        return left.second < right.second;
    }
};

vector<pair<int,int> > ans_vect;
int Knapsack_0_1(vector<pair<int,int> > value_vs_weight,int sz,int total_weight){
    vector<vector<int> > T(sz+1, vector<int>(total_weight+1));

    FOR(i,1,sz)
        FOR(j,0,total_weight)
            if(j==0)
                T[i][j]=0;
            else if(value_vs_weight[i-1].Y>j)
                T[i][j]=T[i-1][j];
            else
                T[i][j]=max(value_vs_weight[i-1].X + T[i-1][j-value_vs_weight[i-1].Y] , T[i-1][j]);

    //Backtrack
    int i=sz, j=total_weight;
    while(T[i][j]!=0){
        if(T[i][j]==T[i-1][j])
            i--;
        else{
            ans_vect.push_back(value_vs_weight[i-1]);
            j-=value_vs_weight[i-1].Y;
            i--;
        }
    }

    return T[sz-1][total_weight];
}

int main(){
    int sz=4;
    int total_weight=7;
    vector<pair<int,int> > value_vs_weight(sz);

    value_vs_weight[0].X=1,value_vs_weight[0].Y=1;
    value_vs_weight[1].X=4,value_vs_weight[1].Y=3;
    value_vs_weight[2].X=5,value_vs_weight[2].Y=4;
    value_vs_weight[3].X=7,value_vs_weight[3].Y=5;

    sort(value_vs_weight.begin(), value_vs_weight.end(),compare() );

    int max_value = Knapsack_0_1(value_vs_weight, sz, total_weight);
    
    cout<<"Maximum Value : "<<max_value<<endl;
    cout<<"Weights are : ";
    FOR(i,0,ans_vect.size()-1)
        cout<<ans_vect[i].Y<<", ";

    return 0;
}
