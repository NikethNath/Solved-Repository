class Solution {
public:
static bool comp(vector<int>& a, vector<int>& b) {
    return (a[1] - a[0]) > (b[1] - b[0]);
}
    bool cancomplete(int energy,vector<vector<int>>& tasks){
        int energey=energy;
        for(auto task : tasks){
            if(task[1]>energey) return false;
            energey-=task[0];

        }
        return true;
    }
    int bs(int low,int high,vector<vector<int>> & tasks){
        int lowe=low;
        int highe=high;
        while(lowe<=highe){
            int mid=(highe+lowe)/2;
            if(cancomplete(mid,tasks)){
                highe=mid-1;
            }
            else{
                lowe=mid+1;
            }
        }
        return lowe;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int lowerbound=0;
        int upperbound=0;
        sort(tasks.begin(),tasks.end(),comp);
        for(auto task : tasks){
            cout<<"["<<task[0]<<","<<task[1]<<"]";
        }
        for(auto task : tasks){
            lowerbound+=task[0];
            upperbound+=task[1];
        }
        return bs(lowerbound,upperbound,tasks);
        
    }
};
