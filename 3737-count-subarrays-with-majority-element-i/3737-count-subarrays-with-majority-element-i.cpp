class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int ans=0;

        for(int i=0;i<nums.size();i++){
            map<int,int>mp;
            for(int j=i;j<nums.size();j++){
                mp[nums[j]]++;
                if(((j-i+1)/2)<mp[target]){
                    ans++;
                }
            }
            mp.clear();
        }
        return ans;
    }
};