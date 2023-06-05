/**
 * @file        algorithms.h
 * @author      Bruno Pezer
 * @brief       Function definitions for algorithms described in Alan Bertossi's "Algoritmi e strutture dati".
 * @version     0.3
 * @date        2023-05-22
 *
 * @copyright   NO Copyright !(c) 2023
 *
 */

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
int min(int a[], int size) {
    //  If the array contains only one item, return it.
    if (size == 1) return a[0];

    //  Consider the first item. If the next item is smaller, assign it to m.
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
        //  Calculate the smallest item in the rest of the array.
        int m = recurMin(a, first + 1, last);

        //  Return the first item of the array, or the smallest from the remainder, whichever is smaller.
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
int getMin(int a[], int j, int size, int *p) {
    // If the array contains only one item, return it.
    if (size == 1) return a[0];

    int m;      // Smallest item
    m = a[j];   //  Consider the initial item to be the smallest.
    *p = j;     //  Point to the position of the initial item.

    //  Consider each item after the initial one. If the next one is smaller,
    //  update the smallest item and the pointer to its position accordingly.
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
void sort(int a[], int size) {
    int pos;    //  Original position of the smallest item
    int temp;   //  Holder variable for switching the current item with the smallest

    //  Consider each item of the array. Store it in a temporary variable, and switch it
    //  with the smallest item found. Repeat from the next position and the smallest
    //  item remaining until the entire array has been sorted.
    for (size_t i = 0; i < size; i++) {
        temp = a[i];
        a[i] = getMin(a, i, size, &pos);
        a[pos] = temp;
    }
}
