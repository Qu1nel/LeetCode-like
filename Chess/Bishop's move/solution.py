def input_coord() -> tuple[int, ...]:
    return tuple(map(int, input("Enter x1 y1 x2 y2: ").split(' ')))


def can_bishop_descend_to(fro: tuple[int, int], to: tuple[int, int]) -> bool:
    x1, y1 = fro
    x2, y2 = to
    return abs(x1 - x2) == abs(y1 - y2)


def main() -> None:
    x1, y1, x2, y2 = input_coord()
    print("YES" if can_bishop_descend_to(fro=(x1, y1), to=(x2, y2)) else "NO")


if __name__ == '__main__':
    main()
