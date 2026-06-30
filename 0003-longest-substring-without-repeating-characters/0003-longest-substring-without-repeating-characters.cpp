class Solution {
public:
    int lengthOfLongestSubstring(string s) {
         map<char,int>freq;
            int l=0;
            int ans=0;
         for(int r=0;r<s.length();r++){
            freq[s[r]]++;
           
            if(freq[s[r]]>1){

                while(s[l]!=s[r]){
                    freq[s[l]]--;
                    l++;
                }
                    freq[s[l]]--;
                    l++;
                     
            }
            else{
            ans=max(ans,r+1-l);

            }

         }


         return ans;
    }
};