// Using dynamic programming to solve optimal selection problem
#include<bits/stdc++.h>

using namespace std;
#define K 3
#define N 8

int total[1<<K][N];
int main(){
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int price[3][8] = {{6,9,5,2,8,9,1,6},
                  {8,2,6,2,7,5,7,2,},
                 {5,3,9,7,3,5,1,4}};
  int k = 3;
  int n = 8;
  for(int x = 0; x < k;x++)
    total[1<<x][0] = price[x][0];

  for(int d = 1;d<n;d++){
    for(int s = 0;s < (1<<k);s++){
      total[s][d] = total[s][d-1];
      for(int x = 0;x <k;x++){
        if(s&(1<<x)){
          total[s][d] = min(total[s][d],
                        total[s^(1<<x)][d-1]+price[x][d]);
        }
      }
    }
  }
  cout<<total[3][8]<<"\n";
  cout<<(1<<8)<<"\n";
  cout<<(1>>8)<<"\n";
  cout<<(256/8)<<"\n";
  int x;cin>>x;
  for(int i = 31;i >=0;i--){
    cout<<((x&(1<<i)? "1":"0"));
  }
}
