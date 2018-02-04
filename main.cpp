/*
 * main.cpp
 *
 *  Created on: Feb 3, 2018
 *      Author: willy
 */
#include "module1/module1.h"
#include "osqueue1.h"
#include "consumer.h"

int main()
{
	Osqueue osqueue;

	Consumer consumer(osqueue);
	consumer.init();
	for(;;)
	{
		  std::this_thread::sleep_for (std::chrono::seconds(1));
		  consumer.sendMessage(5);
	}

}
