#include "dictionary.hpp"

vector< string > LoadDictionary(string path)
{
    //this is a ifstream instance to read our dictionary file
    ifstream filereader;
    filereader.open(path);
    
    vector<string> wordlist;
    if(filereader.is_open() == false)
        return wordlist;
    
    //reading list of words
    string tmp;
    while(getline(filereader, tmp))
    {
        //cout << tmp << endl;
        wordlist.push_back(tmp);
    }
        
    wordlist.erase(wordlist.begin()+0);
    
    return wordlist;
} 
