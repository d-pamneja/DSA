# include <iostream>
# include <vector>

using namespace std;

int BinarySearch(int arr[],int s, int e, int target){
  int start = s;
  int end = e;
  int mid = start + ((end-start)/2);
  
  while(start<=end){
    if(arr[mid]==target){
        return mid;
    }

    else if(arr[mid]>target){
      end = mid -1;
    }

    else if(arr[mid]<target){
      start = mid + 1;
    }

    mid = start + ((end-start)/2);

  }
  return -1;
}

int expSearch(int arr[],int n,int target){
    int i = 0;
    int n = sizeof(arr)/sizeof(arr[0]);
    if(arr[i]==target){ //If element lies at 0th index, return it
        return i;
    }
    i+=1; // Increment i by 1, as we have to multiply agge
    while(i<n && arr[i]<=target){
        i *= 2; // Multiply i by 2
        // With this, you will stop at an index, where arr[index/2]<=target but arr[index]>target
        // This gives you a clear range, i.e. in this subbarray, you will definitely find your target
    }
    int ans = BinarySearch(arr,i/2,min(i,n-1),target); //min(i,n-1) is chosen because there can be a case where i>n, and since we can only search in (n-1) indexes, we cap it
    cout<<"Index at which target is found is : "<<ans<<endl;
}