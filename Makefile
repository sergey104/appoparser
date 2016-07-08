appo : main.o    
	g++ -o appo main.cpp -ljsoncpp

main.o : main.cpp    
	g++ -c main.cpp 

clean :   
	rm edit main.o    
