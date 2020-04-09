#include<bits/stdc++.h>

using namespace std;

const int kMaxN = 1e5+5;
int order[kMaxN];
vector<int> vertex[kMaxN];
bool visited[kMaxN];
vector<int> df_order;

void df(int node){
  df_order.push_back(node);
  visited[node] = true;
  for(auto itr: vertex[node]){
    if(! visited[itr]){
      df(itr);
    }
  }
}

int main(){
  int n,m; cin>>n>>m;
  vector<int> permutation(n);
  for(int i = 0;i < n;i++){
    int x;cin>>x;
    permutation[i] = x;
    order[x] = i;
  }

  for(int i = 0 ;i<m;i++){
    int a,b; cin>>a>>b;
    vertex[a].push_back(b);
    vertex[b].push_back(a);
  }

  for(int i = 1; i <= n; i++){
    sort(vertex[i].begin(),vertex[i].end(), [&](int a,int b){
      return order[a] < order[b];
    });
  }
  df(1);

  cout<<(permutation == df_order) <<"\n";

}
