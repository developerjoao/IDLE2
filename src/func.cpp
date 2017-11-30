#include "../include/func.h"


//***********************************************display*******************************************
void display(){
	srand(time(NULL));
	int num = (rand() % 2) + 1;
	if(num == 1){
		cout <<"\033[91m";
	} else if(num ==2){
		cout <<"\033[92m";
	}
	cout <<"▄█ ██▄   █     ▄███▄       ██▄     ▄      ▄     ▄▀  ▄███▄   ████▄    ▄" << endl;
	cout <<"██ █  █  █     █▀   ▀      █  █     █      █  ▄▀    █▀   ▀  █   █     █ " << endl;
	cout <<"██ █   █ █     ██▄▄        █   █ █   █ ██   █ █ ▀▄  ██▄▄    █   █ ██   █" << endl; 
	cout <<"▐█ █  █  ███▄  █▄   ▄▀     █  █  █   █ █ █  █ █   █ █▄   ▄▀ ▀████ █ █  █" << endl; 
	cout <<" ▐ ███▀      ▀ ▀███▀       ███▀  █▄ ▄█ █  █ █  ███  ▀███▀         █  █ █" << endl; 
	cout <<"                                  ▀▀▀  █   ██                     █   ██\033[39m" << endl;
	cout <<endl;
}
//**********************************************Load Game******************************************
vector<string> Load(ifstream& savefile){
    vector<string> personagem;
    string atributo;
    if(savefile){
      while(getline(savefile, atributo, ';')){
        if(!savefile.eof()){
            personagem.push_back(atributo);
          }
        }
    }
    personagem.push_back(atributo);
    return personagem;
}

