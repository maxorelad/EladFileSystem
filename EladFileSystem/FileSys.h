#pragma once
#include "Disk.h"
#include "FAT.h"
#include <iostream>
class FileSys
{
private:
	Disk disk;
	FAT fat;
public:
	void createFile(const std::string& fileName, const char* content);

	void deleteFile(const std::string& fileName);

	void readFile(const std::string& fileName);
};

