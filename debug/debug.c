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

    puts("Press any key to continue...");
    int c = getchar();

    int bsize = 1;
    int b[1] = {666};
    puts("Array contents");
    for (size_t i = 0; i < bsize; i++) {
        printf("%d ", b[i]);
    }
    printf("\n%s%d\n\n","The smallest element is ", min(b, bsize));
    printf("\n%s%d\n\n","Recursively calculating the smallest element: ", recurMin(b, 0, bsize - 1));

    puts("Press any key to continue...");
    c = getchar();

    printf("Printing the powers of %d up to %d:\n", 2, 7);
    printPowers(2, 7);

    printf("Printing the powers of %d up to %d:\n", -2, 7);
    printPowers(-2, 7);

    puts("Press any key to continue...");
    c = getchar();

    printf("Printing the powers of %d up to %d:\n", 6, -3);
    printPowers(6, -3);

    printf("Printing the powers of %d up to %d:\n", -6, -3);
    printPowers(-6, -3);

    puts("Press any key to continue...");
    c = getchar();

    printf("Printing the powers of %d up to %d:\n", 2, 7);
    printPowers2(2, 7);

    printf("Printing the powers of %d up to %d:\n", -2, 7);
    printPowers2(-2, 7);

    puts("Press any key to continue...");
    c = getchar();

    printf("Printing the powers of %d up to %d:\n", 6, -3);
    printPowers2(6, -3);

    printf("Printing the powers of %d up to %d:\n", -6, -3);
    printPowers2(-6, -3);
    puts("");

    puts("Press any key to continue...");
    c = getchar();

    colours clrs[6];
    clrs[0] = white;
    clrs[1] = green;
    clrs[2] = red;
    clrs[3] = red;
    clrs[4] = green;
    clrs[5] = white;
    for (size_t i = 0; i < 6; i++) {
        if (clrs[i] == green) printf("%s ", "green");
        else if (clrs[i] == white) printf("%s ", "white");
        else printf("%s ", "red");
    }
    puts("");
    puts("");
    sortItalianFlagColours(clrs, 6);
    puts("Sorting colours in array...");
    for (size_t i = 0; i < 6; i++) {
        if (clrs[i] == green) printf("%s ", "green");
        else if (clrs[i] == white) printf("%s ", "white");
        else printf("%s ", "red");
    }
    puts("");

    puts("Press any key to continue...");
    c = getchar();

    colours flag[7] = {red, red, red, green, white, white, red};
    for (size_t i = 0; i < 7; i++) {
        if (flag[i] == green) printf("%s ", "green");
        else if (flag[i] == white) printf("%s ", "white");
        else printf("%s ", "red");
    }
    puts("");
    puts("Sorting the flag colours...");
    sortItalianFlagColours(flag, 7);
    puts("");
    for (size_t i = 0; i < 7; i++) {
        if (flag[i] == green) printf("%s ", "green");
        else if (flag[i] == white) printf("%s ", "white");
        else printf("%s ", "red");
    }
    puts("");

    puts("Press any key to continue...");
    c = getchar();

    colours flag2[9] = {red, white, green, red, red, green, white, white, red};
    for (size_t i = 0; i < 9; i++) {
        if (flag2[i] == green) printf("%s ", "green");
        else if (flag2[i] == white) printf("%s ", "white");
        else printf("%s ", "red");
    }
    puts("");
    puts("Sorting the flag colours...");
    sortItalianFlagColours2(flag2, 9);
    puts("");
    for (size_t i = 0; i < 9; i++) {
        if (flag2[i] == green) printf("%s ", "green");
        else if (flag2[i] == white) printf("%s ", "white");
        else printf("%s ", "red");
    }
    puts("");

    puts("Press any key to continue...");
    c = getchar();

    puts("Checking if a has duplicates...");
    if (hasDuplicate(a, size)) {
        puts("True");
    } else puts("False");
    puts("");

    puts("Checking if b has duplicates...");
    if (hasDuplicate(b, bsize)) {
        puts("True");
    } else puts("False");
    puts("");

    puts("Press any key to continue...");
    c = getchar();

    puts("Checking if a has the sum of 17...");
    if (hasSumOf17(a, size)) {
        puts("True");
    } else puts("False");
    puts("");

    puts("Checking if b has the sum of 17...");
    if (hasSumOf17(b, bsize)) {
        puts("True");
    } else puts("False");
    puts("");

    puts("Press any key to continue...");
    c = getchar();

    return 0;
}
