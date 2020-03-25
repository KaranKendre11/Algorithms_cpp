//for activity selection problem.
//The following implementation assumes that the activites
//are already sorted according to their finish time.
#include<bits/stdc++.h>
using namespace std;
//Prints a maximum set of activites that can be done by a single
//person,one at a time.
// n --> Total number of activites
// s[] --> An array that contains start time of all activities
// f[] --> An array that contains finish time of all activities
void printMaxActivites(int s[],int f[],int n){
  int i,j;
  cout<<"Following activities are selected \n"<<endl;
  //The first activity always get selected
  i = 0;
  cout<<i<<" ";

  //Consider the rest of the activities
  for(j=1;j<n;j++){
    //If this activity has start time greater than
    //or equal to the finish time of previously selected
    //activity, then select it
    if(s[j]>=f[i]){
      cout<<j<<" ";
      i = j;
    }
  }
}
int main(){
  int s[] = {1, 3, 0, 5, 8, 5};
  int f[] = {2, 4, 6, 7, 9, 9};
  int n = sizeof(s)/sizeof(s[0]);
  printMaxActivites(s,f,n);
  return 0;
}

//Explanation: In start time array if element has greater or
            // equal time as finish time array print the index
            // of that element and now consider finish time
            // with new index
