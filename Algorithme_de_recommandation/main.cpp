#include <iostream>
#include <fstream>
#include <cassert>
#include <map>

using namespace std;

int main (int argc,const char ** argv)
{
	assert(argc==2);
	 int ka =0,kc=0,kp=0;
	 map<string,int> mapp,mapc; 
	{
	 ifstream fin(argv[1]);
	
	 while (!fin.eof())
	 {
		 string client, produit,pointvirgule;
		 fin >> client ;
		 fin >> pointvirgule;
		 fin >> produit;
		  if (fin.eof()) break; 
		 // si le produit n'existe pas on le cree
		 if( mapp.find(produit) == mapp.end())
			 mapp[produit]=kp++;
		 if( mapc.find(client) == mapc.end())
			 mapc[client]=kc++;
		 
		
		 cout << ka << "  "<<  client << " " << produit << endl; 
		 ka++; 
	 }
    }
    cout << " nb clients  "<< kc<< endl;
    cout << " nb produits "<< kp << endl;
    cout << endl << endl << endl;
/*
    for(map<string,int>::iterator it = mapp.begin(); it != mapp.end(); ++it)
    {
	    cout << "le " << it -> first << "\t a ete achete \t" << (it -> second)+1 << "eme\tachat (pour la premiere fois)"<< endl;
    }

    cout << "\n\n\n\n"; 

    for(map<string,int>::iterator it2 = mapc.begin(); it2 != mapc.end(); ++it2)
    {
	    cout << "cle " << it2 -> first << "\tvaleur\t" << it2 -> second << endl;
    }

*/
	return 0;
}


/*
#include "client.hpp"
#include <vector>
#include <fstream>
#include <iostream>

//la fonction que nous devons créer : donne les 100 couple de produits 
//les plus corrélés issuent du fichier donnee.
void max_correlation(std::ofstream &donnees){
	
	//code
}

//Exemple d'utilisation de la classe client : Si produits_3 =(1,5,2,1), 
///alors client(3,produits_3) désigne le client 3. De plus, ce client 
//a acheté les produits (1,5,2,1).


int main(){
	//ouverture des fichiers en lecture:
	
	std::ifstream donnees_100("data-100.csv");
	std::ifstream donnees_1000("data-1000.csv");
	std::ifstream donnees_10000("data-10000.csv");
	
	
	std::vector<int> produits_florent(2);
	
	//test de la classe et exemple
	produits_florent[0]=1;
	produits_florent[1]=5;
	client florent(3,produits_florent);
	std::cout<<"numéro de client " << florent.ID()<< ". nombre de produits "
	<<"achetés "<<florent.NB_PROD()<<"."; 

	//test de la fonction
	

return 0;
	
}
	
*/	



