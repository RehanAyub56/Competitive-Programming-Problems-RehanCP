class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int mn=min_element(nums.begin(),nums.end())-nums.begin();
        int mx=max_element(nums.begin(),nums.end())-nums.begin();  
        int n=nums.size();
        int ans=INT_MAX;

if(mn==mx)return mn+1;     
if(mn<mx)ans=min(ans,mx+1),ans=min(ans,n-mn),ans=min(ans,mn+1+(n-mx));
if(mn>mx)ans=min(ans,mn+1),ans=min(ans,n-mx),ans=min(ans,mx+1+(n-mn));


    return ans;
        
        

        return ans;

    }
};