#include <iostream>
#include <fstream>
#include <string>
#include "my_file.h"

using namespace std;

//�޲ι���
MyFile::MyFile() {
	file_name_ = "";
	length_ = 0;
}

//���캯��
//ָ���������ļ���������ȡ�����ݳ��ȸ�ֵΪ 0
MyFile::MyFile(string file_name) {
	file_name_ = file_name;
	length_ = 0;
}

//�����ļ����������ü�¼����������
//���������ļ������������������õ��ļ�
void MyFile::set_file_name(string file_name) {
	file_name_ = file_name;
	length_ = 0;
}

//���ַ�������ȡ��Ӣ�ĵ���
string MyFile::ExtractEnglish_(string str) {
	int pos = str.find_first_of(" ");
	string goal = str.substr(0, pos);

	return goal;
}

//���ַ�������ȡ�����﷭��
string MyFile::ExtractChinese_(string str) {
	int pos = str.find_first_of(" ") + 3;
	string goal = str.substr(pos);

	return goal;
}

//����洢�ĵ������ݿ�����һ������
void MyFile::CopyEnglishDataTo(string array[], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = english_[i];
	}
}

//����洢�ĺ������ݿ�����һ������
void MyFile::CopyChineseDataTo(string array[], int length) {
	for (int i = 0; i < length; i++) {
		array[i] = chinese_[i];
	}
}

//�Զ����ƴ��ļ��а��ж�ȡ���ݣ������ض�ȡ�������ݳ���
int MyFile::ReadData() {
	ifstream infile(file_name_.c_str(), ios::in|ios::binary);
	
	if (!infile) {
		cerr << "open error!" << endl;
		abort();
	} 

	for (int i = 0; i < kDataMaxSize && infile.peek() != EOF; i++) {
		char buff[kBuffLen];
		//����һ������
		infile.getline(buff, kBuffLen);
		//�������char������תΪ string ����
		string tempStr(buff);
		//�洢��������
		english_[i] = ExtractEnglish_(tempStr);
		//�洢��������
		chinese_[i] = ExtractChinese_(tempStr);
		length_++;
	}

	infile.close();

	return length_;
}

//��һ��������ָ������������д���ļ�������д������ݵ�����
//���ļ���Ϊ�գ���������ļ�����
int MyFile::WriteDataOf(string array[], int length) {
	ofstream outfile(file_name_.c_str(), ios::out|ios::binary);

	if (!outfile) {
		cerr << "open error!" << endl;
		abort();
	}
	
	int count = 0;
	char ch = '\n';
	for (int i = 0; i < length; i++) {
		//д������
		outfile.write(array[i].c_str(), sizeof(array[i]));
		//����
		outfile.write("\n", sizeof(ch));
		count++;
	}

	outfile.close();

	return count;
}
