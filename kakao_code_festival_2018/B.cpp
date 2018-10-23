#include <iostream>
#include <cmath>
using namespace std;

int N, K;
int num_list[500];
double answer = 999999;

double mean(int start, int end) {
	int sum = 0;
	for (int i = start; i < end; i++) {
		sum += num_list[i]; 
	}
	return sum / double(end-start);
}

double variance(int start, int end, double mean) {
	double sum = 0;
	for (int i = start; i < end; i++) {
		sum += pow(num_list[i] - mean, 2);
	}
	return sum / double(end-start);
}

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> num_list[i];
	}

	while (K <= N) {
		for (int i = 0; i < N - K + 1; i++) {
			double m = mean(i, i + K);
			
			double v = variance(i, i + K, m);
			double s = sqrt(v);

			//cout << "m: " << m << "/ v: " << v << " / s: " << s << endl;
			if (s < answer) answer = s;
		}
		K++;
	}
	//cout << answer << '\n';
	printf("%.11f\n", answer);
}

