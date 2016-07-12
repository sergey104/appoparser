appo : main.o    
	g++ -o appo main.cpp -ljsoncpp -g

main.o : main.cpp    
	g++ -c main.cpp 

clean :   
	rm edit main.o    
