CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror
LDFLAGS += -static-libgcc -static-libstdc++ -Bstatic -lpthread -Bdynamic
SRCS = \
	autoit_instance_symbols.cpp \
	autoit_instance.cpp \
	entry_points.cpp \
	pool.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = AutoItX3.dll
BASE = $(NAME:%.dll=%)
DEPS = $(SRCS:%.cpp=%.d)

TEST = test.exe

all: $(NAME) $(TEST)

$(TEST): $(OBJS) test.o $(NAME)
	$(CXX) -o $(TEST) $(CXXFLAGS) $(LDFLAGS) -L . -l$(BASE) $(OBJS) test.o

include $(DEPS)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(LDFLAGS) $(OBJS)

%.d: %.cpp
	$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

clean:
	rm -f *.o *.d

fclean: clean
	rm -f $(NAME) $(TEST)

re: fclean all
