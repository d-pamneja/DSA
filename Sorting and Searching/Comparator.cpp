# include <iostream>
# include <vector>

using namespace std;

void Print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void Printvv(vector<vector<int> > &v){
    for(int i=0;i<v.size();i++){
        vector<int>&temp = v[i];
        int a = temp[0];
        int b = temp[1];
        cout<<a<<","<<b<<endl;
    }
    
}

bool myCompInc(int &a, int &b){ // This will sort in increasing order (default)
    return a<b; // Basically, if a is less than b, returns True else false. Jaha jaha True ayega, comparator uske basis pe sort kar dega
}

bool myCompDec(int &a, int &b){ // This will sort in decreasing order
    return a>b; // Basically, if a is greater than b, returns True else false. Jaha jaha True ayega, comparator uske basis pe sort kar dega
}

bool myCompInc2Vec1stIndex(vector<int> &a, vector<int> &b){ // This will sort in increasing order (default)
    return a[1]<b[1]; // Basically, if a is less than b on the first index, returns True else false. Jaha jaha True ayega, comparator uske basis pe sort kar dega
}

int main(){
    // vector<int> v;
    // v.push_back(6);
    // v.push_back(5);
    // v.push_back(0);
    // v.push_back(8);
    // v.push_back(4);
    // v.push_back(3);
    // v.push_back(7);
    // v.push_back(2);
    // v.push_back(1);
    // v.push_back(9);
    // v.push_back(10);

    // vector<int> c;
    // c.push_back(6);
    // c.push_back(5);
    // c.push_back(0);
    // c.push_back(8);
    // c.push_back(4);
    // c.push_back(3);
    // c.push_back(2);
    // c.push_back(1);
    // c.push_back(9);
    // c.push_back(7);
    // c.push_back(10);


    // cout<<"--------------"<<endl;
    // cout<<"Before Sort (Increasing)"<<endl;
    // Print(v);
    // sort(v.begin(),v.end(),myCompInc);
    // cout<<"After Sort Inecreasing)"<<endl;
    // Print(v);
    // cout<<"--------------"<<endl;
    // cout<<"Before Sort (Decreasing)"<<endl;
    // Print(c);
    // sort(c.begin(),c.end(),myCompDec);
    // cout<<"After Sort (Decreasing)"<<endl;
    // Print(c);
    // cout<<"--------------"<<endl;

    vector<vector<int> > v;
    int n;
    cout<<"Enter size of vector: ";
    cin>>n;
    for(int i=0;i<n;i++){
        int a,b;
        cout<<"Enter the elements(space seperated) : ";
        cin>>a>>b;
        vector<int> temp;
        temp.push_back(a);
        temp.push_back(b);
        v.push_back(temp);
    }
    cout<<"Here are the elements: "<<endl;
    cout<<"Before Sorting"<<endl;
    Printvv(v);
    cout<<"After Sorting"<<endl;
    sort(v.begin(),v.end(),myCompInc2Vec1stIndex);
    Printvv(v);
}