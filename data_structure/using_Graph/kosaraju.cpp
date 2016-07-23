#include <bits/stdc++.h>
using namespace std;

class Graph{
    private:
        vector<vector<int> > v1,v2;
        vector<bool> visited;
        int n;
    public:
        vector<vector<int> > ans;
        Graph(int sz){
            n=sz;
            v1.resize(sz);
            v2.resize(sz);
            visited.resize(sz);
        }
        void addEdge(int from,int to){
            v1[from].push_back(to);
            v2[to].push_back(from);
        }
        void explore1(int vertex,stack<int> &tmp){
            visited[vertex]=true;
            for(int i=0;i<=(int)v1[vertex].size()-1;++i)
                if(!visited[ v1[vertex][i] ])
                    explore1(v1[vertex][i],tmp);
            tmp.push(vertex);
        }
        void explore2(int vertex,vector<int> &tmp){
            visited[vertex]=true;
            for(int i=0;i<=(int)v2[vertex].size()-1;++i)
                if(!visited[ v2[vertex][i] ])
                    explore2(v2[vertex][i],tmp);
            tmp.push_back(vertex);
        }
        void kosaraju(){
            stack<int>  tmp;
            for(int i=0;i<=n-1;i++)
                if(!visited[i])
                    explore1(i,tmp);

            visited.resize(0);
            visited.resize(n);
            int curr;
            while(!tmp.empty()){
                curr=tmp.top();
                tmp.pop();
                if(visited[curr]) continue;
                vector<int> tmp2;
                explore2(curr,tmp2);
                ans.push_back(tmp2);
            }
        }
};

int main(){
    Graph g(7);
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 4);
    g.addEdge(3, 4);
    g.addEdge(4, 5);
    g.addEdge(5, 3);
    g.addEdge(5, 6);

    g.kosaraju();

    cout<<"no. of strongly connected component: "<<g.ans.size()<<endl;
    // output: no. of strongly connected component: 3     
    
    cout<<"nodes in each component: "<<endl;
    for(int i=0;i<=(int)g.ans.size()-1;i++){
        vector<int>::iterator it;
        for(it=g.ans[i].begin();it!=g.ans[i].end();++it)
            cout<<*it<<" ";
        cout<<endl;
    }
    /* output: nodes in each component: 
                1 2 0
                5 3 4
                6
    */

    return 0;
}
