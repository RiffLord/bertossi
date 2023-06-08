/**
 * @file        algorithms.h
 * @author      Bruno Pezer
 * @brief       Function definitions for algorithms described in Alan Bertossi's "Algoritmi e strutture dati".
 * @version     0.4
 * @date        2023-05-22
 *
 * @copyright   NO Copyright !(c) 2023
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>
#include <stdbool.h>

/**
 * @brief       Basic iterative algorithm for finding the minimum element of an array.
 *
 * @details     Consider the first array item as the smallest.
 *              For each item in the array consider the next item:
 *              if it is less than the current smallest, consider this one the smallest.
 *
 * @param  a    Array to parse
 * @param  size Size of the array
 * @return      m: the smallest item in the array
 */
int min(int a[], unsigned int size) {
    // If the array contains only one item, return it.
    if (size == 1) return a[0];

    // Consider the first item. If the next item is smaller, assign it to m.
    int m = a[0];
    for (size_t i = 1; i < size; i++) {
        if (a[i] < m)
            m = a[i];
    }
    return m;
}

/**
 * @brief        Basic recursive algorithm for finding the minimum
 *               element of an array. The minimum is either the first
 *               item or the minimum item in the rest of the array.
 *
 * @details      If the first position is equal to the last position,
 *               the array contains only one item which is also the smallest.
 *               Otherwise, the first item is considered to be the smallest,
 *               while the smallest item in the remainder of the array is
 *               recursively calculated. The smallest of these two values is returned.
 *
 * @param  a     Array to parse
 * @param  first Position of the first item in the array
 * @param  last  Position of the last item in the array
 * @return       m: the smallest item in the array
 */
int recurMin(int a[], int first, int last) {
    // If the array contains only one item, return it.
    if (first == last) {
        return a[first];
    } else {
        // Calculate the smallest item in the rest of the array.
        int m = recurMin(a, first + 1, last);

        // Return the first item of the array, or the smallest from the remainder, whichever is smaller.
        if (a[first] < m) {
            return a[first];
        } else return m;
    }
}

/**
 * @brief       Auxiliary function for the sort algorithm implementation, returning the smallest item of an array.
 *
 * @details     Finds the smallest item of an array along with its position within the array.
 *
 * @param a     Array to parse
 * @param j     Initial position of the array to parse
 * @param size  Size of the provided array
 * @param p     Pointer to the position of the smallest item within the array
 *
 * @return      m: the smallest item in the array
 *
 */
int getMin(int a[], int j, unsigned int size, int *p) {
    // If the array contains only one item, return it.
    if (size == 1) return a[0];

    int m;      // Smallest item
    m = a[j];   // Consider the initial item to be the smallest.
    *p = j;     // Point to the position of the initial item.

    // Consider each item after the initial one. If the next one is smaller,
    // update the smallest item and the pointer to its position accordingly.
    for (size_t i = j + 1; i < size; i++) {
        if (a[i] < m) {
            m = a[i];
            *p = i;
        }
    }
    return m;
}

/**
 * @brief      Sorts an array in ascending order.
 *
 * @details    Uses an auxiliary function to discover the smallest item in the array and places it
 *             in the first position. Repeats the process for the remaining items
 *             (starting from the second position, then the third, etc.) until the array is sorted.
 *
 * @param a    Array to sort
 * @param size Size of the array
 */
void sort(int a[], unsigned int size) {
    int pos;    // Original position of the smallest item
    int temp;   // Holder variable for switching the current item with the smallest

    // Consider each item of the array. Store it in a temporary variable, and switch it
    // with the smallest item found. Repeat from the next position and the smallest
    // item remaining until the entire array has been sorted.
    for (size_t i = 0; i < size; i++) {
        temp = a[i];
        a[i] = getMin(a, i, size, &pos);
        a[pos] = temp;
    }
}

/**
 * @brief       Examines the contents of an array to determine if it contains any duplicate items.
 *
 * @details     Compares each item in the array with all of the remaining ones, returning true
 *              at the first duplicate set found. If none are found, returns false.
 *
 * @param a     Array to examine
 * @param size  Size of the array
 * @return      true if a duplicate item is found, false otherwise.
 */
bool hasDuplicate(unsigned int a[], unsigned int size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (a[i] == a[j]) return true;
        }
    }
    return false;
}

/**
 * @brief       Examines the contents of an array of integers to determine whether the sum of any two items is 17.
 *
 * @details     Evaluates the sum of each item in the array with all of the remaining items.
 *
 * @param a     Array to examine
 * @param size  Size of the array
 * @return      true if the sum of any two elements is 17, false otherwise.
 */
bool hasSumOf17(unsigned int a[], unsigned int size) {
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            if (a[i] + a[j] == 17) return true;
        }
    }
    return false;
}

/**
 * @brief   Prints the powers of a number up to a given exponent.
 *
 * @details Successively calculates each power of the number up to the exponent
 *          by storing and printing the results in a cumulative variable.
 *
 * @param n Number
 * @param e Exponent
 *
 * @author  Bruno Pezer
 */
void printPowers(int n, int e) {
    int power = 1;  // Initial value

    // Checks whether the exponent is positive or negative.
    if (e >= 0) {
        // Successively prints the powers of n for each exponent up to e.
        for (unsigned int i = 0; i <= e; i++) {
            printf("%d^%u = %d\n", n, i, power);
            power *= n;
        }
    } else {
        // Successively prints the powers of n for each negative exponent up to e.
        for (int i = 0; i <= abs(e); i++) {
            printf("%d^%d = %f (1 / %d)\n", n, -i, ((float) 1 / power), power);
            power *= n;
        }
    }
}

/**
 * @brief   Alternative function for printing the powers of a number up to a given exponent.
 *
 * @details Successively calculates each power of the number up to the exponent
 *          by storing and printing the results in a cumulative variable.
 *
 * @param n Number
 * @param e Exponent
 *
 */
void printPowers2(int n, int e) {
    int power = 1;  // Initial value
    int i = 0;      // Iteration counter

    // Successively prints the powers of n for each exponent up to e.
    while (i <= abs(e)) {
        if (e >= 0) {
            printf("%d^%u = %d\n", n, i, power);    // Positive exponent
        } else {
            printf("%d^%d = %f (1 / %d)\n", n, -i, ((float) 1 / power), power); // Negative exponent
        }
        power *= n;
        i++;
    }
}

/**
 * @brief           Orders the contents of the array to correspond to the colours of the Italian flag (i.e. green, white, red).
 *
 * @details         Each item of the array is compared with the remaining
 *                  items, progressively switching their positions if the
 *                  second examined item should be placed before the current one.
 *
 * @param colours   Array of strings (char pointers). The only valid values are "green", "white" and "red".
 * @param size      Array size
 *
 * @author          Bruno Pezer
 */
void sortItalianFlagColours(char *colours[], unsigned int size) {
    //  Compare each item of the array with the remaining items.
    for (size_t i = 0; i < size; i++) {
        for (size_t j = i + 1; j < size; j++) {
            //  If the currently examined item is "red" and the second one isn't, or the
            //  currently examined item is "white" and the second one is "green",
            //  switch them with the help of a holder variable.
            if ((colours[i] == "red" && colours[j] != "red") || (colours[i] == "white" && colours[j] == "green")) {
                char *temp = colours[i];
                colours[i] = colours[j];
                colours[j] = temp;
            }
        }
    }
}
