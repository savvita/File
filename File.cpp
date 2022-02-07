#include "File.h"

unsigned int File::_find(const std::string& str)
{
	std::string temp;

	unsigned int count = 0;

	while (std::getline(this->file, temp))
	{
		if (temp == str)
			count++;
	}
	this->_toBegin();

	return count;
}

unsigned int File::_findSubstring(const std::string& str)
{
	std::string temp;

	unsigned int count = 0;

	while (std::getline(file, temp))
	{
		if (temp.find(str) < std::string::npos)
			count++;
	}
	this->_toBegin();

	return count;
}

void File::_toBegin()
{
	this->file.clear();
	this->file.seekg(0, std::ios::beg);
}

File::File(const std::string& path)
{
	this->file.open(path, std::ios::in | std::ios::out);
}

bool File::open(const std::string& path)
{
	this->close();

	this->file.open(path, std::ios::in | std::ios::out);

	if (!this->isOpened())
		return false;

	return true;
}

void File::close()
{
	if (this->isOpened())
		this->file.close();
}

bool File::isOpened() const
{
	return this->file.is_open();
}

unsigned int File::find(const std::string& str, bool isSubstring)
{
	if (!this->isOpened())
		throw std::exception("File is not open\n");

	if(isSubstring)
		return this->_findSubstring(str);

	return this->_find(str);
}

unsigned int File::replace(const std::string& oldStr, const std::string& newStr)
{
	if (!this->isOpened())
		throw std::exception("File is not open\n");

	std::string temp;

	unsigned int count = 0;

	SLinkedList<std::string> text;

	while (std::getline(this->file, temp))
	{
		if (temp == oldStr)
		{
			text.add(newStr);
		}
		else
		{
			text.add(temp);
		}
	}

	this->_toBegin();
	this->file.clear();

	text.print(this->file);
	this->file.flush();

	this->_toBegin();

	return count;
}

void File::reverse()
{
	if (!this->isOpened())
		throw std::exception("File is not open\n");

	std::string temp;

	SLinkedList<std::string> text;

	while (std::getline(this->file, temp))
	{
		text.add(temp);
	}

	this->_toBegin();
	this->file.clear();

	unsigned int count = text.size();

	for (unsigned int i = 0; i < count; i++)
	{
		this->file << text[count - i - 1] << "\n";
	}

	this->file.flush();

	this->_toBegin();
}

void File::show()
{
	if (!this->isOpened())
		throw std::exception("File is not open\n");

	std::string temp;

	while (std::getline(this->file, temp))
	{
		std::cout << temp << "\n";
	}

	this->_toBegin();
}

File::~File()
{
	this->close();
}
