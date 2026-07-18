#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    long long caltotalhr(vector<int>& piles,int speed){
        long long totalhr=0;
        for(auto x:piles){
            totalhr+=ceil((double)x/speed);
        }
        return totalhr;
    }
    int minEatingSpeed(vector<int>& piles, int h){
        int maxval=*max_element(piles.begin(),piles.end());
        int low=1,high=maxval;
       
        while(low<=high){
            int mid=low+(high-low)/2;
            long long totalhr=caltotalhr(piles,mid);
            if (totalhr<=h){
              
                high=mid-1;
            }
            else{
                low=mid+1;
            }

        }
        return low;
    }

};

