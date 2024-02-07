#include <iostream>
#include <limits.h>
#include <vector>
#include <limits.h>

using namespace std;

// Find missing in an array with duplicates
void findMissingDuplicates(int *a,int n){
    int i = 0;
    while(i<n){
        int index = a[i] - 1;
        if(a[i]!=a[index]){
            swap(a[i],a[index]);
        }
        else{
            ++i;
        }
    }
}

// Cols Wave Print
void ColWavePrint(vector<vector<int > > v){
    int row = v.size();
    int col = v[0].size();

    for(int i = 0;i<col;i++){
        if((i&1)==0){
            for(int j=0;j<row;j++){
                cout<<v[j][i]<<" ";
            }
        }
        else{
            for(int j=row-1;j>=0;j--){
                cout<<v[j][i]<<" ";
            }
        }
    }
}

// Rows Wave Print
void RowWavePrint(vector<vector<int > > v){
    int row = v.size();
    int col = v[0].size();

    for(int i = 0;i<row;i++){
        if((i&1)==0){
            for(int j=0;j<col;j++){
                cout<<v[i][j]<<" ";
            }
        }
        else{
            for(int j=col-1;j>=0;j--){
                cout<<v[i][j]<<" ";
            }
        }
    }
}

int main(){
    // int a[] = {1,3,4,3,3};
    // findMissingDuplicates(a,5);
    // for(int i=0;i<5;i++){
    //     if(a[i]!=i+1){
    //         cout<<i+1<<" ";
    //     }
    // }
    // cout<<endl;



    vector<vector<int> >v;
    
    vector<int> v1;
    vector<int> v2;
    vector<int> v3;

    v1.push_back(1);
    v1.push_back(2);
    v1.push_back(3);

    v2.push_back(4);
    v2.push_back(5);
    v2.push_back(6);

    v3.push_back(7);
    v3.push_back(8);
    v3.push_back(9);
    
    v.push_back(v1);
    v.push_back(v2);
    v.push_back(v3);

    ColWavePrint(v);
    cout<<endl;
    RowWavePrint(v);
}

