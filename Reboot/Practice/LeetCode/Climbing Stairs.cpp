/*
* https://leetcode.com/problems/climbing-stairs/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1, 0);
        for(int i = n; i >= 0; --i) {
            if(i == n) dp[i] = 1;
            else if(i + 2 > n) dp[i] = dp[i + 1];
            else dp[i] = dp[i + 1] + dp[i + 2];
        }
        return dp[0];
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.climbStairs(3); // The expected answer for input 3 is 3.
    return 0;
}