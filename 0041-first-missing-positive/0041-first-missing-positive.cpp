class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        

        vector<int>a;

        for(int i=0;i<nums.size();i++){
            if(nums[i]>0){
                a.push_back(nums[i]);
            }
           
        }
        nums=a;

        nums.erase(unique(nums.begin(),nums.end()),nums.end());

int ans=0;
if(nums.size()>=1){
for(int i=0;i<nums.size();i++){
            if(nums[i]!=i+1){
                ans=i+1;
                break;
            }
        }

        for(int i=0;i<nums.size();i++){
            cout<<nums[i]<<" ";
        }

        if(ans==0){
            ans=nums[nums.size()-1]+1;
        }

}
else{
    ans=1;
}
        

        return ans;
    }
};