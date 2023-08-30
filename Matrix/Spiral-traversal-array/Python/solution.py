test_array = [
    [1, 2, 3, 4, 5, 6],
    [20, 21, 22, 23, 24, 7],
    [19, 32, 33, 34, 25, 8],
    [18, 31, 36, 35, 26, 9],
    [17, 30, 29, 28, 27, 10],
    [16, 15, 14, 13, 12, 11],
]


def snail(a: list[list[int]]) -> None:
    rows = len(a)
    cols = len(a[0])

    s_row = s_col = 0

    while s_row < rows and s_col < cols:
        for i in range(s_col, cols):
            print(f"{a[s_row][i]}", end=" ")
        s_col += 1

        for i in range(s_row + 1, rows):
            print(f"{a[i][cols - 1]}", end=" ")
        cols -= 1

        for i in range(cols - 1, s_row - 1, -1):
            print(f"{a[rows - 1][i]}", end=" ")
        rows -= 1

        for i in range(rows - 1, s_col - 1, -1):
            print(f"{a[i][s_row]}", end=" ")
        s_row += 1

    print()


if __name__ == "__main__":
    snail(test_array)
