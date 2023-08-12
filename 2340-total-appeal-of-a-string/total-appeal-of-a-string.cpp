class Solution {
public:
    
    // counting number of substrings that have atleast one char ch
    // total substrings - count of substrings with no char as ch
    long long int count(string st,char ch){ 
        
        long long int len=st.length();
        long long int res=0;
        long long int cnt=0;
        for(long int i=0;i<len;i++){
            
            if(st[i]==ch){
                res+=((cnt)*(cnt+1))/2;
                cnt=0;
            }
            
            else
                cnt++;
        }
        
        res+=((cnt)*(cnt+1))/2;
        return (len*(len+1))/2 - res;
    }
    
    long long appealSum(string st) {
        
        long long int total_cnt=0;
        for(char ch='a';ch<='z';ch++)
            total_cnt+=count(st,ch);
        
        return total_cnt;
    }
};