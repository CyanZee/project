#ifndef _RABBITMQ_H_
#define _RABBITMQ_H_

#include <SimpleAmqpClient/SimpleAmqpClient.h>
#include <string>
#include <pthread.h>
#include <mutex>
#include <queue>

typedef struct {
	char data[512];
	int size;
}message;

class RabbitmqManager {
public:
	~RabbitmqManager();
	
	static RabbitmqManager *getInstance();

	message *Consumer();
	void Producer(const std::string &msgdata, int dsize);		

private:
	
	RabbitmqManager();

	static void *recv(void *parm);
	static void *send(void *parm);	

	static RabbitmqManager *instance;

	AmqpClient::Channel::ptr_t channelout;
	AmqpClient::Channel::ptr_t channel;

	std::string mq_host;
	std::string mq_queue_name;	

	std::queue<message> recvDataQueue;
	std::queue<message> sendDataQueue;
	std::mutex recvQMutex;
	std::mutex sendQMutex;
	pthread_t recvthread;
	pthread_t sendthread;	
};

#endif
