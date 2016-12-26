#ifndef ScopedLock_INCLUDED
#define ScopedLock_INCLUDED
#include <iostream>
#include <stdexcept>
using namespace std;

template <class M>

class ScopedLock
{
public:
	explicit ScopedLock(M& mutex): _mutex(mutex)
	{
		cout << "ScopedLock Locked!!!" << endl;
		_mutex.lock();		
	}

	ScopedLock(M& mutex, long milliseconds): _mutex(mutex)
	{
		_mutex.lock(milliseconds);
	}

	~ScopedLock()
	{
		try
		{
			_mutex.unlock();	
		}
		catch(...)
		{
			cout << "~ScopedLock Exeption" << endl;
		}
		cout << "ScopedLock UnLocked!!!" << endl;
	}
private:
	M& _mutex;
	ScopedLock();
	ScopedLock(const ScopedLock&);
	ScopedLock& operator = (const ScopedLock&);
};

#endif
