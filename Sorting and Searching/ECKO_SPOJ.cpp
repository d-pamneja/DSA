#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool totalwood(vector<long long int> trees, long long int mid, long long int m){
  long long int wood = 0;
  for(long long int i=0;i<trees.size();i++){
    if(trees[i]>mid){
      wood += trees[i] - mid;
    }
  }
  return wood>=m;
}

long long bladeheight(vector<long long int> trees, long long m){
  long long int s = 0;
  long long int e = *max_element(trees.begin(),trees.end());
  long long int mid = s + ((e-s)/2);

  long long int ans = -1;

  while(s<=e){
    if(totalwood(trees,mid,m)){
      ans = mid;
      s = mid + 1;
    }
    else{
      e = mid - 1;
    }
    mid = s + ((e-s)/2);
  }
  return ans;
}


int main() {
  long long int n,m;
  cin>>n>>m;

  vector<long long int> trees;

  while(n--){
    long long int height;
    cin>>height;
    trees.push_back(height);
  }

  cout<<bladeheight(trees,m)<<endl;

  return 0;
}