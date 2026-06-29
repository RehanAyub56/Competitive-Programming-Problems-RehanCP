class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>a;
        sort(nums.begin(),nums.end());
        int l=0,r=1,s=nums.size()-1;


        while(nums[l]<0 && l<nums.size()-2){
            while(r<s){
            if(nums[l]+nums[r]+nums[s]<0){
                r++;
            }
            else if(nums[l]+nums[r]+nums[s]>0){
                s--;
            }
            else {
                a.push_back({nums[l],nums[r],nums[s]});
                r++;
            }
         
            }

            
            l++;
            r=l+1;
            s=nums.size()-1;


        }

        int cnt=count(nums.begin(),nums.end(),0);
        if(cnt>=3){
            a.push_back({0,0,0});
        }

        map<vector<int>,int>mp;
        for(int i=0;i<a.size();i++){
            mp[{a[i][0],a[i][1],a[i][2]}]=i;
        }

        vector<vector<int>>b;
        for(auto it : mp){
    b.push_back(it.first);
}

        return b;
        
    }
};