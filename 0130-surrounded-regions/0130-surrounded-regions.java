class Solution {
    int [][]dir = {{0,1}, {1,0}, {0, -1}, {-1, 0}};

    public void capture(char[][]board, int r, int c){
            if(r < 0 || c < 0 || r >= board.length || c >= board[0].length || 
            board[r][c] != 'O'){
                return;
            }

            board[r][c] = 'T';
            for(int []d: dir){
                int nr = r + d[0];
                int nc = c + d[1];
                capture(board, nr, nc);
            }
    }
    public void solve(char[][] board) {
        
        int ROWS = board.length, COLS = board[0].length;

        // 1. (DFS) capture unsurrounded regions (O -> T)

        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c] == 'O' && (r == 0 || r == ROWS - 1) ||
                (c == 0 || c == COLS - 1))
                {
                    capture(board, r, c);
                }
            }
        }
        // 2. (Double for loop) capture surrounded regions (O -> X)
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c] == 'O')
                {
                    board[r][c] = 'X';
                }
            }
        }

        // 3. uncapture unsurrounded regions (T -> O)
        for(int r = 0; r < ROWS; r++){
            for(int c = 0; c < COLS; c++){
                if(board[r][c] == 'T')
                {
                    board[r][c] = 'O';
                }
            } 
        }
    }
}
