/*
Given a string s consisting of lowercase English Letters. Return the first non-repeating character in s.
If there is no non-repeating character, return '$'.
Note: When you return '$' driver code will output -1.

Examples:

Input: s = "geeksforgeeks"
Output: 'f'
Explanation: In the given string, 'f' is the first character in the string which does not repeat.

Input: s = "racecar"
Output: 'e'
Explanation: In the given string, 'e' is the only character in the string which does not repeat.

Input: s = "aabbccc"
Output: -1
Explanation: All the characters in the given string are repeating.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

char nonRepeatingChar(string &s)
{
    // Your code here
    int n = s.length();

    // for(int i=0; i<n; i++){   //approach 1 but Tc => O(n^2)
    //     bool found = false;
    //     for(int j=0; j<n; j++){
    //         if(i!=j && s[i]==s[j]){
    //             found = true;
    //             break;
    //         }
    //     }
    //     if(!found){
    //         return s[i];
    //     }
    // }
    // return '$';

    vector<int> freq(26, 0);

    for (char ch : s)
    {
        freq[ch - 'a']++;
    }

    for (char ch : s)
    {
        if (freq[ch - 'a'] == 1)
        {
            return ch;
        }
    }

    return '$';
}

int main(){
    string s1 = "geeksforgeeks";
    string s2 = "racecar";
    string s3 = "aabbccc";

    cout << nonRepeatingChar(s1) << endl;
    cout << nonRepeatingChar(s2) << endl;
    cout << nonRepeatingChar(s3) << endl;

    return 0;
}