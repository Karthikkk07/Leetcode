class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend==divisor) return 1;
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        if(divisor == 1) return dividend;
        bool sign=true;
        if(dividend>=0 && divisor<0) 
            sign=false;
        if(dividend<0 && divisor>=0)
            sign=false;
        long long n=dividend;
        long long d=divisor;
        n=abs(n);
        d=abs(d);
        long long ans=0,sum=0;
        while (sum+d<=n){
            ans++;
            sum=sum+d;
        }
        return sign?ans:-ans;

    }
};