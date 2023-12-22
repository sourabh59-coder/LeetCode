class Solution {
public:
    int maxScore(string str) {
        int result = 0;
        for (int i = 0; i < str.size() - 1; i++) {
            int currentScore = 0;
            for (int j = 0; j <= i; j++) {
                if (str[j] == '0') {
                    currentScore++;
                }
            }
            
            for (int j = i + 1; j < str.size(); j++) {
                if (str[j] == '1') {
                    currentScore++;
                }
            }
            
            result = max(result, currentScore);
        }
        
        return result;
    }
};