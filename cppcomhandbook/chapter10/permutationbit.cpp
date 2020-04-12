// x is max weoght that can be occupied by lift and n is number
// of people with k weights respectively
#include<bits/stdc++.h>

#define N 5

using namespace std;

pair<int,int> best[1<<N];
int main(){
int n = 5;
int x = 10;
pair<int,int> weight[5] = {{0,2},{1,3},{2,3},{3,5},{4,6}};
best[0] = {1,0};
for(int s = 1; s <(1<<n);s++){
best[s] = {n+1,0};
for(int p = 0;p < n;p++){
  if (s&(1<<p)) {
    auto option = best[s^(1<<p)];
    if (option.second + weight[p].second <= x){
      option.second += weight[p].second;
    }else{
      option.first++;
      option.second = weight[p].second;
    }
    best[s] = min(best[s],option);
  }
}
}
cout<<best[4].second<<"\n";
}
