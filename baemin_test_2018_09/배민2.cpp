#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <time.h>
using namespace std;

struct File {
	string name;
	string extension;
	string city;
	int year;
	int month;
	int day;
	int hour;
	int min;
	int sec;
	int order;
	int city_total;
};

bool cmp(File* a, File* b) {
	if (a->year < b->year) {
		return true;
	}
	if (a->year == b->year && a->month < b->month)
		return true;
	if (a->year == b->year && a->month == b->month && a->day < b->day)
		return true;
	if (a->year == b->year && a->month == b->month && a->day == b->day 
		&& a->hour < b->hour)
		return true;
	if (a->year == b->year && a->month == b->month && a->day == b->day 
		&& a->hour == b->hour && a->min < b->min)
		return true;
	if (a->year == b->year && a->month == b->month && a->day == b->day
		&& a->hour < b->hour && a->min == b->min && a->sec < b->sec)
		return true;


	return false;
}

string solution(string &S) {
	// write your code in C++14 (g++ 6.2.0)
	vector<string> s_list;

	while (S.find("\n") != string::npos) {
		s_list.push_back(S.substr(0, S.find("\n")));
		S = S.substr(S.find("\n") + 1);
	}
	s_list.push_back(S);

	vector<File> file_list;
	for (auto s : s_list) {
		string file_name = s.substr(0, s.find('.'));
		s = s.substr(s.find('.') + 1);
		string extension = s.substr(0, s.find(','));
		s = s.substr(s.find(',') + 2);
		string city = s.substr(0, s.find(','));
		s = s.substr(s.find(',') + 2);
		int year = stoi(s.substr(0, s.find('-')));
		s = s.substr(s.find('-') + 1);
		int month = stoi(s.substr(0, s.find('-')));
		s = s.substr(s.find('-') + 1);
		int date = stoi(s.substr(0, s.find(' ')));
		s = s.substr(s.find(' ') + 1);
		int hour = stoi(s.substr(0, s.find(':')));
		s = s.substr(s.find(':') + 1);
		int min = stoi(s.substr(0, s.find(':')));
		s = s.substr(s.find(':') + 1);
		int sec = stoi(s.substr(0, s.find(':')));

		file_list.push_back({ file_name, extension, city, year, month, date, hour, min, sec, 0, 0 });
	}

	map<string, vector<File*>> grouped_file;

	for (int i = 0; i < file_list.size(); i++) {
		grouped_file[file_list[i].city].push_back(&file_list[i]);
	}

	for (auto group : grouped_file) {
		sort(group.second.begin(), group.second.end(), cmp);
		for (int i = 0; i < group.second.size(); i++) {
			group.second[i]->order = i + 1;
			group.second[i]->city_total = group.second.size();
		}
	}

	string answer = "";
	for (int i = 0; i < file_list.size(); i++) {
		File file = file_list[i];
		int cnt = 0;
		int temp1 = file.city_total;
		int temp2 = file.order;
		temp1 /= 10;
		while (temp1 != 0) {
			cnt++;
			temp1 /= 10;
		}
		temp2 /= 10;
		while (temp2 != 0) {
			cnt--;
			temp2 /= 10;
		}
		answer += file.city;
		for (int i = 0; i < cnt; i++) {
			answer += "0";
		}
		answer += to_string(file.order);
		answer += "." + file.extension;
		if (i != file_list.size() - 1)
			answer += "\n";
	}
	return answer;
}

int main() {
	string S = "photo.jpg, Warsaw, 2013-09-05 14:08:15\n";
	S += "john.png, London, 2015-06-20 15:13:22\n";
	S += "myFriends.png, Warsaw, 2013-09-05 14:07:13\n";
	S += "Eiffel.jpg, Paris, 2015-07-23 08:03:02\n";
	S += "pisatower.jpg, Paris, 2015-07-22 23:59:59\n";
	S += "BOB.jpg, London, 2015-08-05 00:02:03\n";
	S += "notredame.png, Paris, 2015-09-01 12:00:00\n";
	S += "me.jpg, Warsaw, 2013-09-06 15:40:22\n";
	S += "a.png, Warsaw, 2016-02-13 13:33:50\n";
	S += "b.jpg, Warsaw, 2016-01-02 15:12:22\n";
	S += "c.jpg, Warsaw, 2016-01-02 14:34:30\n";
	S += "d.jpg, Warsaw, 2016-01-02 15:15:01\n";
	S += "e.png, Warsaw, 2016-01-02 09:49:09\n";
	S += "f.png, Warsaw, 2016-01-02 10:55:32\n";
	S += "g.jpg, Warsaw, 2016-02-29 22:13:11";

	
	cout << solution(S) << endl;
}