#include<bits/stdc++.h>
#include<vector>

#define N  5

using namespace std;

int main(){

// Directed graph representation using adjacency list
//  1 -> 2 -> 3
//   ↑   ↓   ↓
//       4
cout<<"\n";
cout<<"Directed Unweighted Graph: \n";
vector<int> adj[N];
adj[1].push_back(2);
adj[2].push_back(3);
adj[2].push_back(4);
adj[3].push_back(4);
adj[4].push_back(1);

for(int i = 1;i < 5;i++){
  for(auto c:adj[i]){
    cout<<c<<" , ";
  }cout<<"\n";
}

// if the gragh is undirected  it can be stored in
// similar way,but each edge is added in both directions

// Weighted graph using adjacency list
cout<<"\n";
cout<<" Directed Weighted Graph: \n";

vector<pair<int,int>> wadj[N];
wadj[1].push_back(make_pair(2,5));
wadj[2].push_back(make_pair(3,7));
wadj[2].push_back(make_pair(4,6));
wadj[3].push_back(make_pair(4,5));
wadj[4].push_back(make_pair(1,2));

for(int i = 1;i < 5;i++){
  for(auto c:wadj[i]){
    cout<<c.first<<" : "<<c.second<<" , ";
  }cout<<"\n";
}
}
