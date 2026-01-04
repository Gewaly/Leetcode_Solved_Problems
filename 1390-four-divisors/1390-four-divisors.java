
class Solution {
    private int sumOfDivisorsIfExactlyFour(int n) {
        int cnt = 0;
        int sum = 0;

        for (int i = 1; i * i <= n; i++) {
            if (n % i == 0) {
                int j = n / i;
                if (i == j) { 
                    cnt += 1;
                    sum += i;
                } else {
                    cnt += 2;
                    sum += i + j;
                }
            }
        }
        return cnt == 4 ? sum : 0;
    }

    public int sumFourDivisors(int[] nums) {
        int ans = 0;
        for (int x : nums) {
            ans += sumOfDivisorsIfExactlyFour(x);
        }
        return ans;
    }
}