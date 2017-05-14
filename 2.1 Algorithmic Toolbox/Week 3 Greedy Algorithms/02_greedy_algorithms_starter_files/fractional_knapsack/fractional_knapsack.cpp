#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using std::vector;

vector<int> get_index(vector<double>& ratio){
	vector<int> idx(ratio.size());
	std::iota(idx.begin(),idx.end(),0);
	std::sort(idx.begin(), idx.end(), [&](double a, double b){return ratio[a] > ratio[b];});
	return idx;
}

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
  double value = 0.0;

  vector<double> vpw(weights.size());
  for(int i = 0; i < weights.size(); i++){
	  vpw[i] = double(values[i]) / double(weights[i]);
  }

  int rem = capacity;
  vector<int> index = get_index(vpw);
  for(int i = 0; i < index.size(); i++){
	  int item = rem;
	  if(item >= weights[index[i]]){
		  item = weights[index[i]];
		  value += item * vpw[index[i]];
		  rem -= item;
	  }
	  else{
		  value += item * vpw[index[i]];
		  rem -= item;
	  }
  }

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }

  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;

  system("pause");
  return 0;
}
