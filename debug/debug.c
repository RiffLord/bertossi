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
    puts("\n");

    int bsize = 1;
    int b[1] = {666};
    puts("Array contents");
    for (size_t i = 0; i < bsize; i++) {
        printf("%d ", b[i]);
    }
    printf("\n%s%d\n\n","The smallest element is ", min(b, bsize));
    printf("\n%s%d\n\n","Recursively calculating the smallest element: ", recurMin(b, 0, bsize - 1));

    printf("Printing the powers of %d up to %d:\n", 2, 7);
    printPowers(2, 7);

    printf("Printing the powers of %d up to %d:\n", -2, 7);
    printPowers(-2, 7);

    printf("Printing the powers of %d up to %d:\n", 6, -3);
    printPowers(6, -3);

    printf("Printing the powers of %d up to %d:\n", -6, -3);
    printPowers(-6, -3);

    printf("Printing the powers of %d up to %d:\n", 2, 7);
    printPowers2(2, 7);

    printf("Printing the powers of %d up to %d:\n", -2, 7);
    printPowers2(-2, 7);

    printf("Printing the powers of %d up to %d:\n", 6, -3);
    printPowers2(6, -3);

    printf("Printing the powers of %d up to %d:\n", -6, -3);
    printPowers2(-6, -3);
    puts("");

    char *c[6];
    c[0] = "white";
    c[1] = "green";
    c[2] = "red";
    c[3] = "red";
    c[4] = "green";
    c[5] = "white";
    for (size_t i = 0; i < 6; i++) {
        printf("%s ", c[i]);
    }
    puts("");
    puts("");
    sortItalianFlagColours(c, 6);
    puts("Sorting colours in array...");
    for (size_t i = 0; i < 6; i++) {
        printf("%s ", c[i]);
    }
    puts("");

    char *flag[7] = {"red", "red", "red", "green", "white", "white", "red"};
    for (size_t i = 0; i < 7; i++) {
        printf("%s ", flag[i]);
    }
    puts("Sorting the flag colours...");
    sortItalianFlagColours(flag, 7);
    puts("");
    for (size_t i = 0; i < 7; i++) {
        printf("%s ", flag[i]);
    }
    puts("");

    //  TODO: test hasDuplicate and hasSumOf17 functions

    return 0;
}
