/*
Given a string s, the task is to find the minimum characters to be added at the front to make the string palindrome.

Note: A palindrome string is a sequence of characters that reads the same forward and backward.

Examples:

Input: s = "abc"
Output: 2
Explanation: Add 'b' and 'c' at front of above string to make it palindrome : "cbabc"

Input: s = "aacecaaaa"
Output: 2
Explanation: Add 2 a's at front of above string to make it palindrome : "aaaacecaaaa"

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    // bool isPalindrome(string s, int i, int j){
    //     while(i<j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }  //TC is more

    vector<int> computeLPS(string &pat) {
        int n = pat.length();
        vector<int> lps(n);
        lps[0] = 0;
        int len = 0;
        int i = 1;

        while (i < n) {
            if (pat[i] == pat[len]) {
                len++;
                lps[i] = len;
                i++;
            } else if (pat[i] != pat[len]) {
                if (len != 0) {
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    int minChar(string& s) {
        // Write your code here
        // int i = s.size() - 1;
        // int count = 0;

        // while(i>=0 && !isPalindrome(s, 0, i)){
        //     i--;
        //     count++;
        // }
        // return count;

        int n = s.length();
        string rev = s;
        reverse(rev.begin(), rev.end());
        s = s + '$' + rev;

        vector<int> lps = computeLPS(s);
        return (n - lps.back());
    }
};

int main() {
    string s;
    cout << "Enter the string: ";
    cin >> s;

    Solution sol;
    int result = sol.minChar(s);
    cout << "Minimum characters to add to make it palindrome: " << result << endl;

    return 0;
}
