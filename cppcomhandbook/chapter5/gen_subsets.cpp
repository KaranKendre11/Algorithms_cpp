#include<bits/stdc++.h>

using namespace std;
// Method 1: using recursive search

void search(vector<int>s1,int k,int n,vector<int> subs){
  if(k == n){
    for(auto x: subs) cout<<x;
    cout<<endl;

  }else{

    search(s1,k+1,n,subs);
    subs.push_back(k);
    search(s1,k+1,n,subs);
    subs.pop_back();
  }
}

int main(){
  vector<int> s1 = {1,2,3,4,5};
  vector<int> subset;
  int n = s1.size();
  search(s1,0,n,subset);
}
