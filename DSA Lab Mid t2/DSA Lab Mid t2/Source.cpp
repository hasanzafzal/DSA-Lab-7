#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isPalindrome( string& input)
{
    stack<char> charStack;
    string filteredInput;
    for (char ch : input) 
    {
        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9')) 
        {
            if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch + ('a' - 'A');
            }
            filteredInput += ch;
            charStack.push(ch);
        }
    }

    for (char ch : filteredInput) 
    {
        if (ch != charStack.top())
        {
            return false;
        }
        charStack.pop();
    }

    return true;
}

int main() 
{
    string input;
    cout << "Enter a string ending with '.': ";
    getline(cin, input);
    if (!input.empty() && input.back() == '.') 
    {
        input.pop_back();
    }
    if (isPalindrome(input))
    {
        cout << "The given string is a palindrome." << endl;
    }
    else 
    {
        cout << "The given string is not a palindrome." << endl;
    }
    return 0;
}