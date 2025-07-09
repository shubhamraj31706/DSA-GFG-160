/*
You are given two strings of equal lengths, s1 and s2. The task is to check if s2 is a rotated version of the string s1.

Note: The characters in the strings are in lowercase.

Examples :

Input: s1 = "abcd", s2 = "cdab"
Output: true
Explanation: After 2 right rotations, s1 will become equal to s2.

Input: s1 = "aab", s2 = "aba"
Output: true
Explanation: After 1 left rotation, s1 will become equal to s2.

Input: s1 = "abcd", s2 = "acbd"
Output: false
Explanation: Strings are not rotations of each other.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(n)
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
  public:
    // M3: KMP LPS array computation
    vector<int> computeLPS(string pat){
        int n = pat.size();
        vector<int> lps(n);
        int len = 0;
        lps[0] = 0;
        int i = 1;
        while(i < n){
            if(pat[i] == pat[len]){
                len++;
                lps[i] = len;
                i++;
            } else {
                if(len != 0){
                    len = lps[len - 1];
                } else {
                    lps[i] = 0;
                    i++;
                }
            }
        }
        return lps;
    }

    bool areRotations(string &s1, string &s2) {
        // M1: Brute Force Rotation (O(n^2))
        /*
        for(int i = 0; i < s1.length(); ++i){ 
            if(s1 == s2) return true;
            char last = s1.back();
            s1.pop_back();
            s1 = last + s1;
        }
        return false;
        */

        // M2: Using built-in find() (O(n))
        /*
        if(s1.length() != s2.length()) return false;
        string temp = s1 + s1;
        return temp.find(s2) != string::npos;
        */

        // M3: Using KMP Algorithm (O(n))
        if(s1.length() != s2.length()) return false;

        string txt = s1 + s1;
        string pat = s2;
        int n = txt.length();
        int m = pat.length();
        vector<int> lps = computeLPS(pat);
        int i = 0, j = 0;

        while(i < n){
            if(pat[j] == txt[i]){
                i++; j++;
            }

            if(j == m) return true;

            else if(i < n && pat[j] != txt[i]){
                if(j != 0) j = lps[j - 1];
                else i++;
            }
        }

        return false;
    }
};

int main() {
    Solution obj;
    string s1 = "ABCD";
    string s2 = "CDAB";

    if(obj.areRotations(s1, s2)){
        cout << "Yes, they are rotations of each other." << endl;
    } else {
        cout << "No, they are NOT rotations of each other." << endl;
    }

    return 0;
}
