#include <iostream>
using namespace std;

// Q1) Check Sorted Array via Recursion
bool checksorted(int arr[], int size, int index){
  if(index>=size){
    return true;
  }

  if(arr[index]<arr[index-1]){
    return false;
  }

  checksorted(arr,size,index+1);
}

// Q2) Maximise Cuts GFG
int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        if(n==0){
            return 0;
        }
        if(n<0){
            return INT_MIN;
        }
           
        
        int option1 = 1 + maximizeTheCuts(n-x,x,y,z);
        int option2 = 1 + maximizeTheCuts(n-y,x,y,z);
        int option3 = 1 + maximizeTheCuts(n-z,x,y,z);
        
        return max(option1,max(option2,option3));
        
    }

int main() {
  int arr[5] = {1,2,3,4,5};
  int size = 5;
  int index = 1;
  
  cout<<checksorted(arr,size,index);
  return 0;
}