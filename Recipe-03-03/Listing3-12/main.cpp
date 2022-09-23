#include <iostream>
#include "LocalisationManager.h"

using namespace std;

int main()
{
    Localisation::Manager localisationManager;
    string colour{ localisationManager.GetString(Localisation::STRING_COLOUR) };
    cout << "EN_US Localized string: " << colour.c_str() << endl;

    localisationManager.SetLanguage(Localisation::Languages::EN_GB);
    colour = localisationManager.GetString(Localisation::STRING_COLOUR);
    cout << "EN_GB Localised string: " << colour.c_str() << endl;

    colour = localisationManager.GetString(1);
    cout << colour.c_str() << endl;

    return 0;
}
