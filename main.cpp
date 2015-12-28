#include <iostream>
#include <stdio.h>
#include "./src/helloworld.h"
#include <pthread.h>
#include <unistd.h>
#include <time.h>

using namespace std;

static int times = 1;

void* tf_get_keyboard(void* arg)
{
	string stInput  = "";
	std::cout << std::endl <<"\033[31m "<<  __FUNCTION__ << " runing " << "\033[0m" << std:: endl;
	while(true)
	{
		std:: cout << " send:" ;
		getline(std::cin, stInput, '\n');
		if(stInput == "exit")
		{
			int ret_val = 1;
			std::cout << "\033[31m exit thread.\033[0m" << std::endl;
			pthread_exit((void*)&ret_val);
		}
		else
		{
			std:: cout << "\t<< " << stInput << endl;
		}

	}
}

void* thread1(void* pm)
{
	while(1)
	{
		std::cout << "thread 1: " <<  times <<std:: endl;
		times++;
		sleep(2);
	}
}

void* thread2(void* pm)
{
	while(1)
	{
		std::cout<< "thread 2: " << times << std::endl;
		times++;
		sleep(2);
	}
}


int main(int argc, char const *argv[])
{
	void* ret_val;
	say_hello();

	pthread_t  pt;
	pthread_create(&pt, NULL, tf_get_keyboard, NULL);
	pthread_join(pt, NULL);

	pthread_t pt1, pt2;
	pthread_create(&pt1, NULL, thread1, NULL);
	pthread_create(&pt2, NULL, thread2, NULL);

	pthread_join(pt1, NULL);
	pthread_join(pt2, NULL);



	return 0;
}