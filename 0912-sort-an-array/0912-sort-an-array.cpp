class Solution {
public:
    void quickSort(vector<int>& nums, int low, int high) {
        if (low >= high)
            return;

        // Random pivot
        int pivotIndex = low + rand() % (high - low + 1);

        // Move pivot to end manually
        int temp = nums[pivotIndex];
        nums[pivotIndex] = nums[high];
        nums[high] = temp;

        int pivot = nums[high];
        int i = low - 1;

        for (int j = low; j < high; j++) {
            if (nums[j] < pivot) {
                i++;

                // Manual swap
                temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
            }
        }

        // Put pivot in correct position
        temp = nums[i + 1];
        nums[i + 1] = nums[high];
        nums[high] = temp;

        int p = i + 1;

        quickSort(nums, low, p - 1);
        quickSort(nums, p + 1, high);
    }

    vector<int> sortArray(vector<int>& nums) {
        quickSort(nums, 0, nums.size() - 1);
        return nums;
    }
};
