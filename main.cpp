#include <iostream>
#include <string>
#include "my_data.h"

using namespace std;

int main() {
	MyData tool;

	cout << "****************************************" << endl;
	cout << "english-chinese-dictionary --version 1.0" << endl;
	cout << "to provide you with translation services" << endl;
	cout << "you can get help by 'help'" << endl;
	cout << "****************************************" << endl;
	
	bool is_open = true;
	while (is_open) {
		cout << ">";

		string key_str, key, str;
		getline(cin, key_str);
		if (key_str.find(" ") != key_str.npos) {
			int pos = key_str.find_first_of(" ") + 1;
			key = key_str.substr(0, pos - 1);
			str = key_str.substr(pos);
		}

		if (key_str.empty()) {

		}
		else if (key_str == "help") {
			cout << "���õ����" << endl;
			cout << "\tfind\t����һ�����ʵĺ��﷭��" << endl;
			cout << "\tadd\t����һ����������" << endl;
			cout << "\tdelete\tɾ��һ�����ʵ�����" << endl;
			cout << "\tquit\t�˳�����" << endl;
			cout << "\thelp\t��ȡ����" << endl;
		}
		else if (key_str == "quit") {
			is_open = false;
			cout << "Bye ! Have a good day." << endl;
		}
		else if (key_str == "add" || key_str == "a") {
			string english, chinese;
			cout << "english:";
			cin >> english;
			cout << "chinese:";
			cin >> chinese;
			if (tool.AddData(english, chinese) == "EMPTY") {
				cout << "���󣺲��������" << endl;
			}
			else {
				cout << endl;
			}
		}
		else if (key == "find" || key == "f") {
			cout << tool.MyHashSearch(str) << endl;
		}
		else if (key == "delete" || key == "d") {
			string res = tool.DeleteData(str);
			if (res == "EMPTY") {
				cout << "����ɾ��������" << endl;
			}
			else if (res == "NOT_FIND"){
				cout << "�������ݲ�����" << endl;
			}
			else {
				cout << endl;
			}
		}
		else {
			cout << "������Ч���" << endl;
			cout << "��ʹ�� help �鿴������Ϣ��" << endl;
		}
	}

	return 0;
}
