// now here we want the total diff combinations to add up to amount
// now the 2 cases for transition
//      1. take and stay ---> f(n, am - v[n - 1]);
//      2. nottake and go back -----> f(n - 1, am)... this step also include aboves steps take and goback case
// and then just add the both ways 
// base case if am < 0 return 0 ---> 
// if n == 0 then if am == 0 then only i way or for other amount there is no way so 0

class Solution {
public:


    int f(int n, int am, vector <int>& coins, vector< vector <int>>& dp) {

        // base case 
        if (n == 0) {
            if (am == 0) return 1;
            return 0;
        }

        // amount became negative
        if (am < 0) return 0;
        if (dp[n][am] != -1) return dp[n][am];


        // the two logic that take and stay and the skip part 
        return dp[n][am] = f(n, am - coins[n - 1], coins, dp) + f(n - 1, am, coins, dp);

    }


    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        // vector <vector <int>> dp (n + 1, vector <int> (amount + 1, -1));
        // return f(n, amount, coins, dp);

        vector <vector <unsigned int>> dp (n + 1, vector <unsigned int> (amount + 1, 0));

        // for n == 0 if am = 0 then 1 or 0;
        // for am == 0  then 1 way 


        for (int i = 0; i < n + 1; i++) {
            dp[i] [0] = 1;
        }


        for (int i = 1; i < n + 1; i++) {
            for (int j = 1; j < amount + 1; j++) {
                
                // now first if j - v[i - 1] is greater than equal to 0 . if yes then added it in dp 
                
                // take and stay logic 
                if (j - coins [i - 1] >= 0) {
                    dp[i][j] += dp[i][j - coins[i - 1]];
                }
                // not take condition 
                dp[i][j] += dp[i - 1][j];
            }
        }

        return dp[n][amount];
    }
};