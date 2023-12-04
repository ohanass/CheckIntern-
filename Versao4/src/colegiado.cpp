#include "colegiado.hpp"

void teste_compatibilidade(Curriculo curriculo, std::map<unsigned long int, Vaga*> vagas){
    int compatibilidade;
    std::multimap<double, std::map<unsigned long int, Vaga*>> ordenador;
    for(std::map<unsigned long int, Vaga*>::iterator it=vagas.begin();it!=vagas.end();++it){
        compatibilidade=0;
        if(it->second->get_salario()>=curriculo.get_salario()){
            compatibilidade++;
        }
        for(long unsigned int j=0; j<curriculo.get_beneficios().size(); ++j){
            for(long unsigned int k=0; k<it->second->get_beneficios().size(); ++k){
                if(it->second->get_beneficios().at(k).find(curriculo.get_beneficios().at(j))!=std::string::npos){
                    compatibilidade++;
                    break;
                }
            }
        }
        for(long unsigned int j=0; j<curriculo.get_aptidoes().size(); ++j){
            for(long unsigned int k=0; k<it->second->get_requisitos().size(); ++k){
                if(it->second->get_requisitos().at(k).find(curriculo.get_aptidoes().at(j))!=std::string::npos){
                    compatibilidade++;
                    break;
                }
            }  
        }
        std::map<unsigned long int, Vaga*> aux;
        aux[it->first]=it->second;
        ordenador.insert(std::make_pair(100.0-(((double)compatibilidade/(double)(curriculo.get_beneficios().size()+curriculo.get_aptidoes().size()+1))*100),aux));
    }
    for(std::multimap<double, std::map<unsigned long int, Vaga*>>::iterator it=ordenador.begin();it!=ordenador.end();++it){
        for(std::map<unsigned long int, Vaga*>::iterator it2=it->second.begin();it2!=it->second.end();++it2){
            if((100.0-it->first)>=50.0){
                std::cout<<"***************************"<<std::endl;
                std::cout<<"CODIGO: #"<<it2->first<<std::endl;
                std::cout<<"---------------------------"<<std::endl;
                it2->second->mostrar_vaga();
                std::cout<<"---------------------------"<<std::endl;
                std::cout<<"COMPATIBILIDADE: "<<std::fixed<<std::setprecision(2)<<(100.0-it->first)<<"%"<<std::endl;
            }
        }
    }
    std::cout<<"***************************"<<std::endl<<std::endl;

}

void validar_CPF(std::string &cpf) {
    bool valido;
    do{
        valido=true;
        std::cout << "Digite o CPF (apenas números): ";
        std::cin >> cpf;
        if (cpf.size() != 11) {
            std::cout << "CPF deve conter 11 dígitos. Tente novamente." << std::endl;
            valido=false;
            continue;
        }
        else{
            for (char c : cpf) {
                if (!std::isdigit(c)) {
                    valido = false;
                    std::cout << "CPF deve conter apenas números. Tente novamente." << std::endl;
                    break;
                }
            }
            if (valido) {
                int digito1 = 0, digito2 = 0;
                int peso = 10;
                for (int i = 0; i < 9; ++i) {
                    digito1 += (cpf[i] - '0') * peso;
                    peso--;
                }
                int resto = digito1 % 11;
                if (resto < 2){
                    digito1 = 0;
                }
                else{
                    digito1 = 11 - resto;
                }
                peso = 11;
                for (int i = 0; i < 10; ++i) {
                    digito2 += (cpf[i] - '0') * peso;
                    peso--;
                }
                resto = digito2 % 11;
                if (resto < 2){
                    digito2 = 0;
                }
                else{
                    digito2 = 11 - resto;
                }
                if ((digito1 != cpf[9] - '0') && (digito2 != cpf[10] - '0')) {
                    valido = false;
                    std::cout << "CPF inválido. Tente novamente." << std::endl;
                }
            }
        }
    }while (!valido);
}

