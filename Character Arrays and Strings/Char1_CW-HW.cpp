# include <iostream>
# include <vector>
# include <string.h>

using namespace std;

// CW - 1. Find the length of a string

int findLength(char ch[],int n){
    int count = 0;
    for(int i=0;i<n;i++){
        if(ch[i]=='\0'){
            break;
        }
        else{
            count ++;
        }
    }
    return count;
}


// HW - 1. Find the length using while loop
int findLengthW(char ch[],int n){
    int i = 0; //Time complexity -> O(n)
    while(ch[i]!='\0'){
        i ++;
    }
    return i;
}

// CW -2. Reverse the string
string ReverseString(char ch[]){
    int i = 0;
    int j = findLengthW(ch,100)-1;
    while(j>i){
        swap(ch[i],ch[j]);
        i++;
        j--;
    }
    return ch;
}


// CW - 3. Convert UpperCase to LowerCase
void UtL(char ch[]){ // Time complexity -> O(l) where l is the length of the string
    int i=0;
    while(ch[i]!='\0'){
        char currchar = ch[i];
        if(currchar >= 'A' && currchar <= 'Z'){
            ch[i] = currchar - 'A' + 'a';
        }
        i++;
    }
}

// CW - 4. Convert LowerCase to UpperCase
void LtU(char ch[]){ // Time complexity -> O(l) where l is the length of the string
    int i=0;
    while(ch[i]!='\0'){
        char currchar = ch[i];
        if(currchar >= 'a' && currchar <= 'z'){
             ch[i] = currchar - 'a' + 'A';
        }
       i++;
    }
}

// CW - 5. Replace certain character with another one
void ReplaceChar(char ch[], char current_char, char new_char){ // Time complexity -> O(l) where l is the length of the string
    int i = 0;
    while(ch[i]!='\0'){
        if(ch[i]==current_char){
            ch[i]=new_char;
            i++;
        }
        i++;
    }
}

// CW -6. Check Palindrome -> VVIMP
bool checkPalindrome(char ch[]){ // Time complexity -> O(n)
    int i=0;
    int j=findLengthW(ch,100)-1;
    while(i<j){
        if(ch[i]!=ch[j]){
            return false;
        }
        i++;
        j--;
    }
    return true;
}





int main(){
    // Length of String
    // char ch[100];
    // cin.getline(ch,100); // Yaha spaces bhi count hongay
    // cout<<"The Length of Input is: "<<findLengthW(ch,100)<<endl;

    //Reverse of String
    // char ah[100];
    // cin.getline(ah,100); // Yaha spaces bhi count hongay
    // cout<<"The Reverse of Input using my functon is: "<<ReverseString(ah)<<endl;

    // HW - Reverse using Inbuilt Function
    // string str;
    // cin>>str;
    // reverse(str.begin(),str.end());
    // cout<<"The Reverse of Input using inbuilt functon is:" <<str<<endl;
    // // cout<<ah<<endl; // Iska matlab by reference hi pass ho raha hai i.e. it will change the original array


    // Upper to Lower and Lower to Upper 
    // char uh[100];
    // cin.getline(uh,100); // Yaha spaces bhi count hongay
    // UtL(uh,findLengthW(uh,100));
    // cout<<"The UpperCase of Input is : " <<uh<<endl;

    // Replace certain character of a string with the given one
    // char rh[100];
    // cin.getline(rh,100); // Yaha spaces bhi count hongay
    // ReplaceChar(rh,findLengthW(rh,100),'@',' ');
    // cout<<"The Replaced string of Input is : " <<rh<<endl;

    //CheckPalindrome (this is ofc case sensitive)
    // char ph[100];
    // cin.getline(ph,100);
    // if(checkPalindrome(ph,findLengthW(ph,100))){
    //     cout<<"The Input is a Palindrome."<<endl;
    // }
    // else{
    //     cout<<"The Input is not a Palindrome."<<endl;
    // }
    
}
