class Solution {
public:

    int f(int n, int m, string text1, string text2, vector <vector <int>> &dp) {
        if (m < 1 || n < 1) return 0;
        if (dp[n][m] != -1) return dp[n][m];
        if (text1[n - 1] == text2[m - 1]) return dp[n][m] = 1 + f(n - 1, m - 1, text1, text2, dp);
        return dp[n][m] = max(f(n - 1, m, text1, text2, dp), f(n , m - 1, text1, text2, dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        
        int n = text1.size();
        int m = text2.size();

        // now first writing pure recurrsive code
        // return f(n, m, text1, text2);

        // now use dp table for memo the n and m parameters 
        // vector <vector <int>> dp(n + 1, vector <int> (m + 1, -1));
        // return f(n, m, text1, text2, dp);


        // now using the tabulation where dp i, j represent the max lcs if text1 is i length and text2 is j length
        vector <vector <int>> dp (n + 1, vector <int>(m + 1, 0));

        // now base if i == 0 or j == 0 then lcs will always be 0;
        // so dirctly filling the table 
        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < m + 1; j++) {

                // if the last word is matched the fidn best ans for n - 1, m - 1
                if (text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];

                // if last word do no match then skip 1 char from the text1 or text2 and find the best of the remaining 
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[n][m];

    }
};