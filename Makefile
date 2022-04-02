CXX = g++
CXXFLAGS = -fPIC -Wall -Wextra -g
LDFLAGS = -shared       
RM = rm -f                       
TARGET_LIB = libbst.so       

SRCS = Node.cpp               
OBJS = $(SRCS:.cpp=.o)                    

.PHONY: all
all: ${TARGET_LIB} install

$(TARGET_LIB): $(OBJS)
	$(CXX) ${LDFLAGS} -o $@ $^

$(SRCS:.cpp=.d):%.d:%.cpp
	$(CXX) $(CXXFLAGS) -MM $< >$@

include $(SRCS:.cpp=.d)

.PHONY: clean
clean:
	-${RM} ${TARGET_LIB} ${OBJS} $(SRCS:.cpp=.d)

.PHONY: install
install:
	cp $(TARGET_LIB) /usr/lib/
	cp Node.h /usr/include/node.h