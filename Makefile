TARGET := TinyDB

SRC = TinyDB.cpp main.cpp

CC = g++

INCLUDE = -I/usr/local/mysql/include
LIB = -L/usr/local/mysql/lib/
LIBS = -lmysqlclient

CXXFLAG = #-std=c++11

$(TARGET) : $(SRC)
	$(CC) $(CXXFLAG) -o $@ $(SRC) $(INCLUDE) $(LIB) $(LIBS) 
clean:
	rm $(TARGET)
