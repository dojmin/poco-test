#ifndef MutexImpl_INCLUDED
#define MutexImpl_INCLUDED

#include <pthread.h>
#include <errno.h>
#include <iostream>

using namespace std;

class MutexImpl
{
protected:
	MutexImpl();
	MutexImpl(bool fast);
	~MutexImpl();
	void lockImpl();
	bool tryLockImpl();
	bool tryLockImpl(long milliseconds);
	void unlockImpl();
private:
	pthread_mutex_t _mutex;
};

class FastMutexImpl: public MutexImpl
{
protected:
	FastMutexImpl();
	~FastMutexImpl();
};

inline void MutexImpl::lockImpl()
{
	if (pthread_mutex_lock(&_mutex)) 
		cout << "cannot lock mutex" << endl;	
	//	throw SystemException("cannot lock mutex");
}


inline bool MutexImpl::tryLockImpl()
{
	int rc = pthread_mutex_trylock(&_mutex);
	if (rc == 0)
		return true;
	else if (rc == EBUSY)
		return false;
	else
		cout << "cannot lock mutex" << endl;	
		//throw SystemException("cannot lock mutex");
}


inline void MutexImpl::unlockImpl()
{
	if (pthread_mutex_unlock(&_mutex))
		cout << "cannot lock mutex" << endl;	
		//throw SystemException("cannot unlock mutex");
}


#endif
