#include <bits/stdc++.h>
using namespace std;

// Method 2: using exploitation of bit representation of integers

int main(){
  vector <int> S = {0,1,2};
  int n = S.size();
  for(int b = 0; b < (1<<n); b++){
    // process subset
  }
  for(int b = 0; b < (1<<n); b++){
    vector<int>subset;
    for(int i = 0;i<n;i++){
      if (b&(1<<i)) subset.push_back(S[i]);
    }
    for (auto x:subset) cout<<x;
    cout<<endl;
  }
}
