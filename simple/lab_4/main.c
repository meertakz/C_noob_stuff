#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

#define EXIT_SUCCESS 0
#define N  10

/* function prototypes */
int mult (int, int);
void d2b (int, int *, int *);
int catalan (int);
int countSpaces (char *);
int isPalindrome (char *, int);
void triangleA (int, int);
void triangleB (int, int, int);

/*
 *  main program
 */
int main(void)
{
    /* Part A */
    {
        int x = 5, y = 18, res;

        res = mult (x, y);
        fprintf (stdout, "-- Mul: %d x %d = %d\n", x, y, res);
    }

    /* Part B */
    {
        int i, b[10], d = 35, n = 0;

        d2b (d, b, &n);
        fprintf (stdout, "-- Decimal to Binary Conversion: (base 10) %d = (base 2) ", d);
        for (i=n-1; i>=0; i--)
            fprintf (stdout, "%d", b[i]);
        fprintf (stdout, "\n");
    }

    /* Part C */
    {
        int i;

        printf ("-- Catalan Numbers: ");
        for (i=0; i<10; i++) {
            printf ("%d ", catalan(i));
        }
        printf ("\n");
    }


    /* Part D */
    {
        int n;
        char s[] = "This is my string to check for spaces";

        n = countSpaces (s);
        fprintf (stdout, "-- Count Spaces in (%s) = %d\n", s, n);
    }

    /* Part E */
    {
        // Aro un autodromo o mordo tua nuora";
        char s[] = "aro un aut odrom o o mordo tua nu ora";

        if ( isPalindrome (s, strlen (s)) )
            fprintf (stdout, "-- (%s) is palindrome\n", s);
        else
            fprintf (stdout, "-- (%s) is not palindrome\n", s);
    }

    /* Part F */
    {
        fprintf (stdout, "-- Triangle A:\n");
        triangleA (4, 1);
        fprintf (stdout, "-- Triangle B:\n");
        triangleB (5, 1, 1);
    }

    return EXIT_SUCCESS;
}

int mult (
        int x,
        int y
)
{
    int res;

    if (y==0)
        return (0);

    if (y==1)
        return (x);

    res = x + mult (x, y-1);
    return (res);
}

void d2b (
        int d,
        int *b,
        int *np
)
{
    if (d==0)
        return;

    b[*np] = d % 2;
    d = d / 2;
    *np = *np + 1;
    d2b (d, b, np);
    return;
}

int catalan (
        int n
)
{
    int i, res;

    if (n==0)
        return (1);

    res = 0;
    for (i=0; i<n; i++)
        res += catalan(i) * catalan(n - 1 - i);

    return res;
}

int countSpaces (
        char *s
)
{
    if (*s=='\0')
        return 0;
    else
        return ((isspace(*s) ? 1 : 0) + countSpaces(s+1));
}

int isPalindrome (
        char *s,
        int len
)
{
    if (len <=1 )
        return 1;
    else
        return ((s[0]==s[len-1]) && isPalindrome(s+1, len-2));
}

void triangleA (
        int n,
        int i
)
{
    int j;

    if (i>n) {
        return;
    }

    for (j=0; j<i; j++)
        printf ("%d ", i);
    printf ("\n");

    triangleA (n, i+1);
}

void triangleB (
        int n,
        int i,
        int j)
{
    if (i>n) {
        return;
    }

    if (j<=i) {
        printf ("%d ", i);
        triangleB (n, i, j+1);
        return;
    }

    printf ("\n");
    triangleB (n, i+1, 1);
}
