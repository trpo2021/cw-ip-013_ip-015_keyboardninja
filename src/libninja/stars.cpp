#include <libninja/stars.hpp>

int stars (int mistakes, int time) 
{
	if (mistakes > 45)
		return 0;
	else if (mistakes > 30)
		return 1;
	else if (mistakes > 15 && time > 15)
		return 2;
	else if (time > 25)
		return 3;
	return -1;		
}
