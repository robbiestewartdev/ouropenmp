# Makefile for sample program
.PHONY			: all clean

# the program to build
NAME			:= ouropenmp

# Build tools and flags
INCLUDES := 
LIBS := 


CXX			:= g++
LD			:= g++

OBJS                    := ouropenmp.o 
CPPFLAGS		:= -w -I $(INCLUDES) -std=c++11 -Wno-write-strings  -Wl,-rpath -Wl,$ORIGIN -rdynamic -fopenmp
LDFLAGS			:= -L $(LIBS) -lpthread -lgomp -std=c++11 -O3 -lnvinfer -lnvinfer_plugin -lnvparsers -lstdc++fs

all			: $(NAME)

$(NAME)			: $(OBJS)
	$(LD) -o $@ $^ $(CPPFLAGS) $(LDFLAGS)  

%.o		: %.cpp 
	$(CXX) $(CPPFLAGS) -c -o $@ $<

clean			:
	$(RM) *.o $(NAME)