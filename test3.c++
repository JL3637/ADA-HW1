#include<stdio.h>
#include<stdlib.h>
#include<algorithm>
using namespace std;

typedef struct city{
    long long x;
    long long y;
}city;

void merge(city *cities, int left, int mid, int right){
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    long long leftArray[subArrayOne];
    long long rightArray[subArrayTwo];
    long long leftArray_y[subArrayOne];
    long long rightArray_y[subArrayTwo];

    for(int i = 0; i < subArrayOne; i++){
        leftArray[i] = (cities+(left + i))->x;
        leftArray_y[i] = (cities+(left + i))->y;
    }
    for (int j = 0; j < subArrayTwo; j++){
        rightArray[j] = (cities+(mid + 1 + j))->x;
        rightArray_y[j] = (cities+(mid + 1 + j))->y;
    }

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if(leftArray[indexOfSubArrayOne] < rightArray[indexOfSubArrayTwo]){
            (cities+indexOfMergedArray)->x = leftArray[indexOfSubArrayOne];
            (cities+indexOfMergedArray)->y = leftArray_y[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else if(leftArray[indexOfSubArrayOne] == rightArray[indexOfSubArrayTwo]){
            if(leftArray_y[indexOfSubArrayOne] <= rightArray_y[indexOfSubArrayTwo]){
                (cities+indexOfMergedArray)->x = leftArray[indexOfSubArrayOne];
                (cities+indexOfMergedArray)->y = leftArray_y[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
            else{
                (cities+indexOfMergedArray)->x = rightArray[indexOfSubArrayTwo];
                (cities+indexOfMergedArray)->y = rightArray_y[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
        else{
            (cities+indexOfMergedArray)->x = rightArray[indexOfSubArrayTwo];
            (cities+indexOfMergedArray)->y = rightArray_y[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    while(indexOfSubArrayOne < subArrayOne) {
        (cities+indexOfMergedArray)->x = leftArray[indexOfSubArrayOne];
        (cities+indexOfMergedArray)->y = leftArray_y[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        (cities+indexOfMergedArray)->x = rightArray[indexOfSubArrayTwo];
        (cities+indexOfMergedArray)->y = rightArray_y[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort(city *cities, int begin, int end){
    if(begin >= end){
        return;
    }
    int mid = begin + (end - begin) / 2;
    mergeSort(cities, begin, mid);
    mergeSort(cities, mid + 1, end);
    merge(cities, begin, mid, end);
}

void merge_y(city *cities, int left, int mid, int right, long long *num){
    int subArrayOne = mid - left + 1;
    int subArrayTwo = right - mid;

    long long leftArray_y[subArrayOne];
    long long rightArray_y[subArrayTwo];

    for(int i = 0; i < subArrayOne; i++){
        leftArray_y[i] = (cities+(left + i))->y;
    }
    for (int j = 0; j < subArrayTwo; j++){
        rightArray_y[j] = (cities+(mid + 1 + j))->y;
    }

    int indexOfSubArrayOne = 0;
    int indexOfSubArrayTwo = 0;
    int indexOfMergedArray = left;
    while(indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo){
        if(leftArray_y[indexOfSubArrayOne] <= rightArray_y[indexOfSubArrayTwo]){
            (cities+indexOfMergedArray)->y = leftArray_y[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else{
            (cities+indexOfMergedArray)->y = rightArray_y[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
            *num += subArrayOne - indexOfSubArrayOne;
        }
        indexOfMergedArray++;
    }
    while(indexOfSubArrayOne < subArrayOne) {
        (cities+indexOfMergedArray)->y = leftArray_y[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    while (indexOfSubArrayTwo < subArrayTwo) {
        (cities+indexOfMergedArray)->y = rightArray_y[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
}

void mergeSort_y(city *cities, int begin, int end, long long *num){
    if(begin >= end){
        return;
    }
    int mid = begin + (end - begin) / 2;
    mergeSort_y(cities, begin, mid, num);
    mergeSort_y(cities, mid + 1, end, num);
    merge_y(cities, begin, mid, end, num);
}

int main(){
    long long n;
    scanf("%lld", &n);
    long long l1, l2, r1, r2;
    scanf("%lld%lld%lld%lld", &l1, &l2, &r1, &r2);
    city *cities = (city *)malloc(sizeof(city)*n);
    for(int i = 0; i < n; i++){
        scanf("%lld%lld", &(cities+i)->x, &(cities+i)->y);
    }
    for(int i = 0; i < n; i++){
        long long a = (cities+i)->x;
        long long b = (cities+i)->y;
        (cities+i)->x = r1 * a - r2 * b;
        (cities+i)->y = l2 * b - l1 * a;
    }

    mergeSort(cities, 0, n-1);
    long long inv_cnt = 0;
    mergeSort_y(cities, 0, n-1, &inv_cnt);
    long long ans = n * (n-1) / 2 - inv_cnt;

    printf("%lld", ans);

    return 0;
}