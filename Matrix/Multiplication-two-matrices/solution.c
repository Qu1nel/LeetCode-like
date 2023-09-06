#include <stdio.h>
#include <stdlib.h>

#define H1 3
#define W1 3

#define H2 3
#define W2 2


void print_matrix(const size_t height, const size_t width, int A[height][width]);
int **mult_matrix(const size_t h1, const size_t w1, int A[h1][w1], const size_t h2, const size_t w2, int B[h2][w2]);

int A[H1][W1] = {
    {1, 2, 1},
    {0, 1, 0},
    {2, 3, 4},
};

int B[H2][W2] = {
    {2, 5},
    {6, 7},
    {1, 8},
};


int main(void)
{
    print_matrix(H1, W1, A);
    fputs("\n\tX\n\n", stdout);
    print_matrix(H2, W2, B);
    fputs("\nResult:\n\n", stdout);

    int **C = calloc(H1, sizeof(int *));  // mult_matrix(3, 3, A, 3, 2, B);

    if (C == NULL) {
        perror("Error memory");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < H1; ++i) {
        C[i] = calloc(W2, sizeof(int));
        for (size_t j = 0; j < W2; ++j) {
            for (size_t k = 0; k < H1; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // print dynamic matrix
    for (size_t i = 0; i < H1; ++i) {
        for (size_t j = 0; j < W2; ++j) {
            printf("%5d", C[i][j]);
        }
        free(C[i]);
        putchar('\n');
    }

    free(C);

    return EXIT_SUCCESS;
}


void print_matrix(const size_t height, const size_t width, int A[height][width])
{
    putchar('\n');
    for (size_t i = 0; i < height; ++i) {
        for (size_t j = 0; j < width; ++j) {
            printf("%5d", A[i][j]);
        }
        putchar('\n');
    }
    putchar('\n');
}
