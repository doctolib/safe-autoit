CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror
LDFLAGS += -static-libgcc -static-libstdc++ -lwinpthread
SRCS = \
	autoit_instance_symbols.cpp \
	autoit_instance.cpp \
	entry_points.cpp \
	pool.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = AutoItX3.dll
BASE = $(NAME:%.dll=%)
DEPS = $(SRCS:%.cpp=%.d)

all: $(NAME)

clean:
	rm -f *.o *.d

fclean: clean
	rm -f $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(LDFLAGS) $(OBJS)

%.d: %.cpp
	$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

include $(DEPS)
