/*
Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.

Examples:

Input: arr[][] = [[1,3],[2,4],[6,8],[9,10]]
Output: [[1,4], [6,8], [9,10]]
Explanation: In the given intervals we have only two overlapping intervals here, [1,3] and [2,4] which on merging will become [1,4]. Therefore we will return [[1,4], [6,8], [9,10]].

Input: arr[][] = [[6,8],[1,9],[2,4],[4,7]]
Output: [[1,9]]
Explanation: In the given intervals all the intervals overlap with the interval [1,9]. Therefore we will return [1,9].

Expected Complexities
    Time Complexity: O(n log n)
    Auxiliary Space: O(1)
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<int>> mergeOverlap(vector<vector<int>>& arr) {
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());  // sort by start times

    // Method 1 (M1) - Nested loop approach
    // for(int i=0; i<n; i++){
    //     int start = arr[i][0];
    //     int end = arr[i][1];

    //     if(!ans.empty() && end <= ans.back()[1]) continue;

    //     for(int j=i+1; j<n; j++){
    //         if(arr[j][0] <= end){
    //             end = max(end, arr[j][1]);
    //         } else {
    //             break;
    //         }
    //     }
    //     ans.push_back({start, end});
    // }

    // Method 2 - Efficient single pass after sorting
    for (int i = 0; i < n; i++) {
        if (ans.empty() || arr[i][0] > ans.back()[1]) {
            ans.push_back(arr[i]);
        } else {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }

    return ans;
}

void printIntervals(const vector<vector<int>>& intervals) {
    cout << "[";
    for (size_t i = 0; i < intervals.size(); i++) {
        cout << "[" << intervals[i][0] << "," << intervals[i][1] << "]";
        if (i != intervals.size() - 1) cout << ", ";
    }
    cout << "]" << endl;
}

int main() {
    vector<vector<int>> arr1 = {{1,3},{2,4},{6,8},{9,10}};
    vector<vector<int>> result1 = mergeOverlap(arr1);
    cout << "Output 1: ";
    printIntervals(result1);

    vector<vector<int>> arr2 = {{6,8},{1,9},{2,4},{4,7}};
    vector<vector<int>> result2 = mergeOverlap(arr2);
    cout << "Output 2: ";
    printIntervals(result2);

    return 0;
}
