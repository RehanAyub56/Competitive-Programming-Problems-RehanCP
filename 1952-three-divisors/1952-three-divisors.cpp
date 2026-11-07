class Solution {
public:
    bool isThree(int n) {
        int d=0;

        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                d++;
                if(i!=n/i)d++;
            }
        }

        return d==3;
    }
};