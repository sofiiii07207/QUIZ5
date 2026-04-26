#include <iostream> 
#include <string>
#include <vector>
using namespace std;

class Personaje {
public:
Personaje(string nombre, int vida, int nivel)
    : nombre_(nombre), 
      vida_(vida), 
      nivel_(nivel) {}
  void mostrar() const{
      cout << "["<< nivel_ <<"]" << nombre_
      << "HP:" << vida_ << endl;
  }
  virtual void atacar() const{
    cout<< nombre_ << "ataca de forma basica" << endl;
  }
  virtual ~Personaje() {}
protected:
  string nombre_; 
  int vida_; 
  int nivel_;
};
class Guerrero : public Personaje {
public:
    Guerrero(string nombre, int vida, int nivel, string arma, int fuerza)
    : Personaje (nombre, vida, nivel),
    arma_(arma), 
    fuerza_(fuerza) {}
    void info_guerrero() const{
    cout << "Arma:" << arma_ << endl;
    cout << "Fuerza:" << fuerza_ << endl;
    }
    void atacar () const override {
        cout << nombre_ << "ataca con una" << arma_ << endl;
        cout << "Dano fisico: " << fuerza_ *2 << endl;
    }
private: 
string arma_;
int fuerza_;
};

class Mago : public Personaje { 
public:
    Mago(string nombre, int vida, int nivel, string escuela, int mana)
    : Personaje (nombre, vida, nivel),
    escuela_(escuela), 
    mana_(mana) {}
    void info_mago() const {
    cout << "Escuela:" << escuela_ << endl;
    cout << "Mana:" << mana_ << endl;
    }
    void atacar() const override {
        cout << nombre_ << "lanza un hechizo de" << escuela_ << endl;
        cout << "Dano magico: " << mana_/2 << endl;
    }
private: 
string escuela_;
int mana_;
};
class Arquero: public Personaje {
public:
    Arquero(string nombre, int vida, int nivel, string arco, int precision)
    : Personaje(nombre, vida, nivel),
      arco_(arco),
      precision_(precision) {}
    void atacar() const override {
    cout << nombre_ << "dispara con" << arco_ << endl;
    cout << "Precision:" << precision_ << "% Dano:" << precision_ * 3 << endl;
    }
private:
string arco_;
int precision_;
};

int main() {
vector<Personaje*> partida;
partida.push_back(new Personaje("Aldeano", 30, 1));
partida.push_back(new Guerrero("Thorin", 100, 5, "Hacha de guerra", 42));
partida.push_back(new Mago("Elara", 75, 7, "Fuego", 120));
partida.push_back(new Guerrero("Ragnar", 120, 8, "Espada runa", 58));
partida.push_back(new Arquero("Sergio", 90, 10, "Arco Largo", 95));
partida.push_back(new Arquero("Sofia", 80, 9, "Arco Oscuro", 88));
cout << "=== Ronda de combate ===" << endl;

for (Personaje* p:partida) {
p->mostrar(); 
p->atacar(); 
cout << endl;
}
for (Personaje* p : partida) delete p;
return 0;
}
