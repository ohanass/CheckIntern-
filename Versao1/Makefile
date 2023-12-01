CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -O3 -std=c++11 -I include/ 

all: main

#vaga:
vaga:
	@mkdir -p build
	$(CC) $(CFLAGS) -c src/vaga.cpp -o build/vaga.o
estagiario:
	$(CC) $(CFLAGS) -c src/estagiario.cpp -o build/estagiario.o
empresa:
	$(CC) $(CFLAGS) -c src/empresa.cpp -o build/empresa.o
sistema:
	$(CC) $(CFLAGS) -c src/sistema.cpp -o build/sistema.o

# Modifique a funcao main
main: vaga estagiario empresa sistema
	$(CC) $(CFLAGS) build/vaga.o build/estagiario.o build/empresa.o build/sistema.o src/main.cpp -o $(TARGET)
	@clear
clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
