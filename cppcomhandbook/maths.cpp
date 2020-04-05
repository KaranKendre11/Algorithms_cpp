#include<bits/stdc++.h>
#include<cmath>
using namespace std;
int main(){
  int n = 2;
  int count = 0;
  for(int i = 1;i<=n;i++){
    count += pow(i,2);
  }
  cout<<"count: "<<count<<endl;
  int ans = (n*(n+1)*(2*n+1))/6;
  cout<<ans<<endl;
}
