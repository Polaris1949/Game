object = main.o
rootdir = /cygdrive/d/develop/roco
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
bindir = $(rootdir)/bin
libdir = $(rootdir)/lib/game
libfile = $(libdir)/libgui.a $(libdir)/libgacc.a

CXX = g++
CXXINC = -I$(incdepdir) -I$(incdir)
LIBS = -lgame -L$(bindir)
CXXFLAGS = -std=gnu++17 -Wall -DROCO_IN -g3 $(CXXINC)

all: lib bin install

bin: $(object)
	$(CXX) $(CXXFLAGS) $(object) $(LIBS) -o roco.exe

lib: lib-rec
	$(AR) cru libgame.a */*.a
	$(CXX) ui/cyggui.dll account/cyggacc.dll -fPIC -shared -o cyggame.dll

$(object): %.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

lib-rec:
	$(MAKE) -C account
	$(MAKE) -C ui

install: install-bin install-lib

install-bin:
	mkdir -p $(bindir)
	cp roco.exe $(bindir)

install-lib:
	cp libgame.a $(libdir)
	cp cyggame.dll $(bindir)

clean: clean-rec clean-bin clean-lib

clean-bin:
	rm -f *.exe

clean-lib:
	rm -f *.a *.o *.dll

clean-rec:
	$(MAKE) -C account clean
	$(MAKE) -C ui clean
