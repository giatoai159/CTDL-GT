#include"func.h"

int main()
{
	int choice;
	char file_in[FILENAME_MAX], file_out[FILENAME_MAX];
	for (;;) {
		system("cls");
		cout << " ----------------------------------------- " << endl;
		cout << "|         1 - Compress txt file           |" << endl;
		cout << "|         2 - Decompress txt file         |" << endl;
		cout << "|         3 - Exit                        |" << endl;
		cout << " ----------------------------------------- " << endl;
		do 
		{
			cout << "Enter a command: ";
			cin >> choice;
		} while (isalpha(choice));

		if (choice == 3)
			exit(EXIT_SUCCESS);

		cout << "Enter input file name: "; cin >> file_in;
		cout << "Enter output file name: "; cin >> file_out;
		switch (choice) 
		{
		case 1:
			Compress(file_in, file_out); break;
		case 2:
			Decompress(file_in, file_out); break;
		}
		cout << endl;
	}
	return 0;
}
