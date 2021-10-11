class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        auto v = vector<vector<int> >(m, vector<int>());
        if (original.size() != n * m) return vector<vector<int> >();
        int cnt = -1;
        for (int i = 0; i < original.size(); i++) {
            if (i % n == 0) cnt++;
            v[cnt].push_back(original[i]);
        }
        return v;
    }
};