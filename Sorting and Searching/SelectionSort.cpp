# include <iostream>
# include <vector>

using namespace std;

// Basically, Selection Sort is:
// For the ith Iteration, find the smallest element from i to (n-1) and SWAP it with the ith element


void Print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void SelectionSortInc(vector<int>& v){ // This is if you want in increasing order (default)
    for(int i=0;i<v.size()-1;i++){ // Because agar 5 element hai, toh 4 iterations mein you will get your answer. Thus, you make i < (n-1) in the outer loop (iterations ka loop)
        int min = i;
        for(int j=i+1;j<v.size();j++){ // Because for each element, you will compare it with all elements ahead of it (excluding itself). Thus, you will make (n-1) comparisons in the inner loop (comparisions ka loop)
            if(v[j]<v[min]){
                min = j;
            }
        }
        swap(v[i],v[min]);
    }
}

void SelectionSortDec(vector<int>& v){ // This is if you want in decreasing order
    for(int i=0;i<v.size()-1;i++){ // Because agar 5 element hai, toh 4 iterations mein you will get your answer. Thus, you make i < (n-1) in the outer loop (iterations ka loop)
        int max = i;
        for(int j=i+1;j<v.size();j++){ // Because for each element, you will compare it with all elements ahead of it (excluding itself). Thus, you will make (n-1) comparisons in the inner loop (comparisions ka loop)
            if(v[j]>v[max]){
                max = j;
            }
        }
        swap(v[i],v[max]);
    }
}

int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(0);
    v.push_back(8);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);
    v.push_back(9);
    v.push_back(10);


    cout<<"--------------"<<endl;
    cout<<"Before Selection Sort (Increasing)"<<endl;
    Print(v);
    SelectionSortInc(v);
    cout<<"After Selection Sort Inecreasing)"<<endl;
    Print(v);
    cout<<"--------------"<<endl;
    cout<<"Before Selection Sort (Decreasing)"<<endl;
    Print(v);
    SelectionSortDec(v);
    cout<<"After Selection Sort (Decreasing)"<<endl;
    Print(v);
    cout<<"--------------"<<endl;
}