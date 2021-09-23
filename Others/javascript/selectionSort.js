/**
 * @file     selectionSort.js
 * @brief    selection
 * @author   Zhu
 * @date     2021-08-11 21:39
 */

/*
 * 每次选最小的元素放到头
 */
function selectionSort(array) {
    for (let i = 0; i < array.length; i++) {
        for (let j = i + 1; j < array.length; j++) {
            if (array[j] < array[i]) {
                let temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
}

/*
 * 少做无意义的交换
 */
function selectionSort(array) {
    for (let i = 0; i < array.length - 1; i++) {
        let min = i;
        for (let j = i + 1; j < array.length; j++) {
            if (array[j] < array[min]) {
                min = j;
            }
        }
        if (i !== min) {
            let temp = array[min];
            array[min] = array[i];
            array[i] = temp;
        }
    }
}
