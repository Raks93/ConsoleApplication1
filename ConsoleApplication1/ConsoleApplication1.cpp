// ConsoleApplication1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>

int main()
{
	setlocale(LC_ALL, "ru");

	std::ifstream fin;
	fin.open("file.txt");

	if (!fin.is_open())
	{
		std::cout << "Ошибка открытия файла." << std::endl;
		std::cerr << "Error: " << strerror(errno) << std::endl;
	}
	else
	{
		
		std::cout << "Файл открыт!" << std::endl;
		std::string str;
		
		int i = 60;
		std::string err = "************************************************************";
		while (!fin.eof())
		{
			str = "";
			fin >> str;
			if (str != "" && i != 60)
			{
				std::cout  << " ";
				i -= 1;
			}
			if (i > str.length())
			{
				if(str == "")
				{
					if (i != 60) std::cout << std::endl;
				}
				else
				{
					std::cout << str ;
					i -= str.length();
				}
			}
			else if (i == str.length())
			{
				std::cout << str << std::endl;
				i = 60;
			}
			else
			{
				if (str.length() > 60)
				{
					if (i != 60) std::cout << std::endl;
					std::cout << err << std::endl;
					std::cout << "В строке ниже отсутствуют пробелы, и она больше 60 символов:" << std::endl;
					std::cout << str << std::endl;
					std::cout << err << std::endl;
					i = 60;
				}
				else if (str.length() == 60)
				{
					std::cout << std::endl;
					std::cout << str << std::endl;
					i = 60;
				}
				else
				{
					std::cout << std::endl;
					std::cout << str;
					i = 60 - str.length();
				}
			}
		}
	}

	fin.close();

    return 0;
}

