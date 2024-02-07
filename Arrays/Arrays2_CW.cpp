# include <iostream>
# include <stdio.h>
# include <stdlib.h>

using namespace std;



void sort01(int arr[], int n){
      int i = 0;
      int j = n-1;
      while(i<j){
        if(arr[i]==0){
          i++;
        }
        else if (arr[j]==1)
        {
          j--;
        }

        else if(arr[i]==1 && arr[j]==0){
          swap(arr[i],arr[j]);
        }
      }
}

void shiftRight(int arr[],int n){
  int temp = arr[n-1];


  for(int i=(n-1);i>=0;i--){
    arr[i] = arr[i-1];
  }

  arr[0] = temp;
}

void shiftLeft(int arr[],int n){
  int temp = arr[0];

  for(int i=0;i<n;i++){
    arr[i] = arr[i+1];
  }

  arr[n-1] = temp;
}

void shiftRightby2(int arr[],int n){
  int temp1 = arr[n-2];
  int temp2 = arr[n-1];


  for(int i=(n-1);i>=0;i--){
    arr[i] = arr[i-2];
  }

  arr[0] = temp1;
  arr[1] = temp2;
}

void printArray(int arr[],int n){
  for(int i=0;i<n;i++){
    cout<<arr[i]<<" ";
  }
}

int main() {
  int arr[4] = {10,20,30,40};
  int n=4;


//   // Printing all Pairs
//   cout<<"Printing all pairs : "<<endl;
//   for(int i=0;i<n;i++){
//     for(int j=0;j<n;j++){
//       cout<<arr[i]<<" "<<arr[j]<<endl;
//     }
//   }

//   // Printing all Unique Pairs i.e. no repetition of values
//   cout<<"Printing all unique pairs : "<<endl;
//   for(int i=0;i<n;i++){
//     for(int j=i;j<n;j++){
//       cout<<arr[i]<<" "<<arr[j]<<endl;
//     }
//   }

//   // Printing all pairs where first element index is less than equal to n/2
//   cout<<"Printing all pairs where first element index is less than equal to n/2 : "<<endl;
//   for(int i=0;i<n/2;i++){
//     for(int j=i;j<n;j++){
//       cout<<arr[i]<<" "<<arr[j]<<endl;
//     }
//   }

// // Printing all unique pairs where first and second element index is less than n/2. This will have the same effect if we keep it in the outer loop as well
//     cout<<"Printing all unique pairs where first and second element index is less than n/2: "<<endl;
//     for(int i=0;i<n;i++){
//         for(int j=i;j<n/2;j++){
//         cout<<arr[i]<<" "<<arr[j]<<endl;
//         }
//     }

//  // Printing all Triplets
//     int brr[3] = {1,2,3};
//     int size = 3;

//     for(int i=0;i<size;i++){
//         for(int j=0;j<size;j++){
//             for(int k=0;k<size;k++){
//                 cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
//             }
//         }
//     }

//  // Printing all Unique Triplets
//     int brr[3] = {1,2,3};
//     int size = 3;

//     for(int i=0;i<size;i++){
//         for(int j=i;j<size;j++){
//             for(int k=j;k<size;k++){
//                 cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
//             }
//         }
//     }
    
  // // Sort 0s and 1s
  // int arr[20] = {0,1,0,1,0,1,0,1,0,1,1,0,1,0,0,1,0,1,0,1};

  // sort01(arr,20);
  // printArray(arr,20);

  // // Shift Index by 1 to the right

  // int arr[6] = {10,20,30,40,50,60};
  // int n = 6;
  
  // cout<<"Original Array : ";
  
  // printArray(arr,6);
  // cout<<endl;

  // shiftRight(arr,6);

  // cout<<"Shifted Array : ";
  // printArray(arr,6);

  // // Shift Index by 2 to the right

  // int arr[6] = {10,20,30,40,50,60};
  // int n = 6;

  // cout<<"Original Array : ";

  // printArray(arr,6);
  // cout<<endl;

  // shiftRightby2(arr,6);

  // cout<<"Shifted Array : ";
  // printArray(arr,6);

  // // Shift Index by 1 to the left

  // int arr[6] = {10,20,30,40,50,60};
  // int n = 6;
  
  // cout<<"Original Array : ";
  
  // printArray(arr,6);
  // cout<<endl;

  // shiftLeft(arr,6);

  // cout<<"Shifted Array : ";
  // printArray(arr,6);
  
  
  return 0;
}