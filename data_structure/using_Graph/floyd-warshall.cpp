#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define X first
#define Y second

const int MAX=1000;

class Graph{
    private:
        vector<vector<pair<int,int> > > v;
        int n;
    public:
        vector<vector<int> > distance;
        vector<vector<int> > path;

        Graph(int sz){
            n=sz;
            v.resize(n);
            distance.resize(n,vector<int>(n,MAX) );
            path.resize(n,vector<int>(n,-1) );
        }
        void addEdge(int from,int to,int weight){
            v[from].push_back(make_pair(to,weight) );
        }
        void floyd_warshall(){
            pair<int,int> ptemp;
            FOR(i,0,n-1){
                FOR(j,0,(int)v[i].size()-1 ){
                    ptemp = v[i][j];
                    distance[i][ptemp.X] = ptemp.Y;
                    path[i][ptemp.X] = i;
                }
                if(distance[i][i]>0){
                    distance[i][i]=0;
                    path[i][i]=-1;
                }
            }

            FOR(k,0,n-1)
                FOR(i,0,n-1)
                    FOR(j,0,n-1)
                        if( distance[i][j] > distance[i][k]+distance[k][j] ){

                            distance[i][j] = distance[i][k]+distance[k][j];
                            path[i][j]=k;
                        }
        }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1, 1);
    g.addEdge(0, 2, -3);
    g.addEdge(1, 2, 4);
    g.addEdge(2, 0, 3);
    g.addEdge(2, 3, 2);

    g.floyd_warshall();

    int a=1,b=3;
    // shortest path from a to b
    cout<<"length of shortest path= "<<g.distance[a][b]<<endl;  
    /* output: length of shortest path= 6 */

    // path taken from a to b
    cout<<"path taken: ";
    cout<<b<<"<-- ";
    while(g.path[a][b]!=-1 ){
        cout<<g.path[a][b]<<"<-- ";
        b=g.path[a][b];
    } 
    /* output: path taken: 3<-- 2<--1<-- */

    return 0;
}
