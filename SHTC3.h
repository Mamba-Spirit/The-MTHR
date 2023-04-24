#ifndef SHTC3_H
#define SHTC3_H

#include <vector>
using std::vector;
#include <cmath>
#include <unistd.h>
#include "../include/AccesI2C.h"
#define ADDRESS_MIN 0x70
#define ADDRESS_MAX 0x77
#define SHTC3_ADDR 0x70

class SHTC3 : public AccesI2C
{
public:
    SHTC3(AccesI2C *I2C,const unsigned char &adresse);
    ~SHTC3();
    bool StartConvert(); // démarre la conversion de Température
    bool ReadTemperature (float &temperature);  
    //bool IsOK(); // composant présent
    static unsigned char GetMinAddress(); //retourne l'adresse min possible des composants 0x70
    static unsigned char GetMaxAddress(); // retourne l'adresse max possible des composants 0x77
    static bool ValidateAddress(const unsigned char &adresse); // True si l'adresse proposée est valide (entre 0x70 et 0x77)
    bool Wake_up(); //this function allow the shct3 to wakeup to quit the sleep mode
    bool WriteNI2C(const unsigned char &adresse, const unsigned int &N, const vector <unsigned char> &data);
    bool Read_the_temperature();  //
    bool ReadHumidity();    //Lecture de l'humidité relative
    float testing_the_conversion(unsigned char msb, unsigned char lsb);
private:
    AccesI2C *m_I2C; // objet permettant l'accès au bus i²C
    unsigned char m_adresse; // adresse du composant
    
    
                        
};

#endif // SHTC3_H
