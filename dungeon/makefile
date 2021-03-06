PROGRAM		= dungeon

SDIR		:= src
IDIR		:= include

CXX			?= g++
INCLUDES	:= -I $(IDIR)
C_FLAGS		:= -Wall -Wextra -Wshadow -std=c++11
RC_FLAGS	:= -O2
DC_FLAGS	:= -g -DDEBUG -D_GLIBCXX_DEBUG -D_GLIBCXX_DEBUG_PEDANTIC -D_GLIBCXX_DEBUG_PEDANTIC_ASSERT

ifeq ($(DEBUG), 1)
	CXXFLAGS := $(CXXFLAGS) $(C_FLAGS) $(DC_FLAGS)
	ODIR := obj\\debug
	BDIR := bin\\debug
else
	CXXFLAGS := $(CXXFLAGS) $(C_FLAGS) $(RC_FLAGS)
	ODIR := obj\\release
	BDIR := bin\\release
endif

EXE			:= $(BDIR)\\$(PROGRAM)
SRCS		:= $(wildcard $(SDIR)/*.cpp)
OBJS		:= $(SRCS:$(SDIR)/%.cpp=$(ODIR)\\%.o)

all: run

run: $(EXE)
	$<

$(EXE): dirs $(OBJS)
	$(CXX) $(OBJS) -o $@

$(ODIR)\\%.o: $(SDIR)\\%.cpp
	$(CXX) $(CXXFLAGS) $(INCLUDES) -MP -MMD -c $< -o $@

dirs:
	@-mkdir $(BDIR)
	@-mkdir $(ODIR)

clean:
	$(RM) -r obj bin

show:
	@echo 'EXE      :' $(EXE)
	@echo 'CXX      :' $(CXX)
	@echo 'CXXFLAGS :' $(CXXFLAGS)
	@echo 'BDIR     :' $(BDIR)
	@echo 'SDIR     :' $(SDIR)
	@echo 'ODIR     :' $(ODIR)
	@echo 'SRCS     :' $(SRCS)
	@echo 'OBJS     :' $(OBJS)
