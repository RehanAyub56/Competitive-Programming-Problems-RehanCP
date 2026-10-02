class Solution {
public:
    vector<int>dp;
    int Dice(vector<int>&nums,int target,int sum){
        int n=nums.size();
        if(sum>target){
            return 0;
        }
        if(sum==target){
            return 1;
        }

        if(dp[sum]!=-1){
            return dp[sum];
        }
        dp[sum]=0;
        for(int i=0;i<n;i++){
            dp[sum]+=Dice(nums,target,sum+nums[i]);
        }

        return dp[sum];

    }
    int combinationSum4(vector<int>& nums, int target) {
        for(int i=0;i<target+1;i++){
            dp.push_back(-1);
        }
        int sum=0;
        int ans=Dice(nums,target,sum);

        return ans;

    }
};

/*
Discussion:-

                           Dice
                        /  |    \
                     1     2        3
                  / | \   / | \   / | \
                1   2  3 1  2  3  1  2  3

        we can take all the combinations of that and then those sum become greater then target keeps returning thier 0 because ther is no way of then but if sum is less then target there can be more possibilties so that we can get desired target 

        use of Dp to get rid of repeated calculations and before checking all we make dp[sum]=0 because we dont want to add in already -1 in that dp so start with 0 then proceed 

        we take the dp size of target + 1 because of base case saying that if sum>target we do not need to store it always 0 we only want that have less then target or equal to so from 0 to target only needed 

*/