#include<bits/stdc++.h>

using namespace std;

int main(){
  int val[] = {1,1,1};
  int wt[] = {1,1,1};
  int W = 3;
  int n = sizeof(val)/sizeof(val[0]);
  int K[n+1][W+1];

  // Build table K[][]
  for(int i =0;i <= n;i++){
    for(int w = 0; w <= W;w++){
      if( i == 0 || w == 0)  K[i][w] = 0;
      else if(wt[i-1] <= w)
        K[i][w] = max(val[i-1]+ K[i-1][w-wt[i-1]],K[i-1][w]);
      else
          K[i][w] = K[i-1][w];
    }
  }
  for(int i = 0 ; i <= n;i++){
    for(int j = 0; j <= W;j++)
    cout<<"["<<i<<"]"<<"["<<j<<"]"<<" : "<<K[i][j]<<endl;
  }

}
