CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror --std=c++17 -I../include
LDFLAGS += -static-libgcc -static-libstdc++ -L.. -lAutoItX3
SRCS = test.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = test.exe

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean:
	rm -f $(OBJS) $(NAME)

re: fclean all

../AutoItX3.dll:
	make -C ..

$(NAME): $(OBJS) ../AutoItX3.dll
	$(CXX) -o $(NAME) $(CXXFLAGS) $(LDFLAGS) $(OBJS)

.PHONY: all clean fclean re
