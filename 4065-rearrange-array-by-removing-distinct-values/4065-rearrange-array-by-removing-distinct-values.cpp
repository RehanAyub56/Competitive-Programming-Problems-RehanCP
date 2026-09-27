class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int>ans;
        vector<int>rep=nums;

        
        while(!rep.empty()){
            sort(rep.begin(),rep.end());            
            vector<int>a,b;
            a.push_back(rep[0]);
            for(int i=1;i<rep.size();i++){
                if(rep[i]==rep[i-1]){
                    b.push_back(rep[i]);
                }
                else{
                    a.push_back(rep[i]);
                }
            }

            for(int i=0;i<a.size();i++){
                ans.push_back(a[i]);
            }
            
            rep=b;
            
        }


        return ans;
    }
};