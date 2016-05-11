// in c++ we can directly do `__gcd(a,b)` for finding gcd of a,b

#include <bits/stdc++.h>
using namespace std;

int gcd(int x,int y){
	if(y%x==0) return x;
    else return gcd(y%x,x);
}

int main()
{
	int a; cin>>a;
	int b; cin>>b;

	int big,small;
	big=(a>b)?a:b;
	small=(a>b)?b:a;

	int the_gcd=gcd(big,small);
	
	return 0;
}
