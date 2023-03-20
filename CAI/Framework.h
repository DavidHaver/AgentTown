#pragma once
#include "MainServer.h"
#include "message.h"
#include "GameEngine.h"
#include "QueueManager.h"

class Framework
{
private:
	std::unique_ptr<MainServer> base_server;

	boost::asio::io_context io_context_;
	GameEngine engine;
	std::thread context_thread, engine_thread;
	boost::asio::ip::tcp::endpoint end_point;

	std::string host;
	int port;

	std::shared_ptr<QueueManager<message::message>> message_pipeline_;
public:
	Framework();
	~Framework();
};

