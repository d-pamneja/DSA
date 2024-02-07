#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Q1) Debug the code. Search in sorted rotated array. (Sorting was less to high).
int search(vector<int>& nums, int target) {
		int l = 0, r = nums.size() - 1;
		while(l <= r){
			int mid = l + (r-l)/2;
			if(nums[mid] == target) return mid;
			else if(nums[l]<=nums[mid]){ // Handles Part B // Here, nums[l] have to be less than nums[mid] only then can be know we in part B
				if(nums[l]<=target && target<nums[mid]) r = mid-1;
				else l = mid+1;
			}
			else{ // Handles Part A
				if(nums[mid]<target && target<=nums[r]) l = mid +1;
				else r = mid-1;
			}
		}
		return -1; // No need to debug this line.
}


// Q2) Debug the code. Find square root of x.
int mySqrt(int x) {
        if (x == 0)
            return x;
        int first = 1, last = x;
        int ans = 0;
        while (first <= last) {
            int mid = first + (last - first) / 2;
            if (mid  == x /mid)
                return mid;
            else if (mid > x / mid) {
                last = mid-1; // Yaha mid - 1 ayega, as this is definetely not the sqaure, no point storing it here
            }
            else {
                ans = mid; // if possible answer, store 
                first = mid+1; // Since you stored, start ko mid + 1 kar de
            }
        }
        return ans;
}

// Q3) Debug the code. Find minimum in rotated sorted array. (Sorting was in ascending order).
int findMin(vector<int>& nums) {
        int start = 0, end = nums.size()-1, ans = start;
        while(nums[start] > nums[end]) {
            int mid = (start + end) >> 1; // Change here to ">>"
            if(nums[mid] <= nums[start] && nums[mid] <= nums[end]) // Part B mein hai, toh preserve karke peeche bhadengay
                end = mid;
            else if(nums[mid] >= nums[start] && nums[mid] >= nums[end]) // Part A se end ke beech mein hai, toh agge badhengay
                start = mid + 1;          
            else return nums[mid];
            ans = start;
        }
        return nums[ans];
}

//Q4) Debug the code. A peak element is an element that is strictly greater than its neighbors. Find the peak element. } Do AGAIN!!
int findPeakElement(vector<int>& nums) {
        int n = nums.size();
        int low = 0;
        int high = n-1;
        while(low < high){
            int mid = (low + high) >> 1;
            if(nums[mid] > nums[mid+1]){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
}

//Q5) Debug the code. Find the length of the longest strictly increasing subsequence. } Do AGAIN!!
int lengthOfLIS(vector<int>& nums) 
    {
        vector<int> ans;
        ans.push_back(nums[0]);
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i]<ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                int index=lower_bound(ans.begin(), ans.end(), nums[i])-ans.begin(); // Before solving get acquainted with lower_bound()
                ans[index]=nums[i];
            }
        }    
        return ans.size();
}

//Q6) Debug the code. Implement selection sort. } Do AGAIN!!
void selectionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

//Q7) Debug BS. // DO AGAIN!!!
int binarySearch(vector<int> nums, int target) {
        int left = 0;
        int right = int(nums.size());
        
        while (left <= right) {
            int mid = left + ((right - left)/ 2);
            if (nums[mid] <= target) {
                left = mid+1;
            } 
            else{
                right = mid;
            }
        }
        if (left >= 0 && nums[left-1] == target) {
                return left-1;
            } 
        else{
            return -1;
        }
}



int main(){
    vector<int> v;
    v.push_back(4);
    v.push_back(5);
    v.push_back(6);
    v.push_back(7);
    v.push_back(9);
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    cout<<binarySearch(v,6)<<endl;

    // cout<<mySqrt(37)<<endl;


}