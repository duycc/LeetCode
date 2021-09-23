/**
 * @file     quickSort.js
 * @brief    quick sort
 * @author   Zhu
 * @date     2021-08-12 23:35
 */

function quickSort(arr, start, end) {
    if (start >= end) return;

    let left = start;
    let right = end;
    let key = arr[left];
    while (left < right) {
        while (left < right && arr[right] >= key) {
            right--;
        }
        if (left < right) {
            arr[left] = arr[right];
        }
        while (left < right && arr[left] <= key) {
            left++;
        }
        if (left < right) {
            arr[right] = arr[left];
        }
    }
    arr[left] = key; // 至此，本轮排序以key为分界线左小右大
    quickSort(arr, start, left - 1);
    quickSort(arr, right + 1, end);
}