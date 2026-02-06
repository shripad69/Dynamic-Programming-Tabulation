//  f(n) --> tells what is max profit if rod is of length n
// f(0) --> will be 0 , that is max profit 
// same for f(n < 0)  ---> 0
// now for each n we divide it from like 0 , n
// or (1, n - 1) ---> (2, n - 2) ----> f(3, n - 3)
// now the logic is dp[i] represent that what is the max profit till length i
class Solution {
  public:

    // recurrsive + memo code 
    int f(int n, vector <int> & v, vector <int>& dp) {
        
        if (dp[n] != -1) return dp[n];
        if (n < 0) return 0;
        int maxp = 0;

        // break using all possible way
        for (int i = 1; i <= n; i++) {
            maxp = max(v[i - 1] + f(n - i, v, dp), maxp);
        } 

        // return max profit 
        return dp[n] = maxp;
    }

    // tabulation logic 
    int cutRod(vector<int> &price) {

        int n = price.size();
        vector <int> dp (n + 1, INT_MIN);

        // if n == 0 then profit is 0 and if i have only one inch rod then sell directly
        dp[0] = 0;
        dp[1] = price[0];


        for (int i = 2; i <= n; i++) {

            // now check for all possible break;
            for (int j = 1; j <= i; j++) {

                // one part is of length j, and find best for (i - j) length
                dp[i] = max(dp[i], price[j - 1] + dp[i - j]);
            }
        }
        
        return dp[n];
    }
};