#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        vector<vector<int> > v;
        vector<bool> visited;

    public:
        Graph(int sz){
            v.resize(sz);

            visited.resize(sz);
            for(int i=0;i<sz;++i)
                visited[i]=false;
        }
        void addEdge(int from,int to){
            v[from].push_back(to);
        }
        void bfs(int vertex){
            queue<int> q;
            q.push(vertex);
            visited[vertex]=true;

            while(!q.empty() ){
                int temp=q.front();
                cout<<q.front()<<"-->";
                q.pop();

                vector<int>::iterator i;
                for(i=v[temp].begin();i!=v[temp].end();++i)
                    if(visited[*i]==false)
                    {
                        q.push(*i);
                        visited[*i]=true;
                    }
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

    g.bfs(2);
    //outputs 2-->0-->3-->1-->

    return 0;
}
