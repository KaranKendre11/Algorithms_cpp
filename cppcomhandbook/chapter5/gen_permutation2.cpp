#include <bits/stdc++.h>
using namespace std;

// Method 2

int main(){
  vector<int> s1 = {1,2,3};
  int n = s1.size();
  vector<int> permutation;
  for(int i = 0;i<n ;i++){
    permutation.push_back(s1[i]);
  }
  do{
    for(auto x: permutation) cout<<x;
    cout<<endl;
  }while(next_permutation(permutation.begin(),permutation.end()));}
