// graph representation using adjacency list

#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        vector<vector<int> > v;
        vector<bool> status;
    public:
        Graph(int sz){
            v.resize(sz);

            status.resize(sz);
            for(int i=0;i<sz;i++)
                status[i]=false;
        }
        void addEdge(int from,int to){
            v[from].push_back(to);
        }
        void dfs_iterative(int vertex){
            stack<int> stk;
            stk.push(vertex);
            int curr;
            while(!stk.empty()){
                curr=stk.top();
                stk.pop();
                if(status[curr]) continue;
                status[curr]=true;
                cout<<curr<<"-->";
                for(int i=0;i<=(int)v[curr].size()-1;i++)
                    stk.push(v[curr][i]);
            }
        }
};

int main()
{
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    g.dfs_iterative(2);
    // prints 2-->3-->0-->1-->

    return 0;
}
