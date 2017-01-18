CXXFLAGS = -Wall -Wextra -std=c++11
BIN = readfile_exception.out readfile_errno.out

all: $(BIN)

%.out: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f $(BIN)