void validar_CNPJ(std::string &cnpj) {
    bool valido;
    do {
        valido = true;
        std::cout << "Digite o CNPJ (apenas números): ";
        std::cin >> cnpj;
        if (cnpj.size() != 14) {
            std::cout <<"CNPJ deve conter 14 dígitos. Tente novamente." << std::endl;
            valido = false;
            continue;
        } else {
            for (char c : cnpj) {
                if (!std::isdigit(c)) {
                    valido = false;
                    std::cout << "CNPJ deve conter apenas números. Tente novamente." << std::endl;
                    break;
                }
            }
            if (valido) {
                int digito1 = 0, digito2 = 0;
                int peso = 5, soma = 0;
                for (int i = 0; i < 12; ++i) {
                    peso = (peso == 1) ? 9 : peso;
                    digito1 += (cnpj[i] - '0') * peso;
                    peso--;
                }
                int resto = digito1 % 11;
                digito1 = (resto < 2) ? 0 : 11 - resto;
                peso = 6;
                for (int i = 0; i < 13; ++i) {
                    peso = (peso == 1) ? 9 : peso;
                    digito2 += (cnpj[i] - '0') * peso;
                    peso--;
                }
                resto = digito2 % 11;
                digito2 = (resto < 2) ? 0 : 11 - resto;
                if (digito1 != cnpj[12] - '0' || digito2 != cnpj[13] - '0') {
                    valido = false;
                    std::cout << "CNPJ inválido. Tente novamente." << std::endl;
                }
            }
        }
    } while (!valido);
}

void separar_Str(std::vector<std::string>* str){
    std::string aux;
    char input;
    do {
        input = getchar(); // Lê um caractere do console
        if ((input == ','&&!(aux.empty()))||(input == '\n'&&!(aux.empty()))) {
            str->push_back(aux);
            aux.clear();
        } else if (input != '\n'&&!(input==' '&&aux.empty())&&input != ',') {
            aux+=input;
        }
    } while (input != '\n');
}

void Colegiado::cadastrar_servidor(Servidor* novo_servidor){
    if(this->_lista_servidores.find(novo_servidor->get_login())==this->_lista_servidores.end()){
       for(std::map<std::string, Servidor*>::iterator it=this->_lista_servidores.begin();it!=this->_lista_servidores.end();++it){
            if(it->second->get_email()==novo_servidor->get_email()){
                std::cout<<"EMAIL JÁ CADASTRADO"<<std::endl;
                return ;
            }
        }
        std::cout<<"SERVIDORQ CADASTRADO"<<std::endl;
        this->_lista_servidores.insert(std::make_pair(novo_servidor->get_login(), novo_servidor));
    }
    else{
        std::cout<<"SERVIDOR JÁ CADASTRADO"<<std::endl;
    }
}

