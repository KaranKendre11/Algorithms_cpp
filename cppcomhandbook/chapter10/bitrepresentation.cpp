#include<bits/stdc++.h>

using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int x;
  cin>>x;
  for(int i = 0;i <= 3; i++){
    if(x &(1<<i)) cout<<i;
  }

}
