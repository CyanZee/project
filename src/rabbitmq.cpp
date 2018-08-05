#include <iostream>

#include "rabbitmq.h"

RabbitmqManager::RabbitmqManager(std::string host, std::string que_name_in, std::string que_name_out):mq_host(host),queue_name_in(que_name_in),queue_name_out(que_name_out) {
	channel = AmqpClient::Channel::Create(host);
	channel->DeclareQueue(queue_name_in, false, false, false, false);
	channelout = AmqpClient::Channel::Create(host);
	channelout = DeclareQueue(queue_name_out, false, false, false, false);
 }

void RabbitmqManager::Recv() {
	std::string consumer_tag = channel->BasicConsume(queue_name_in, "");
	while (1) {
		AmqpClient::Envelope::ptr_t envelope = channel->BasicConsumeMessage(consumer_tag);
		std::string buffer = envelope->Message()->Body();
		std::cout << "the recv buffer: " << buffer << std::endl;
	}
	channel->BasicCancel(consumer_tag);
}


void RabbitmqManager::Send(std::striing meg) {
	std::cout << "the message: " << meg << std::endl;
	channelout->BasicPublish("", queue_name_out, AmqpClient::BasicMessage::Create(meg));
}


