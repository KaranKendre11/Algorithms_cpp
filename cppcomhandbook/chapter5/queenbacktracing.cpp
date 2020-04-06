// Backtracing so that no 2 queen attack each other
// in a n*n chess board.
#include<bits/stdc++.h>
using namespace std;

int n = 16;
int column[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int diag1[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
int diag2[16] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

 void search(int y){
  int count = 0;
  if(y == n){
    count++;
    return;
  }
for (int x = 0;x < n;x++){
  if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
  column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
  search(y+1);
  column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
}
}

int main(){
  search(1);
}
