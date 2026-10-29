class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string ans="";
        int mn=INT_MAX;
        for(int i=0;i<strs.size();i++){
            mn=min(mn,int(strs[i].size()));
        }
        int k=0;
        for(int i=0;i<mn;i++){
            char pref=strs[0][i];
            for(int j=1;j<strs.size();j++){
                if(pref!=strs[j][k]){
                    return ans;
                }
            }
            ans+=pref;
            k++;
        }
         

        return ans;
    }
};