class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.length();
        int m = t.length();
        
        // Use double or unsigned long long for intermediate sums if needed, 
        // though the problem guarantees result fits in a 32-bit signed int.
        // We use vector<uint64_t> to prevent overflow during intermediate steps.
        vector<uint64_t> dp(m + 1, 0);
        
        // Base case: An empty t is a subsequence of any prefix of s exactly once.
        dp[0] = 1;
        
        for (int i = 1; i <= n; i++) {
            // Traverse backwards so we use values from the 'previous row' 
            // without them being overwritten yet.
            for (int j = m; j >= 1; j--) {
                if (s[i - 1] == t[j - 1]) {
                    dp[j] = dp[j] + dp[j - 1];
                }
                // If they don't match, dp[j] remains dp[j] (same as dp[i-1][j])
            }
        }
        
        return (int)dp[m];
    }
};