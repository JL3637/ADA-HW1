using namespace std;
#include<stdio.h>
#include<bits/stdc++.h>
#define R 1
#define L -1

int find_min(int a, int b){
    if(a > b){
        return b;
    }
    else{
        return a;
    }
}

void count_num(int *value, int start, int end, long long *num, int *left, int *right){
    if(start == end){
        return;
    }
    int mid = (start + end) / 2;
    int min = find_min(value[mid], value[mid+1]);
    int left_index = 0;
    int right_index = 1;
    int left_or_right = L;
    while(left_index + right_index <= end - start + 1){
        if(left_or_right == L){
            if(mid - left_index < start){
                left_or_right = R;
            }
            else if(min <= value[mid - left_index]){
                left[value[mid - left_index]]++;
                if(value[mid - left_index] + min <= 100000){
                    *num += right[value[mid - left_index] + min];
                }
                if(value[mid - left_index] - min > 0){
                    *num += right[value[mid - left_index] - min];
                }
                left_index++;
                left_or_right = R;
            }
            else{
                if(value[mid + right_index] < min){
                    if(value[mid - left_index] > value[mid + right_index]){
                        min = value[mid - left_index];
                        left_or_right = L;
                    }
                    else{
                        min = value[mid + right_index];
                        left_or_right = R;
                    }
                }
                else if(right_index == end - mid + 1){
                    min = value[mid - left_index];
                    left_or_right = L;
                }
                else{
                    left_or_right = R;
                }
            }
        }
        else if(left_or_right == R){
            if(mid + right_index > end){
                left_or_right = L;
            }
            else if(min <= value[mid + right_index]){
                right[value[mid + right_index]]++;
                if(value[mid + right_index] + min <= 100000){
                    *num += left[value[mid + right_index] + min];
                }
                if(value[mid + right_index] - min > 0){
                    *num += left[value[mid + right_index] - min];
                }
                right_index++;
                left_or_right = L;
            }
            else{
                if(value[mid - left_index] < min){
                    if(value[mid - left_index] > value[mid + right_index]){
                        min = value[mid - left_index];
                        left_or_right = L;
                    }
                    else{
                        min = value[mid + right_index];
                        left_or_right = R;
                    }
                }
                else if(left_index == mid - start + 1){
                    min = value[mid + right_index];
                    left_or_right = R;
                }
                else{
                    left_or_right = L;
                }
            }
        }
    }
    for(int i = start; i <= end; i++){
        if(i <= mid){
            left[value[i]] = 0;
        }
        else{
            right[value[i]] = 0;
        }
    }
    count_num(value, start, mid, num, left, right);
    count_num(value, mid + 1, end, num, left, right);
}

int main(){
    int n;
    scanf("%d", &n);
    int *value = (int *)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++){
        scanf("%d", &value[i]);
    }
    int *left = (int *)calloc(200001, sizeof(int));
    int *right = (int *)calloc(200001, sizeof(int));
    long long num = 0;
    count_num(value, 0, n-1, &num, left, right);
    printf("%lld", num);

    return 0;
}