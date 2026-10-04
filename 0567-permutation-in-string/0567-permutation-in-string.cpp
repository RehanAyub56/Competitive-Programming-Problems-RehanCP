class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1,mp2;
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]]++;
        }
        int l=0;
        for(int i=0;i<s2.length();i++){
            mp2[s2[i]]++;
            
            if(mp1[s2[i]]==0){
                while(l<=i){
                    mp2[s2[l]]--;
                    l++;
                }
            }
            else{
                while(mp2[s2[l]]>mp1[s2[l]]){
                    mp2[s2[l]]--;
                    l++;
                }
                if(mp1==mp2){
                    return true;
                }
            }
            cout<<l<<" ";
            
        }

        return false;

    }
};