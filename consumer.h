/*
 * consumer.h
 *
 *  Created on: Feb 4, 2018
 *      Author: willy
 */

#ifndef CONSUMER_H_
#define CONSUMER_H_

#include <thread>
#include "osqueue1.h"
#include <iostream>
#include <functional>

class Consumer
{
public:

	Consumer(Osqueue& osqueue)
	{
		m_osqueue = &osqueue;
	};

	void receiveMessage(Osqueue& osqueue)
	{
		std::cout<<"consuming"<<std::endl;
		m_osqueue->print();

	}

	void sendMessage(int msg)
	{
		m_osqueue->sendMessage(msg);
	}

	void run()
	{
		for(;;)
		{
			(void)receiveMessage(*m_osqueue);
		}
		t1.join();

	}

	void init()
	{
		t1 = std::thread(&Consumer::run, this);
	}

	std::thread t1;
	Osqueue* m_osqueue;

};



#endif /* CONSUMER_H_ */
