class Solution {
public:
    int getSum(int a, int b) {

        /*

        Discussion:-

        Xor operator add the bits two that are distinct like 10 ^ 01 = 11
        because thay are distint bits but we need the carry too Xor operator completlty ignore the carry but we know the AND operator will give the carry if bits are same same bits will always generates the carry like :-

                1100101
              & 0101011
              = 0100101

        we know that carry always shifted to the right so right shift by one
        until no carry remains 
        

        */


        while(b){
            int temp=a;
            a=a^b;
            b=((temp&b)<<1);     
        }


        return a;

    }
};