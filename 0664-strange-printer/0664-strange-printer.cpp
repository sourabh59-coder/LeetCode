class Solution {
    
private:
    string s;
    int answer[100][100];
    
	/* Find minimum number of turns the printer will need in order to print the string from index i to index j */
    int find(int i, int j)
    {
		/* I don't need to explain this */
        if(answer[i][j] != -1)
            return answer[i][j];
        
        if(s[j-1] == s[j] || s[i] == s[j])
        {
            /* A clear optimization here would be that if sj-1 == sj or si == sj, then Solution[i][j] = Solution[i][j-1] */
            answer[i][j] = find(i, j-1);
        }
        else if(s[i] == s[i+1])
        {
            /* Another optimization here would be that if si+1 == si, then Solution[i][j] = Solution[i+1][j] */
            answer[i][j] = find(i+1, j);
        }
        else
        {
			/* PossibleSolution[i][j] = Solution[i][j-1] + 1 */
            answer[i][j] = find(i, j-1) + 1;
            
            for(int k = i+1; k < j; ++k)
            {
                if(s[k] == s[j])
                {
					/* PossibleSolution[i][j] = Solution[i][k-1] (solution to print the string starting at index i and ending at k-1) + Solution[k, j-1] (solution to print the string starting at index k and ending at j-1) */
                    answer[i][j] = min(answer[i][j], find(i, k-1) + find(k, j-1));
                }
            }
        }
        
        return answer[i][j];
    }
    
public:
    int strangePrinter(string s) 
    {
        if(s.length() == 0)
            return 0;
        
        this->s = std::move(s);
        
        for(int i = 0 ; i < this->s.length(); ++i)
        {
            for(int j = 0 ; j < this->s.length(); ++j)
            {
                if(i==j)
                    answer[i][j] = 1;
                else
                    answer[i][j] = -1;
            }
        }
        
        return find(0, this->s.length()-1);
    }
};