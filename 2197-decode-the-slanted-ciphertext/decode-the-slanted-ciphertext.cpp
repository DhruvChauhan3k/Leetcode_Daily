class Solution {
public:
       string decodeCiphertext(string s, int rows) {
           if(s.size()==0)return s;
        int n = s.size(), cols = n / rows;
        string res;
        for (int i = 0; i < cols; ++i)
            for (int j = i; j < n; j += cols + 1)
                res += s[j];
        while (res.back() == ' ')
            res.pop_back();
        return res;
    }
};