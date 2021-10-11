class Solution {
public:
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            int pos1 = 0, cur = 0;
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == ' ') {
                    pos1++;
                    cur++;
                } else if (islower(board[i][j])) {
                    if (board[i][j] == word[pos1]) {
                        pos1++;
                        cur++;
                    } else {
                        pos1 = cur = 0;
                    }
                } else { pos1 = cur = 0; }
                if (pos1 == word.length()) {
                    if ((j == board[0].size() - 1 || board[i][j + 1] == '#') && (j - pos1 + 1 == 0 || board[i][j - pos1] == '#')) {
                        cout << 1 << " " << i << " " << j << endl;
                        return 1;
                    }
                    else {
                        pos1 = cur = 0;
                    }
                }
            }
        }
        cout << "1 finish" << endl;
        for (int i = 0; i < board.size(); i++) {
            int pos1 = 0, cur = 0;
            for (int j = board[0].size() - 1; j >= 0; j--) {
                if (board[i][j] == ' ') {
                    pos1++;
                    cur++;
                } else if (islower(board[i][j])) {
                    if (board[i][j] == word[pos1]) {
                        pos1++;
                        cur++;
                    } else {
                        pos1 = cur = 0;
                    }
                } else { pos1 = cur = 0; }
                if (pos1 == word.length()) {
                    if ((j == 0 || board[i][j - 1] == '#') && (j + pos1 - 1 == board[0].size() - 1 || board[i][j + pos1] == '#')) {
                        cout << 2 << " " << i << " " << j << endl;
                        return 1;
                    }
                    else {
                        pos1 = cur = 0;
                    }
                }
            }
        }
        cout << "2 finish" << endl;
        for (int j = 0; j < board[0].size(); j++) {
            int pos1 = 0, cur = 0;
            for (int i = 0; i < board.size(); i++) {
                if (board[i][j] == ' ') {
                    pos1++;
                    cur++;
                } else if (islower(board[i][j])) {
                    if (board[i][j] == word[pos1]) {
                        pos1++;
                        cur++;
                    } else {
                        pos1 = cur = 0;
                    }
                } else { pos1 = cur = 0; }
                if (pos1 == word.length()) {
                    if ((i == board.size() - 1 || board[i + 1][j] == '#') && (i - pos1 + 1 == 0 || board[i - pos1][j] == '#')) {
                        cout << 3 << " " << i << " " << j << endl;
                        return 1;
                    }
                    else {
                        pos1 = cur = 0;
                    }
                }
            }
        }
        cout << "3 finish" << endl;
        for (int j = 0; j < board[0].size(); j++) {
            int pos1 = 0, cur = 0;
            for (int i = board.size() - 1; i >= 0; i--) {
                if (board[i][j] == ' ') {
                    pos1++;
                    cur++;
                } else if (islower(board[i][j])) {
                    if (board[i][j] == word[pos1]) {
                        pos1++;
                        cur++;
                    } else {
                        pos1 = cur = 0;
                    }
                } else { pos1 = cur = 0; }
                if (pos1 == word.length()) {
                    if ((i == 0 || board[i - 1][j] == '#') && (i + pos1 - 1 == board.size() - 1 || board[i + pos1][j] == '#')) {
                        cout << 4 << " " << i << " " << j << endl;
                        return 1;
                    }
                    else {
                        pos1 = cur = 0;
                    }
                }
            }
        }
        cout << "4 finish" << endl;
        return 0;
    }
};