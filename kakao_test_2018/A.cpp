#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<pair<string, string>> cmd_list;
	map<string, string> nick_list;
	vector<string> answer;


	for (int i = 0; i < record.size(); i++) {
		string rest;
		int idx;
		string command, uid, nick;

		rest = record[i];
		idx = rest.find(' ');
		command = rest.substr(0, idx);
		rest = rest.substr(idx + 1);		
		idx = rest.find(' ');
		uid = rest.substr(0, idx);
		rest = rest.substr(idx + 1);
		nick = rest;

		cmd_list.push_back({ command, uid });
		if (command == "Leave") continue;
		nick_list[uid] = nick;
	}

	for (int i = 0; i < cmd_list.size(); i++) {
		auto cur = cmd_list[i];
		if (cur.first == "Enter") {
			string uid = cur.second;
			string nick = nick_list[uid];
			string s = nick + "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù.";
			answer.push_back(s);
		}
		else if (cur.first == "Leave") {
			string uid = cur.second;
			string nick = nick_list[uid];
			string s = nick + "´ÔÀÌ ³ª°¬½À´Ï´Ù.";
			answer.push_back(s);
		}
	}



	return answer;
}

int main() {
	vector<string> record(5);
	record = {
		"Enter uid1234 Muzi",
		"Enter uid4567 Prodo",
		"Leave uid1234",
		"Enter uid1234 Prodo",
		"Change uid4567 Ryan" };
	
	vector<string> a = solution(record);

	for (auto s : a) {
		cout << s << endl;
	}

}