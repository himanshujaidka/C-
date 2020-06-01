#include<stdio.h>

void merger(int A[], int l, int mid, int h) {
    int i, j, k;
    int B[10];
    i = l, j = mid + 1, k = l;
    while (i <= mid && j <= h) {
        if (A[i] < A[j]) {
            B[k++] = A[i++];
        }
        else {
            B[k++] = A[j++];
        }
    }
    for (; i <= mid; i++) {
        B[k++] = A[i];
    }
    for (; j <= h; j++) {
        B[k++] = A[j];
    }
    for (i = l; i <= h; i++) {
        A[i] = B[i];
    }

}
void MergeSort(int A[], int n)
{
    int p, l, h, mid, i;

    for (p = 2; p <= n; p = p * 2)
    {
        for (i = 0; i + p - 1 <= n; i = i + p)
        {
            l = i;
            h = i + p - 1;
            mid = (l + h) / 2;
            merger(A, l, mid, h);
        }
    }
    if (p / 2 < n)
        merger(A, 0, p / 2 - 1, n);

}

int main() {
    int A[] = { 11,13,7,12,1,-1 }, n = 6, i;
    printf("Before : ");
    for (i = 0; i < n; i++) {printf("%d ", A[i]);}
    printf("\n");
    MergeSort(A, n - 1);
    printf("After : ");
    for (i = 0; i < n; i++) { printf("%d ", A[i]); }
    printf("\n");    
    return 0;
} 


