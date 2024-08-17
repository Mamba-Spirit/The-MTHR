/*******************************************************************************
 * Name:      AccesI2C.h
 * Projet:    AccesI2C
 * utilité:   Bibliothèque  permettant d'accéder au bus I2C sur raspberry PI
 * Author:    Axel NGANDU BISEBA
 ******************************************************************************/
#ifndef ACCESI2C_H
#define ACCESI2C_H

#define BUSI2C "/dev/i2c-1" // chemin du bus i2C

#include <iostream>
using namespace std;

#include <sys/ioctl.h>
#include <fcntl.h>
#include <unistd.h>
#include <vector>
using std::vector;
#include <linux/i2c.h>
#include <linux/i2c-dev.h>
extern "C" {
#include <i2c/smbus.h> // pour i2c_smbus_read_byte
}

class AccesI2C
{
public:
    AccesI2C(const string &device=BUSI2C); 
    ~AccesI2C();
    bool IsOK(); // bus I2C correctement ouvert
    // true si composant présent à adresse
    bool ComponantACK(const unsigned char &adresse); 
    // retourne les adresses des composants trouvé sur le bus
    bool ScanBus(vector <unsigned char> &adresses); 
    // lit un ou plusieurs octets 
    bool Read(const unsigned char &adresse, unsigned char &data);
    bool ReadN(const unsigned char &adresse, const unsigned int &N, 
               vector <unsigned char> &datas);
    // écrit un ou plusieurs octets 
    bool Write(const unsigned char &adresse, const unsigned char &data);
    bool WriteN(const unsigned char &adresse, const unsigned int &N, 
                const vector <unsigned char> &datas);

private:
    int m_fdI2C=0; // file descriptor du bus
    string m_device; // contient le chemin absolu du bus
    bool m_I2C_OK; // True si bus I2C correctement ouvert
};

#endif // ACCESI2C_H
