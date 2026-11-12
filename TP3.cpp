#include <iostream>
#include <iomanip>

using namespace std;

class rectangle{

}
private:
double largeur;
double hauteur;
public:
rectangle():largeur(1),hauteur(1){

}
rectangle(double l, double h){
largeur = l;
hauteur = h;
cpt++;
}
rectangle(double largeur, double hauteur){
    this -> largeur = largeur;
    this -> hauteur = hauteur;
}
rectangle(double l, double h):largeur(l), hauteur(h)
~rectangle(){
    count << "Ca marche";
}
double aire() const{
     returb largeur * hauteur;
}
double Perimetre(){
    return 2*(hauteur * largeur);
}
bool estcarre() const{
    return largeur == hauteur;
}
bool redimensionner(double largeur, double hauteur){
    if(Largeur =< 0 || hauteur =< 0){
        return false;
    }
    else{
        this -> largeur = largeur;
        this -> hauteur = hauteur;
        return true;
    }
}
void afficher() const{

}
cout << Largeur << "x" << hauteur;
cout << "L'aire" << aire();
cout << "Perimetre" << Perimetre();
if (estcarre()){
    cout << "carre"; 
}
int main(){
    rectangle r1;
    rectangle r2(4,3);
    rectangle r3(5,5);
    r2.afficher();
    r3.afficher();
    if(r2.redimensionner(2.2))
    cout << "ok";
    Rectangle :: afficher();
    Rectangle *R = new Rectangle(4,2);
    cout << fixed << setprecision(2);
    return 0;
}

