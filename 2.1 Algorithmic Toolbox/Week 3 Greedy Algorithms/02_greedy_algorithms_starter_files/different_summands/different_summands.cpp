#include <iostream>
#include <vector>

using std::vector;

vector<int> optimal_summands(int n) {
  vector<int> summands;
  summands[0] = 1;
  int Test = 2;
  int Total = 3;
  while (Total <=  n){
	  summands.push_back(Test);
	  Test += 1;
	  Total += Test;
  }
  summands[-1] += n - (Total - Test);
  return summands;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
}
