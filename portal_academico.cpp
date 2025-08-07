#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

struct aluno  //struct para armazenar os dados dos alunos
{
	int usuario;
	string senha;
	string recado;
	float nota;
	int frequencia;
};

struct professor //struct para armazenar os dados dos professores (login e senha)
{
	string usuario;
	string senha;
};

int main()
{
	aluno alu[100];  // chamando a struct como vetor para armazenamento de alunos
	professor prof[100]; // chamando a struct como vetor para armazenamento de professores
	int i = 0, p = 0, freq = 0, mat, s, opc, usu;  // declarando as variaveis inteiras da main
	char a, q, n, cat;
	string usua, sen, rec;  //string para onde contem letras
	float nota = 0;  //notas como float para numeros decimais

	do
	{
		cout << endl;  //para pular uma linha em branco
		cout << "     PORTAL ACADEMICO " << endl;  //nome do projeto
		cout << endl;
		cout << "1- Cadastro de Professor" << endl;
		cout << "2- Cadastro de Aluno" << endl;
		cout << "3- Login de usuario" << endl;
		cout << "0 - sair" << endl;
		cout << "Escolha uma opcao: ";
		cin >> opc;  // selecionando a categoria (cadastro ou login)

		if (opc == 1)    // se caso for escolhido cadastro de professor
		{
			do
			{
				cout << "Digite seu usuario: ";
				cin.ignore(); // Adicionei essa linha para consumir a nova linha pendente
				getline(cin, prof[i].usuario);  //entra com o usuario de professor (pode conter letras e numeros)
				cout << "Digite sua senha: ";
				getline(cin, prof[i].senha);  //entra com a senha do professor (pode conter letras e numeros)

				i++;  //variavel para contar quantas repetiçoes(+1)

				cout << "Digite 's' para novo cadastro ou 'n' para retornar: ";
				cin >> a;
			}
			while (a == 's');    // o programa se repete enquanto for digitado 's'
		}
		else if (opc == 2)      // se caso for escolhido cadastro de aluno
		{
			do
			{
				cout << "Digite sua matricula: ";
				cin >> alu[p].usuario;  //entra com a matricula do aluno (somente numeros)
				cout << "Digite sua senha(somente numeros): ";
				cin.ignore(); // Adicionei essa linha para consumir a nova linha pendente
				getline(cin, alu[p].senha);  //entra com a senha do aluno (somente numeros)

				p++;  //contador

				cout << "Digite 's' para novo cadastro ou 'n' para retornar: ";
				cin >> a;
			}
			while (a == 's');    // o programa se repete enquanto for digitado 's'
		}
		else if (opc == 3)  //se caso for escolhido entrar com o login
		{
			cout << endl;
			cout << "1- Fazer login como professor" << endl;
			cout << "2- Fazer login como aluno" << endl;
			cin >> s;

			if (s == 1)  //se caso for escolhido login como professor
			{
				do
				{
					cout << endl;
					cout << "Digite seu usuario: ";  // saindo do programa de cadastro, vai para o de pesquisa
					cin.ignore(); // Adicionei essa linha para consumir a nova linha pendente
					getline(cin, usua);  // entra com o usuario para pesquisa
					cout << "Digite sua senha: ";
					getline(cin, sen);  //entra com a senha ja cadastrada

					bool found = false;
					for (int j = 0; j < i; j++)    // estrutura de repetição para pesquisa
					{
						if (usua == prof[j].usuario && sen == prof[j].senha)    // se o usuario digitado for igual a algum usuario dentro do vetor
						{
							found = true; //se o usuario e senha estiverem corretos
							do
							{
								cout << "Bem vindo professor(a) " << prof[j].usuario << endl;
								cout << endl;
								cout << "Selecione a opcao que deseja realizar:" << endl;
								cout << endl;
								cout << "1- Lancar nota" << endl;
								cout << "2- Lancar faltas" << endl;
								cout << "3- Lancar recado" << endl;
								cin >> cat;

								switch (cat)    // estrutura de escolha de acordo com a opcao desejada
								{
								case '1':  // se for nota
									cout << "Digite a matricula do aluno desejado: ";
									cin >> mat;
									for (int k = 0; k < p; k++)
									{
										if (mat == alu[k].usuario)
										{
											cout << alu[k].usuario << endl;
											cout << "Digite a nota do aluno: ";
											cin >> nota;
											alu[k].nota = nota;
										}
									}
									break;

								case '2':  // se for frequencia
									cout << "Digite a matricula do aluno desejado: ";
									cin >> mat;
									for (int k = 0; k < p; k++)
									{
										if (mat == alu[k].usuario)
										{
											cout << alu[k].usuario << endl;
											cout << "Digite as faltas do aluno: ";
											cin >> freq;
											alu[k].frequencia = freq;
										}
									}
									break;

								case '3':  // se for recado
									cout << "Digite a matricula do aluno desejado: ";
									cin >> mat;
									for (int k = 0; k < p; k++)
									{
										if (mat == alu[k].usuario)
										{
											cout << alu[k].usuario << endl;
											cout << "Digite o recado desejado para o aluno: ";
											cin.ignore(); // Adicionei essa linha para consumir a nova linha pendente
											getline(cin, rec);  //escreve o recado
											alu[k].recado = rec;
										}
									}
									break;
								}
								cout << "Deseja retornar ao menu? (s ou n): ";
								cin >> n;
							}
							while(n == 's');
						}
					}
					if (!found)
					{
						cout << "Usuario nao encontrado" << endl;  // se o usuario nao for encontrado
					}

					cout << "Deseja efetuar novo login de professor? (s ou n): ";
					cin >> q;
				}
				while (q == 's');    // se for digitado 's' sera encaminhado para realizar uma novo login

			}
			else if (s == 2)  //se caso escolha login de aluno
			{
				do
				{
					cout << endl;
					cout << "Digite sua matricula: ";
					cin >> usu;  // entra com o usuario para pesquisa (apenas numeros)
					cout << "Digite sua senha (somente numeros): ";
					cin >> sen;   //entra com a senha ja cadastrada (apenas numeros)

					bool found = false;
					for (int l = 0; l < p; l++)    // estrutura de repetição para pesquisa
					{
						if (usu == alu[l].usuario && sen == alu[l].senha)    // se o usuario digitado for igual a algum usuario dentro do vetor
						{
							found = true;
							do
							{
								cout << "Bem vindo(a) " << alu[l].usuario << endl;
								cout << endl;
								cout << "Selecione a opcao que deseja realizar:" << endl;
								cout << "1- Notas" << endl;
								cout << "2- Frequencias" << endl;
								cout << "3- Recados" << endl;
								cout << "4- Horarios" << endl;
								cout << "5- Provas" << endl;
								cin >> cat;

								switch (cat)    // estrutura de escolha de acordo com a opcao desejada
								{
								case '1':  // se for nota
									cout << endl;
									cout << "nota: " << alu[l].nota << endl;

									break;

								case '2':  // se for frequencia
									cout << endl;
									cout << "limite total de faltas : 100" << endl;
									cout << endl;
									cout << "total de faltas do aluno: " << alu[l].frequencia << endl;
									break;

								case '3':  // se for recado
									cout << endl;
									cout << "Recados:" << endl;
									cout << alu[l].recado << endl;
									break;

								case '4':  // se for horarios
									cout << "            Horarios" << endl;
									cout << endl;
									cout << "  segunda                terca               quarta              quinta           sexta" << endl;
									cout << " 13h30: Matematica    13h30: Geografia    15h30: Portugues    17h30: Fisica    13h30: Fisica" << endl;
									cout << " 15h30: Portugues     17h30: Historia     17h30: Matematica " << endl;
									break;

								case '5':  // se for provas
									cout << "           Provas" << endl;
									cout << endl;
									cout << "     26/04                         16/06                       04/07 " << endl;
									cout << "13h30: 1 prova geral       13h30: 2 prova geral       15h30: prova final   " << endl;
									break;
								}
								cout << "Deseja retornar ao menu? (s ou n): ";
								cin >> n;
							}
							while(n == 's');
						}
					}
					if (!found) // se o usuario nao for encontrado
					{
						cout << "Usuario nao encontrado" << endl;
					}

					cout << "Deseja efetuar novo login de aluno? (s ou n): ";
					cin >> q;
				}
				while (q == 's');    // se for digitado 's' sera encaminhado para realizar uma nova pesquisa
			}
		}

		cout << "Digite 's' para retornar ao menu principal: ";
		cin >> a;

	}
	while (a == 's');

	return 0;
}
