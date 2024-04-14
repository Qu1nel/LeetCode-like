#include <iostream>

int main(int argc, char *argv[]) {
  int n, m;

  std::cout << "Enter 'n' and 'm': " << std::endl;
  std::cin >> n;
  std::cin >> m;

  int sign = (n < m) ? 1 : -1;

  while (sign * n <= m * sign) {
    std::cout << n << std::endl;
    n += sign;
  }

  return 0;
}
