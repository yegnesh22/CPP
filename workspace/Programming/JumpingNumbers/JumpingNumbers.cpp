#include <iostream>
#include <queue>

using namespace std;

class Solution {
public:
    long long m_msp;
    long long m_X;

    long long genJNumber()
    {
        queue<long long> q;
        long  long maxJn;
        long long i;

        q.push(m_msp);
        if (msp != 1)
            q.push(m_msp - 1);
        else
            q.push(9);

        while (!q.empty()) {
            long long num = q.front();
            q.pop();

            if (num <= m_X) {
                maxJn = max(num, maxJn);
                int lastdigit = num % 10;

                if (lastdigit == 0) {
                    q.push(((num * 10) + (lastdigit + 1)));
                }
                else if (lastdigit == 9) {
                    q.push(((num * 10) + (lastdigit - 1)));
                }
                else {
                    q.push(((num * 10) + (lastdigit - 1)));
                    q.push(((num * 10) + (lastdigit + 1)));
                }
            }
        }
        return maxJn;
    }

    long long jumpingNums(long long X) {
        
        bool isSelfJumping = true;
        long long jNumber;
        long long i, k;
        int d1, d2;

        k = 1;
        for (i = X; i > 0; i /= 10, k *= 10) {
            if (isSelfJumping == true) {
                if (k == 1) {
                    d2 = i % 10;
                }
                else {
                    d1 = i % 10;
                    if (abs(d1 - d2) != 1)
                        isSelfJumping = false;
                    d2 = d1;
                }
            }
        }
        m_msp = X / (k / 10);

        if (isSelfJumping == true)
            return X;
        m_X = X;
        return genJNumber();
    }
};

int main()
{
    Solution s;
    long long X;

    cin >> X;
    cout << s.jumpingNums(X) << endl;
    return 0;
}