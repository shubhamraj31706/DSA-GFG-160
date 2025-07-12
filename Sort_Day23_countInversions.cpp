/*
Given an array of integers arr[]. You have to find the Inversion Count of the array. 
Note : Inversion count is the number of pairs of elements (i, j) such that i < j and arr[i] > arr[j].

Examples:

Input: arr[] = [2, 4, 1, 3, 5]
Output: 3
Explanation: The sequence 2, 4, 1, 3, 5 has three inversions (2, 1), (4, 1), (4, 3).

Input: arr[] = [2, 3, 4, 5, 6]
Output: 0
Explanation: As the sequence is already sorted so there is no inversion count.

Input: arr[] = [10, 10, 10]
Output: 0
Explanation: As all the elements of array are same, so there is no inversion count.

Expected Complexities
    Time Complexity: O(n log n)
    Auxiliary Space: O(n)
*/


#include <iostream>
#include <vector>
using namespace std;

int countAndMerge(vector<int>& arr, int l, int m, int r){
    int n1 = m - l + 1, n2 = r - m;
    vector<int> left(n1), right(n2);

    for(int i = 0; i < n1; i++){
        left[i] = arr[l + i];
    }
    for(int j = 0; j < n2; j++){
        right[j] = arr[m + 1 + j];
    }

    int res = 0, i = 0, j = 0, k = l;

    while(i < n1 && j < n2){
        if(left[i] <= right[j]){
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
            res += (n1 - i);
        }
    }

    while(i < n1) arr[k++] = left[i++];
    while(j < n2) arr[k++] = right[j++];

    return res;
}

int countInv(vector<int>& arr, int l, int r){
    int res = 0;
    if(l < r){
        int m = l + (r - l) / 2;

        res += countInv(arr, l, m);
        res += countInv(arr, m + 1, r);
        res += countAndMerge(arr, l, m, r);
    }
    return res;
}

int inversionCount(vector<int> &arr) {
    int n = arr.size();

    // int count = 0;   //M1 but TC => O(n^2)
    // for(int i = 0; i < n; i++){
    //     for(int j = i + 1; j < n; j++){
    //         if((i < j) && (arr[i] > arr[j])) count++;
    //     }
    // }
    // return count;

    return countInv(arr, 0, n - 1);
}

void runTestCase(vector<int> arr) {
    cout << "Input: arr[] = [";
    for(int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if(i != arr.size() - 1) cout << ", ";
    }
    cout << "]" << endl;

    int result = inversionCount(arr);
    cout << "Output: " << result << endl << endl;
}

int main() {
    vector<int> test1 = {2, 4, 1, 3, 5};  
    vector<int> test2 = {2, 3, 4, 5, 6};  
    vector<int> test3 = {10, 10, 10};     

    runTestCase(test1);
    runTestCase(test2);
    runTestCase(test3);

    return 0;
}
