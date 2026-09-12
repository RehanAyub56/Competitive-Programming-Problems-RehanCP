class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        
        set<int>s;
        int ans=0;
        int n=digits.size();

        for(int i=0;i<n;i++){
            if(digits[i]%2==0)
            for(int j=0;j<n;j++){
                for(int k=0;k<n;k++){
                    if(j!=k && i!=k && i!=j && digits[k]!=0){
                        s.insert(digits[i]*100 + digits[j]*10 + digits[k]);
                    }
                }
            } 
        }
        

        return s.size();

    }
};