CC := g++
SRCDIR := src
BUILDDIR := build
TARGET := main.out
CFLAGS := -g -O3 -std=c++11 -I include/ 

#vaga:
vaga:
	@mkdir -p build
	$(CC) $(CFLAGS) -c src/vaga.cpp -o build/vaga.o
testeVaga: vaga
	$(CC) $(CFLAGS) src/TesteVaga.cpp build/vaga.o -o Testes/TesteVaga	
curriculo:
	$(CC) $(CFLAGS) -c src/curriculo.cpp -o build/curriculo.o
testeCurriculo: curriculo
	$(CC) $(CFLAGS) src/TesteCurriculo.cpp build/curriculo.o -o Testes/TesteCurriculo
aluno:
	$(CC) $(CFLAGS) -c src/aluno.cpp -o build/aluno.o
TesteAluno: aluno
	$(CC) $(CFLAGS) src/TesteAluno.cpp build/aluno.o -o Testes/TesteAluno
usuario:
	$(CC) $(CFLAGS) -c src/usuario.cpp -o build/usuario.o
TesteUsuario: aluno curriculo vaga usuario 
	$(CC) $(CFLAGS) src/TesteUsuario.cpp build/aluno.o build/curriculo.o build/vaga.o build/usuario.o -o Testes/TesteUsuario
empresa:
	$(CC) $(CFLAGS) -c src/empresa.cpp -o build/empresa.o
colegiado:
	$(CC) $(CFLAGS) -c src/colegiado.cpp -o build/colegiado.o

# Modifique a funcao main
test: testeVaga testeCurriculo
run: vaga curriculo aluno usuario empresa colegiado
	$(CC) $(CFLAGS) build/vaga.o build/curriculo.o build/aluno.o build/usuario.o build/empresa.o build/colegiado.o src/main.cpp -o $(TARGET)
all: vaga curriculo aluno usuario empresa colegiado testeVaga testeCurriculo
	$(CC) $(CFLAGS) build/vaga.o build/curriculo.o build/aluno.o build/usuario.o build/empresa.o build/colegiado.o src/main.cpp -o $(TARGET)
clean:
	$(RM) -r $(BUILDDIR)/* $(TARGET)
