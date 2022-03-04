int maxHouse_DP(int *arr, int n, int i)
{
    int *output = new int[n + 1];
    output[n] = 0;
    for (int i = n; i >= 0; i--)
    {
        output[i] = max(output[i] + output[i + 2], output[i + 1]);
    }
    return output[i];
}
int helper(vector<int> &nums, int n, int *output, int i)
{
    if (i >= n)
    {
        return 0;
    }
    if (output[i] != -1)
    {
        return output[i];
    }
    return output[i] = max(nums[i] + helper(nums, n, output, i + 2), helper(nums, n, output, i + 1));
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    int *output = new int[n + 1];
    for (int i = 0; i <= n; i++)
    {
        output[i] = -1;
    }
    return helper(nums, n, output, 0);
}
int maxMoneyLooted(int *arr, int n)
{
    // Write your code here
    int *output = new int[n + 1];
    output[0] = 0;
    output[1] = arr[0];
    for (int i = 2; i <= n; i++)
    {
        output[i] = max(arr[i - 1] + output[i - 2], output[i - 1]);
    }
    return output[n];
}