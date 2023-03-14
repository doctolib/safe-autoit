CXX = x86_64-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror --std=c++17 -I include
LDFLAGS += -static-libgcc -static-libstdc++ -lwinpthread
SRCS = \
	src/autoit_instance_symbols.cpp \
	src/autoit_instance.cpp \
	src/entry_points.cpp \
	src/pool.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = AutoItX3_x64.dll
BASE = $(NAME:%.dll=%)

TEST_NAME = test.exe
TEST_SRCS = test/test.cpp
TEST_OBJS = $(TEST_SRCS:%.cpp=%.o)

all: $(NAME) $(TEST_NAME)

clean:
	rm -f $(OBJS) $(TEST_OBJS)

fclean: clean
	rm -f $(NAME) $(TEST_NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(LDFLAGS) $(OBJS)

$(TEST_NAME): $(TEST_OBJS) $(NAME)
	$(CXX) -o $(TEST_NAME) $(CXXFLAGS) $(LDFLAGS) $(TEST_OBJS) -L. -l$(BASE)

.PHONY: all clean fclean re test
