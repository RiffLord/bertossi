#include <stdio.h>
#ifdef __linux__
	#include "../algorithms.h"
#elif _WIN32
	#include "..\algorithms.h"
#else
	#error Platform not supported
#endif

int main(void) {
    int size = 10;
    int a[10] = {12, 13, 2, 6, 8, 5, 5, 3, 1, 8};
    puts("Array contents");
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n%s%d\n\n","The smallest element is ", min(a, size));
    printf("\n%s%d\n\n","Recursively calculating the smallest element: ", recurMin(a, 0, size - 1));

    puts("Ordering array...");
    sort(a, size);
    for (size_t i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }

    int bsize = 1;
    int b[1] = {666};
    puts("Array contents");
    for (size_t i = 0; i < bsize; i++) {
        printf("%d ", b[i]);
    }
    printf("\n%s%d\n\n","The smallest element is ", min(b, bsize));
    printf("\n%s%d\n\n","Recursively calculating the smallest element: ", recurMin(b, 0, bsize - 1));

    return 0;
}
