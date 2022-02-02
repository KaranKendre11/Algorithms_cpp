#include<bits/stdc++.h>

using namespace std;
int main(){
  int p,h,t;
  int res;
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin>>t;
  while(t--){
    cin>>h>>p;
    h = h - p;
    while(h != 0 && p != 0){
    p = abs(p /2);
    h = abs(h - p);
  }
  if(h>p){
    res = 0;
  }else{
    res = 1;
  }
  cout<<res<<"\n";
  }
}
