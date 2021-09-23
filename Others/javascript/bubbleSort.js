/**
 * @file     bubbleSort.js
 * @brief    bubble
 * @author   Zhu
 * @date     2021-08-11 21:17
 */

/*
 * 相邻元素两两比较，大的往后冒泡
 */
function bubbleSort(array) {
    for (let i = 0; i < array.length - 1; i++) {
        let sorted = true;
        for (let j = 1; j < array.length - i; j++) {
            if (array[j - 1] > array[j]) {
                let temp = array[j];
                array[j] = array[j - 1];
                array[j - 1] = temp;
                sorted = false;
            }
        }
        if (sorted) return;
    }
}
