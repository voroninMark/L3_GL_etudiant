PACKAGES = gtkmm-2.4 libvlc
CXXFLAGS = -std=c++11 -Wall -Wextra -g -Isrc
LDFLAGS = 
LIBS = -lboost_system -lboost_filesystem

LIB_OBJ = src/play_video/Filesystem.o

GUI_BIN = bin/play_video_gui.out
GUI_OBJ = src/play_video_gui/play_video_gui.o \
		  src/play_video_gui/PlayerWindow.o

TEST_BIN = bin/play_video_test.out
TEST_OBJ = src/play_video_test/play_video_test.o

CXXFLAGS += `pkg-config --cflags $(PACKAGES)`
LDFLAGS +=`pkg-config --libs-only-L --libs-only-other $(PACKAGES)`
LIBS +=`pkg-config --libs-only-l $(PACKAGES)`

.PHONY : all clean 

all: $(GUI_BIN) $(TEST_BIN)

$(GUI_BIN): $(LIB_OBJ) $(GUI_OBJ)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

$(TEST_BIN): $(LIB_OBJ) $(TEST_OBJ)
	mkdir -p $(@D)
	$(CXX) $(CXXFLAGS) $(LDFLAGS) -o $@ $^ $(LIBS)

clean:
	rm -f $(LIB_OBJ) $(GUI_OBJ) $(GUI_BIN)  $(TEST_OBJ) $(TEST_BIN) 

