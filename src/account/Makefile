object = accfile.o account.o user.o
rootdir = /cygdrive/d/develop/roco
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib/game
libfile = libgacc.a
libdyn = cyggacc.dll

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir) -I$(incdir)/core -I$(incdir)/account
CXXFLAGS = -std=gnu++17 -g3 -DROCO_IN $(CXXINC)

all: lib install

lib: $(object)
	$(AR) cru $(libfile) $(object)
	$(CXX) $(CXXFLAGS) $(object) -fPIC -shared -o $(libdyn)

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install:
	mkdir -p $(libdir)
	cp $(libfile) $(libdir)

clean:
	rm -f *.o *.a
