// Problem:
// Given an array A of size N containing 0s, 1s, and 2s; you need to sort the array in ascending order.

// Input:
// The first line contains an integer 'T' denoting the total number of test cases. Then T testcases follow. Each testcases contains two lines of input. The first line denotes the size of the array N. The second lines contains the elements of the array A separated by spaces.

// Output: 
// For each testcase, print the sorted array.

// Constraints:
// 1 <= T <= 500
// 1 <= N <= 106
// 0 <= Ai <= 2

// Example:
// Input :
// 2
// 5
// 0 2 1 2 0
// 3
// 0 1 0

// Output:
// 0 0 1 2 2
// 0 0 1

#include <iostream>
#include <vector>

using namespace std;


// With counting
// int main() {
//     int t, n, num;
//     vector<int> v;

//     cin>>t;
//     for(int i = 0; i < t; i++) {
//         cin>>n;
//         v.clear();

//         for(int j = 0; j < n; j++) {
//             cin>>num;
//             v.push_back(num);
//         }

//         int zeroes = 0, ones = 0, twos = 0;
//         for(int j = 0; j < n; j++) {
//             if (v[j] == 0) {
//                 zeroes += 1;
//             } else if (v[j] == 1) {
//                 ones += 1;
//             } else {
//                 twos += 1;
//             }
//         }

//         while(zeroes > 0) {
//             cout<<"0 ";
//             zeroes -= 1;
//         }
//         while(ones > 0) {
//             cout<<"1 ";
//             ones -= 1;
//         }
//         while(twos > 0) {
//             cout<<"2 ";
//             twos -= 1;
//         }
//         cout<<endl;       
//     }

//     return 0;
// }

// With Dutch National Flag Algorithm
int main() {
    int t, n, num, low, mid, high, temp;
    vector<int> v;

    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> n;
        v.clear();

        for (int j = 0; j < n; j++) {
            cin >> num;
            v.push_back(num);
        }

        low = mid = 0;
        high = n - 1;

        while(mid <= high) {
            switch(v[mid]) {
                case 0:
                    temp = v[low];
                    v[low] = v[mid];
                    v[mid] = temp;
                    low++;
                    mid++;
                    break;

                case 1:
                    mid++;
                    break;

                case 2:
                    temp = v[mid];
                    v[mid] = v[high];
                    v[high] = temp;
                    high--;
            }
        }

        for(int j = 0; j < n; j++) {
            cout<<v[j]<<" ";
        } cout<<endl;
    }
    return 0;
}