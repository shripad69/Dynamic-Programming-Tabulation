// dp logic 
// if n == 0 if am == 0 then dp[n][am] = 1 else 0;

// else logic 
// also check if am - v[n - 1] >= 0 logic
// int takeandStay = 1 + f(n, am - v[n - 1], v); 
// int takeandPass = 1 + f(n - 1, am - v[n - 1], v);
// int skip = f(n - 1, am, v);

class Solution {
public:

    int coinChange(vector<int>& coins, int amount) {

        int n = coins.size();

        vector <vector <int>> dp (n + 1, vector <int> (amount + 1, INT_MAX));

        // initilize the base case
        dp[0][0] = 1;
        for (int j = 1; j <= amount; j++) {
            dp[0][i] = 0; 
        }

        // filling table
        for (int i = 1; <= n; i++) {
            for (int j = 0; j <= amount; j++) {

                // take and stay
                if (am - coins[j - 1] >= 0) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][am - coins[j - 1]]);
                }

                // take and go back
                if (am - coins[j - 1] >= 0) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i - 1][am - coins[j - 1]]);
                }

                // dont take and go back
                dp[i][j] = min(dp[i][j], dp[i - 1][j]);
            }
        }

        return dp[n][amount];
    }
};