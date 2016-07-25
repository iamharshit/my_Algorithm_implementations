#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

class Graph{
    private:
        vector<vector<int> > v;
        vector<bool> visited;
        vector<int> parent,child;
        int timee=0;
        vector<pair<int,int> > t;
    public:
        int n;
        int total_articulation_points;
        vector<int> is_point;
        Graph(int sz){
            n=sz;
            v.resize(n);
        }
        void addEdge(int from,int to){
            v[from].push_back(to);
            v[to].push_back(from);
        }
        void explore(int source){
            visited[source]=true;
            t[source].X=t[source].Y=++timee;
            int curr;
            for(int i=0;i<=(int)v[source].size()-1;i++){
                curr=v[source][i];
                if(curr==parent[source]) continue;
                if(!visited[curr]){
                    ++child[source];
                    parent[curr]=source;
                    explore(curr);
                    t[source].Y=min(t[source].Y,t[curr].Y);
                    if(t[source].X <= t[curr].Y)
                        is_point[source]=true;
                }
                else
                    t[source].Y=min(t[source].Y,t[curr].X);
            }
        }
        void articulation_points(int source){
            visited.resize(n), is_point.resize(n) , parent.resize(n) , child.resize(n) , t.resize(n);
            explore(source);

            total_articulation_points=0;
            is_point[source]=(child[source]>1? 1:0);
            for(int i=0;i<=n-1;++i)
                if(is_point[i])
                    total_articulation_points++;
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);

    g.articulation_points(0);
    cout<<"no. of articulation points: "<<g.total_articulation_points<<endl;
    // output: no. of articulation points: 2

    cout<<"ariculation points are: ";
    for(int i=0;i<=g.n-1;++i)
        if(g.is_point[i])
            cout<<i<<" ";
    // output: ariculation points are: 1 2

    return 0;
}
