class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;
        if(coins.size()== 0) return 0;

        vector<int> dp(amount+1, amount+1);
        dp[0] = 0;

        for(int i = 0; i<amount+1; i++){
            for(int c: coins){
                if(i >= c){
                    dp[i] = min(dp[i], dp[i-c]+1);
                }
            }
        }

        return dp[amount] > amount ? -1 : dp[amount];
        
    }
};
