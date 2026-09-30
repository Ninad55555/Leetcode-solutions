class Solution {
public:
    int partition(vector<int>& a, int low, int high) {
        int pivot = a[high];
        int i = low - 1;
        for (int j = low; j < high; j++) {
            if (a[j] < pivot) {
                i++;
                swap(a[i], a[j]);
            }
        }
        swap(a[i + 1], a[high]);
        return i + 1;
    }

    void quickSort(vector<int>& a, int low, int high) {
        if (low < high) {
            int p = partition(a, low, high);
            quickSort(a, low, p - 1);
            quickSort(a, p + 1, high);
        }
    }

    int arrayPairSum(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        int sum = 0;
        for (int i = 0; i < nums.size(); i += 2)
            sum += nums[i];
        return sum;
    }
};

