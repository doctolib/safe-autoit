CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror
SRCS = \
	autoit_instance_symbols.cpp \
	autoit_instance.cpp \
	entry_points.cpp \
	pool.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = safe-autoit.dll

all: $(NAME)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(OBJS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ -MF  ./.depend;

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all

include .depend
