all:sensor-demo

sensor-demo:rpy.o fun.o main.o
	g++ $^ -o $@
rpy.o: rpy.cpp rpy.h
	g++ rpy.cpp -c
fun.o: fun.cpp fun.h
	g++ fun.cpp -c
main.o: main.cpp rpy.h fun.h
	g++ main.cpp -c
clean:
	rm -rf *.o sensor-demo
run:
	./sensor-demo
	
