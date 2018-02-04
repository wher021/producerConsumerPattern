/*
 * osqueue1.h
 *
 *  Created on: Feb 4, 2018
 *      Author: willy
 */

#ifndef OSQUEUE1_H_
#define OSQUEUE1_H_

#include <iostream>
#include <mutex>

class Osqueue
{
public:
	Osqueue()
	{

	}
	void print()
	{
		g_num_mutex2.lock();
		int i = 0;
		while(i < 100)
		{
			std::cout<<m_array[i];
			i++;
		}
		g_num_mutex2.unlock();
	}

	void sendMessage(int msg)
	{
		g_num_mutex.lock();
		int i = 0;
		while(m_array[i] != 0)
		{
			i++;
		}
		m_array[i] = msg;
		g_num_mutex.unlock();
	}
	int m_array[100] = {0};
	std::mutex g_num_mutex;
	std::mutex g_num_mutex2;
};


#endif /* OSQUEUE1_H_ */
