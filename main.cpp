#include "header.h"
int main()
{
#ifdef Test_square
Test();
#else
    double a = 0;
    double b = 0;
    double c = 0;
    char ch = 'Y';
    while (1)
    {
        if (ch != 'Y' && ch != 'N')
        {
            printf("You haven't made a choice, please try again\n");
            printf("Want to solve a quadratic equation?"
                " If yes, then click  'Y', otherwise 'N'\n");

        }
        else if (ch == 'N')
        {
            break;
        }
        else if (ch == 'Y')
        {
            printf("Enter the coefficients of the quadratic equation:\n");
            printf("Enter the coefficient before x^2:\n");
            a = read_num();

            printf("Enter the coefficient before x:\n");
            b = read_num();

            printf("Enter a free coefficient:\n");
            c = read_num();

            number_of_roots(a, b, c);

            printf("If you want to continue, click 'Y', to finish, click 'N'\n");

        }

        Read(&ch);

    }

    printf("The End\n");

#endif
    return 0;
}
