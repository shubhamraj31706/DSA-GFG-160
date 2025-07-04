/*
Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.

Examples:

Input: s1 = "geeks" s2 = "kseeg"
Output: true
Explanation: Both the string have same characters with same frequency. So, they are anagrams.

Input: s1 = "allergy", s2 = "allergyy"
Output: false
Explanation: Although the characters are mostly the same, s2 contains an extra 'y' character. Since the frequency of characters differs, the strings are not anagrams.

Input: s1 = "listen", s2 = "lists"
Output: false
Explanation: The characters in the two strings are not the same — some are missing or extra. So, they are not anagrams.

Expected Complexities
    Time Complexity: O(n + m)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <unordered_map>
using namespace std;

bool areAnagrams(string &s1, string &s2)
{
    // code here
    if (s1.length() != s2.length())
        return false;

    // sort(s1.begin(), s1.end()); //approach1 but Tc is more
    // sort(s2.begin(), s2.end());

    // return s1 == s2;

    unordered_map<char, int> m; // better approach

    for (char ch : s1)
    {
        m[ch] += 1;
    }

    for (char ch : s2)
    {
        m[ch] -= 1;
    }

    for (auto val : m)
    {
        if (val.second != 0)
            return false;
    }
    return true;
}

int main(){
    string s1 = "geeks";
    string s2 = "kseeg";

    cout << areAnagrams(s1, s2) << endl;
    return 0;
}