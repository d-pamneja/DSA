
// CLASS NOTES: 10
// 	1. Moving All Negative Number to the Left Side of an Array
// 	2. Sort Colors (Leetcode-75)
//  3. Rotate Array (Leetcode-189)
//  4. Missing Number (Leetcode-268)
//  5. Row with maximum ones (VVIimp Leetcode-2643)
//  6. Rotate Image by 90 degree (VVImp Leetcode-48)

// HW SOLVE THESE APPROACHES WITH DIFFERENT APPROACHES

// CLASS HOMEWORK: 10
// 	0. Re-arrange array elements (Leetcode-2149) - 3.extra

#include <iostream>
#include <limits.h>
#include <vector>
#include <limits.h>

using namespace std;



void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

void MoveNegFirst(int arr[], int n)
{
    int j = 0; // Here, j is going to track the first positive i.e. jaha par sabse phele +ve number hai for the trail
    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}


// Sort Colors (Leetcode-75) Dutch National Flag Problem
void sortColors(vector<int> &nums)
{
    int i = 0;
    int left = 0; // Position of Last 0 track karne ke liye
    int right = (nums.size() - 1); // Position of last 2's track karne ke liye

    while (i <= right)
    {
        if (nums[i] == 2)
        {
            // Agar starting mein 2 mille, usse end mein bhej ke right minus kar do, par because swap hoke 0 ya 1 hai we do not know, leave the index and left there only
            swap(nums[i], nums[right]);
            right--;
        }

        else if (nums[i] == 0)
        {
            // Case jab starting mein 0 mille, khud se hi swap kar do aur phir index aur left dono ko hi agge kar do
            swap(nums[i], nums[left]);
            left++;
            i++;
        }

        else
        { // agar 1 hai, toh agge bagh jao
            i++;
        }
    }
}


// Rotate Array (Leetcode-189) //Inteview Question
void rotate(vector<int>& nums, int k) {
        //Modulus Method
        vector<int> ans(nums.size());
        for(int i=0; i<nums.size();i++){
            ans[(i+k)%nums.size()] = nums[i];
        }
        nums=ans;
}

void rotate(vector<int>& nums, int k) { // IMP approach for Interview
        // Reverse Method
        k = k %(nums.size()); // Taaki k ki value n se badi na ho
        reverse(nums.begin(),nums.end());
        reverse(nums.begin(),nums.begin()+k);
        reverse(nums.begin()+k,nums.end());

        // [1,2,3,4,5,6,7]; k = 3
        // Reverse (0,n-1) -> [7,6,5,4,3,2,1]
        // Reverse (0, k -1) -> [5,6,7,4,3,2,1]
        // Reverse (k,n-1) -> [5,6,7,1,2,3,4]
}

// Missing Number (Leetcode-268) //Interview
int missingNumber(vector<int>& nums) {
        // Sum Method
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += nums[i];
        }
        int n = nums.size();
        
        return ((n*(n+1))/2) - ans;
}

// Missing Number (Leetcode-268) //Interview
int missingNumber(vector<int>& nums) {
        // XOR Method
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans = ans^ nums[i];
        }
        for(int i=0;i<nums.size();i++){
            ans = ans^ i;
        }
        return ans;
}


// Row with maximum ones (VVIimp Leetcode-2643)
vector<int> rowAndMaximumOnes(vector<vector<int > >& mat) {
    vector<int> ans;
    int max_sum = INT_MIN;
    int max_row = -1;
    for(int i = 0;i<mat.size();i++){
        int sum = 0;
        for(int j=0;j<mat[i].size();j++){
            if(mat[i][j]==1){
                sum++;
            }
        }
        if(sum>max_sum){
            max_sum = sum;
            max_row = i;
        }
    }

    ans.push_back(max_row);
    ans.push_back(max_sum);
    return ans;
}

// Rotate Image by 90 degree (VVImp Leetcode-48) // Interview Question
void rotate(vector<vector<int > >& matrix) {
        // Transpose karle phele
        int n = matrix.size();
        for(int i=0;i<n;i++){
            for(int j=i;j<matrix[i].size();j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        // Saari rows ki reverse kar de abh
        for(int i=0;i<n;i++){
            reverse(matrix[i].begin(),matrix[i].end());
        }
}

// Re-arrange array elements (Leetcode-2149)
vector<int> rearrangeArray(vector<int>& nums) {
        int pos = 0;
        int neg = 1;
        vector<int> ans(nums.size(),-1);

        for(int i=0;i<nums.size();i++){
            if(nums[i]<0){
                ans[neg] = nums[i];
                neg+=2;
            }
            else{
                ans[pos] = nums[i];
                pos+=2;
            }
        }
        nums=ans;
        return nums;
    }

int main()
{
    int arr[] = {-1, 2, -3, -4, 5};
    MoveNegFirst(arr, 5);
    printArray(arr, 5);
}
