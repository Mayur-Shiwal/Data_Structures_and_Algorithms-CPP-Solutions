#include <iostream>

using namespace std;


char tolowerCase(char ch){
    if(ch>='a' && ch<='z'){
        return ch;
    }
    else{
        char temp=ch-'A'+'a';
        return temp;
    }

}

bool checkPalindrome(char a[], int n){

    int s=0,e=n-1;
    while(s<=e){
        if(tolowerCase(a[s])!=tolowerCase(a[e])){
            return 0;
        }
        else{
            s++;
            e--;
        }
    }
    return 1;

}

int main()
{
    char str[20];
    cout<<"Enter a string to check a palindrome: "<<endl;
    cin>>str;
    int count=0;
    for(int i=0;str[i]!='\0';i++){
        count++;
    }

    cout<<"palindrome or not: "<<checkPalindrome(str,count)<<endl;


    return 0;
}
