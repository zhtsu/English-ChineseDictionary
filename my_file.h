#pragma once
#ifndef  __MYFILE__H__
#define __MYFILE__H__

#include <iostream>

using namespace std;

//��ȡ�������ݵ��������
const int kDataMaxSize = 1000;
//�����ļ����Ļ�������С
const int kBuffLen = 100;

//�ļ������࣬ʵ�ֳ�����ļ��Ķ�д����
class MyFile {
public:
	MyFile();
	MyFile(string file_name);

public:
	//���ò������ļ���
	void set_file_name(string file_name);
	//���ļ���ȡ����
	int ReadData();
	//���ļ�д������
	int WriteDataOf(string array[], int length);
	//�����������ݵ�ָ������
	void CopyEnglishDataTo(string array[], int length);
	//�����������ݵ�ָ������
	void CopyChineseDataTo(string array[], int length);

private:
	//��ȡ��������
	string ExtractEnglish_(string str);      
	//��ȡ��������
	string ExtractChinese_(string str);     

private:
	//�洢�ļ���
	string file_name_;
	//��¼�Ѷ�ȡ�����ݳ���
	int length_;          
	//�洢��ȡ���ĵ�������
	string english_[kDataMaxSize];
	//�洢��ȡ���ĺ�������
	string chinese_[kDataMaxSize];
};

#endif // !__MYFILE__H__
