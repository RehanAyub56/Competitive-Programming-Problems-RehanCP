class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        
        vector<int>cnt={0,0,0};
        int n=stones.size();
        for(int i=0;i<n;i++){
            if(stones[i]%3==0){
                cnt[0]++;
            }
            else if(stones[i]%3==1){
                cnt[1]++;
            }
            else{
                cnt[2]++;
            }
        }

        /*
        Look if 3,6,9,12,15,18....... only has these values then first value chose always divided by 3 so what alice looses in her first attempt
        */
       
        

        if(cnt[0]%2==0){
            return cnt[1]>0 && cnt[2]>0;
        }

        if(abs(cnt[1]-cnt[2])>2){
            return true;
        }

        return false;
        

    }
};