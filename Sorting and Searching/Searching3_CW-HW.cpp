// 1. Find the nearest integer quotient of a/b using Binary Search

# include<iostream>
# include<vector>
# include<limits.h>

using namespace std;

// Here, a/b i.e. a is dividend and b is divisor

int findNearestQ(int a, int b) {
  int s = 0;
  int e = a;
  int mid = s + ((e - s) / 2);
  int ans = -1;
  if (b == 0) {
    cout << "Division by Zero" << endl;
    return -1;
  } else if (b != 0) {
    while (s <= e) {
      if (mid * b == a) {
        ans = mid;
        return ans;
      }
      if (mid * b > a) {
        e = mid - 1;
      } else if (mid * b <= a) {
        ans = mid;
        s = mid + 1;
      }
      mid = s + ((e - s) / 2);
    }
  }
  return ans;
}

double findExactQ(int a, int b){
    double ans = findNearestQ(a,b);
    double step = 0.1;
    int pre = 10;
    for(int i=0;i<pre;i++){
      double j = ans;
      while(j*b<=a){
      ans = j;
      j += step;
      }
      step /= 10;
    }
    return ans;
}

// 2. Find element in nearly sorted array
// Now, a nearly sorted array is, where an element which should be at ith position is either at (i-1)th index, ith index or (i+1)th index
// SA = [10,20,30,40,50,60,70]
// NSA = [20,10,30,50,40,70,60]

int findNSArray(vector<int>& arr,int target){
    int s = 0;
    int e = arr.size()-1;
    int mid = s + ((e-s)/2);

    while(s<=e){
      if(arr[mid]==target){
        return mid;
      }
      else if(arr[mid-1]==target){
        return mid-1;
      }
      else if(arr[mid+1]==target){
        return mid+1;
      }
      else if(arr[mid]>target){
        e = mid -2; // IMP POINT, since mid-1 is already checked
      }
      else{
        s = mid + 2; // IMP POINT, since mid+1 is already checked
      }
      mid = s + ((e-s)/2);
    }
    return -1;
}

// 3. Find the Odd Occuring Element (Matlab saare element even times appear hotte hai ek ke baad ek sirf ek ko chod kar, 
// no pair is repeating and ke baar mein koi bhi number will not appear more than twice)
// EG: [10,10,20,20,30,30,40,50,50,60,60]

int findOOEle(vector<int>& arr){
  int s = 0;
  int e = arr.size()-1;
  int mid = s +  ((e-s)/2);
  
  while(s<=e){
    if(s==e){
      return s;
    }
    if(mid&1){
      if((mid-1)>=0 && arr[mid]==arr[mid-1]){
        s = mid +1;
      }
      else{
        e = mid-1;
      }
    }
    else{
      if((mid+1 < arr.size()) && arr[mid]==arr[mid+1]){
        s = mid + 2;
      }
      else{
        e = mid;
      }
    }
    mid = s + ((e-s)/2);
  }
  return -1;
}


int main() {


// //Find Nearest Quotient
//   int dividend = 22;
//   int divisor = 7;
//   double a = findExactQ(abs(dividend), abs(divisor));
//   if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0)) {
//     cout << "Final answer is :" <<endl;
//     printf("%10f",a);
//     cout<<endl;
//   } else {
//     double b = a * (-1);
//     cout << "Final answer is :" <<endl;
//     printf("%10f",b);
//     cout<<endl;


// Find in Nearly Sorted Array
//  vector<int> NSA;
//  NSA.push_back(20);
//  NSA.push_back(10);
//  NSA.push_back(30);
//  NSA.push_back(50);
//  NSA.push_back(40);
//  NSA.push_back(70);
//  NSA.push_back(60);
//  int k = 60;
//  int ans = findNSArray(NSA,k);
//  cout<<"Target is at Index : "<<ans<<endl;

  // Find odd occuring element
  // vector<int> arr;
  // arr.push_back(10);
  // arr.push_back(10);
  // arr.push_back(20);
  // arr.push_back(20);
  // arr.push_back(30);
  // arr.push_back(30);
  // arr.push_back(40);
  // arr.push_back(40);
  // arr.push_back(50);
  // arr.push_back(60);
  // arr.push_back(60);
  // arr.push_back(70);
  // arr.push_back(70);
  // arr.push_back(80);
  // arr.push_back(80);

  // int ans = findOOEle(arr);
  // cout<<"The odd occuring element is : "<<ans<<endl;
 


}
