// Knapsack problem using dp set of objects is given,
// need to find subset with some properties
// list of weights is given find sum of possible
// constructed weights
#include<bits/stdc++.h>

using namespace std;
#define N 15
int main(){
  int possible[13];
  possible[0] = true;
  int weights[4] = {1,3,3,5};
  int n = 4;
  int W = 12;
  for(int k = 1;k<=n;k++){
    for(int x = W; x >= 0; x--){
      if(possible[x]) {
        possible[x+weights[k]] = true;
        cout<<x<<":"<<possible[x]<<" | "<<weights[k]<<endl;
      }
    }
  }
}
