// Taller 2 - Estructura de Datos - Punto 2: Toby y las Galletas

#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

void Merge(long long int A[], int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    long long int L[n1], R[n2];

    for (int i = 0; i < n1; i++)
        L[i] = A[p + i];
    for (int j = 0; j < n2; j++)
        R[j] = A[q + 1 + j];

    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++)
    {
        if (i < n1 && (j >= n2 || L[i] <= R[j]))
        {
            A[k] = L[i];
            i++;
        }
        else if (j < n2)
        {
            A[k] = R[j];
            j++;
        }
    }
}

void MergeSort(long long int A[], int p, int r)
{
	if (p < r)
	{
		int q = (p + r) / 2;
		MergeSort(A, p, q);
		MergeSort(A, q + 1, r);
		Merge(A, p, q, r);
	}
}

int BinarySearch(long long int A[], int i, int j, int k)
{
    int r = -1;
    while (i <= j){
        int m = (i + j) / 2;
        if (k == A[m]){ 
            r = m; 
            break; 
        } 
        else if (k > A[m]) 
            i = m + 1; 
        else
            j = m - 1; 
    } 

    if (r == -1) 
        r = i - 1; // No encontrado, devolver el menor que k

    return r;
}

int BinarySearchLastOcurrence(long long int A[], int i, int j, int k){
	int r = BinarySearch(A,i,j,k);
	if (r>=0){
		long long int r2 = BinarySearch(A,r+1,j,k);
		if (r2>=0){
			r = r2;
			r2 = BinarySearch(A,r+1,j,k);
		}
	}
	return r;
}

int main(void) {
    long int n;
    // Lee hasta EOF
    while (scanf("%ld", &n) == 1) {
        long long int A[n];
        for (int i = 0; i < n; i++) {
            scanf("%lld", &A[i]);
        }

        MergeSort(A, 0, n - 1);

        int idQuery;
        scanf("%d", &idQuery);
        for (int i = 0; i < idQuery; i++) {
            long long int k;
            scanf("%lld", &k);
            long long int result = BinarySearchLastOcurrence(A, 0, n - 1, k) + 1;
            printf("%lld ", result);
        }
        printf("\n");
    }
    return 0;
}