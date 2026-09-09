/*
Discussion :

we can have both positive and negative numbers in the array so we have to normalize it for nomalization first we use 
                                    x%k
but if we have negative let say -1 
                                    -1%5=-1
so   (-1+5)%k=4    for normalization

At last we have the same frequency of all additive inverses


                    


*/


class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {

        map<int,int>mp;
        for(auto x:arr){
            mp[((x%k)+k)%k]++;
        }
        if(mp[0]%2!=0)return false;
        for(int rem = 0; rem < k; rem++){
             int need=(k-rem)%k;
            if(mp[rem] != mp[need])
                return false;
        }

        return true;

    }
};