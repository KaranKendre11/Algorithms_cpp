#include <bits/stdc++.h>
using namespace std;

// A class to represent a job
class job{
public:
  char id; // Job ID
  int dead; // Deadline of job
  int profit;
};

// This function is used for sorting all jobs according to profit
bool comparision(job a, job b){
  return (a.profit > b.profit);
}

// Returns minimum number of platforms required
void printJobScheduling(job arr[], int n){

  // Sort all jobs according to decreasing order of profit
  sort(arr,arr+n,comparision);

  int result[n]; // To store result (Sequence of jobs)
  bool slot[n]; // To keep track of free time slots

  // Initialize all slots to be free
  for(int i = 0;i<n;i++)
      slot[i] = false;

  // Iterate through all given jobs
  for(int i =0;i<n;i++){
    //Find a free slot for this jobs (Note that we start)
    // from the last possible slot)
    for(int j = min(n,arr[i].dead)-1; j>=0;j--){
      cout<<"min: "<<j<<endl;
      // Free slot found
      if(slot[j] == false){
        result[j] = i; // Add this job to result
        slot[j] = true; // Make this slot occupied
        break;
      }
    }
  }
  // Print the result
  for(int i =0; i< n;i++)
    if(slot[i])
      cout<<arr[result[i]].id<<" ";
}


//Driver program
int main(){
  job arr[] = {{'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                   {'d', 1, 25}, {'e', 3, 15}};
  int n = sizeof(arr)/sizeof(arr[0]);
  cout<<"Following is the maximum profit sequence of jobs\n";
  printJobScheduling(arr,n);
  cout<<"This is arr+n: "<<arr+n<<endl;
  return 0;
}
