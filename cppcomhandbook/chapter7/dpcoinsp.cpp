// METHOD 1: RECURSIVE FORMULATION
// Coins problem using dynamic programming recursively call
// mininum value between best and (x-coin)+1 if x < 0 infinity
// else if x is 0 then 0 and recursion for x > 0
#include<bits/stdc++.h>
#define INF 1000000007
using namespace std;

int solve(int x,vector<int>coins){
  if(x < 0) return INF;
  if(x == 0) return 0;
  int best = INF;
  for (auto c : coins){
    best = min(best,solve(x-c,coins)+1);
  }
  return best;
}

int main(){
  vector<int>coins{1,3,4};
  cout<<solve(10,coins);
}
