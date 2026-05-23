class Solution {
public:
    bool canload(int capacity, vector<int> &weights,int days){
        int day=1;
        int load=0;
        for(int w : weights){
            if(load+w<=capacity){
                load=load+w;
            }
            else{
                load=w;
                day++;
                if(day>days) return false;
            }
        }
        return true;
    }
    int bs(int l, int r, vector<int> &weights, int days){
        if(l==r) return l;
        int mid=l+(r-l)/2;
        bool loadornot=canload(mid,weights,days);
        if(loadornot){
            return bs(l,mid,weights,days);
        }
        if(!loadornot){
            return bs(mid+1,r,weights,days);
        }
        return -1;


    }

    int shipWithinDays(vector<int>& weights, int days) {
        int sum=accumulate(weights.begin(),weights.end(),0);
        int maxwt=0;
        for(int a : weights){

            maxwt=max(maxwt,a);

        }
        return bs(maxwt,sum,weights,days);
        
    }
};
