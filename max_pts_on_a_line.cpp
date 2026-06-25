class Solution {
public:
    double findslope(vector<int> &p1 , vector<int> &p2){
        if(p1[0]-p2[0]==0) return 1e9;
        return (p1[1]-p2[1])/(1.00*(p1[0]-p2[0]));
    }
    int maxPoints(vector<vector<int>>& points) {
        int ans=0;
        if(points.size()<=2) return points.size();
        for(int i=0 ; i<points.size() ; i++){
            for(int j=i+1 ; j<points.size() ; j++){
                double slope=findslope(points[i],points[j]);
                int tempans=2;
                for(int k=0 ; k<points.size() ; k++){
                    if(k==i || k==j){
                        continue;
                    }
                    double newslope=findslope(points[k],points[j]);

                    if(newslope==slope)tempans++;
                    
                }
                ans=max(ans,tempans);
            }
        }
        return ans;
        
    }
};
