source = *.cpp
object = *.o
executable = *.exe
rootdir = /cygdrive/d/develop/roco
incdir = $(rootdir)/include
incdepdir = /cygdrive/d/develop
libdir = $(rootdir)/lib
libfile = libgcore.a

CXX = g++
CXXFLAGSINC = -I$(incdepdir) -I$(incdir)/core -I$(incdir)/ui
CXXFLAGSLNK = -lgame -L$(libdir)
CXXFLAGS = -std=gnu++17 $(CXXFLAGSINC) $(CXXFLAGSLNK)

all: check

check test:
	$(foreach var, $(wildcard $(source)), $(CXX) $(var) $(CXXFLAGS))
	$(foreach var, $(wildcard $(executable)), ./$(var))
