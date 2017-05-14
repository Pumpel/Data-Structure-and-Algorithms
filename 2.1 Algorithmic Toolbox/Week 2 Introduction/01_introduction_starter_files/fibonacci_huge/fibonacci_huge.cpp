#include <iostream>
#include <vector>
using std::vector;

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
    }

    return current % m;
}

long long get_fibonacci_huge_fast(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
	vector<long long> cycle;
	cycle.push_back(0);
	cycle.push_back(1);
	int i = 1;
	
    while (i == 1) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
		cycle.push_back(current);
		int clen = cycle.size();
		vector<long long>::const_iterator first = cycle.begin();
		vector<long long>::const_iterator mid = cycle.begin()+int(clen/2);
		vector<long long>::const_iterator last = cycle.end();
		vector<long long> v1(first, mid);
		vector<long long> v2(mid, last);
		if(clen%2 == 0 && clen != 0 && v1 == v2){
			break;
		}
    }

	int clen = cycle.size();
	vector<long long>::const_iterator first = cycle.begin();
	vector<long long>::const_iterator mid = cycle.begin()+int(clen/2);
	vector<long long> pisano(first, mid);
	int clen1 = pisano.size();

    return pisano.at(n % clen1);
}

int main() {
    long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_fast(n, m) << '\n';

	system("pause");
}
