#include <iostream>
#include <map>
#include <string>
#include <vector>
using namespace std;

void go(int cacheSize, vector<string> cities) {
	if (cacheSize == 0) {
		cout << 5 * cities.size() << endl;
		return;
	}
	for (int j = 0; j < cities.size(); j++) {
		for (int i = 0; i < cities[j].size(); i++) {
			if (cities[j][i] > 'Z') {
				cities[j][i] = cities[j][i] - 'a' + 'A';
			}
		}
	}
	map<string, int> cache;
	int time = 1;
	int answer = 0;
	for (auto city : cities) {		
		// miss
		if (cache.find(city) == cache.end()) {
			// full 
			if (cache.size() == cacheSize) {
				int LRU_time = 99999999;
				string LRU_city;
				for (auto city2 : cache) {
					if (city2.second < LRU_time) {
						LRU_time = city2.second;
						LRU_city = city2.first;
					}
				}
				cache.erase(cache.find(LRU_city));
				cache.insert({ city, time++ });
			}
			// not full
			else {
				cache.insert({ city, time++ });
			}
			answer += 5;
		}
		// hit
		else {
			cache[city] = time++;
			answer += 1;
		}
	}
	cout << answer << endl;
}

int main() {
	/*int cacheSize = 3;
	vector<string> cities(10);
	cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA"};
	go(cacheSize, cities);*/

	/*int cacheSize = 3;
	vector<string> cities(9);
	cities = { "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul", "Jeju", "Pangyo", "Seoul" };
	go(cacheSize, cities);*/

	/*int cacheSize = 2;
	vector<string> cities(12);
	cities = {"Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome"};
	go(cacheSize, cities);*/

	/*int cacheSize = 5;
	vector<string> cities(12);
	cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" };
	go(cacheSize, cities);*/


	/*int cacheSize = 2;
	vector<string> cities(4);
	cities = { "Jeju", "Pangyo", "NewYork", "newyork" };
	go(cacheSize, cities);*/

	/*int cacheSize = 0;
	vector<string> cities(5);
	cities = { "Jeju", "Pangyo", "Seoul", "NewYork", "LA" };
	go(cacheSize, cities);*/
}