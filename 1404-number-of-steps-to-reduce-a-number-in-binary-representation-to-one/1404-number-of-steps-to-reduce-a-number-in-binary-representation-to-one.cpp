class Solution {
public:
    int numSteps(string s) {
        int ans = 0;
        int carry = 0; // to handle the carry when adding 1 to the binary number
        for (int i = s.size() - 1; i > 0; i--) {
            if ((s[i] - '0' + carry) % 2 == 0) {
                ans++; // Even, just divide by 2 (remove the bit)
            } else {
                carry = 1; // Odd, make it even by adding 1, causing carry
                ans += 2; // Adding 1 and then divide by 2
            }
        }
        return ans + carry; // Finally add the remaining carry to the answer
    }
};
