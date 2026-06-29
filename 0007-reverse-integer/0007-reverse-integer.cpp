class Solution {
public:
    int reverse(int x) {
         long long int reversed=0,digit;
    if(x>=0 && x<=2147483647){
         while(x>0){
        digit=x%10;
        reversed=10*reversed+digit;
        x=x/10;
     
    }
    if(reversed<-2147483648 || reversed>2147483647 ){
        return 0;
    }
  
     return reversed;
    }
    else if(x<=0 && x>=-2147483648){
        while(x<0){
        digit=x%10;
        reversed=10*reversed+digit;
        x=x/10;
     
    }
    if(reversed<-2147483648 || reversed>2147483647 ){
        return 0;
    }
    return reversed;
    }
    
    return 0;
   
    }
};
