object = core.o
rootdir = /cygdrive/d/develop/roco
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libsubdir = $(libdir)/game
libname = gmcore
libsta = lib$(libname).a
libdyn = cyg$(libname).dll

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir) -I$(incdir)/core
CXXFLAGS = -std=gnu++17 -g3 $(CXXINC)
LIBS = -lp -L$(libdir)

all: lib install

lib: $(object)
	$(AR) cru $(libsta) $(object)
	$(CXX) $(CXXFLAGS) $(object) -fPIC -shared -o $(libdyn) $(LIBS)

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

install:
	mkdir -p $(bindir) $(libdir)
	cp $(libsta) $(libdir)
	cp $(libdyn) $(bindir)

clean:
	rm -f *.o *.a *.dll
