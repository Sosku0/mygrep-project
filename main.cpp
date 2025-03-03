
#include "iostream"
#include "cpp/handler.h"
#include "cpp/loader.h"

using namespace std;

//enableOptions = "-o";
//enableLineNumbering = "l";
//enableOccurrences = "o";
//enableIgnoreCase = "i";
//enableReverseSearch = "r";

// SEURAAVASSA SearchForOptionalArgument() MUUTETAAN ALKUPERÄISTÄ vector<bool> &optionalSettings JOTEN PALAUTUSTA EI TARVITA.
void SearchForOptionalArgument(string argument, vector<bool> &optionalSettings) { // HAETAAN VALINNAISET SUORITUS ARGUMENTIT.
  //cout << "DEBUG: Searching for optional argument from: " << argument << endl;

  vector<char> characters;

  for (char c : argument)
  {
    characters.push_back(c);
  }

  if (!characters.empty())
  {
    if (characters[0] == '-')
    {
      if (characters[1] == 'o')
      {
        optionalSettings[0] = true;
        for (int i = 2; i < characters.size(); i++)
        {
          if (characters[i] == 'l')
          {
            //cout << "DEBUG: Line numbering enabled" << endl;
            optionalSettings[1] = true;
          }
          if (characters[i] == 'o')
          {
            //cout << "DEBUG: Occurrences enabled" << endl;
             optionalSettings[2] = true;
          }
          if (characters[i] == 'i')
          {
            //cout << "DEBUG: IgnoreCase enabled" << endl;
            optionalSettings[3] = true;
          }
          if (characters[i] == 'r')
          {
            //cout << "DEBUG: Reverse Search enabled" << endl;
            optionalSettings[4] = true;
          }
        }
      }
    }
  }
}

int main(int argc, char* argv[]) { // OHJELMAN SUORITUS

  // LUODAAN TARVITTAVAT MUUTTUJAT TIEDON TALLETTAMISEEN KUTEN VALINNAISILLE SUORITUS ASETUKSILLE JA RIVIT TIEDOSTOSTA.
  vector<string> linesToSearchFrom;
  vector<bool> optionalSettings = {false, false, false, false, false}; //-o, l, o, i, r

  string searchString;
  string filename;


  // DEBUGGING
  /*cout << "DEBUG: Arguments in command found: " << argc << endl;
  for (int i = 0; i < argc; i++)
  {
    cout << "DEBUG: Argument " << i << ": " << argv[i] << endl;
  }
  */



  // OHJELMAN "VALIKKO"
  // SWITCH RIIPPUU ARGUMENTTIEN MÄÄRÄSTÄ
  // 1 = VAIN ./ohjelma (SULJETAAN SUORITTAMATTA)
  // 2 = VAIN ./ohjelma *SearchString* (SULJETAAN SUORITTAMATTA)
  // 3 = SUORITETTAVA KOMENTO ./ohjelma *SearchString* *File*
  // 4 = SUORITETTAVA KOMENTO ./ohjelma *OPTIONAL_SETTINGS* *SearchString* *File*
  switch (argc)
  {

    case 1:
      cout << "No arguments found \n"
      << "Missing: *SearchString* \n"
      << "Missing: *File*"
      << endl;
      break;

    case 2:
      cout << "Please provide a valid file." << endl;
      break;

    case 3:
      searchString = argv[1];
      filename = argv[2];

      linesToSearchFrom = loadFile(filename);
      if (!linesToSearchFrom.empty())
      {
        Search(searchString, linesToSearchFrom, optionalSettings);
      } else
      {
        cout << "No searchable lines were found in: " << filename << endl;
      }
      break;

    case 4:

      searchString = argv[2];
      filename = argv[3];

      linesToSearchFrom = loadFile(filename);

      SearchForOptionalArgument(argv[1], optionalSettings);

      if (!linesToSearchFrom.empty())
      {
        Search(searchString, linesToSearchFrom, optionalSettings);
      } else
      {
        cout << "No searchable lines were found in: " << filename << endl;
      }

      break;
  }
  return 0;
}