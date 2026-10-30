class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        map<char,int>mps,mpp;
        int n=s.length(),m=p.length();
        for(int i=0;i<m;i++){
            mpp[p[i]]++;
        }
        int l=0;
        vector<int>ans;
        for(int i=0;i<n;i++){
            
            mps[s[i]]++;
            if(i>=m-1){

                if(mpp==mps){
                    ans.push_back(l);
                }
                mps[s[l]]--;
                if(!mps[s[l]]){
                    mps.erase(s[l]);
                }
                l++;
                
                
            }
            
        }
        return ans;

    }
};