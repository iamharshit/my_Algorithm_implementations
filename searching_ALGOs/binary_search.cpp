#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

#define INPUT(_x) int _x;cin>>_x;
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define TCASE int _t;cin>>_t;FOR(int i,1,_t)
#define VECTORFILL(_vec) int _x;cin>>_x;while(_x!=-1){vec.push_back(_x);cin>>_x;}
#define VECTORPRINT(_vec) int _t=0;while(_t<_vec.size()){cout<<_vec[_t++]<<endl;}

int binarySearch(int a,int start,int end){       //returns the index or -1 if not found
	if (start>end) return -1;
	int mid=(start+end)/2;
	if(vec[mid]==a) return mid;
	else if(vec[mid]>a) return binarySearch(a,start,mid-1);
	else if(vec[mid]<a) return binarySearch(a,mid+1,end);
}

int main()
{
	VECTORFILL(vec);      //assuming -1 is the breaking point
	INPUT(a);
	cout<<binarySearch(a,0,vec.size()-1);
	return 0;
}
