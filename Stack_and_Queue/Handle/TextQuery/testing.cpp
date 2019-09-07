#include "testing.h"
#include "TextQuery.h"

#include <iostream>

using namespace std;

int executeTextQuery(int argc, char* argv[])
{
	std::ifstream infile;
	if ((argc < 2) || !open_file(infile, argv[1]))
	{
		std::cerr << "No input file!" << std::endl;
		return EXIT_FAILURE;
	}

	TextQuery tq;
	tq.read_file(infile);	/* build the query map */
	/* iterate with user:prompt for a word to find out and print the results
	 * loop indefinitely; the loop exits is inside the the while-loop
	 */
	while (true)
	{
		std::cout << "Enter word to look for, or q to quit: ";
		string s;
		cin >> s;
		if (!cin || s == "q")
			break;

		set<TextQuery::line_no> locs = tq.run_query(s);
		/* print count and all occurrences, if any */
		print_results(locs, s, tq);
	}
	return 0;
}
