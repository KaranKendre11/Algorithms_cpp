#include<bits/stdc++.h>
#define MAX 100
using namespace std;

// Method 1

vector<int> s1 = {1,2,3,4};
int n = s1.size();
vector<int> permutation;
int chosen[MAX];
void search(){
  if (permutation.size() == n){
    for(auto x: permutation) cout<<x;
    cout<<endl;
  }else{
    for (int i = 0;i<n;i++){
      if(chosen[i]) continue;
      chosen[i] = true;
      permutation.push_back(s1[i]);
      search();
      chosen[i] = false;
      permutation.pop_back();
    }
  }
}
int main(){
  search();
}
