// CLASS NOTES: 11
//  5. Find first occurrence of a number in sorted array
//  6. Find last occurrence of a number in sorted array
// 	7. Find total occurrence of a number in sorted array
// 	8. Find missing element in sorted array (GFG)
// 	9. Peak element/index in a mountain array (Leetcode-852)

// CLASS HOMEWORK: 11
// 	1. Find pivot element (Leetcode-724)


# include<iostream>
# include<vector>
# include<limits.h>
using namespace std;


//  5. Find first occurrence of a number in sorted array
int FirstOccurence(int arr[],int n,int target){
        int start = 0;
        int end = (n-1);
        int fo = -1;

        while(start<=end){
            int mid = start + ((end-start)/2);

            if(arr[mid]==target){
                fo = mid;
                end = mid-1;
            }

            if(arr[mid]<target){
                start = mid+1;
            }

            if(arr[mid]>target){
                end = mid -1;
            }

        }
        return fo;
}

//  6. Find last occurrence of a number in sorted array
int LastOccurence(int arr[],int n,int target){
        int start = 0;
        int end = (n-1);
        int fo = -1;

        while(start<=end){
            int mid = start + ((end-start)/2);

            if(arr[mid]==target){
                fo = mid;
                start=mid+1;
            }

            if(arr[mid]<target){
                start = mid+1;
            }

            if(arr[mid]>target){
                end = mid -1;
            }

        }
        return fo;
}

// 	7. Find total occurrence of a number in sorted array
// This is nothing but based on the formular :
// Last Occurence - First Occurence + 1
void TotalOccurence(int arr[],int n, int target){
    int total = (LastOccurence(arr,n,target) - FirstOccurence(arr,n,target) + 1);
    cout<<"Total Occurence is : "<<total<<endl;
}

// 	8. Find missing element in sorted array (GFG)
// Here, jab tak missing walla element nahi aya hai ek pattern chalega, aur jaha number break ho gaya, wahi par hai missing number

int FindMissingElement(int arr[],int n){
    int start = 0;
    int end = (n-1);
    int ans = n; // Assume kar le ki last index pe hi number missing hai

    while(start<=end){
        int mid = start + ((end-start)/2);

        if((arr[mid]-mid)==1){
            start = mid+1;
        }
        else{
            ans = mid;
            end = mid -1; // Here, end stores ki pattern sabse pehle kaha break hua and stores ans at that index
        }
    }
    
    return ans+1;
}

// 	9. Peak element/index in a mountain array (Leetcode-852)
int peakIndexInMountainArray(vector<int>& arr) {
        int start = 0;
        int end = arr.size() -1;
        int ans;

        while(start<end){
            int mid = start + ((end-start)/2);
            if(arr[mid]<arr[mid+1]){
                start = mid+1;
            }
            else if(arr[mid]>arr[mid+1]){
                ans = mid;
                end = mid;
            }
        }
        return ans;
        
    }

// Find pivot element (Leetcode-724)
int pivotIndex(vector<int>& nums) {
        vector<int> sumlarr(nums.size(),0);
        vector<int> sumrarr(nums.size(),0);

        for(int i = 1;i<nums.size();i++){
            sumlarr[i] = sumlarr[i-1] + nums[i-1];
        }
        for(int j = (nums.size()-2);j>=0;j--){
            sumrarr[j] = sumrarr[j+1] + nums[j+1];
        }

        for(int i=0;i<nums.size();i++){
            if(sumlarr[i]==sumrarr[i]){
                return i;
            }
        }
        return -1;
}

int main(){
    int arr[7] = {1,3,4,5,6,7,8};
    // FirstOccurence(arr,6,2);
    // LastOccurence(arr,6,2);
    // TotalOccurence(arr,6,2);
    cout<<FindMissingElement(arr,7)<<endl;;
}