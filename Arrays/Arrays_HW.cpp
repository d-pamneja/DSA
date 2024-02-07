# include <iostream>
# include <vector>

using namespace std;

// Move all negative element to left
void MoveNegLeft(vector<int> &nums){
    int s = 0;
    int e = nums.size() - 1;

    while(s<e){
        if(nums[s]<0){
            s++;
        }
        else if(nums[e]>0){
            e--;
        }
        else{
            swap(nums[s],nums[e]);
        }
    }
}

int main(){
    vector<int> v;
    v.push_back(-5);
    v.push_back(15);
    v.push_back(0);
    v.push_back(1);
    v.push_back(-1);
    v.push_back(2);
    v.push_back(5);
    v.push_back(-45);

    MoveNegLeft(v);
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}