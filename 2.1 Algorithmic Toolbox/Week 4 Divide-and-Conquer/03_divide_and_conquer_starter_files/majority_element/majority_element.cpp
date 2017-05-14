#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int k = right / 2;
  int major_left = get_majority_element(a, left, left+k-1);
  int major_right = get_majority_element(a, left+k, right);
  int count_left = 0;
  int count_right = 0;
  for (int i=0; i<a.size(); i++){
	  if (a[i] == major_left){
		  count_left++;
	  }
	  if (a[i] == major_right){
		  count_right++;
	  }
  }
  if (count_left > right/2){
	  return major_left;
  }
  if (count_right > right/2){
	  return major_right;
  }
  return -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  system("pause");
}
