/**
 * @file     insertionSort.js
 * @brief    insertion
 * @author   Zhu
 * @date     2021-08-11 22:01
 */

// 两两交换，相邻比
function insertionSort(array) {
    for (let i = 1; i < array.length; i++) {
        const cur = array[i];
        let j = i;
        while (j > 0 && array[j - 1] > array[j]) {
            array[j] = array[j - 1];
            array[j - 1] = cur;
            j--;
        }
    }
}

// 挖坑最后填
function insertionSort(array) {
    for (let i = 1; i < array.length; i++) {
        const cur = array[i];
        let j = i;
        while (j > 0 && array[j - 1] > cur) {
            array[j] = array[j - 1];
            j--;
        }
        array[j] = cur;
    }
}

// 判断条件在内部
function insertionSort(arr) {
    for (let i = 1; i < arr.length; i++) {
        const cur = arr[i];
        let j = i;
        while (j--) {
            if (cur < arr[j]) {
                arr[j + 1] = arr[j];
            } else {
                break;
            }
        }
        arr[j + 1] = cur;
    }
}
