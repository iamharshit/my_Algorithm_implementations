// graph representation using adjacency list

#include <bits/stdc++.h>
using namespace std;
int countt=1;
vector<int> flag;

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
			//cout<<vertex<<"-->";
			status[vertex]=true;

			vector<int>::iterator i;
			for(i=v[vertex].begin();i!=v[vertex].end();++i)
				if(status[*i]==false){
					dfs(*i);
					flag[*i] = countt;
				}
		}
};

int main(){
    int n;
    cout<<"No. of elements: ";cin>>n;
    Graph g(n);
    
    //take adjacency list
    /*
    g.addEdge(0, 1);
    g.addEdge(1, 2);
    g.addEdge(2, 3);
    g.addEdge(3, 5);
    g.addEdge(5, 1);

    g.addEdge(3, 6);*/

    int x;
    int a[n][n];    
    for(int i=0;i<n;i++)
	for(int j=0;j<n;j++)
 		a[i][j]=0;	
	
    cout<<"Enter adjacency matrix: "<<endl;
    for(int i=0;i<n;i++){
	for(int j=0;j<n;j++)
		cin>>a[i][j];
	cout<<endl;
    }			
 
    for(int i=0;i<n;i++)
	for(int j=i;j<n;j++)
		if(a[i][j]!=0)
			g.addEdge(i, j);

    flag.resize(n);
    for(int i=0;i<n;i++)
	if(flag[i]==0){
    	    g.dfs(i);
	    countt++;
	}

    cout<<"No. of subgraphs= "<<countt-1<<endl;

    return 0;
}
