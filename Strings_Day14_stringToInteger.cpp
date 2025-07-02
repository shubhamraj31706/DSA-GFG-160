/*
Given a string s, the objective is to convert it into integer format without utilizing any built-in functions. Refer the below steps to know about atoi() function.

Cases for atoi() conversion:

Skip any leading whitespaces.
Check for a sign (‘+’ or ‘-‘), default to positive if no sign is present.
Read the integer by ignoring leading zeros until a non-digit character is encountered or end of the string is reached. If no digits are present, return 0.
If the integer is greater than 231 – 1, then return 231 – 1 and if the integer is smaller than -231, then return -231.
Examples:

Input: s = "-123"
Output: -123
Explanation: It is possible to convert -123 into an integer so we returned in the form of an integer

Input: s = "  -"
Output: 0
Explanation: No digits are present, therefore the returned answer is 0.

Input: s = " 1231231231311133"
Output: 2147483647
Explanation: The converted number will be greater than 231 – 1, therefore print 231 – 1 = 2147483647.

Input: s = "-999999999999"
Output: -2147483648
Explanation: The converted number is smaller than -231, therefore print -231 = -2147483648.

Input: s = "  -0012gfg4"
Output: -12
Explanation: Nothing is read after -12 as a non-digit character ‘g’ was encountered.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int myAtoI(string s)
{
    if (s.length() == 0)
        return 0;
    int i = 0;
    while (i < s.length() && s[i] == ' ')
        i++;
    s = s.substr(i);

    int sign = 1;
    long long ans = 0;
    if (s[0] == '-')
        sign = -1;

    if (s[0] == '-' || s[0] == '+')
    {
        i = 1;
    }
    else
    {
        i = 0;
    }

    while (i < s.length())
    {
        if (!isdigit(s[i]))
            break;

        ans = ans * 10 + s[i] - '0';

        if (sign == -1 && -ans < INT_MIN)
            return INT_MIN;
        if (sign == 1 && ans > INT_MAX)
            return INT_MAX;

        i++;
    }

    return (int)(ans * sign);
}

int main()
{
    string s1 = "-123";
    string s2 = "  -";
    string s3 = " 1231231231311133";
    string s4 = "-999999999999";
    string s5 = "  -0012gfg4";

    cout << myAtoI(s1) << endl;
    cout << myAtoI(s2) << endl;
    cout << myAtoI(s3) << endl;
    cout << myAtoI(s4) << endl;
    cout << myAtoI(s5) << endl;
    return 0;
}