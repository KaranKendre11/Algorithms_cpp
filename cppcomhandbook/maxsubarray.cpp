#include <bits/stdc++.h>
using namespace std;

// Algorithm 1:
/* A straight forward way to solve the problem is to go through
all possible subarrays, calculate the sum of values in each
subarray and maintain the maximum sum.
The follwoing code implements the algorithm */

int main(){
  int best = 0;
  int n = 8;
  int array[n] = {-1,2,4,-3,5,2,-5,2};
  for (int a = 0; a < n; a++){
    for(int b = a; b < n; b++){
      int sum = 0;
      for (int k = a; k<= b; k++){
        sum += array[k];
      }
      best = max(best,sum);
    }
  }
  cout<<best<<endl;
}

// Algorithm 2:
/* It is easy to make Algorithm 1 more efficient by removing one loop from it
This is possible by calculating the sum at the same time when the right end
of the subarray moves.The result is the following code: */

int main(){
  int best = 0;
  for(int a = 0;a<n;a++){
    int sum = 0;
    for(int b = a;b<n;b++){
      sum += array[b];
      best = max(best,sum);
    }
  }
  cout<< best<<"\n";
}

// Algorithm 3:
/* it is possible to solve the problem in O(n) time. Which means that
just one loop is enough. The idea is to calculate, for each array
position, the maximum sum of subarray that ends at that position*/

int main(){
  int best = 0,sum = 0;
  for (int k = 0; k < n;k++){
    sum = max(array[k],sum+array[k]);
    best = max(best,sum);
  }
  cout<<best<<"\n";
}
