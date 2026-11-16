class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int>a;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0){
                a.push_back(nums[i]);
            }
        }
        if(a.size()>0){
        k=k%(a.size());
        int n=a.size();
        reverse(a.begin(),a.end());
        reverse(a.begin(),a.end()-k);
        reverse(a.begin()+n-k,a.end());
        }
        int v=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>=0)nums[i]=a[v],v++;
        }

        return nums;
        
    }
};