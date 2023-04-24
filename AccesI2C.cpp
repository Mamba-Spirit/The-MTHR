/*******************************************************************************
 * Name:      AccesI2C.cpp
 * Projet:    AccesI2C
 * utilité:   Bibliothèque  permettant d'accéder au bus I²C sur raspberry PI
 * Author:    Éric Laly (elaly@free.fr)
 * Created:   2021-10-16
 ******************************************************************************/
#include "AccesI2C.h"

AccesI2C::AccesI2C(const string &device)
{
    // on ouvre le port i²C
    m_fdI2C= open(device.c_str(), O_RDWR);
    if (m_fdI2C < 0)
        m_I2C_OK=false;
    else
        m_I2C_OK=true;
}

AccesI2C::~AccesI2C()
{
    close(m_fdI2C);
}

bool AccesI2C::IsOK()
{
    return m_I2C_OK;
}

bool AccesI2C::ComponantACK(const unsigned char &adresse)
{
    bool retour=false;
    if (IsOK())
    {
        // on sélectionne le composant
        if (ioctl(m_fdI2C, I2C_SLAVE, adresse) >= 0)
            // on vérifie si le composant répond positivement
            if (i2c_smbus_read_byte(m_fdI2C)>=0)
                retour=true;
    }
    return retour;
}

bool AccesI2C::ScanBus(vector <unsigned char> &adresses)
{
    bool retour=false;
    if (IsOK())
    {
        // on scanne la plage d'adresse
        for (unsigned int adresse=0x08; adresse<0x78; adresse++)
            if (ComponantACK(adresse)) // si le composant existe
            {
                adresses.push_back(adresse); // on l'ajoute
                retour=true;
            }
    }
    return retour;
}

bool AccesI2C::Read(const unsigned char &adresse, unsigned char &valeur_lue)
{
    bool retour=false;
    vector <unsigned char> datas;
    if (ReadN(adresse,1,datas))
    {
        retour=true;
        valeur_lue=datas[0];
    }
    return retour;
}

bool AccesI2C::ReadN(const unsigned char &adresse, const unsigned int &N,
                     vector <unsigned char> &datas)
{
    bool retour=false;
    if (IsOK())
    {
        if (ComponantACK(adresse))
        {
            // lecture des N octets de réponse
            int iN=N;
            unsigned char *cdata=new unsigned char[N];
            if (read(m_fdI2C,cdata,N)==iN)
            {
                datas.clear();
                for (unsigned int i=0; i<=N; i++)
                    datas.push_back(cdata[i]);
                retour=true;
            }
        }
    }
    return retour;
}

bool AccesI2C::Write(const unsigned char &adresse, const unsigned char &data)
{
    vector <unsigned char> datas;
    datas.push_back(data);
    return WriteN(adresse,1,datas);
}

bool AccesI2C::WriteN(const unsigned char &adresse, const unsigned int &N, 
                      const vector <unsigned char> &datas)
{
    bool retour=false;
    if (IsOK())
    {
        if (ComponantACK(adresse))
        {
            char *cdata=new char[N];
            for (unsigned i=0; i<N; i++) cdata[i]=datas[i];
            int iN=N;
            if (write(m_fdI2C, cdata, N) == iN)
                retour=true;
            delete cdata;
        }
    }
    return retour;
}
