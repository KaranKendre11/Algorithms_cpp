// finding longest increasing subsequence in an array
// of n elements.
#include<bits/stdc++.h>
using namespace std;


  int main(){
    vector<int> array{6,2,5,1,7,4,8,3};
    int n = array.size();
    vector<int>length(n);
    for(int i = 0;i<n;i++){
      length[i] = 1;
    for(int j = 0;j<i;j++){
      if(array[j] < array[i]){
        length[i] = max(length[i],length[j]+1);
      }
    }
    }
    for(auto x:length) cout<<x<<",";
  }
