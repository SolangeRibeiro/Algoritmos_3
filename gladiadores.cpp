#include <iostream>
using namespace std;

struct Gladiador //struct de cadastro 
{
	string nome;
	int forca, habilidade, idade, vida;
};

int potencia(int base, int exp)  //funçao para a potencia sem usar biblioteca cmath
{
	if (exp == 0) return 1;
	if (exp == 1) return base;
	return base * potencia(base, exp - 1);
}

int ataque(Gladiador gladiador) //funçao para calcular o dano 
{
	return gladiador.forca + potencia(2, gladiador.habilidade);
}

bool combate(Gladiador gladiador1, Gladiador gladiador2)  //funçao para a batalha 
{
	while (gladiador1.vida > 0 && gladiador2.vida > 0)
	{
		gladiador2.vida -= ataque(gladiador1);
		gladiador1.vida -= ataque(gladiador2);
	}
	if (gladiador2.vida <= 0) return true;
	else return false;
}

int main()
{
	Gladiador gladiadores[1000]; //chamando a struct para cadastro
	string nome;
	int forca, habilidade, idade, gladiador1, gladiador2;
	int op;  //opçao
	int total = 0; //quantidade de gladiadores cadastrados e a posição deles

	do
	{
		cout << "escolha uma das opcoes:" << endl;
		cout << "1 - cadastrar gladiador" << endl;
		cout << "2 - iniciar batalha" << endl;
		cout << "3 - sair do sistema" << endl;

		cin >> op;  //entrando com a opçao
 
		if (op == 1)  //cadastrando cada gladiador
		{
			cout << "Digite nome, forca, habilidade e idade do gladiador:" << endl;
			cin >> nome >> forca >> habilidade >> idade;
			gladiadores[total] = {nome, forca, habilidade, idade, 100};
			cout << "Gladiador cadastrado na posicao " << total << endl;
			total++; //incrementando no vetor 
		}
		else if (op == 2)  //iniciando uma batalha
		{
			if (total < 2)  //se tiver menos de 2 gladiadores repete as opçoes, pq precisa cadastrar no minimo 2
			{
				cout << "Cadastre ao menos dois gladiadores antes de iniciar a batalha!" << endl;
			}
			else if (total > 1) 
			{
				cout << "Digite a posicao dos dois gladiadores para a batalha:" << endl;
				cin >> gladiador1 >> gladiador2;  //entrando com os gladiadores para a batalha

				if (gladiador1 < 0 || gladiador1 >= total || gladiador2 < 0 || gladiador2 >= total) //validando a posiçao no vetor
				{
					cout << "posicao invalida. Tente novamente." << endl;
				}
				else if (combate(gladiadores[gladiador1], gladiadores[gladiador2]))
				{
					cout << gladiadores[gladiador1].nome;
					cout << " ganhou  batalha contra ";
					cout << gladiadores[gladiador2].nome;
					cout << "." << endl;
				}
				else
				{
					cout << gladiadores[gladiador2].nome;
					cout << " ganhou  batalha contra ";
					cout << gladiadores[gladiador1].nome;
					cout << "." << endl;
				}
			}
		}
		else if (op == 3) //sai do sistema 
		{
			cout << "Sistema encerrado." << endl;
		}
		else
		{
			cout << "invalido! digite novamente" << endl;
		}

	}
	while (op != 3);

	return 0;
}
