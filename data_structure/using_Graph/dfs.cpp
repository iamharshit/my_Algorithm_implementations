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
		void dfs(int vertex){
			cout<<vertex<<"-->";
			status[vertex]=true;

			vector<int>::iterator i;
			for(i=v[vertex].begin();i!=v[vertex].end();++i)
				if(status[*i]==false)
					dfs(*i);
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

    g.dfs(2);
    // prints 2-->0-->1-->3-->

    return 0;
}
