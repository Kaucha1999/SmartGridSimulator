CXX = g++
CXXFLAGS = -std=c++17 -Wall

OBJS = main.o power_source.o load.o breaker.o grid_manager.o logger.o

simulator: $(OBJS)
	$(CXX) $(CXXFLAGS) -o simulator $(OBJS)

main.o: main.cpp power_source.hpp load.hpp breaker.hpp grid_manager.hpp
power_source.o: power_source.cpp power_source.hpp
load.o: load.cpp load.hpp
breaker.o: breaker.cpp breaker.hpp load.hpp
grid_manager.o: grid_manager.cpp grid_manager.hpp power_source.hpp breaker.hpp logger.hpp
logger.o: logger.cpp logger.hpp

clean:
	rm -f *.o simulator
