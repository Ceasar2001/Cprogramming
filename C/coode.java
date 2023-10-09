public class coode {
    public static boolean perfect(int n) {
        boolean[] prime = new boolean[n + 1];
        for (int i = 2; i <= n; i++) {
            prime[i] = true;
        }

        for (int p = 2; p * p <= n; p++) {
            if (prime[p]) {
                for (int i = p * p; i <= n; i += p) {
                    prime[i] = false;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (!prime[i]) {
                continue;
            }

            int target = n - i;
            if (isPerfectSquare(target) && prime[target]) {
                return true;
            }
        }

        return false;
    }

    private static boolean isPerfectSquare(int num) {
        int sqrt = (int) Math.sqrt(num);
        return sqrt * sqrt == num;
    }

    public static void main(String[] args) {
        int n = 25;
        boolean perfectSquare = perfect(n);
        System.out.println("Does a perfect square exist that can be expressed as the sum of two primes?: " + perfectSquare);
    }
}
