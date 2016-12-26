#include "AtomicCounter.h"

AtomicCounter::AtomicCounter()
{
		_counter.value = 0;
}

	
AtomicCounter::AtomicCounter(AtomicCounter::ValueType initialValue)
{
		_counter.value = initialValue;
}


AtomicCounter::AtomicCounter(const AtomicCounter& counter)
{
		_counter.value = counter.value();
}


AtomicCounter::~AtomicCounter()
{
}


AtomicCounter& AtomicCounter::operator = (const AtomicCounter& counter)
{
		FastMutex::ScopedLock lock(_counter.mutex);
		_counter.value = counter.value();
		return *this;
}

	
AtomicCounter& AtomicCounter::operator = (AtomicCounter::ValueType value)
{
		FastMutex::ScopedLock lock(_counter.mutex);
		_counter.value = value;
		return *this;
}
