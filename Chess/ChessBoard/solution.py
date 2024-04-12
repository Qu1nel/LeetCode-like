def input_coord() -> tuple[int, ...]:
    return tuple(map(int, input("Enter x1 y1 x2 y2: ").split(' ')))


def can_same_color(fro: tuple[int, int], to: tuple[int, int]) -> bool:
    x1, y1 = fro
    x2, y2 = to
    return (x1 + y1) % 2 == (x2 + y2) % 2


def main() -> None:
    x1, y1, x2, y2 = input_coord()
    print("YES" if can_same_color(fro=(x1, y1), to=(x2, y2)) else "NO")


if __name__ == '__main__':
    main()
