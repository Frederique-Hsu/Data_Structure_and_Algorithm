#include "exercises.h"

#include <map>
#include <iostream>
#include <sstream>


using namespace std;

void word_conversion(int argc, char* argv[])
/* A program to transform words.
 * Take 2 arguments: The first is name of the word transformation file,
 *                   the second is name of the input to transform.
 */
{
    /* map to hold the word transformation pairs:
     * key is the word to look for in the input; 
     * value is the word to use in the output
     */
    map<string, string> trans_map;
    string key, value;
    if (argc != 3)
    {
        throw runtime_error("wrong number of arguments");
    }
    /* open transformation file and check that open succeeded */
    ifstream map_file;
    if (!open_file(map_file, argv[1]))
    {
        throw runtime_error("no transformation file");
    }
    /* read the transformation map and build the map */
    while (map_file >> key >> value)
    {
        trans_map.insert(make_pair(key, value));
    }
    /* OK, now we are ready to do the transformations, 
     * open the input file and check that the open succeeded 
     */
    ifstream input;
    if (!open_file(input, argv[2]))
    {
        throw runtime_error("no input file");
    }
    string line;        /* hold each line from the input */
    /* read the text to transform it a line at a time */
    while (getline(input, line))
    {
        istringstream stream(line);     /* read the line a word at a time */
        string word;
        bool firstword = true;      /* controls whether a space is printed */
        while (stream >> word)
        {
            /* OK: the actual mapwork, this part is the heart of this program */
            map<string, string>::const_iterator map_cit = trans_map.find(word);
            if (map_cit != trans_map.end())     /* if this word is in the transformation map */
            {
                word = map_cit->second;     /* replace it by the transformatuon value in the map */  
            }
            if (firstword)
            {
                firstword = false;
            }
            else
            {
                cout << " ";    /* print the space between words. */
            }
            cout << word;
        }
        cout << endl;       /* done with this line of input */
    }
}

ifstream& open_file(ifstream& in, const string& file)   /* opens in binding it to the given file */
{
    in.close();     /* close in case that it was already opened */
    in.clear();     /* clear any existing errors */
    /* if the open fails, the stream will be in an invalid state */
    in.open(file.c_str());      /* open the file we were given */
    return in;      /* condition state is good if open succeeded */
}