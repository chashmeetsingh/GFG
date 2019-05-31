// Problem:
// Given an array A of N positive numbers. The task is to find the position where equilibrium first occurs in the array. Equilibrium position in an array is a position such that the sum of elements before it is equal to the sum of elements after it.

// Input:
// The first line of input contains an integer T, denoting the number of test cases. Then T test cases follow. First line of each test case contains an integer N denoting the size of the array. Then in the next line are N space separated values of the array A.

// Output:
// For each test case in a new  line print the position at which the elements are at equilibrium if no equilibrium point exists print -1.

// Constraints:
// 1 <= T <= 100
// 1 <= N <= 106
// 1 <= Ai <= 108

// Example:
// Input:
// 2
// 1
// 1
// 5
// 1 3 5 2 2

// Output:
// 1
// 3

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int t, n, num, flag, pos;
    vector<int> v;

    cin>>t;
    for(int i = 0; i < t; i++) {
        cin>>n;
        v.clear();

        for(int j = 0; j < n; j++) {
            cin>>num;
            v.push_back(num);
        }

        int sum = 0;
        for(int j = 0; j < n; j++) {
            sum += v[j];
        }

        flag = 0;

        // TLE
        // cout<<"Sum: "<<sum<<endl;
        // for(int j = 0; j < n; j++) {
        //     int left_sum = sum;
        //     for(int k = j; k < n; k++) {
        //         left_sum -= v[k];
        //         // cout<<"sum: "<<left_sum<<endl;
        //     }
        //     // cout<<endl<<"Left "<<left_sum<<endl;
        //     if (left_sum == (sum - left_sum - v[j])) {
        //         flag = 1;
        //         pos = j;
        //         break;
        //     }
        // }

        // Faster method
        int left_sum = 0;
        int right_sum = sum - v[0];

        if (left_sum == right_sum) {
            flag = 1;
            pos = 0;
        } else {
            for(int j = 1; j < n; j++) {
                left_sum += v[j - 1];
                right_sum -= v[j];

                if (left_sum == right_sum) {
                    flag = 1;
                    pos = j;
                    break;
                }
            }
        }

        if (flag) {
            cout<<pos+1<<endl;
        } else {
            cout<<-1<<endl;
        }
    }
    return 0;
}