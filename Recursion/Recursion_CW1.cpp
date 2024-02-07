# include <iostream>


using namespace std;

int fact(int n){
    // Base Case
    if(n==0){ 
        return 1;
    }
    if(n==1){
        return 1;
    }

    // Recursive Call
    int rec_ans = n * fact(n-1);

    // Processing 
    int final_ans = n * fact(n-1);
    return final_ans;
}

int main(){
    cout<<fact(5)<<endl;
}