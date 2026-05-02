class Solution {
public:
    int transform(int a){
        if(a==0 || a==1 || a==8) return a;
        if(a==2) return 5;
        if(a==5) return 2;
        if(a==6) return 9;
        if(a==9) return 6;
        return a;

    }

    bool isgood(int k){
        int val=0;  
        int comp=k;
        stack<int> stk;
        int digits=0;
        while(k/10!=0){
            stk.push(k%10);
            k=k/10;
            digits++;
        }
        stk.push(k);
        while(!stk.empty()){
            int temp=stk.top();
            stk.pop();
            if (temp==3 || temp==7 || temp==4) return false;
            val+=transform(temp)* pow(10,digits);
            digits--;

        }
        if(val==comp) return false;
        return true;

    }
    int rotatedDigits(int n) {
        int ans=0;
        for(int i=1 ; i<=n ; i++){
            if(isgood(i)){
                cout<<i<<" ";
                ans++;
            }

        }
        return ans;
        
    }
};
