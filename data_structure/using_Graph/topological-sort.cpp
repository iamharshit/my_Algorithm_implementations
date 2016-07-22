#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        vector<vector<int> > v;
        vector<bool> visited;
        int n;
    public:
        stack<int> stk;
        Graph(int sz){
            n=sz;
            v.resize(n);
            visited.resize(n,false);
        }
        void addEdge(int from,int to){
            v[from].push_back(to);
        }
        void explore(int vertex){
            visited[vertex]=true;
            for(int i=0;i<=(int)v[vertex].size()-1;++i){
                if(visited[ v[vertex][i] ]) continue;
                explore(v[vertex][i]);
            }
            stk.push(vertex);
        }
        void topological_sort(){
            for(int i=0;i<=n-1;++i){
                if(visited[i]) continue;
                explore(i);
                if(stk.size()==n) return;
            }
        }
};

int main(){
    Graph g(4);
    g.addEdge(0, 2);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(1, 3);

    g.topological_sort();
    while(!g.stk.empty()){
        cout << g.stk.top() << " ";
        g.stk.pop();
    }
    // ouputs : 0 1 3 2

    return 0;
}
