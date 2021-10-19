#include <stdio.h>

int nb = 3;
//============================================================
void mal_ecrit_1 (int nb)
{
printf ("nb mal_ecrit_1 = %d\n",nb++);
{
int nb = 14;
printf ("nb mal_ecrit_1 = %d\n",nb);
}
printf ("nb mal_ecrit_1 = %d\n",nb);
}
//============================================================
int mal_ecrit_2 (int x, int y)
{
printf ("nb mal_ecrit_2 = %d\n",x + nb);
printf ("nb mal_ecrit_2 = %d\n",y + nb);
return (nb *= 0);
}
//============================================================
int main(void) {

    int x = 3;
    int y = 6;
    printf ("nb main = %d\n",nb);
    mal_ecrit_1(nb);
    printf ("nb main = %d\n",nb);
    printf("resultat de mal_ecrit_2 = %d\n",mal_ecrit_2(y,x));
    printf ("nb = %d\n",nb);
    return 0;

}