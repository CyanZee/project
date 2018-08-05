#ifndef _RABBITMQ_H_
#define _RABBITMQ_H_

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>

class RabbitmqManager {
public:
	RabbitmqManager(std::string mq_host, std::string queue_name);
	~RabbitmqManager();

	void Recv();
	void Send();	

	AmqpClient::Channel::ptr_t channel;
	AmqpClient::Channel::ptr_t channelout;

private:
	std::string mq_host;
	std::string queue_name_in;	
	std::string queue_name_out;
};
