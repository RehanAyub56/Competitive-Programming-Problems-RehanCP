class Solution {
public:

    int Search(vector<int>& nums,int target,bool LeftBais){

        int left=0;
        int right=nums.size()-1;
        int index=-1;
        while(left<=right){
            int middle=(left+right)/2;
            if(nums[middle]>target){
                right=middle-1;
            }
            else if(nums[middle]<target){
                left=middle+1;
            }
            else{
                index=middle;
                if(LeftBais){
                    right=middle-1;
                }
                else{
                    left=middle+1;
                }
                

            }
        }

        return index;

    }
    vector<int> searchRange(vector<int>& nums, int target) {

        int left=Search(nums,target,true);
        int right=Search(nums,target,false);
        return {left,right};
    }
};