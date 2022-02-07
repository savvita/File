#include<fstream>
#include<string>
#include<iostream>
#include"File.h"

int main()
{
	File f("44.txt");
	f.show();
	std::cout << "=======================\n";
	//f.replace("Yakov, 3333333333333", "++++++++++++++++++++++++");
	f.reverse();
	f.show();

}

