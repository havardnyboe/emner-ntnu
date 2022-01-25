# Name of the executable
EXECUTABLE := program

# Library path
GRAPH_LIB_DIR := $(HOME)/.config/Code/User/globalStorage/tdt4102ntnu.tdt4102-tools/tdt4102/Graph_lib
GRAPH_LIB_INCLUDE := $(GRAPH_LIB_DIR)/include

FLTK_DIR := $(HOME)/.config/Code/User/globalStorage/tdt4102ntnu.tdt4102-tools/tdt4102/FLTK
FLTK_INCLUDE := $(FLTK_DIR)/include
FLTK_LIB := $(FLTK_DIR)/lib

TDT4102_DIR := $(HOME)/.config/Code/User/globalStorage/tdt4102ntnu.tdt4102-tools/tdt4102/TDT4102
TDT4102_INCLUDE := $(TDT4102_DIR)

# Output directories
DEBUG_OUT := Debug
RELEASE_OUT := Release

# Use clang as compiler and linker
# Use C++17 and suppress false positive warnings
CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wno-overloaded-virtual -I$(GRAPH_LIB_INCLUDE) -I$(FLTK_INCLUDE) -I$(TDT4102_INCLUDE)
LDFLAGS = -L$(FLTK_LIB) 
LINK = $(CXX)

# fltk-config returns compiler and linker flags needed successfully
# build fltk programs.
ifdef DEBUG
CXXFLAGS += $(shell /bin/bash $(FLTK_DIR)/fltk-config-debug --use-images --cxxflags)
LDFLAGS += $(shell /bin/bash $(FLTK_DIR)/fltk-config-debug --use-images --ldstaticflags)
else
CXXFLAGS += $(shell /bin/bash $(FLTK_DIR)/fltk-config-release --use-images --cxxflags)
LDFLAGS += $(shell /bin/bash $(FLTK_DIR)/fltk-config-release --use-images --ldstaticflags)
endif

LDFLAGS += -lstdc++fs

SOURCES := $(wildcard *.cpp)
GRAPH_LIB_SOURCES := $(wildcard $(GRAPH_LIB_DIR)/src/*.cpp)
TDT4102_SOURCES := $(wildcard $(TDT4102_DIR)/src/*.cpp)

ifdef DEBUG
CXXFLAGS += -g -ggdb -O0 -DDEBUG
OUT := $(DEBUG_OUT)
GRAPH_LIB := Graph_libd
else
CXXFLAGS += -O3 -DNDEBUG
OUT := $(RELEASE_OUT)
GRAPH_LIB := Graph_lib
endif

SOUCES_BUILDDIR = $(OUT)/sources

TDT4102_BUILDDIR = $(OUT)/TDT4102
TDT4102_OBJECTS = $(TDT4102_BUILDDIR)/AnimationWindow.o $(TDT4102_BUILDDIR)/InputHandler.o $(TDT4102_BUILDDIR)/MoveableImage.o $(TDT4102_BUILDDIR)/ShapeDrawQueue.o

GRAPH_LIB_BUILDDIR = $(OUT)/Graph_lib
GRAPH_LIB_OBJECTS = $(GRAPH_LIB_BUILDDIR)/Graph.o $(GRAPH_LIB_BUILDDIR)/GUI.o $(GRAPH_LIB_BUILDDIR)/Window.o

OBJECTS := $(SOURCES:%.cpp=$(SOUCES_BUILDDIR)/%.o) $(GRAPH_LIB_OBJECTS) $(TDT4102_OBJECTS)

$(OUT):
	mkdir -p $@

# There is probably a better way to do this, but this works without any hassle
$(TDT4102_BUILDDIR)/AnimationWindow.o:
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $(TDT4102_DIR)/AnimationWindow.cpp -o $@

$(TDT4102_BUILDDIR)/InputHandler.o:
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $(TDT4102_DIR)/InputHandler.cpp -o $@

$(TDT4102_BUILDDIR)/MoveableImage.o:
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $(TDT4102_DIR)/MoveableImage.cpp -o $@

$(TDT4102_BUILDDIR)/ShapeDrawQueue.o:
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $(TDT4102_DIR)/ShapeDrawQueue.cpp -o $@

$(GRAPH_LIB_BUILDDIR)/Graph.o:
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $(GRAPH_LIB_DIR)/src/Graph.cpp -o $@

$(GRAPH_LIB_BUILDDIR)/GUI.o:
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $(GRAPH_LIB_DIR)/src/GUI.cpp -o $@

$(GRAPH_LIB_BUILDDIR)/Window.o:
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $(GRAPH_LIB_DIR)/src/Window.cpp -o $@

$(SOUCES_BUILDDIR)/%.o: %.cpp
	mkdir -p ./$(dir $(subst //,/,$@))
	$(CXX) $(CXXFLAGS) -c $< -o $(subst //,/,$@)

$(OUT)/$(EXECUTABLE): $(OUT) $(OBJECTS)
	$(LINK) -g $(OBJECTS) -o $@ $(LDFLAGS)

.PHONY: runrelease rundebug
runrelease: release
	./$(RELEASE_OUT)/$(EXECUTABLE)
rundebug: debug
	./$(DEBUG_OUT)/$(EXECUTABLE)

.PHONY: clean cleandebug cleanrelease
clean: cleandebug cleanrelease
cleandebug:
	$(RM) $(DEBUG_OUT)/$(EXECUTABLE)
	$(RM) -r $(DEBUG_OUT)/sources
cleanrelease:
	$(RM) $(RELEASE_OUT)/$(EXECUTABLE)
	$(RM) -r $(RELEASE_OUT)/sources

# Helpers to build release and debug binaries
.PHONY: debug release
debug:
	DEBUG=1 $(MAKE) $(DEBUG_OUT)/$(EXECUTABLE)
release:
	$(MAKE) $(RELEASE_OUT)/$(EXECUTABLE)


# Helper to clean console
.PHONY: clearscreen
clearscreen:
	clear
