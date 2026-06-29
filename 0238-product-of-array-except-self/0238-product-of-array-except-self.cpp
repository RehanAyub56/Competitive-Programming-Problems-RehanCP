class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>left(nums.size());
        vector<int>right(nums.size());

        right[nums.size()-1]=1;
        left[0]=1;
        int val=1;
        for(int i=1;i<nums.size();i++){
            val*=nums[i-1];
            left[i]=val;
        }
        val=1;
        for(int i=nums.size()-2;i>=0;i--){
            val*=nums[i+1];
            right[i]=val;
        }

        vector<int>product;
        for(int i=0;i<nums.size();i++){
            product.push_back(left[i]*right[i]);
        }

        return product;

    }
};