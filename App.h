#ifndef APP_H
#define APP_H

#include <iostream>
using namespace std;
#include <bitset>
#include "AccesI2C.h"
#include "SHTC3.h"
#define SHTC3_ADDR 0x70 //component


class App
{
public:
    App();
    ~App();
    void Init();// fonction d'initialisation de l'application
    void Loop();// boucle de l'application
    bool InitOK(); // retourne True si un SHTC a été trouvé sur le bus I2C
    
private:
    bool m_initOK;  //flag: True si un SHTC3 a été trouvé sur le bus I2C
    AccesI2C *m_accesI2C;   //pointeur vers le bus I2C à utiliser
    SHTC3 *m_shtc3; //premier composant SHTC3 trouvé (ou pas)
    bool CreateFirstSHTC3(const vector <unsigned char> &adresses);  // crée un composant SHTC3 parmi ceux trouvé sur le bus I2C
    void ExitError(const string &message);  //affiche un message d'erreur et sort de l'application

};

#endif // APP_H
