unordered_map<char,int>freqChar;
    static bool comp(char&a,char&b)
    {
        if(freqChar[a]==freqChar[b])return a>b;
        return freqChar[a]>freqChar[b];
    }

class Solution {
public:
    
    string frequencySort(string s) {
        freqChar.clear();
        for(auto it:s)
        {
            freqChar[it]++;
        }
        sort(s.begin(),s.end(),comp);
        return s;
    }
};