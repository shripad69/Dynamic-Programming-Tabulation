// here dp[i][j] tells that can we make the subset sum  equal to j using first i number of elements
// if dp[i][j] == 1 then we make the subset sum j
// now we traverse the the i == n and then find the all possible sums and then we calculate the diff   



class Solution {

  public:
    int minDifference(vector<int>& arr) {

        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);
        
        vector <vector <int>> dp (n + 1, vector <int> (sum + 1, 0));

        // using any i number of elements we can make the subset having sum == 0
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j <= sum; j++) {
                if (i == 0 || j == 0) continue;
                else {
                    dp[i][j] = dp[i][j] || dp[i - 1][j];
                    if (j - arr[i - 1] >= 0) {
                        dp [i][j] = dp[i][j] || dp[i - 1][j - arr[ i - 1]];
                    }
                }
            }
        }
        
        int ans = INT_MAX;
        
        for (int j = 0; j <= sum; j++) {
            
            // j is sum of current subset  and (sum - j) another subset 
            if (dp[n][j]) {
                ans = min(ans, abs ((sum - j)- j));    
            }
        }
        return ans;
    }
};
