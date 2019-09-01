/*
* https://leetcode.com/problems/edit-distance/
*/

#include <bits/stdc++.h>

using namespace std;

class Solution {
public:
    int minDistance(string word1, string word2) {
        int w1l = word1.length(), w2l = word2.length();
        vector<vector<int> > dp(w1l + 1, vector<int>(w2l + 1, 0));
        for(int i = 0; i <= w1l; ++i) {
            for(int j = 0; j <= w2l; ++j) {
                if(i == 0) dp[i][j] = j;
                else if(j == 0) dp[i][j] = i;
                else {
                    if(word1[i - 1] == word2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                    else dp[i][j] = min({dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]}) + 1;
                }
            }
        }
        return dp[w1l][w2l];
    }
};

// Driver Code
int main() {
    Solution sol;
    cout << sol.minDistance("intention", "execution"); // The expected answer with word1 = "intention" and word2 = "execution" is 5.
    return 0;
}