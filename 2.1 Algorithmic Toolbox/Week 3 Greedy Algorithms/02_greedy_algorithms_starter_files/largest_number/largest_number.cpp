#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>

using std::vector;
using std::string;

bool cmp(const string& a, const string& b){
	if (a[0] != b[0]){
		return a[0] > b[0];
	}
	else if (a[0] == b[0] && a.length() > 1 && b.length() > 1){
		return a[1] > b[1];
	}
	else if (a[0] == b[0] && a.length() == 1 && b.length() > 1){
		return a[0] > b[1];
	}
	else if (a[0] == b[0] && a.length() > 1 && b.length() == 1){
		return a[1] > b[0];
	}
};

string largest_number(vector<string> a) {
  std::sort(a.begin(), a.end(), cmp);
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
  std::cout << std::endl;

  system("pause");
}
