class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int>mp;
        int n=nums.size();
        pair<int,int>x={nums[0],nums[1]};
        mp[x]++;
        x={nums[n-1],nums[n-2]};
        mp[x]++;
        for(int i=1;i<n-1;i++){
            x={nums[i],nums[i+1]};
            mp[x]++;
            x={nums[i],nums[i-1]};
            mp[x]++;
        }
        int mxi=0;
        pair<int,int>y;
        for(auto it : mp){
            if(it.second>mxi && it.first.first!=it.first.second){
                y=it.first;
                mxi=it.second;
            }
        }

        for(int i=0;i<n;i++){
            if(nums[i]==y.first){
                nums[i]=y.second;
            }
        }

        int ans=0;
        for(int i=1;i<n;i++){
            if(nums[i]==nums[i-1]){
                ans++;
            }
        }

        return ans;
    }
};