#include <iostream>
#include <string>
#include "my_data.h"

using namespace std;

//�޲ι���
//���ļ���ȡ���ݹ������й�ϣ�����
//����ŵ����������
MyData::MyData() {
	string key_array[1000];
	string val_array[1000];
	string file_name;
	int length = 0;
	MyFile file;
	
	char ch = 'a';
	for (int i = 0; i < 26; i++) {
		file_name = "TXT\\";
		file_name += ch;
		file_name += "_.txt";
		
		file.set_file_name(file_name);
		length = file.ReadData(); 
		file.CopyEnglishDataTo(key_array, length);
		file.CopyChineseDataTo(val_array, length); 
		avl_tree_[i] = new AvlTree(key_array, val_array, length);
		my_hash_[i] = new MyHash(key_array, val_array, length);
		ch++;
	}
}

//��������
//�ͷ������и�����ռ�õĶ�̬�ڴ�ռ�
MyData::~MyData() {
	for (int i = 0; i < 26; i++) {
		delete avl_tree_[i];
		delete my_hash_[i];
	}
}

//���ù�ϣ��Ĳ���
string MyData::MyHashSearch(string english) {
	if (english.empty()) {
		return "NOT_FIND";
	}
	
	char first_ch = *english.begin();
	if (first_ch >= 'A' && first_ch <= 'Z') {
		first_ch += 32;
	}

	int in = first_ch - 97;

	return my_hash_[in]->GetVal(english);
}

//����AVl���Ĳ���
string MyData::AvlTreeSearch(string english) {
	if (english.empty()) {
		return "NOT_FIND";
	}

	char first_ch = *english.begin();
	if (first_ch >= 'A' && first_ch <= 'Z') {
		first_ch += 32;
	}

	int in = first_ch - 97;

	return avl_tree_[in]->GetVal(english);
}

//����һ����������
string MyData::AddData(string english, string chinese) {
	if (english.empty()) {
		return "EMPTY";
	}

	char first_ch = *english.begin();
	if (first_ch >= 'A' && first_ch <= 'Z') {
		first_ch += 32;
	}

	int in = first_ch - 97;
	my_hash_[in]->Insert(english, chinese);
	avl_tree_[in]->Insert(english, chinese);

	return english;
}

//ɾ��һ����������
string MyData::DeleteData(string english) {
	if (english.empty()) {
		return "EMPTY";
	}

	char first_ch = *english.begin();
	if (first_ch >= 'A' && first_ch <= 'Z') {
		first_ch += 32;
	}

	int in = first_ch - 97;
	string del_chinese = my_hash_[in]->Delete(english);
	avl_tree_[in]->Delete(english);

	return del_chinese;
}
