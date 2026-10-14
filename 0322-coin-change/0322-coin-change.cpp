class Solution {
public:
    long long int Coins(vector<int>& coins,vector<int>&dp,vector<bool>&dpb,int amount){
        if(amount==0){
            return 0;
        }

        if(amount<0){
            return INT_MAX;
        }
        
        if(dpb[amount]){
            return dp[amount];
        }
        long long int ways=INT_MAX;
        for(int j=0;j<coins.size();j++){
            
            ways=min(ways,1+Coins(coins,dp,dpb,amount-coins[j]));

        }
        dpb[amount]=true;
        return dp[amount]=ways;
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        sort(coins.begin(),coins.end(),greater<int>());
        vector<int>dp(amount+1,INT_MAX);
        vector<bool>dpb(amount+1,false);
        int ans=Coins(coins,dp,dpb,amount);
        if(amount==0)return 0;
        if(amount==INT_MAX)return -1;
        return ((ans==INT_MAX)?-1:ans);

    }
};