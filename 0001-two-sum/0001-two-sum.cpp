class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        vector<pair<int,int>>p;
        for(int i=0;i<nums.size();i++){
            p.push_back({nums[i],i});
        }
        sort(p.begin(),p.end());

        vector<int>a;

        for(int i=0;i<p.size();i++){
            if(p[l].first+p[r].first>target){
                r--;
            }
            else if(p[l].first+p[r].first<target){
                l++;
            }
            else{
                a.push_back(p[l].second);
                a.push_back(p[r].second);
                return a;
            }
        }

         return a;
    }
};