class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        sort(nums1.begin(),nums1.end());
        bool ok=true;
        int mn=INT_MAX;
        for(int i=0;i<nums1.size();i++){
            if(nums1[i]&1)
            mn=min(mn,nums1[i]);
        }

     
            for(int i=1;i<nums1.size();i++){
                if(nums1[0]%2==1 && nums1[i]%2==0 && (nums1[i]-mn)<1){
                    ok=false;
                }
                else if(nums1[0]%2==0 && nums1[i]%2==1 && (nums1[i]-mn)<1){
                    ok=false;
                }
            }
        
        
        return ok;

        
    }
};