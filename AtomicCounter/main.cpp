#include "ScopedLock.h"
#include "Mutex.h"

using namespace std;

FastMutex _mutex;
void funTest()
{
	FastMutex::ScopedLock lock(_mutex);
}

int main()
{
	funTest();
	return -1;
}
