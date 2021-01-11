#include <iostream>
using namespace std;

int isPalindrome(int x) {
    int digit;
    int reversed;
    while(x!=0)
    {
        digit=x%10;
        reversed = reversed*10 + digit;
    }
    if(reversed==x)
    {
        return 1;
    } else {
        return 0;
    }
    
}

int main() {
    int n;
    cin >>n;
    
    if(isPalindrome(n) == 1) {
        cout <<n<<" is a palindrome";
    }
    else {
        cout << n<<" is NOT a palindrome";
    }
    return 0;
}