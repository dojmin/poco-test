#ifndef AtomicCounter_INCLUDED
#define AtomicCounter_INCLUDED
#include "Mutex.h"

class AtomicCounter
{
public:
	typedef int ValueType;
	
	AtomicCounter();

	explicit AtomicCounter(ValueType initialValue);

	AtomicCounter(const AtomicCounter& counter);

	~AtomicCounter();

	AtomicCounter& operator = (const AtomicCounter& counter);

	AtomicCounter& operator = (ValueType value);

	operator ValueType () const;

	ValueType value() const;

	ValueType operator ++ (); //perfix

	ValueType operator ++ (int);

	ValueType operator -- ();

	ValueType operator -- (int);

	bool operator ! () const;

private:

	struct ImplType
	{
		mutable FastMutex mutex;
		volatile int value;
	};
	
	ImplType _counter;
};

inline AtomicCounter::operator AtomicCounter::ValueType() const
{
	ValueType result;
	{
		FastMutex::ScopedLock lock(_counter.mutex);
		result = _counter.value;
	}
	return	result;
}

inline AtomicCounter::ValueType AtomicCounter::value() const
{
	ValueType result;
	{
		FastMutex::ScopedLock lock(_counter.mutex);
		result = _counter.value;
	}
	return	result;
}

inline AtomicCounter::ValueType AtomicCounter::operator ++ () // prefix
{
	ValueType result;
	{
		FastMutex::ScopedLock lock(_counter.mutex);
		result = ++_counter.value;
	}
	return result;
}

	
inline AtomicCounter::ValueType AtomicCounter::operator ++ (int) // postfix
{
	ValueType result;
	{
		FastMutex::ScopedLock lock(_counter.mutex);
		result = _counter.value++;
	}
	return result;
}


inline AtomicCounter::ValueType AtomicCounter::operator -- () // prefix
{
	ValueType result;
	{
		FastMutex::ScopedLock lock(_counter.mutex);
		result = --_counter.value;
	}
	return result;
}

	
inline AtomicCounter::ValueType AtomicCounter::operator -- (int) // postfix
{
	ValueType result;
	{
		FastMutex::ScopedLock lock(_counter.mutex);
		result = _counter.value--;
	}
	return result;
}

	
inline bool AtomicCounter::operator ! () const
{
	bool result;
	{
		FastMutex::ScopedLock lock(_counter.mutex);
		result = _counter.value == 0;
	}
	return result;
}

#endif
