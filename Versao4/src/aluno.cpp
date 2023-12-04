#include "aluno.hpp"

void Aluno::atualizar_curriculo(Curriculo* curriculo){
    this->_curriculo.atualizar_curriculo(curriculo);
}

Curriculo Aluno::get_curriculo(void){
    return this->_curriculo;
}
void Aluno::mostrar_aluno(void){
    std::cout << "---------------------------" << std::endl;
    std::cout << "NOME: " << this->_nome << std::endl;
    std::cout << "CPF: ";
    for(unsigned int i = 0;i < 9;i += 3){
        std::cout << this->_cpf.substr(i,3);
        if(i < 6){
            std::cout << ".";
        }
    }
    std::cout << "-" << this->_cpf.substr(9,10) << std::endl;
    std::cout << "IDADE: " << this->_idade << std::endl;
    std::cout << "ENDERECO: " << this->_endereco << std::endl;
    std::cout << "CURSO: " << this->_curso << std::endl;
    std::cout << "PERIODO: " << this->_periodo << std::endl;
    std::cout << "CONTATO: " << this->_numeroTelefone.substr(0,2) << " " << _numeroTelefone.substr(2,5) << "-" << _numeroTelefone.substr(7,4) << std::endl;
    std::cout << "---------------------------" << std::endl;
} 

void Aluno::mostrar_curriculo(void){
    this->mostrar_aluno();
    this->_curriculo.mostrar_curriculo();
}

void Aluno::enviar_curriculo(Vaga* vaga){
    this->_vagasCandidatadas.push_back(vaga);
}

void Aluno::mostrar_vagasCandidatadas(void){
    for(unsigned long int i = 0;i < this->_vagasCandidatadas.size();++i){
        if(this->_vagasCandidatadas.at(i)->get_ativa()){
            std::cout << i + 1 << "." << std::endl;
            this->_vagasCandidatadas.at(i)->mostrar_vaga_resumido();
        }
	else{
            std::cout << "VAGA INATIVA" << std::endl;
        }
    }
    else{
        std::cout << "VAGA INEXISTENTE" << std::endl;
    }
}

void Aluno::mostrar_vagaDetalhada(unsigned long int id){
    if(id <= this->_vagasCandidatadas.size()){
        if(this->_vagasCandidatadas.at(id)->get_ativa()){
            this->_vagasCandidatadas.at(id-1)->mostrar_vaga();
        }
        else{
            std::cout << "VAGA INATIVA" << std::endl;
        }
    }
    else{
        std::cout << "VAGA INEXISTENTE" << std::endl;
    }
}

std::string Aluno::get_nome(void){
    return this->_nome;
}

std::string Aluno::get_cpf(void){
    return this->_cpf;
}

unsigned short int Aluno::get_idade(void){
    return this->_idade;
}

std::string Aluno::get_endereco(void){
    return this->_endereco;
}

std::string Aluno::get_curso(void){
    return this->_curso;
}

unsigned short int Aluno::get_periodo(void){
    return this->_periodo;
}

std::string Aluno::get_numeroTelefone(void){
    return this->_numeroTelefone;
}