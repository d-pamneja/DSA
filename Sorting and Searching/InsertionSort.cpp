# include <iostream>
# include <vector>

using namespace std;

// Basically, the insertion sort is:
// For ith element, we want that uske peeche ke sarre element sorted ho, and agar nahi toh hum ek ek karke agge shift kare 
// and unn sabko sort karre. By this, once you reach the last element, everything is sorted. Matlab ki you will be inserting the smallest element
// to the left of ith element.

void Print(vector<int> &v){
    for(int i=0;i<v.size();i++){
        cout<<v[i]<<" ";
    }
    cout<<endl;
}

void InsertionSortInc(vector<int> &v){ // This is if you want in increasing order
    for(int i = 1; i<v.size();i++){ // Because agar 5 element hai, toh 4 iterations mein you will get your answer. Thus, you make i < (n-1) in the outer loop (iterations ka loop)
        int key = v[i];
        int j = i -1;

        // Move elements of arr[0..(i-1)] that are greater than 
        // key to one position ahead of their current position

        while(j>=0 && v[j]>key){ // Because for each element, you will compare it with all elements behind of it (excluding itself). Thus, you will make (n-1) comparisons in the inner loop (comparisions ka loop)
            v[j+1] = v[j]; // Yeh shifting ho rahi hai jab tak current key se sarre element bade hai and it is >= 0
            j--;
        }
        v[j+1] = key; // Actual Insertion yaha ho rahi hai
    }
} 

void InsertionSortDec(vector<int> &v){ // This is if you want in decreasing order
    for(int i = 1; i<v.size();i++){
        int key = v[i];
        int j = i -1;

        // Move elements of arr[0..(i-1)] that are greater than 
        // key to one position ahead of their current position

        while(j>=0 && v[j]<key){
            v[j+1] = v[j]; // Yeh shifting ho rahi hai jab tak current key se sarre element bade hai and it is >= 0
            j--;
        }
        v[j+1] = key; // Actual Insertion yaha ho rahi hai
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
    v.push_back(7);
    v.push_back(2);
    v.push_back(1);
    v.push_back(9);
    v.push_back(10);

    vector<int> c;
    c.push_back(6);
    c.push_back(5);
    c.push_back(0);
    c.push_back(8);
    c.push_back(4);
    c.push_back(3);
    c.push_back(2);
    c.push_back(1);
    c.push_back(9);
    c.push_back(7);
    c.push_back(10);


    cout<<"--------------"<<endl;
    cout<<"Before Insertion Sort (Increasing)"<<endl;
    Print(v);
    InsertionSortInc(v);
    cout<<"After Insertion Sort Inecreasing)"<<endl;
    Print(v);
    cout<<"--------------"<<endl;
    cout<<"Before Insertion Sort (Decreasing)"<<endl;
    Print(c);
    InsertionSortDec(c);
    cout<<"After Insertion Sort (Decreasing)"<<endl;
    Print(c);
    cout<<"--------------"<<endl;
}