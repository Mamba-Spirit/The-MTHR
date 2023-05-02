#include "App.h"
#include "SHTC3.h"

App::App()
{
    m_initOK=false;
    // ouverture du port I2C
    m_accesI2C=new AccesI2C();
    if (m_accesI2C->IsOK())
    {
        //on recherche les composants sur le bus I2C
        vector <unsigned char> adresses;
        if (m_accesI2C->ScanBus(adresses))
        {
            // création du premier composant I2C SHTC3 trouvé
            m_initOK=CreateFirstSHTC3(adresses);
        }
    }
}

App::~App()
{
    if (m_initOK) delete m_shtc3;
    delete m_accesI2C;
}

bool App::InitOK(){

    return m_initOK;
}

void App::Init()
{
    //m_shtc3->Wake_up();
    float The_temperature;
    float The_humidity;
    
    if(m_shtc3->Read_the_temperature(The_temperature) && m_shtc3->ReadHumidity(The_humidity)){
        
        cout << "Valeur décimale de la Température = "<<The_temperature<<"°C"<<endl;
        cout << "Valeur décimale de l'humidité = "<<The_humidity<<" %"<<endl;
        
    }
    
    else{
        
        ExitError("Erreur lors de la lecture de la température et de l'humidité");
    }
    //m_shtc3->Temperature_Conversion(0x64, 0xA8);  //Testing the conversion function
}

void App::Loop()
{
    bool lecture_demandee=false;
    string reponse="";
    float The_temperature;
    float The_humidity;

    do
    {
        if(m_shtc3->Read_the_temperature(The_temperature) && m_shtc3->ReadHumidity(The_humidity)){
            
            cout << "Valeur décimale de la Température = "<<The_temperature<<"°C"<<endl;
            cout << "Valeur décimale de l'humidité = "<<The_humidity<<" %"<<endl;
        }
        else{
            
            ExitError("Erreur lors de la lecture de la température et de l'humidité");
        }

            cout << "Autre lecture (o/n)? ";
            cin >> reponse;
            if (reponse=="o"){
                
                lecture_demandee=true;
            }
            else
                lecture_demandee = false;
    }
    while (lecture_demandee);
}


bool App::CreateFirstSHTC3(const vector <unsigned char> &adresses)
{
    bool retour=false;
    bool find=false;
    unsigned int i=0;
    if (!adresses.empty())
    {
        //on cherche un SHTC3 parmi les adresses fournies
        do
        {
            if (SHTC3::ValidateAddress(adresses[i])) find=true;
            
            else i++;
        }
        while (i<adresses.size() && !find);
    }
    // si on a trouvé un SHTC3 sur le bus
    if (find)
    {
        cout << "SHTC3 trouvé à l'adresse 0x"<< hex << (int)adresses[i] <<endl;
        // on essaye de le créer
        m_shtc3=new SHTC3(m_accesI2C,adresses[i]);
        retour=m_shtc3->IsOK();
    }
    return retour;
}

void App::ExitError(const string &message)
{
    cout << message <<endl;
    exit(1);
}
