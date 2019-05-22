CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror --std=c++17
LDFLAGS += -static-libgcc -static-libstdc++ -lwinpthread
SRCS = \
	autoit_instance_symbols.cpp \
	autoit_instance.cpp \
	entry_points.cpp \
	pool.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = AutoItX3.dll
BASE = $(NAME:%.dll=%)

all: $(NAME)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(LDFLAGS) $(OBJS)
