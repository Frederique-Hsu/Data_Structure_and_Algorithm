#include "IO_Stream.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

static void process_input(void);

void execute_test_cases(void)
{
    // refresh_ostream_buffer();
    // access_file_stream();
    convert_format_sstream_objects();
}

void manage_query_stream_state(void)
{
    int ival;
    /* read cin and test only for EOF; 
     * loop is executed even if there are other IO failures 
     */
    while (cin >> ival, !cin.eof())
    {
        if (cin.bad())      /* input stream is corrupted; bail out */
        {
            throw runtime_error("IO stream corrupted.");
        }
        if (cin.fail())     /* bad input */
        {
            cerr << "bad data, try again.";     /* warning the user */
            cin.clear(istream::failbit);        /* reset the stream */
            continue;       /* get the next input */
        }
        /* now safely to process the ival */
    }
}

void access_condition_state(void)
{
    istream::iostate old_state = cin.rdstate();     /* remember current state of cin */
    cin.clear();
    process_input();    /* use cin */
    cin.clear(old_state);       /* now reset cin to old state */

    ifstream is;
    is.setstate(ifstream::badbit | ifstream::failbit);      /* set both badbit and the failbit */
}

void process_input(void)
{
}

void refresh_ostream_buffer(void)
{
    cout << "hi!" << flush;     /* flushes the buffer; adds no data */
    cout << "hi!" << ends;      /* inserts a null, then flushes the buffer */
    cout << "hi!" << endl;      /* inserts a newline, then flushes the buffer */

    cout << unitbuf << "first" << " second" << nounitbuf;

    /* Illustration only : the library ties cin and cout for us */
    cin.tie(&cout);
    ostream* old_tie = cin.tie();
    cin.tie(0);     /* break tie to cout, cout no longer flushed when cin is read */
    cin.tie(&cerr);     /* ties cin and cerr, not necessarily a good idea. */

    cin.tie(0);     /* break tie between cin and cerr */
    cin.tie(old_tie);   /* restablish normal tie between cin and cout */
}

void access_file_stream(void)
{
    string ifile = "in.txt";
    /* construct an ifstream and bind it to the file named ifile */
    ifstream infile(ifile.c_str());

    string ofile = "out.txt";
    /* ofstream output file object to write file named ofile */
    ofstream outfile(ofile.c_str(), ofstream::app);
    outfile.close();

    infile.open(ifile.c_str(), ifstream::in);     /* open file in current directory */
    if (!infile)    /* check that the open succeeded */
    {
        cerr << "Error : unable to open the input file: " << ifile << endl;
        // return;
    }
    infile.close();

    fstream inOut("copyOut", fstream::in | fstream::out);   /* open for input and output */
}

void clear_file_stream_states(void)
{
    ifstream input, s;
    vector<string> files;
    vector<string>::const_iterator it = files.begin();
    /* for each file in the vector */
    while (it != files.end())
    {
        input.open(it->c_str());    /* open the file */
        /* if the file is OK, read and "process" the input */
        if (!input)
        {
            break;      /* error : bail out! */
        }
#if 0
        while (input >> s)      /* do the work on this file */
        {
            process(s);
        }
#endif
        input.close();      /* close file when we are done with it */
        input.clear();      /* reset state to OK, it is a MUST. */
        ++it;
    }
}

void access_stringstream_objects(void)
{
    string line, word;      /* will hold a line and word from input, respectively */
    while (getline(cin, line))      /* read a lien from the input into line */
    {   /* do per-line processing */
        istringstream stream(line);     /* bind to stream to the line we read */
        while (stream >> word)
        {
            /* do per-word processing */
            cout << word << endl;
        }
    }
}

void convert_format_sstream_objects(void)
{
    int val1 = 512, val2 = 0x5EFB;
    ostringstream format_message;
    /* OK : converts values to a string representation */
    format_message << "value1: " << val1 << "\n"
        << "value2: " << val2 << "\n";
    
    int field1, field2;
    /* "str" member obtains the string associated with a stringstream */
    istringstream input_istring(format_message.str());
    string dump;    /* place to dump the labels from the formatted message */
    /* extracts the stored ASCII values, converting back to arithmetic types */
    input_istring >> dump >> field1 >> dump >> field2;
    cout << "value1 = " << field1 << ", value2 = " << field2 << endl;
}

ifstream& open_file(ifstream& in, const string& file)   /* opens in binding it to the given file */
{
    in.close();     /* close in case that it was already opened */
    in.clear();     /* clear any existing errors */
    /* if the open fails, the stream will be in an invalid state */
    in.open(file.c_str());      /* open the file we were given */
    return in;      /* condition state is good if open succeeded */
}