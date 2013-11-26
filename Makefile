CC     = g++
SRC    = codegen.cpp
INC    = -I~/workspace/llvm/include
CONF   = `/home/hiroki/workspace/llvm/Debug+Asserts/bin/llvm-config --cxxflags --ldflags --libs`

all:
	$(CC) $(INC) $(SRC) $(CONF) -o codegen -lpthread -ldl
	./codegen

clean:
	rm codegen
