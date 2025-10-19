class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadendSet(deadends.begin(), deadends.end());
        if (deadendSet.count("0000")) {
            return -1;
        }
        
        queue<pair<string, int>> queue;
        queue.push({"0000", 0});
        deadendSet.insert("0000");
        
        while (!queue.empty()) {
            auto current = queue.front();
            queue.pop();
            string currentCombination = current.first;
            int moves = current.second;
            
            if (currentCombination == target) {
                return moves;
            }
            
            for (int i = 0; i < 4; i++) {
                for (int delta : {-1, 1}) {
                    int newDigit = (currentCombination[i] - '0' + delta + 10) % 10;
                    string newCombination = currentCombination;
                    newCombination[i] = '0' + newDigit;
                    
                    if (deadendSet.find(newCombination) == deadendSet.end()) {
                        deadendSet.insert(newCombination);
                        queue.push({newCombination, moves + 1});
                    }
                }
            }
        }
        
        return -1; // Target is not reachable
    }
};