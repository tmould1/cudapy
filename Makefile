CXXFLAGS =	-O2 -g -Wall -fmessage-length=0

OBJS =		cuda_apy.o

LIBS =

TARGET =	cuda_apy

$(TARGET):	$(OBJS)
	$(CXX) -o $(TARGET) $(OBJS) $(LIBS)

all:
	python setup.py build_ext -i
clean:
	rm -f $(OBJS) $(TARGET)
