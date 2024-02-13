class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for(int i=0;i<words.size();i++)
        {
            string it=words[i];
            reverse(it.begin(),it.end());
            if(words[i]==it)return words[i];
        }
        return "";
    }
};