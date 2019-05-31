// Problem:
// Given a sorted array of positive integers. Your task is to rearrange  the array elements alternatively i.e first element should be max value, second should be min value, third should be second max, fourth should be second min and so on...

// Note: O(1) extra space is allowed. Also, try to modify the input array as required.

// Input:
// First line of input conatins number of test cases T. First line of test case contain an integer denoting the array size N and second line of test case contain N space separated integers denoting the array elements.

// Output:
// Output the modified array with alternated elements.

// Constraints:
// 1 <=T<= 100
// 1 <=N<= 107
// 1 <=arr[i]<= 107

// Example:
// Input:
// 2
// 6
// 1 2 3 4 5 6
// 11 
// 10 20 30 40 50 60 70 80 90 100 110

// Output:
// 6 1 5 2 4 3
// 110 10 100 20 90 30 80 40 70 50 60


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int t, n, num;
    vector<int> v;
    cin>>t;

    for(int i = 0; i < t; i++) {
        cin>>n;
        v.clear();

        for(int j = 0; j < n; j++) {
            cin>>num;
            v.push_back(num);
        }
        
        // sort(v.begin(), v.end());

        int start = 0;
        int end = n - 1;
        while (start < end) {
            cout<<v[end]<<" "<<v[start]<<" ";
            end--;
            start++;
        }
        if (start == end) {
            cout<<v[start];
        }
        cout<<endl;
    }

    return 0;
}