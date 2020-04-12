#include<bits/stdc++.h>

#define N 5
using namespace std;
int main(){
  int sum[1<<N];
  int value[5] = {1,2,3,4,5};
  int n = sizeof(value)/sizeof(value[0]);
  for(int s = 0;s < (1<<n);s++){
    sum[s] = value[s];
  }
  for(int k = 0;k < n;k++){
    for(int s = 0; s < (1<<n);s++){
      if (s&(1<<k)){
        sum[s] += sum[s ^ (1<<k)];
      }
    }
  }
  cout<<sum[1];
}
