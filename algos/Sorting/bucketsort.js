function sort (arr) {
    // insertion sort to sort individual buckets

    for (let i = 1; i < arr.length; i++) {
        let x = arr[i];
        let j = i - 1;

        while (j >= 0 && arr[j] > x) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = x;
    }
}

function bucketSort (arr) {
    let buckets = [];

    for (let i = 0; i < arr.length; i++) {
        if (!buckets[parseInt(arr[i]/10)]) buckets[parseInt(arr[i]/10)] = [];

        buckets[parseInt(arr[i]/10)].push(arr[i]);
    }

    let sortedArr = [];

    for (let j = 0; j < buckets.length; j++) {
        if (buckets[j]) {
            sort(buckets[j]);
            sortedArr = sortedArr.concat(buckets[j]);
        }
    }

    return sortedArr;
}

let array = [15, 65, 54, 53, 23, 34, 37, 60];

console.log(bucketSort(array));