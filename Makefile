CXX = i686-w64-mingw32-g++
CXXFLAGS += -Wall -Wextra -Werror
SRCS = autoit_instance_symbols.cpp
	entry_points.cpp \
	autosync.cpp
OBJS = $(SRCS:%.o=%.cpp)
NAME = safe-autoit.dll

$(NAME): $(OBJS)
	$(CXX) -o $(NAME) $(CXXFLAGS) $(OBJS)

depend: .depend

.depend: $(SRCS)
	rm -f ./.depend
	$(CXX) $(CXXFLAGS) -MM $^ -MF  ./.depend;

include .depend
