#include<bits/stdc++.h>
using namespace std;
//arr[] = sorted array,n = size of array,x = number to be searched
int interpolationSearch(int arr[],int n,int x){
    //Find indexes of two corners
    int lo = 0,hi = (n-1);
    //Since array is sorted ,an element present
    //in array must be in range defined by corners
    while(lo <= hi && x >= arr[lo] && x <= arr[hi]){

        if (lo == hi){
            if (arr[lo] == x) return lo;
            return -1;
        }
        // Probing the position with keeping
        // uniform distribution in mind.

        int pos = lo +(((double)(hi-lo)/(arr[hi]-arr[lo]))*(x - arr[lo]));
        cout<<pos<<"\n";
        //Condition of target found
        if(arr[pos] == x){
            return pos;
        }
        //If x is larger, x is in upper part
        if (arr[pos] < x)
            lo = pos + 1;
        // If x is smaller, x is in the lower part
        else
            hi = pos - 1;
      }
       return -1;
    }

int main(){
    int arr[] = {10, 12, 13, 16, 18, 19, 20, 21,
                 22, 23, 24, 33, 35, 42, 47};
    int n = sizeof(arr)/sizeof(arr[0]);
    int x = 18;
    int index = interpolationSearch(arr,n,x);
    if (index != -1)
    cout<<"Element Found at index "<<index;
    else
    cout<<"Element not found";
    return 0;
}
