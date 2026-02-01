// main idea --
// row --->            number of elements take from the array
// col --->            target sum we want to make 
// dp[row][col] --->   can we make the sum equal to col by using the row number of elements
// here we only intialized the dp[0][0] , but and number of elements 0 
// but not target sum == 0 because there can be 0's in the array so we let the dp handle it ...

class Solution {
  public:
    int perfectSum(vector<int>& arr, int target) {
        
        int n = arr.size();
        vector <vector <int>> dp(n + 1, vector <int>(target + 1, 0));
        
        dp[0][0] = 1;
        
        for (int ele = 1; ele <= n; ele++) {
            for (int tar = 0; tar <= target; tar++) {
                if (ele == 0 && tar == 0) continue;
                else {
                    if (tar - arr[ele - 1] >= 0) {
                        dp[ele][tar] = dp[ele - 1][tar - arr[ele - 1]] + dp[ele - 1][tar];
                    }
                    else {
                        dp[ele][tar] = dp[ele - 1][tar];
                    }
                }
            }
        }
        
        return dp[n][target];
    }
};