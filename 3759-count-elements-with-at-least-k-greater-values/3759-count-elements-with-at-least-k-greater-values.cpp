class Solution {
public:

    int partition(vector<int>&nums,int l,int h){
        int pivot=nums[l];
        int i=l,j=h;
        while(i<=j){
            while(i<=h && nums[i]<=pivot ){
                i++;
            }
            while(j>l && nums[j]>pivot){
                j--;
            }
            if(i<j)
            swap(nums[i],nums[j]);
        }
        swap(nums[l],nums[j]);

        return j;
    }
    void quickSort(vector<int>&nums,int l,int h){
        if(l<h){
            int j=partition(nums,l,h);
            quickSort(nums,l,j-1);
            quickSort(nums,j+1,h);
        }
    }
    int countElements(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());

        if(k==0)return nums.size();
        int threshold=nums[nums.size()-k];
        int ans=0;
        for(auto it:nums){
            if(it<threshold){
                ans++;
            }
        }
        return ans;

    }
};