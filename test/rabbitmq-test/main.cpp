#include <iostream>

#include "rabbitmq.h"

int main()
{
	RabbitmqManager *mq = RabbitmqManager::getInstance();
	mq->Producer("hello",sizeof("hello"));
	while(1);
	std::cout<< "+++ main() end +++" << std::endl;
	return 0;
}
