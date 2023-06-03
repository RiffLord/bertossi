/**
 * @file        algorithms.h
 * @author      Bruno Pezer
 * @brief       Function definitions for algorithms described in Alan Bertossi's "Algoritmi e strutture dati".
 * @version     0.2
 * @date        2023-05-22
 *
 * @copyright   NO Copyright !(c) 2023
 *
 */

/**
 * @brief       Basic iterative algorithm for finding the minimum
 *              element of an array.
 *
 * @details     Uses a variable @var m of type integer.
 *              Considers the first array item @param a and assigns it to @var m.
 *              While @param a has items, consider the next item:
 *              if the next item is less than @var m, assign item to @var m.
 *
 * @param  a    Array to parse
 * @param  size Size of the array
 * @var    m    Minimum array element
 * @return m
 */
int min(int a[], int size) {
    //  If the array contains only one item, return it.
    if (size == 1) return a[0];

    //  Consider the first item. If the next item is smaller, assign it to @var m.
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
 * @details      If the @param first is equal to @param last,
 *               the array contains one item, which is also the smallest.
 *               Otherwise, the first item is considered to be the smallest,
 *               while the smallest item in the remainder of the array is
 *               recursively calculated. The smallest of these two values is returned.
 *
 * @param  a     Array to parse
 * @param  first Position of the first item in the array
 * @param  last  Position of the last item in the array
 * @var    m     Minimum array element
 * @return m
 */
int recurmin(int a[], int first, int last) {
    // If the array contains only one item, return it.
    if (first == last) {
        return a[first];
    } else {
        //  Calculate the smallest item in the rest of the array
        int m = recurmin(a, first + 1, last);

        //  Return the first item of the array, or the smallest from the remainder, whichever is smaller.
        if (a[first] < m) {
            return a[first];
        } else return m;
    }
}
