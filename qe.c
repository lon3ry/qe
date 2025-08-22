#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

#define ARE_FLOATS_EQUAL(A, B) ((A) - (B) <= 1e-6)

enum { quadratic_inf_sols = -1 };

void print_about(void)
{
    puts("The quadratic equation solver");
}

static int
solve_quadratic(double a, double b, double c, double *x1, double *x2)
{
    double d;

    assert(a != 0);
    assert(x1 != NULL);
    assert(x2 != NULL);
    assert(x1 != x2);

    if (ARE_FLOATS_EQUAL(a, 0.0) && ARE_FLOATS_EQUAL(b, 0.0) &&
        ARE_FLOATS_EQUAL(c, 0.0)
    ) {
        return quadratic_inf_sols;
    }

    d = b*b - 4*a*c;

    *x1 = (-b + d) / (2*a);
    *x2 = (-b - d) / (2*a);

    if (d > 0)
        return 2;
    else
    if (d == 0)
        return 1;
    else
        return 0;
}

static void read_double_safe(const char *msg, double *res)
{
    int r;
    printf("%s%s", msg, ": ");
    r = scanf("%lf", res);
    if (r != 1) {
        fputs("error while reading number.", stderr);
        exit(1);
    }
}

static void print_quadratic_sols(double a, double b, double c)
{
    double x1, x2;
    int root_count;

    root_count = solve_quadratic(a, b, c, &x1, &x2);
    switch (root_count) {
    case 0:
        puts("No real sols.");
        break;
    case 1:
        printf("x1 = %g.\n", x1);
        break;
    case 2:
        printf("x1 = %g, x2 = %g.\n", x1, x2);
        break;
    case quadratic_inf_sols:
        puts("Infinite number of sols.");
        break;
    }
}

int main(int argc, char **argv)
{
    double a, b, c;

    print_about();
    read_double_safe("Enter coefficient a", &a);
    if (ARE_FLOATS_EQUAL(a, 0.0)) {
        fputs("a = 0 but this program is not intended to solve "
              "linear equations.", stderr);
        return 1;
    }
    read_double_safe("Enter coefficient b", &b);
    read_double_safe("Enter coefficient c", &c);
    print_quadratic_sols(a, b, c);
    return 0;
}
