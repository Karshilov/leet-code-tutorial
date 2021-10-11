impl Solution {

    fn dfs(board: &mut Vec<Vec<char>>, col: &mut Vec<i32>, row: &mut Vec<i32>, grid: &mut Vec<i32>, dots: &Vec<i32>, pos: usize)->u8 {
        if board.iter().filter(|&x| (*x).iter().filter(|&d| *d == '.').next() != None).next() == None { 1 }
        else {
            let i = (dots[pos] / 9) as usize;
            let j = (dots[pos] % 9) as usize;
            for dgt in 1..10 {
                if (col[i] & (1 << dgt) == 0) && 
                    (row[j] & (1 << dgt) == 0) &&
                    (grid[i / 3 * 3 + j / 3] & (1 << dgt) == 0) {
                        board[i][j] = ('0' as u8 + dgt as u8) as char;
                        col[i] = col[i] | (1 << dgt);
                        row[j] = row[j] | (1 << dgt);
                        grid[i / 3 * 3 + j / 3] = grid[i / 3 * 3 + j / 3] | (1 << dgt);
                        let res = Solution::dfs(board, col, row, grid, dots, pos + 1);
                        if res == 1 { return 1; }
                        else {
                            board[i][j] = '.';
                            col[i] = col[i] - (1 << dgt);
                            row[j] = row[j] - (1 << dgt);
                            grid[i / 3 * 3 + j / 3] = grid[i / 3 * 3 + j / 3] - (1 << dgt);
                        }
                    }
            }
            0
        }
    }

    pub fn solve_sudoku(board: &mut Vec<Vec<char>>) {
        let mut col: Vec<i32> = vec![0, 0, 0, 0, 0, 0, 0, 0, 0];
        let mut row: Vec<i32> = vec![0, 0, 0, 0, 0, 0, 0, 0, 0];
        let mut grid: Vec<i32> = vec![0, 0, 0, 0, 0, 0, 0, 0, 0];
        let mut dots: Vec<i32> = vec![];
        for i in 0..9 {
            for j in 0..9 {
                if board[i][j] == '.' { dots.push(i as i32 * 9 + j as i32); }
                else {
                    let dgt = board[i][j] as u8 - '0' as u8;
                    board[i][j] = ('0' as u8 + dgt as u8) as char;
                    col[i] = col[i] | (1 << dgt);
                    row[j] = row[j] | (1 << dgt);
                    grid[i / 3 * 3 + j / 3] = grid[i / 3 * 3 + j / 3] | (1 << dgt);
                }
            }
        }
        Solution::dfs(board, &mut col, &mut row, &mut grid, &mut dots, 0);
    }
}