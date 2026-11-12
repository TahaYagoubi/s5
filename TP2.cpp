/* Exercice 1
#include <iostream> 
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

void SaisirNotes(vector <float> &notes ){
    float x = 0;
    while(true){
        cout << "Saisir les notes" << endl;
        cin >> x;
    if(x == -1){
        break; 
    }notes.push_back(x);
}
    

}
void afficherNotes(const vector<float> &notes){
  for(float n : notes){ // for each ne renvoie pas l'indice i
    cout << "les notes sont" << n << endl;
}
}
float CalculerMoy(const vector<float> &notes){
    float somm = 0;
    if (notes.empty()){
        return 0;
    }
        for(float n : notes){
            somm += n; 
        }
      return somm/notes.size(); // size renvoie le nbr d'elements
    }
float noteMax(const vector<float> &notes){
     if (notes.empty()) return 0;                   // faux avec [sort] car sort modifie un constant: const vector<float> &notes // sort(notes.begin(), notes.end());
    return *max_element(notes.begin(), notes.end());
}
float noteMin(const vector<float> &notes){
    if (notes.empty()) return 0;                    // meme chause ici: -> sort(notes.begin(), notes.end(),greater<float>());
    return *min_element(notes.begin(), notes.end());
}

int compterAuDessus(const vector<float> &notes, float seuil){ // 40 minute thought process
    int cpt = 0;
    for(float n : notes){
        if(n > seuil){
        cpt ++;
        }
    }
    return cpt;
}
int main(){
    vector<float> notes;
    SaisirNotes(notes);
    afficherNotes(notes);
    cout << "La moyenne" << CalculerMoy(notes) << " ";
    cout << "Note max" << noteMax(notes) <<  " ";
    cout << "Note min" << noteMin(notes) << " ";
    float seuil;
    cout << "Saisir le seuil" << endl;
    cin >> seuil;
    int x = compterAuDessus(notes,seuil);
    cout << "Notes en haut du seuil" << x << endl;
    return 0;
}*/

// Exercice 2
/*
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

void afficherMenu(){
    cout << "1. Ajouter 2. Afficher 3. Rechercher 4. Supprimer 5. Trier 0. Quitter"<< endl; 
}
void afficherContacts(const vector<string> &contacts){
    
        if(contacts.empty() == 1){
            cout << "Aucun contact" << " ";
        }
        for(const string& n : contacts){
        cout << "Les contactes:" << n <<endl;
        }
    }
int rechercherContact(const vector<string> &contacts, string nom){
    auto it = find(contacts.begin(), contacts.end(), nom); //auto: Déduit automatiquement le type d'une variable || find(beg,end): Comme un for
    if (it == contacts.end()) {
        return -1;
    }
    return it - contacts.begin(); //permet d'obtenir son indice dans le vector
}
bool supprimerContact(vector <string> &contacts, int numero){
    if(numero < 0){
        return false;
    }

      contacts.erase(contacts.begin() + numero);

     return true;
}

int main(){
    vector <string> contacts;
    int choix;
    string nom;
    int numero;

    do{
        afficherMenu();
        cout << "Saisir le choix" << endl;
        cin >> choix;
        cin.ignore();
        switch(choix){
            case 1 : 
            cout << "Saisit le nom du contact:";
            getline(cin, nom); 
            if (!nom.empty()) {
                contacts.push_back(nom);
            }
            break;

            case 2 :
            afficherContacts(contacts);
            break;

            case 3 :
            cout << "Nom à rechercher : ";
            getline(cin, nom);
            numero = rechercherContact(contacts, nom);
                if (numero == -1)
                    cout << "Contact introuvable" << endl;
                else
                    cout << "Contact trouvé à l'indice : " << numero << endl;
                break;

            case 4 :
            cout << "Indice du contact à supprimer : ";
            cin >> numero;
            if (supprimerContact(contacts, numero)){
                cout << "Contact supprime" << endl;
            }
            else{
                cout << "Contact introuvable";
            }
            break;

            case 5 :
            sort(contacts.begin(), contacts.end());
            cout << "Contacts triés" << endl;
            break;

            case 0 :
            cout << "Au revoir !" << endl;
            break;

            default :
            cout << "Choix invalide" << endl;
            
        }
    }while(choix != 0);

    return 0;
}
*/
// Exercice 3

#include <iostream>
#include <string>
#include <list>

using namespace std;

void afficherMenu(){
    cout << "1. Arrive 2. Prioritaire 3. Servir 4. Depart 5. Afficher 0. Fermer" << endl;
}
void afficherFile(const list <string> &file){
    if(file.empty()){
        cout << "La file est vide" << endl;
    }
    for (list<string> :: const_iterator it = file.begin(); it != file.end(); ++it)
    cout << *it << endl;
}
bool servirClient(list <string> &file, string &servi){
    if(file.empty()){
        return false;
    }
    servi = file.front();
    file.pop_front();
    cout << servi << endl;
    return true;
}
int main(){
    list<string> file;
    int choix;
    string nom;
    string servi;
    cout << "Saisir le nom du clien" << endl;
    cin >> nom;
    do{
        afficherMenu();
        cout << "Saisir le choix" << endl;
        cin >> choix;
        switch(choix){

        case 1:
        file.push_back(nom); 
        cout << "Client arrive" << endl;
        break;
        
        case 2:
        file.push_front(nom);
        break;

        case 3:
        int x = servirClient(file, servi);
        cout << "Client servi" << x << endl;
        break;

        case 4:
        cout << "File avant changement:" << endl;
        afficherFile(file);
        cout << "File apres changement:" << servirClient(file, servi) << endl;
        break;

        case 5:
        afficherFile(file);
        break;
        
        case 0:
        cout << "Guichet fermet" << endl;
        break;

        default:
        cout << "Choix invalide" << endl;
    }
    }while(choix != 0);
    return 0;
}
// exercice 4


#include <iostream>
#include <string>
#include <list>
#include <vector>

using namespace std;

void saisirListe(list <int> &liste){
    
    while(n < 0){
    if(n == 0){
         break;
    }
    if(n > 0){
        cout << "Saisir les elements de la liste" << endl;
        cin >> n;
        liste.push_back(n);
    }}
}

void afficherListe(const list<int> &liste, string titre){
    cout << "Le titre et ses elements:" << saisirliste(liste) << endl;
    cin >> titre;
}

void supprimerNegatifs(list <int> &liste){
for (list <int> :: const_iterator it = liste.begin(); it != liste.end(); ++it){
    cout << list.erase() << end.l;
}
}

int main(){
    list<int> liste;

    return 0;
}
