#pragma once
#include<fstream>
#include<string>
#include<iostream>
#include"SLinkedList.h"

class File
{
private:
	std::fstream file;

	unsigned int _find(const std::string& str);
	unsigned int _findSubstring(const std::string& str);

	void _toBegin();

public:
	File() = default;
	explicit File(const std::string& path);

	bool open(const std::string& path);
	void close();

	bool isOpened() const;

	unsigned int find(const std::string& str, bool isSubstring = false);
	unsigned int replace(const std::string& oldStr, const std::string& newStr);

	void reverse();

	void show();

	~File();
};

