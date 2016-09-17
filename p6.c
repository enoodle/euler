#include <stdio.h>

int main()
{
        int i;
        double sumos=0;

        for (i=1; i<=100; i++)
                printf("%lf\n",sumos+=i*i);

        printf("\n %lf \n",-sumos+(5050*5050));
}
