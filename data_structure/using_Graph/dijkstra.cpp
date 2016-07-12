#include<bits/stdc++.h>
using namespace std;

#define mp make_pair
#define FOR(i,a,b) for(int i=a;i<=b;++i)

typedef vector<int> vi;
typedef vector<pair<int,int> > vpii;

class Graph{
    private:
        vector<vector<pair<int,int> > > v;
        int sz;
    public:
        vi path;
        Graph(int sizee){
            sz=sizee;
            v.resize(sz);
            path.resize(sz);
        }
        void addEdge(int from,int to,int wt){
            v[from].push_back(mp(to,wt));
            v[to].push_back(mp(from,wt));
        }
        vi dijkstra(int source){
            vi distance(sz,INT_MAX);
            set<pair<int,int> > st;
            vector<pair<int,int> >::iterator it;
            distance[source]=0;
            path[source]=source;
            st.insert( {0,source} );
            int curr_node,curr_dis;
            while(!st.empty() ){
                curr_node = st.begin()->second;
                curr_dis = st.begin()->first;
                distance[curr_node] = curr_dis;
                st.erase( {curr_dis,curr_node} );
                for(it=v[curr_node].begin();it!=v[curr_node].end();it++)
                    if(distance[it->first] > curr_dis + it->second)
                    {
                        st.erase( {distance[it->first], it->first} );
                        distance[it->first] = curr_dis + it->second;
                        path[it->first]=curr_node;
                        st.insert( {distance[it->first], it->first} );
                    }
            }
            return distance;
        }
};

void path_print(vi arr,int x){
    cout<<x;
    while(arr[x]!=x){
        cout<<" <-- "<<arr[x];
        x=arr[x];
    }
    cout<<endl;
}

void f(vi arr){
    cout<<arr[2]<<endl;
}

int main(){
    int sz=3;
    Graph g(sz);
    g.addEdge(0,1,1);
    g.addEdge(1,2,2);
    g.addEdge(0,2,7);

    vi dis;
    dis=g.dijkstra(0);
    for(int i=0;i<sz;++i){
      cout<<"node no.= "<<i<<endl;
      cout<<"dist. from source= "<<dis[i]<<endl;
      cout<<"path from source= ";
      path_print(g.path,i);
      cout<<endl;
    }

/*
OUTPUT:
node no.= 0
dist. from source= 0
path from source= 0

node no.= 1
dist. from source= 1
path from source= 1 <-- 0

node no.= 2
dist. from source= 3
path from source= 2 <-- 1 <-- 0

*/

return 0;
}
