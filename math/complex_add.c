/**
 * @file
 * @brief Function to add up two complex numbers.
 */
#define _USE_MATH_DEFINES /**< required for MS Visual C */
#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief Function to add two complex numbers.
 *\f{eqnarray*}{
 x + yi &=& (x_1 + y_1i) + (x_2 + y_2i)
 x &=& x_1 + x_2
 y &=% y_1 + y_2
 \f}
 * @param [in] x1 real part of the first summand
 * @param [in] y1 imaginary part of the first summand
 * @param [in] x2 real part of the second summand
 * @param [in] y2 imaginary part of the second summand
 * @param [out] x pointer to real part of the sum
 * @param [out] y pointer to imaginary part of the sum
 */
void summing(double x1, double y1, double x2, double y2, double *x, double *y)
{
    *x = x1 + x2;
    *y = y1 + y2;
}

/**
 * @brief Generate a random number in the given limits
 *
 * @param lim1 lower limit
 * @param lim2 upper limit
 * @return random number in the given range
 */
double get_rand(double lim1, double lim2)
{
    double r = (double)rand() / RAND_MAX;  // value in [0,1)
    return (lim2 - lim1) * r + lim1;       // scale to range
}

/**
 * @brief Test implementation
 *
 */
void test()
{
    srand(10);
    int NUM_TESTS = 5;

    for (int i = 0; i < NUM_TESTS; i++)
    {
        double x, y;
        printf("Test %d.... ", i);
        double x1 = get_rand(-5, 5);
        double y1 = get_rand(-5, 5);
        double x2 = get_rand(-5, 5);
        double y2 = get_rand(-5, 5);
        printf("(%.2g + %.2g i) + (%.2g + %.2g i)", x1, y1, x2, y2);
        summing(x1, y1, x2, y2, &x, &y);
        assert(fabs(x - (x1 + x2)) < 0.01);
        assert(fabs(y - (y1 + y2)) < 0.01);
        printf("passed\n");
    }
}

/** Main function */
int main()
{
    test();

    return 0;
}
