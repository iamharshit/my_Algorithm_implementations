#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

struct edge{
    int a,b;
};

class Graph{
    private:
        vector<vector<pair<int,int> > > v;
        vector<bool> visited;
        int n;
    public:
        int total_weight=0;
        vector<pair<edge,int> > mst;
        Graph(int sz){
            n=sz;
            v.resize(n);
        }
        void addEdge(int from,int to,int weight){
            v[from].push_back( {to,weight} );
            v[to].push_back( {from,weight} );
        }
        void prims(){
            visited.resize(n);
            vector<int> d(n,INT_MAX);
            d[0]=0;
            vector<edge> corresponding_edge(n);
            set<pair<int,int> > st;
            for(int i=0;i<=n-1;i++)
                st.insert( {d[i],i} );

            pair<int,int> curr;
            while(!st.empty() ){
                curr=*st.begin();
                st.erase(st.begin() );
                visited[curr.Y]=true;
                total_weight += curr.X;
                mst.push_back( {corresponding_edge[curr.Y],curr.X} );
                for(int i=0;i<=(int)v[curr.Y].size()-1;i++)
                    if(!visited[ v[curr.Y][i].X ] && d[ v[curr.Y][i].X ] > v[curr.Y][i].Y){
                        st.erase( st.find( { d[ v[curr.Y][i].X ],v[curr.Y][i].X } ) );
                        d[ v[curr.Y][i].X ] = v[curr.Y][i].Y;
                        st.insert( { d[ v[curr.Y][i].X ],v[curr.Y][i].X } );
                        corresponding_edge[ v[curr.Y][i].X ] = { curr.Y,v[curr.Y][i].X };
                    }
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(1, 2, 1);
    g.addEdge(1, 3, 3);
    g.addEdge(2, 3, 4);
    g.addEdge(0, 3, 1);

    g.prims();

    cout<<"total weight of mst: "<<g.total_weight<<endl;
    // output: total weight of mst: 3

    cout<<"edges of mst: "<<endl;
    for(int i=1;i<=(int)g.mst.size()-1;++i)
        cout<<g.mst[i].X.a<<" "<<g.mst[i].X.b<<" "<<g.mst[i].Y<<endl;
    /* output: edges of mst:
               0 1 1
               1 2 1
               0 3 1
    */

    return 0;
}
