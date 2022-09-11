#include "SaveManager.h"
#include <string>

float SaveManager::GetSave()
{
	std::ifstream is("resources/save.txt");
	std::string line;
	std::getline(is, line);
	return std::stoi(line);
}

void SaveManager::SetSave(const char* p_n)
{
	std::ofstream is("resources/save.txt");
	is.write(p_n, 1);
}
