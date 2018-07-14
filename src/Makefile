source = *.cpp
object = *.o
rootdir = /cygdrive/d/develop/roco
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
bindir = $(rootdir)/bin
libdir = $(rootdir)/lib/game
libfile = $(libdir)/*.a

CXX = g++
CXXFLAGSINC = -I$(incdepdir) -I$(incdir)
CXXFLAGSLNK = -lgui -L$(libdir)
CXXFLAGS = -std=gnu++17 -Wall -g3 $(CXXFLAGSINC) $(CXXFLAGSLNK)

all: bin install

bin:
	$(CXX) $(source) -c $(CXXFLAGS)
	$(CXX) $(object) -o roco.exe $(CXXFLAGS)

install:
	mkdir -p $(bindir)
	cp roco.exe $(bindir)

clean:
	rm -f *.exe
