// BFS for undirected graph

#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)
#define nFOR(_i,_a,_b) for(int _i=_a;_i>=_b;_i--)
#define ARR_SIZE(_arr) sizeof(_arr)/sizeof(_arr[0])

//----------------Queue----------------------------
struct queue_ds{
	int front;
	int rear;
	int item[100];
};
void en_queue(queue_ds *q, int x){
	q->item[q->rear] = x;
	q->rear++;
}
void print_queue(queue_ds *q){
	if(q->rear>=100){
		cout<<"Overflow has occured"<<endl;
		return;
	}
	for(int i=q->front;i<q->rear;i++)
		cout<<q->item[i]<<" ";
	cout<<endl;
}
int empty(queue_ds *q){
	if(q->rear==q->front) return 1;
	else return 0;
}
void de_queue(queue_ds *q){
	if(empty(q)){
		cout<<"Underflow has occured"<<endl;
		return;
	}
	//cout<<"Dequeued Element="<<q->item[q->front]<<endl;
	q->front++;
}
//--------------------------------------------------

class Graph{
     public:
	int sz;
	vector<vector<int> > vec; 
	vector<int> visited;
	Graph(int n){
		sz=n;
		vec.resize(sz, vector<int>(sz));
		visited.resize(sz);
		FOR(i,0,sz-1)
			visited[i]=0;
	}
	void addEdge(int from,int to){
		vec[from].push_back(to);
		vec[to].push_back(from);
	}
	void bfs(int x){
		queue_ds *myqueue = new queue_ds;
		myqueue->front=0;   myqueue->rear=0;
		
		en_queue(myqueue,x);
		while(!empty(myqueue)){
			int temp=myqueue->item[myqueue->front];
			visited[temp]=1;
			cout<<temp<<"-->";
			de_queue(myqueue);

			vector<int>::iterator i;
			for(i=vec[temp].begin();i!=vec[temp].end();++i)
				if(visited[*i]==0)
				{
					en_queue(myqueue,*i);
					visited[*i]=1;
				}	
		}
		cout<<endl;		
	}
};

int main(){
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(0, 2);
	g.addEdge(1, 2);
	g.addEdge(2, 0);
	g.addEdge(2, 3);
	g.addEdge(3, 3);

	g.bfs(2);
	
	return 0;
}
