#include <bits/stdc++.h>
using namespace std;

vector<int> vec;

void swap(int a,int b){
	int temp=vec[a];
	vec[a]=vec[b];
	vec[b]=temp;
}

void quicksort(int begin,int end){
	int pivot=end;
	int curr=begin;
	int wall=begin;

	while(curr<pivot){
		if(vec[curr]>vec[pivot]) {}  //pass
		else if(vec[curr]<vec[pivot]){
			swap(wall,curr);
			wall++;
		}
		curr++;
	}

	swap(wall,pivot);

	if(wall!=begin && begin!=wall-1 && begin!=wall-2) quicksort(begin,wall-1);
	if(wall!=end && wall+1!=end && wall+2!=end) quicksort(wall+1,end);
}

int main()
{
	int x;
	cin>>x;
	while(x!=-1){    //assuming -1 is the breaking point
		vec.push_back(x);
		cin>>x;
	}

  quicksort(0,vec.size()-1);

  return 0;
}
