class Solution {
public:
    string multiply(string num1, string num2) {
         // Length of both numbers
        int n = num1.length();
        int m = num2.length();

        // Reverse strings to multiply from least significant digit
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        // Result array to store intermediate sums
        vector<int> arr(n + m + 1, 0);

        // Multiply each digit and store at correct index
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                int pro = (num1[i] - '0') * (num2[j] - '0');
                arr[i + j] += pro;
            }
        }

        // Reverse array to process carry from right to left
        reverse(arr.begin(), arr.end());

        // Handle carry for each position
        for (int i = n + m; i >= 1; i--) {
            arr[i - 1] += arr[i] / 10;
            arr[i] %= 10;
        }

        // Remove leading zeros
        int zero = 0;
        while (zero <= n + m && arr[zero] == 0)
            zero++;

        // If all digits are zero
        if (zero == n + m + 1)
            return "0";

        // Convert result array to string
        string ans = "";
        for (int i = zero; i <= n + m; i++) {
            ans += to_string(arr[i]);
        }

        return ans;
    }
};