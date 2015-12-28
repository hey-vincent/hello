#include "helloworld.h"
#include <string>
using namespace std;

void say_hello()
{
	std::cout << "\033[1m who you are ?\033[0m"<< std::endl;
	string st_name = "";
	getline(std::cin, st_name, '\n');
	std::cout << "\033[34mHello " << st_name << ". Welcome to Linux. Wish you enjoy it! Let's begin.\033[0m" 
		<< std::endl << std:: endl;
}