class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>dp(n+1,0);
        dp[0]=0;
        if(n>=1)dp[1]=1;
        for(int i=1;i<=n;i++){
            int j=i;
            int cnt=0;

            while(!dp[j]){
                if(j&1){
                    cnt++;
                }
                j=j>>1;
            }
            dp[i]=dp[j]+cnt;
        }


        return dp;
    }
};