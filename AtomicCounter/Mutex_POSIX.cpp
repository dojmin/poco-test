#include "Mutex_POSIX.h"
#include <unistd.h>
#include <sys/time.h>

MutexImpl::MutexImpl()
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
#if defined(PTHREAD_MUTEX_RECURSIVE_NP)
	pthread_mutexattr_settype_np(&attr, PTHREAD_MUTEX_RECURSIVE_NP);
#elif !defined(POCO_VXWORKS) 
	pthread_mutexattr_settype(&attr, PTHREAD_MUTEX_RECURSIVE);
#endif
	if (pthread_mutex_init(&_mutex, &attr))
	{
		pthread_mutexattr_destroy(&attr);
		//throw SystemException("cannot create mutex");
	}
	pthread_mutexattr_destroy(&attr);
}

MutexImpl::MutexImpl(bool fast)
{
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
#if defined(PTHREAD_MUTEX_RECURSIVE_NP)
	pthread_mutexattr_settype_np(&attr, fast ? PTHREAD_MUTEX_NORMAL_NP : PTHREAD_MUTEX_RECURSIVE_NP);
#elif !defined(POCO_VXWORKS)
	pthread_mutexattr_settype(&attr, fast ? PTHREAD_MUTEX_NORMAL : PTHREAD_MUTEX_RECURSIVE);
#endif
	if (pthread_mutex_init(&_mutex, &attr))
	{
		pthread_mutexattr_destroy(&attr);
		//throw SystemException("cannot create mutex");
	}
	pthread_mutexattr_destroy(&attr);
}

MutexImpl::~MutexImpl()
{
	pthread_mutex_destroy(&_mutex);
}

FastMutexImpl::FastMutexImpl(): MutexImpl(true)
{
}

FastMutexImpl::~FastMutexImpl()
{
}
