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
testeVaga:
	$(CC) $(CFLAGS) src/TesteVaga.cpp build/vaga.o -o Testes/TesteVaga	
curriculo:
	$(CC) $(CFLAGS) -c src/curriculo.cpp -o build/curriculo.o
testeCurriculo:
	$(CC) $(CFLAGS) src/TesteCurriculo.cpp build/curriculo.o -o Testes/TesteCurriculo
aluno:
	$(CC) $(CFLAGS) -c src/aluno.cpp -o build/aluno.o
usuario:
	$(CC) $(CFLAGS) -c src/usuario.cpp -o build/usuario.o
empresa:
	$(CC) $(CFLAGS) -c src/empresa.cpp -o build/empresa.o
colegiado:
	$(CC) $(CFLAGS) -c src/colegiado.cpp -o build/colegiado.o

# Modifique a funcao main
main: vaga curriculo aluno usuario empresa colegiado testeVaga testeCurriculo
	$(CC) $(CFLAGS) build/vaga.o build/curriculo.o build/aluno.o build/usuario.o build/empresa.o build/colegiado.o src/main.cpp -o $(TARGET)
	@clear
clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
