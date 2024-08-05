#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main()
{
    float atas, bawah, x, fA, fB, fX;
    int iterasi;
    printf("f(x) = exp(x) + x\n");
    printf("Batas atas\t: ");
    scanf("%f", &atas);
    printf("Batas bawah\t: ");
    scanf("%f", &bawah);
    x = (atas + bawah) / 2;
    fA = exp(atas) + atas;
    fB = exp(bawah) + bawah;
    fX = exp(x) + x;
    if (fA * fB >= 0)
    {
        printf("%3.5f %3.5f\n", fA, fB);
        system("pause");
        return 0;
    }
    else
    {
        while (fabs(fX * 10000) > 1)
        {
            printf("%2.6f\t%2.6f\t%2.6f\t%2.6f\t%2.6f\t%2.6f\n", bawah, x, atas, fB, fX, fA);

            if (fA * fX > 0)
            {
                atas = x;
                fA = fX;
            }
            else if (fB * fX > 0)
            {
                bawah = x;
                fB = fX;
            }
            x = (atas + bawah) / 2;
            fA = exp(atas) + atas;
            fB = exp(bawah) + bawah;
            fX = exp(x) + x;
        }
        printf("%2.6f\t%2.6f\t%2.6f\t%2.6f\t%2.6f\t%2.6f\n", bawah, x, atas, fB, fX, fA);
        printf("%5.6f\n", fX);
        system("pause");
    }
}