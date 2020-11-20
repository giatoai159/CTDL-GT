#include"func.h"
#include"Queue.h"
#include"Tree.h"

int main(int argc, char * argv[])
{
	string in_name;
	string out_name;
	bool encode = true;
	bool verbose = false;

	for (int i = 1; i < argc; ++i)
	{
		if (!strcmp("-h", argv[i]) || !strcmp("--help", argv[i]))
		{
			usage_msg(argv[0]);
			exit(HELP_ERROR);
		}
		else if (!strcmp("-i", argv[i]))
		{
			cerr << "input file is '" << argv[++i] << "'" << endl;
			in_name = argv[i];
		}
		else if (!strcmp("-o", argv[i]))
		{
			cerr << "output file is '" << argv[++i] << "'" << endl;
			out_name = argv[i];
		}
		else if (!strcmp("-d", argv[i]))
		{
			encode = false;
		}
		else if (!strcmp("-e", argv[i]))
		{
			encode = true;
		}
		else if (!strcmp("-v", argv[i]))
		{
			verbose = true;
		}

	}
	if (!in_name.size() || !out_name.size())
	{
		cerr << "input and output file are required, nothing to do!" << endl;
		usage_msg(argv[0]);
		exit(HELP_ERROR);
	}

	if (encode)
	{
		cerr << "running in encoder mode" << endl;
		encoder(in_name, out_name, verbose);
	}
	else
	{
		cerr << "running in decoder mode" << endl;
		decoder(in_name, out_name, verbose);
	}
	cerr << "done .... " << endl;

	return 0;
}