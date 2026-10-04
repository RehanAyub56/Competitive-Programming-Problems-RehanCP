class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        map<int,int>mp,ms;
        for(auto x:nums) mp[x]++;
        
        for(auto it:mp){
            ms[it.second]++;
        }

        for(auto x:nums){
            if(ms[mp[x]]==1){
                return x;
            }
        }

        return -1;

    }
};