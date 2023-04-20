// Write a program to create two threads where one thread adds half of the element from the beginning of the array and 
// another thread add half of the element from the end of the array.
//  And at the end main process shows the sum of all the elements in the given array.


#include <stdio.h>
#include <pthread.h>

void* add_from_start(void* arg) {
    int* arr = (int*)arg;
    int sum = 0;
    int len = *arr; 
    printf("the value of x :%d",len);
    for (int i = 1; i <= len / 2; i++) {
        sum += arr[i];
    }

    int* result = (int*)malloc(sizeof(int));
    *result = sum / 2;
    pthread_exit(result);
}

void* add_from_end(void* arg) {
    int* arr = (int*)arg;
    int sum = 0;
    int len = arr[0]; 
    for (int i = len / 2 + 1; i <= len; i++) {
        sum += arr[i];
    }

    int* result = (int*)malloc(sizeof(int));
    *result = sum / 2;
    pthread_exit(result);
}

int main() {
    int arr[] = {10, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int sum_start = 0;
    int sum_end = 0;

    pthread_t t1, t2;
    pthread_create(&t1, NULL, add_from_start, (void*)&arr);
    pthread_create(&t2, NULL, add_from_end, (void*)&arr);


    int* result_start;
    int* result_end;
    pthread_join(t1, (void**)&result_start);
    pthread_join(t2, (void**)&result_end);

    
    sum_start = *result_start;
    sum_end = *result_end;


    printf("Sum from start: %d\n", sum_start);
    printf("Sum from end: %d\n", sum_end);

    printf("Total sum: %d\n", sum_start + sum_end);

    free(result_start);
    free(result_end);

    return 0;
}
