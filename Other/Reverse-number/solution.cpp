#include <cmath>
#include <cstdint>
#include <iostream>
#include <math.h>

int32_t get_reverse_number(int32_t);

int main(int argc, char *argv[]) {
  int32_t number;

  std::cout << "Enter your number: ";
  std::cin >> number;

  int32_t reverse_number = get_reverse_number(number);

  std::cout << "Number " << number << " to " << reverse_number << std::endl;

  return 0;
}

int32_t get_reverse_number(int32_t num) {
  int sign = 1;

  if (num < 0) {
    sign = -1;
    num = -num;
  }

  size_t length_num = floor(log10(num) + 1);
  int32_t result_number = 0;

  while (length_num) {
    int digit = num % 10 * pow(10, --length_num);
    result_number += digit;
    num /= 10;
  }

  return sign * result_number;
}
