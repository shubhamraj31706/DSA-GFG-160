/*
Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive integer. Do the mentioned change in the array in place.

Note: Consider the array as circular.

Examples :

Input: arr[] = [1, 2, 3, 4, 5], d = 2
Output: [3, 4, 5, 1, 2]
Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

Input: arr[] = [7, 3, 9, 1], d = 9
Output: [3, 9, 1, 7]
Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.

Expected Complexities
    Time Complexity: O(n)
    Auxiliary Space: O(1)
*/



#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


//MY APPROACH
void rotateArray1(vector<int> &arr, int d){
    int n = arr.size();
    int newd = d%n;
    vector<int> ans;

    for(int i =newd; i<n; i++){
        ans.push_back(arr[i]);
    }
    for(int i = 0; i<newd; i++){
        ans.push_back(arr[i]);
    }

    for(int val : ans){
        cout << val << " ";
    }

    cout << endl;
}

//BETTER APPROACH
void rotateArray2(vector<int> &arr, int d){
    int n = arr.size();
    d=d%n;

    reverse(arr.begin(), arr.begin() + d);
    reverse(arr.begin() + d, arr.end());
    reverse(arr.begin() , arr.end());

    for(int val : arr){
        cout << val << " ";
    }

    cout << endl;
}
int main(){
    vector<int> arr1 = {1,2,3,4,5};
    vector<int> arr2 = {2, 4, 6, 8, 10, 12, 14, 16, 18, 20};
    vector<int> arr3 = {7, 3, 9, 1};
    int d1 = 2, d2 = 3, d3 = 9;

    rotateArray1(arr1, d1);
    rotateArray2(arr1, d1);
    rotateArray1(arr2, d2);
    rotateArray2(arr2, d2);
    rotateArray1(arr3, d3);
    rotateArray2(arr3, d3);
    
    return 0;
}