//**********************************************Menu principal*************************************
void intro(){
	string username, aux, option;
	vector<string> personagem;
	int num;
	bool laco = true;
	Character* player;
	
	display();
	cout << "Bem vindo! digite o seu nome de usuario(se nao existir, um novo personagem sera criado): ";
	
	cin >> username;
	
	aux = "data/Save/" + username + ".txt";

	ifstream savefile(aux, ifstream::in);
	
	if(savefile.is_open()){
		system("clear");
		personagem = Load(savefile);
		//Novo personagem
		Equip new_equip;
		list<Equip> new_list;
		if(stoi(personagem[0]) == 0){
			player = new Warrior(personagem[1],stoi(personagem[2]),stoi(personagem[3]),stoi(personagem[4]),stoi(personagem[5]),stoi(personagem[6]),stoi(personagem[7]),stoi(personagem[8]),stoi(personagem[9]), new_equip,new_list);
			laco = false;
		} else if(stoi(personagem[0]) == 1){
			player = new Warlock(personagem[1],stoi(personagem[2]),stoi(personagem[3]),stoi(personagem[4]),stoi(personagem[5]),stoi(personagem[6]),stoi(personagem[7]),stoi(personagem[8]),stoi(personagem[9]), new_equip,new_list);
			laco = false;
		} else {
			player = new Thief(personagem[1],stoi(personagem[2]),stoi(personagem[3]),stoi(personagem[4]),stoi(personagem[5]),stoi(personagem[6]),stoi(personagem[7]),stoi(personagem[8]),stoi(personagem[9]), new_equip,new_list);
			laco = false;
		}		
		savefile.close();
	}else{
		while(laco){
		cout << "Esse personagem não existe! deseja cria-lo? (y/n)" << endl;
		cin >> option;
			
			if(option.compare("y") == 0 or option.compare("Y") == 0){
				cout << "Escolha a sua classe:" << endl;
				cout << "[1] Guerreiro" << endl;
				cout << "[2] Mago" << endl;
				cout << "[3] Ladino" << endl;
				
				cin >> num;
				
				if(num > 3 or num < 1){
					cout << "\033[91mOpcao invalida!\033[39m" << endl;
					
				} else {
					//Novo personagem
					Equip new_equip;
					list<Equip> new_list;
					if(num == 1){
						player = new Warrior(username,150,30,8,10,0,1,100,0,new_equip,new_list);
						laco = false;
					} else if(num == 2){
						player = new Warlock(username,80,20,10,17,0,1,100,0,new_equip,new_list);
						laco = false;
					} else {
						player = new Thief(username,100,15,15,10,0,1,100,0,new_equip,new_list);
						laco = false;
					}
					system("clear");
				}
				
			} else if(option.compare("n") == 0 or option.compare("N") == 0){
				cout << "Fim de jogo!" << endl;
				player->setHp(-999999);
				laco = false;
				
			} else {
				system("clear");
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				
			}
		}
	}
	if(player->getHp() != -999999)
	game(player);
	
}
//**********************************************Fim do menu****************************************
//**********************************************Inicio do Save*************************************
void save_game(Character* player){
	
	string aux = "data/Save/" + player->getName() + ".txt", save;
	//É só concatenar todas as informações do personagem nesse padrão aí
	//Que já tá escrevendo no arquivo bonitinho! O problema tá no label... acho melhor que durante a criação o personagem tenha
	//Uma string classe para identifica-lá!
	save = to_string(player->getLabel())+";" +player->getName()+ ";" +to_string(player->getHp())+ ";" +to_string(player->getStr())+ ";" +to_string(player->getDex())+ ";" +to_string(player->getWis())+ ";" +to_string(player->getExp())+ ";" +to_string(player->getLvl())+ ";" +to_string(player->getNext_lvl())+ ";" +to_string(player->getMoney())+ ";";
	ofstream outfile;
	outfile.open(aux);
	if(outfile.is_open()){
		outfile << save;
	}
	
	outfile.close();
}
//**********************************************Fim do Save****************************************
//**********************************************Inicio da Loja*************************************
Equip loja(int label){
	/*Dinheiro do jogador
	cout<<"Wallet: "<<player->getMoney()<<endl;*/
	string aux2;
	bool loja = true;
	while(loja){
		if(label == 0){
			cout << "[1] Espada de bronze - 100G" << endl;
			cout << "[2] Espada de prata - 1000G" << endl;
			cout << "[3] Espada de ouro - 10000G" << endl;
			cout << "[4] Retornar a cidade." << endl;
			cin >> aux2;
			if(aux2.compare("1")== 0){
				return Equip("Espada de bronze", "espada", 1,100);
			} else if(aux2.compare("2") == 0){
				return Equip("Espada de prata", "espada", 15,1000);
			} else if(aux2.compare("3") == 0){
				return Equip("Espada de ouro", "espada", 200,10000);
			} else if(aux2.compare("4") == 0){
				return Equip("Vazio", "espada", 0, 0);
			} else{
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				cout << endl;
			}
		} else if(label == 1){
			cout << "[1] Cajado de bronze - 100G" << endl;
			cout << "[2] Cajado de prata - 1000G" << endl;
			cout << "[3] Cajado de ouro - 10000G" << endl;
			cout << "[4] Retornar a cidade." << endl;
			cin >> aux2;
			if(aux2.compare("1") == 0){
				return Equip("Cajado de bronze", "cajado", 1,100);
			} else if(aux2.compare("2") == 0){
				return Equip("Cajado de prata", "cajado", 15,1000);
			} else if(aux2.compare("3") == 0){
				return Equip("Cajado de ouro", "cajado", 200,10000);
			} else if(aux2.compare("4") == 0){
				return Equip("Vazio", "cajado", 0, 0);
			} else {
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				cout << endl;
			}
		} else if(label == 2){
			cout << "[1] Adaga de bronze - 100G" << endl;
			cout << "[2] Adaga de prata - 1000G" << endl;
			cout << "[3] Adaga de ouro - 10000G" << endl;
			cout << "[4] Retornar a cidade." << endl;
			cin >> aux2;
			if(aux2.compare("1") == 0){
				return Equip("Adaga de bronze", "adaga", 1,100);
			} else if(aux2.compare("2") == 0){
				return Equip("Adaga de prata", "adaga", 15,1000);
			} else if(aux2.compare("3") == 0){
				return Equip("Adaga de ouro", "adaga", 200,10000);
			} else if(aux2.compare("4") == 0){
				return Equip("Vazio", "adaga", 0, 0);
			} else {
				cout << "\033[91mOpcao invalida!\033[39m" << endl;
				cout << endl;
			}
		} else {
			system("clear");
			cout << "\033[91mOpcao invalida!\033[39m" << endl;
			cout << endl;
		}
	}
}
//**********************************************Fim da loja****************************************
//**********************************************Inicio do jogo*************************************
bool game(Character* player){
	int num;
	bool laco = true;
	
	while(laco){
		cout << "Bem vindo, "<<player->getName()<<", a cidade de Crystal Water! Lar da dungeon infinita!" << endl;
		cout << "[1] Enfrentar a dungeon." << endl;
		cout << "[2] Ver status." << endl;
		cout << "[3] Ir a loja." << endl;
		cout << "[4] Salvar o jogo." << endl;
		cout << "[5] Voltar ao menu inicial." << endl;
		cout << "[6] Sair do jogo." << endl;
		cout << "O que voce deseja fazer?" << endl;
		cin >> num;
		
		if(num == 1){
			system("clear");
			cout<<"Exp:"<<player->getExp()<<endl;
			player->battle();
			
		} else if(num == 2){
			system("clear");
			player->showStatus();
		
		} else if(num == 3){
			system("clear");
			player->equip(loja(player->getLabel()));
			if(player->equipPrice() > player->getMoney()){
				player->equip();
				cout << "Nao tem dinheiro? Devolva a minha arma e saia da minha loja!" << endl;
			} else {
				player->setMoney(player->getMoney() - player->equipPrice());
			}
		} else if(num == 4){
			save_game(player);
			system("clear");
			//display();
			cout << "O seu jogo foi salvo!" << endl;
			cout << endl;
		
		} else if(num == 5){
			system("clear");
			intro();
		
		} else if(num == 6){
			system("clear");
			cout << "Obrigado por visitar nossa cidade aventureiro!!!" << endl;
			return false;
		
		} else{
			system("clear");
			cout << "\033[91mOpcao invalida!\033[39m" << endl;
			cout << endl;
		
		}
		num = 0;
	}
	cout << "\033[91mOcorreu um erro inesperado!!!" << endl;
	cout << "Fechando o programa!!!\033[39m" << endl;
	return false;
}

//**********************************************Fim do jogo****************************************
//**********************************************Fim do jogo****************************************