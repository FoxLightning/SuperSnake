#include "Observer.h"


void Observer::add_subscriber(Subscriber* subscriber)
{
	subscribers_list.push_back(subscriber);
}

void Observer::remove_subscriber(Subscriber* subscriber)
{
	subscribers_list.remove(subscriber);
}
