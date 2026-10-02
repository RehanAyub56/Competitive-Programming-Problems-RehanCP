class Solution {
public:
    const int Mode=1e9+7;
    vector<vector<int>>dp;
    int Dice(int n,int k,int target,int sum,int dice){
        if(sum>target || dice>n ){
            return 0;
        }
        if(sum==target && dice==n){
            return 1;
        }
        if(dp[dice][sum]!=-1)return dp[dice][sum];
        int ways=0;
        for(int i=1;i<=k;i++){
            ways=(ways+Dice(n,k,target,sum+i,dice+1))%Mode;
        }
        return dp[dice][sum]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        for(int i=0;i<n+1;i++){
            vector<int>a;
            for(int j=0;j<target+1;j++){
                a.push_back(-1);
            }
            dp.push_back(a);
        }
        int ans=Dice(n,k,target,0,0);

        return ans;
    }
};


/*
Discussion:

We use 2D DP here this is because we have two things changing one is sum every Time and other is Dice every Time we can not use the dp[dice1] sum for the dp[dice2] sum they both we diffrernt So what is intuition:

IMPORTANT Point : we Take the Dimension of Dp with respect to the number of changing quatity 

normally only one quantity is changing so we take dp vector but in this case two changing every Time we need 2D DP 

we Take Size of dp upto the max limit of changing quantity 


*/