# include <iostream>
# include <vector>

using namespace std;

// Basically, bubble sort is:
// Swap the adjacent elements if needed,
// and keep on doing till we get all the array sorted
         
// Time Complexity → n + (n-1) + … + 2 + 1 → O(n*(n-1)/2) → O(n^2)
// This is it’s biggest drawback, that it’s TC is O(N^2). Get it?

void Print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void BubbleSortInc(vector<int> &v){ // This is if you want in increasing order (default)
    int n = v.size();
    for(int i = 0; i<(n-1);i++){ // Because agar 5 element hai, toh 4 iterations mein you will get your answer. Thus, you make i < (n-1) in the outer loop (iterations ka loop)
        for(int j = 0;j<(n-i)-1;j++){ // Because in each iteration, total comparsions will be 1 less than that iteration number. Thus you make j<(n-i)-1 in the inner loop (comparisions ka loop)
            if(v[j]>v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}

void BubbleSortDec(vector<int> &v){ // This is if you want in decreasing order
    int n = v.size();
    for(int i = 0; i<(n-1);i++){ // Because agar 5 element hai, toh 4 iterations mein you will get your answer. Thus, you make i < (n-1) in the outer loop (iterations ka loop)
        for(int j = 0;j<(n-i)-1;j++){ // Because in each iteration, total comparsions will be 1 less than that iteration number. Thus you make j<(n-i)-1 in the inner loop (comparisions ka loop)
            if(v[j]<v[j+1]){
                swap(v[j],v[j+1]);
            }
        }
    }
}

int main(){
    vector<int> v;
    v.push_back(6);
    v.push_back(5);
    v.push_back(4);
    v.push_back(3);
    v.push_back(2);
    v.push_back(1);

    vector<int> c;
    c.push_back(1);
    c.push_back(2);
    c.push_back(3);
    c.push_back(4);
    c.push_back(5);
    c.push_back(6);

    cout<<"--------------"<<endl;
    cout<<"Before Bubble Sort (Increasing)"<<endl;
    Print(v);
    BubbleSortInc(v);
    cout<<"After Bubble Sort Inecreasing)"<<endl;
    Print(v);
    cout<<"--------------"<<endl;
    cout<<"Before Bubble Sort (Decreasing)"<<endl;
    Print(c);
    BubbleSortDec(c);
    cout<<"After Bubble Sort (Decreasing)"<<endl;
    Print(c);
    cout<<"--------------"<<endl;
}