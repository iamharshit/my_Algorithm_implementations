//Worst-case time complexity for Hull formation = O(logn)

#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
stack<pii > results;
pii p0;
#define X first
#define Y second
#define out(x) cout<<x<<endl;	
#define VECTORPRINT(_vec) {int _t=0;while(_t<_vec.size()){cout<<_vec[_t].X<<' '<<_vec[_t].Y<<' '<<endl; ++_t;} }

pii belowTop(stack<pii > v){
	v.pop();
	return v.top();
}

int dist(pii a,pii b){
	int x = a.X-b.X;
	int y = a.Y-b.Y;
	return x*x+y*y; 
}

int orientation(pii a, pii b, pii c){
	int value = (b.Y-a.Y)*(c.X-b.X)-(c.Y-b.Y)*(b.X-a.X);
	if(value==0) return 0;
	else if(value>0) return 1; // right or clockwise
	else return -1;  //left or couter-clockwise
}

bool compare(pii p1, pii p2){
	int val = (p1.Y-p0.Y)*(p2.X-p0.X) - (p2.Y-p0.Y)*(p1.X-p0.X);
	if(val==0) return dist(p0,p1)<dist(p0,p2); 
	else return val<0;
}

void convexHull(vector<pii > points){
	if(points.size()<3) return;

	int ymin = 0;
	for(int i=1;i<points.size();i++)
		ymin = points[i].Y<points[ymin].Y ? i:ymin;
	out(ymin);
	//indexing
	swap(points[0], points[ymin]); //cout<<points[0].X<<" "<<points[0].Y<<endl;
	p0=points[0];
	sort(points.begin()+1 , points.end(), compare); //cout<<points[0].X<<" "<<points[0].Y<<endl;
	VECTORPRINT(points) cout<<endl;
	//cleaning points: Keep the farthest only of same orientation
	int m=1;
	for(int i=1;i<points.size();i++){
		while(i<points.size()-1 && orientation(p0, points[i], points[i+1])==0)
			i++;
		points[m]=points[i];
		m++;
	}
	points.resize(m);		
	//VECTORPRINT(points) cout<<endl;
	if(points.size()<3) return;
		
	//push top 3 points
	results.push(points[0]);
	results.push(points[1]);	

	//for the remaining m-2 points
	for(int i=2;i<points.size();i++){		
		while(orientation(belowTop(results), results.top(), points[i])==1)
			results.pop();
		results.push(points[i]);
	}
}

int main(){
	vector<pii > points;
	points.push_back(make_pair(-3,3));
	points.push_back(make_pair(-4,-3));
	points.push_back(make_pair(13,0));
	points.push_back(make_pair(1,0));
	
	convexHull(points);

	//print result
	while(!results.empty()){
		cout<<results.top().X<<" "<<results.top().Y<<endl;
		results.pop();
	}
	/* output=
		 -4,-3
		 -3,3
		 13,0
	*/
	return 0;
}
