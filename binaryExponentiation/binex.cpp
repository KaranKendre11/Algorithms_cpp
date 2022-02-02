// Binary Exponentiation is a trick which allows to calculate a^n
// using only O(log n) multiplications instead of O(n) by the naive approach.


#include<bits/stdc++.h>
using namespace std;

long long binpow(long long a,long long b){
  if(b == 0) return 1;
  long long res = binpow(a,b/2);
  if (b % 2) return res * res * a;
  else return res * res;
}

int main(){
  long long a,b;
  cin>>a>>b;
  cout<<"Recursive: "<<binpow(a,b)<<endl;
  int result = 1;
  while(b > 0){
    if(b%2 == 1) result *= a;
    a *= a;
    b /= 2;
  }

/*
  // example :-  3^4 ---
  1. a = 9     b = 4/2 = 2  res = 1
  2. a = 81    b = 2/2 = 1 res = 1
  3. a = 81    b = 1 { b % 2 == 1} res = 1 * a = 81 last line
  result = 81


*/
  cout<<"Iterative: "<<result<<endl;
  return 0;
}
