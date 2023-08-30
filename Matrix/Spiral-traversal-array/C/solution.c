#include <inttypes.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

typedef int32_t i32;

i32** get_matrix(size_t rows, size_t cols);

int main(void)
{
    size_t n, m;
    printf("rows, cols: ");
    scanf("%zu %zu", &n, &m);

    i32** result = get_matrix(n, m);
    if (result == NULL) {
        perror("[Some Error =(]");
        return EXIT_FAILURE;
    }

    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < m; ++j) {
            printf("%5" PRId32, result[i][j]);
        }
        puts("");
        free(result[i]);
    }
    free(result);

    return EXIT_SUCCESS;
}

i32** get_matrix(size_t rows, size_t cols)
{
    i32** result = (i32**)calloc(rows, sizeof(i32*));
    if (result == NULL) {
        return NULL;
    }

    for (size_t i = 0; i < rows; ++i) {
        result[i] = (i32*)calloc(cols, sizeof(i32));
        if (result[i] == NULL) {
            return NULL;
        }
    }

    int s_row = 0;
    int s_col = 0;

    size_t idx = 0;

    while (s_row < rows && s_col < cols) {
        for (int i = s_col; i < cols; ++i) result[s_row][i] = ++idx;
        s_col++;

        for (int i = s_row + 1; i < rows; ++i) result[i][cols - 1] = ++idx;
        cols--;

        for (int i = cols - 1; i > s_row - 1; --i) result[rows - 1][i] = ++idx;
        rows--;

        for (int i = rows - 1; i > s_col - 1; --i) result[i][s_row] = ++idx;
        s_row++;
    }

    return result;
}
