.SUFFIXES : .cpp .o 

CC = g++
CXXFLAGS = -g -W -O2  
LIBS = -lpthread
INC = -I./

TARGET = test

SOURCES = main.cpp \
		Mutex_POSIX.cpp \
		Mutex.cpp \
		AtomicCounter.cpp

OBJECTS = main.o \
		Mutex_POSIX.o \
		Mutex.o \
		AtomicCounter.o
		

.cpp.o :
	$(CXX) $(CXXFLAGS) $(INC) -c -o $@ $< 

all: $(TARGET)

$(TARGET) : $(OBJECTS)
	$(CC) $(CXXFLAGS) -o $@ $^ $(LIBS)

clean:
	-rm -rf $(OBJECTS) $(TARGET)
	

