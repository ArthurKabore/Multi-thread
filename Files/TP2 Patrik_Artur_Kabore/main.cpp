//Patrik Artur Kabore

#include <iostream>
#include <string>
#include <queue>
#include "Processus.h"
using namespace std;

//Fonctions utilisees dans main.
void afficher(queue<Processus> f);
void iterationProcessus(queue<Processus> f);

int main(int argc, char** argv) {
try {
	int temps;
	string nom;
	
	int n = 0; //Nombre de processus dans la file.
	cout << "Entrez le nombre de processus pour la file: ";
	cin >> n;
	//Validation.
	if(cin.fail() || n<0)
	{
		do{
			cerr <<"Erreur! Valeur num\202rique et positive seulement!\n";
			cin.clear();
			cin.ignore(256,'\n'); //Vidage du input stream.
			cout <<"Entrez le nombre de processus pour la file: ";
			cin >> n;
		}while(cin.fail() || n<0);
	}

	//Creation de la file de Processus.
	cout <<"\nCr\202ation de la file de " << n << " processus." << endl;
	
	queue<Processus> file; 
	for(int i=0; i<n; i++){
		cout << "Entrez le nom du processus " << i+1 << " : ";
		cin >> nom;
		
		cout<< "Entrez le temps d'ex\202cution du processus "<< nom << " en unit\202s: ";
		cin>>temps;
		//Validation avant de passer au constructeur.
		if(cin.fail() || temps < 0){
			do{
				cerr<<"Erreur! Valeur num\202rique et positive seulement!\n";
				cin.clear();
				cin.ignore(256,'\n');	//Vidage du input stream.
				cout<< "Entrez le temps d'ex\202cution du processus "<< nom << " en unit\202s: ";
				cin>>temps;
			}while(cin.fail() || temps < 0);
		}
			
			file.push(Processus(nom,temps));
	}//Fin de la creation de la file.

	//Affichage de l'etat initial.
	cout<<"\n\220tat initial de la file d'attente des processus		-temps courant 0\n";
	afficher(file);
	
	//Traitements de la file + affichages.
	iterationProcessus(file);
	
	system("pause");
	return 0;
	
  } 
  catch (std::bad_alloc &bd) {
    cerr << "Manque de memoire"<< endl;
    return 1;
  }
  catch(std::exception &e) {
    cerr << "Erreur imprevue avec l'exception "<< e.what() << endl;
    return 2;
  }
}

void afficher(queue<Processus> f) {
	while (!f.empty()) 
	{
		cout << f.front() << " ";
		f.pop();
	}
} 

void iterationProcessus(queue<Processus> f) {
	queue<Processus> fileExit; //File pour afficher les processus qui quittent.
	int temps = 0,i = 0;
	
	//Iteration de la file.
	while(!f.empty()){
		++i;
		temps=f.front().getTemps()-2; //Execution du processus.
		f.front().setTemps(temps); 
		if(f.front().getTemps() >0){ f.push(f.front()); f.pop();} 
		else if(f.front().getTemps() <=0 && !f.empty()){ fileExit.push(f.front()); f.pop();}
	
	//Affichages.
	cout<<"\n\220tat "<< i <<" apr\212s le "<< i <<"-e quantum de temps de CPU(Q=2)\t-temps courant "<< i+i << endl; //i+i= temps courant
	afficher(f); 
	
	if(fileExit.front().getTemps() <=0 && !fileExit.empty() && f.size()>0)
		{
		cout<<"\t-processus "<< fileExit.front().getIdentite() <<" a termin\202 son ex\202cution"; fileExit.pop();}
	}
	if(f.empty()){cout<<"File d'attente vide.\n";}
} 
