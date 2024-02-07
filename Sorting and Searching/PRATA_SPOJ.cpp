#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isPossibleSolution(vector<int> arr,int nP,int maxtime){
    int currP = 0;
    for(int i=0;i<arr.size();i++){
        int j = 1;
        int R = arr[i];
        int timetaken = 0;

        while(true){
            if(timetaken + j*R <= maxtime){
                currP++;
                timetaken += j*R;
                j++;
            }
            else{
                break;
            }
        }
        if(currP>=nP){
            return true;
        }
    }
    return false;
}

int minTimetoCompleteOrder(vector<int> arr,int nP){
    int s = 0;
    int e = *max_element(arr.begin(),arr.end());
    int cooksum = (nP*(nP+1))/2;
    e = e * cooksum;

    int mid = s + ((e-s)/2);
    int ans = 0;

    while(s<=e){
        if(isPossibleSolution(arr,nP,mid)){
            ans = mid;
            e = mid - 1;
        }
        else{
            s = mid + 1;
        }
        mid = s + ((e-s)/2);
    }
    return ans;
}

int main() {
    int T;cin >> T;
    while(T--){
        int nP,nC;
        cin >> nP >> nC;
    

        vector<int> cookRanks;

        while(nC--){
            int r;cin >> r;
            cookRanks.push_back(r);
        }
        cout<<minTimetoCompleteOrder(cookRanks,nP)<<endl; 
    }
    
  
}