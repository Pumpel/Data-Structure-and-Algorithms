#include <iostream>

int get_change(int m) {
	int coins[3] = {10, 5, 1};
	int result = 0;
	int remainder = m;
	for (int i = 0; i < 3; i++){
		result += remainder / coins[i];
		remainder = remainder % coins[i];
	}
  return result;
}

int main() {
  int m;
  std::cin >> m;
  std::cout << get_change(m) << '\n';
  system("pause");
}
