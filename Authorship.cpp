/// Authorship - infinite data authentication independent of encryption type or symmetry.
///              Get a number only you can modify--which anyone can verify.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/* Version 7.0.0
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~

 Set testing_mode to true and get a number. Now repeat options 2 and 3; You're
 verifying yourself to see what others will see but you need only verify others.

~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~*/

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	//                               user knobs
	
	/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\//////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\  /////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\    ////////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\      ///////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\        //////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\            ////////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\              ///////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\\\                  /////////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\\\\\                      ///////////////////////////
	\\\\\\\\\\\\\\\\\\\\\\\                              ///////////////////////
	\\\\\\\\\\\\\\\\\\                                        ////////////////*/
	
	
	//                                                                                                               |
	bool testing_mode = false; // DEFAULT = false                                              fatal if broken >     |
	//                                                                                                               |
	
	
	/*////////////////                                          \\\\\\\\\\\\\\\\
	///////////////////////                              \\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////                      \\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////                  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////              \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////            \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////        \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	///////////////////////////////////      \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	////////////////////////////////////    \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	/////////////////////////////////////  \\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
	//////////////////////////////////////\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/
	
	cout << "\n(Authorship)\n\n"
	
	     << "(1) Create - get a number only you can modify--which anyone can verify.\n"
	     << "(2) Modify - needs Authorship.private file to make Authorship.public file.\n"
	     << "(3) Verify - needs both their Authorship.public and Authorship.number files.\n\n"
	
	     << "Enter option: ";
	
	int user_option; cin >> user_option;
	ifstream in_stream;
	ofstream out_stream;
	
	
	
	
	
	//_____________________________________________________________________________________________________________________
	//__________________________________________________GET_FIRST_NUMBER__________________________________________________/
	if(user_option == 1)
	{	//Using existing quantity, Authorship proceeds as before but utilizes only needed portions of the whole.
		//Multi-way functions (of type step-down as used here) means no reversal shortcuts. But multiple solutions
		//means less certainty of intended decryption... To increase certainty of intended decryption (to step down
		//from perfect secrecy of the One-time pad's all-way function to computational difficulty of multi-way functions),
		//expected identifying properties of plaintext are contiguous 5-digit primes. Authorship has general
		//search priorities built-in. They expect these prime properties from decrypted plaintext.
		
		//Checks if files already exists.
		bool existence_of_file_Authorship_number  = false;
		bool existence_of_file_Authorship_private = false;
		in_stream.open("Authorship.number");  if(in_stream.fail() == false) {existence_of_file_Authorship_number  = true;} in_stream.close();
		in_stream.open("Authorship.private"); if(in_stream.fail() == false) {existence_of_file_Authorship_private = true;} in_stream.close();
		
		if((existence_of_file_Authorship_number  == true)
		&& (existence_of_file_Authorship_private == true))
		{cout << "\nFiles Authorship.number and Authorship.private already exist.\n"; return 0;}
		
		if(existence_of_file_Authorship_number  == true) {cout << "\nFile Authorship.number already exists.\n";  return 0;}
		if(existence_of_file_Authorship_private == true) {cout << "\nFile Authorship.private already exists.\n"; return 0;}
		
		//Gets seeds for RNG.
		unsigned int user_seeds[50] = {0};
		if(testing_mode == false)
		{	//Gets 50 seeds from the user.
			cout << "\nEnter a random 8-digit integer, repeat 50 times.\n\n";
			for(int a = 0; a < 50; a++)
			{	if(a < 9) {cout << " " << (a + 1) << " of 50: ";} //Blank for aesthetics.
				else      {cout <<        (a + 1) << " of 50: ";}
				
				//Gets and checks input.
				cin >> user_seeds[a];
				if((user_seeds[a] > 99999999) || (user_seeds[a] < 10000000)) {cout << "\nOut of bounds, try again.\n"; return 0;}
			}
		}
		else
		{	//Fills seeds automatically (not secure, please turn off testing_mode.)
			cout << "\nCAUTION: testing_mode is turned on!  Use of these files is strongly discouraged!";
			srand(time(0));
			for(int a = 0; a < 50; a++) {user_seeds[a] = (rand() % 100000000);}
		}
		
		cout << "\n\nWait 5 seconds...\n";
		
		/*Generates random numbers in arrays functions[] and keys[]. (Constructively applies randomness based on 50 user seeds.)
		Number of possible keys per key: (95^1,000 or 10^1977) ~= 529182274774504763830539013129828002031774783533315989172550112454325120067086
		5320146452373594718852917306195312985394577376458207810856924643582943374082422747388708888747644424641359666528756626103165740624350564
		7458352903136303750933244235717370788699695208239031166611256027967040028838334795356155711479538914638596550775005291039392481521230142
		4866763813372856977497426768548229883133952014400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000  */
		unsigned char functions[50400] = {0}; //Eventually  becomes 1,008 contiguous    50-character functions (encrypted.)
		unsigned char keys   [1008000] = {0}; //Immediately becomes 1,008 contiguous 1,000-character keys (used as seeds.)
		for(int a = 0; a < 50; a++)
		{	srand(user_seeds[a]);
			
			if((user_seeds[a] % 2) == 0)
			{	//Constructively fills functions[] and keys[] LEFT to right based on seeds.
				for(int b = 0; b < 50400; b++)
				{	functions[b] += (rand() % 10);
					functions[b] %= 10;
				}
				
				for(int b = 0; b < 1008000; b++)
				{	keys[b] += (rand() % 95);
					keys[b] %= 95;
				}
			}
			else
			{	//Constructively fills functions[] and keys[] RIGHT to left based on seeds.
				for(int b = 50399; b >= 0; b--)
				{	functions[b] += (rand() % 10);
					functions[b] %= 10;
				}
				
				for(int b = 1007999; b >= 0; b--)
				{	keys[b] += (rand() % 95);
					keys[b] %= 95;
				}
			}
		}
		
		//Generates additional seeds from keys[] for additional transformation of actual_key[] before encryption.
		long long secondary_seeds[100800] = {0}; //Assembles 100 (mostly 11-digit) seeds per key, from each of the 1,008 1,000-character keys.
		int keys_read_bookmark = 0;
		int secondary_seeds_write_bookmark = 0;
		for(int a = 0; a < 100800; a++) //100,800 comes from 10 contiguous key characters being scraped at once, 100,800 times. Recall that keys[] is 10x bigger.
		{	for(int b = 0; b < 10; b++)
			{	secondary_seeds[secondary_seeds_write_bookmark] *= 10;
				secondary_seeds[secondary_seeds_write_bookmark] += keys[keys_read_bookmark + b];
			}
			
			keys_read_bookmark += 10;
			secondary_seeds_write_bookmark++;
		}
		
		//Generates 1,008 contiguous 50-digit plaintext (each composed of 10 contiguous 5-digit primes.)
		//Randomness in functions[] is used to create this plaintext then functions[] is overwritten with it.
		bool sieve[100000] = {1, 1}; //Boolean sieve of Eratosthenes. Zeros are mapped to prime elements.
		for(int prime = 2; prime < 317; prime++) //317 is sqrt(100,000)
		{	for(int a = prime + prime; a < 100000; a += prime) {sieve[a] = 1;}
		}
		
		int functions_read_bookmark  = 0;
		int functions_write_bookmark = 0;
		for(int a = 0; a < 10080; a++) //50,400/5 = 10,080 total 5-digit primes.
		{	//Unloads 5 array elements to make one integer.
			int temp_5_digit_prime;
			temp_5_digit_prime  = functions[functions_read_bookmark    ]; if(temp_5_digit_prime == 0) {temp_5_digit_prime++;} temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 1]; temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 2]; temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 3]; temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 4];
			
			//Adjusts temp_5_digit_prime for primality (tests & searches in pos dir.) If length > 5, sets to largest 5-digit prime.
			while(sieve[temp_5_digit_prime] == 1)
			{	if(temp_5_digit_prime > 99991) {temp_5_digit_prime = 99991; break;}
				temp_5_digit_prime++;
			}
			
			//Writes the prime to functions[].
			functions[functions_write_bookmark + 4] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark + 3] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark + 2] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark + 1] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark    ] =  temp_5_digit_prime;
			
			functions_read_bookmark  += 5;
			functions_write_bookmark += 5;
		}
		
		//Encrypts 1,008 plaintext to make the functions.
		char garbage_byte;
		functions_write_bookmark = 0;
		keys_read_bookmark = 0;
		unsigned char actual_key[50] = {0};
		int secondary_seeds_read_bookmark = 0;
		for(int a = 0; a < 1008; a++) //Generates random numbers in array actual_key[].
		{	for(int b = 0; b < 1000; b++) //Constructively applies randomness based on keys[] (used as seeds, 1,000 items per actual_key[].)
			{	srand(keys[keys_read_bookmark]);
				
				if((keys[keys_read_bookmark] % 2) == 0)
				{	for(int c = 0; c < 50; c++) //Fills left to right based on seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				else
				{	for(int c = 49; c >= 0; c--) //Fills right to left based on seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				
				keys_read_bookmark++;
			}
			
			//Further transforms actual_key[] based on secondary_seeds[].
			for(int b = 0; b < 100; b++) //Constructively applies randomness based on secondary_seeds[] (used as seeds, 100 11-digit integer per actual_key[].)
			{	srand(secondary_seeds[secondary_seeds_read_bookmark]);
				
				if((secondary_seeds[secondary_seeds_read_bookmark] % 2) == 0)
				{	for(int c = 0; c < 50; c++) //Fills left to right based on SECONDARY seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				else
				{	for(int c = 49; c >= 0; c--) //Fills right to left based on SECONDARY seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				
				secondary_seeds_read_bookmark++;
			}
			
			//Layers encryption by again transforming actual_key[] using sha256sum AND sha512sum of key.
			out_stream.open("temp");
			keys_read_bookmark -= 1000;
			for(int b = 0; b < 1000; b++) {out_stream.put(keys[keys_read_bookmark + b]);}
			keys_read_bookmark += 1000;
			out_stream.close();
			
			system("sha512sum temp > temp_512");
			system("sha256sum temp > temp_256");
			
			in_stream.open("temp_256");
			for(int b = 0; b < 50; b++)
			{	in_stream.get(garbage_byte);
				actual_key[b] += garbage_byte;
				actual_key[b] %= 95;
			}
			in_stream.close();
			
			in_stream.open("temp_512");
			for(int b = 0; b < 50; b++)
			{	in_stream.get(garbage_byte);
				actual_key[b] += garbage_byte;
				actual_key[b] %= 95;
			}
			in_stream.close();
			
			///Encrypts functions[] using actual_key[].
			for(int b = 0; b < 50; b++)
			{	functions[functions_write_bookmark] += actual_key[b];
				functions[functions_write_bookmark] %= 95;
				
				functions_write_bookmark++;
			}
			
			//Resetting actual key. If not reset (in option 3) then string depends on keys not present.
			for(int a = 0; a < 50; a++) {actual_key[a] = 0;}
		}
		
		//Creates sha512sum of only the first 512 functions.
		out_stream.open("temp");
		for(int a = 0; a <  25600; a++) {out_stream.put(functions[a] + 32);}
		out_stream.close();
		
		system("sha512sum temp > temp_512");
		
		in_stream.open("temp_512");
		out_stream.open("Authorship.number");
		for(int a = 0; a < 128; a++) {in_stream.get(garbage_byte); out_stream.put(garbage_byte);}
		in_stream.close();
		out_stream.close();
		
		remove("temp");
		remove("temp_256");
		remove("temp_512");
		
		//Writes functions and keys to file Authorship.private.
		out_stream.open("Authorship.private");
		out_stream << "DO NOT PUBLISH! Authorship.private v7.0.0=\r\n\r\n"; //46-byte header must be. Use "\r\n" for all returns (for max compatibility.)
		for(int a = 0; a <  25600; a++) {out_stream.put(functions[a] + 32);} out_stream << "\r\n";
		for(int a = 0; a < 512000; a++) {out_stream.put(keys     [a] + 32);}
		out_stream.close();
		
		//Overwrites RAM of arrays: unsigned int user_seeds[50] and unsigned char actual_key[50].
		for(int a = 0; a < 50; a++)
		{	user_seeds[a] = 0; user_seeds[a] = 12345678; user_seeds[a] = 87654321; user_seeds[a] = 99999999;
			actual_key[a] = 0; actual_key[a] = 255;
		}
		
		//Overwrites RAM of array: unsigned char keys[1008000].
		for(int a = 0; a < 1008000; a++) {keys[a] = 0; keys[a] = 255;}
		
		cout << "\n\nPublish the contents of Authorship.number (128 characters.)\n"
		     << "Please include the Authorship version used, and your name or tag.\n"
		     << "(Not needed once published; verifying parties update it as you modify.)\n"
		     << "Guardedly cache Authorship.private. It contains dynamic one-time data.\n\n";
	}
	
	
	
	
	
	//_____________________________________________________________________________________________________________________
	//____________________________________________________MODIFY_NUMBER___________________________________________________/
	else if(user_option == 2)
	{	//Using existing quantity, Authorship proceeds as before but utilizes only needed portions of the whole.
		
		/* Basic layout:
		
		1. Loads Authorship.private file.
		2. Overwrites Authorship.private file with new info.
		3. Selectively writes that old private info to a new .public file so as to symbolize [the sha512sum of] the new number & message. */
		
		//Checks if file Authorship.private is present.
		in_stream.open("Authorship.private");
		if(in_stream.fail() == true)
		{	in_stream.close();
			
			cout << "\nAuthorship.private is missing or misspelled. Copy and paste it into the\n"
			     << "folder from which you run this Authorship program. If this is an executable file\n"
			     << "running in the terminal, its effectiveness-directory is the user folder on this\n"
			     << "machine such as: /home/nikolay--where Authorship.private should be placed.\n"
			     << "Continue? y/n: ";
			
			char wait;
			cin >> wait;
			if(wait != 'y') {return 0;}
		}
		in_stream.close();
		
		in_stream.open("Authorship.private");
		if(in_stream.fail() == true) {in_stream.close(); cout << "\nCannot continue without Authorship.private, program ended.\n"; return 0;}
		char sniffed_one_file_character_Authorship_private;
		in_stream.get(sniffed_one_file_character_Authorship_private);
		if(in_stream.eof() == true)  {in_stream.close(); cout << "\nAuthorship.private is empty, program ended.\n"; return 0;}
		in_stream.close();
		
		//Loads file Authorship.private.
		char old_functions[ 25600];
		char old_keys     [512000];
		char header_waste;
		in_stream.open("Authorship.private");
		for(int a = 0; a < 46; a++) {in_stream.get(header_waste);} //Skips through the 46-character header.
		for(int a = 0; a < 25600; a++) {in_stream.get(old_functions[a]);}
		in_stream.get(header_waste); in_stream.get(header_waste); //Skips the "\r\n" characters after the 1,008 functions.
		for(int a = 0; a < 512000; a++) {in_stream.get(old_keys[a]);}
		in_stream.close();
		
		
		
		
		
		//The following block-bunch is a perfect snippet of option 1 except new number file in named new_number_and_message.
		//Gets seeds for RNG.
		unsigned int user_seeds[50] = {0};
		if(testing_mode == false)
		{	//Gets 50 seeds from the user.
			cout << "\nEnter a random 8-digit integer, repeat 50 times.\n\n";
			for(int a = 0; a < 50; a++)
			{	if(a < 9) {cout << " " << (a + 1) << " of 50: ";} //Blank for aesthetics.
				else      {cout <<        (a + 1) << " of 50: ";}
				
				//Gets and checks input.
				cin >> user_seeds[a];
				if((user_seeds[a] > 99999999) || (user_seeds[a] < 10000000)) {cout << "\nOut of bounds, try again.\n"; return 0;}
			}
		}
		else
		{	//Fills seeds automatically (not secure, please turn off testing_mode.)
			cout << "\nCAUTION: testing_mode is turned on!  Use of these files is strongly discouraged!";
			srand(time(0));
			for(int a = 0; a < 50; a++) {user_seeds[a] = (rand() % 100000000);}
		}
		
		cout << "\n\nWait 5 seconds...\n";
		
		/*Generates random numbers in arrays functions[] and keys[]. (Constructively applies randomness based on 50 user seeds.)
		Number of possible keys per key: (95^1,000 or 10^1977) ~= 529182274774504763830539013129828002031774783533315989172550112454325120067086
		5320146452373594718852917306195312985394577376458207810856924643582943374082422747388708888747644424641359666528756626103165740624350564
		7458352903136303750933244235717370788699695208239031166611256027967040028838334795356155711479538914638596550775005291039392481521230142
		4866763813372856977497426768548229883133952014400000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		0000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000
		000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000000  */
		unsigned char functions[50400] = {0}; //Eventually  becomes 1,008 contiguous    50-character functions (encrypted.)
		unsigned char keys   [1008000] = {0}; //Immediately becomes 1,008 contiguous 1,000-character keys (used as seeds.)
		for(int a = 0; a < 50; a++)
		{	srand(user_seeds[a]);
			
			if((user_seeds[a] % 2) == 0)
			{	//Constructively fills functions[] and keys[] LEFT to right based on seeds.
				for(int b = 0; b < 50400; b++)
				{	functions[b] += (rand() % 10);
					functions[b] %= 10;
				}
				
				for(int b = 0; b < 1008000; b++)
				{	keys[b] += (rand() % 95);
					keys[b] %= 95;
				}
			}
			else
			{	//Constructively fills functions[] and keys[] RIGHT to left based on seeds.
				for(int b = 50399; b >= 0; b--)
				{	functions[b] += (rand() % 10);
					functions[b] %= 10;
				}
				
				for(int b = 1007999; b >= 0; b--)
				{	keys[b] += (rand() % 95);
					keys[b] %= 95;
				}
			}
		}
		
		//Generates additional seeds from keys[] for additional transformation of actual_key[] before encryption.
		long long secondary_seeds[100800] = {0}; //Assembles 100 (mostly 11-digit) seeds per key, from each of the 1,008 1,000-character keys.
		int keys_read_bookmark = 0;
		int secondary_seeds_write_bookmark = 0;
		for(int a = 0; a < 100800; a++) //100,800 comes from 10 contiguous key characters being scraped at once, 100,800 times. Recall that keys[] is 10x bigger.
		{	for(int b = 0; b < 10; b++)
			{	secondary_seeds[secondary_seeds_write_bookmark] *= 10;
				secondary_seeds[secondary_seeds_write_bookmark] += keys[keys_read_bookmark + b];
			}
			
			keys_read_bookmark += 10;
			secondary_seeds_write_bookmark++;
		}
		
		//Generates 1,008 contiguous 50-digit plaintext (each composed of 10 contiguous 5-digit primes.)
		//Randomness in functions[] is used to create this plaintext then functions[] is overwritten with it.
		bool sieve[100000] = {1, 1}; //Boolean sieve of Eratosthenes. Zeros are mapped to prime elements.
		for(int prime = 2; prime < 317; prime++) //317 is sqrt(100,000)
		{	for(int a = prime + prime; a < 100000; a += prime) {sieve[a] = 1;}
		}
		
		int functions_read_bookmark  = 0;
		int functions_write_bookmark = 0;
		for(int a = 0; a < 10080; a++) //50,400/5 = 10,080 total 5-digit primes.
		{	//Unloads 5 array elements to make one integer.
			int temp_5_digit_prime;
			temp_5_digit_prime  = functions[functions_read_bookmark    ]; if(temp_5_digit_prime == 0) {temp_5_digit_prime++;} temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 1]; temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 2]; temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 3]; temp_5_digit_prime *= 10;
			temp_5_digit_prime += functions[functions_read_bookmark + 4];
			
			//Adjusts temp_5_digit_prime for primality (tests & searches in pos dir.) If length > 5, sets to largest 5-digit prime.
			while(sieve[temp_5_digit_prime] == 1)
			{	if(temp_5_digit_prime > 99991) {temp_5_digit_prime = 99991; break;}
				temp_5_digit_prime++;
			}
			
			//Writes the prime to functions[].
			functions[functions_write_bookmark + 4] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark + 3] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark + 2] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark + 1] = (temp_5_digit_prime % 10); temp_5_digit_prime /= 10;
			functions[functions_write_bookmark    ] =  temp_5_digit_prime;
			
			functions_read_bookmark  += 5;
			functions_write_bookmark += 5;
		}
		
		//Encrypts 1,008 plaintext to make the functions.
		char garbage_byte;
		functions_write_bookmark = 0;
		keys_read_bookmark = 0;
		unsigned char actual_key[50] = {0};
		int secondary_seeds_read_bookmark = 0;
		for(int a = 0; a < 1008; a++) //Generates random numbers in array actual_key[].
		{	for(int b = 0; b < 1000; b++) //Constructively applies randomness based on keys[] (used as seeds, 1,000 items per actual_key[].)
			{	srand(keys[keys_read_bookmark]);
				
				if((keys[keys_read_bookmark] % 2) == 0)
				{	for(int c = 0; c < 50; c++) //Fills left to right based on seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				else
				{	for(int c = 49; c >= 0; c--) //Fills right to left based on seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				
				keys_read_bookmark++;
			}
			
			//Further transforms actual_key[] based on secondary_seeds[].
			for(int b = 0; b < 100; b++) //Constructively applies randomness based on secondary_seeds[] (used as seeds, 100 11-digit integer per actual_key[].)
			{	srand(secondary_seeds[secondary_seeds_read_bookmark]);
				
				if((secondary_seeds[secondary_seeds_read_bookmark] % 2) == 0)
				{	for(int c = 0; c < 50; c++) //Fills left to right based on SECONDARY seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				else
				{	for(int c = 49; c >= 0; c--) //Fills right to left based on SECONDARY seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				
				secondary_seeds_read_bookmark++;
			}
			
			//Layers encryption by again transforming actual_key[] using sha256sum AND sha512sum of key.
			out_stream.open("temp");
			keys_read_bookmark -= 1000;
			for(int b = 0; b < 1000; b++) {out_stream.put(keys[keys_read_bookmark + b]);}
			keys_read_bookmark += 1000;
			out_stream.close();
			
			system("sha512sum temp > temp_512");
			system("sha256sum temp > temp_256");
			
			in_stream.open("temp_256");
			for(int b = 0; b < 50; b++)
			{	in_stream.get(garbage_byte);
				actual_key[b] += garbage_byte;
				actual_key[b] %= 95;
			}
			in_stream.close();
			
			in_stream.open("temp_512");
			for(int b = 0; b < 50; b++)
			{	in_stream.get(garbage_byte);
				actual_key[b] += garbage_byte;
				actual_key[b] %= 95;
			}
			in_stream.close();
			
			///Encrypts functions[] using actual_key[].
			for(int b = 0; b < 50; b++)
			{	functions[functions_write_bookmark] += actual_key[b];
				functions[functions_write_bookmark] %= 95;
				
				functions_write_bookmark++;
			}
			
			//Resetting actual key. If not reset (in option 3) then string depends on keys not present.
			for(int a = 0; a < 50; a++) {actual_key[a] = 0;}
		}
		
		//Creates sha512sum of only the first 512 functions.
		out_stream.open("temp");
		for(int a = 0; a <  25600; a++) {out_stream.put(functions[a] + 32);}
		out_stream.close();
		
		system("sha512sum temp > temp_512");
		
		in_stream.open("temp_512");
		out_stream.open("new_number_and_message");
		for(int a = 0; a < 128; a++) {in_stream.get(garbage_byte); out_stream.put(garbage_byte);}
		in_stream.close();
		out_stream.close();
		
		remove("temp");
		remove("temp_256");
		remove("temp_512");
		
		//Writes functions and keys to file Authorship.private.
		out_stream.open("Authorship.private");
		out_stream << "DO NOT PUBLISH! Authorship.private v7.0.0=\r\n\r\n"; //46-byte header must be. Use "\r\n" for all returns (for max compatibility.)
		for(int a = 0; a <  25600; a++) {out_stream.put(functions[a] + 32);} out_stream << "\r\n";
		for(int a = 0; a < 512000; a++) {out_stream.put(keys     [a] + 32);}
		out_stream.close();
		
		//Overwrites RAM of arrays: unsigned int user_seeds[50] and unsigned char actual_key[50].
		for(int a = 0; a < 50; a++)
		{	user_seeds[a] = 0; user_seeds[a] = 12345678; user_seeds[a] = 87654321; user_seeds[a] = 99999999;
			actual_key[a] = 0; actual_key[a] = 255;
		}
		
		//Overwrites RAM of array: unsigned char keys[1008000].
		for(int a = 0; a < 1008000; a++) {keys[a] = 0; keys[a] = 255;}
		
		
		
		
		
		//Prints number and gets the user's message.
		cout << "\nEnter a message to be authenticated (9k char max) else press enter:\n\n";
		char nothing_to_see_here[1]; //Catching cached new line. GNU+Linux does not perform auto-clearing of char input, the "enter" you pressed just
		cin.getline(nothing_to_see_here, 1); //before this is eaten by the next available cin.getline(), in this case--by variable nothing_to_see_here.
		
		char message[10000] = {'\0'}; //Now that the new line is caught, message[] can safely eat actual typed characters.
		cin.getline(message, 10000);  //Init to '\0' sets remaining to null, this line will not do that on its own after input!
		message[9000] = '\0';
		
		//Creates hash of message and new_number, where the hash is composed of 256 0 bits and 256 1 bits.
		//Appends user message to number first.
		if(message[0] != '\0')
		{	out_stream.open("new_number_and_message", ios::app);
			out_stream << " Message: ";
			for(int a = 0; message[a] != '\0'; a++) {out_stream << message[a];}
			out_stream.close();
		}
		
		out_stream.open("new_number_and_message", ios::app);
		out_stream << char(226) << char(150) << char(136);
		out_stream.close();
		
		for(;;)
		{	system("sha512sum new_number_and_message > distributed_hash");
			
			int zeros_counter = 0;
			in_stream.open("distributed_hash");
			for(int a = 0; a < 128; a++)
			{	in_stream.get(garbage_byte);
				if     (garbage_byte == '0') {zeros_counter += 4;} //hex 0 consists of 4 0 bits, and so on.
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
				else                         {cout << "\n\nError_d\n\n"; in_stream.close(); return 0;}
			}
			in_stream.close();
			
			if(zeros_counter == 256) {break;}
			
			out_stream.open("new_number_and_message", ios::app);
			out_stream << 0; //# of zeros appended is # of tries to find the distributed hash.
			out_stream.close();
		}
		
		//Sets b[] (binary) based on bits of distributed hash.
		bool b[512];
		int i = 0;
		in_stream.open("distributed_hash");
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
			
			else {cout << "\n\nError_d2\n\n"; in_stream.close(); return 0;}
			
			i += 4;
		}
		in_stream.close();
		
		//Creates file Authorship.public, writes all old functions, and selectively writes old keys.
		//In this file, you'll see two columns. Left one is all functions, and the right one--keys to the corresponding functions.
		int old_functions_read_bookmark = 0;
		int old_keys_read_bookmark = 0;
		
		out_stream.open("Authorship.public");
		out_stream << "Authorship.public v7.0.0=\r\n\r\n"; //29-byte header must be. Use "\r\n" for all returns (for max compatibility.)
		for(int a = 0; a < 512; a++)
		{	//Writes function.
			for(int b = 0; b < 50; b++)
			{	out_stream.put(old_functions[old_functions_read_bookmark]);
				old_functions_read_bookmark++;
			}
			
			///Writes key if b[] == 1.
			if(b[a] == 1)
			{	out_stream.put(' ');
				for(int b = 0; b < 1000; b++)
				{	out_stream.put(old_keys[old_keys_read_bookmark]);
					old_keys_read_bookmark++;
				}
				
				out_stream << "\r\n";
			}
			else
			{	//###################################################
				//##=`                                           `=##
				            old_keys_read_bookmark += 1000;        //
				//##=_                                           _=##
				//###################################################
				
				
				out_stream << "\r\n";
			}
		}
		
		out_stream << "\r\n";
		out_stream << char(226) << char(150) << char(136);
		in_stream.open("new_number_and_message");
		in_stream.get(garbage_byte);
		for(; in_stream.eof() == false;) {out_stream.put(garbage_byte); in_stream.get(garbage_byte);}
		in_stream.close();
		out_stream << "\r\n";
		
		out_stream.close();
		
		remove("new_number_and_message");
		remove("distributed_hash");
		
		//Overwrites RAM of array: (signed) char old_keys[1008000].
		for(int a = 0; a < 1008000; a++) {old_keys[a] = 0; old_keys[a] = -1;}
		
		cout << "\nAuthorship.private is updated, cache it guardedly and destroy the old copy.\n"
		     << "Publish Authorship.public. Once verified the file needs not exist anywhere.";
	}
	
	
	
	
	
	//_____________________________________________________________________________________________________________________
	//_____________________________________________VERIFY_NUMBER_MODIFICATION_____________________________________________/
	else if(user_option == 3)
	{	/* Basic layout:
		
		1. Compares sha512sum hash of functions to the number in the number file.
		2. Solves functions to which keys are present. Ensures 256 of 512 are solved.
		   Resulting presence & absence of keys represents a sha512sum of a new # & message.
		   So, the new # & message are independently hashed and compared to the hash represented.
		3. If hash match, overwrites Authorship.number with the new number--the sha512sum of another function list not yet public. */
		
		//Checks if BOTH files Authorship.number and Authorship.public are present.
		bool presence_of_file_Authorship_number = false;
		bool presence_of_file_Authorship_public = false;
		in_stream.open("Authorship.number"); if(in_stream.fail() == false) {presence_of_file_Authorship_number = true;} in_stream.close();
		in_stream.open("Authorship.public"); if(in_stream.fail() == false) {presence_of_file_Authorship_public = true;} in_stream.close();
		if((presence_of_file_Authorship_number == false)
		&& (presence_of_file_Authorship_public == false))
		{	cout << "\nBoth files are missing. If this is an executable file running in the terminal,\n"
			     << "its effectiveness-directory is the user folder, for example: /home/nikolay\n";
			return 0;
		}
		if(presence_of_file_Authorship_number == false)
		{	cout << "\nAuthorship.number is missing. If this is an executable file running in the\n"
			     << "terminal, its effectiveness-directory is the user folder such as /home/nikolay\n";
			return 0;
		}
		if(presence_of_file_Authorship_public == false)
		{	cout << "\nAuthorship.public is missing. If this is an executable file running in the\n"
			     << "terminal, its effectiveness-directory is the user folder such as /home/nikolay\n";
			return 0;
		}
		
		//Checks if BOTH files Authorship.number and Authorship.public are empty.
		bool existence_of_substance_in_file_Authorship_number = false;
		bool existence_of_substance_in_file_Authorship_public = false;
		char sniffed_one_file_character;
		
		in_stream.open("Authorship.number");
		in_stream.get(sniffed_one_file_character);
		if(in_stream.eof() == false) {existence_of_substance_in_file_Authorship_number = true;}
		in_stream.close();
		in_stream.open("Authorship.public");
		in_stream.get(sniffed_one_file_character);
		if(in_stream.eof() == false) {existence_of_substance_in_file_Authorship_public = true;}
		in_stream.close();
		
		if((existence_of_substance_in_file_Authorship_number == false)
		&& (existence_of_substance_in_file_Authorship_public == false))
		{	cout << "\nBoth files are empty.\n";
			return 0;
		}
		if(existence_of_substance_in_file_Authorship_number == false) {cout << "\nAuthorship.number is empty.\n"; return 0;}
		if(existence_of_substance_in_file_Authorship_public == false) {cout << "\nAuthorship.public is empty.\n"; return 0;}
		
		//Loads file Authorship.public and places functions and keys in different batches.
		char functions[ 25600]; //512 50-character functions.
		char keys     [256000]; //256,000 = (256 of 512 present keys * 1,000 characters in length).
		int functions_write_bookmark = 0;
		int keys_write_bookmark = 0;
		bool b[512] = {0}; //b for binary, logs presence and absence of keys.
		
		in_stream.open("Authorship.public");
		bool presence_of_13 = false;
		bool presence_of_10 = false;
		bool presence_of_13_and_10 = false;
		char temp_file_byte; for(int a = 0; a < 25; a++) {in_stream.get(temp_file_byte);} //Skips 29-byte header (29 if \r\n present, tests for it now.)
		
		for(int a = 0; a < 2; a++) //Grabs two bytes after the first equals sign in the text.
		{	in_stream.get(temp_file_byte);
			if(temp_file_byte == '\r') {presence_of_13 = true;}
			if(temp_file_byte == '\n') {presence_of_10 = true;}
		}
		
		if((presence_of_13 == false)
		&& (presence_of_10 == false)) {in_stream.close(); cout << "\n\nAuthorship.public header is corrupted.\n\n"; return 0;}
		
		if((presence_of_13 == true)
		&& (presence_of_10 == true))
		{	for(int a = 0; a < 2; a++) //Grabs two bytes after the first "\r\n".
			{	in_stream.get(temp_file_byte);
				if(temp_file_byte == '\r') {presence_of_13 = true;}
				if(temp_file_byte == '\n') {presence_of_10 = true;}
			}
			
			if((presence_of_13 == true)
			&& (presence_of_10 == true)) {presence_of_13_and_10 = true;}
			else {in_stream.close(); cout << "\n\nAuthorship.public header is corrupted.\n\n"; return 0;}
		}
		
		for(int a = 0; a < 512; a++) //Grabbing 768 items (512 functions + 256 keys.)
		{	//Gets function.
			for(int b = 0; b < 50; b++)
			{	in_stream.get(functions[functions_write_bookmark]);
				functions_write_bookmark++;
			}
			
			//Gets key if present.
			in_stream.get(temp_file_byte); //Checks what's after the function.
			if(temp_file_byte == ' ')
			{	b[a] = 1; //1 = key present.
				for(int c = 0; c < 1000; c++)
				{	in_stream.get(keys[keys_write_bookmark]);
					keys_write_bookmark++;
				}
				
				if(presence_of_13_and_10 == true) {in_stream.get(temp_file_byte);} //Skips '\r'.
				in_stream.get(temp_file_byte); //Skips '\n'.
			}
			else
			{	if(presence_of_13_and_10 == true) in_stream.get(temp_file_byte); //Skips '\n' from the "\r\n" after function.
			}
		}
		in_stream.close();
		
		//Adjusts functions[] and keys[].
		for(int a = 0; a <  25600; a++) {functions[a] -= 32;}
		for(int a = 0; a < 256000; a++) {     keys[a] -= 32;}
		
		//Creates sha512sum of only the first 512 functions.
		out_stream.open("temp");
		for(int a = 0; a <  25600; a++) {out_stream.put(functions[a] + 32);}
		out_stream.close();
		
		system("sha512sum temp > temp_512");
		
		//Compares the functions hash with the number on file--belonging to the modifying party.
		int number_on_file[128];
		char garbage_byte;
		
		in_stream.open("temp_512");
		for(int a = 0; a < 128; a++) {in_stream.get(garbage_byte); number_on_file[a] = garbage_byte;} //Loads new #.
		in_stream.close();
		
		in_stream.open("Authorship.number");
		for(int a = 0; a < 128; a++)
		{	in_stream.get(garbage_byte);
			if((number_on_file[a]) != garbage_byte)
			{	in_stream.close();
				cout << "\nFAILED! Number decompression did not produce the given public functions.\n";
				return 0;
			}
		}
		in_stream.close();
		
		//Generates additional seeds from keys[] for additional transformation of actual_key[] before decryption.
		long long secondary_seeds[25600] = {0}; //Assembles 100 (mostly 11-digit) seeds per key, from each of the 256 1,000-character keys.
		int keys_read_bookmark = 0;
		int secondary_seeds_write_bookmark = 0;
		for(int a = 0; a < 25600; a++) //25,600 comes from 10 contiguous key characters being scraped at once, 25,600 times.
		{	for(int b = 0; b < 10; b++)
			{	secondary_seeds[secondary_seeds_write_bookmark] *= 10;
				secondary_seeds[secondary_seeds_write_bookmark] += keys[keys_read_bookmark + b];
			}
			
			keys_read_bookmark += 10;
			secondary_seeds_write_bookmark++;
		}
		
		//Turns keys into actual keys.
		keys_read_bookmark  = 0;
		int write_back_actual_key_bookmark = 0;
		int secondary_seeds_read_bookmark  = 0;
		unsigned char actual_key[50] = {0};
		for(int a = 0; a < 256; a++) //Generates random numbers in array actual_key[].
		{	for(int b = 0; b < 1000; b++) //Constructively applies randomness based on keys[] (used as seeds, 1,000 items per actual_key[].)
			{	srand(keys[keys_read_bookmark]);
				
				if((keys[keys_read_bookmark] % 2) == 0)
				{	for(int c = 0; c < 50; c++) //Fills left to right based on seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				else
				{	for(int c = 49; c >= 0; c--) //Fills right to left based on seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				
				keys_read_bookmark++;
			}
			
			//Further transforms actual_key[] based on secondary_seeds[].
			for(int b = 0; b < 100; b++) //Constructively applies randomness based on secondary_seeds[] (used as seeds, 100 11-digit integer per actual_key[].)
			{	srand(secondary_seeds[secondary_seeds_read_bookmark]);
				
				if((secondary_seeds[secondary_seeds_read_bookmark] % 2) == 0)
				{	for(int c = 0; c < 50; c++) //Fills left to right based on SECONDARY seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				else
				{	for(int c = 49; c >= 0; c--) //Fills right to left based on SECONDARY seeds.
					{	actual_key[c] += (rand() % 95);
						actual_key[c] %= 95;
					}
				}
				
				secondary_seeds_read_bookmark++;
			}
			
			//Layers encryption by again transforming actual_key[] using sha256sum AND sha512sum of key.
			out_stream.open("temp");
			keys_read_bookmark -= 1000;
			for(int b = 0; b < 1000; b++) {out_stream.put(keys[keys_read_bookmark + b]);}
			keys_read_bookmark += 1000;
			out_stream.close();
			
			system("sha512sum temp > temp_512");
			system("sha256sum temp > temp_256");
			
			in_stream.open("temp_256");
			for(int b = 0; b < 50; b++)
			{	in_stream.get(garbage_byte);
				actual_key[b] += garbage_byte;
				actual_key[b] %= 95;
			}
			in_stream.close();
			
			in_stream.open("temp_512");
			for(int b = 0; b < 50; b++)
			{	in_stream.get(garbage_byte);
				actual_key[b] += garbage_byte;
				actual_key[b] %= 95;
			}
			in_stream.close();
			
			//Writes the result back to keys[]. Only in Authorship option 3, the first 28,000 elements of keys[] is reused for temporary write-back of actual_key[].
			for(int d = 0; d < 50; d++)
			{	keys[write_back_actual_key_bookmark] = actual_key[d];
				write_back_actual_key_bookmark++;
			}
			
			//Resetting actual key. If not reset (in option 3) then string depends on keys not present.
			for(int a = 0; a < 50; a++) {actual_key[a] = 0;}
		}
		
		remove("temp");
		remove("temp_256");
		remove("temp_512");
		
		//Decrypts 256 functions.
		keys_read_bookmark = 0;
		int functions_read_write_bookmark = 0;
		for(int a = 0; a < 512; a++)
		{	if(b[a] == 1)
			{	/*   ______________________________________________ ________________________________________________
				    |                                              |                                                |
				    |              if key <= ciphertext            |                     else                       |
				    |      then plaintext = (ciphertext - key)     |      plaintext = ((95 - key) + ciphertext)     |
				    |______________________________________________|________________________________________________|
				*/
				for(int b = 0; b < 50; b++)
				{	if(keys[keys_read_bookmark] <= functions[functions_read_write_bookmark])
					{	functions[functions_read_write_bookmark] = (functions[functions_read_write_bookmark] - keys[keys_read_bookmark]);
						
						//Checks if extracted plaintext is one digit. Never exceeds 99,999 upon later reconstruction from 5 elements.
						if(functions[functions_read_write_bookmark] > 9)
						{	cout << "\nFailed! Plaintext properties don't satisfy search priorities.\n";
							return 0;
						}
					}
					else
					{	functions[functions_read_write_bookmark] = ((95 - keys[keys_read_bookmark]) + functions[functions_read_write_bookmark]);
						
						//Checks if extracted plaintext is one digit. Never exceeds 99,999 upon later reconstruction from 5 elements.
						if(functions[functions_read_write_bookmark] > 9)
						{	cout << "\nFailed! Plaintext properties don't satisfy search priorities.\n";
							return 0;
						}
					}
					
					keys_read_bookmark++;
					functions_read_write_bookmark++;
				}
			}
			else
			{	//########################################################
				//##=`                                                `=##
				            functions_read_write_bookmark += 50;        //
				//##= _                                               _=##
				//########################################################
			}
		}
		
		//Checks if solved functions contain 10 unspecified 5-digit contiguous primes.
		//This means solutions are not mathematically inherent to a function hence no reversal shortcuts.
		bool sieve[100000] = {1, 1}; //Boolean sieve of Eratosthenes. Zeros are mapped to prime elements.
		for(int prime = 2; prime < 317; prime++) //317 is sqrt(100,000)
		{	for(int a = prime + prime; a < 100000; a += prime) {sieve[a] = 1;}
		}
		
		int functions_read_bookmark = 0;
		int search_priority_satisfaction = false;
		int solved_counter = 0;
		for(int a = 0; a < 512; a++) //10 5-digit primes per function, 560 functions solved.
		{	if(b[a] == 1)
			{	for(int b = 0; b < 10; b++)
				{	//Unloads 5 array elements to make one integer.
					int five_digit_prime;
					five_digit_prime  = functions[functions_read_bookmark    ]; five_digit_prime *= 10;
					five_digit_prime += functions[functions_read_bookmark + 1]; five_digit_prime *= 10;
					five_digit_prime += functions[functions_read_bookmark + 2]; five_digit_prime *= 10;
					five_digit_prime += functions[functions_read_bookmark + 3]; five_digit_prime *= 10;
					five_digit_prime += functions[functions_read_bookmark + 4];
					
					//Tests for primality.
					if((five_digit_prime < 10007)
					|| (sieve[five_digit_prime] != 0))
					{	cout << "\nFailed! Plaintext properties don't satisfy search priorities.\n";
						return 0;
					}
					
					functions_read_bookmark  += 5;
				}
				
				solved_counter++;
			}
			else
			{	//###################################################
				//##=`                                           `=##
				            functions_read_bookmark += 50;         //
				//##=_                                           _=##
				//###################################################
			}
			
			search_priority_satisfaction++; //Must run 1,008 times.
		}
		
		if((search_priority_satisfaction != 512) || (solved_counter != 256))
		{	cout << "\nFAILED! Could not test 256 of 512 functions.\n";
			return 0;
		}
		
		//Extracts hash from the presence and absence of successful keys.
		int symbolism[128];
		int i = 0;
		for(int a = 0; a < 128; a++)
		{	
			//               |                  |                  |                  |
			if     ((b[i] == 0) && (b[i + 1] == 0) && (b[i + 2] == 0) && (b[i + 3] == 0)) {symbolism[a] = '0';}
			else if((b[i] == 0) && (b[i + 1] == 0) && (b[i + 2] == 0) && (b[i + 3] == 1)) {symbolism[a] = '1';}
			else if((b[i] == 0) && (b[i + 1] == 0) && (b[i + 2] == 1) && (b[i + 3] == 0)) {symbolism[a] = '2';}
			else if((b[i] == 0) && (b[i + 1] == 0) && (b[i + 2] == 1) && (b[i + 3] == 1)) {symbolism[a] = '3';}
			//               |                  |                  |                  |
			else if((b[i] == 0) && (b[i + 1] == 1) && (b[i + 2] == 0) && (b[i + 3] == 0)) {symbolism[a] = '4';}
			else if((b[i] == 0) && (b[i + 1] == 1) && (b[i + 2] == 0) && (b[i + 3] == 1)) {symbolism[a] = '5';}
			else if((b[i] == 0) && (b[i + 1] == 1) && (b[i + 2] == 1) && (b[i + 3] == 0)) {symbolism[a] = '6';}
			else if((b[i] == 0) && (b[i + 1] == 1) && (b[i + 2] == 1) && (b[i + 3] == 1)) {symbolism[a] = '7';}
			//               |                  |                  |                  |
			else if((b[i] == 1) && (b[i + 1] == 0) && (b[i + 2] == 0) && (b[i + 3] == 0)) {symbolism[a] = '8';}
			else if((b[i] == 1) && (b[i + 1] == 0) && (b[i + 2] == 0) && (b[i + 3] == 1)) {symbolism[a] = '9';}
			else if((b[i] == 1) && (b[i + 1] == 0) && (b[i + 2] == 1) && (b[i + 3] == 0)) {symbolism[a] = 'a';}
			else if((b[i] == 1) && (b[i + 1] == 0) && (b[i + 2] == 1) && (b[i + 3] == 1)) {symbolism[a] = 'b';}
			//               |                  |                  |                  |
			else if((b[i] == 1) && (b[i + 1] == 1) && (b[i + 2] == 0) && (b[i + 3] == 0)) {symbolism[a] = 'c';}
			else if((b[i] == 1) && (b[i + 1] == 1) && (b[i + 2] == 0) && (b[i + 3] == 1)) {symbolism[a] = 'd';}
			else if((b[i] == 1) && (b[i + 1] == 1) && (b[i + 2] == 1) && (b[i + 3] == 0)) {symbolism[a] = 'e';}
			else if((b[i] == 1) && (b[i + 1] == 1) && (b[i + 2] == 1) && (b[i + 3] == 1)) {symbolism[a] = 'f';}
			//               |                  |                  |                  |
			
			else {cout << "\n\nError e1"; return 0;}
			
			i += 4;
		}
		
		//Copies new # & message from public file, to temp file.
		in_stream.open("Authorship.public");
		out_stream.open("temp_extracted");
		in_stream.get(garbage_byte);
		for(; garbage_byte != -120;) {in_stream.get(garbage_byte);} //Skips until new #.
		for(; in_stream.eof() == false;)
		{	in_stream.get(garbage_byte);
			if((garbage_byte == '\r') || (garbage_byte == '\n')) {break;}
			out_stream.put(garbage_byte);
		}
		out_stream.close();
		in_stream.close();
		
		//Checks if hash of included # & message is what's represented by the presence and absence of successful keys.
		system("sha512sum temp_extracted > temp_extracted_512");
		in_stream.open("temp_extracted_512");
		for(int a = 0; a < 128; a++)
		{	in_stream.get(garbage_byte);
			if(garbage_byte != char(symbolism[a])) {cout << "\n\nFailed! Appended data cannot be authenticated."; in_stream.close(); return 0;}
		}
		in_stream.close();
		
		//Updating file Authorship.number.
		in_stream.open("temp_extracted");
		out_stream.open("Authorship.number");
		for(int a = 0; a < 128; a++) {in_stream.get(garbage_byte); out_stream.put(garbage_byte);}
		bool existence_of_message = false;
		in_stream.get(garbage_byte);
		if(garbage_byte == ' ') {existence_of_message = true;}
		out_stream.close();
		in_stream.close();
		
		cout << "\n\n\tVerification SUCCESSFUL!\n\n"
		
		     << "The number file has been overwritten with their new number.\n"
		     << "You can discard any and all old modification information.\n";
		
		if(existence_of_message == true) {cout << "The user INCLUDED a message for this authentication event. \n";}
		else                             {cout << "The user omitted a message for this authentication event.\n";}
		
		//Creates file for message.
		if(existence_of_message == true)
		{	//138
			in_stream.open("temp_extracted");
			out_stream.open("MESSAGE");
			for(int a = 0; a < 138; a++) {in_stream.get(garbage_byte);}
			for(; in_stream.eof() == false;)
			{	in_stream.get(garbage_byte);
				if(garbage_byte == -30) {break;}
				out_stream.put(garbage_byte);
			}
			out_stream.close();
			in_stream.close();
		}
		
		remove("temp_extracted");
		remove("temp_extracted_512");
	}
	
	else {cout << "\nInvalid option, program ended.\n"; return 0;}
}
