#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

void indextarget(int n){
  if(n<=0){
    return;
  }

  int remain = n%10;

  indextarget(n/10);

  cout<<remain<<" ";

 
}

void indextargetvector(int n, vector<int> &v){
  if(n<=0){
    return;
  }

  int remain = n%10;

  indextarget(n/10);

  v.push_back(remain);

 
}

// Vector to print
void vectorprint(vector<int> v,int index,string &str){
  if(index>=v.size()){
    return;
  }

  // cout<<v[index];
  char s = ('0' + v[index]);
  str = str + s;

  vectorprint(v,index+1,str);

}


//String 'Babbar" target "a" print index(s) of the vector + push in vector
void stringpush(string s,vector<int> &v,int index,char target){
  if(index>=s.length()){
    return;
  }

  if(s[index]==target){
    v.push_back(index);
    
  }

  stringpush(s,v,index+1,target);

}



int main() {
  int arr[5] = {10,10,10,40,10};
  int size = 5;
  int index = 0;
  // int max1 = INT_MIN;
  // maxnikal(arr,size,index,max1);

  // cout<<max1;
  // cout<<endl;
  // vector<int> v1 = {4,2,5,7};
  // vectorprint(v1,index);
  // indextarget(123456789);
  // indextargetvector(1234,v1);
  // for(int num:v1){
  //   cout<<num<<endl;
  // }

  string s1 = "Babbar";
  vector<int> v2;
  // char t1 = "a";

  // stringpush(s1,v2,index,'a');
  // for(int num:v2){
  //   cout<<num<<endl;
  // }

  vector<int> v3;
  v3.push_back(4);
  v3.push_back(7);
  v3.push_back(1);
  v3.push_back(2);

  string str1 = "";

  vectorprint(v3,0,str1);
  str1 = str1 + '\0';
  cout<<stoi(str1);
  cout<<endl;

  return 0;
}