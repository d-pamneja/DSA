# include <iostream>
# include <vector>
# include <string.h>
# include<stdio.h>

using namespace std;

// HW - 1. Mannual Scratch Function to FIND
int findSratch() // TC -> O(n) ; SC -> O(1)
{
    int i,j,temp;
    char str[100]={"This is a pattern matching"};
    char substr[20]={"pattern"};
 
    for(i=0;str[i]!='\0';i++)
    {
        j=0;
        if(str[i]==substr[j])
        {
            temp=i+1;
            while(str[i]==substr[j])
            {
                i++;
                j++;
            }
 
            if(substr[j]=='\0')
            {
                printf("The substring is present in given string at position %d\n",temp);
                exit(0);
            }
            else
            {
                i=temp;
                temp=0;
            }
        }
    }
 
    if(temp==0)
        printf("The substring is not present in given string\n");
 
    return 0;
}

// HW - 2. Mannual Scratch Function to ERASE
int EraseScratch() // TC -> O(n) ; SC -> O(1)
{
    int i, j = 0, k = 0,n = 0;
    int flag = 0;
 
    char str[100], neww[100], word[100];

    printf("Enter Any String to Remove a Word from String: ");
    gets(str);

    printf("\n\n Enter Any Word You Want to be Removed: ");
    gets(word);

    for(i = 0 ; str[i] != '\0' ; i++)
    {
        k = i;
     
        while(str[i] == word[j])
        {
            i++,j++;
            if(j == strlen(word))
            {
                flag = 1;
                break;
            }
        }
    j = 0;

    if(flag == 0)
        i = k;      
    else
        flag = 0;

    neww[n++] = str[i];
    }

    neww[n] = '\0';
    
    printf("\n\n After Removing Word From String: %s",neww);
}

//HW 