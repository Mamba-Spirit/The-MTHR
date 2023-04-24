#include "App.h"
#include "AccesI2C.h"
int main()
{
    App MyApp;
    // on a trouvé un SHTC3
    if (MyApp.InitOK())
    {
        // on l'initialise
        MyApp.Init();
        // boucle de lecture du SHTC3
       // MyApp.Loop();
    }
    
    else
        cout << "pas de SHTC3 trouvé sur le bus I2C";
    return 0;
}