#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

int modulo(int a,int b,int c){
  int res=1,base=a;
  while(b>0){
      if(b%2==1)
          res = (res*base)%c;
      base = (base*base)%c;
      b/=2;
  }
  return res;
}

bool isPrime(int p, int iterations){
  if(p==1)
      return false;
  if(p==2 || p==3 || p==5 || p==7)
      return true;
  if(p%2==0 || p%3==0 || p%5==0 || p%7==0)
      return false;
  FOR(i,1,iterations){
        int a = rand()%(p-1) + 1;
        if(modulo(a,p-1,p)!=1)
            return false;
  }
  return true;
}

int main(){
  int p=19;
  int iterations=5;

  if(isPrime(p,iterations) )
      cout<< p << " is prime";
  else
      cout<< p << " is not prime";

  return 0;
}
