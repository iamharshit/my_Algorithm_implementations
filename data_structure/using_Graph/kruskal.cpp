#include <bits/stdc++.h>
using namespace std;

struct edge{
    int weight,node1,node2;
};

bool compare(edge e1,edge e2){
    return e1.weight<e2.weight;
}

class Graph{
    private:
        vector<edge> v;
        int n;
        vector<int> parent;
        vector<int> sizes;
    public:
        int total_weight;
        vector<edge> mst;
        Graph(int sz){
            n=sz;
        }

        void addEdge(int _node1,int _node2,int _weight){
            v.push_back( {_weight,_node1,_node2} );
        }

        int root(int node){
            while(node!=parent[node]){
                parent[node]=parent[parent[node]];
                node=parent[node];
            }
            return node;
        }

        void unionset(int _node1,int _node2){
            int root1=root(_node1);
            int root2=root(_node2);
            if(sizes[root1]>sizes[root2]){
                parent[root2]=root1;
                sizes[root2]+=sizes[root1];
            }
            else{
                parent[root1]=root2;
                sizes[root2]+=sizes[root1];
            }
        }

        bool findset(int _node1,int _node2){
            return root(_node1)==root(_node2) ? true : false;
        }

        void kruskal(){
            parent.resize(n);
            sizes.resize(n);
            for(int i=0;i<=n-1;++i){
                parent[i]=i;
                sizes[i]=1;
            }

            sort(v.begin(), v.end(), compare);
            total_weight = 0;

            edge curr;
            for(int i=0;i<=(int)v.size()-1;++i){
                curr = v[i];
                if(findset(curr.node1,curr.node2)) continue;
                unionset(curr.node1,curr.node2);
                total_weight +=curr.weight;
                mst.push_back( {curr.weight, curr.node1, curr.node2} );
                if(mst.size()==n-1) return;
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

    g.kruskal();
    cout<<"total weight of mst: "<<g.total_weight<<endl;
    // output: total weight of mst: 3

    cout<<"edges of mst: "<<endl;
    for(int i=0;i<=(int)g.mst.size()-1;++i)
        cout<<g.mst[i].node1<<" "<<g.mst[i].node2<<" "<<g.mst[i].weight<<endl;
    /* output: edges of mst:
               0 1 1
               1 2 1
               0 3 1
    */
    
    return 0;
}
