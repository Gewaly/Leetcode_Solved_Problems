/**
 * @param {character[][]} board
 * @param {string} word
 * @return {boolean}
 */
var exist = function(board, word) {
    const rows = board.length;
    const cols = board[0].length;
    
    const isValidCell = (i, j) => i >= 0 && j >= 0 && i < rows && j < cols;
    
    const dfs = (i, j, k) => {
        if (!isValidCell(i, j) || board[i][j] !== word[k]) {
            return false;
        }
        if (k === word.length - 1) return true;
        
        const temp = board[i][j];
        board[i][j] = '*';
        
        const found = dfs(i + 1, j, k + 1) || dfs(i - 1, j, k + 1) || dfs(i, j + 1, k + 1) || dfs(i, j - 1, k + 1);
        
        board[i][j] = temp;
        return found;
    };
    
    for (let i = 0; i < rows; i++) {
        for (let j = 0; j < cols; j++) {
            if (dfs(i, j, 0)) {
                return true;
            }
        }
    }
    
    return false;
};