class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        auto sum = vector<int>(answerKey.length(), 0);
        auto sum2 = vector<int>(answerKey.length(), 0);
        sum[0] = answerKey[0] == 'T' ? 1 : 0;
        sum2[0] = answerKey[0] == 'F' ? 1 : 0;
        for (int i = 1; i < answerKey.length(); i++) {
            sum[i] = sum[i - 1] + (answerKey[i] == 'T' ? 1 : 0);
            sum2[i] = sum2[i - 1] + (answerKey[i] == 'F' ? 1 : 0);
        }
        int ans1 = 0;
        int ans2 = 0;
        for (int i = 0; i < answerKey.length(); i++) {
                if (answerKey[i] == 'T') {
                    auto pos = upper_bound(sum2.begin() + i, sum2.end(), sum2[i] + k);
                    if (pos == sum2.end()) ans1 = max(ans1, (int) answerKey.length() - i);
                    else {
                        ans1 = max(ans1, (int) (pos - (sum2.begin() + i)));
                    }
                    auto pos2 = upper_bound(sum.begin() + i, sum.end(), sum[i] + k - 1);
                    if (pos2 == sum.end()) ans1 = max(ans1, (int) answerKey.length() - i);
                    else {
                        ans1 = max(ans1, (int) (pos2 - (sum.begin() + i)));
                    }
                } else {
                    auto pos = upper_bound(sum.begin() + i, sum.end(), sum[i] + k);
                    // cout << i << " " << pos - (sum.begin() + i) << endl;
                    if (pos == sum.end()) ans2 = max(ans2, (int) answerKey.length() - i);
                    else {
                        ans2 = max(ans2, (int) (pos - (sum.begin() + i)));
                    }
                    auto pos2 = upper_bound(sum2.begin() + i, sum2.end(), sum2[i] + k - 1);
                    // cout << i << " " << pos - (sum2.begin() + i) << endl;
                    if (pos2 == sum2.end()) ans1 = max(ans1, (int) answerKey.length() - i);
                    else {
                        ans1 = max(ans1, (int) (pos2 - (sum2.begin() + i)));
                    }
                }
        }
        return max(ans1, ans2);
    }
};