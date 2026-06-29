class Solution {
public:

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>a;
        double median=0;

                int j=0;
                int k=0;
            while(k<nums1.size() && j<nums2.size()){
                if(nums1[k]<nums2[j]){
                    a.push_back(nums1[k]);
                    k++;
                }
                else{
                     a.push_back(nums2[j]);
                     j++;
                }
            }

            while(k<nums1.size()){
                    a.push_back(nums1[k]);
                    k++;   
            }
            while(j<nums2.size()){
                    a.push_back(nums2[j]);
                    j++;   
            }
int n=a.size();
            if(a.size()%2==0){
                median=(a[(n/2)-1]+a[n/2])/2.0;
            }
            else{
                median=a[(n/2)];
            }

            for(int i=0;i<a.size();i++){
                cout<<a[i]<<" ";
            }
        

        return median;
    }
};