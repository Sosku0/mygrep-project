//
// Created by oskar on 03/03/2025.
//

#include "handler.h"

#include <cstring>
#include <iostream>
#include <ostream>
#include <vector>

using namespace std;

// MUUTETAAN STRING PIENIKSIKIRJAIMIKSI
string StringToLowerCase(string str)
{
    for (char &c : str)
    {
        c = tolower(c);
    }
    return str;
}
int ScanLine(string line, string searchString, bool reverseSearch)
{

    size_t result = line.find(searchString);

    // JOS REVERSE SEARCH EI OLE PÄÄLLÄ NIIN PALAUTETAAN LÖYDETYT RIVIT MISTÄ HAKU LÖYTYY
    // JOS REVERSE SEARCH TAAS ON PÄÄLLÄ NIIN PALAUTETAAN VAIN "1" ELI KAIKKI MUUT RIVIT KUIN NE MISTÄ SANA LÖYTYY
    if (!reverseSearch)
    {
        if (result != string::npos)
        {
            return result;
        }
        else
        {
            return -1;
        }
    } else
    {
        if (result == string::npos)
        {
            return 1; // Hakusanaa ei löydy
        }
        else
        {
            return -1; // Hakusana löytyy
        }
    }
}

void Search(string searchString, vector<string> linesToSearchFrom, vector<bool> &optionalSettings)
{
    // SEURAAVA TARKISTAA ONKO OPTION 'i', JOS ON NIIN TEKEE JOKAISESTA CHARACTERISTA PIENEN. (IgnoreCase)
    if (optionalSettings[0] == true && optionalSettings[3] == true)
    {
        searchString = StringToLowerCase(searchString);
    }
    string currentLine;

    cout << endl;
    cout << "Searching for: " << searchString << "\n";

    int matchCount = 0;
    //vector<int> lineNumbersForMatches;


    for (int i = 0; i < linesToSearchFrom.size(); i++)
    {
        //cout << "Step: " << i << " -> Processing line: " << linesToSearchFrom[i] << endl;

        // SEURAAVA TARKISTAA ONKO OPTION 'i', JOS ON NIIN TEKEE JOKAISESTA CHARACTERISTA PIENEN. (IgnoreCase)
        if (optionalSettings[0] == true && optionalSettings[3] == true)
        {
             currentLine = StringToLowerCase( linesToSearchFrom[i]);
        } else
        {
            currentLine = linesToSearchFrom[i];
        }

        // HAETAAN RESULT: ELI SIIS TUTKITAAN FUNKTIOLLA ScanLine() ONKO 'i' RIVILLÄ ETSITTYÄ MERKKIJONOA.
        int result = ScanLine(currentLine,searchString, optionalSettings[4]);

        // KÄSITELLÄÄN PALAUTETTU TULOS:
        if (result != -1)
        {
            cout << "\n";
            if (optionalSettings[0] == true && optionalSettings[1] == true)
            {
                    cout << i + 1 << ": ";
            }

            cout << linesToSearchFrom[i];
            cout << endl;

            matchCount++;
        }

    }
    if (optionalSettings[0] == true, optionalSettings[2] == true)
    {
        cout << endl;
        if (!optionalSettings[4]) {
            cout << "Occurrences of lines containing '" << searchString << "': " << matchCount << endl;
        } else {
            cout << "Occurrences of lines NOT containing '" << searchString << "': " << matchCount << endl;
        }
    }
}
