#include<stdlib.h>
#include<stdio.h>

// Объединяет два массива в arr[].
// Первый подмассив arr[l..m]
// Второй подмассив arr[m+1..r]
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* создаем временные массивы */
    int L[n1], R[n2];

    /* копируем данные во временные массивы L[] и R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Объединяем отсортированные временные массивы в один arr[l..r]*/
    i = 0; // индекс первого подмассива
    j = 0; // индекс второго подмассива
    k = l; // индекс объединенного подмассива
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Копируем оставшиеся элементы маасива L[], если они есть */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

   /* Копируем оставшиеся элементы маасива R[], если они есть */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l - левый игдекс, r - правый */
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // Тоже, что и (l+r)/2
        int m = l+(r-l)/2;

        // Сортируем первую и вторую половину
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}
