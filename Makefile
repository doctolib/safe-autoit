CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror
LDFLAGS += -static-libgcc -static-libstdc++ -Bstatic -lpthread -Bdynamic
SRCS = \
	autoit_instance_symbols.cpp \
	autoit_instance.cpp \
	entry_points.cpp \
	pool.cpp
OBJS = $(SRCS:%.cpp=%.o)
NAME = safeautoit.dll
DEPS = $(SRCS:%.cpp=%.d)

TEST = minimize-all.exe

all: $(NAME) $(TEST)

$(TEST): $(OBJS) test.o $(NAME)
	$(CXX) -o $(TEST) $(CXXFLAGS) $(LDFLAGS) -L . -lsafeautoit $(OBJS) test.o

include $(DEPS)

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) -shared $(CXXFLAGS) $(LDFLAGS) $(OBJS)

%.d: %.cpp
	@$(CXX) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean all
