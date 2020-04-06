// METHOD 2: MEMOIZATION

#include <bits/stdc++.h>
#define INF 1000000007
#define N 100
using namespace std;


bool ready[N];
int value[N];

int solve(int x,vector<int> coins){
  if (x < 0 ) return INF;
  if (x == 0) return 0;
  if(ready[x]) return value[x];
  int best = INF;
  for (auto c : coins){
    best = min(best,solve(x-c,coins)+1);
  }
  value[x] = best;
  ready[x] = true;
  return best;
}

int main(){
  vector<int>coins{1,3,4};
  cout<<"Recursively: "<<solve(10,coins)<<endl;
  value[0] = 0;
  int n = 10;
  for(int x = 1;x <= n;x++){
    for(auto c: coins){
      if (x-c >= 0){
        value[x] = min(value[x],value[x-c]+1);
      }
    }
  }
  cout<<"Iteratively: "<<value[n]<<endl;
}
