//Worst-case time complexity for Hull formation = O(n^2)

#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;
#define X first
#define Y second

vector<pii > result;

int orientation(pii a, pii b, pii c){
	int value = (b.Y-a.Y)*(c.X-b.X)-(c.Y-b.Y)*(b.X-a.X);
	if(value==0) return 0;
	else if(value>0) return 1; // right or clockwise
	else return -1;  //left or couter-clockwise
}

void convexHull(vector<pii > points){
	if(points.size()<3)
		return;
	
	int leftmost = 0;
	for(int i=1;i<points.size();i++)
		leftmost = points[leftmost].X>points[i].X ? i:leftmost;
	
	int curr=leftmost,next;		
	do{
		result.push_back(points[curr]);

		next=(curr+1)%points.size();
		for(int i=0;i<points.size();i++)
			if(orientation(points[curr], points[i], points[next])==1)
				next=i;
		curr=next;
	}while(curr!=leftmost);		
}

int main(){
	vector<pii > points;
	points.push_back(make_pair(-3,3));
	points.push_back(make_pair(-4,-3));
	points.push_back(make_pair(13,0));
	points.push_back(make_pair(1,0));

	convexHull(points);

	//print result
	for(int i=0;i<result.size();i++)
		cout<<result[i].X<<","<<result[i].Y<<endl;	
	/* output=
		 -4,-3
		 -3,3
		 13,0
	*/
}