bool Colegiado::entrar_servidor(std::string login, std::string senha){
    if(this->_lista_servidores.find(login)!=this->_lista_servidores.end()){
        if(this->_lista_servidores.at(login)->get_senha()==senha){
            std::cout<<"SEJA BEM VINDO "<<this->_lista_servidores.at(login)->get_nome()<<std::endl;
            return true;
        }
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

bool Colegiado::alterar_email_servidor(std::string login, std::string email){
    if(this->_lista_servidores.find(login)!=this->_lista_servidores.end()){
        for(std::map<std::string, Servidor*>::iterator it=this->_lista_servidores.begin();it!=this->_lista_servidores.end();++it){
            if(it->second->get_email()==email){
                std::cout<<"EMAIL JÁ CADASTRADO"<<std::endl;
                return false;
            }
        }
        this->_lista_servidores.at(login)->alterar_email(email);
        std::cout<<"ALTERACAO REALIZADA COM SUCESSO "<<this->_lista_servidores.at(login)->get_nome()<<std::endl;
        return true;
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

bool Colegiado::alterar_login_servidor(std::string login,std::string novo_login){
    if(this->_lista_servidores.find(login)!=this->_lista_servidores.end()){
        if(this->_lista_servidores.find(novo_login)==this->_lista_servidores.end()){
            this->_lista_servidores.at(login)->alterar_login(novo_login);
            cadastrar_servidor(_lista_servidores.at(login));
            this->_lista_servidores.erase(login);
            std::cout<<"ALTERACAO REALIZADA COM SUCESSO "<<this->_lista_servidores.at(login)->get_nome()<<std::endl;
            return true;
        }
        std::cout<<"USUARIO CADASTRADO"<<std::endl;
        return false;
    }
    std::cout<<"USUARIO NAO ENCONTRADO"<<std::endl;
    return false;
}

bool Colegiado::alterar_senha_servidor(std::string login, std::string senha_atual, std::string senha_nova){
    if(_lista_servidores.find(login)!=_lista_servidores.end()){
        if(_lista_servidores.at(login)->get_senha()==senha_atual){
            this->_lista_servidores.at(login)->alterar_senha(senha_nova);
            std::cout<<"SENHA ALTERADA COM SUCESSO "<<this->_lista_servidores.at(login)->get_nome()<<std::endl;
            return true;
        }
        std::cout<<"SENHA INCORRETA"<<std::endl;
        return false;
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

void Colegiado::cadastrar_empresa(Empresa* nova_empresa){
    if(this->_lista_empresas.find(nova_empresa->get_CNPJ())==this->_lista_empresas.end()){
        this->_lista_empresas.insert(std::make_pair(nova_empresa->get_CNPJ(), nova_empresa));
        std::cout<<"EMPRESA CADASTRADA COM SUCESSO"<<std::endl;
    }
    else{
        std::cout<<"EMPRESA JÁ CADASTRADA"<<std::endl;
    }
}

void Colegiado::adicionar_vaga(std::string cnpj, Vaga* vagas){
    this->_lista_empresas.at(cnpj)->adicionar_vaga(vagas);
}

void Colegiado::remover_vaga(std::string cnpj, unsigned long int cod_vaga){
    if(this->_lista_empresas.find(cnpj)!=this->_lista_empresas.end()){
        if(this->_lista_empresas.at(cnpj)->verifica_existenciaVaga(cod_vaga)){
            this->_lista_empresas.at(cnpj)->remover_vaga(cod_vaga);
            std::cout<<"VAGA REMOVIDA "<<std::endl;
            return ;
        }
        std::cout<<"VAGA INEXISTENTE "<<std::endl;
        return ;
    }
    std::cout<<"EMPRESA NÃO ENCONTRADA"<<std::endl;
    return ;

}


void Colegiado::mostrar_todas_vagas(void){
    for(std::map<std::string, Empresa*>::iterator it=this->_lista_empresas.begin();it!=this->_lista_empresas.end();++it){
        std::cout<<"---------------------------"<<std::endl;
        std::cout<<it->second->get_nome()<<std::endl;
        std::cout<<"CNPJ: "<<it->first<<std::endl;
        it->second->mostrar_vagas();
    }
}

void Colegiado::mostrar_curriculos_enviados(std::string cnpj){
    if(this->_lista_empresas.find(cnpj)!=this->_lista_empresas.end()){
        std::cout<<this->_lista_empresas.at(cnpj)->get_nome()<<std::endl;
        this->_lista_empresas.at(cnpj)->mostrar_curriculos();
    }
    else{
        std::cout<<"EMPRESA NAO ENCONTRADA"<<std::endl;
    }
}


void Colegiado::cadastrar_aluno(Aluno* novo_aluno){
    if(this->_lista_alunos.find(novo_aluno->get_login())==this->_lista_alunos.end()){
       for(std::map<std::string, Aluno*>::iterator it=this->_lista_alunos.begin();it!=this->_lista_alunos.end();++it){
            if(it->second->get_email()==novo_aluno->get_email()){
                std::cout<<"EMAIL JÁ CADASTRADO"<<std::endl;
                return ;
            }
        }
        std::cout<<"ALUNO CADASTRADO"<<std::endl;
        this->_lista_alunos.insert(std::make_pair(novo_aluno->get_login(), novo_aluno));
    }
    else{
        std::cout<<"ALUNO JÁ CADASTRADO"<<std::endl;
    }

}

bool Colegiado::alterar_email_aluno(std::string login, std::string email){
    if(this->_lista_alunos.find(login)!=this->_lista_alunos.end()){
        for(std::map<std::string, Aluno*>::iterator it=this->_lista_alunos.begin();it!=this->_lista_alunos.end();++it){
            if(it->second->get_email()==email){
                std::cout<<"EMAIL JÁ CADASTRADO"<<std::endl;
                return false;
            }
        }
        this->_lista_alunos.at(login)->alterar_email(email);
        std::cout<<"ALTERACAO REALIZADA COM SUCESSO "<<this->_lista_alunos.at(login)->get_nome()<<std::endl;
        return true;
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

bool Colegiado::alterar_login_aluno(std::string login, std::string novo_login){
    if(this->_lista_alunos.find(login)!=this->_lista_alunos.end()){
        if(this->_lista_alunos.find(novo_login)==this->_lista_alunos.end()){
            this->_lista_alunos.at(login)->alterar_login(novo_login);
            cadastrar_aluno(_lista_alunos.at(login));
            this->_lista_alunos.erase(login);
            std::cout<<"ALTERACAO REALIZADA COM SUCESSO "<<this->_lista_alunos.at(login)->get_nome()<<std::endl;
            return true;
        }
        std::cout<<"ALUNO CADASTRADO"<<std::endl;
        return false;
    }
    std::cout<<"ALUNO NAO ENCONTRADO"<<std::endl;
    return false;
}
bool Colegiado::alterar_senha_aluno(std::string login, std::string senha_atual, std::string senha_nova){
    if(_lista_alunos.find(login)!=_lista_alunos.end()){
        if(_lista_alunos.at(login)->get_senha()==senha_atual){
            this->_lista_alunos.at(login)->alterar_senha(senha_nova);
            std::cout<<"SENHA ALTERADA COM SUCESSO "<<this->_lista_alunos.at(login)->get_nome()<<std::endl;
            return true;
        }
        std::cout<<"SENHA INCORRETA"<<std::endl;
        return false;
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

bool Colegiado::entrar_aluno(std::string login, std::string senha){
    if(this->_lista_alunos.find(login)!=this->_lista_alunos.end()){
        if(this->_lista_alunos.at(login)->get_senha()==senha){
            std::cout<<"SEJA BEM VINDO "<<this->_lista_alunos.at(login)->get_nome()<<std::endl;
            return true;
        }
    }
    std::cout<<"SENHA OU USUARIO INCORRETOS"<<std::endl;
    return false;
}

void Colegiado::atualizar_curriculo(std::string login, Curriculo* curriculo){
    this->_lista_alunos.at(login)->atualizar_curriculo(curriculo);
}

void Colegiado::mostrar_vagas_compativeis(std::string login){
    for(std::map<std::string, Empresa*>::iterator it=this->_lista_empresas.begin();it!=this->_lista_empresas.end();++it){
        std::cout<<it->second->get_nome()<<std::endl;
        std::cout<<"CNPJ: "<<it->first<<std::endl;
        teste_compatibilidade(this->_lista_alunos.at(login)->get_curriculo(), it->second->get_vagas());
    }
}

void Colegiado::mostrar_vagas_candidatadas(std::string login){
    this->_lista_alunos.at(login)->mostrar_vagasCandidatadas();
}

void Colegiado::mostrar_vaga_candidatada_detalhada(std::string login, unsigned long int cod_vaga){
    this->_lista_alunos.at(login)->mostrar_vagaDetalhada(cod_vaga);
}

void Colegiado::enviar_curriculo(std::string login,std::string cnpj, unsigned long int cod_vaga){
    if(this->_lista_empresas.find(cnpj)!=this->_lista_empresas.end()){
        if(this->_lista_empresas.at(cnpj)->verifica_existenciaVaga(cod_vaga)){
            this->_lista_alunos.at(login)->enviar_curriculo(this->_lista_empresas.at(cnpj)->get_vaga(cod_vaga));
            this->_lista_empresas.at(cnpj)->receber_curriculo(cod_vaga, this->_lista_alunos.at(login));
            std::cout<<"CURRICULO ENVIADO "<<this->_lista_alunos.at(login)->get_nome()<<std::endl;
            return ;
        }
        std::cout<<"VAGA INEXISTENTE "<<this->_lista_alunos.at(login)->get_nome()<<std::endl;
        return ;
    }
    std::cout<<"EMPRESA NÃO ENCONTRADA"<<std::endl;
    return ;
}


