class Solution {
public:
    int characterReplacement(string s, int k) {
            map<char,int>freq;
            int l=0;
            int ans=0;
            int r=0;
            int mx=0;
            for(;r<s.length();r++){
                freq[s[r]]++;
                mx=max(mx,freq[s[r]]);
                int res=r-l+1-mx;
                cout<<res<<" "<<mx<<endl;
                if(res>k){
                    ans=max(ans,r-l);
                    freq[s[l]]--;
                    l++;
                }
                else{
                    ans=max(ans,r-l+1);
                }

            }



        return ans;
    }
};