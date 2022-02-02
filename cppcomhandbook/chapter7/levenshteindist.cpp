// Levenshtein distance or edit distance is the minimum
// number of editing operations needed to transform a
// string into another string.
#include<bits/stdc++.h>

using namespace std;

int min(int x,int y,int z){
  return  min(min(x,y),z);
}

int main(){
  string str1 = "FIRSTSTR";
  string str2 = "SECONDSTR";

  int len1 = str1.length();
  int len2 = str2.length();

  int DP[2][len1+1];
  memset(DP,0,sizeof(DP));

  for(int i =0;i <= len1;i++)
    DP[0][i] = i;

    for(int i = 0;i<2;i++){
      for(int j = 0;j<5;j++) cout<<i<<","<<j<<" : "<<DP[i][j]<<endl;
    }

    for(int i = 1;i <= len2;i++){
      for(int j = 0;j <= len1;j++){
        if(j == 0)
         DP[i % 2][j] = i;

        else if(str1[j-1] == str2[i - 1]){
          DP[i % 2][j] = DP[(i-1) % 2][j-1];

        }else{
          DP[i % 2][j] = 1 + min(DP[(i-1) % 2][j],
                                min(DP[i%2][j-1],
                                DP[(i - 1) % 2][j -1 ]));
        }
        }
      }
      cout<<DP[len2 % 2][len1]<<endl;

      for(int i = 0;i<2;i++){
        for(int j = 0;j<5;j++) cout<<i<<","<<j<<" : "<<DP[i][j]<<endl;
      }
    }
