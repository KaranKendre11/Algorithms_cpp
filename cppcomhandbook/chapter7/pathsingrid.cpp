// find a path from the upper-left corner to the lower-right corner
// of an n x n grid, such that we only move down and right.

#include<bits/stdc++.h>

using namespace std;

int sum(int x,int y){

}


int main(){
// int sum[5][5] = {{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}};
int n = 5;
 vector<vector<int>> value{{3,7,9,2,7},{9,8,3,5,5},{1,7,9,8,5},{3,8,6,4,10},{6,3,9,7,8}};
 int sum;
for(int y = 1;y <= 4;y++){
  for(int x=1;x <= 4;x++){
    value[y][x] += max(value[y][x-1],value[y-1][x]);
    sum = value[y][x]+value[0][0];
  }
}
cout<<sum;
}
