object = main.o
rootdir = /cygdrive/d/develop/roco
bindir = $(rootdir)/bin
incdir = $(rootdir)/include
depdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libsubdir = $(libdir)/game
libname = game
libsta = lib$(libname).a
libdyn = cyg$(libname).dll

CXX = g++
CXXINC = -I$(depdir) -I$(incdir) -I$(incdir)/core -I$(incdir)/ui
CXXFLAGS = -std=gnu++17 -Wall -g3 $(CXXINC)
LIBS = -lgmui -lgmacc -lgmcore -lp -L$(libdir)

all: lib install-lib bin install-bin

re: clean all

bin: $(object)
	$(CXX) $(CXXFLAGS) $(object) $(LIBS) -o roco.exe

lib: lib-dep lib-rec
	$(AR) cru $(libsta) */*.o
	$(CXX) $(libsta) -fPIC -shared -o $(libdyn)

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

lib-dep:
	cp $(depdir)/libp/lib/*.a $(libdir)
	cp $(depdir)/libp/bin/*.dll $(bindir)

lib-rec:
	$(MAKE) -C core
	$(MAKE) -C account
	$(MAKE) -C ui

install: install-bin install-lib

install-bin:
	mkdir -p $(bindir)
	cp roco.exe $(bindir)

install-lib:
	cp $(libsta) $(libdir)
	cp $(libdyn) $(bindir)

clean: clean-rec clean-bin clean-lib

clean-bin:
	rm -f *.exe

clean-lib:
	rm -f *.a *.o *.dll

clean-rec:
	$(MAKE) -C core clean
	$(MAKE) -C account clean
	$(MAKE) -C ui clean
