#include<bits/stdc++.h>
using namespace std;

void swap(int *xp,int *yp){
  int temp = *xp;
  *xp = *yp;
  *yp = temp;
}

void selectionsort(int arr[],int n){
  int j,i,min_idx;

  //One by one move boundary of unsorted subarray
  for(i=0;i<n-1;i++){
    min_idx = i;
    for(j=i+1;j<n;j++)
    if(arr[j]<arr[min_idx])
    min_idx = j;

    //Swap the found minimum element with first element
    swap(&arr[min_idx],&arr[i]);
  }
}

void printArray(int arr[],int size){
  int i;
  for(i=0;i<size;i++)
    cout<<arr[i]<<" ";
  cout<<endl;
}

int main(){
  int arr[] ={64,25,12,22,11};
  int n=sizeof(arr)/sizeof(arr[0]);
  selectionsort(arr,n);
  cout<<"Sorted array: ";
  printArray(arr,n);
  return 0;
}
