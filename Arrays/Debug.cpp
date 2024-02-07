#include<iostream>
using namespace std;



//Q1) Debug the code. Sum of array.


// int main(){
//     int n, sum;
//     sum=0;
//     cin >> n;
//     int input[n];
//     for(int i=0;i<n;i++){
//         cin >> input[i];
//     }

//     for(int i=0; i<n; i++){
//         sum = sum + input[i];
//     }
//     cout<<sum<<endl;
//     return 0;
// }

//Q2) Debug the code. Linear Search
int linearSearch(int arr[], int n ,int val){
    for(int i=0;i<n;i++){
        if(arr[i]==val){
            return i;
        }
    }
    return -1;
}


//Q3) Debug the code. Your task is to populate the array using the integer values in the range 1 to N (both inclusive) 
// in the order - 1,3,5,.......,6,4,2. 
void populate(int arr[],int n){
    int j=0;
    for(int i=0; i < n; i = i + 2){
        arr[n-j-1] = i+2;
        arr[j] = i+1;
        j++;
    }
}

//Q4) Debug
void swapAlternate(int arr[],int size){
    for(int i=0;i<size-1;i=i+2){
        int temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp;
    }
}

//Q5) Debug the code. List all pairs in array that sums to X.
int pairSumToX(int input[], int size, int x){
	int pairs = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			if(input[i] + input[j] == x) {
                pairs++;
                cout<<input[i]<<" "<<input[j]<<endl;
            }
		}
	}
	return pairs;
}

//Q6) Debug the code. List all triplets in array that sums to X.
int tripletSumToX(int input[], int size, int x){
	int triplets = 0;
	for(int i=0; i<size; i++){
		for(int j=i+1; j<size; j++){
			for(int k=i+2; k<size; k++){
				if(input[i] + input[j] + input[k] == x){
                    cout<<input[i]<<" "<<input[j]<<" "<<input[k]<<endl;
                    triplets++;
                } 
                
			}
		}
	}
	return triplets;
}

//Q7) Sort 0's and 1's
void sort0sand1s(int input[], int size){
	int nextZero = 0;
	for(int i=0; i<size; i++){
		if(input[i] == 0){
			int temp = input[nextZero];
			input[nextZero] = input[i];
			input[i] = temp;
            nextZero++;
		}
	}
}

int main(){
    int arr[6]={1,1,0,1,0,1};
    int n = 6;
    sort0sand1s(arr,6);
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
    
    
    
    
}


