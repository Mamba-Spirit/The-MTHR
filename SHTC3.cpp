#include "SHTC3.h"

SHTC3::SHTC3(AccesI2C *I2C,const unsigned char &adresse)
{
    m_I2C=I2C;
    m_adresse=adresse;
}

SHTC3::~SHTC3()
{
}

unsigned char SHTC3::GetMinAddress()
{
    return ADDRESS_MIN;

}

unsigned char SHTC3::GetMaxAddress()
{
    return ADDRESS_MAX;

}

bool SHTC3::ValidateAddress(const unsigned char &adresse)
{
    return ((adresse>= GetMinAddress()) && (adresse<= GetMaxAddress()));
}

bool SHTC3::Wake_up()
{
    bool retour = true;
    vector<unsigned char> data;
    data.push_back(0x35);
    data.push_back(0x17);

    if (!(m_I2C->WriteN(SHTC3_ADDR, 2, data)))
    {

        cout << "probleme from the wake_up function" << endl;
        retour = false;
    }

    return retour;
}


bool SHTC3::Read_the_temperature(){

    bool retour= true;
    // envoie de la commande pour le prelevement de la temperature//
//************************************************************************************************
    vector<unsigned char> data;
    data.push_back(0x78);
    data.push_back(0x66);
    if(!(m_I2C->WriteN(SHTC3_ADDR, 2, data))){
        cout<<"la commande de la prise de mesude de la température ne fonctionne pas"<<endl;
        retour = false;
    }
//************************************************************************************************
    sleep(15000); //On donne le temps au capteur de faire le prelevement//
    
    vector<unsigned char> temp(3);
    
    if(!(m_I2C->ReadN(SHTC3_ADDR, 3, temp))){
        cout<<"Echec de lecture de la temperature"<<endl;
        retour = false;
    }
    
    if(retour){
        unsigned int temperature_preleve = (temp[0]*256)+temp[1];
        int temperature_reel = 45+(175*(temperature_preleve/65536));
    }
    
    return retour;
}
bool SHTC3::ReadHumidity(){
        bool retour= true;
    // envoie de la commande pour le prelevement d'humidité//
//************************************************************************************************
    vector<unsigned char> data;
    data.push_back(0x58);
    data.push_back(0xE0);
    if(!(m_I2C->WriteN(SHTC3_ADDR, 2, data))){
        cout<<"Echec de messure d'humidité"<<endl;
        retour = false;
    }
//************************************************************************************************
    sleep(15000); //On donne le temps au capteur de faire le prelevement//
    
    vector<unsigned char> humidity(3);
    
    if(!(m_I2C->ReadN(SHTC3_ADDR, 3, humidity))){
        cout<<"Echec de lecture d'humidité"<<endl;
        retour = false;
    }
    
    if(retour){
        unsigned int humidity_preleve = (humidity[0]*256)+humidity[1];
        int humidity_reel = 100 * (humidity_preleve/65536);
    }
    
    return retour;
}
float SHTC3::testing_the_conversion(unsigned char msb, unsigned char lsb){
    unsigned char temp_msb=msb;
    unsigned char temp_lsb=lsb;
    unsigned int temperature_preleve = temp_msb<<8 | temp_lsb;
    //(temp_msb*256)+temp_lsb;
    int temperature_reel = 175.0f * (float)temperature_preleve/65535.0f -45.0f;
    //-45+(175*(temperature_preleve/65536));
    cout<<"the temperature is : "<<temperature_reel<<" degre celcius"<<endl;
    
    return temperature_reel;
}