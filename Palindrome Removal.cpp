// Source: https://usaco.guide/general/io

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int solve(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));

        for (int i = 0; i < n; i++) dp[i][i] = 1;

        for (int length = 2; length <= n; length++) {  
            for (int start = 0; start <= n - length; start++) {
                int end = start + length - 1;

                if (arr[start] == arr[end] && length == 2) {
                    dp[start][end] = 1;
                } else if (arr[start] == arr[end]) {
                    dp[start][end] = dp[start + 1][end - 1];
                } else {
                    dp[start][end] = INT_MAX;
                    for (int split = start; split < end; split++) {
                        dp[start][end] = min(dp[start][end], dp[start][split] + dp[split + 1][end]);
                    }
                }
            }
        }

        return dp[0][n - 1];
    }
};



int main() {
 vector<int> arr = {1, 3, 4, 1, 5};
    Solution sol;
    cout << "Minimum moves to remove palindromes: " << sol.solve(arr) << endl;

}
