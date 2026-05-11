class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> mpp;   // numbers to indexes
    vector<int> arr;
    int n;
    RangeFreqQuery(vector<int>& arr) {
        this->arr=arr;
         this->n=arr.size();
        for(int i=0 ; i<n; i++){
            mpp[arr[i]].push_back(i);
        }

    
        
    }
    
    int query(int left, int right, int value) {
        return upper_bound(mpp[value].begin(), mpp[value].end(), right)
     - lower_bound(mpp[value].begin(), mpp[value].end(), left);
        
    }
};
