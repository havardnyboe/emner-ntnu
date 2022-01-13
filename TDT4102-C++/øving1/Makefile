# Name of the executable
EXECUTABLE := program

# Library path
GRAPH_LIB_DIR := $(HOME)/Library/tdt4102/Graph_lib
GRAPH_LIB_INCLUDE := $(GRAPH_LIB_DIR)/include
GRAPH_LIB_LIB := $(GRAPH_LIB_DIR)/lib

FLTK_DIR := $(HOME)/Library/tdt4102/FLTK
FLTK_INCLUDE := $(FLTK_DIR)/include
FLTK_LIB := $(FLTK_DIR)/lib

TDT4102_DIR := $(HOME)/Library/tdt4102/TDT4102
TDT4102_INCLUDE := $(TDT4102_DIR)


# Output directories
DEBUG_OUT := Debug
RELEASE_OUT := Release

# Use clang as compiler and linker
# Suppress false positive warnings
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wno-overloaded-virtual -I$(GRAPH_LIB_INCLUDE) -I$(TDT4102_INCLUDE) --target=x86_64-apple-darwin-macho
LDFLAGS = -L$(GRAPH_LIB_LIB) -l$(GRAPH_LIB) --target=x86_64-apple-darwin-macho
LINK = $(CXX)

# fltk-config returns compiler and linker flags needed to successfully
# build fltk programs.
CXXFLAGS += -I$(FLTK_INCLUDE) -I$(FLTK_INCLUDE)/FL/images -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D_THREAD_SAFE -D_REENTRANT #$(shell fltk-config --use-images --cxxflags)
LDFLAGS += -L$(FLTK_LIB) -lfltk_images -lfltk_jpeg -lfltk_png -lz -lfltk -lm -lpthread -framework Cocoa

SOURCES := $(wildcard *.cpp)
TDT4102_SOURCES := $(wildcard $(TDT4102_DIR)/*.cpp)

ifdef DEBUG
CXXFLAGS += -g -O0 -DDEBUG
OUT := $(DEBUG_OUT)
GRAPH_LIB := Graph_libd
else
CXXFLAGS += -O3 -DNDEBUG
OUT := $(RELEASE_OUT)
GRAPH_LIB := Graph_lib
endif

OBJECTS := $(SOURCES:%.cpp=$(OUT)/%.o) $(TDT4102_SOURCES:%.cpp=$(OUT)/%.o)

$(OUT):
	mkdir -p $@

$(OUT)/%.o: %.cpp
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $< -o $(subst //,/,$@)

$(OUT)/$(EXECUTABLE): $(OUT) $(OBJECTS)
	$(LINK) $(OBJECTS) -o $@ $(LDFLAGS)

.PHONY: runrelease rundebug
runrelease: release
	./$(RELEASE_OUT)/$(EXECUTABLE)
rundebug: debug
	./$(DEBUG_OUT)/$(EXECUTABLE)

.PHONY: clean cleandebug cleanrelease
clean: cleanrelease cleandebug
cleandebug:
	$(RM) -r $(DEBUG_OUT)
cleanrelease:
	$(RM) -r $(RELEASE_OUT)

# Helpers to build release and debug binaries
.PHONY: debug release
debug:
	DEBUG=1 $(MAKE) $(DEBUG_OUT)/$(EXECUTABLE)
release:
	$(MAKE) $(RELEASE_OUT)/$(EXECUTABLE)
