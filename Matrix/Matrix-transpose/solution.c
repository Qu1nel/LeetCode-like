#include <stdio.h>
#include <stdlib.h>

#define WIDTH  5
#define HEIGHT 5

void print_matrix(const size_t n, const size_t m, int A[][m]);
void transpone_matrix(const size_t n, const size_t m, int A[][m]);

int A[HEIGHT][WIDTH] = {
    {1, 3, 5, 6, 2}, {-3, 5, 2, 7, 9}, {0, 1, 3, 8, 6}, {0, -4, 6, 2, 7}, {3, -5, 2, 2, 9},
};


int main(void)
{
    print_matrix(HEIGHT, WIDTH, A);
    fputs("\n\tVVVVVVVVVVVV\n\n", stdout);
    transpone_matrix(HEIGHT, WIDTH, A);
    print_matrix(HEIGHT, WIDTH, A);

    return EXIT_SUCCESS;
}

void transpone_matrix(const size_t n, const size_t m, int A[][m])
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            if (i < j) {
                A[i][j] ^= A[j][i] ^= A[i][j] ^= A[j][i];
            }
        }
    }
}

void print_matrix(const size_t n, const size_t m, int A[][m])
{
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%5d", A[i][j]);
        }
        putchar('\n');
    }
}
