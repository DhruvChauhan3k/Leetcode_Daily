class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        vector<int>left(n,1e9);
        int prev=-1;
        if(seats[0]==1){
            left[0]=0;
            prev=0;
        }
        for(int i=1;i<n;i++){
            if(seats[i]==1){
                prev=i;
                left[i]=0;
            }
            else{
                left[i]=i-prev;
            }
        }
        vector<int>right(n,1e9);
        prev=n;
        if(seats[n-1]==1){
            right[n-1]=0;
            prev=n-1;
        }
        for(int i=n-2;i>=0;i--){
            if(seats[i]==1){
                prev=i;
                right[i]=0;
            }
            else{
                right[i]=prev-i;
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,min(left[i],right[i]));
        }
        return ans;
    }
};