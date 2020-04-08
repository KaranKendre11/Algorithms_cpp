#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int arr[] = {1,3,4,8,6,1,4,2};
  int n = sizeof(arr)/sizeof(arr[0]);
  int psa[n];
  for(int i = 0;i<n;i++){
    psa[i] = psa[i-1] + arr[i];
  }
  // calc sum(a,b) in O(1)
  int sum = 0;
  int a,b;
  cin>>a>>b;
  cout<<psa[b]-psa[a-1];


}
