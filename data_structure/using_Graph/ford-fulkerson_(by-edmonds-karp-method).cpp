#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        vector<vector<int> > v;
        int n;
        int cnt=-1;
    public:
        int max_flow=0;
        vector<vector<int> > paths;
        Graph(int sz){
            n=sz;
            v.resize(n,vector<int>(n));
        }
        void addEdge(int from,int to,int weight){
            v[from][to]=weight;
        }
        void ford_fulkerson(int source,int sink){
                bool flag=true;
                while(flag){
                        flag=false;
                        vector<int> parent(n);
                        queue<int> q; q.push(source);
                        vector<bool> visited(n);  visited[source]=true;
                        int curr;
                        bool flag2=false;
                        while(!q.empty() ){
                            curr=q.front(); q.pop();
                            if(curr==sink){
                                    flag=true;
                                    cnt++;
                                    int flow_allowed=INT_MAX;
                                    int item=sink;
                                    while(item!=source){
                                        flow_allowed=min(flow_allowed,v[ parent[item] ][item] );
                                        paths.resize(cnt+1);
                                        paths[cnt].push_back(item);
                                        item=parent[item];
                                    }
                                    paths[cnt].push_back(source);
                                    max_flow+=flow_allowed;
                                    int a,b;
                                    for(int i=1;i<paths[cnt].size();i++){
                                        a=paths[cnt][i-1], b=paths[cnt][i];
                                        v[b][a]-=flow_allowed , v[a][b]+=flow_allowed;
                                    }
                                    flag2=true;
                            }
                            if(flag2) break;

                            for(int i=0;i<=n-1;i++)
                                    if(v[curr][i]>0 && !visited[i]){
                                        parent[i]=curr;
                                        visited[i]=true;
                                        q.push(i);
                                    }
                        }
                }
        }
};

int main(){
    Graph g(3);
    g.addEdge(0, 1, 3);
    g.addEdge(1, 2, 6);

    g.ford_fulkerson(0, 2);

    cout<<"max flow from source to sink is: "<<g.max_flow<<endl;
    // output: max flow from source to sink is: 3

    cout<<"flow paths are: "<<endl;  // although multiple flow paths are possible
    for(int i=0;i<g.paths.size();i++){
        for(int j=0;j<g.paths[i].size();j++)
            cout<<g.paths[i][g.paths[i].size()-1-j]<<' ';
        cout<<endl;
    }
    /* output: flow paths are:
               0 1 2
    */

    return 0;
}
