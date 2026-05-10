class NumArray {
public:
    vector<int> tree;
    vector<int> nums;
    int n;
    int query(int index,int left, int right, int qleft,int qright){
        if(qleft>right || qright<left) return 0;
        if(left>=qleft && right<=qright) return tree[index];
        
        int ans=0;
        int mid=(left+right)/2;
        ans+=query(2*index+1,left,mid,qleft,qright);
        ans+=query(2*index+2,mid+1,right,qleft,qright);
        return ans;
    }
    void build(int idx, int left, int right){
        if(left==right){
            tree[idx]=nums[left];
            return;
        }
        int mid=(left+right)/2;
        build(2*idx+1,left,mid);
        build(2*idx+2,mid+1,right);

        tree[idx]=tree[2*idx+1]+tree[2*idx+2];

    }
    void updatee(int idx,int left,int right, int pos,int val){
        if(left==right){
            tree[idx]=val;
            nums[left]=val;
            return;
        }
        int mid=(left+right)/2;
        if(pos<=mid){
            updatee(2*idx+1,left,mid,pos,val);
        }
        else{
            updatee(2*idx+2,mid+1,right,pos,val);
        }
        tree[idx]=tree[2*idx+1]+tree[2*idx+2];
    }
    NumArray(vector<int>& nums) {
        this->nums=nums;
        this->n=nums.size();
        tree.resize(4*n,0);
        build(0,0,n-1);
    }
    
    void update(int index, int val) {
        updatee(0,0,n-1,index,val);

    }
    
    int sumRange(int left, int right) {
        return query(0,0,nums.size()-1,left,right);
        
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
