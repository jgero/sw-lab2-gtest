#CXX := clang++
#CXXFLAGS := -c -std=c++14 -Weverything -Wno-c++98-compat -Wno-c++98-compat-pedantic -Wno-invalid-source-encoding -Wno-global-constructors -Wno-exit-time-destructors -Wno-missing-prototypes -Wno-weak-vtables -Wno-padded -pedantic -ferror-limit=1 
#GCC_INSTALL_PREFIX=/usr/local/bin ggf. anpassen
CXX := g++
CXXFLAGS := -Wall -c -std=c++14 -pedantic -fmax-errors=1

### Windows
ifeq "$(findstring Windows,$(OS))" "Windows"
CXXFLAGS+=-DWIN32
endif

EXE := generator.exe

OBJS := $(patsubst %.cpp,%.o,$(wildcard *.cpp))
HEADERS := $(wildcard *.h)
TEMPLATES := $(wildcard *.t)
.PHONY: clean

$(EXE): $(OBJS)
	-$(CXX) -o $(EXE) $(OBJS) $(LDFLAGS)

$(OBJS): %.o : %.cpp  $(HEADERS) $(TEMPLATES)
	-$(CXX) $(CXXFLAGS) $(INCLUDE) $< -o $@

clean:
	rm -f $(OBJS) $(EXE)

