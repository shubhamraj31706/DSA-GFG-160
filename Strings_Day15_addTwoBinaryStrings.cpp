/*
Given two binary strings s1 and s2 consisting of only 0s and 1s. Find the resultant string after adding the two Binary Strings.
Note: The input strings may contain leading zeros but the output string should not have any leading zeros.

Input: s1 = "1101", s2 = "111"
Output: 10100
Explanation:
 1101
+ 111
10100

Input: s1 = "00100", s2 = "010"
Output: 110
Explanation:
  100
+  10
  110

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(n)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

string addBinary(string &s1, string &s2)
{
    // long long d1 = 0;  // my approach but cant handle big inputs
    // long long d2 = 0;

    // for(char digit : s1){
    //     d1 = d1*2 + digit - '0';
    // }
    // for(char digit : s2){
    //     d2 = d2*2 + digit - '0';
    // }

    // long long ans = d1+d2;

    // string sum = "";

    // if(ans==0) return "0";
    // while(ans>0){
    //     int rem = ans%2;
    //     sum = char(rem+'0') + sum;
    //     ans/=2;
    // }

    // return sum;

    int a = s1.length();
    int b = s2.length();
    int i = 0, carry = 0;
    string ans = "";

    while (i < a || i < b || carry != 0)
    {
        int x = 0;
        if (i < a && s1[a - i - 1] == '1')
        {
            x = 1;
        }

        int y = 0;
        if (i < b && s2[b - i - 1] == '1')
        {
            y = 1;
        }

        ans = char((x + y + carry) % 2 + '0') + ans;
        carry = (x + y + carry) / 2;
        i += 1;
    }

    int pos = 0;
    while (pos < ans.size() - 1 && ans[pos] == '0')
    {
        pos++;
    }

    return ans.substr(pos);
}

int main(){
    string s1 = "1101";
    string s2 = "111";

    cout << addBinary(s1, s2) << endl;

    return 0;
}