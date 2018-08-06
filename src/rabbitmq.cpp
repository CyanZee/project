#include <iostream>

#include "rabbitmq.h"

RabbitmqManager *RabbitmqManager::instance = 0;

RabbitmqManager::RabbitmqManager() {
	std::cout << "+++ try to create rabbitmqManager object." << std::endl;
	mq_host = "localhost";
	mq_queue_name = "tester";
	channel = AmqpClient::Channel::Create(mq_host);
	channel->DeclareQueue(mq_queue_name, false, true, false, false);
	channelout = AmqpClient::Channel::Create(mq_host);
	channelout->DeclareQueue(mq_queue_name, false, true, false, false);
	
	if (0 != pthread_create(&recvthread, NULL, recv, this))
	{
		std::cout << "--- pthread_create recvthread failed." << std::endl;
	}
	if (0 != pthread_create(&sendthread, NULL, send, this))
	{ 
		std::cout << "--- pthread_create sendthread failed." << std::endl;
	}
 }

RabbitmqManager::~RabbitmqManager() { }

RabbitmqManager *RabbitmqManager::getInstance() {
	if (!instance)
	{
		instance = new RabbitmqManager();
	}
	return instance;
}

void *RabbitmqManager::recv(void *parm) {
	RabbitmqManager *mq = (RabbitmqManager *)parm;

	std::string consumer_tag = mq->channel->BasicConsume(mq->mq_queue_name, "");
	std::cout << "+++ enter Recv() the consumer_tag is: " << consumer_tag << std::endl;
	while (1) {
		AmqpClient::Envelope::ptr_t envelope = mq->channel->BasicConsumeMessage(consumer_tag);
		std::string buffer = envelope->Message()->Body();
		std::cout << "the recv buffer: " << buffer << std::endl;
	}
	mq->channel->BasicCancel(consumer_tag);
	return NULL;
}

void *RabbitmqManager::send(void *parm) {
	RabbitmqManager *mq = (RabbitmqManager *)parm;

	std::string msg = "{\"name\":\"cyan\"}";
	std::cout << "the message: " << msg << std::endl;
	mq->channelout->BasicPublish("", mq->mq_queue_name, AmqpClient::BasicMessage::Create(msg));
	return NULL;
}

message * RabbitmqManager::Consumer() {
	
	return NULL;
}

void RabbitmqManager::Producer(const std::string &msgdata, int dsize) {
	
	std::cout << "+++ the msgdata is: " << msgdata << std::endl;
	std::cout << "+++ the dsize is: " << dsize << std::endl;
}



