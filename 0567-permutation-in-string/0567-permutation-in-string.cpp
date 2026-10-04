class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char,int>mp1,mp2;
        for(int i=0;i<s1.length();i++){
            mp1[s1[i]]++;
        }
        int k=s1.length();
        int l=0;

        for(int i=0;i<s2.length();i++){
            mp2[s2[i]]++;
            cout<<i-l<<endl;
            if(i>=k){
               mp2[s2[l]]--;
               if(mp2[s2[l]]==0){
                    mp2.erase(s2[l]);
               }
               l++; 
               
            }
                if(mp1==mp2){
                    return true;
                }
            
        }

        return false;

    }
};