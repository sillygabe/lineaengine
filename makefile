main:
	g++-13 main.cpp -o main -F /Library/Frameworks -framework SDL2 -framework SDL2_image -framework SDL2_ttf -std=c++20 -Wall

clean:
	rm main
	clear