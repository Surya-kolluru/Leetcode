int numOfSubarrays(int* arr, int arrSize) {
    long long mod = 1000000007;
    long long odd = 0, even = 1, ans = 0;
    int sum = 0;

    for (int i = 0; i < arrSize; i++) {
        sum += arr[i];

        if (sum % 2 == 1) {
            ans = (ans + even) % mod;
            odd++;
        } else {
            ans = (ans + odd) % mod;
            even++;
        }
    }

    return (int)ans;
}