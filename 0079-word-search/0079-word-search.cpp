class Solution {
    
    bool find( int r, int c, int i, vector<vector<char>>& edge, string& word, bool** visit ){
    if(i == word.size() ){
        return true;
    }
    if( r >= edge.size() || c >= edge[r].size() || r<0 || c<0 || i<0 || visit[r][c]){
        return false;
    }
    if( edge[r][c] == word[i] ){
        visit[r][c] = true;
        if( find( r-1, c, i+1, edge, word, visit) || find( r+1, c, i+1,edge,word,visit) ||
           find( r, c-1, i+1, edge, word, visit) || find( r, c+1, i+1, edge,word,visit)){
            return true; 
        }
        visit[r][c] = false;
    }
    
    return false;
}
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size();
        int m = board[0].size();
    bool**visited = new bool*[n];
    for(int i=0;i<n;i++){
        visited[i] = new bool[m];
        for(int j=0;j<m; j++){
            visited[i][j] = false;
        }
    }

    for(int i=0; i<n; i++ ){
        for (int j=0; j<m; j++){
            if(board[i][j]==word[0] && !visited[i][j] &&
                                     find(i ,j, 0, board, word, visited) ){
                  return true;
              }
        }
    }
        
    return false;
    }
};