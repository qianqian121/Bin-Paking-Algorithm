#pragma once
#include <string>//CStringͷ�ļ�
#include "vector"
using namespace std;

class FileManager
{
public:

	static std::string GetFilePath();//��һ�����ڣ�ѡ��һ��TXT�ļ�
	static vector<vector<int>> GetFileIntData(std::string path);//��ȡtxt��ÿ�о��εĿ��ߡ�����

};

