/*
Given two strings, one is a text string txt and the other is a pattern string pat. 
The task is to print the indexes of all the occurrences of the pattern string in the text string. Use 0-based indexing while returning the indices. 
Note: Return an empty list in case of no occurrences of pattern.

Examples :

Input: txt = "abcab", pat = "ab"
Output: [0, 3]
Explanation: The string "ab" occurs twice in txt, one starts at index 0 and the other at index 3. 

Input: txt = "abesdu", pat = "edu"
Output: []
Explanation: There's no substring "edu" present in txt.

Expected Complexities
    Time Complexity: O(n + m)
    Auxiliary Space: O(m
*/

#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Function to build LPS array
vector<int> computeLPS(string pat) {
    int m = pat.length();
    vector<int> lps(m, 0);
    int len = 0;  // length of the previous longest prefix suffix
    int i = 1;

    while(i < m) {
        if(pat[i] == pat[len]) {
            len++;
            lps[i] = len;
            i++;
        } else {
            if(len != 0) {
                len = lps[len - 1];  // try the previous prefix
            } else {
                lps[i] = 0;
                i++;
            }
        }
    }

    return lps;
}

// Function to perform KMP search
vector<int> KMPSearch(string txt, string pat) {
    vector<int> result;
    int n = txt.length();
    int m = pat.length();

    // //approach 1 but TC can be reduced
        // for(int i=0; i<t-p+1; i++){
        //     if(txt.substr(i,p) == pat){
        //         ans.push_back(i);
        //     }
        // }
        
        // return ans;

    vector<int> lps = computeLPS(pat);

    int i = 0, j = 0;  // i for txt, j for pat
    while(i < n) {
        if(txt[i] == pat[j]) {
            i++; j++;
        }

        if(j == m) {
            result.push_back(i - j);  // match found
            j = lps[j - 1];  // continue checking for overlapping patterns
        } else if(i < n && txt[i] != pat[j]) {
            if(j != 0) {
                j = lps[j - 1];  // fallback in pattern
            } else {
                i++;
            }
        }
    }

    return result;
}

int main() {
    string txt = "ababcabcabababd";
    string pat = "abab";

    vector<int> result = KMPSearch(txt, pat);

    if(result.empty()) {
        cout << "[]";
    } else {
        for(int idx : result) {
            cout << idx << " ";
        }
    }

    return 0;
}
