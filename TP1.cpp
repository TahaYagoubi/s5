// EXERCICE 1

#include<iostream>
#include<string>

const int LARGEUR = 40;
using namespace std;
void afficherLigne(int longueur = LARGEUR, char car = '*'){
    cout << longueur << endl;
}
void afficherEntete(){
    cout << "Bienvenue au TP de POO" << endl;
}
string demanderNom(string nom){
    cout << "entrer votre nom" << endl;
    cin >> nom ;
    getline(cin,nom);
     cout << "Votre nom est: " <<nom <<endl;
     return nom;
}
void afficherMessageBienvenue(string nom){
    cout << "Bienvenue "<<nom <<endl;
nom.length();
cout << "Votre nom contient :" << endl;
}
int main(){
	string nom;
afficherLigne(LARGEUR,'=');
afficherEntete();
afficherMessageBienvenue(nom);
return 0;
}

// EXERCICE 2 

#include<iostream>
#include<iomanip>

 using namespace std; 
const float SOLDE_INITIALE = 1000.0;
 
        bool deposer(float &solde, float montant){ 
            if(montant <= 0){
                cout << "False" << endl;
                return false;
            }
            solde += montant;
            return true;
        }
        bool retirer(float &solde, float montant){
            if(montant <= 0 || montant > solde){ 
                cout << "False" << endl;
                return false;
            }
            solde -= montant;
            return true;
            }
        void afficherSolde(float solde){
            cout << fixed << setprecision(2) << solde << endl;
        }
        void afficherMenu(){
            cout << "affichage du menu" << endl;
            cout << "1 Deposer" << endl;
            cout << "2 Retirer" << endl;
            cout << "3 Afficher le solde" << endl;
            cout << "4 Quitter" << endl;
            cout << "Votre choix : ";
        }
 int main(){
float solde = SOLDE_INITIALE;
int choix;
float montant;    
     do{
      afficherMenu();
      cin >> choix;
         switch(choix){
           case 1:
             cout << "Montant a deposer : " << endl;
             cin >> montant;
             deposer(solde , montant);
           break;

           case 2:
              cout << "Montant a retirer : " << endl;
              cin >> montant;
              retirer(solde , montant);
            break;

            case 3:
              afficherSolde(solde);
            break;

            case 4:
              cout << "Quitter" << endl;
            break;
                    
             default:
              cout << "Choix invalid" << endl;
            }
            }while(choix != 4);

            return 0;
        }
 #include <iostream>
 #include <cstdlib>
 #include <ctime>

    // exercice 3

    using namespace std;
 const int NB_MIN = 1;
 const int NB_MAX = 100;
 const int MAX_TENTATIVES = 7;
        int genererNombreSecret(){
            return rand() % (NB_MAX - NB_MIN + 1) + NB_MIN; 
        }
        bool faireDeviner(int nbrSecret, int &tentatives){
            tentatives = 0;
            int proposition;
            nbrSecret = genererNombreSecret();          
        
            while(tentatives < MAX_TENTATIVES){{
                cout << "Saisir la proposition" << endl;
                cin >> proposition;    
                tentatives ++;
                if(nbrSecret > proposition){
                cout << "Trop petit" << endl;
                }
                else if(nbrSecret < proposition){
                cout << "Trop GRAND" << endl;
                }
                else if(nbrSecret == proposition){
                cout << "Gagne" << endl;
                return true;
                }
            
            }}
        }
        void afficherResultat(bool reussi, int tentatives, int nbrSecret){
            reussi = faireDeviner(nbrSecret,tentatives);
            if(tentatives < nbrSecret || reussi == true){
            cout << "Non reussi" << endl;
            }
            if(tentatives == nbrSecret){
            cout << nbrSecret << endl;
            }
        }
        void jouePartie(){
            int proposition = 7;
            int nbrSecret = 10;
            char x;
            do{
            cout << "Rejouer?" << endl;
            if(x == '0'){
            faireDeviner(nbrSecret,proposition);
        }
        else{
            cout << "Faux" << endl;
        }
        }while(nbrSecret == 7);
        }
        int main(){
            srand(time(0));
            bool reussi;
            int tentatives = MAX_TENTATIVES;
            int nbrSecret = 7;           
            genererNombreSecret();
            faireDeviner(nbrSecret,tentatives);
            afficherResultat(reussi,tentatives,nbrSecret);
            jouePartie();
            return 0;
        }

        // exercice 4

        #include <iostream>
        #include <iomanip>
        #include <string>
        using namespace std;

        float saisirNote(int numero){
            float n;
            do{
                cout  << "Saisir la note" << numero << endl;  
                cin >> n;
            }while(n <= 0);
            return n;
        }
        float calculerMoyenne(float n1, float n2, float n3){
            return (n1 + n2 + n3)/3;
        }
        string calculerMention(float moyenne){
            if(moyenne < 10){
                return "echec";
            }
            else if(moyenne <= 12 ){
                return "Passable";
            }
            else if(moyenne <= 14 ){
                return "Assez bien";
            }
            else if(moyenne <= 16 ){
                return "Bien";
            }
            else
                return "Tres bien";
            
        }
        int main(){
            int n;
            do{
            cout << "Saisir le nombre des etudiants" << endl;
            cin >> n;
            }while(n <= 0);
            cin.ignore();
            string *noms = new string[n];
            float *notes = new float[3 * n]; //tableau dynamique à une seule dimension, avec 3 notes
            for(int i = 0 ; i < n ; i++){
                    cout << "Nom de l'etudiant(char):" << i + 1 << endl;
                    getline(cin , noms[i]); // ignorer les espaces entre les noms
            }
            for(int i = 0 ; i < n ; i++){
                    cout  << "Notes de l'etudiant:" << noms[i] << endl;
                     for(int j = 0; j < 3; j++) {
                    notes[3*i + j] = saisirNote(j + 1);//notes[3*i + j] stocke cette valeur dans la bonne case.
            }
            }
            
            float somme = 0;
            for(int i = 0 ; i < n ; i++){
                    float Moyenne = calculerMoyenne(notes[3*i],notes[3*i + 1],notes[3*i + 2]);
            
            string Mention = calculerMention(Moyenne);
            
             cout << noms[i] << Mention << Moyenne << endl;
             somme += Moyenne;
            }
            float moyenneClasse = somme / n;
            cout << "Moyenne de la classe : " << moyenneClasse << endl;
            delete[] noms;
            delete[] notes;
            return 0;
        }

        exercice 5

