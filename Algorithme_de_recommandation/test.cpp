#include "fonctions.hpp"
#include <assert.h>
#include <utility>
#include <time.h>
#include <algorithm>

using namespace std;



int main(int argc, const char** argv)
{
	//On note tau le nombre de produits dont on calcule la corrélation
	//avant arrêt de l'algorithme. Choisissez tau élevé pour avoir 
	//un résultat certain. Choisissez tau faible pour obtenir un résultat 
	//rapidement.
	unsigned int tau;
	cout<<"tau = ";
	cin>>tau;
//////////////////////DEBUT D'EXECUTION DU PROGRAMME////////////////////

	time_t debut, fin;
	double duree;
	debut=time(NULL);


/////////////////////CREATION DE LA MAP(produits, clients ayant acheté ce produit)

	assert(argc==2);
	map<string, vector<string> > data;  
	//data = (produit, clients achetant le produit)
	ifstream file(argv[1]);
	int  kp = 0, ka = 0;
	string  client, produit, pointvirgule;
	while(!file.eof())
	{
		file >> client;
		file >> pointvirgule;
		file >> produit;
		ka++;
		
		if(file.eof()) break;
		if(data.find(produit) == data.end())
		{
			(data[produit]).push_back(client);
			kp++;
		}
		else
			(data[produit]).push_back(client);

	}
	
	
	
	

	
//////////////////LISTE DES CLIENTS AYANT ACHETES CHAQUE PRODUIT : OPTIONNEL

	
	//for(multimap<int, string >::iterator it = data_nprod.begin(); it != data_nprod.end(); ++it)
	//{
		
		//cout << "le " << it -> second << " a ete achete par :\n";
		//for(vector<string>::iterator it2 = data[(it -> second)].begin(); it2 != data[(it -> second)].end(); ++it2)
		//	cout << "\t le " << *it2 << endl;
		//cout << "\n\n\n";
	//}

	//cout << "le nombre de produits est " << kp << endl;
	//cout << "test produit 8" << endl;
	
	
/////////////////////CALCUL DES CORRELATIONS////////////////////////////
	
	
	
	int nb_combi = 0;
	int rang = 1;

	
	priority_queue< pair<int, pair<string, string> > > res(fnt_corr_optim(data, tau));
	
	
	
	pair<int, pair<string, string> > top;
	ofstream output("output.csv");
	output<< "rang" << " ; " << "couple" << " ; " << "corrélation"<< endl;
	while(! res.empty() && nb_combi <= 99)
	{
	    top = res.top();
	    cout << "rang : "<< rang << ", ";
		cout << "corrélation = " << top.first << endl;
		cout << endl;
		cout << "\t   pour le : " << (top.second).first << endl;
		cout << "\tet pour le : " << (top.second).second << endl << endl;
		output<< rang << " ; " << "(" <<(top.second).first << "," << (top.second).second <<")"<< " ; " << top.first << endl;
		res.pop();
		rang++;
		nb_combi++;
	}
	
	
	///////////////////TEMPS D'EXECUTION DU PROGRAMME///////////////////
	
	fin=time(NULL);
	duree=difftime(fin, debut);
	
	cout<<" Le temps d'exécution de ce programme est de "<<duree<<" secondes.";
	cout<<endl;
	cout<<endl;
	return 0;
}


