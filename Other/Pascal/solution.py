def get_layout_from_pascal(n: int) -> list[int]:
    result = [[1] + [0 for _ in range(n)] for _ in range(n + 1)]

    for i in range(1, n + 1):
        for k in range(1, n + 1):
            result[i][k] = result[i - 1][k] + result[i - 1][k - 1]

    return result[n]


def main() -> None:
    n = int(input("Enter your n: "))
    layout = get_layout_from_pascal(n)
    print(f"{n}: ", *layout, sep=" ")


if __name__ == "__main__":
    main()
