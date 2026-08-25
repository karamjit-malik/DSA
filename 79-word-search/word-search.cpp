class Solution {
public:
vector<vector<int>> dp;
bool dfs(const string& s , int i , int j , int idx , vector<vector<char>>& board)
{
    if(idx == s.size())
    return true;
    int n = board.size();
    int m = board[0].size();
    if(i<0 || j<0 || i>=n || j>=m)
    return false;
    if(board[i][j]!=s[idx])
    return false;
    char temp = board[i][j];
    board[i][j] = '#';
    bool found = dfs(s,i+1,j,idx+1,board) || dfs(s,i,j+1,idx+1,board)
    || dfs(s,i-1,j,idx+1,board) || dfs(s,i,j-1,idx+1,board);
    board[i][j] = temp;
    return found;
}
    bool exist(vector<vector<char>>& board, string word)
    {
        int n = board.size();
        int m = board[0].size();
        dp.resize(n,vector<int>(m,-1));
        for(int i = 0 ; i<n ; i++)
        {
            for(int j = 0 ; j<m ; j++)
            {
                if(dfs(word,i,j,0,board))
                return true;
            }
        }
        return false;
    }
};