#include <iostream>
#include <string>
#include <cctype>
using namespace std;
    const int Longuer_min = 8;

    void compterCaracteres(string mdp, int &majuscules, int &miniscules, int &chiffres, int &speciaux){
        majuscules = 0;
    miniscules = 0;
    chiffres = 0;
    speciaux = 0;

    for(int i = 0; i < mdp.length(); i++) {
        if(isupper(mdp[i])) {
            majuscules++;
        }
        if(islower(mdp[i])) {
            miniscules++;
        }
        if(isdigit(mdp[i])) {
            chiffres++;
        }
        if(!isalpha(mdp[i]) && !isdigit(mdp[i])) {
            speciaux++;
        }
    }
}
    int compterCriteres(string mdp){
        int critere = 0;
        int critereisupper = 0;
        int critereislower = 0;
        int critereisdigit = 0;
        int critereisalpha = 0;
        compterCaracteres(mdp, critereisupper, critereislower, critereisdigit, critereisalpha);
        if(mdp.length() >= Longuer_min){
           critere ++;
        }
        if(critereisupper >= 1){
            critere ++;
        }
        if(critereislower >= 1){
            critere ++;
        }
        if(critereisdigit >= 1){
            critere ++;
        }
        if(critereisalpha >= 1){
            critere ++;
        }
        return critere;
    
    }
    bool estRobuste(string mdp){
        int critere = compterCriteres(mdp);
        return critere == 5;
    
    }
    string evaluerNiveau(string mdp){
        int critere = compterCriteres(mdp);
        if(critere == 5){
            return "Fort";
        }
        if(critere >= 3 && critere <= 4){
            return "Moyen";
        }
        if(critere >= 0 && critere <= 2){
            return "Faible";
        }
        return mdp;
    }

    int main(){
        string mdp;
        while(estRobuste(mdp) == 0){
            cout << "Saisir le MP:" << endl;
            cin >> mdp;
        }
        cout << "Le niveau est:" << evaluerNiveau(mdp);
        int majuscules ;
        int miniscules ;
        int chiffres ;
        int speciaux ;
        compterCaracteres(mdp, majuscules,  miniscules, chiffres, speciaux);
    return 0;
    }
