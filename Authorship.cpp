/// Authorship - get a number only you can modify--which anyone                 Run it: "apt install g++ geany". Open this in Geany. Hit F9 once. F5 to run.
///              can verify (infinite data authentication
///              independent of encryption type or symmetry.)


// Version 8.0.0   +   rolling-code 3.1.0

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	cout << "\n(1) Create   Your number which others save."
	     << "\n(2) Modify   Your Personal folder renewed makes public file which others verify."
	     << "\n(3) Verify   Their new public file modifies their number file which you saved."
	
	     << "\n\nOption: ";
	
	int user_option; cin >> user_option;
	if((user_option != 1) && (user_option != 2) && (user_option != 3)) {cout << "\nInvalid.\n"; return 0;}
	
	
	
	
	
	//_______________________________________________________Create___________________________________________________//
	if(user_option == 1)
	{	
		/* SUMMARY
		-------------
		* 512 keys.
		* 512 ciphertext using keys.
		* sha512sum of ciphertext list (your number.)
		* (RAM of sensitive data overwritten.) */
		
		//Checks if files already exists.
		in_stream.open("Personal");
		if(in_stream.fail() == false) {cout << "\n\"Personal\" already exists. Move it.\n"; in_stream.close(); return 0;}
		in_stream.close();
		
		//Generates 512 keys--each 1,000 digits.
		//The following verbatim from rolling-code.cpp, except user knobs, cout, renamed "RC_seeds", renamed "Code", extraction, out_stream, comments, absurd, mkdir.
		{	long long code_length_in_thousands = 512;
			bool RAM_Unix_time_supplement = true; //Set to true for codes of unique randomness, even with the same seeds file. DEFAULT = true.
			
			//Creates seeds file if missing.
			const char seeds_file_name[50] = {"Personal/private/AS_seeds"};
			char garbage_byte_for_seeds_file;
			{	//..........Checks if seeds file exists.
				in_stream.open(seeds_file_name);
				bool existence_of_seeds_file = true;
				if(in_stream.fail() == true) {existence_of_seeds_file = false;}
				in_stream.close();
				
				if(existence_of_seeds_file == false)
				{	//..........Gets path to file from user.
					cout << "Just once, drop/enter any file"
					     << "\nof 1,000+ random first bytes:\n";
					
					//..........Gets path then fixes it if drag-n-dropped, regardless of single-quote presence and "enter"
					//..........not being cleared, meaning you can have options before this, where the user presses enter.
					char path_to_file_for_seeds[10000] = {'\0'};
					{	for(int a = 0; a < 10000; a++) {path_to_file_for_seeds[a] = '\0';}
						cin.getline(path_to_file_for_seeds, 10000);
						if(path_to_file_for_seeds[0] == '\0')
						{	for(int a = 0; a < 10000; a++) {path_to_file_for_seeds[a] = '\0';}
							cin.getline(path_to_file_for_seeds, 10000);
						}
						if(path_to_file_for_seeds[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
						
						//..........Removes last space in path_to_file_for_seeds[].
						bool existence_of_last_space = false;
						for(int a = 9999; a > 0; a--)
						{	if(path_to_file_for_seeds[a] != '\0')
							{	if(path_to_file_for_seeds[a] == ' ') {path_to_file_for_seeds[a] = '\0'; existence_of_last_space = true;}
								break;
							}
						}
						
						//..........Removes encapsulating single-quotes in path_to_file_for_seeds[].
						bool existence_of_encapsulating_single_quotes = false;
						if(path_to_file_for_seeds[0] == '\'')
						{	for(int a = 0; a < 9999; a++)
							{	path_to_file_for_seeds[a] = path_to_file_for_seeds[a + 1];
								if(path_to_file_for_seeds[a] == '\0') 
								{	if(path_to_file_for_seeds[a - 1] != '\'') {cout << "\nBad path.\n"; return 0;}
									path_to_file_for_seeds[a - 1] = '\0';
									existence_of_encapsulating_single_quotes = true;
									break;
								}
							}
						}
						
						//..........Replaces all "'\''" with "'" in path_to_file_for_seeds[].
						int single_quote_quantity = 0;
						for(int a = 0; a < 10000; a++)
						{	if(path_to_file_for_seeds[a] == '\'') {single_quote_quantity++;}
						}
						
						if((single_quote_quantity                     >    0)
						&& (existence_of_last_space                  == true)
						&& (existence_of_encapsulating_single_quotes == true))
						{	if((single_quote_quantity % 3) != 0) {cout << "\nBad path.\n"; return 0;}
							
							for(int a = 0; a < 9997; a++)
							{	if(path_to_file_for_seeds[a] == '\'')
								{	int temp = (a + 1);
									for(; temp < 9997; temp++)
									{	path_to_file_for_seeds[temp] = path_to_file_for_seeds[temp + 3];
									}
								}
							}
						}
					}
					
					//..........Loads seeds[] with given file's 1,000 Bytes.
					in_stream.open(path_to_file_for_seeds);
					if(in_stream.fail() == true) {cout << "\nNo such file.\n"; in_stream.close(); return 0;}
					unsigned int seeds[1000];
					for(int a = 0; a < 1000; a++)
					{	in_stream.get(garbage_byte_for_seeds_file);
						if(in_stream.eof() == true)
						{	for(int b = 0; b < 1000; b++) {seeds[b] = 0; seeds[b] = 4294967295;} //..........Overwrites RAM of array unsigned int seeds[1000].
							cout << "\n\nFile too small.\n\n"; in_stream.close(); return 0;
						}
						
						int normal_byte = garbage_byte_for_seeds_file;
						if(normal_byte < 0) {normal_byte += 256;}
						seeds[a] = normal_byte;
					}
					in_stream.close();
					
					system("mkdir Personal"        );
					system("mkdir Personal/private");
					
					//..........Creates seeds file (digits, and better distributed.)
					out_stream.open(seeds_file_name);
					srand(seeds[0]);
					for(int a = 0; a < 1000; a++)
					{	long long temp = ((seeds[a] + rand()) % 10);
						out_stream << char(temp + 48);
					}
					out_stream.close();
					
					//..........Overwrites RAM of array unsigned int seeds[1000].
					for(int a = 0; a < 1000; a++) {seeds[a] = 0; seeds[a] = 4294967295;}
				}
			}
			
			//Generates randomness.
			{	long long temp_overflow_for_randomness;
				
				//..........Loads seeds[] with seeds file.
				in_stream.open(seeds_file_name);
				unsigned int seeds[1000];
				for(int a = 0; a < 1000; a++)
				{	in_stream.get(garbage_byte_for_seeds_file);
					int normal_byte = garbage_byte_for_seeds_file;
					if(normal_byte < 0) {normal_byte += 256;}
					seeds[a] = normal_byte;
					
					seeds[a] -= 48;
					if((in_stream.eof() == true) || (seeds[a] > 9))
					{	for(int b = 0; b < 1000; b++) {seeds[b] = 0; seeds[b] = 4294967295;} //..........Overwrites RAM of array unsigned int seeds[1000].
						cout << "\n\nBad seeds file.\n\n"; in_stream.close(); return 0;
					}
				}
				in_stream.close();
				
				//..........Makes 100 10-digit actual seeds based on seeds[]. (Strings together 10 contiguous digits, 100 times.)
				unsigned int actual_seeds[100] = {0};
				int seeds_read_bookmark = 0;
				for(int a = 0; a < 100; a++)
				{	temp_overflow_for_randomness = 0;
					for(int b = 0; b < 10; b++)
					{	temp_overflow_for_randomness += seeds[seeds_read_bookmark];
						if(b < 9) {temp_overflow_for_randomness *= 10;}
						seeds_read_bookmark++;
					}
					
					actual_seeds[a] = (temp_overflow_for_randomness % 4294967296);
				}
				
				/*..........Supplements actual_seeds[] for unique randomness. (100 10-digit values
				            created from garbage RAM are added to the 100 10-digit actual_seeds[].)
				            Even if all zeros as supplement, actual_seeds[] take the weight (seeds file.)
				            Declare 100k or 1M unsigned int array; there will be ~628 garbage items at end.*/
				if(RAM_Unix_time_supplement == true)
				{	unsigned int RAM_garbage[100000];
					temp_overflow_for_randomness = (time(0) % 4294967296); //..........Adds Unix time to actual_seeds[0]. (temp_overflow_for_randomness is never reset; each actual_seed[] is supplemented with incremental, and unique.)
					
					for(int a = 0; a < 100; a++) //..........Adds sum of every RAM_garbage[] to actual_seeds[0], then sum of every other to actual_seeds[1], then sum of every third to actual_seeds[2], and so on.
					{	int skip = (a + 1);
						for(int b = 0; b < 100000; b += skip) {temp_overflow_for_randomness += RAM_garbage[b]; temp_overflow_for_randomness %= 4294967296;}
						
						temp_overflow_for_randomness += actual_seeds[a];
						actual_seeds[a] = (temp_overflow_for_randomness % 4294967296);
					}
					
					for(int a = 0; a < 100000; a++) {RAM_garbage[a] = 0; RAM_garbage[a] = 4294967295;} //..........Overwrites RAM of array unsigned int RAM_garbage[100000].
				}
				
				//..........Generator house.
				out_stream.open("Personal/private/512_keys", ios::app);
				unsigned int randomness[1000] = {0};
				for(long long a = 0; a < code_length_in_thousands; a++)
				{	
					//..........Generator powerhouse.
					for(int b = 0; b < 100; b++)
					{	srand(actual_seeds[b]);
						for(int c = 0; c < 1000; c++) {randomness[c] += rand(); randomness[c] %= 256;} //..........Fills randomness[] (100x per 1,000-char code.)
						temp_overflow_for_randomness = (actual_seeds[99 - b] + rand()); //..........Modifies inverse actual_seeds[].
						actual_seeds[99 - b] = (temp_overflow_for_randomness % 4294967296);
						
						srand(actual_seeds[99 - b]);  //..........Now using that inverse seed.
						for(int c = 0; c < 1000; c++) //..........Swaps EACH & EVERY element in randomness[] with randomly chosen (100,000x per 1,000-char code.)
						{	int random_element = (rand() % 1000);
							for(; random_element == c;) {random_element = (rand() % 1000);}
							
							unsigned int temp_element = randomness[random_element];
							randomness[random_element] = randomness[c];
							randomness[c] = temp_element;
						}
						temp_overflow_for_randomness = (actual_seeds[b] + rand()); //..........Modifies current actual_seeds[].
						actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
					}
					
					//..........Makes 100 10-digit new actual seeds based on randomness[]. (!!! Adds to current actual_seeds. !!! The generated Code is NOT alone responsible for new actual_seeds. !!!) (Strings together 10 contiguous digits, 100 times.)
					int randomness_read_bookmark = 0;
					for(int b = 0; b < 100; b++)
					{	temp_overflow_for_randomness = 0;
						for(int c = 0; c < 10; c++)
						{	temp_overflow_for_randomness += (randomness[randomness_read_bookmark] % 10);
							if(c < 9) {temp_overflow_for_randomness *= 10;}
							randomness_read_bookmark++;
						}
						
						temp_overflow_for_randomness += actual_seeds[b];
						actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
					}
					
					for(int b = 0; b < 1000; b++) {out_stream << char((randomness[b] % 10) + 48);}
				}
				out_stream.close();
				
				//..........Overwrites seeds file.
				out_stream.open(seeds_file_name);
				for(int a = 0; a < 100; a++)
				{	unsigned int place = 10;
					for(int b = 0; b < 9; b++)
					{	if(actual_seeds[a] < place) {out_stream << "0";}
						place *= 10;
					}
					out_stream << actual_seeds[a];
				}
				out_stream << "\n\nSeeds are always supplemented with RAM garbage and Unix time.\n";
				out_stream.close();
				
				//..........Overwrites RAM of variable long long temp_overflow_for_randomness.
				temp_overflow_for_randomness = 0; temp_overflow_for_randomness = -9223372036854775807; temp_overflow_for_randomness = 9223372036854775807;
				
				//..........Overwrites RAM of arrays unsigned int seeds[1000] and unsigned int randomness[1000].
				for(int a = 0; a < 1000; a++) {seeds[a] = 0; seeds[a] = 4294967295; randomness[a] = 0; randomness[a] = 4294967295;}
				
				//..........Overwrites RAM of array unsigned int actual_seeds[100].
				for(int a = 0; a < 100; a++) {actual_seeds[a] = 0; actual_seeds[a] = 4294967295;}
			}
		}
		
		//Generates 512 ciphertext--each 1,000 characters (33 to 126; no space.) - From those 512 keys made above.
		//The following is components from rolling-code.cpp.
		in_stream.open("Personal/private/512_keys");
		out_stream.open("Personal/private/512_ciphertext");
		for(int loop = 0; loop < 512; loop++)
		{	long long temp_overflow_for_randomness;
			char garbage_byte_for_seeds_file;
			
			//..........Loads seeds[] with 1 key at-a-time.
			unsigned int seeds[1000];
			for(int a = 0; a < 1000; a++)
			{	in_stream.get(garbage_byte_for_seeds_file);
				int normal_byte = garbage_byte_for_seeds_file;
				if(normal_byte < 0) {normal_byte += 256;}
				seeds[a] = normal_byte;
				
				seeds[a] -= 48;
				if((in_stream.eof() == true) || (seeds[a] > 9))
				{	for(int b = 0; b < 1000; b++) {seeds[b] = 0; seeds[b] = 4294967295;} //..........Overwrites RAM of array unsigned int seeds[1000].
					cout << "\n\nBad keys.\n\n"; in_stream.close(); out_stream.close(); return 0;
				}
			}
			
			//..........Makes 100 10-digit actual seeds based on seeds[]. (Strings together 10 contiguous digits, 100 times.)
			unsigned int actual_seeds[100] = {0};
			int seeds_read_bookmark = 0;
			for(int a = 0; a < 100; a++)
			{	temp_overflow_for_randomness = 0;
				for(int b = 0; b < 10; b++)
				{	temp_overflow_for_randomness += seeds[seeds_read_bookmark];
					if(b < 9) {temp_overflow_for_randomness *= 10;}
					seeds_read_bookmark++;
				}
				
				actual_seeds[a] = (temp_overflow_for_randomness % 4294967296);
			}
			
			//..........Generator powerhouse.
			unsigned int randomness[1000] = {0};
			for(int b = 0; b < 100; b++)
			{	srand(actual_seeds[b]);
				for(int c = 0; c < 1000; c++) {randomness[c] += rand(); randomness[c] %= 256;} //..........Fills randomness[] (100x per 1,000-char code.)
				temp_overflow_for_randomness = (actual_seeds[99 - b] + rand()); //..........Modifies inverse actual_seeds[].
				actual_seeds[99 - b] = (temp_overflow_for_randomness % 4294967296);
				
				srand(actual_seeds[99 - b]);  //..........Now using that inverse seed.
				for(int c = 0; c < 1000; c++) //..........Swaps EACH & EVERY element in randomness[] with randomly chosen (100,000x per 1,000-char code.)
				{	int random_element = (rand() % 1000);
					for(; random_element == c;) {random_element = (rand() % 1000);}
					
					unsigned int temp_element = randomness[random_element];
					randomness[random_element] = randomness[c];
					randomness[c] = temp_element;
				}
				temp_overflow_for_randomness = (actual_seeds[b] + rand()); //..........Modifies current actual_seeds[].
				actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
			}
			
			for(int b = 0; b < 1000; b++) {out_stream << char((randomness[b] % 94) + 33);}
			
			if(loop == 511)
			{	//..........Overwrites RAM of variable long long temp_overflow_for_randomness.
				temp_overflow_for_randomness = 0; temp_overflow_for_randomness = -9223372036854775807; temp_overflow_for_randomness = 9223372036854775807;
				
				//..........Overwrites RAM of arrays unsigned int seeds[1000] and unsigned int randomness[1000].
				for(int a = 0; a < 1000; a++) {seeds[a] = 0; seeds[a] = 4294967295; randomness[a] = 0; randomness[a] = 4294967295;}
				
				//..........Overwrites RAM of array unsigned int actual_seeds[100].
				for(int a = 0; a < 100; a++) {actual_seeds[a] = 0; actual_seeds[a] = 4294967295;}
			}
		}
		in_stream.close();
		out_stream.close();
		
		//Takes the sha512sum hash of file "ciphertext".
		system("echo -n \"$(sha512sum Personal/private/512_ciphertext | cut -d \' \' -f 1)\" > Personal/number"); //..........Extra commands for omitting dir, \n.
		
		cout << "\nYour \"Personal\" folder is ready. Publish your number.\n\n\n";
	}
	
	
	
	
	
	//_______________________________________________________Modify___________________________________________________//
	if(user_option == 2)
	{	
		/* SUMMARY
		-------------
		* Prompts user for message to be authenticated with event.
		* Copies ciphertext to new file "public".
		* Loads old keys to RAM.
		* New keys.
		* New ciphertext.
		* sha512sum of new ciphertext list (your new number.)
		* Writes user message to new file "representing_sha512sum_of".
		* Appends new number to file "representing_sha512sum_of".
		* Keeps appending 0s to file "representing_sha512sum_of" until its sha512sum hash is composed of 256 1 bits and 256 0 bits. (16 tries on average.)
		* Appends only 256 old keys to file "public" (based on bits from hash in file "the_sha512sum".)
		* Appends presence & absence indication to file "public".
		* Appends user message and new number to file "public" (all from file "representing_sha512sum_of".)
		* (RAM of sensitive data overwritten.) */
		
		//Gets path then fixes it if drag-n-dropped, regardless of single-quote presence and "enter"
		//not being cleared, meaning you can have options before this, where the user presses enter.
		cout << "Drop/enter personal folder:\n";
		char path_to_file[10000] = {'\0'};
		{	for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';}
			cin.getline(path_to_file, 10000);
			if(path_to_file[0] == '\0')
			{	for(int a = 0; a < 10000; a++) {path_to_file[a] = '\0';}
				cin.getline(path_to_file, 10000);
			}
			if(path_to_file[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
			
			//..........Removes last space in path_to_file[].
			bool existence_of_last_space = false;
			for(int a = 9999; a > 0; a--)
			{	if(path_to_file[a] != '\0')
				{	if(path_to_file[a] == ' ') {path_to_file[a] = '\0'; existence_of_last_space = true;}
					break;
				}
			}
			
			//..........Removes encapsulating single-quotes in path_to_file[].
			bool existence_of_encapsulating_single_quotes = false;
			if(path_to_file[0] == '\'')
			{	for(int a = 0; a < 9999; a++)
				{	path_to_file[a] = path_to_file[a + 1];
					if(path_to_file[a] == '\0') 
					{	if(path_to_file[a - 1] != '\'') {cout << "\nBad path.\n"; return 0;}
						path_to_file[a - 1] = '\0';
						existence_of_encapsulating_single_quotes = true;
						break;
					}
				}
			}
			
			//..........Replaces all "'\''" with "'" in path_to_file[].
			int single_quote_quantity = 0;
			for(int a = 0; a < 10000; a++)
			{	if(path_to_file[a] == '\'') {single_quote_quantity++;}
			}
			
			if((single_quote_quantity                     >    0)
			&& (existence_of_last_space                  == true)
			&& (existence_of_encapsulating_single_quotes == true))
			{	if((single_quote_quantity % 3) != 0) {cout << "\nBad path.\n"; return 0;}
				
				for(int a = 0; a < 9997; a++)
				{	if(path_to_file[a] == '\'')
					{	int temp = (a + 1);
						for(; temp < 9997; temp++)
						{	path_to_file[temp] = path_to_file[temp + 3];
						}
					}
				}
			}
			
			in_stream.open(path_to_file);
			if(in_stream.fail() == true) {cout << "\nNo such file or directory.\n"; in_stream.close(); return 0;}
			in_stream.close();
		}
		
		//Gets location of the first encountered end-null coming from the left in path_to_file[].
		int path_to_file_null_bookmark;
		for(int a = 0; a < 10000; a++) {if(path_to_file[a] == '\0') {path_to_file_null_bookmark = a; break;}}
		
		//Creates path to keys, ciphertext, AS_seeds, public, number, representing_sha512sum_of, and the_sha512sum.
		char path_to_keys                     [10000] = {'\0'};
		char path_to_ciphertext               [10000] = {'\0'};
		char path_to_AS_seeds                 [10000] = {'\0'};
		char path_to_public                   [10000] = {'\0'};
		char path_to_number                   [10000] = {'\0'};
		char path_to_representing_sha512sum_of[10000] = {'\0'};
		char path_to_the_sha512sum            [10000] = {'\0'};
		for(int a = 0; a < 10000; a++)
		{	path_to_keys                     [a] = path_to_file[a];
			path_to_ciphertext               [a] = path_to_file[a];
			path_to_AS_seeds                 [a] = path_to_file[a];
			path_to_public                   [a] = path_to_file[a];
			path_to_number                   [a] = path_to_file[a];
			path_to_representing_sha512sum_of[a] = path_to_file[a];
			path_to_the_sha512sum            [a] = path_to_file[a];
		}
		
		char temp_name_keys                     [100] = "/private/512_keys"                 ;
		char temp_name_ciphertext               [100] = "/private/512_ciphertext"           ;
		char temp_name_AS_seeds                 [100] = "/private/AS_seeds"                 ;
		char temp_name_public                   [100] = "/public"                           ;
		char temp_name_number                   [100] = "/number"                           ;
		char temp_name_representing_sha512sum_of[100] = "/private/representing_sha512sum_of";
		char temp_name_the_sha512sum            [100] = "/private/the_sha512sum"            ;
		
		for(int null = path_to_file_null_bookmark, a = 0; temp_name_keys                     [a] != '\0'; a++) {path_to_keys                     [null] = temp_name_keys                     [a]; null++;}
		for(int null = path_to_file_null_bookmark, a = 0; temp_name_ciphertext               [a] != '\0'; a++) {path_to_ciphertext               [null] = temp_name_ciphertext               [a]; null++;}
		for(int null = path_to_file_null_bookmark, a = 0; temp_name_AS_seeds                 [a] != '\0'; a++) {path_to_AS_seeds                 [null] = temp_name_AS_seeds                 [a]; null++;}
		for(int null = path_to_file_null_bookmark, a = 0; temp_name_public                   [a] != '\0'; a++) {path_to_public                   [null] = temp_name_public                   [a]; null++;}
		for(int null = path_to_file_null_bookmark, a = 0; temp_name_number                   [a] != '\0'; a++) {path_to_number                   [null] = temp_name_number                   [a]; null++;}
		for(int null = path_to_file_null_bookmark, a = 0; temp_name_representing_sha512sum_of[a] != '\0'; a++) {path_to_representing_sha512sum_of[null] = temp_name_representing_sha512sum_of[a]; null++;}
		for(int null = path_to_file_null_bookmark, a = 0; temp_name_the_sha512sum            [a] != '\0'; a++) {path_to_the_sha512sum            [null] = temp_name_the_sha512sum            [a]; null++;}
		
		//Checks if files exist.
		bool existence = true;
		in_stream.open(path_to_keys      ); if(in_stream.fail() == true) {cout << "\n\"512_keys\" missing."      ; existence = false;} in_stream.close();
		in_stream.open(path_to_ciphertext); if(in_stream.fail() == true) {cout << "\n\"512_ciphertext\" missing."; existence = false;} in_stream.close();
		in_stream.open(path_to_AS_seeds  ); if(in_stream.fail() == true) {cout << "\n\"AS_seeds\" missing."      ; existence = false;} in_stream.close();
		if(existence == false) {return 0;}
		
		//Checks if files are empty.
		char garbage_byte;
		bool substance = true;
		in_stream.open(path_to_keys      ); in_stream.get(garbage_byte); if(in_stream.eof() == true) {cout << "\n\"512_keys\" empty."      ; substance = false;} in_stream.close();
		in_stream.open(path_to_ciphertext); in_stream.get(garbage_byte); if(in_stream.eof() == true) {cout << "\n\"512_ciphertext\" empty."; substance = false;} in_stream.close();
		in_stream.open(path_to_AS_seeds  ); in_stream.get(garbage_byte); if(in_stream.eof() == true) {cout << "\n\"AS_seeds\" empty."      ; substance = false;} in_stream.close();
		if(substance == false) {return 0;}
		
		//Checks that files have the right substance.
		bool right_substance = true;
		in_stream.open(path_to_keys      ); for(int a = 0; a < 512000; a++) {in_stream.get(garbage_byte); if((garbage_byte < 48) || (garbage_byte >  57)) {cout << "\n\"512_keys\" corrupted."      ; right_substance = false; break;}} in_stream.close();
		in_stream.open(path_to_ciphertext); for(int a = 0; a < 512000; a++) {in_stream.get(garbage_byte); if((garbage_byte < 33) || (garbage_byte > 126)) {cout << "\n\"512_ciphertext\" corrupted."; right_substance = false; break;}} in_stream.close();
		in_stream.open(path_to_AS_seeds  ); for(int a = 0; a <   1000; a++) {in_stream.get(garbage_byte); if((garbage_byte < 48) || (garbage_byte >  57)) {cout << "\n\"AS_seeds\" corrupted."      ; right_substance = false; break;}} in_stream.close();
		if(right_substance == false) {return 0;}
		
		//Prompts user for message to be authenticated with event.
		cout << "Enter message to be authenticated (9k char max) else press enter:\n";
		char message[10000] = {'\0'};
		cin.getline(message, 10000);
		message[9000] = '\0';
		bool existence_of_message = false;
		if(message[0] != '\0') {existence_of_message = true;}
		
		//Copies ciphertext to new file "public".
		in_stream.open (path_to_ciphertext);
		out_stream.open(path_to_public    );
		for(int a = 0; a < 512000; a++) {in_stream.get(garbage_byte); out_stream.put(garbage_byte);}
		in_stream.close();
		out_stream.close();
		
		//Loads old keys to RAM.
		char old_keys[512000];
		in_stream.open(path_to_keys);
		for(int a = 0; a < 512000; a++) {in_stream.get(old_keys[a]);}
		in_stream.close();
		
		//New keys just as option 1, except paths, no seeds file creation.
		
		//Overwrites "512_keys" with new keys.
		//The following verbatim from rolling-code.cpp, except user knobs, cout, renamed "RC_seeds", renamed "Code", extraction, out_stream, comments, absurd, mkdir.
		//Generates randomness.
		{	long long code_length_in_thousands = 512;
			bool RAM_Unix_time_supplement = true; //Set to true for codes of unique randomness, even with the same seeds file. DEFAULT = true.
			char garbage_byte_for_seeds_file;
			long long temp_overflow_for_randomness;
			
			//..........Loads seeds[] with seeds file.
			in_stream.open(path_to_AS_seeds);
			unsigned int seeds[1000];
			for(int a = 0; a < 1000; a++)
			{	in_stream.get(garbage_byte_for_seeds_file);
				int normal_byte = garbage_byte_for_seeds_file;
				if(normal_byte < 0) {normal_byte += 256;}
				seeds[a] = normal_byte;
				
				seeds[a] -= 48;
				if((in_stream.eof() == true) || (seeds[a] > 9))
				{	for(int b = 0; b < 1000; b++) {seeds[b] = 0; seeds[b] = 4294967295;} //..........Overwrites RAM of array unsigned int seeds[1000].
					cout << "\n\nBad seeds file.\n\n"; in_stream.close(); return 0;
				}
			}
			in_stream.close();
			
			//..........Makes 100 10-digit actual seeds based on seeds[]. (Strings together 10 contiguous digits, 100 times.)
			unsigned int actual_seeds[100] = {0};
			int seeds_read_bookmark = 0;
			for(int a = 0; a < 100; a++)
			{	temp_overflow_for_randomness = 0;
				for(int b = 0; b < 10; b++)
				{	temp_overflow_for_randomness += seeds[seeds_read_bookmark];
					if(b < 9) {temp_overflow_for_randomness *= 10;}
					seeds_read_bookmark++;
				}
				
				actual_seeds[a] = (temp_overflow_for_randomness % 4294967296);
			}
			
			/*..........Supplements actual_seeds[] for unique randomness. (100 10-digit values
			            created from garbage RAM are added to the 100 10-digit actual_seeds[].)
			            Even if all zeros as supplement, actual_seeds[] take the weight (seeds file.)
			            Declare 100k or 1M unsigned int array; there will be ~628 garbage items at end.*/
			if(RAM_Unix_time_supplement == true)
			{	unsigned int RAM_garbage[100000];
				temp_overflow_for_randomness = (time(0) % 4294967296); //..........Adds Unix time to actual_seeds[0]. (temp_overflow_for_randomness is never reset; each actual_seed[] is supplemented with incremental, and unique.)
				
				for(int a = 0; a < 100; a++) //..........Adds sum of every RAM_garbage[] to actual_seeds[0], then sum of every other to actual_seeds[1], then sum of every third to actual_seeds[2], and so on.
				{	int skip = (a + 1);
					for(int b = 0; b < 100000; b += skip) {temp_overflow_for_randomness += RAM_garbage[b]; temp_overflow_for_randomness %= 4294967296;}
					
					temp_overflow_for_randomness += actual_seeds[a];
					actual_seeds[a] = (temp_overflow_for_randomness % 4294967296);
				}
				
				for(int a = 0; a < 100000; a++) {RAM_garbage[a] = 0; RAM_garbage[a] = 4294967295;} //..........Overwrites RAM of array unsigned int RAM_garbage[100000].
			}
			
			//..........Generator house.
			out_stream.open(path_to_keys);
			unsigned int randomness[1000] = {0};
			for(long long a = 0; a < code_length_in_thousands; a++)
			{	
				//..........Generator powerhouse.
				for(int b = 0; b < 100; b++)
				{	srand(actual_seeds[b]);
					for(int c = 0; c < 1000; c++) {randomness[c] += rand(); randomness[c] %= 256;} //..........Fills randomness[] (100x per 1,000-char code.)
					temp_overflow_for_randomness = (actual_seeds[99 - b] + rand()); //..........Modifies inverse actual_seeds[].
					actual_seeds[99 - b] = (temp_overflow_for_randomness % 4294967296);
					
					srand(actual_seeds[99 - b]);  //..........Now using that inverse seed.
					for(int c = 0; c < 1000; c++) //..........Swaps EACH & EVERY element in randomness[] with randomly chosen (100,000x per 1,000-char code.)
					{	int random_element = (rand() % 1000);
						for(; random_element == c;) {random_element = (rand() % 1000);}
						
						unsigned int temp_element = randomness[random_element];
						randomness[random_element] = randomness[c];
						randomness[c] = temp_element;
					}
					temp_overflow_for_randomness = (actual_seeds[b] + rand()); //..........Modifies current actual_seeds[].
					actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
				}
				
				//..........Makes 100 10-digit new actual seeds based on randomness[]. (!!! Adds to current actual_seeds. !!! The generated Code is NOT alone responsible for new actual_seeds. !!!) (Strings together 10 contiguous digits, 100 times.)
				int randomness_read_bookmark = 0;
				for(int b = 0; b < 100; b++)
				{	temp_overflow_for_randomness = 0;
					for(int c = 0; c < 10; c++)
					{	temp_overflow_for_randomness += (randomness[randomness_read_bookmark] % 10);
						if(c < 9) {temp_overflow_for_randomness *= 10;}
						randomness_read_bookmark++;
					}
					
					temp_overflow_for_randomness += actual_seeds[b];
					actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
				}
				
				for(int b = 0; b < 1000; b++) {out_stream << char((randomness[b] % 10) + 48);}
			}
			out_stream.close();
			
			//..........Overwrites seeds file.
			out_stream.open(path_to_AS_seeds);
			for(int a = 0; a < 100; a++)
			{	unsigned int place = 10;
				for(int b = 0; b < 9; b++)
				{	if(actual_seeds[a] < place) {out_stream << "0";}
					place *= 10;
				}
				out_stream << actual_seeds[a];
			}
			out_stream << "\n\nSeeds are always supplemented with RAM garbage and Unix time.\n";
			out_stream.close();
			
			//..........Overwrites RAM of variable long long temp_overflow_for_randomness.
			temp_overflow_for_randomness = 0; temp_overflow_for_randomness = -9223372036854775807; temp_overflow_for_randomness = 9223372036854775807;
			
			//..........Overwrites RAM of arrays unsigned int seeds[1000] and unsigned int randomness[1000].
			for(int a = 0; a < 1000; a++) {seeds[a] = 0; seeds[a] = 4294967295; randomness[a] = 0; randomness[a] = 4294967295;}
			
			//..........Overwrites RAM of array unsigned int actual_seeds[100].
			for(int a = 0; a < 100; a++) {actual_seeds[a] = 0; actual_seeds[a] = 4294967295;}
		}
		
		//New ciphertext just as option 1, except paths.
		
		//Overwrites "512_ciphertext" with new ciphertext. - From those 512 keys made above.
		//The following is components from rolling-code.cpp.
		in_stream.open (path_to_keys      );
		out_stream.open(path_to_ciphertext);
		for(int loop = 0; loop < 512; loop++)
		{	long long temp_overflow_for_randomness;
			char garbage_byte_for_seeds_file;
			
			//..........Loads seeds[] with 1 key at-a-time.
			unsigned int seeds[1000];
			for(int a = 0; a < 1000; a++)
			{	in_stream.get(garbage_byte_for_seeds_file);
				int normal_byte = garbage_byte_for_seeds_file;
				if(normal_byte < 0) {normal_byte += 256;}
				seeds[a] = normal_byte;
				
				seeds[a] -= 48;
				if((in_stream.eof() == true) || (seeds[a] > 9))
				{	for(int b = 0; b < 1000; b++) {seeds[b] = 0; seeds[b] = 4294967295;} //..........Overwrites RAM of array unsigned int seeds[1000].
					cout << "\n\nBad keys.\n\n"; in_stream.close(); out_stream.close(); return 0;
				}
			}
			
			//..........Makes 100 10-digit actual seeds based on seeds[]. (Strings together 10 contiguous digits, 100 times.)
			unsigned int actual_seeds[100] = {0};
			int seeds_read_bookmark = 0;
			for(int a = 0; a < 100; a++)
			{	temp_overflow_for_randomness = 0;
				for(int b = 0; b < 10; b++)
				{	temp_overflow_for_randomness += seeds[seeds_read_bookmark];
					if(b < 9) {temp_overflow_for_randomness *= 10;}
					seeds_read_bookmark++;
				}
				
				actual_seeds[a] = (temp_overflow_for_randomness % 4294967296);
			}
			
			//..........Generator powerhouse.
			unsigned int randomness[1000] = {0};
			for(int b = 0; b < 100; b++)
			{	srand(actual_seeds[b]);
				for(int c = 0; c < 1000; c++) {randomness[c] += rand(); randomness[c] %= 256;} //..........Fills randomness[] (100x per 1,000-char code.)
				temp_overflow_for_randomness = (actual_seeds[99 - b] + rand()); //..........Modifies inverse actual_seeds[].
				actual_seeds[99 - b] = (temp_overflow_for_randomness % 4294967296);
				
				srand(actual_seeds[99 - b]);  //..........Now using that inverse seed.
				for(int c = 0; c < 1000; c++) //..........Swaps EACH & EVERY element in randomness[] with randomly chosen (100,000x per 1,000-char code.)
				{	int random_element = (rand() % 1000);
					for(; random_element == c;) {random_element = (rand() % 1000);}
					
					unsigned int temp_element = randomness[random_element];
					randomness[random_element] = randomness[c];
					randomness[c] = temp_element;
				}
				temp_overflow_for_randomness = (actual_seeds[b] + rand()); //..........Modifies current actual_seeds[].
				actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
			}
			
			for(int b = 0; b < 1000; b++) {out_stream << char((randomness[b] % 94) + 33);}
			
			if(loop == 511)
			{	//..........Overwrites RAM of variable long long temp_overflow_for_randomness.
				temp_overflow_for_randomness = 0; temp_overflow_for_randomness = -9223372036854775807; temp_overflow_for_randomness = 9223372036854775807;
				
				//..........Overwrites RAM of arrays unsigned int seeds[1000] and unsigned int randomness[1000].
				for(int a = 0; a < 1000; a++) {seeds[a] = 0; seeds[a] = 4294967295; randomness[a] = 0; randomness[a] = 4294967295;}
				
				//..........Overwrites RAM of array unsigned int actual_seeds[100].
				for(int a = 0; a < 100; a++) {actual_seeds[a] = 0; actual_seeds[a] = 4294967295;}
			}
		}
		in_stream.close();
		out_stream.close();
		
		//Takes the sha512sum hash of file "ciphertext".
		char sha512sum       [10000] = {"echo -n \"$(sha512sum "    }; //..........Ends up to be like:   echo -n "$(sha512sum /home/nikolay/Desktop/Personal/private/512_ciphertext | cut -d ' ' -f 1)" > /home/nikolay/Desktop/Personal/number
		char sha512sum_middle[10000] = {" | cut -d \' \' -f 1)\" > "};
		int  sha512sum_write_bookmark = 21;
		for(int a = 0; path_to_ciphertext[a] != '\0'; a++) {sha512sum[sha512sum_write_bookmark] = path_to_ciphertext[a]; sha512sum_write_bookmark++;}
		for(int a = 0; sha512sum_middle  [a] != '\0'; a++) {sha512sum[sha512sum_write_bookmark] = sha512sum_middle  [a]; sha512sum_write_bookmark++;}
		for(int a = 0; path_to_number    [a] != '\0'; a++) {sha512sum[sha512sum_write_bookmark] = path_to_number    [a]; sha512sum_write_bookmark++;}
		system(sha512sum);
		
		//Writes user message to new file "representing_sha512sum_of".
		out_stream.open(path_to_representing_sha512sum_of);
		if(existence_of_message == true) {for(int a = 0; message[a] != '\0'; a++) {out_stream << message[a];}}
		out_stream << "\n";
		out_stream.close();
		
		//Appends new number to file "representing_sha512sum_of".
		in_stream.open(path_to_number);
		out_stream.open(path_to_representing_sha512sum_of, ios::app);
		for(int a = 0; a < 128; a++) {in_stream.get(garbage_byte); out_stream.put(garbage_byte);}
		out_stream << "\n0";
		in_stream.close();
		out_stream.close();
		
		//Keeps appending 0s to file "representing_sha512sum_of" until its sha512sum hash is composed of 256 1 bits and 256 0 bits. (16 tries on average.)
		char sha512sum_bit_distributed[10000] = {"echo -n \"$(sha512sum "};
		int  sha512sum_bit_distributed_write_bookmark = 21;
		for(int a = 0; path_to_representing_sha512sum_of[a] != '\0'; a++) {sha512sum_bit_distributed[sha512sum_bit_distributed_write_bookmark] = path_to_representing_sha512sum_of[a]; sha512sum_bit_distributed_write_bookmark++;}
		for(int a = 0; sha512sum_middle                 [a] != '\0'; a++) {sha512sum_bit_distributed[sha512sum_bit_distributed_write_bookmark] = sha512sum_middle                 [a]; sha512sum_bit_distributed_write_bookmark++;}
		for(int a = 0; path_to_the_sha512sum            [a] != '\0'; a++) {sha512sum_bit_distributed[sha512sum_bit_distributed_write_bookmark] = path_to_the_sha512sum            [a]; sha512sum_bit_distributed_write_bookmark++;}
		
		for(int a = 0; a < 5000; a++)
		{	system(sha512sum_bit_distributed);
			int zeros_counter = 0;
			
			in_stream.open(path_to_the_sha512sum);
			for(int b = 0; b < 128; b++)
			{	in_stream.get(garbage_byte);
				if     (garbage_byte == '0') {zeros_counter += 4;} //..........hex 0 consists of 4 0 bits, and so on.
				else if(garbage_byte == '1') {zeros_counter += 3;}
				else if(garbage_byte == '2') {zeros_counter += 3;}
				else if(garbage_byte == '3') {zeros_counter += 2;}
				
				else if(garbage_byte == '4') {zeros_counter += 3;}
				else if(garbage_byte == '5') {zeros_counter += 2;}
				else if(garbage_byte == '6') {zeros_counter += 2;}
				else if(garbage_byte == '7') {zeros_counter += 1;}
				
				else if(garbage_byte == '8') {zeros_counter += 3;}
				else if(garbage_byte == '9') {zeros_counter += 2;}
				else if(garbage_byte == 'a') {zeros_counter += 2;}
				else if(garbage_byte == 'b') {zeros_counter += 1;}
				
				else if(garbage_byte == 'c') {zeros_counter += 2;}
				else if(garbage_byte == 'd') {zeros_counter += 1;}
				else if(garbage_byte == 'e') {zeros_counter += 1;}
				else if(garbage_byte == 'f') {zeros_counter += 0;}
				else                         {cout << "\n\nError_d1\n\n"; in_stream.close(); return 0;}
			}
			in_stream.close();
			
			if(zeros_counter == 256) {break;}
			out_stream.open(path_to_representing_sha512sum_of, ios::app);
			out_stream << "0";
			out_stream.close();
			
			if(a == 4999) {cout << "\nError_d2\n"; return 0;}
		}
		
		out_stream.open(path_to_the_sha512sum, ios::app);
		out_stream << "\n\nThis hash is composed of 256 0 bits and 256 1 bits."
		           << "\nIt's a hash of file \"representing_sha512sum_of\""
		           << "\nwhich contains your message and new number."
		           << "\n"
		           << "\nIt is what will be represented by the presence and"
		           << "\nabsence of keys to your previous ciphertext list.\n";
		out_stream.close();
		
		//Appends only 256 old keys to file "public" (based on bits from hash in file "the_sha512sum".)
		bool b[512];
		int i = 0;
		in_stream.open(path_to_the_sha512sum);
		for(int a = 0; a < 128; a++)
		{	in_stream.get(garbage_byte); //      |             |             |             |
			if     (garbage_byte == '0') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == '1') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == '2') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == '3') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			else if(garbage_byte == '4') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == '5') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == '6') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == '7') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			else if(garbage_byte == '8') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == '9') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == 'a') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == 'b') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			else if(garbage_byte == 'c') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == 'd') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == 'e') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == 'f') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			
			else {cout << "\n\nError_d3\n\n"; in_stream.close(); return 0;}
			
			i += 4;
		}
		in_stream.close();
		
		out_stream.open(path_to_public, ios::app);
		out_stream << "\n";
		int old_keys_read_bookmark = 0;
		for(int a = 0; a < 512; a++)
		{	if(b[a] == 1)
			{	for(int present = 0; present < 1000; present++) {out_stream << old_keys[old_keys_read_bookmark]; old_keys_read_bookmark++;}
			}
			else {old_keys_read_bookmark += 1000;}
		}
		out_stream.close();
		
		//Appends presence & absence indication to file "public".
		out_stream.open(path_to_public, ios::app);
		out_stream << "\n";
		for(int a = 0; a < 512; a++) {out_stream << b[a];}
		out_stream.close();
		
		//Appends user message and new number to file "public" (all from file "representing_sha512sum_of".)
		in_stream.open(path_to_representing_sha512sum_of);
		out_stream.open(path_to_public, ios::app);
		out_stream << "\n";
		in_stream.get(garbage_byte);
		for(; in_stream.eof() == false;) {out_stream.put(garbage_byte); in_stream.get(garbage_byte);}
		in_stream.close();
		out_stream.close();
		
		//Overwrites RAM of array char old_keys[512000].    //Binary: 00000000, 111111111.
		for(int a = 0; a < 512000; a++) {old_keys[a] = '\0'; old_keys[a] = -1;}
		
		if(existence_of_message == true) {cout << "\n";}
		cout << "\nModified. Publish file \"public\""
		     << "\nso they can update your number.\n\n\n";
	}
	
	
	
	
	
	//_______________________________________________________Verify___________________________________________________//
	if(user_option == 3)
	{	
		/* SUMMARY
		-------------
		* Takes hash of ciphertext in file "public" and compares it to the number.
		* Loads the 512 ciphertext to RAM.
		* Loads the 256 keys to RAM.
		* Loads the 512 presence & absence indication to RAM.
		* Writes user message & number to file.
		* Takes sha512sum of user message & number file.
		* Decrypts ciphertext to which keys are present.
		* Compares this presence & absence to the bits of the hash of "user message & number file".
		* If compares, saves message from "user message & number file".
		* If compares, overwrites file "number" with the number in "user message & number file". */
		
		//Gets path to file "public".
		//..........Gets path then fixes it if drag-n-dropped, regardless of single-quote presence and "enter"
		//..........not being cleared, meaning you can have options before this, where the user presses enter.
		cout << "Drop/enter their disposable public file:\n";
		char path_to_public[10000] = {'\0'};
		{	for(int a = 0; a < 10000; a++) {path_to_public[a] = '\0';}
			cin.getline(path_to_public, 10000);
			if(path_to_public[0] == '\0')
			{	for(int a = 0; a < 10000; a++) {path_to_public[a] = '\0';}
				cin.getline(path_to_public, 10000);
			}
			if(path_to_public[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
			
			//..........Removes last space in path_to_public[].
			bool existence_of_last_space = false;
			for(int a = 9999; a > 0; a--)
			{	if(path_to_public[a] != '\0')
				{	if(path_to_public[a] == ' ') {path_to_public[a] = '\0'; existence_of_last_space = true;}
					break;
				}
			}
			
			//..........Removes encapsulating single-quotes in path_to_public[].
			bool existence_of_encapsulating_single_quotes = false;
			if(path_to_public[0] == '\'')
			{	for(int a = 0; a < 9999; a++)
				{	path_to_public[a] = path_to_public[a + 1];
					if(path_to_public[a] == '\0') 
					{	if(path_to_public[a - 1] != '\'') {cout << "\nBad path.\n"; return 0;}
						path_to_public[a - 1] = '\0';
						existence_of_encapsulating_single_quotes = true;
						break;
					}
				}
			}
			
			//..........Replaces all "'\''" with "'" in path_to_public[].
			int single_quote_quantity = 0;
			for(int a = 0; a < 10000; a++)
			{	if(path_to_public[a] == '\'') {single_quote_quantity++;}
			}
			
			if((single_quote_quantity                     >    0)
			&& (existence_of_last_space                  == true)
			&& (existence_of_encapsulating_single_quotes == true))
			{	if((single_quote_quantity % 3) != 0) {cout << "\nBad path.\n"; return 0;}
				
				for(int a = 0; a < 9997; a++)
				{	if(path_to_public[a] == '\'')
					{	int temp = (a + 1);
						for(; temp < 9997; temp++)
						{	path_to_public[temp] = path_to_public[temp + 3];
						}
					}
				}
			}
			
			in_stream.open(path_to_public);
			if(in_stream.fail() == true) {cout << "\nNo such file or directory.\n"; in_stream.close(); return 0;}
			in_stream.close();
		}
		
		//Gets path to file "number".
		//..........Gets path then fixes it if drag-n-dropped, regardless of single-quote presence and "enter"
		//..........not being cleared, meaning you can have options before this, where the user presses enter.
		cout << "\nDrop/enter their number file to modify:\n";
		char path_to_number[10000] = {'\0'};
		{	for(int a = 0; a < 10000; a++) {path_to_number[a] = '\0';}
			cin.getline(path_to_number, 10000);
			if(path_to_number[0] == '\0')
			{	for(int a = 0; a < 10000; a++) {path_to_number[a] = '\0';}
				cin.getline(path_to_number, 10000);
			}
			if(path_to_number[0] == '\0') {cout << "\nNo path given.\n"; return 0;}
			
			//..........Removes last space in path_to_number[].
			bool existence_of_last_space = false;
			for(int a = 9999; a > 0; a--)
			{	if(path_to_number[a] != '\0')
				{	if(path_to_number[a] == ' ') {path_to_number[a] = '\0'; existence_of_last_space = true;}
					break;
				}
			}
			
			//..........Removes encapsulating single-quotes in path_to_number[].
			bool existence_of_encapsulating_single_quotes = false;
			if(path_to_number[0] == '\'')
			{	for(int a = 0; a < 9999; a++)
				{	path_to_number[a] = path_to_number[a + 1];
					if(path_to_number[a] == '\0') 
					{	if(path_to_number[a - 1] != '\'') {cout << "\nBad path.\n"; return 0;}
						path_to_number[a - 1] = '\0';
						existence_of_encapsulating_single_quotes = true;
						break;
					}
				}
			}
			
			//..........Replaces all "'\''" with "'" in path_to_number[].
			int single_quote_quantity = 0;
			for(int a = 0; a < 10000; a++)
			{	if(path_to_number[a] == '\'') {single_quote_quantity++;}
			}
			
			if((single_quote_quantity                     >    0)
			&& (existence_of_last_space                  == true)
			&& (existence_of_encapsulating_single_quotes == true))
			{	if((single_quote_quantity % 3) != 0) {cout << "\nBad path.\n"; return 0;}
				
				for(int a = 0; a < 9997; a++)
				{	if(path_to_number[a] == '\'')
					{	int temp = (a + 1);
						for(; temp < 9997; temp++)
						{	path_to_number[temp] = path_to_number[temp + 3];
						}
					}
				}
			}
			
			in_stream.open(path_to_number);
			if(in_stream.fail() == true) {cout << "\nNo such file or directory.\n"; in_stream.close(); return 0;}
			in_stream.close();
		}
		
		//Takes hash of ciphertext in file "public" and compares it to the number.
		char ciphertext_hash[10000] = {"head -c 512000 "};
		int  ciphertext_hash_write_bookmark = 15;
		for(int a = 0; path_to_public[a] != '\0'; a++)
		{	ciphertext_hash[ciphertext_hash_write_bookmark] = path_to_public[a];
			ciphertext_hash_write_bookmark++;
		}
		
		char ciphertext_hash_appendix[100] = {" | sha512sum > temp_sha512sum_Authorship_verification"};
		for(int a = 0; ciphertext_hash_appendix[a] != '\0'; a++)
		{	ciphertext_hash[ciphertext_hash_write_bookmark] = ciphertext_hash_appendix[a];
			ciphertext_hash_write_bookmark++;
		}
		
		system(ciphertext_hash);
		
		in_stream.open(path_to_number);
		char temp_number_for_comparison[128] = {'\0'};
		for(int a = 0; a < 128; a++) {in_stream.get(temp_number_for_comparison[a]);}
		in_stream.close();
		
		in_stream.open("temp_sha512sum_Authorship_verification");
		char garbage_byte;
		for(int a = 0; a < 128; a++)
		{	in_stream.get(garbage_byte);
			if(garbage_byte != temp_number_for_comparison[a]) {cout << "\nFAILED! That number is not the ciphertext hash.\n"; in_stream.close(); return 0;}
		}
		in_stream.close();
		
		remove("temp_sha512sum_Authorship_verification");
		
		in_stream.open(path_to_public);
		//........
		//.....
		//..
		//.
		
		//Loads the 512 ciphertext to RAM.
		char ciphertext[512000];
		for(int a = 0; a < 512000; a++) {in_stream.get(ciphertext[a]);}
		in_stream.get(garbage_byte);
		
		//Loads the 256 keys to RAM.
		char keys[256000];
		for(int a = 0; a < 256000; a++) {in_stream.get(keys[a]); keys[a] -= 48;}
		in_stream.get(garbage_byte);
		
		//Loads the 512 presence & absence indication to RAM.
		char presence_absence[512];
		for(int a = 0; a < 512; a++) {in_stream.get(presence_absence[a]);}
		in_stream.get(garbage_byte);
		
		int zeros_counter = 0;
		int ones_counter  = 0;
		for(int a = 0; a < 512; a++)
		{	if     (presence_absence[a] == '0') {zeros_counter++;}
			else if(presence_absence[a] == '1') {ones_counter++ ;}
			else                                {cout << "\nPresence & absence indication must have 256 zeros and 256 ones.\n"; return 0;}
		}
		
		if(zeros_counter != ones_counter) {cout << "\nPresence & absence indication must have 256 zeros and 256 ones.\n"; return 0;}
		
		//Writes user message & number to file.
		out_stream.open("temp_user_message_and_number_Authorship_verification");
		in_stream.get(garbage_byte);
		for(; in_stream.eof() != true;) {out_stream.put(garbage_byte); in_stream.get(garbage_byte);}
		out_stream.close();
		
		//.
		//..
		//.....
		//........
		in_stream.close();
		
		//Takes sha512sum of user message & number file.
		system("sha512sum temp_user_message_and_number_Authorship_verification > temp_sha512sum_of_user_message_and_number");
		
		//Decrypts ciphertext to which keys are present.
		int ciphertext_read_bookmark = 0;
		int keys_read_bookmark       = 0;
		for(int a = 0; a < 512; a++)
		{	if(presence_absence[a] == '1')
			{	long long temp_overflow_for_randomness;
				
				//..........Makes 100 10-digit actual seeds based on keys[]. (Strings together 10 contiguous digits, 100 times.)
				unsigned int actual_seeds[100] = {0};
				for(int b = 0; b < 100; b++)
				{	temp_overflow_for_randomness = 0;
					for(int b = 0; b < 10; b++)
					{	temp_overflow_for_randomness += keys[keys_read_bookmark];
						if(b < 9) {temp_overflow_for_randomness *= 10;}
						keys_read_bookmark++;
					}
					
					actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
				}
				
				//..........Generator powerhouse.
				unsigned int randomness[1000] = {0};
				for(int b = 0; b < 100; b++)
				{	srand(actual_seeds[b]);
					for(int c = 0; c < 1000; c++) {randomness[c] += rand(); randomness[c] %= 256;} //..........Fills randomness[] (100x per 1,000-char code.)
					temp_overflow_for_randomness = (actual_seeds[99 - b] + rand()); //..........Modifies inverse actual_seeds[].
					actual_seeds[99 - b] = (temp_overflow_for_randomness % 4294967296);
					
					srand(actual_seeds[99 - b]);  //..........Now using that inverse seed.
					for(int c = 0; c < 1000; c++) //..........Swaps EACH & EVERY element in randomness[] with randomly chosen (100,000x per 1,000-char code.)
					{	int random_element = (rand() % 1000);
						for(; random_element == c;) {random_element = (rand() % 1000);}
						
						unsigned int temp_element = randomness[random_element];
						randomness[random_element] = randomness[c];
						randomness[c] = temp_element;
					}
					temp_overflow_for_randomness = (actual_seeds[b] + rand()); //..........Modifies current actual_seeds[].
					actual_seeds[b] = (temp_overflow_for_randomness % 4294967296);
				}
				
				for(int b = 0; b < 1000; b++)
				{	if( char((randomness[b] % 94) + 33) != ciphertext[ciphertext_read_bookmark]) {cout << "\nFAILED! Incorrect keys.\n"; return 0;}
					ciphertext_read_bookmark++;
				}
			}
			else {ciphertext_read_bookmark += 1000;}
		}
		
		//Compares this presence & absence to the bits of the hash of "user message & number file".
		bool b[512];
		int i = 0;
		in_stream.open("temp_sha512sum_of_user_message_and_number");
		for(int a = 0; a < 128; a++)
		{	in_stream.get(garbage_byte); //      |             |             |             |
			if     (garbage_byte == '0') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == '1') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == '2') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == '3') {b[i] = 0; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			else if(garbage_byte == '4') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == '5') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == '6') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == '7') {b[i] = 0; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			else if(garbage_byte == '8') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == '9') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == 'a') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == 'b') {b[i] = 1; b[i + 1] = 0; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			else if(garbage_byte == 'c') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 0;}
			else if(garbage_byte == 'd') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 0; b[i + 3] = 1;}
			else if(garbage_byte == 'e') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 0;}
			else if(garbage_byte == 'f') {b[i] = 1; b[i + 1] = 1; b[i + 2] = 1; b[i + 3] = 1;}
			//                                   |             |             |             |
			
			else {cout << "\n\nError_d4\n\n"; in_stream.close(); return 0;}
			
			i += 4;
		}
		in_stream.close();
		
		for(int a = 0; a < 512; a++)
		{	if(presence_absence[a] != char(b[a] + 48)) {cout << "\nFAILED! Hash of \"message + new number\" does not match key presence & absence.\n"; return 0;}
		}
		
		cout << "\nVerified!";
		
		in_stream.open("temp_user_message_and_number_Authorship_verification");
		//........
		//.....
		//..
		//.
		
		//If compares, saves message from "user message & number file".
		in_stream.get(garbage_byte);
		if(garbage_byte != '\n')
		{	char path_to_message[10000] = {'\0'};
			for(int a = 0; a < 10000; a++) {path_to_message[a] = path_to_number[a];}
			
			int name_bookmark = 0;
			for(int a = 9999; a > 0; a--)
			{	if(path_to_message[a] == '/') {name_bookmark = (a + 1); break;}
			}
			
			char temp_name_message[100] = {"message"};
			for(int a = 0; temp_name_message[a] != '\0'; a++) {path_to_message[name_bookmark] = temp_name_message[a]; name_bookmark++;}
			path_to_message[name_bookmark] = '\0';
			
			out_stream.open(path_to_message, ios::app);
			for(; garbage_byte != '\n';) {out_stream.put(garbage_byte); in_stream.get(garbage_byte);}
			out_stream << "\n";
			out_stream.close();
			
			cout << "\nMessage appended.";
		}
		else {cout << "\nNo message.";}
		
		//If compares, overwrites file "number" with the number in "user message & number file".
		out_stream.open(path_to_number);
		in_stream.get(garbage_byte);
		for(int a = 0; a < 128; a++) {out_stream.put(garbage_byte); in_stream.get(garbage_byte);}
		out_stream.close();
		
		cout << "\nNumber updated.\n\n\n";
		
		//.
		//..
		//.....
		//........
		in_stream.close();
		
		remove("temp_user_message_and_number_Authorship_verification");
		remove("temp_sha512sum_of_user_message_and_number"           );
	}
}
