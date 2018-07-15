object = ui.o
rootdir = /cygdrive/d/develop/roco
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib/game
libfile = libgui.a
libdyn = cyggui.dll
libdep = $(libdir)/libgacc.a

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir) -I$(incdir)/core -I$(incdir)/ui
CXXFLAGS = -std=gnu++17 -g3 -DROCO_IN $(CXXINC)

all: lib install

lib: $(object)
	$(AR) cru $(libfile) $(object)
	$(CXX) $(CXXFLAGS) $(object) $(libdep) -fPIC -shared -o $(libdyn)

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install:
	mkdir -p $(libdir)
	cp $(libfile) $(libdir)

clean:
	rm -f *.o *.a
