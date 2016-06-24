#include <bits/stdc++.h>
using namespace std;

#define FOR(_i,_a,_b) for(int _i=_a;_i<=_b;_i++)

typedef long long int lli;

lli modulo(lli a,lli b,lli c){
  lli res=1,base=a;
  while(b>0){
      if(b%2==1)
          res = (res*base)%c;
      base = (base*base)%c;
      b/=2;
  }
  return res;
}

lli modmul(lli a,lli b,lli c){
  lli res=0;
  a%=c;
  while(b>0){
      if(b%2==1)
          res = (res+a)%c;
      a=(a*2)%c;
      b/=2;
  }
  return res;
}

lli arr[]={2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

bool isPrime(lli p, int iteration){
  if(p<2)
      return false;
  FOR(i,0,24)
     if(p==arr[i])
        return true;
     else if(p%arr[i]==0)
        return false;

  lli s=p-1;
  while(s%2==0)
      s/=2;
  FOR(i,1,iteration){
      lli a = rand()%(p-1) + 1;
      lli temp=s;
      lli mod=modulo(a,temp,p);
      while(temp!=p-1 && mod!=1 && mod!=p-1){
          mod=modmul(mod,mod,p);
          temp*=2;
      }
      if(mod!=p-1 && temp%2==0) return false;
  }
  return true;
}

int main(){
  lli p=211;
  int iterations=5;

  if(isPrime(p,iterations) )
      cout<< p << " is prime";
  else
      cout<< p << " is not prime";

  return 0;
}
