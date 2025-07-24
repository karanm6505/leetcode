bool isValidSudoku(char** board, int boardSize, int* boardColSize) {
    bool rows[9][9] = {false};
    bool cols[9][9] = {false};
    bool boxes[9][9] = {false};

    for (int i = 0; i < boardSize; i++) 
    {
        for (int j = 0; j < boardColSize[i]; j++) 
        {
            char c = board[i][j];
            if (c != '.') 
            {
                int num = c - '1';
                int box_index = (i / 3) * 3 + (j / 3);

                if (rows[i][num] || cols[j][num] || boxes[box_index][num]) 
                {
                    return false;
                }

                rows[i][num] = true;
                cols[j][num] = true;
                boxes[box_index][num] = true;
            }
        }
    }
    return true;
}
