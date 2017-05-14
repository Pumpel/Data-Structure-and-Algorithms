#include <iostream>
#include <vector>
using std::vector;

vector<int> pisano(int n){
	long long previous = 0;
	long long current = 1;

	vector<int> cycle;
	cycle.push_back(0);
	cycle.push_back(1);
	int i = 1;

	while ( i == 1){
		long long tmp_previous = previous;
		previous = current;
		current = (tmp_previous + current) % n;
		cycle.push_back(current);
		int m = cycle.size();
		vector<int>::const_iterator first = cycle.begin();
		vector<int>::const_iterator mid = cycle.begin() + int(m/2);
		vector<int>::const_iterator last = cycle.end();
		vector<int> v1(first, mid);
		vector<int> v2(mid, last);
		if (m%2 == 0 && m != 0 && v1 == v2){
			break;
		}
	}
	int clen = cycle.size();
	vector<int>::const_iterator first = cycle.begin();
	vector<int>::const_iterator mid = cycle.begin()+int(clen/2);
	vector<int> pisano(first, mid);
	return pisano;
}

int fibonacci_sum_fast(int n) {
    // the nth fibonacci is F(n+2) - 1
	vector<int> cycle;
	cycle = pisano(10);
	int clen = cycle.size();
	return cycle.at((n+2) % clen) -1;
}

int main() {
    long long n = 0;
    std::cin >> n;
	vector<int> cycle;
	cycle = pisano(10);
	int clen = cycle.size();
	std::cout << fibonacci_sum_fast(n) << std::endl;

	system("pause");
}
