// Copyright 2021 NNTU-CS

int countPairs1(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        for (int j = i + 1; j < len; ++j) {
            if (arr[i] + arr[j] == value) {
                ++count;
            }
        }
    }

    return count;
}

int countPairs2(int *arr, int len, int value) {
    int count = 0;
    int left = 0;
    int right = len - 1;

    while (left < right) {
        int sum = arr[left] + arr[right];

        if (sum == value) {
            int lCount = 1;
            while (left + 1 < right && arr[left] == arr[left + 1]) {
                ++lCount;
                ++left;
            }
            int rCount = 1;
            while (right - 1 > left && arr[right] == arr[right - 1]) {
                ++rCount;
                --right;
            }

            count += lCount * rCount;
            ++left;
            --right;
        } else if (sum < value) {
            ++left;
        } else {
            --right;
        }
    }

    return count;
}

int countPairs3(int *arr, int len, int value) {
    int count = 0;

    for (int i = 0; i < len; ++i) {
        int target = value - arr[i];

        int left = i + 1;
        int right = len - 1;
        int pos = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (arr[mid] == target) {
                pos = mid;
                right = mid - 1;
            } else if (arr[mid] < target) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (pos != -1) {
            int k = pos;
            while (k < len && arr[k] == target) {
                ++count;
                ++k;
            }
        }
    }

    return count;
}
