// CLASS NOTES: 12
// 	1. Find pivot element index from sorted and rotated array
// 	2. Search in a rotated and sorted array (Leetcode-33)
//  3. Sqrt of X (Leetcode-69)
// 	4. Binary search in 2D array (Leetcode-74)

// CLASS HOMEWORK: 12
// 	1. Find sqrt of X upto 3 decimal place


# include<iostream>
# include<vector>
# include<limits.h>
using namespace std;

//  1. Find pivot element index from sorted and rotated array and Search in a rotated and sorted array (Leetcode-33)
int findPivotIndex(vector<int>& nums){
    int s = 0;
    int n = nums.size();
    int e = n-1;
    int mid = s + ((e-s)/2);
    
    while(s<=e){
        if((mid-1)>=0 && nums[mid]<nums[mid-1]){
            return mid-1;
        }
        else if (mid+1 < n && nums[mid]>nums[mid+1])
        {
            return mid;
        }
        else if(nums[s]<nums[mid]){
            s = mid + 1;
        }
        else{
            e = mid -1;
        }
        
    }
    return -1;
}

int BinarySearch(vector<int>& nums,int s,int e,int target){
    int mid = s + ((e-s)/2);
    while(s<=e){
        if(nums[mid]==target){
            return mid;
        }
        else if(nums[mid]>target){
            e = mid -1;
        }
        else if(nums[mid]<target){
            s = mid+1;
        }
        mid = s + ((e-s)/2);
    }
    return -1;
}

int PivotIndex(vector<int> &nums, int target){
    int s = 0;
    int e = nums.size()-1;
    int pi = findPivotIndex(nums);

    if(nums[0]<= target && target <= nums[pi]){
        return BinarySearch(nums,s,pi,target);
    }
    else{
        return BinarySearch(nums,pi,e,target);
    }
}

//  3. Sqrt of X (Leetcode-69)
int mySqrt(int x){
    int s = 0;
    int e = x;
    long long mid = s + ((e-s)/2);
    int ans = -1;

    while(s<=e){
        if(mid*mid == x){
            return mid;
        }
        else if((mid*mid)>x){
            e = mid -1;
        }
        else{
            ans = mid;
            s = mid + 1;
        }
        mid = s + ((e-s)/2);
    }
    return ans;
}

// 	HW - 1. Find sqrt of X upto n decimal place
double exactSqrt(int x){
    double ans = mySqrt(x);
    double step = 0.1;
    int pre = 10;
    for(int i=0;i<pre;i++){
        double j = ans;
        while(j*j<=x){
            ans = j;
            j += step;
        }
        step = step / 10;
    }
    
    return ans;
}

// 	4. Binary search in 2D array (Leetcode-74)
bool searchMatrix(vector<vector<int > >& matrix, int target){
    int s = 0;
    int e = matrix[0].size()-1;
    int mid = s + ((e-s)/2);

    int rows = matrix.size()-1;
    int cols = matrix[0].size()-1;

    while(s<=e){
        int rowIndex = mid/cols;
        int colIndex = mid%cols;

        int currNum = matrix[rowIndex][colIndex];

        if(currNum==target){
            return true;
        }
        else if(currNum<target){
            e = mid -1;
        }
        else{
            s = mid + 1;
        }
        mid = s + ((e-s)/2);
    }
    return false;
}


int main(){
    // [4,5,6,7,0,1,2
    // vector<int> v;
    // v.push_back(4);
    // v.push_back(5);
    // v.push_back(6);
    // v.push_back(7);
    // v.push_back(0);
    // v.push_back(1);
    // v.push_back(2);
    // int ans = PivotIndex(v,3);
    // cout<<ans<<endl;

    double ans = exactSqrt(51);
    printf("%10f",ans);
    cout<<endl;

}

