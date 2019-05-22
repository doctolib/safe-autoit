CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror --std=c++17
LDFLAGS += -static-libgcc -static-libstdc++
SRCS = test.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = test.exe

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(LDFLAGS) $(OBJS)

.PHONY: all clean fclean re
