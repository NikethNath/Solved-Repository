class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int earliest_land_time=1e9;
        int earliest_water_time=1e9;
        int land_ans=1e9;
        int water_ans=1e9;
        int n=landStartTime.size();
        int m=waterStartTime.size();
        for(int i=0 ; i<n ; i++){
            earliest_land_time=min(earliest_land_time,landStartTime[i]+landDuration[i]);
        }
        for(int j=0 ; j<m ; j++){
            earliest_water_time=min(earliest_water_time,waterStartTime[j]+waterDuration[j]);

        }
        for(int j=0 ; j<m ; j++){
            if(waterStartTime[j]>=earliest_land_time){
                land_ans=min(land_ans,waterStartTime[j]+waterDuration[j]);

            }
            else{
                land_ans=min(land_ans,earliest_land_time+waterDuration[j]);
            }
        } 

        for(int i=0 ; i<n ; i++){
            if(landStartTime[i]>=earliest_water_time ){
                water_ans=min(water_ans,landStartTime[i]+landDuration[i]);
            }
                else{
                    water_ans=min(water_ans,earliest_water_time+landDuration[i]);
                }

            }
        
        return min(land_ans,water_ans); 



        
    }
};
