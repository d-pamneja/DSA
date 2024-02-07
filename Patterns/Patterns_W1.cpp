#include <iostream>
using namespace std;

void soildSquarePattern(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
    cout<<"*";
    }
    cout<<endl;
  }
  
}

void hollowSquarePattern(int n){
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if( i == 0 || i == n-1 || j == 0 || j == n-1){
        cout<<"*";
      }
      else{
        cout<<" ";
      }
    }
    cout<<endl;
  }
}

void hollowInvertedHalfPiramid(int n){
  
}

int main() {
  hollowSquarePattern(4);
  return 0;
}