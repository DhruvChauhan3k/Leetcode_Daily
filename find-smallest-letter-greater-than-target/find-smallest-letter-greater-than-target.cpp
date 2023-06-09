class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char t) {
        // sort(letter.begin(),letters.end());
        for(auto it:letters)
        {
            if(it>t)return it;
        }
        return letters[0];
    }
};