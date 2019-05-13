CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror
SRCS = \
	autoit_instance_symbols.cpp \
	autoit_instance.cpp \
	entry_points.cpp \
	pool.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = safe-autoit.dll
DEPS = $(SRCS:%.cpp=%.d)


all: $(NAME)

include $(DEPS)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(OBJS)

%.d: %.cpp
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
