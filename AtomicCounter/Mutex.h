#ifndef Mutex_INCLUDED
#define Mutex_INCLUDED
#include "Mutex_POSIX.h"
#include "ScopedLock.h"

class Mutex: private MutexImpl
{
public:
	typedef ::ScopedLock<Mutex> ScopedLock;

	Mutex();
	~Mutex();

	void lock();
	//void lock(long milliseconds);
	bool tryLock();
	//bool tryLock(long milliseconds);
	void unlock();
private:
	Mutex(const Mutex&);
	Mutex& operator = (const Mutex&);
};


class FastMutex: private MutexImpl
{
public:
        typedef ::ScopedLock<FastMutex> ScopedLock;
        FastMutex();
        ~FastMutex();
        void lock();
        //void lock(long milliseconds);
        bool tryLock();
        //bool tryLock(long milliseconds);
        void unlock();
private:
        FastMutex(const FastMutex&);
        FastMutex& operator = (const FastMutex&);
};

inline void Mutex::lock()
{
	lockImpl();
}

inline bool Mutex::tryLock()
{
	return tryLockImpl();
}

inline void Mutex::unlock()
{
	unlockImpl();
}




inline void FastMutex::lock()
{
	lockImpl();
}
inline bool FastMutex::tryLock()
{
	return tryLockImpl();
}
inline void FastMutex::unlock()
{
	unlockImpl();
}




#endif
