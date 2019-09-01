/*
* https://leetcode.com/problems/decode-ways/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n, 0);
        dp[n - 1] = 1;
        dp[n - 2] = 2;
        for(int i = n - 3; i >= 0; --i) {
            if(s[i] == '0') dp[i] = 0;
            else if(s[i] == '1') dp[i] = dp[i + 1] + dp[i + 2];
            else if(s[i] == '2') {
                if(s[i + 1] - '0' <= 6) dp[i] = dp[i + 1] + dp[i + 2];
                else dp[i] = dp[i + 1];
            }
            else dp[i] = dp[i + 1];
        }
        return dp[0];
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.numDecodings("12"); // The expected answer with word1 = "intention" and word2 = "execution" is 5.
    return 0;
}