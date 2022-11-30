#include "header.h"

int linear_eq(double b,double c,double* x1)
{
    assert(b != NAN && c != NAN && x1 != NULL);
    if (is_equal(b, 0.0))
    {
        if (is_equal(c, 0.0))
            return INF;
        else
            return ZERO;
    }
    else
    {
        assert(b != 0);
        *x1 = (-c) / b;
    }
    return LINE_EQUATION;
}

// func -- if i call function it will solve_sqare
int solve_squre(double a, double b, double c, double* x1, double* x2)
{
    assert(a!= NAN &&b != NAN && c != NAN && x1 != NULL && x2 != NULL);
    assert(x1 != x2 && x1 != NULL && x2 != NULL);
    if (is_equal(a, 0.0))
    {
        int ans = linear_eq(b, c, x1);
        return ans;
        // return linear_eq(b, c, x1);
    }

    double D = b*b - 4*a*c;
    if (is_equal(D, 0.0))
    {
        assert(a != 0);
        *x1 = -b / (2*a);
        return ONE_ROOT;
    }
    if (D < 0) {
        return NO_ROOTS;
    }

    assert(a != 0);
    double sqr = sqrt(D);
    *x1 = (-b + sqr) / (2*a);
    *x2 = (-b - sqr) / (2*a);
    return TWO_ROOTS; //TWO_ROOTS HELLOFROMMEAGAIN HELLO_FROM_ME_AGAIN
}




// print_solutions show_solutions
void number_of_roots(double a, double b, double c)
{
    assert(a!= NAN &&b != NAN && c != NAN);

    double x1 = 0;
    double x2 = 0;

    switch(solve_squre(a, b, c, &x1, &x2))
    {
        case INF:
            printf("Infinite number of solutions\n");
            break;

        case NO_ROOTS:
            printf("The discriminant is negative, there are no roots\n");
            break;

        case ONE_ROOT:
            printf("The discriminant is 0, the root is 1: %.2lf\n", x1);
            break;

        case TWO_ROOTS:
            printf("The discriminant is greater than 0, 2 roots: %.2lf and %.2lf \n", x1, x2);
            break;

        case LINE_EQUATION:
            printf("The equation is linear. Its root: %.2lf\n", x1);
            break;

        case ZERO:
            printf("There are no roots\n");
            break;

        default:
            break;
    }
}

double read_num()
{
    int amount = -1;
    char   ch = 0, tmp = 0;
    double number = 0;

    while(!((amount = scanf("%lf%c", &number, &tmp)) == 2 && tmp == '\n'))
    {
        if (amount != 2) {
            putchar('"');
            while((ch = getchar()) != '\n')
                putchar(ch);
            putchar('"');
            printf(" is not a number\n");
        }
        else {
            putchar('"');
            if ((int)number == number) {
                printf("%d%c", (int)number, tmp);
            }
            else {
                printf("%lf%c", number, tmp);
            }
            while((ch = getchar()) != '\n')
                putchar(ch);
            putchar('"');
            printf(" invalid input\n");
        }

    }



    return number;
}

void flush()
{
    while(getchar() != '\n')
        ;
}


void check_quadratic_equation(double a,double b, double c,  int number_of_roots , double x1, double x2)
{
    assert(a!= NAN &&b != NAN && c != NAN && number_of_roots != NAN && x1 != NAN && x2 != NAN);

    // snake_case_fd camelCaseSuper PascalCase
    double test_x1 = 0, test_x2 = 0;

    int n_roots = solve_squre(a, b, c, &test_x1, &test_x2);

    if (!(n_roots == number_of_roots && (is_equal(x1, test_x1) || is_equal(x2, test_x1)) && (is_equal(x1, test_x2) || is_equal(x2, test_x2))))
    {
        printf(
            "\n========================================\n"
            "Test FAILED:\n"
            "   Input    data: %lg %lg %lg\n"
            "   Expected data: %d %lg %lg\n"
            "   Got      data: %d %lg %lg\n"
            "==========================================\n\n",
            a, b, c,    number_of_roots, x1, x2,    n_roots, test_x1, test_x2
        );
    }
    else
    {
        printf(
            "Test passed.\n"
        );
    }

}

void Read(char* ch) {

        char symbol = 0;

        char word[String_Max_Len];

        char chr = 0;

        int number = 0;

        char incorrect_input = 0;

        scanf("%c", &chr);

        while (chr != '\n') {

            if (isalnum(chr) || ispunct(chr)) {

                symbol++;
            }

            word[number++] = chr;

            if (chr != ' ' || chr != 'N'  || chr != 'Y') {
                incorrect_input = 1;
            }

            scanf("%c", &chr);
        }

        word[number] = '\0';

        if (incorrect_input == 1 && symbol != 1) {
            printf("\n\033[0;31mInvalid input:\033[0m\"%s\"\n\n", word);
            *ch = '0';
        }

        else {
            
            if (strchr(word, 'N')) {
                *ch = 'N';
            }
            else {
                *ch = 'Y';
            }
        }
}

void Test()
{
    check_quadratic_equation(0.0, 0.0, 0.0, INF, 0.0, 0.0);
    check_quadratic_equation(0.0, 0.0, 1.0, ZERO, 0.0, 0.0);
    check_quadratic_equation(0.0, 1.0, 0.0, LINE_EQUATION, 0.0, 0.0);
    check_quadratic_equation(1.0, 0.0, 0.0, ONE_ROOT, 0.0, 0.0);
    check_quadratic_equation(1.0, 2.0, 1.0, ONE_ROOT, -1.0, 0.0);
    check_quadratic_equation(2.0, 1.0, 6.0, NO_ROOTS, 0.0, 0.0);
    check_quadratic_equation(1.0, -8.0, 15.0, TWO_ROOTS, 3.0, 5.0);
    check_quadratic_equation(1.0, -7.0, 12.0, TWO_ROOTS, 4.0, 3.0);
}

int is_equal(double num1, double num2)
{
    // EPSILON - THRESHOLD - TOLERANCE
    const double EPSILON = 1.e-9;

    return (fabs(num1 - num2) <= EPSILON);
}