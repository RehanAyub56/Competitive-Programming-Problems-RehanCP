class Solution {
public:
    int dp[50];
    int climb(int n){
        if(n<=2){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n]=climb(n-1)+climb(n-2);

    }
    int climbStairs(int n) {
        for(int i=0;i<50;i++)dp[i]=-1;
        return climb(n);
    }
};