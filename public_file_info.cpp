/* Prints old number, new number, and message of Authorship.public files.
 ______________________________________________________________________________
/                                                                              \
|  * old number: the hash or "deductive lossy compression" of the              |
|                public file's 1,008 functions residing in the left column.    |
|                                                                              |
|  * new number: the presence and absence of keys symbolize a new              |
|                number--a compression of functions not yet published.         |
|                These are keys to the first 288 functions (32 groups of 9.)   |
|                                                                              |
|  *  message:   the presence and absence of keys symbolize a new note of up   |
|                to 80 characters left by the modifying party. These are keys  |
|                to the remaining 720 functions (80 groups of 9.)              |
\______________________________________________________________________________/

WARNING: read everything I write so that logs of your circulation are futile. */

#include <fstream>
#include <iostream>
using namespace std;

int main() //                                                                                                        |
{	bool bulk_verification_efficiency = false; /* DEFAULT=FALSE ELSE NO PLAINTEXT FILES.       Octet if broken >     |
	    By default Authorship deals with files containing the standard 95 printable ASCII                            |
	    characters 32 to 126  (+13 & 10)  allowing any user to visually observe all files
	    but more so--to share  .public  files as plaintext via paste bins like stikked.ch
	    For example, the implementation generates values 0 - 94 then adds 32 upon writing
	    to file. And subtracts 32 upon reading from file.  All files are inter-compatible
	    given the bulk-verification variable is changed where needed. If true, characters
	    are not adjusted therefore  number modification verification  takes significantly
	    less time if processing bulk. All files but  Authorship.number  are affected.*/
	
	ifstream in_stream;
	
	//Gets path to file from user.
	cout << "\nDrag & drop Authorship.public file into terminal or enter path:\n\n";
	char  path_to_file[10000];
	for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';} //Fills path_to_file[] with null.
	cin.getline(path_to_file, 10000);
	if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
	
	//Fixes path to file if drag & dropped (removes single quotes for ex:)   '/home/nikolay/my documents/hush hush.bmp'
	if(path_to_file[0] == '\'')
	{	for(int a = 0; a < 10000; a++)
		{	path_to_file[a] = path_to_file[a + 1];
			if(path_to_file[a] == '\'')
			{	path_to_file[a] = '\0';
				path_to_file[a + 1] = '\0';
				path_to_file[a + 2] = '\0';
				break;
			}
		}
	}
	
	//Checks if file exists (failure can be bad path info as well.)
	in_stream.open(path_to_file);
	if(in_stream.fail() == true) {in_stream.close(); cout << "\n\nNo such file or directory.\n";             return 0;}
	char sniffed_one_file_character;
	in_stream.get(sniffed_one_file_character);
	if(in_stream.eof() == true) {in_stream.close();  cout << "\n\nNothing to process, the file is empty.\n"; return 0;}
	in_stream.close();
	
	//Loads the public functions from file Authorship.public.
	char functions[50400]; //1,008 50-character functions.
	int functions_write_bookmark = 0;
	bool b[1008] = {0}; //b for binary, logs presence and absence of keys.
	
	in_stream.open(path_to_file);
	char temp_file_byte; for(int a = 0; a < 29; a++) {in_stream.get(temp_file_byte);} //As the 29-byte headers can change, they are skipped.
	for(int a = 0; a < 1008; a++) //Grabbing 1,568 items (1,008 functions + 560 keys. Here, keys are skipped for efficiency.)
	{	//Gets function.
		for(int b = 0; b < 50; b++)
		{	in_stream.get(functions[functions_write_bookmark]);
			functions_write_bookmark++;
		}
		
		//Gets key if present.
		in_stream.get(temp_file_byte); //Checks what's after the function.
		if(temp_file_byte == ' ')
		{	b[a] = 1; //1 = key present.
			for(int c = 0; c < 1000; c++) {in_stream.get(temp_file_byte);}
			
			in_stream.get(temp_file_byte); //Skips '\r'.
			in_stream.get(temp_file_byte); //Skips '\n'.
		}
		else
		{	in_stream.get(temp_file_byte); //Skips '\n' from the "\r\n" after function.
		}
	}
	in_stream.close();
	
	//Adjusts functions[] if bulk_verification_efficiency is off (default.)
	if(bulk_verification_efficiency == false)
	{	for(int a = 0; a <  50400; a++) {functions[a] -= 32;}
	}
	
	//Generates deductive lossy compression of the 1,008 functions.
	long long deductive_lossy_compression[4]; //4 16-digit integers strung together, unique compression for each.
	long long snapshots[4];                   //Same but takes snapshots of compression, applies to compression after.
	for(int a = 0; a < 4; a++) {deductive_lossy_compression[a] = 5555555555555555; snapshots[a] = 5555555555555555;}
	
	for(int a = 0; a < 4; a++)
	{	for(int b = 0; b < 50400; b++)
		{	deductive_lossy_compression[a] += functions[b];
			deductive_lossy_compression[a] *= (a + 2);
			deductive_lossy_compression[a] %= 10000000000000000;
			
			//Takes snapshots of the compression as it evolves over time.
			if((b == 10000) || (b == 20000) || (b == 30000) || (b == 40000))
			{	snapshots[a] += deductive_lossy_compression[a];
				snapshots[a] %= 10000000000000000;
			}
		}
		
		//Applies snapshots to last stage of compression per integer.
		deductive_lossy_compression[a] += snapshots[a];
		deductive_lossy_compression[a] %= 10000000000000000;
		
		//Ensures all 4 compression integers are 16 digits long.
		if(deductive_lossy_compression[a] < 1000000000000000) {deductive_lossy_compression[a] += 1000000000000000;}
	}
	
	//Converts deductive_lossy_compression[] to 32 characters (1 char for every two contiguous digits.)
	unsigned char number[32];
	int  number_write_bookmark = 0;
	
	for(int a = 0; a < 4; a++)
	{	number[number_write_bookmark] =  (deductive_lossy_compression[a] / 100000000000000);        number_write_bookmark++;
		number[number_write_bookmark] = ((deductive_lossy_compression[a] /   1000000000000) % 100); number_write_bookmark++;
		number[number_write_bookmark] = ((deductive_lossy_compression[a] /     10000000000) % 100); number_write_bookmark++;
		number[number_write_bookmark] = ((deductive_lossy_compression[a] /       100000000) % 100); number_write_bookmark++;
		number[number_write_bookmark] = ((deductive_lossy_compression[a] /         1000000) % 100); number_write_bookmark++;
		number[number_write_bookmark] = ((deductive_lossy_compression[a] /           10000) % 100); number_write_bookmark++;
		number[number_write_bookmark] = ((deductive_lossy_compression[a] /             100) % 100); number_write_bookmark++;
		number[number_write_bookmark] =  (deductive_lossy_compression[a]                    % 100); number_write_bookmark++;
	}
	
	//Applies snapshots to the last character of the number.
	for(int a = 0; a < 4; a++) {number[31] += (snapshots[a] % 100); number[31] %= 100;}
	
	//Fixes number, it is now complete.
	//Collisions via brute-force is futile; inputs are well-tested for additional properties therefore 32 char
	//is over-kill indeed. 94^32 = 1380674536088650126365233338290905239051505147118049339937652736 or ~10^64.
	for(int a = 0; a < 32; a++)
	{	if(number[a] == 0) {number[a]++;}     //Ensures no spaces.
		if(number[a] > 94) {number[a] -= 94;} //Ensures no values > 94.
	}
	
	//Prints the old number (compression of these released public functions).
	cout << "\n\n\nOld Number: "; for(int a = 0; a < 32; a++) {cout << (char(number[a] + 32));}
	
	//Extracts the new number and user message based on the symbolism of key presence and absence. First if = no_char.
	//This step in its nature simultaneously checks that there are strictly 5 keys for every group of 9 contiguous functions.
	char cat[112]; //Concatenation of 32-character number and 80-character message.
	int m = 0; //m for read_bookMark for b[].
	for(int a = 0; a < 112; a++)
	{	
		//              1              2              3              4              5              6              7              8              9          Extracted
		//              |              |              |              |              |              |              |              |              |          character
		     if((b[m]== 1 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]='\0';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= ' ';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '!';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '"';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '#';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '$';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '%';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '&';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]='\'';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '(';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= ')';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '*';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '+';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= ',';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '-';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '.';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '/';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '0';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '1';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '2';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '3';}
		else if((b[m]== 0 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= '4';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '5';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '6';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '7';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '8';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '9';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= ':';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= ';';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '<';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '=';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '>';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '?';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '@';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'A';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'B';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'C';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'D';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'E';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'F';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'G';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'H';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'I';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'J';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'K';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'L';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'M';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'N';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'O';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'P';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'Q';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'R';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'S';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'T';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'U';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'V';}
		else if((b[m]== 0 )&&(b[m+1]== 1 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'W';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'X';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'Y';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'Z';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '[';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]='\\';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= ']';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '^';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '_';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '`';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'a';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'b';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'c';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'd';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'e';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 0 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'f';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'g';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'h';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'i';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'j';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'k';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'l';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'm';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'n';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'o';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 0 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'p';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= 'q';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'r';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 's';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 't';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'u';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'v';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= 'w';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= 'x';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'y';}
		else if((b[m]== 1 )&&(b[m+1]== 0 )&&(b[m+2]== 1 )&&(b[m+3]== 1 )&&(b[m+4]== 1 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 0 )&&(b[m+8]== 0 )) {cat[a]= 'z';}
		else if((b[m]== 1 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 0 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '{';}
		else if((b[m]== 1 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 0 )&&(b[m+7]== 1 )&&(b[m+8]== 1 )) {cat[a]= '|';}
		else if((b[m]== 1 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 0 )&&(b[m+8]== 1 )) {cat[a]= '}';}
		else if((b[m]== 1 )&&(b[m+1]== 1 )&&(b[m+2]== 0 )&&(b[m+3]== 0 )&&(b[m+4]== 0 )&&(b[m+5]== 1 )&&(b[m+6]== 1 )&&(b[m+7]== 1 )&&(b[m+8]== 0 )) {cat[a]= '~';}
		//              |              |              |              |              |              |              |              |              |
		//              1              2              3              4              5              6              7              8              9
		
		else {cout << "\nFailed! Symbolism not corresponding to assignment.\n"; return 0;}
		
		m += 9;
	}
	
	//Prints the new number of the modifying party. Verifying parties overwrite this user's old number with this one.
	cout << "\n\nNew number: "; for(int a = 0; a < 32; a++) {cout << char(cat[a]);}
	
	//Prints user's message if present for this event.
	if(cat[32] != '\0') //If 33rd item in cat[] is not no_char.
	{	cout << "\n\nThe user included a message for this authentication event: \n\n";
		
		for(int a = 32; a < 112; a++) {cout << char(cat[a]);}
		cout << "\n";
	}
	else {cout << "\n\nThe user omitted a message for this authentication event.\n";}
}
