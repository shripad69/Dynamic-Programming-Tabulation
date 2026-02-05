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
        
        // Using amount + 1 as a safe "infinity"
        vector <vector <int>> dp (n + 1, vector <int> (amount + 1, amount + 1));

        // Base case: 0 coins needed to make amount 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 0;
        }

        // filling table
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= amount; j++) {
                
                // 1. Logic: Don't take and go back (Skip current coin)
                dp[i][j] = dp[i - 1][j];

                // 2. Logic: Take and stay (Use current coin, stay on same row)
                // Use i-1 to pick the current coin from the vector
                if (j - coins[i - 1] >= 0) {
                    dp[i][j] = min(dp[i][j], 1 + dp[i][j - coins[i - 1]]);
                }
                
            }
        }

        if (dp[n][amount] <= amount) return dp[n][amount];
        return -1;
    }
};