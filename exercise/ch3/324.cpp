#include <iostream>
#include <vector>

void sum_adjacent(const std::vector<int> &v) {
  if (v.size() < 2)
    return;
  for (auto it = v.begin(); it != v.end() - 1; ++it)
    std::cout << *it + *(it + 1) << '\t';
  std::cout << std::endl;
}

void sum_symmetric(const std::vector<int> &v) {
  // If the vector has odd size, element in the middle will add to itself.
  auto mid = v.begin() + (v.end() - v.begin() + 1) / 2;
  for (auto it = v.cbegin(); it != mid; ++it)
    std::cout << *it + *(v.end() - 1 - (it - v.begin())) << '\t';
  std::cout << std::endl;
}

int main() {
  std::vector<int> iv;
  int i;
  while (std::cin >> i)
    iv.push_back(i);

  sum_adjacent(iv);
  sum_symmetric(iv);

  return 0;
}