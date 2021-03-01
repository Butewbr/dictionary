#include "dictionary.hpp"

using namespace std;

int main()
{
    vector< vector< string > > listofdicts;
    vector< string > names;
    vector< string > wordlist;
    string query;
    int NDEBUG = 1;
    int choice = 0;

    while(choice!=5)
    {
    if(NDEBUG==1) cout << "DICTIONARY MANIPULATOR HACK" << endl;
    if(NDEBUG==1) cout << "Select an option:" << endl;
    if(NDEBUG==1) cout << "1. Open dictionary..." << endl;
    if(NDEBUG==1) cout << "2. Search substrings..." << endl;
    if(NDEBUG==1) cout << "3. Remove words containing substrings..." << endl;
    if(NDEBUG==1) cout << "4. Show statistics" << endl;
    if(NDEBUG==1) cout << "5. Exit" << endl;
    if(NDEBUG==1) cout << "Option: ";
    cin >> choice;

        if (choice == 1) //funcionando
        {
            string path;
            if(NDEBUG==1) cout << "Enter a dictionary file: ";
            cin >> path;
            vector< string > wordlist = LoadDictionary(path);
            if(NDEBUG==1) cout << "File to be read: " << path << endl;
            listofdicts.push_back(wordlist); 
            names.push_back(path);  
        }

        else if (choice == 2) //funcionando
        {
            if(NDEBUG==1) cout << "Enter a substring to search: ";
            cin >> query;
            int amount=0;
            for (size_t j = 0; j < listofdicts.size(); j++)
            {
                for(size_t i=0; i < listofdicts.at(j).size(); i++)
                {
                    string str = listofdicts.at(j).at(i);
                    size_t found=str.find(query);
                    if (found != -1)
                    {
                        amount++;
                        if(NDEBUG==1) cout << "Substring found!" << endl;
                        if(NDEBUG==1) cout << query << " was found in dictionary " << names.at(j) << " in line " << i << endl;
                        if(NDEBUG==1) cout << "Full string: ";
                        cout << str << endl;
                    }
                }
            }
            if(NDEBUG==1) cout << "Substring was found " << amount << " times." << endl;
        }

        else if (choice == 3)
        {

            string wordtoremove;
            if(NDEBUG==1) cout << "Enter a substring to remove: ";
            cin >> wordtoremove;
            int amount=0;

            for (size_t j = 0; j < listofdicts.size(); j++)
            {
                for (size_t i = 0; i < listofdicts.at(j).size(); i++)
                {
                    int counter=0;
                    string str = listofdicts.at(j).at(i);
                    size_t found = str.find(wordtoremove);
                    if (found != -1)
                    {                  
                        amount++;
                        if(NDEBUG==1) cout << "String removed!" << endl;
                        if(NDEBUG==1) cout << wordtoremove << " was removed from dictionary " << names.at(j) << " line " << i << endl;
                        if(NDEBUG==1) cout << "Word removed: ";
                        if(NDEBUG==1) cout << str << endl;
                        listofdicts.at(j).erase(listofdicts.at(j).begin() + i);
                        i--;
                    }
                }
            }
            if(NDEBUG==1) cout << amount << " words removed." << endl;
        }

        else if (choice == 4) //funcionando
        {
            cout << "Statistics:" << endl;

            for (size_t i=0; i < listofdicts.size(); i++)
            {
                cout << names.at(i) << " -> " << listofdicts.at(i).size() << " words" << endl;

            }
        }

        else
        {
            return 1;
        }

    }
    
    return 0;
}