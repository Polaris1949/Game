source = *.cpp
object = *.o
rootdir = /cygdrive/d/develop/roco
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib/game
libfile = libgui.a

CXX = g++
CXXFLAGSINC = -I$(incdepdir) -I$(incdir)/core -I$(incdir)/ui
CXXFLAGS = -std=gnu++17 -c -g3 $(CXXFLAGSINC)

all: lib install

lib:
	$(CXX) $(source) $(CXXFLAGS)
	ar cru $(libfile) $(object)

install:
	mkdir -p $(libdir)
	cp $(libfile) $(libdir)

clean:
	rm -f *.o *.a
