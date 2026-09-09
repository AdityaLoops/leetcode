class Solution {
    using ll= long long;
public:
    long long countCommas(long long n) {
        if(n < 1000)  return 0;
        if(n<1000000) return n - 999;


        ll ans = 0;
        ll c1 = (1000000-999-1)*1*1ll;
        ll c2 = 1ll*(1000000000-999999-1)*2;
        ll c3 = 1ll*(1000000000000-999999999-1)*3;
        ll c4 = 1ll*(1000000000000000-999999999999-1)*4;
        
        ll l1 = 1000000000000;
        ll l2 = 1000000000;
        ll l3 = 1000000;
        if(n == 1000000000000000) return c1+c2+c3+c4+5;
        if( n >= l1) return c1+c2+c3 + 4*ll(n-999999999999);
        else if(n >=l2) return c1+ c2+ 3ll*(n - 999999999);
        else   return c1+ 2ll*(n- 999999);
        
       
 
    }
};