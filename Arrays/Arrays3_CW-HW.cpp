
// CLASS NOTES: 09
// 	7. Print 2D-Array column wise
// 	8. Taking input from user in 2D-Array
// 	9. Linear Search in 2D-Array
// 	10. Maximum and Minimum in 2D-Array
// 	11. Print row wise and column wise sum of 2D-Array
// 	12. Sum of principal diagonal elements of a matrix
// 	13. Transpose of a matrix
// 	14. Vector Notes
// 	15. Jagged Array

// CLASS HOMEWORK: 09
// 	1. Column wise sum of a 2D-Array
// 	2. Sum of secondary diagonal elements


#include <iostream>
#include <limits.h>
#include <vector>

using namespace std;

void Print2DArrayRowWise(int arr[][3], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

void Print2DArrayColWise(int arr[][3], int row, int col) {
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

void Input2DArray(int arr[][3], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      cout << "Enter the input for row index " << i << " column index " << j<< " : ";
      cin >> arr[i][j];
    }
  }
}

bool LinearSearch2D(int arr[][3], int row, int col, int element) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] == element) {
        cout << "Element found at index " << i << "," << j << endl;
        return true;
      }
    }
  }
  return false;
}

void Maxin2DArray(int arr[][3],int row,int col){
  int maximum = INT_MIN;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] >= maximum) {
                maximum = arr[i][j];
      }
    }
  }
  cout<<"Maximum element is : "<<maximum<<endl;
}

void Minin2DArray(int arr[][3],int row,int col){
  int minimum = INT_MAX;
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {
      if (arr[i][j] <= minimum) {
                minimum = arr[i][j];
      }
    }
  }
  cout<<"Minimum element is : "<<minimum<<endl;
}

void RowWiseSum2DArray(int arr[][3],int row,int col){
  for (int i = 0; i < row; i++) {
    int sum = 0;
    for (int j = 0; j < col; j++) {
      sum += arr[i][j];
    }
    cout <<"The sum for elements in Row "<<i<<" is "<< sum<<endl;
  }
}

void ColWiseSum2DArray(int arr[][3],int row,int col){
  for (int i = 0; i < col; i++) {
    int sum = 0;
    for (int j = 0; j < row; j++) {
      sum += arr[j][i];
    }
    cout <<"The sum for elements in Col "<<i<<" is "<< sum<<endl;
  }
}
  
void DiaWiseSum2DArray(int arr[3][3],int row,int col){
  int sum = 0;
  for (int i = 0; i < row; i++) {
        sum += arr[i][i];
  }
  cout <<"The sum for Diagonal is : "<< sum<<endl;
}

void Transpose2DArray(int arr[][3], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = i; j < col; j++) {
      swap(arr[i][j],arr[j][i]);
    }
  }
}

void SecondaryDiagonalSum2DArray(int arr[][3],int row, int col){
    int n = 3;
    int sum = 0;
    for(int i=0;i<row;i++){
            sum += arr[i][(n-i)-1];
    }
    cout<<"The sum of secondary diagonal is : "<<sum<<endl;
}

int main() {
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  // int brr[3][3];
  int row = 3;
  int col = 3;

  // Print 2D Array Row Wise
  // Print2DArrayRowWise(arr, row, col);

  // Print 2D Array Col Wise
  // Print2DArrayColWise(arr, row, col);

  // Take Input and Print 2D Array
  // Input2DArray(brr, row, col);
  // Print2DArrayRowWise(brr, row, col);

  // Search an element via Linear Search in 2D Array
  // LinearSearch2D(arr, row, col, 81);

  // Printing Max and Min element
  // Maxin2DArray(arr, row, col);
  // Minin2DArray(arr, row, col);
  
  // Row Wise Sum
  // RowWiseSum2DArray(arr, row, col);

  // Col Wise Sum
  // ColWiseSum2DArray(arr, row, col);

  // Diagonal Wise Sum
  // DiaWiseSum2DArray(arr, row, col);

  // Transpose a 2D Array
  // Transpose2DArray(arr,row,col);
  // Print2DArrayRowWise(arr, row, col);

  // Sum of Secondary Array
  SecondaryDiagonalSum2DArray(arr,row,col);
  Print2DArrayRowWise(arr, row, col);
}