class Solution {
public:
    int get(int index,MountainArray &m){
        if(index==-1 || index==m.length()) return 0;
        return m.get(index);
    }
    
    int leftbs(int l,int r,int target,MountainArray & m){
        if(l>r) return -1;
        int mid=l+(r-l)/2;
        int midval=get(mid,m);
        if(midval==target) return mid;
        if(target<midval) return leftbs(l,mid-1,target,m);
        return leftbs(mid+1,r,target,m);
        

    }
    int rightbs(int l,int r,int target,MountainArray & m){
        if(l>r) return -1;
        int mid=l+(r-l)/2;
        int midval=get(mid,m);
        if(midval==target) return mid;
        if(target>midval) return leftbs(l,mid-1,target,m);
        return leftbs(mid+1,r,target,m);
    }

    int bs(int l,int r,MountainArray & m){
        int mid=l+(r-l)/2;
        int midval=get(mid,m);
        int leftval=get(mid-1,m);
        int rightval=get(mid+1,m);
        if( midval>rightval && midval >leftval ){
            return mid;
            
        }
        if(leftval<midval && midval<rightval){
            return bs(mid+1,r,m);

        }
        if(leftval>midval && midval>rightval){
            return bs(l,mid-1,m);
        }
        return -1;
    }
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peak=bs(0,mountainArr.length()-1,mountainArr);
        if(get(peak,mountainArr)==target) return peak;
        int ans=-1;
        ans=max(ans,leftbs(0,peak-1,target,mountainArr));
        if(ans==-1) return rightbs(peak+1,mountainArr.length()-1,target,mountainArr);
        return ans;

        
    }
};
