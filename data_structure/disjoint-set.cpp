#include <bits/stdc++.h>
using namespace std;

class Disjoint_Set{
    private:
        vector<int> parent;
        vector<int> sizes;
    public:
        Disjoint_Set(int sz){
            parent.resize(sz);
            sizes.resize(sz,1);
            for(int i=0;i<=sz-1;++i)
                parent[i]=i;
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
        int disjoint_set_count(){
            int ct=0;
            for(int i=0;i<=(int)parent.size()-1;i++)
                if(parent[i]==i)
                    ++ct;
            return ct;
        }
};

int main(){
    Disjoint_Set d(10);
    d.unionset(1,5);
    d.unionset(2,4);
    d.unionset(3,5);

    cout << "no. of disjoint sets: " << d.disjoint_set_count() << endl;

    return 0;
}
