

// main idea --
// row --->            number of elements take from the array
// col --->            target sum we want to make 
// dp[row][col] --->   can we make the sum equal to col by using the row number of elements


bool isSubsetSum(vector<int>& arr, int sum) {
        
        int n = arr.size();
        
        vector <vector <bool>> dp (n + 1, vector <bool> (sum + 1));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = 1;
        }
        
        for (int j = 1; j < sum + 1; j++) {
            dp[0][j] = 0;
        }
        
        for (int idx = 0; idx <= n; idx++) {
            for (int curr = 0; curr <= sum; curr++) {
                if (idx == 0 || curr == 0) continue;
                else {
                    if (curr - arr[idx - 1] >= 0) {
                        dp[idx][curr] = dp[idx - 1][curr] || dp[idx - 1][curr - arr[idx - 1]];
                    }
                    else {
                        dp[idx][curr] = dp[idx - 1][curr];
                    }
                }
            }
        }
        return dp[n][sum];
    }