/// Authorship - infinite authentication tool.
/// Nikolay Valentinovich Repnitskiy - License: WTFPLv2+ (wtfpl.net)


/* Version 4.2, 12k-digit multi-way functions. This is computational difficulty
and super-flexibility in endless cryptographic evidence. In literal terminology:
publicly-verifiable authorized-only number modification. Designed for  1+GB RAM.
Please flip through the nine-pager on   github.com/compromise-evident/Authorship
You can generate and publish a personal Authorship number, preferably before you
are subject to censorship or worse. This way the public can trust its ownership.
Once you become a governmental threat, the public inquires about your well being
after which--you modify your number. Given that only you can modify your number,
and given that the public or verifying party is here-given the ability to verify
your modification,  we can rest assured that any further correspondence from you
is not impersonation. Additionally you can insert data, messages, links, or hash
for every authentication event meaning information source can be trusted. Uses:
-------------------------------------------------------------------------------
 * Proof of life.
 * User authentication.
 * Canary update authentication.
 * Data, author, and version control authentication.
 * Unretentive suspend-able untraceable anonymous cryptocurrency
   (publicly-verifiable authorized-only withdrawal/ownership hand-over.)
 * Untraceable anonymous fair trade over any network
   (cryptographic solution to the Prisoner’s Dilemma.)
 * Group and military authorization.
 * Animal theft management.
 * Voter fraud prevention.
--------------------------------------------------------------------------------
Authorship.number   (Storage for another user's  Authorship number,       1.0 kB
                    it will update automatically as they publish.)
Authorship.public   (Number modification information meant to be       ~138.1 MB
                    published. This file will construct a new number.)
Authorship.private  (*SENSITIVE* Dynamic storage for your Authorship   ~243.2 MB
                    info & keys. This produces Authorship.public.)
--------------------------------------------------------------------------------
How to run the program  -  Software package repositories for GNU+Linux operating
systems have all the tools you can imagine. Open a terminal and use this command
as root to install Geany and g++ on your computer: apt install geany g++   Geany
is a fast & lightweight text editor and Integrated Development Environment where
you can write and run code. g++ is the GNU compiler for C++ which allows written
code to run. The compiler operates in the background and displays errors in your
code as you will see in the lower Geany box. Make a new folder somewhere on your
machine. Paste this code into Geany. For clarity in auditing, enable indentation
guides: go to View >> Show Indentation Guides. Save the document as anything.cpp
within the newly-created folder. Use these shortcuts to run the program: F9, F5.
You may paste over this code with other  .cpp files, or open a new tab & repeat.
--------------------------------------------------------------------------------
How to make an executable with g++  -  Save this program as anything.cpp, open a
terminal, and type g++ then space. Drag & drop this saved file into the terminal
and its directory will be  appended to your pending entry. Click on the terminal
and press enter.   a.out now resides in the user directory, you may rename it to
anything.  To run that executable, simply drag and drop it into a terminal, then
click on the terminal and press enter.  Reminder:  executable's effect-directory
is the user directory on your machine, for example:  /home/nikolay    Enjoy. */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	int user_option;
	
	cout << "\n(Authorship) - infinite authentication tool\n\n"
	
	     << " (1) Get Authorship number\n"
	     << "        (Generates your first number. This option is\n"
	     << "         used once, unless you know what you’re doing.)\n\n"
	
	     << " (2) Modify Authorship number\n"
	     << "        (Generates your new number. Your old number is then modified to\n"
	     << "         represent this new one, as well as any message of your choice.)\n\n"
	
	     << " (3) Verify number modification\n"
	     << "        (Generates their new number & message using their published file.\n"
	     << "         This file's function-compression must match their old number.)\n\n"
	
	     << "Enter option: ";
	
	cin >> user_option; //You can run all three ifs holding options  1, 2, and 3 in isolation from one another (self-sustained.)
	if((user_option != 1) && (user_option != 2) && (user_option != 3)) {cout << "\nInvalid, program ended.\n"; return 0;}
	
	
	
	
	
	//________________________________________________________________________________________________________________________
	//                                                                                                                       |
	//                                           1   Get Authorship number                                                   |
	//_______________________________________________________________________________________________________________________|
	if(user_option == 1)
	{	ifstream in_stream;
		ofstream out_stream;
		
		//The following block-bunch generates random numbers in array Authorship_private[].
		cout << "\n>>>>>>>>>>>>>>>>>>>>>>>(Get your first Authorship number)<<<<<<<<<<<<<<<<<<<<<<<\n"
		     << "Enter 8 random digits, repeat 50 times. (Get 243MB worth of keys in 20 minutes.)\n\n";
		
		unsigned int user_seed[50]; //Fills user_seed with 50 user-defined seeds of size 8.
		for(int a = 0; a < 50; a++)
		{	if(a < 9) {cout << " " << (a + 1) << " of 50: ";} //Prints blank to align input status report (aesthetics.)
			else {cout << (a + 1) << " of 50: ";}
			
			cin >> user_seed[a];
		} //CAUTION: "cin" must exist last, just before the rest of the computation-heavy program begins,
		//otherwise some things may not be printed and INPUT STREAMS CAN BE SKIPPED such as cin.getline() (see option 2.)
		//Be extra careful when changing order of user inputs here. The old compiler and hardware used for this build
		//seems to require all of these sub-optimal methods in order to actually get input, as well as save on memory.
		//(It's important to build sensitive software as such on the worst possible machines as this will run on such
		//machines elsewhere in the world. Plus, cheap disposable machines like that give you connectivity control
		//as you can easily strip wifi cards and other sensors.)
		
		
		
		
		
		static char Authorship_private[256500000]; //This array is filled with random digits then read from and written to left to right
		cout << "\n\n\n\n\nGenerating randomness...\n";
		//dynamically to save RAM space. It provides random digit input and temporary key storage (to be written to file: Authorship.private.)
		int read_bookmark = 1000000;  //Bookmarks where to read next from Authorship_private[]. Initial size Prevents read/write collision.
		int write_bookmark = 0; //Bookmarks where to write next in Authorship_private[].
		//(Function generation extracts random numbers using read/write bookmarks. Authorship_private[] is first filled with random numbers normally.)
		
		for(int a = 0; a < 50; a++) //Generates a random location (+10^6) for where to read from Authorship_private[]. This step prevents bookmark
		{	read_bookmark += (user_seed[a] % 10000); //collision and adds to the randomness strength. Average total value for read_bookmark: 1,250,000.
		} //The last item in the for loop who generates 13,500 multi-way functions deals with collision again, allowing bookmark proximity of ~30,000.
		
		srand(time(0));
		for(int a = 256499999; a >= 0; a--) //Fills Authorship_private[] with random numbers based on Unix time. WRITES RIGHT TO LEFT.
		{	Authorship_private[a] = (rand() % 10);
		}
		
		for(int a = 0; a < 50; a++) //Constructively applies random digits to Authorship_private[] based on the 50 seeds provided by the user.
		{	srand(user_seed[a]);    //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 50 user seeds.
			
			if((user_seed[a] % 2) == 0)
			{	for(int b = 0; b < 256500000; b++) //WRITES LEFT TO RIGHT.
				{	Authorship_private[b] = (Authorship_private[b] + (rand() % 10));
					Authorship_private[b] %= 10;
				}
			}
			else
			{	for(int b = 256499999; b >= 0; b--) //WRITES RIGHT TO LEFT.
				{	Authorship_private[b] = (Authorship_private[b] + (rand() % 10));
					Authorship_private[b] %= 10;
				}
			}
		}
		
		srand(time(0)); //Constructively applies random numbers to Authorship_private[] once more, based on Unix time. WRITES LEFT TO RIGHT.
		for(int a = 0; a < 256500000; a++)
		{	Authorship_private[a] = (Authorship_private[a] + (rand() % 10));
			Authorship_private[a] %= 10;
		}
		
		
		
		
		
		//These declarations are for deductive lossy compression, they produce the Authorship number dynamically.
		//See the compression block-bunch near the end of the following for loop who generates 13,500 functions.
		long long int compression_115[100]; //Hops by -115
		long long int    snapshot_115[100]; //Takes a snapshot of compression_115[] every once in a while.
		
		long long int compression_116[100]; //Hops by -116
		long long int    snapshot_116[100]; //Takes a snapshot of compression_116[] every once in a while.
		
		long long int compression_117[100]; //Hops by -117
		long long int    snapshot_117[100]; //Takes a snapshot of compression_117[] every once in a while.
		
		long long int compression_118[100]; //Hops by -118
		long long int    snapshot_118[100]; //Takes a snapshot of compression_118[] every once in a while.
		
		long long int compression_119[100]; //Hops by -119
		long long int    snapshot_119[100]; //Takes a snapshot of compression_119[] every once in a while.
		
		for(int a = 0; a < 100; a++)
		{	compression_115[a] = 5555555555;	snapshot_115[a] = 5555555555;
			compression_116[a] = 5555555555;	snapshot_116[a] = 5555555555;
			compression_117[a] = 5555555555;	snapshot_117[a] = 5555555555;
			compression_118[a] = 5555555555;	snapshot_118[a] = 5555555555;
			compression_119[a] = 5555555555;	snapshot_119[a] = 5555555555;
		}
		
		//This is a boolean sieve of Eratosthenes. Zeros are prime, conveniently mapped to their element index. (It is used here like the following
		//example: if(sieve[my_candidate] == 0) then my_candidate is prime. Otherwise, my_candidate is increased until it is prime. This adjusts
		//my_candidate for primality in the positive direction.) And values over 99 for 2-digit primes for example are set to the largest prime < 100.)
		bool sieve[100000] = {1, 1};
		for(int prime = 2; prime < 317; prime++) //317 is sqrt(100000)
		{	for(int a = prime + prime; a < 100000; a += prime) {sieve[a] = 1;}
		}
		
		
		
		
		
		//The following for loop generates 13,500 multi-way functions in array Authorship_private[].
		cout << "Generating 13,500 multi-way functions...\n";
		for(int f = 0; f < 13500; f++)
		{	//The following block-bunch generates sub-function 1 for the current function. (Cool zone.)
			int transformation_determinant[2000];
			for(int a = 0; a < 2000; a++) //Fills transformation_determinant[] with random digits.
			{	transformation_determinant[a] = Authorship_private[read_bookmark];
				read_bookmark++;
			}
			
			long long assembled_seed_for_transformation[200] = {0}; //Prepares 200 10-digit seeds from transformation_determinant[]
			int transformation_determinant_read_bookmark = 0;       //for further key transformation.
			for(int a = 0; a < 200; a++)
			{	long long multiplier = 1000000000;
				for(int b = 0; b < 10; b++)
				{	assembled_seed_for_transformation[a] += (transformation_determinant[transformation_determinant_read_bookmark] * multiplier);
					transformation_determinant_read_bookmark++;
					multiplier /= 10;
				}
			}
			
			int sub_key[2000];
			int temp_sub_key[2000];
			for(int a = 0; a < 2000; a++) //Fills sub_key[] with random digits. This sub-key will be transformed and used dynamically.
			{	sub_key[a] = Authorship_private[read_bookmark];
				temp_sub_key[a] = Authorship_private[read_bookmark]; //Makes temp copy of sub-key so as to later append it near the current
				read_bookmark++;                                     //ciphertext when complete. (Written to Authorship_private[].)
			}                                                        //These kind of details prevent read/write_bookmark collision.
			
			for(int a = 0; a < 2000; a++) //Generates first sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += Authorship_private[read_bookmark];
				Authorship_private[write_bookmark] %= 10;
				read_bookmark++;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1999; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 2.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 1]) % 10); //[a + 1] means do up to 1998 or seg fault.
			}
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1000]) % 10); //Last element was not transformed so here it is.
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(1st of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 2 for the current function. (Hot zone.)
			int sub_plaintext_SUB2[2000];
			int prime_lengths_in_order_SUB2[1000]; //Expected contiguous primes: ~667.
			
			int length_sum_SUB2 = 0;
			int element_SUB2 = 0; //Begins writing to prime_lengths_in_order_SUB2[] from element 0 (basic counter.)
			while(length_sum_SUB2 < 2000)
			{	if(Authorship_private[read_bookmark] < 5) {	Authorship_private[read_bookmark]++;} //Reassigns (0=1,1=2,2=3,3=4,4=5.)
				else //Assigns 5 to: 1, 6 to: 2, 7 to: 3, 8 to: 4, and 9 to: 5. (All prime lengths must be 1-5.)
				{	Authorship_private[read_bookmark] += 16;
					Authorship_private[read_bookmark] %= 10; //Example: 7: (7+16) = 23, 23 mod 10 = 3. Seven is now 3.
				}
				
				length_sum_SUB2 += Authorship_private[read_bookmark];
				prime_lengths_in_order_SUB2[element_SUB2] = Authorship_private[read_bookmark]; //Prime lengths are recorded in
				element_SUB2++; //prime_lengths_in_order_SUB2[] so as to later append it near the current ciphertext when complete.
				read_bookmark++; //    ...(Written to Authorship_private[].)
			}
			
			element_SUB2--;
			if(length_sum_SUB2 > 2000) //Subtracts from last entry in prime_lengths_in_order_SUB2[] so as to ensure sum(entries) = 2,000.
			{	int overflow = (length_sum_SUB2 % 10);
				prime_lengths_in_order_SUB2[element_SUB2] -= overflow;
			}
			
			int write_bookmark_SUB2 = 0;
			for(int a = 0; a <= element_SUB2; a++) //Generates primes of corresponding length & writes them to sub_plaintext_SUB2[].
			{	if(prime_lengths_in_order_SUB2[a] == 1) //Randomly generates a single-digit prime.
				{	if(Authorship_private[read_bookmark] < 5)
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB2[write_bookmark_SUB2] = 2;} //The prime 2.
						else {sub_plaintext_SUB2[write_bookmark_SUB2] = 3;} //The prime 3.
					}
					
					else
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB2[write_bookmark_SUB2] = 5;} //The prime 5.
						else {sub_plaintext_SUB2[write_bookmark_SUB2] = 7;} //The prime 7.
					}
					
					write_bookmark_SUB2++;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 2) //Randomly generates a two-digit prime.
				{	int temp_2_digit_prime;
					temp_2_digit_prime = Authorship_private[read_bookmark]; //Unloads 2 array elements to make one integer.
					if(temp_2_digit_prime == 0) {temp_2_digit_prime++;}
					temp_2_digit_prime *= 10;
					temp_2_digit_prime += Authorship_private[read_bookmark + 1];
					
					while(sieve[temp_2_digit_prime] == 1) //Adjusts temp_2_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_2_digit_prime > 99) {temp_2_digit_prime = 97; break;} //If exceeds length of 2, sets it to largest 2-digit prime.
						temp_2_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_2_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_2_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_2_digit_prime;
					
					write_bookmark_SUB2 += 2;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 3) //Randomly generates a three-digit prime.
				{	int temp_3_digit_prime;
					temp_3_digit_prime = Authorship_private[read_bookmark]; //Unloads 3 array elements to make one integer.
					if(temp_3_digit_prime == 0) {temp_3_digit_prime++;}
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 1];
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 2];
					
					while(sieve[temp_3_digit_prime] == 1) //Adjusts temp_3_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_3_digit_prime > 999) {temp_3_digit_prime = 997; break;} //If exceeds length of 3, sets it to largest 3-digit prime.
						temp_3_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 2] = (temp_3_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_3_digit_prime % 10);
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_3_digit_prime;
					
					write_bookmark_SUB2 += 3;
					read_bookmark += 3;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 4) //Randomly generates a four-digit prime.
				{	int temp_4_digit_prime;
					temp_4_digit_prime = Authorship_private[read_bookmark]; //Unloads 4 array elements to make one integer.
					if(temp_4_digit_prime == 0) {temp_4_digit_prime++;}
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 1];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 2];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 3];
					
					while(sieve[temp_4_digit_prime] == 1) //Adjusts temp_4_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_4_digit_prime > 9999) {temp_4_digit_prime = 9973; break;} //If exceeds length of 4, sets it to largest 4-digit prime.
						temp_4_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 3] = (temp_4_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 2] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_4_digit_prime;
					
					write_bookmark_SUB2 += 4;
					read_bookmark += 4;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 5) //Randomly generates a five-digit prime.
				{	int temp_5_digit_prime;
					temp_5_digit_prime = Authorship_private[read_bookmark]; //Unloads 5 array elements to make one integer.
					if(temp_5_digit_prime == 0) {temp_5_digit_prime++;}
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 1];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 2];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 3];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 4];
					
					while(sieve[temp_5_digit_prime] == 1) //Adjusts temp_5_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_5_digit_prime > 99999) {temp_5_digit_prime = 99991; break;} //If exceeds length of 5, sets it to largest 5-digit prime.
						temp_5_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 4] = (temp_5_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 3] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 2] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_5_digit_prime;
					
					write_bookmark_SUB2 += 5;
					read_bookmark += 5;
					continue;
				}
			}
			
			for(int a = 0; a < 2000; a++) //Generates second sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += sub_plaintext_SUB2[a];
				Authorship_private[write_bookmark] %= 10;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1998; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 3.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 2]) % 10); //[a + 2] means do up to 1997 or seg fault.
			}
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1005]) % 10); //Last two elements were not transformed so here it is.
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1010]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(2nd of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 3 for the current function. (Cool zone.)
			for(int a = 0; a < 2000; a++) //Generates third sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += Authorship_private[read_bookmark];
				Authorship_private[write_bookmark] %= 10;
				read_bookmark++;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			
			for(int a = 0; a < 1997; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 4.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 3]) % 10); //[a + 3] means do up to 1996 or seg fault.
			}
			sub_key[1997] = ((sub_key[1997] + transformation_determinant[1015]) % 10); //Last three elements were not transformed so here it is.
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1020]) % 10);
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1025]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(3rd of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 4 for the current function. (Hot zone.)
			int sub_plaintext_SUB4[2000];
			int prime_lengths_in_order_SUB4[1000]; //Expected contiguous primes: ~667.
			
			int length_sum_SUB4 = 0;
			int element_SUB4 = 0; //Begins writing to prime_lengths_in_order_SUB4[] from element 0 (basic counter.)
			while(length_sum_SUB4 < 2000)
			{	if(Authorship_private[read_bookmark] < 5) {	Authorship_private[read_bookmark]++;} //Reassigns (0=1,1=2,2=3,3=4,4=5.)
				else //Assigns 5 to: 1, 6 to: 2, 7 to: 3, 8 to: 4, and 9 to: 5. (All prime lengths must be 1-5.)
				{	Authorship_private[read_bookmark] += 16;
					Authorship_private[read_bookmark] %= 10; //Example: 7: (7+16) = 23, 23 mod 10 = 3. Seven is now 3.
				}
				
				length_sum_SUB4 += Authorship_private[read_bookmark];
				prime_lengths_in_order_SUB4[element_SUB4] = Authorship_private[read_bookmark]; //Prime lengths are recorded in
				element_SUB4++; //prime_lengths_in_order_SUB4[] so as to later append it near the current ciphertext when complete.
				read_bookmark++; //    ...(Written to Authorship_private[].)
			}
			
			element_SUB4--;
			if(length_sum_SUB4 > 2000) //Subtracts from last entry in prime_lengths_in_order_SUB4[] so as to ensure sum(entries) = 2,000.
			{	int overflow = (length_sum_SUB4 % 10);
				prime_lengths_in_order_SUB4[element_SUB4] -= overflow;
			}
			
			int write_bookmark_SUB4 = 0;
			for(int a = 0; a <= element_SUB4; a++) //Generates primes of corresponding length & writes them to sub_plaintext_SUB4[].
			{	if(prime_lengths_in_order_SUB4[a] == 1) //Randomly generates a single-digit prime.
				{	if(Authorship_private[read_bookmark] < 5)
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB4[write_bookmark_SUB4] = 2;} //The prime 2.
						else {sub_plaintext_SUB4[write_bookmark_SUB4] = 3;} //The prime 3.
					}
					
					else
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB4[write_bookmark_SUB4] = 5;} //The prime 5.
						else {sub_plaintext_SUB4[write_bookmark_SUB4] = 7;} //The prime 7.
					}
					
					write_bookmark_SUB4++;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 2) //Randomly generates a two-digit prime.
				{	int temp_2_digit_prime;
					temp_2_digit_prime = Authorship_private[read_bookmark]; //Unloads 2 array elements to make one integer.
					if(temp_2_digit_prime == 0) {temp_2_digit_prime++;}
					temp_2_digit_prime *= 10;
					temp_2_digit_prime += Authorship_private[read_bookmark + 1];
					
					while(sieve[temp_2_digit_prime] == 1) //Adjusts temp_2_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_2_digit_prime > 99) {temp_2_digit_prime = 97; break;} //If exceeds length of 2, sets it to largest 2-digit prime.
						temp_2_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_2_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_2_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_2_digit_prime;
					
					write_bookmark_SUB4 += 2;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 3) //Randomly generates a three-digit prime.
				{	int temp_3_digit_prime;
					temp_3_digit_prime = Authorship_private[read_bookmark]; //Unloads 3 array elements to make one integer.
					if(temp_3_digit_prime == 0) {temp_3_digit_prime++;}
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 1];
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 2];
					
					while(sieve[temp_3_digit_prime] == 1) //Adjusts temp_3_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_3_digit_prime > 999) {temp_3_digit_prime = 997; break;} //If exceeds length of 3, sets it to largest 3-digit prime.
						temp_3_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 2] = (temp_3_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_3_digit_prime % 10);
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_3_digit_prime;
					
					write_bookmark_SUB4 += 3;
					read_bookmark += 3;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 4) //Randomly generates a four-digit prime.
				{	int temp_4_digit_prime;
					temp_4_digit_prime = Authorship_private[read_bookmark]; //Unloads 4 array elements to make one integer.
					if(temp_4_digit_prime == 0) {temp_4_digit_prime++;}
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 1];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 2];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 3];
					
					while(sieve[temp_4_digit_prime] == 1) //Adjusts temp_4_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_4_digit_prime > 9999) {temp_4_digit_prime = 9973; break;} //If exceeds length of 4, sets it to largest 4-digit prime.
						temp_4_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 3] = (temp_4_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 2] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_4_digit_prime;
					
					write_bookmark_SUB4 += 4;
					read_bookmark += 4;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 5) //Randomly generates a five-digit prime.
				{	int temp_5_digit_prime;
					temp_5_digit_prime = Authorship_private[read_bookmark]; //Unloads 5 array elements to make one integer.
					if(temp_5_digit_prime == 0) {temp_5_digit_prime++;}
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 1];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 2];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 3];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 4];
					
					while(sieve[temp_5_digit_prime] == 1) //Adjusts temp_5_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_5_digit_prime > 99999) {temp_5_digit_prime = 99991; break;} //If exceeds length of 5, sets it to largest 5-digit prime.
						temp_5_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 4] = (temp_5_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 3] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 2] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_5_digit_prime;
					
					write_bookmark_SUB4 += 5;
					read_bookmark += 5;
					continue;
				}
			}
			
			for(int a = 0; a < 2000; a++) //Generates fourth sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += sub_plaintext_SUB4[a];
				Authorship_private[write_bookmark] %= 10;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1996; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 5.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 4]) % 10); //[a + 4] means do up to 1995 or seg fault.
			}
			sub_key[1996] = ((sub_key[1996] + transformation_determinant[1030]) % 10); //Last four elements were not transformed so here it is.
			sub_key[1997] = ((sub_key[1997] + transformation_determinant[1035]) % 10);
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1040]) % 10);
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1045]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(4th of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 5 for the current function. (Cool zone.)
			for(int a = 0; a < 2000; a++) //Generates fifth sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += Authorship_private[read_bookmark];
				Authorship_private[write_bookmark] %= 10;
				read_bookmark++;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1995; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 6.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 5]) % 10); //[a + 5] means do up to 1994 or seg fault.
			}
			sub_key[1995] = ((sub_key[1995] + transformation_determinant[1050]) % 10); //Last five elements were not transformed so here it is.
			sub_key[1996] = ((sub_key[1996] + transformation_determinant[1055]) % 10);
			sub_key[1997] = ((sub_key[1997] + transformation_determinant[1060]) % 10);
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1065]) % 10);
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1070]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(5th of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 6 for the current function. (Hot zone.)
			int sub_plaintext_SUB6[2000];
			int prime_lengths_in_order_SUB6[1000]; //Expected contiguous primes: ~667.
			
			int length_sum_SUB6 = 0;
			int element_SUB6 = 0; //Begins writing to prime_lengths_in_order_SUB6[] from element 0 (basic counter.)
			while(length_sum_SUB6 < 2000)
			{	if(Authorship_private[read_bookmark] < 5) {	Authorship_private[read_bookmark]++;} //Reassigns (0=1,1=2,2=3,3=4,4=5.)
				else //Assigns 5 to: 1, 6 to: 2, 7 to: 3, 8 to: 4, and 9 to: 5. (All prime lengths must be 1-5.)
				{	Authorship_private[read_bookmark] += 16;
					Authorship_private[read_bookmark] %= 10; //Example: 7: (7+16) = 23, 23 mod 10 = 3. Seven is now 3.
				}
				
				length_sum_SUB6 += Authorship_private[read_bookmark];
				prime_lengths_in_order_SUB6[element_SUB6] = Authorship_private[read_bookmark]; //Prime lengths are recorded in
				element_SUB6++; //prime_lengths_in_order_SUB6[] so as to later append it near the current ciphertext when complete.
				read_bookmark++; //    ...(Written to Authorship_private[].)
			}
			
			element_SUB6--;
			if(length_sum_SUB6 > 2000) //Subtracts from last entry in prime_lengths_in_order_SUB6[] so as to ensure sum(entries) = 2,000.
			{	int overflow = (length_sum_SUB6 % 10);
				prime_lengths_in_order_SUB6[element_SUB6] -= overflow;
			}
			
			int write_bookmark_SUB6 = 0;
			for(int a = 0; a <= element_SUB6; a++) //Generates primes of corresponding length & writes them to sub_plaintext_SUB6[].
			{	if(prime_lengths_in_order_SUB6[a] == 1) //Randomly generates a single-digit prime.
				{	if(Authorship_private[read_bookmark] < 5)
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB6[write_bookmark_SUB6] = 2;} //The prime 2.
						else {sub_plaintext_SUB6[write_bookmark_SUB6] = 3;} //The prime 3.
					}
					
					else
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB6[write_bookmark_SUB6] = 5;} //The prime 5.
						else {sub_plaintext_SUB6[write_bookmark_SUB6] = 7;} //The prime 7.
					}
					
					write_bookmark_SUB6++;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 2) //Randomly generates a two-digit prime.
				{	int temp_2_digit_prime;
					temp_2_digit_prime = Authorship_private[read_bookmark]; //Unloads 2 array elements to make one integer.
					if(temp_2_digit_prime == 0) {temp_2_digit_prime++;}
					temp_2_digit_prime *= 10;
					temp_2_digit_prime += Authorship_private[read_bookmark + 1];
					
					while(sieve[temp_2_digit_prime] == 1) //Adjusts temp_2_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_2_digit_prime > 99) {temp_2_digit_prime = 97; break;} //If exceeds length of 2, sets it to largest 2-digit prime.
						temp_2_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_2_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_2_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_2_digit_prime;
					
					write_bookmark_SUB6 += 2;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 3) //Randomly generates a three-digit prime.
				{	int temp_3_digit_prime;
					temp_3_digit_prime = Authorship_private[read_bookmark]; //Unloads 3 array elements to make one integer.
					if(temp_3_digit_prime == 0) {temp_3_digit_prime++;}
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 1];
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 2];
					
					while(sieve[temp_3_digit_prime] == 1) //Adjusts temp_3_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_3_digit_prime > 999) {temp_3_digit_prime = 997; break;} //If exceeds length of 3, sets it to largest 3-digit prime.
						temp_3_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 2] = (temp_3_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_3_digit_prime % 10);
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_3_digit_prime;
					
					write_bookmark_SUB6 += 3;
					read_bookmark += 3;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 4) //Randomly generates a four-digit prime.
				{	int temp_4_digit_prime;
					temp_4_digit_prime = Authorship_private[read_bookmark]; //Unloads 4 array elements to make one integer.
					if(temp_4_digit_prime == 0) {temp_4_digit_prime++;}
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 1];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 2];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 3];
					
					while(sieve[temp_4_digit_prime] == 1) //Adjusts temp_4_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_4_digit_prime > 9999) {temp_4_digit_prime = 9973; break;} //If exceeds length of 4, sets it to largest 4-digit prime.
						temp_4_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 3] = (temp_4_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 2] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_4_digit_prime;
					
					write_bookmark_SUB6 += 4;
					read_bookmark += 4;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 5) //Randomly generates a five-digit prime.
				{	int temp_5_digit_prime;
					temp_5_digit_prime = Authorship_private[read_bookmark]; //Unloads 5 array elements to make one integer.
					if(temp_5_digit_prime == 0) {temp_5_digit_prime++;}
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 1];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 2];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 3];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 4];
					
					while(sieve[temp_5_digit_prime] == 1) //Adjusts temp_5_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_5_digit_prime > 99999) {temp_5_digit_prime = 99991; break;} //If exceeds length of 5, sets it to largest 5-digit prime.
						temp_5_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 4] = (temp_5_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 3] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 2] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_5_digit_prime;
					
					write_bookmark_SUB6 += 5;
					read_bookmark += 5;
					continue;
				}
			}
			
			for(int a = 0; a < 2000; a++) //Generates sixth sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += sub_plaintext_SUB6[a];
				Authorship_private[write_bookmark] %= 10;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			
			
			
			
			//The following block-bunch generates the Authorship number dynamically. (Its final form is then produced after the 13,500 functions.)
			//This sits here (just after the full function is written to array Authorship_private[]) because now temp_write_bookmark fingerprints the
			//function right to left so as to build the Authorship number. Then solution ingredients are appended to the current function.
			compression_119[0] += compression_119[99];
			compression_119[0] %= 10000000000;
			
			int temp_write_bookmark;
			temp_write_bookmark = (write_bookmark - 2);
			
			for(int a = 0; a < 100; a++)
			{	compression_115[a] += Authorship_private[temp_write_bookmark];
				compression_115[a] *= 5;
				compression_115[a] %= 10000000000;
				temp_write_bookmark -= 115;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_116[a] += Authorship_private[temp_write_bookmark];
				compression_116[a] *= 6;
				compression_116[a] %= 10000000000;
				temp_write_bookmark -= 116;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_117[a] += Authorship_private[temp_write_bookmark];
				compression_117[a] *= 7;
				compression_117[a] %= 10000000000;
				temp_write_bookmark -= 117;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_118[a] += Authorship_private[temp_write_bookmark];
				compression_118[a] *= 8;
				compression_118[a] %= 10000000000;
				temp_write_bookmark -= 118;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_119[a] += Authorship_private[temp_write_bookmark];
				compression_119[a] *= 9;
				compression_119[a] %= 10000000000;
				temp_write_bookmark -= 119;
			}
			
			//Compression snapshots are active in early stages of Authorship number evolution. They are applied to the compression in the end.
			if((f == 1000) || (f == 2000) || (f == 3000) || (f == 4000) || (f == 5000) || (f == 6000) || (f == 7000) || (f == 8000))
			{	for(int a = 0; a < 100; a++)
				{	snapshot_115[a] += compression_115[a];
					snapshot_115[a] %= 10000000000; //(10^10, results in last ten digits shown.)
					
					snapshot_116[a] += compression_116[a];
					snapshot_116[a] %= 10000000000;
					
					snapshot_117[a] += compression_117[a];
					snapshot_117[a] %= 10000000000;
					
					snapshot_118[a] += compression_118[a];
					snapshot_118[a] %= 10000000000;
					
					snapshot_119[a] += compression_119[a];
					snapshot_119[a] %= 10000000000;
				}
			}
			
			
			
			
			
			//The following block-bunch appends to the current function in Authorship_private[]: solution ingredients.
			for(int a = 0; a < 2000; a++) //Writes the transformation determinant.
			{	Authorship_private[write_bookmark] = transformation_determinant[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 2000; a++) //Writes the sub-key.
			{	Authorship_private[write_bookmark] = temp_sub_key[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a <= element_SUB2; a++) //Writes the prime_lengths_in_order_SUB2 (hot zone.)
			{	Authorship_private[write_bookmark] = prime_lengths_in_order_SUB2[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a <= element_SUB4; a++) //Writes the prime_lengths_in_order_SUB4 (hot zone.)
			{	Authorship_private[write_bookmark] = prime_lengths_in_order_SUB4[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a <= element_SUB6; a++) //Writes the prime_lengths_in_order_SUB6 (hot zone.)
			{	Authorship_private[write_bookmark] = prime_lengths_in_order_SUB6[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			if((read_bookmark - write_bookmark) < 30000) //Further collision prevention for read/write bookmarks. After each cycle within this
			{	read_bookmark += 1000000; //for loop, read_bookmark increases by ~16,000 while write_bookmark increases by ~18,000 and so the
			}                             //write_bookmark eventually catches up. This block forces read_bookmark to jump dynamically.
		                                  //Consider instead making tiny jumps away from write_bookmark--adjusting only by ~2,000 elements forward.
		                                  //That would be okay because you're just following along with write_bookmark and Authorship_private[]
		                                  //fits them all just fine. Now consider jumping only once in a while--distancing in bulk. This is no more
		                                  //a waste of random numbers than making small jumps. The bookmarks simply and smoothly approach
		                                  //one another over time. All that space between them must exist one way or another--in bulk or in parts.
		}
		
		
		
		
		
		//Writes everything to the file Authorship.private including the last dot then the null character.
		cout << "Creating files...\n";
		out_stream.open("Authorship.private");
		for(int a = 0; a < write_bookmark; a++)
		{	if(Authorship_private[a] == '.') {out_stream << '.';}
			else {out_stream << int(Authorship_private[a]);}
		}
		out_stream << '\0'; //These digits will be loaded into RAM one day, null marks when to stop reading them.
		out_stream.close();
		
		
		
		
		
		//Constructively combines the compression tables. compression_119[] will hold it all.
		for(int a = 0; a < 100; a++)
		{	compression_119[a] += compression_115[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 2;}
			
			compression_119[a] += compression_116[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 3;}
			
			compression_119[a] += compression_117[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 5;}
			
			compression_119[a] += compression_118[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 7;}
			
			compression_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		//Constructively combines the snapshot tables. snapshot_119[] will hold it all.
		for(int a = 0; a < 100; a++)
		{	snapshot_119[a] += snapshot_115[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 2;}
			
			snapshot_119[a] += snapshot_116[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 3;}
			
			snapshot_119[a] += snapshot_117[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 5;}
			
			snapshot_119[a] += snapshot_118[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 7;}
			
			snapshot_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		//Applies the snapshots to the last stage in compression. (As the Authorship number evolved over time, snapshots made a record of its early stages.)
		for(int a = 0; a < 100; a++)
		{	compression_119[a] += snapshot_119[a];
			compression_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		for(int a = 0; a < 100; a++) //Ensures each constituent compression integer is 10 digits long. The Authorship number is now complete.
		{	if(compression_119[a]   < 1000000000)
			{	compression_119[a] += 1000000000;
			}
		}
		
		
		
		
		
		//Writes number to the file Authorship.number.
		out_stream.open("Authorship.number");
		for(int a = 0; a < 100; a++)
		{	out_stream << compression_119[a];
		}
		out_stream.close();
		
		//The following block-bunch attempts to check for bad HDD sectors. The user will not be allowed to continue if bad
		//sectors are detected. This happens more often than you might think, especially with drives written to in one spot.
		//Converts the here-generated number (100 integers in compression_119[]) to type array for checking bad HDD sectors.
		cout << "Testing for bad sectors...\n";
		int compression[1000] = {0};
		int compression_write_bookmark = 0;
		for(int a = 0; a < 100; a++)
		{	compression[compression_write_bookmark] =  (compression_119[a] / 1000000000);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 100000000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 10000000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 1000000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 100000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 10000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 1000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 100) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 10) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] =  (compression_119[a]      % 10);
			compression_write_bookmark++;
		}
		
		//Loads file Authorship.number into Authorship_number[].
		char Authorship_number[1000];
		in_stream.open("Authorship.number");
		for(int a = 0; a < 1000; a++)
		{	in_stream >> Authorship_number[a];
			
			     if(Authorship_number[a] == 48) {Authorship_number[a] = 0;} //(Loaded ASCII characters from file) so converting them to our familiar numbers!
			else if(Authorship_number[a] == 49) {Authorship_number[a] = 1;} //Look to the ASCII table & character assignment in option 2.
			else if(Authorship_number[a] == 50) {Authorship_number[a] = 2;}
			else if(Authorship_number[a] == 51) {Authorship_number[a] = 3;}
			else if(Authorship_number[a] == 52) {Authorship_number[a] = 4;}
			else if(Authorship_number[a] == 53) {Authorship_number[a] = 5;}
			else if(Authorship_number[a] == 54) {Authorship_number[a] = 6;}
			else if(Authorship_number[a] == 55) {Authorship_number[a] = 7;}
			else if(Authorship_number[a] == 56) {Authorship_number[a] = 8;}
			else if(Authorship_number[a] == 57) {Authorship_number[a] = 9;}
			else {cout << "\n\nCosmic ray file corruption. Try again.     SV9\n\n"; return 0;}
		}
		in_stream.close();
		
		//Compares the number from file with the number in RAM.
		bool Authorship_number_sector_accident = false;
		for(int a = 0; a < 1000; a++)
		{	if(compression[a] != Authorship_number[a]) {Authorship_number_sector_accident = true; break;}
		}
		
		//Loads file Authorship.private.
		in_stream.open("Authorship.private");
		bool Authorship_private_sector_accident = false;
		int dot_counter = 0;
		char sniffed_a_file_character;
		for(int a = 0; a < 256500000; a++)
		{	in_stream.get(sniffed_a_file_character);
			if(sniffed_a_file_character == '\0') {break;}
			if(sniffed_a_file_character == '.') {dot_counter++; continue;} //There should be 148500 dots in all .private files.
			if((sniffed_a_file_character - 48) != Authorship_private[a]) {Authorship_private_sector_accident = true; break;}
		}
		in_stream.close();
		
		if((Authorship_number_sector_accident  == true)
		|| (Authorship_private_sector_accident == true)
		|| (dot_counter != 148500))
		{	remove("Authorship.number");
			remove("Authorship.private");
			
			cout << "\n\n\nBad sectors! There's something wrong with your storage device.\n\n"
			
			     << "For a quick fix, fill your storage device with a few gigabytes worth of any\n"
			     << "data then try this again. And do not disturb that dummy data as its purpose\n"
			     << "is to consume bad sectors and abused parts of the storage device.\n\n";
			
			return 0;
		}
		
		
		
		
		
		//Overwrites RAM of Authorship_private[].
		for(int a = 0; a < 256500000; a++)
		{	for(int b = 0; b < 10; b++) {Authorship_private[a] = b;}
		}
		
		//Overwrites RAM of user_seed[].
		for(int a = 0; a < 50; a++)
		{	user_seed[a] = 0; user_seed[a] = 12345678; user_seed[a] = 87654321; user_seed[a] = 99999999;
		}
		
		cout << "\n\n\nFinished.\n\n\n"
		
		     << "Your number resides in the file Authorship.number, publish it (1,000 digits.)\n"
		     << "Your  keys  reside in the file Authorship.private, cache them guardedly.\n\n\n\n";
	}
	
	
	
	
	
	//________________________________________________________________________________________________________________________
	//                                                                                                                       |
	//                                          2   Modify Authorship number                                                 |
	//_______________________________________________________________________________________________________________________|
	if(user_option == 2)
	{	ifstream in_stream;
		ofstream out_stream;
		
		//BASIC LAYOUT:
		//1. Generates your new number & keys (same as Authorship option 1 but holds in RAM until step 3.)
		//2. Loads given old Authorship.private file into old[].
		//3. Overwrites given Authorship.private file with new keys from step 1.
		//4. Forces old[] to represent your new number & message.
		//5. Writes old[] to now-created file Authorship.public.
		
		cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>>(Modify Authorship number)<<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
		     <<   "Place a COPY of a Authorship.private file in this directory if not already here.\n"
		     <<   "Enter 8 random digits, repeat 50 times. (Overwrites private file in 20 minutes.)\n"
		     <<   "Your old keys are then selectively written to your new public file created here.\n\n";
		
		unsigned int user_seed[50]; //Fills user_seed with 50 user-defined seeds of size 8.
		for(int a = 0; a < 50; a++)
		{	if(a < 9) {cout << " " << (a + 1) << " of 50: ";} //Prints blank to align input status report (aesthetics.)
			else {cout << (a + 1) << " of 50: ";}
			
			cin >> user_seed[a];
		}
		
		//Checks if file Authorship.private is present.
		in_stream.open("Authorship.private");
		if(in_stream.fail() == true)
		{	in_stream.close();
			
			cout << "\nAuthorship.private is still missing or misspelled. Copy and paste it into the\n"
			     << "folder from which you run this Authorship program. If this is an executable file\n"
			     << "running in the terminal, its effectiveness-directory is the user folder on this\n"
			     << "machine such as: /home/nikolay--where Authorship.private should then be placed.\n"
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
		
		
		
		
		
		static char Authorship_private[256500000]; //This array is filled with random digits then read from and written to left to right
		cout << "\n\n\n\n\nGenerating randomness...\n";
		//dynamically to save RAM space. It provides random digit input and temporary key storage (to be written to file: Authorship.private.)
		int read_bookmark = 1000000;  //Bookmarks where to read next from Authorship_private[]. Initial size prevents read/write collision.
		int write_bookmark = 0; //Bookmarks where to write next in  Authorship_private[].
		//(Function generation extracts random numbers using read/write bookmarks. Authorship_private[] is first filled with random numbers normally.)
		
		for(int a = 0; a < 50; a++) //Generates a random location (+10^6) for where to read from Authorship_private[]. This step prevents bookmark
		{	read_bookmark += (user_seed[a] % 10000); //collision and adds to the randomness strength. Average total value for read_bookmark: 1,250,000.
		} //The last item in the for loop who generates 13,500 multi-way functions deals with collision again, allowing bookmark proximity of ~30,000.
		
		srand(time(0));
		for(int a = 256499999; a >= 0; a--) //Fills Authorship_private[] with random numbers based on Unix time. WRITES RIGHT TO LEFT.
		{	Authorship_private[a] = (rand() % 10);
		}
		
		for(int a = 0; a < 50; a++) //Constructively applies random digits to Authorship_private[] based on the 50 seeds provided by the user.
		{	srand(user_seed[a]);    //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 50 user seeds.
			
			if((user_seed[a] % 2) == 0)
			{	for(int b = 0; b < 256500000; b++) //If current user seed is even, WRITES RANDOM NUMBERS LEFT TO RIGHT.
				{	Authorship_private[b] = (Authorship_private[b] + (rand() % 10));
					Authorship_private[b] %= 10;
				}
			}
			else
			{	for(int b = 256499999; b >= 0; b--) //If current user seed is odd, WRITES RANDOM NUMBERS RIGHT TO LEFT.
				{	Authorship_private[b] = (Authorship_private[b] + (rand() % 10));
					Authorship_private[b] %= 10;
				}
			}
		}
		
		srand(time(0)); //Constructively applies random numbers to Authorship_private[] once more, based on Unix time. WRITES LEFT TO RIGHT.
		for(int a = 0; a < 256500000; a++)
		{	Authorship_private[a] = (Authorship_private[a] + (rand() % 10));
			Authorship_private[a] %= 10;
		}
		
		
		
		
		
		//These declarations are for deductive lossy compression, they produce the Authorship number dynamically.
		//See the compression block-bunch near the end of the following for loop who generates 13,500 functions.
		long long int compression_115[100]; //Hops by -115
		long long int    snapshot_115[100]; //Takes a snapshot of compression_115[] every once in a while.
		
		long long int compression_116[100]; //Hops by -116
		long long int    snapshot_116[100]; //Takes a snapshot of compression_116[] every once in a while.
		
		long long int compression_117[100]; //Hops by -117
		long long int    snapshot_117[100]; //Takes a snapshot of compression_117[] every once in a while.
		
		long long int compression_118[100]; //Hops by -118
		long long int    snapshot_118[100]; //Takes a snapshot of compression_118[] every once in a while.
		
		long long int compression_119[100]; //Hops by -119
		long long int    snapshot_119[100]; //Takes a snapshot of compression_119[] every once in a while.
		
		for(int a = 0; a < 100; a++)
		{	compression_115[a] = 5555555555;	snapshot_115[a] = 5555555555;
			compression_116[a] = 5555555555;	snapshot_116[a] = 5555555555;
			compression_117[a] = 5555555555;	snapshot_117[a] = 5555555555;
			compression_118[a] = 5555555555;	snapshot_118[a] = 5555555555;
			compression_119[a] = 5555555555;	snapshot_119[a] = 5555555555;
		}
		
		//This is a boolean sieve of Eratosthenes. Zeros are prime, conveniently mapped to their element index. (It is used here like the following
		//example: if(sieve[my_candidate] == 0) then my_candidate is prime. Otherwise, my_candidate is increased until it is prime. This adjusts
		//my_candidate for primality in the positive direction.) And values over 99 for 2-digit primes for example are set to the largest prime < 100.)
		bool sieve[100000] = {1, 1};
		for(int prime = 2; prime < 317; prime++) //317 is sqrt(100000)
		{	for(int a = prime + prime; a < 100000; a += prime) {sieve[a] = 1;}
		}
		
		
		
		
		
		//The following for loop generates 13,500 multi-way functions in array Authorship_private[].
		cout << "Generating 13,500 multi-way functions...\n";
		for(int f = 0; f < 13500; f++)
		{	//The following block-bunch generates sub-function 1 for the current function. (Cool zone.)
			int transformation_determinant[2000];
			for(int a = 0; a < 2000; a++) //Fills transformation_determinant[] with random digits.
			{	transformation_determinant[a] = Authorship_private[read_bookmark];
				read_bookmark++;
			}
			
			long long assembled_seed_for_transformation[200] = {0}; //Prepares 200 10-digit seeds from transformation_determinant[]
			int transformation_determinant_read_bookmark = 0;       //for further key transformation.
			for(int a = 0; a < 200; a++)
			{	long long multiplier = 1000000000;
				for(int b = 0; b < 10; b++)
				{	assembled_seed_for_transformation[a] += (transformation_determinant[transformation_determinant_read_bookmark] * multiplier);
					transformation_determinant_read_bookmark++;
					multiplier /= 10;
				}
			}
			
			int sub_key[2000];
			int temp_sub_key[2000];
			for(int a = 0; a < 2000; a++) //Fills sub_key[] with random digits. This sub-key will be transformed and used dynamically.
			{	sub_key[a] = Authorship_private[read_bookmark];
				temp_sub_key[a] = Authorship_private[read_bookmark]; //Makes temp copy of sub-key so as to later append it near the current
				read_bookmark++;                                     //ciphertext when complete. (Written to Authorship_private[].)
			}                                                        //These kind of details prevent read/write_bookmark collision.
			
			for(int a = 0; a < 2000; a++) //Generates first sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += Authorship_private[read_bookmark];
				Authorship_private[write_bookmark] %= 10;
				read_bookmark++;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1999; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 2.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 1]) % 10); //[a + 1] means do up to 1998 or seg fault.
			}
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1000]) % 10); //Last element was not transformed so here it is.
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(1st of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 2 for the current function. (Hot zone.)
			int sub_plaintext_SUB2[2000];
			int prime_lengths_in_order_SUB2[1000]; //Expected contiguous primes: ~667.
			
			int length_sum_SUB2 = 0;
			int element_SUB2 = 0; //Begins writing to prime_lengths_in_order_SUB2[] from element 0 (basic counter.)
			while(length_sum_SUB2 < 2000)
			{	if(Authorship_private[read_bookmark] < 5) {	Authorship_private[read_bookmark]++;} //Reassigns (0=1,1=2,2=3,3=4,4=5.)
				else //Assigns 5 to: 1, 6 to: 2, 7 to: 3, 8 to: 4, and 9 to: 5. (All prime lengths must be 1-5.)
				{	Authorship_private[read_bookmark] += 16;
					Authorship_private[read_bookmark] %= 10; //Example: 7: (7+16) = 23, 23 mod 10 = 3. Seven is now 3.
				}
				
				length_sum_SUB2 += Authorship_private[read_bookmark];
				prime_lengths_in_order_SUB2[element_SUB2] = Authorship_private[read_bookmark]; //Prime lengths are recorded in
				element_SUB2++; //prime_lengths_in_order_SUB2[] so as to later append it near the current ciphertext when complete.
				read_bookmark++; //    ...(Written to Authorship_private[].)
			}
			
			element_SUB2--;
			if(length_sum_SUB2 > 2000) //Subtracts from last entry in prime_lengths_in_order_SUB2[] so as to ensure sum(entries) = 2,000.
			{	int overflow = (length_sum_SUB2 % 10);
				prime_lengths_in_order_SUB2[element_SUB2] -= overflow;
			}
			
			int write_bookmark_SUB2 = 0;
			for(int a = 0; a <= element_SUB2; a++) //Generates primes of corresponding length & writes them to sub_plaintext_SUB2[].
			{	if(prime_lengths_in_order_SUB2[a] == 1) //Randomly generates a single-digit prime.
				{	if(Authorship_private[read_bookmark] < 5)
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB2[write_bookmark_SUB2] = 2;} //The prime 2.
						else {sub_plaintext_SUB2[write_bookmark_SUB2] = 3;} //The prime 3.
					}
					
					else
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB2[write_bookmark_SUB2] = 5;} //The prime 5.
						else {sub_plaintext_SUB2[write_bookmark_SUB2] = 7;} //The prime 7.
					}
					
					write_bookmark_SUB2++;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 2) //Randomly generates a two-digit prime.
				{	int temp_2_digit_prime;
					temp_2_digit_prime = Authorship_private[read_bookmark]; //Unloads 2 array elements to make one integer.
					if(temp_2_digit_prime == 0) {temp_2_digit_prime++;}
					temp_2_digit_prime *= 10;
					temp_2_digit_prime += Authorship_private[read_bookmark + 1];
					
					while(sieve[temp_2_digit_prime] == 1) //Adjusts temp_2_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_2_digit_prime > 99) {temp_2_digit_prime = 97; break;} //If exceeds length of 2, sets it to largest 2-digit prime.
						temp_2_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_2_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_2_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_2_digit_prime;
					
					write_bookmark_SUB2 += 2;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 3) //Randomly generates a three-digit prime.
				{	int temp_3_digit_prime;
					temp_3_digit_prime = Authorship_private[read_bookmark]; //Unloads 3 array elements to make one integer.
					if(temp_3_digit_prime == 0) {temp_3_digit_prime++;}
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 1];
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 2];
					
					while(sieve[temp_3_digit_prime] == 1) //Adjusts temp_3_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_3_digit_prime > 999) {temp_3_digit_prime = 997; break;} //If exceeds length of 3, sets it to largest 3-digit prime.
						temp_3_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 2] = (temp_3_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_3_digit_prime % 10);
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_3_digit_prime;
					
					write_bookmark_SUB2 += 3;
					read_bookmark += 3;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 4) //Randomly generates a four-digit prime.
				{	int temp_4_digit_prime;
					temp_4_digit_prime = Authorship_private[read_bookmark]; //Unloads 4 array elements to make one integer.
					if(temp_4_digit_prime == 0) {temp_4_digit_prime++;}
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 1];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 2];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 3];
					
					while(sieve[temp_4_digit_prime] == 1) //Adjusts temp_4_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_4_digit_prime > 9999) {temp_4_digit_prime = 9973; break;} //If exceeds length of 4, sets it to largest 4-digit prime.
						temp_4_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 3] = (temp_4_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 2] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_4_digit_prime;
					
					write_bookmark_SUB2 += 4;
					read_bookmark += 4;
					continue;
				}
				
				if(prime_lengths_in_order_SUB2[a] == 5) //Randomly generates a five-digit prime.
				{	int temp_5_digit_prime;
					temp_5_digit_prime = Authorship_private[read_bookmark]; //Unloads 5 array elements to make one integer.
					if(temp_5_digit_prime == 0) {temp_5_digit_prime++;}
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 1];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 2];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 3];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 4];
					
					while(sieve[temp_5_digit_prime] == 1) //Adjusts temp_5_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_5_digit_prime > 99999) {temp_5_digit_prime = 99991; break;} //If exceeds length of 5, sets it to largest 5-digit prime.
						temp_5_digit_prime++;
					}
					
					sub_plaintext_SUB2[write_bookmark_SUB2 + 4] = (temp_5_digit_prime % 10); //Writes prime to sub_plaintext_SUB2[].
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 3] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 2] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2 + 1] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB2[write_bookmark_SUB2] = temp_5_digit_prime;
					
					write_bookmark_SUB2 += 5;
					read_bookmark += 5;
					continue;
				}
			}
			
			for(int a = 0; a < 2000; a++) //Generates second sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += sub_plaintext_SUB2[a];
				Authorship_private[write_bookmark] %= 10;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1998; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 3.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 2]) % 10); //[a + 2] means do up to 1997 or seg fault.
			}
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1005]) % 10); //Last two elements were not transformed so here it is.
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1010]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(2nd of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 3 for the current function. (Cool zone.)
			for(int a = 0; a < 2000; a++) //Generates third sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += Authorship_private[read_bookmark];
				Authorship_private[write_bookmark] %= 10;
				read_bookmark++;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			
			for(int a = 0; a < 1997; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 4.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 3]) % 10); //[a + 3] means do up to 1996 or seg fault.
			}
			sub_key[1997] = ((sub_key[1997] + transformation_determinant[1015]) % 10); //Last three elements were not transformed so here it is.
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1020]) % 10);
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1025]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(3rd of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 4 for the current function. (Hot zone.)
			int sub_plaintext_SUB4[2000];
			int prime_lengths_in_order_SUB4[1000]; //Expected contiguous primes: ~667.
			
			int length_sum_SUB4 = 0;
			int element_SUB4 = 0; //Begins writing to prime_lengths_in_order_SUB4[] from element 0 (basic counter.)
			while(length_sum_SUB4 < 2000)
			{	if(Authorship_private[read_bookmark] < 5) {	Authorship_private[read_bookmark]++;} //Reassigns (0=1,1=2,2=3,3=4,4=5.)
				else //Assigns 5 to: 1, 6 to: 2, 7 to: 3, 8 to: 4, and 9 to: 5. (All prime lengths must be 1-5.)
				{	Authorship_private[read_bookmark] += 16;
					Authorship_private[read_bookmark] %= 10; //Example: 7: (7+16) = 23, 23 mod 10 = 3. Seven is now 3.
				}
				
				length_sum_SUB4 += Authorship_private[read_bookmark];
				prime_lengths_in_order_SUB4[element_SUB4] = Authorship_private[read_bookmark]; //Prime lengths are recorded in
				element_SUB4++; //prime_lengths_in_order_SUB4[] so as to later append it near the current ciphertext when complete.
				read_bookmark++; //    ...(Written to Authorship_private[].)
			}
			
			element_SUB4--;
			if(length_sum_SUB4 > 2000) //Subtracts from last entry in prime_lengths_in_order_SUB4[] so as to ensure sum(entries) = 2,000.
			{	int overflow = (length_sum_SUB4 % 10);
				prime_lengths_in_order_SUB4[element_SUB4] -= overflow;
			}
			
			int write_bookmark_SUB4 = 0;
			for(int a = 0; a <= element_SUB4; a++) //Generates primes of corresponding length & writes them to sub_plaintext_SUB4[].
			{	if(prime_lengths_in_order_SUB4[a] == 1) //Randomly generates a single-digit prime.
				{	if(Authorship_private[read_bookmark] < 5)
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB4[write_bookmark_SUB4] = 2;} //The prime 2.
						else {sub_plaintext_SUB4[write_bookmark_SUB4] = 3;} //The prime 3.
					}
					
					else
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB4[write_bookmark_SUB4] = 5;} //The prime 5.
						else {sub_plaintext_SUB4[write_bookmark_SUB4] = 7;} //The prime 7.
					}
					
					write_bookmark_SUB4++;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 2) //Randomly generates a two-digit prime.
				{	int temp_2_digit_prime;
					temp_2_digit_prime = Authorship_private[read_bookmark]; //Unloads 2 array elements to make one integer.
					if(temp_2_digit_prime == 0) {temp_2_digit_prime++;}
					temp_2_digit_prime *= 10;
					temp_2_digit_prime += Authorship_private[read_bookmark + 1];
					
					while(sieve[temp_2_digit_prime] == 1) //Adjusts temp_2_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_2_digit_prime > 99) {temp_2_digit_prime = 97; break;} //If exceeds length of 2, sets it to largest 2-digit prime.
						temp_2_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_2_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_2_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_2_digit_prime;
					
					write_bookmark_SUB4 += 2;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 3) //Randomly generates a three-digit prime.
				{	int temp_3_digit_prime;
					temp_3_digit_prime = Authorship_private[read_bookmark]; //Unloads 3 array elements to make one integer.
					if(temp_3_digit_prime == 0) {temp_3_digit_prime++;}
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 1];
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 2];
					
					while(sieve[temp_3_digit_prime] == 1) //Adjusts temp_3_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_3_digit_prime > 999) {temp_3_digit_prime = 997; break;} //If exceeds length of 3, sets it to largest 3-digit prime.
						temp_3_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 2] = (temp_3_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_3_digit_prime % 10);
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_3_digit_prime;
					
					write_bookmark_SUB4 += 3;
					read_bookmark += 3;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 4) //Randomly generates a four-digit prime.
				{	int temp_4_digit_prime;
					temp_4_digit_prime = Authorship_private[read_bookmark]; //Unloads 4 array elements to make one integer.
					if(temp_4_digit_prime == 0) {temp_4_digit_prime++;}
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 1];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 2];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 3];
					
					while(sieve[temp_4_digit_prime] == 1) //Adjusts temp_4_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_4_digit_prime > 9999) {temp_4_digit_prime = 9973; break;} //If exceeds length of 4, sets it to largest 4-digit prime.
						temp_4_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 3] = (temp_4_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 2] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_4_digit_prime;
					
					write_bookmark_SUB4 += 4;
					read_bookmark += 4;
					continue;
				}
				
				if(prime_lengths_in_order_SUB4[a] == 5) //Randomly generates a five-digit prime.
				{	int temp_5_digit_prime;
					temp_5_digit_prime = Authorship_private[read_bookmark]; //Unloads 5 array elements to make one integer.
					if(temp_5_digit_prime == 0) {temp_5_digit_prime++;}
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 1];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 2];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 3];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 4];
					
					while(sieve[temp_5_digit_prime] == 1) //Adjusts temp_5_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_5_digit_prime > 99999) {temp_5_digit_prime = 99991; break;} //If exceeds length of 5, sets it to largest 5-digit prime.
						temp_5_digit_prime++;
					}
					
					sub_plaintext_SUB4[write_bookmark_SUB4 + 4] = (temp_5_digit_prime % 10); //Writes prime to sub_plaintext_SUB4[].
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 3] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 2] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4 + 1] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB4[write_bookmark_SUB4] = temp_5_digit_prime;
					
					write_bookmark_SUB4 += 5;
					read_bookmark += 5;
					continue;
				}
			}
			
			for(int a = 0; a < 2000; a++) //Generates fourth sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += sub_plaintext_SUB4[a];
				Authorship_private[write_bookmark] %= 10;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1996; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 5.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 4]) % 10); //[a + 4] means do up to 1995 or seg fault.
			}
			sub_key[1996] = ((sub_key[1996] + transformation_determinant[1030]) % 10); //Last four elements were not transformed so here it is.
			sub_key[1997] = ((sub_key[1997] + transformation_determinant[1035]) % 10);
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1040]) % 10);
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1045]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(4th of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 5 for the current function. (Cool zone.)
			for(int a = 0; a < 2000; a++) //Generates fifth sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += Authorship_private[read_bookmark];
				Authorship_private[write_bookmark] %= 10;
				read_bookmark++;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 1995; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 6.)
			{	sub_key[a] += transformation_determinant[a];
				sub_key[a] = ((sub_key[a] + transformation_determinant[a + 5]) % 10); //[a + 5] means do up to 1994 or seg fault.
			}
			sub_key[1995] = ((sub_key[1995] + transformation_determinant[1050]) % 10); //Last five elements were not transformed so here it is.
			sub_key[1996] = ((sub_key[1996] + transformation_determinant[1055]) % 10);
			sub_key[1997] = ((sub_key[1997] + transformation_determinant[1060]) % 10);
			sub_key[1998] = ((sub_key[1998] + transformation_determinant[1065]) % 10);
			sub_key[1999] = ((sub_key[1999] + transformation_determinant[1070]) % 10);
			
			for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
			{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
				
				if((assembled_seed_for_transformation[a] % 2) == 0)
				{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
				else
				{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
					{	sub_key[b] = (sub_key[b] + (rand() % 10));
						sub_key[b] %= 10;
					}
				}
			}
			//(5th of 5 total transformations per function.) Each one is different.
			
			
			
			
			
			//The following block-bunch generates sub-function 6 for the current function. (Hot zone.)
			int sub_plaintext_SUB6[2000];
			int prime_lengths_in_order_SUB6[1000]; //Expected contiguous primes: ~667.
			
			int length_sum_SUB6 = 0;
			int element_SUB6 = 0; //Begins writing to prime_lengths_in_order_SUB6[] from element 0 (basic counter.)
			while(length_sum_SUB6 < 2000)
			{	if(Authorship_private[read_bookmark] < 5) {	Authorship_private[read_bookmark]++;} //Reassigns (0=1,1=2,2=3,3=4,4=5.)
				else //Assigns 5 to: 1, 6 to: 2, 7 to: 3, 8 to: 4, and 9 to: 5. (All prime lengths must be 1-5.)
				{	Authorship_private[read_bookmark] += 16;
					Authorship_private[read_bookmark] %= 10; //Example: 7: (7+16) = 23, 23 mod 10 = 3. Seven is now 3.
				}
				
				length_sum_SUB6 += Authorship_private[read_bookmark];
				prime_lengths_in_order_SUB6[element_SUB6] = Authorship_private[read_bookmark]; //Prime lengths are recorded in
				element_SUB6++; //prime_lengths_in_order_SUB6[] so as to later append it near the current ciphertext when complete.
				read_bookmark++; //    ...(Written to Authorship_private[].)
			}
			
			element_SUB6--;
			if(length_sum_SUB6 > 2000) //Subtracts from last entry in prime_lengths_in_order_SUB6[] so as to ensure sum(entries) = 2,000.
			{	int overflow = (length_sum_SUB6 % 10);
				prime_lengths_in_order_SUB6[element_SUB6] -= overflow;
			}
			
			int write_bookmark_SUB6 = 0;
			for(int a = 0; a <= element_SUB6; a++) //Generates primes of corresponding length & writes them to sub_plaintext_SUB6[].
			{	if(prime_lengths_in_order_SUB6[a] == 1) //Randomly generates a single-digit prime.
				{	if(Authorship_private[read_bookmark] < 5)
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB6[write_bookmark_SUB6] = 2;} //The prime 2.
						else {sub_plaintext_SUB6[write_bookmark_SUB6] = 3;} //The prime 3.
					}
					
					else
					{	if(Authorship_private[read_bookmark + 1] < 5) {sub_plaintext_SUB6[write_bookmark_SUB6] = 5;} //The prime 5.
						else {sub_plaintext_SUB6[write_bookmark_SUB6] = 7;} //The prime 7.
					}
					
					write_bookmark_SUB6++;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 2) //Randomly generates a two-digit prime.
				{	int temp_2_digit_prime;
					temp_2_digit_prime = Authorship_private[read_bookmark]; //Unloads 2 array elements to make one integer.
					if(temp_2_digit_prime == 0) {temp_2_digit_prime++;}
					temp_2_digit_prime *= 10;
					temp_2_digit_prime += Authorship_private[read_bookmark + 1];
					
					while(sieve[temp_2_digit_prime] == 1) //Adjusts temp_2_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_2_digit_prime > 99) {temp_2_digit_prime = 97; break;} //If exceeds length of 2, sets it to largest 2-digit prime.
						temp_2_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_2_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_2_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_2_digit_prime;
					
					write_bookmark_SUB6 += 2;
					read_bookmark += 2;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 3) //Randomly generates a three-digit prime.
				{	int temp_3_digit_prime;
					temp_3_digit_prime = Authorship_private[read_bookmark]; //Unloads 3 array elements to make one integer.
					if(temp_3_digit_prime == 0) {temp_3_digit_prime++;}
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 1];
					temp_3_digit_prime *= 10;
					temp_3_digit_prime += Authorship_private[read_bookmark + 2];
					
					while(sieve[temp_3_digit_prime] == 1) //Adjusts temp_3_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_3_digit_prime > 999) {temp_3_digit_prime = 997; break;} //If exceeds length of 3, sets it to largest 3-digit prime.
						temp_3_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 2] = (temp_3_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_3_digit_prime % 10);
					temp_3_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_3_digit_prime;
					
					write_bookmark_SUB6 += 3;
					read_bookmark += 3;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 4) //Randomly generates a four-digit prime.
				{	int temp_4_digit_prime;
					temp_4_digit_prime = Authorship_private[read_bookmark]; //Unloads 4 array elements to make one integer.
					if(temp_4_digit_prime == 0) {temp_4_digit_prime++;}
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 1];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 2];
					temp_4_digit_prime *= 10;
					temp_4_digit_prime += Authorship_private[read_bookmark + 3];
					
					while(sieve[temp_4_digit_prime] == 1) //Adjusts temp_4_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_4_digit_prime > 9999) {temp_4_digit_prime = 9973; break;} //If exceeds length of 4, sets it to largest 4-digit prime.
						temp_4_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 3] = (temp_4_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 2] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_4_digit_prime % 10);
					temp_4_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_4_digit_prime;
					
					write_bookmark_SUB6 += 4;
					read_bookmark += 4;
					continue;
				}
				
				if(prime_lengths_in_order_SUB6[a] == 5) //Randomly generates a five-digit prime.
				{	int temp_5_digit_prime;
					temp_5_digit_prime = Authorship_private[read_bookmark]; //Unloads 5 array elements to make one integer.
					if(temp_5_digit_prime == 0) {temp_5_digit_prime++;}
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 1];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 2];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 3];
					temp_5_digit_prime *= 10;
					temp_5_digit_prime += Authorship_private[read_bookmark + 4];
					
					while(sieve[temp_5_digit_prime] == 1) //Adjusts temp_5_digit_prime for primality (tests current value & searches in pos dir.)
					{	if(temp_5_digit_prime > 99999) {temp_5_digit_prime = 99991; break;} //If exceeds length of 5, sets it to largest 5-digit prime.
						temp_5_digit_prime++;
					}
					
					sub_plaintext_SUB6[write_bookmark_SUB6 + 4] = (temp_5_digit_prime % 10); //Writes prime to sub_plaintext_SUB6[].
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 3] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 2] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6 + 1] = (temp_5_digit_prime % 10);
					temp_5_digit_prime /= 10;
					sub_plaintext_SUB6[write_bookmark_SUB6] = temp_5_digit_prime;
					
					write_bookmark_SUB6 += 5;
					read_bookmark += 5;
					continue;
				}
			}
			
			for(int a = 0; a < 2000; a++) //Generates sixth sub-ciphertext of current function and writes it to Authorship_private[].
			{	Authorship_private[write_bookmark] = sub_key[a];
				Authorship_private[write_bookmark] += sub_plaintext_SUB6[a];
				Authorship_private[write_bookmark] %= 10;
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			
			
			
			
			//The following block-bunch generates the Authorship number dynamically. (Its final form is then produced after the 13,500 functions.)
			//This sits here (just after the full function is written to array Authorship_private[]) because now temp_write_bookmark fingerprints the
			//function right to left so as to build the Authorship number. Then solution ingredients are appended to the current function.
			compression_119[0] += compression_119[99];
			compression_119[0] %= 10000000000;
			
			int temp_write_bookmark;
			temp_write_bookmark = (write_bookmark - 2);
			
			for(int a = 0; a < 100; a++)
			{	compression_115[a] += Authorship_private[temp_write_bookmark];
				compression_115[a] *= 5;
				compression_115[a] %= 10000000000;
				temp_write_bookmark -= 115;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_116[a] += Authorship_private[temp_write_bookmark];
				compression_116[a] *= 6;
				compression_116[a] %= 10000000000;
				temp_write_bookmark -= 116;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_117[a] += Authorship_private[temp_write_bookmark];
				compression_117[a] *= 7;
				compression_117[a] %= 10000000000;
				temp_write_bookmark -= 117;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_118[a] += Authorship_private[temp_write_bookmark];
				compression_118[a] *= 8;
				compression_118[a] %= 10000000000;
				temp_write_bookmark -= 118;
			}
			temp_write_bookmark = (write_bookmark - 2); //Resetting the temporary variable.
			
			for(int a = 0; a < 100; a++)
			{	compression_119[a] += Authorship_private[temp_write_bookmark];
				compression_119[a] *= 9;
				compression_119[a] %= 10000000000;
				temp_write_bookmark -= 119;
			}
			
			//Compression snapshots are active in early stages of Authorship number evolution. They are applied to the compression in the end.
			if((f == 1000) || (f == 2000) || (f == 3000) || (f == 4000) || (f == 5000) || (f == 6000) || (f == 7000) || (f == 8000))
			{	for(int a = 0; a < 100; a++)
				{	snapshot_115[a] += compression_115[a];
					snapshot_115[a] %= 10000000000; //(10^10, results in last ten digits shown.)
					
					snapshot_116[a] += compression_116[a];
					snapshot_116[a] %= 10000000000;
					
					snapshot_117[a] += compression_117[a];
					snapshot_117[a] %= 10000000000;
					
					snapshot_118[a] += compression_118[a];
					snapshot_118[a] %= 10000000000;
					
					snapshot_119[a] += compression_119[a];
					snapshot_119[a] %= 10000000000;
				}
			}
			
			
			
			
			
			//The following block-bunch appends to the current function in Authorship_private[]: solution ingredients.
			for(int a = 0; a < 2000; a++) //Writes the transformation determinant.
			{	Authorship_private[write_bookmark] = transformation_determinant[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a < 2000; a++) //Writes the sub-key.
			{	Authorship_private[write_bookmark] = temp_sub_key[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a <= element_SUB2; a++) //Writes the prime_lengths_in_order_SUB2 (hot zone.)
			{	Authorship_private[write_bookmark] = prime_lengths_in_order_SUB2[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a <= element_SUB4; a++) //Writes the prime_lengths_in_order_SUB4 (hot zone.)
			{	Authorship_private[write_bookmark] = prime_lengths_in_order_SUB4[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			for(int a = 0; a <= element_SUB6; a++) //Writes the prime_lengths_in_order_SUB6 (hot zone.)
			{	Authorship_private[write_bookmark] = prime_lengths_in_order_SUB6[a];
				write_bookmark++;
			}
			
			Authorship_private[write_bookmark] = '.'; //Separates the entry in Authorship_private[] from the next by one dot because
			write_bookmark++;                         //the quantity of contiguous primes is not fixed in length. All entries are separated.
			
			if((read_bookmark - write_bookmark) < 30000) //Further collision prevention for read/write bookmarks. After each cycle within this
			{	read_bookmark += 1000000; //for loop, read_bookmark increases by ~16,000 while write_bookmark increases by ~18,000 and so the
			}                             //write_bookmark eventually catches up. This block forces read_bookmark to jump dynamically.
		                                  //Consider instead making tiny jumps away from write_bookmark--adjusting only by ~2,000 elements forward.
		                                  //That would be okay because you're just following along with write_bookmark and Authorship_private[]
		                                  //fits them all just fine. Now consider jumping only once in a while--distancing in bulk. This is no more
		                                  //a waste of random numbers than making small jumps. The bookmarks simply and smoothly approach
		                                  //one another over time. All that space between them must exist one way or another--in bulk or in parts.
		}
		
		
		
		
		
		//Loads old file Authorship.private into old[].
		cout << "Reading from then overwriting Authorship.private...\n";
		static char old[256500000];
		in_stream.open("Authorship.private");
		for(int a = 0; a < 256500000; a++)
		{	in_stream >> old[a];
			if(old[a] == '\0') {break;}
		}
		in_stream.close();
		
		
		
		
		
		//Overwrites new keys to file Authorship.private including the last dot then the null character.
		out_stream.open("Authorship.private");
		for(int a = 0; a < write_bookmark; a++)
		{	if(Authorship_private[a] == '.') {out_stream << '.';}
			else {out_stream << int(Authorship_private[a]);}
		}
		out_stream << '\0'; //These digits will be loaded into RAM one day, null marks when to stop reading them.
		out_stream.close();
		
		//Loads file Authorship.private (looking for bad HDD sectors.)
		cout << "Testing for bad sectors...\n";
		in_stream.open("Authorship.private");
		bool Authorship_private_sector_accident = false;
		int dot_counter = 0;
		char sniffed_a_file_character;
		for(int a = 0; a < 256500000; a++)
		{	in_stream.get(sniffed_a_file_character);
			if(sniffed_a_file_character == '\0') {break;}
			if(sniffed_a_file_character == '.') {dot_counter++; continue;} //There should be 148500 dots in all .private files.
			if((sniffed_a_file_character - 48) != Authorship_private[a]) {Authorship_private_sector_accident = true; break;}
		}
		in_stream.close();
		
		if((Authorship_private_sector_accident == true) || (dot_counter != 148500))
		{	remove("Authorship.private");
			
			cout << "\n\n\nBad sectors! There's something wrong with your storage device.\n\n"
			
			     << "For a quick fix, fill your storage device with a few gigabytes worth of any\n"
			     << "data then try this again. And do not disturb that dummy data as its purpose\n"
			     << "is to consume bad sectors and abused parts of the storage device.\n\n";
			
			return 0;
		}
		
		
		
		
		
		//Constructively combines the compression tables. compression_119[] will hold it all.
		for(int a = 0; a < 100; a++)
		{	compression_119[a] += compression_115[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 2;}
			
			compression_119[a] += compression_116[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 3;}
			
			compression_119[a] += compression_117[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 5;}
			
			compression_119[a] += compression_118[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 7;}
			
			compression_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		//Constructively combines the snapshot tables. snapshot_119[] will hold it all.
		for(int a = 0; a < 100; a++)
		{	snapshot_119[a] += snapshot_115[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 2;}
			
			snapshot_119[a] += snapshot_116[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 3;}
			
			snapshot_119[a] += snapshot_117[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 5;}
			
			snapshot_119[a] += snapshot_118[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 7;}
			
			snapshot_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		//Applies the snapshots to the last stage in compression. (As the Authorship number evolved over time, snapshots made a record of its early stages.)
		for(int a = 0; a < 100; a++)
		{	compression_119[a] += snapshot_119[a];
			compression_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		for(int a = 0; a < 100; a++) //Ensures each constituent compression integer is 10 digits long. The Authorship number is now complete.
		{	if(compression_119[a]   < 1000000000)
			{	compression_119[a] += 1000000000;
			}
		}
		
		
		
		
		
		//The following table shows symbol assignment. Every contiguous nine multi-way functions in the list of 13,500 represent something.
		//Recall that 5/9 of all special strings of nine are always "1" so as to prevent ambiguity through clever selective censorship.
		///          nine functions     Authorship   user's                   original
		///            solved = 1         number     message                 ASCII # of
		/// ref       unsolved = 0       fragment   character                characters
		//#  1      0 0 0 0 1 1 1 1 1       00              (blank or space)    (32)
		//#  2      0 0 0 1 0 1 1 1 1       01          !                       (33)
		//#  3      0 0 0 1 1 0 1 1 1       02          "                       (34)
		//#  4      0 0 0 1 1 1 0 1 1       03          #                       (35)
		//#  5      0 0 0 1 1 1 1 0 1       04          $                       (36)
		//#  6      0 0 0 1 1 1 1 1 0       05          %                       (37)
		//#  7      0 0 1 0 0 1 1 1 1       06          &                       (38)
		//#  8      0 0 1 0 1 0 1 1 1       07          '                       (39)
		//#  9      0 0 1 0 1 1 0 1 1       08          (                       (40)
		//# 10      0 0 1 0 1 1 1 0 1       09          )                       (41)
		//# 11      0 0 1 0 1 1 1 1 0       10          *                       (42)
		//# 12      0 0 1 1 0 0 1 1 1       11          +                       (43)
		//# 13      0 0 1 1 0 1 0 1 1       12          ,   (comma)             (44)
		//# 14      0 0 1 1 0 1 1 0 1       13          -   (minus)             (45)
		//# 15      0 0 1 1 0 1 1 1 0       14          .   (dot)               (46)
		//# 16      0 0 1 1 1 0 0 1 1       15          /                       (47)
		//# 17      0 0 1 1 1 0 1 0 1       16          0                       (48)
		//# 18      0 0 1 1 1 0 1 1 0       17          1   (the number one)    (49)
		//# 19      0 0 1 1 1 1 0 0 1       18          2                       (50)
		//# 20      0 0 1 1 1 1 0 1 0       19          3                       (51)
		//# 21      0 0 1 1 1 1 1 0 0       20          4                       (52)
		//# 22      0 1 0 0 0 1 1 1 1       21          5                       (53)
		//# 23      0 1 0 0 1 0 1 1 1       22          6                       (54)
		//# 24      0 1 0 0 1 1 0 1 1       23          7                       (55)
		//# 25      0 1 0 0 1 1 1 0 1       24          8                       (56)
		//# 26      0 1 0 0 1 1 1 1 0       25          9                       (57)
		//# 27      0 1 0 1 0 0 1 1 1       26          :                       (58)
		//# 28      0 1 0 1 0 1 0 1 1       27          ;                       (59)
		//# 29      0 1 0 1 0 1 1 0 1       28          <                       (60)
		//# 30      0 1 0 1 0 1 1 1 0       29          =                       (61)
		//# 31      0 1 0 1 1 0 0 1 1       30          >                       (62)
		//# 32      0 1 0 1 1 0 1 0 1       31          ?                       (63)
		//# 33      0 1 0 1 1 0 1 1 0       32          @                       (64)
		//# 34      0 1 0 1 1 1 0 0 1       33          A                       (65)
		//# 35      0 1 0 1 1 1 0 1 0       34          B                       (66)
		//# 36      0 1 0 1 1 1 1 0 0       35          C                       (67)
		//# 37      0 1 1 0 0 0 1 1 1       36          D                       (68)
		//# 38      0 1 1 0 0 1 0 1 1       37          E                       (69)
		//# 39      0 1 1 0 0 1 1 0 1       38          F                       (70)
		//# 40      0 1 1 0 0 1 1 1 0       39          G                       (71)
		//# 41      0 1 1 0 1 0 0 1 1       40          H                       (72)
		//# 42      0 1 1 0 1 0 1 0 1       41          I                       (73)
		//# 43      0 1 1 0 1 0 1 1 0       42          J                       (74)
		//# 44      0 1 1 0 1 1 0 0 1       43          K                       (75)
		//# 45      0 1 1 0 1 1 0 1 0       44          L                       (76)
		//# 46      0 1 1 0 1 1 1 0 0       45          M                       (77)
		//# 47      0 1 1 1 0 0 0 1 1       46          N                       (78)
		//# 48      0 1 1 1 0 0 1 0 1       47          O                       (79)
		//# 49      0 1 1 1 0 0 1 1 0       48          P                       (80)
		//# 50      0 1 1 1 0 1 0 0 1       49          Q                       (81)
		//# 51      0 1 1 1 0 1 0 1 0       50          R                       (82)
		//# 52      0 1 1 1 0 1 1 0 0       51          S                       (83)
		//# 53      0 1 1 1 1 0 0 0 1       52          T                       (84)
		//# 54      0 1 1 1 1 0 0 1 0       53          U                       (85)
		//# 55      0 1 1 1 1 0 1 0 0       54          V                       (86)
		//# 56      0 1 1 1 1 1 0 0 0       55          W                       (87)
		//# 57      1 0 0 0 0 1 1 1 1       56          X                       (88)
		//# 58      1 0 0 0 1 0 1 1 1       57          Y                       (89)
		//# 59      1 0 0 0 1 1 0 1 1       58          Z                       (90)
		//# 60      1 0 0 0 1 1 1 0 1       59          [                       (91)
		//# 61      1 0 0 0 1 1 1 1 0       60          \                       (92)
		//# 62      1 0 0 1 0 0 1 1 1       61          ]                       (93)
		//# 63      1 0 0 1 0 1 0 1 1       62          ^                       (94)
		//# 64      1 0 0 1 0 1 1 0 1       63          _   (underscore)        (95)
		//# 65      1 0 0 1 0 1 1 1 0       64          `   (slant/emphasis)    (96)
		//# 66      1 0 0 1 1 0 0 1 1       65          a                       (97)
		//# 67      1 0 0 1 1 0 1 0 1       66          b                       (98)
		//# 68      1 0 0 1 1 0 1 1 0       67          c                       (99)
		//# 69      1 0 0 1 1 1 0 0 1       68          d                      (100)
		//# 70      1 0 0 1 1 1 0 1 0       69          e                      (101)
		//# 71      1 0 0 1 1 1 1 0 0       70          f                      (102)
		//# 72      1 0 1 0 0 0 1 1 1       71          g                      (103)
		//# 73      1 0 1 0 0 1 0 1 1       72          h                      (104)
		//# 74      1 0 1 0 0 1 1 0 1       73          i                      (105)
		//# 75      1 0 1 0 0 1 1 1 0       74          j                      (106)
		//# 76      1 0 1 0 1 0 0 1 1       75          k                      (107)
		//# 77      1 0 1 0 1 0 1 0 1       76          l   (l as in linguist) (108)
		//# 78      1 0 1 0 1 0 1 1 0       77          m                      (109)
		//# 79      1 0 1 0 1 1 0 0 1       78          n                      (110)
		//# 80      1 0 1 0 1 1 0 1 0       79          o                      (111)
		//# 81      1 0 1 0 1 1 1 0 0       80          p                      (112)
		//# 82      1 0 1 1 0 0 0 1 1       81          q                      (113)
		//# 83      1 0 1 1 0 0 1 0 1       82          r                      (114)
		//# 84      1 0 1 1 0 0 1 1 0       83          s                      (115)
		//# 85      1 0 1 1 0 1 0 0 1       84          t                      (116)
		//# 86      1 0 1 1 0 1 0 1 0       85          u                      (117)
		//# 87      1 0 1 1 0 1 1 0 0       86          v                      (118)
		//# 88      1 0 1 1 1 0 0 0 1       87          w                      (119)
		//# 89      1 0 1 1 1 0 0 1 0       88          x                      (120)
		//# 90      1 0 1 1 1 0 1 0 0       89          y                      (121)
		//# 91      1 0 1 1 1 1 0 0 0       90          z                      (122)
		//# 92      1 1 0 0 0 0 1 1 1       91          {                      (123)
		//# 93      1 1 0 0 0 1 0 1 1       92          |   (Unix pipe)        (124)
		//# 94      1 1 0 0 0 1 1 0 1       93          }                      (125)
		//# 95      1 1 0 0 0 1 1 1 0       94          ~                      (126) (And this makes 95 printable ASCII characters.)
		//# 96      1 1 0 0 1 0 0 1 1       95          no_char
		//# 97      1 1 0 0 1 0 1 0 1       96          unassigned
		//# 98      1 1 0 0 1 0 1 1 0       97          unassigned
		//# 99      1 1 0 0 1 1 0 0 1       98          unassigned
		//#100      1 1 0 0 1 1 0 1 0       99          unassigned
		//#101      1 1 0 0 1 1 1 0 0       unassigned  unassigned
		//#102      1 1 0 1 0 0 0 1 1       unassigned  unassigned
		//#103      1 1 0 1 0 0 1 0 1       unassigned  unassigned
		//#104      1 1 0 1 0 0 1 1 0       unassigned  unassigned
		//#105      1 1 0 1 0 1 0 0 1       unassigned  unassigned
		//#106      1 1 0 1 0 1 0 1 0       unassigned  unassigned
		//#107      1 1 0 1 0 1 1 0 0       unassigned  unassigned
		//#108      1 1 0 1 1 0 0 0 1       unassigned  unassigned
		//#109      1 1 0 1 1 0 0 1 0       unassigned  unassigned
		//#110      1 1 0 1 1 0 1 0 0       unassigned  unassigned
		//#111      1 1 0 1 1 1 0 0 0       unassigned  unassigned
		//#112      1 1 1 0 0 0 0 1 1       unassigned  unassigned
		//#113      1 1 1 0 0 0 1 0 1       unassigned  unassigned
		//#114      1 1 1 0 0 0 1 1 0       unassigned  unassigned
		//#115      1 1 1 0 0 1 0 0 1       unassigned  unassigned
		//#116      1 1 1 0 0 1 0 1 0       unassigned  unassigned
		//#117      1 1 1 0 0 1 1 0 0       unassigned  unassigned
		//#118      1 1 1 0 1 0 0 0 1       unassigned  unassigned
		//#119      1 1 1 0 1 0 0 1 0       unassigned  unassigned
		//#120      1 1 1 0 1 0 1 0 0       unassigned  unassigned
		//#121      1 1 1 0 1 1 0 0 0       unassigned  unassigned
		//#122      1 1 1 1 0 0 0 0 1       unassigned  unassigned
		//#123      1 1 1 1 0 0 0 1 0       unassigned  unassigned
		//#124      1 1 1 1 0 0 1 0 0       unassigned  unassigned
		//#125      1 1 1 1 0 1 0 0 0       unassigned  unassigned
		//#126      1 1 1 1 1 0 0 0 0       unassigned  unassigned
		
		//Combination 96 (reference # 96) is repeated for all remaining contiguous nine functions if no user message exists.
		//For messages shorter than 1,000 characters, remaining unused spaces are also filled with combination 96 (1 1 0 0 1 0 0 1 1.)
		//(Combination 96 (no_char) is a custom assignment in the Authorship program. It is NOT the null character.)
		
		
		
		
		
		//Prints the new number in case the user wants to see it, publish it, or send it for trade. Numbers are normally
		//handled automatically. This option to see the new number allows any new user to begin verifying authentication
		//events. Perhaps some verifying party had lost your number and wishes to begin again, here.
		cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
		for(int a = 0; a < 100; a++) {cout << compression_119[a];}
		cout << "\n\nYour new number is printed above if trading or if some verifying\n"
		     << "party had lost your number or began verifying at a later time..........\n\n\n";
		
		//The following block-bunch converts the new number and message information into the "5/9 filled special binary combinations."
		int pair[500];
		int pair_write_bookmark = 4;
		for(int a = 0; a < 100; a++) //Converts number into array (loads number as fragments of 2 digits into each element of pair[].)
		{	pair[pair_write_bookmark] = compression_119[a] % 100;
			compression_119[a] /= 100;
			pair[pair_write_bookmark - 1] = compression_119[a] % 100;
			compression_119[a] /= 100;
			pair[pair_write_bookmark - 2] = compression_119[a] % 100;
			compression_119[a] /= 100;
			pair[pair_write_bookmark - 3] = compression_119[a] % 100; //(Don't forget, C++ is sensitive to order, parentheses,
			compression_119[a] /= 100;                                //and commands (compression_119[a] mod 100 is performed first.)
			pair[pair_write_bookmark - 4] = compression_119[a];
			
			pair_write_bookmark += 5;
		}
		
		bool b[13500]; //b for binary, will hold the final binary super-string.
		int m = 0; //Write bookmark for b[].
		for(int a = 0; a < 500; a++) //Loads binary expansion for number into b[]. (The first 500 groups of nine in b[] will represent the Authorship number, each group giving a digit pair.)
		{
			//              number
			//             fragment      |           |           |           |           |           |           |           |           |
			     if(pair[a] == 0) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 1) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 2) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 3) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 4) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 5) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] == 6) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 7) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 8) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] == 9) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==10) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==11) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==12) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==13) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==14) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==15) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==16) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==17) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==18) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==19) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==20) {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==21) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==22) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==23) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==24) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==25) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==26) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==27) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==28) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==29) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==30) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==31) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==32) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==33) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==34) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==35) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==36) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==37) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==38) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==39) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==40) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==41) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==42) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==43) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==44) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==45) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==46) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==47) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==48) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==49) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==50) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==51) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==52) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==53) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==54) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==55) {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==56) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==57) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==58) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==59) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==60) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==61) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==62) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==63) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==64) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==65) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==66) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==67) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==68) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==69) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==70) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==71) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==72) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==73) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==74) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==75) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==76) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==77) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==78) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==79) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==80) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==81) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==82) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==83) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==84) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==85) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==86) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==87) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==88) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==89) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==90) {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==91) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==92) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==93) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==94) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==95) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==96) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==97) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
			else if(pair[a] ==98) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
			else if(pair[a] ==99) {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;} //This is 100th (00 - 99.)
			//                           |           |           |           |           |           |           |           |           |
			
			else {cout << "\n\nCosmic ray corruption.     jx9\n\n"; return 0;}
		}
		
		m = 4500; //Sets write head of b[] to where the user message will begin in "5/9 binary" as the last operation (above) did m += 9. b[4500] is the 4,501st element.
		
		//Now b[] is filled with user message information...
		//Message or not, remaining b[] elements are filled with reference # 96 (no_char = 1 1 0 0 1 0 0 1 1.)
		{	for(int a = 0; a < 1000; a++) //Remaining 1000 groups of nine.)
			{	b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;
			}	//    |           |           |           |           |           |           |           |           |
		}
		
		cout << "Notes included in public files will be extracted as plaintext upon verification.\n"
		     << "Enter a message (1,000 characters max, will be truncated) otherwise press enter:\n\n";
		char nothing_to_see_here[1];
		cin.getline(nothing_to_see_here, 1); //Catching cache.
		
		char message[10000]; //This is TEN thousand in case the user enters too many.
		cin.getline(message, 10000); //If enter is pressed, ALL message[] elements are auto-set to null, else remaining are.
		message[1000] = '\0'; //Now to safely truncate the message length to its max (1,001st element is set to null.)
		cout << "\nSelectively writing solutions to Authorship.public...\n";
		
		
		
		
		
		if(message[0] != '\0')
		{	m = 4500; //Again, sets write head of b[] to where the user message will begin in "5/9 binary." b[4500] is the 4,501st element.
			for(int a = 0; message[a] != '\0'; a++) //Loads binary expansion for user's message. (The remaining 1,000 groups of nine in b[] will represent the user message or data.)
			{	
				//                  message
				//                 character      |           |           |           |           |           |           |           |           |
				     if(message[a] == ' ') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;} //(Blank or space.) Not to be confused with no_char.
				else if(message[a] == '!') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '"') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '#') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '$') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '%') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '&') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] =='\'') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '(') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == ')') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '*') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '+') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == ',') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '-') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '.') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '/') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '0') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '1') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '2') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '3') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '4') {b[m]= 0;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '5') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '6') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '7') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '8') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '9') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == ':') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == ';') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '<') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '=') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '>') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '?') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '@') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'A') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'B') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'C') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'D') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'E') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'F') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'G') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'H') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'I') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'J') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'K') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'L') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'M') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'N') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'O') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'P') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'Q') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'R') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'S') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'T') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'U') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'V') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'W') {b[m]= 0;  b[m+1]= 1;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'X') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'Y') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'Z') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '[') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] =='\\') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == ']') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '^') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '_') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '`') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'a') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'b') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'c') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'd') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'e') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'f') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 0;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'g') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'h') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'i') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'j') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'k') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'l') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'm') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'n') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'o') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'p') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 0;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'q') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'r') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 's') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 't') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'u') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'v') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'w') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == 'x') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'y') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == 'z') {b[m]= 1;  b[m+1]= 0;  b[m+2]= 1;  b[m+3]= 1;  b[m+4]= 1;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 0;  b[m+8]= 0;  m+=9;}
				else if(message[a] == '{') {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 0;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '|') {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 0;  b[m+7]= 1;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '}') {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 0;  b[m+8]= 1;  m+=9;}
				else if(message[a] == '~') {b[m]= 1;  b[m+1]= 1;  b[m+2]= 0;  b[m+3]= 0;  b[m+4]= 0;  b[m+5]= 1;  b[m+6]= 1;  b[m+7]= 1;  b[m+8]= 0;  m+=9;} //This makes all 95 printable ASCII characters (but only printable.)
				//                                |           |           |           |           |           |           |           |           |
				
				else {cout << "\n\nCosmic ray corruption.     kv6\n\n"; return 0;}
			}
		}
		
		
		
		
		
		//Selectively writes old[] to file Authorship.public. SELECTIVITY IS BASED ON THE CONTENTS OF b[]. (Authorship.public is a new file created now.)
		bool hash_digits_table[12006] = {0}; //Prepares a hash-digits distribution table who dictates which items to omit and which to write to file Authorship.public.
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 115;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 116;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 117;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 118;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 119;}
		
		//Solution ingredients meant to be destroyed are turned into the single character x. Example with the usual dot separators: 25467132.x.90683471
		//The special binary representation has already been established, now the program only writes to file Authorship.public based on b[].
		out_stream.open("Authorship.public");
		int old_read_bookmark = 0;
		int Authorship_private_write_bookmark_for_sector_accident_reference = 0; //Authorship_private[] will hold a RAM copy of Authorship.public for sector testing.
		for(int revelation = 0; revelation < 13500; revelation++)
		{	if(b[revelation] == 0)
			{	/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				for(int a = 0; a < 12006; a++) ///Writes only the hash-digits of the function (495 digits then one separating dot.) //////////////////////
				{	if(hash_digits_table[a] == 0) {old_read_bookmark++;}
					else
					{	     if(old[old_read_bookmark] == 48) {out_stream << '0'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 0;}
						else if(old[old_read_bookmark] == 49) {out_stream << '1'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 1;}
						else if(old[old_read_bookmark] == 50) {out_stream << '2'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 2;}
						else if(old[old_read_bookmark] == 51) {out_stream << '3'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 3;}
						else if(old[old_read_bookmark] == 52) {out_stream << '4'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 4;}
						else if(old[old_read_bookmark] == 53) {out_stream << '5'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 5;}
						else if(old[old_read_bookmark] == 54) {out_stream << '6'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 6;}
						else if(old[old_read_bookmark] == 55) {out_stream << '7'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 7;}
						else if(old[old_read_bookmark] == 56) {out_stream << '8'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 8;}
						else if(old[old_read_bookmark] == 57) {out_stream << '9'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 9;}
						else {cout << "\n\nCosmic ray corruption.     ym8\n\n"; return 0;}
						
						old_read_bookmark++;
						Authorship_private_write_bookmark_for_sector_accident_reference++;
					}
				}
				
				out_stream << '.';
				Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = '.';
				Authorship_private_write_bookmark_for_sector_accident_reference++;
			}
			
			else
			{	/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
				for(int a = 0; a < 12006; a++) ///Writes only the function (six sub-ciphertext and the six separating dots.) /////////////////////////////
				{	     if(old[old_read_bookmark] == 48) {out_stream << '0'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 0;}
					else if(old[old_read_bookmark] == 49) {out_stream << '1'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 1;}
					else if(old[old_read_bookmark] == 50) {out_stream << '2'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 2;}
					else if(old[old_read_bookmark] == 51) {out_stream << '3'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 3;}
					else if(old[old_read_bookmark] == 52) {out_stream << '4'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 4;}
					else if(old[old_read_bookmark] == 53) {out_stream << '5'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 5;}
					else if(old[old_read_bookmark] == 54) {out_stream << '6'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 6;}
					else if(old[old_read_bookmark] == 55) {out_stream << '7'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 7;}
					else if(old[old_read_bookmark] == 56) {out_stream << '8'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 8;}
					else if(old[old_read_bookmark] == 57) {out_stream << '9'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 9;}
					else if(old[old_read_bookmark] == 46) {out_stream << '.'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = '.';}
					else {cout << "\n\nCosmic ray corruption.     ij2\n\n"; return 0;}
					
					old_read_bookmark++;
					Authorship_private_write_bookmark_for_sector_accident_reference++;
				}
			}
			
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			if(b[revelation] == 1) ///Appends the solution ingredients to the function. //////////////////////////////////////////////////////////////////
			{	for(int a = 0; a < 5; a++)
				{	while(old[old_read_bookmark] != '.')
					{	     if(old[old_read_bookmark] == 48) {out_stream << '0'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 0;}
						else if(old[old_read_bookmark] == 49) {out_stream << '1'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 1;}
						else if(old[old_read_bookmark] == 50) {out_stream << '2'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 2;}
						else if(old[old_read_bookmark] == 51) {out_stream << '3'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 3;}
						else if(old[old_read_bookmark] == 52) {out_stream << '4'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 4;}
						else if(old[old_read_bookmark] == 53) {out_stream << '5'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 5;}
						else if(old[old_read_bookmark] == 54) {out_stream << '6'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 6;}
						else if(old[old_read_bookmark] == 55) {out_stream << '7'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 7;}
						else if(old[old_read_bookmark] == 56) {out_stream << '8'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 8;}
						else if(old[old_read_bookmark] == 57) {out_stream << '9'; Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 9;}
						else {cout << "\n\nCosmic ray corruption.     fz3\n\n"; return 0;}
						
						old_read_bookmark++;
						Authorship_private_write_bookmark_for_sector_accident_reference++;
					}
					
					out_stream << '.';
					old_read_bookmark++;
					Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = '.';
					Authorship_private_write_bookmark_for_sector_accident_reference++;
				}
			}
			
			//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			else ///Skips through the solution ingredients of the function. //////////////////////////////////////////////////////////////////////////////
			{	for(int a = 0; a < 5; a++)
				{	while(old[old_read_bookmark] != '.')
					{	old_read_bookmark++;
					}
					
					old_read_bookmark++;
				}
				
				out_stream << 'x' << '.';
				Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = 'x';
				Authorship_private_write_bookmark_for_sector_accident_reference++;
				Authorship_private[Authorship_private_write_bookmark_for_sector_accident_reference] = '.';
				Authorship_private_write_bookmark_for_sector_accident_reference++;
			}
		}
		out_stream << '\0';
		out_stream.close();
		
		
		
		
		
		//Loads file Authorship.public (looking for bad HDD sectors.)
		cout << "Testing for bad sectors again...\n";
		in_stream.open("Authorship.public");
		bool Authorship_public_sector_accident = false;
		for(int a = 0; a < 256500000; a++)
		{	in_stream.get(sniffed_a_file_character);
			if(sniffed_a_file_character == '\0') {break;}
			if(sniffed_a_file_character == '.') {continue;}
			if(sniffed_a_file_character == 'x') {continue;}
			if((sniffed_a_file_character - 48) != Authorship_private[a]) {Authorship_public_sector_accident = true; break;}
		}
		in_stream.close();
		
		if(Authorship_public_sector_accident == true)
		{	remove("Authorship.private");
			remove("Authorship.public");
			
			cout << "\n\n\nBad sectors! There's something wrong with your storage device.\n\n"
			
			     << "For a quick fix, fill your storage device with a few gigabytes worth of any\n"
			     << "data then try this again. And do not disturb that dummy data as its purpose\n"
			     << "is to consume bad sectors and abused parts of the storage device.\n\n";
			
			return 0;
		}
		
		//Overwrites RAM of old[] and Authorship_private[].
		for(int a = 0; a < 256500000; a++)
		{	for(int b = 0; b < 10; b++) {old[a] = b;}
			for(int c = 0; c < 10; c++) {Authorship_private[a] = c;}
		}
		
		//Overwrites RAM of user_seed[].
		for(int a = 0; a < 50; a++)
		{	user_seed[a] = 0; user_seed[a] = 12345678; user_seed[a] = 87654321; user_seed[a] = 99999999;
		}
		
		cout << "\n\n\n\n\n\n\n\n\n\n\nFinished.\n\n\n"
		
		     << "Authorship.private has been overwritten with your new keys.\n"
		     << "Cache them guardedly and destroy the old copy file.  You no longer\n"
		     << "need YOUR Authorship.number file, numbers will be intertwined within\n"
		     << "your Authorship.public files, as well as being printed in the\n"
		     << "terminal for every authentication event as printed here, above.\n\n"
		
		     << "Authorship.public now resides in this directory. Publish it and\n"
		     << "the verifying party will extract your new number from this file.\n"
		     << "Once they have your new number, they can discard any old numbers\n"
		     << "and keys you have published in the past.\n\n";
	}
	
	
	
	
	
	//________________________________________________________________________________________________________________________
	//                                                                                                                       |
	//                                          3   Verify number modification                                               |
	//_______________________________________________________________________________________________________________________|
	if(user_option == 3)
	{	ifstream in_stream;
		ofstream out_stream;
		
		//Basic layout:
		//1. Reads file Authorship.public then generates the compression.
		//2. Reads file Authorship.number and compares it to the compression from step 1. Fails if mismatch.
		//3. Tests the transformation determinants, keys, key transformations, and primes of the file in step 1. Fails on error.
		//4. Extracts the new number & message from the file in step 1 and tests for additional properties. Fails on error.
		//5. Writes the number to now-created file Authorship.number.
		
		cout << "\n>>>>>>>>>>>>>>>>>>>>>>>>>>(Verify number modification)<<<<<<<<<<<<<<<<<<<<<<<<<<\n"
		     << "Place COPIES of the following two files in this directory.  (5-minute run-time.)\n\n"
		
		     << "    Authorship.number  (User's number as saved on your device. This is a plain\n"
		     << "                        text file containing 1,000 digits. It can be created.)\n"
		     << "    Authorship.public  (User's published file as downloaded on your device.)\n\n"
		
		     << "Continue? y/n: ";
		
		char wait;
		cin >> wait;
		if(wait != 'y') {return 0;}
		
		
		
		
		
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
		
		//Loads file Authorship.public into Authorship_public[].
		cout << "\nCompressing Authorship.public...\n";
		static char Authorship_public[140000000];
		in_stream.open("Authorship.public");
		for(int a = 0; a < 140000000; a++)
		{	in_stream >> Authorship_public[a];
			if(Authorship_public[a] == '\0') {break;}
		}
		in_stream.close();
		
		for(int a = 0; Authorship_public[a] != '\0'; a++) //Converts Authorship_public[] items to numerical values ('x' and '.' excluded.)
		{	     if(Authorship_public[a] == 48) {Authorship_public[a] = 0;}
			else if(Authorship_public[a] == 49) {Authorship_public[a] = 1;}
			else if(Authorship_public[a] == 50) {Authorship_public[a] = 2;}
			else if(Authorship_public[a] == 51) {Authorship_public[a] = 3;}
			else if(Authorship_public[a] == 52) {Authorship_public[a] = 4;}
			else if(Authorship_public[a] == 53) {Authorship_public[a] = 5;}
			else if(Authorship_public[a] == 54) {Authorship_public[a] = 6;}
			else if(Authorship_public[a] == 55) {Authorship_public[a] = 7;}
			else if(Authorship_public[a] == 56) {Authorship_public[a] = 8;}
			else if(Authorship_public[a] == 57) {Authorship_public[a] = 9;}
			else if(Authorship_public[a] == '.') {continue;}
			else if(Authorship_public[a] == 'x') {continue;}
			else {cout << "\n\nCosmic ray corruption.     tq4\n\n"; return 0;}
		}
		
		
		
		
		
		//The following block-bunch generates the compression and compares it to Authorship.number. The following guardians must ALL sing
		//"true" before the verifying party gets the message "Verification SUCCESSFUL!" These guardians exist for exceptional clarity and
		//safety in the many diverse devices who may run the Authorship program. Any errors or mismatch in the verification process
		//IMMEDIATELY ends the program with the message "Verification FAILED!" This ensures that false authentication events are terminated
		//here long before any chance of sliding under additional guardians. Guardians may be controlled by external means at any moment,
		//by accident in overflow or with clever attacks. Guardians sing "false" by default. (Sensitive software means safety first!)
		bool comparison = false; //The extracted number must match the provided number.
		bool keys       = false; //Keys, transformation determinants, key transformations, and prime lengths must satisfy 5/9 of 13,500 functions.
		bool digits     = false; //The first 500 groups of nine contiguous functions must correspond to digit pair assignment.
		bool characters = false; //The remaining 1,000 groups of nine contiguous functions must correspond to character assignment.
		
		//Those who wish to harm and slow down some currency circulation or whatever Authorship system, might exhaustively publish Authorship.public
		//files who must receive acceptance by large communities using old hardware. This is just another reason to have early fault detection
		//as the file is read, however, it seems no elegant solutions exist and so the file Authorship.public is read whole before being processed.
		//This is a waste of time and resources since most machines download and read content slowly which becomes problematic with serious quantity.
		//Consider generating deductive lossy compression of the first few functions, then overwriting that to a few integers in the final number.
		//Then, while reading the file, if its first few functions produce certain integers who match those in a list of Authorship numbers, file
		//reading continues. Attackers can place highly curated faulty files to do just that and get away with wasting the time it takes your machine
		//to read and verify the remaining 138.09999MB. But let's get clever. Suppose the first string read from the file contains a cryptographic key
		//who unlocks a portion of some number in a public list. Certainly, you can halt reading faulty files without a correct key. In fact, you can
		//even halt the download early as you can process downloaded data sequentially. Surprisingly, this is not a solution still. And given the
		//untraceable and anonymous capabilities of Authorship, you can bet that any and all systems will utilize those capabilities--which makes it
		//impossible to know who's uploading the garbage. And just as they are free to sabotage, you are free to hunt them down. Attackers will take
		//advantage of the high traffic in such systems--machines just can't get to every file as soon as it's released. And so the key strings who are
		//first in the files can be inserted into their faulty files. Now let's go even further--combine the cryptographic key guard with the compression
		//in the first consideration. This helps pin-point which number the file inquires to modify, however, the remaining file content could be faulty
		//for the purpose of wasting time as the genuine file could have been automatically curated by machines looking through the published
		//Authorship.public files. This adds garbage to the pile yet the pile must be processed. Please solve for x and let me know.
		
		//These declarations are for deductive lossy compression, they produce the Authorship number dynamically.
		long long int compression_115[100]; //Hops by -115
		long long int    snapshot_115[100]; //Takes a snapshot of compression_115[] every once in a while.
		
		long long int compression_116[100]; //Hops by -116
		long long int    snapshot_116[100]; //Takes a snapshot of compression_116[] every once in a while.
		
		long long int compression_117[100]; //Hops by -117
		long long int    snapshot_117[100]; //Takes a snapshot of compression_117[] every once in a while.
		
		long long int compression_118[100]; //Hops by -118
		long long int    snapshot_118[100]; //Takes a snapshot of compression_118[] every once in a while.
		
		long long int compression_119[100]; //Hops by -119
		long long int    snapshot_119[100]; //Takes a snapshot of compression_119[] every once in a while.
		
		for(int a = 0; a < 100; a++)
		{	compression_115[a] = 5555555555;	snapshot_115[a] = 5555555555;
			compression_116[a] = 5555555555;	snapshot_116[a] = 5555555555;
			compression_117[a] = 5555555555;	snapshot_117[a] = 5555555555;
			compression_118[a] = 5555555555;	snapshot_118[a] = 5555555555;
			compression_119[a] = 5555555555;	snapshot_119[a] = 5555555555;
		}
		
		bool hash_digits_table[12006] = {0}; //Prepares a hash-digits distribution table.
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 115;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 116;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 117;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 118;}
		for(int marker = 12004, a = 0; a < 100; a++) {hash_digits_table[marker] = 1; marker -= 119;}
		
		//Generates compression
		int read_bookmark = 0;
		for(int f = 0; f < 13500; f++) //Chronologically reads through 13,500 functions in Authorship_public[].
		{	if(Authorship_public[read_bookmark + 495] == '.') //If chunk of hash-digits, simulates them in the length of a real function.
			{	int simulated_function[12006];
				for(int a = 0; a < 12006; a++)
				{	if(hash_digits_table[a] == 1)
					{	simulated_function[a] = Authorship_public[read_bookmark];
						read_bookmark++;
					}
				}
				
				compression_119[0] += compression_119[99];
				compression_119[0] %= 10000000000;
				
				int temp_read_bookmark = 12004;
				
				for(int a = 0; a < 100; a++)
				{	compression_115[a] += simulated_function[temp_read_bookmark];
					compression_115[a] *= 5;
					compression_115[a] %= 10000000000;
					temp_read_bookmark -= 115;
				}
				temp_read_bookmark = 12004; //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_116[a] += simulated_function[temp_read_bookmark];
					compression_116[a] *= 6;
					compression_116[a] %= 10000000000;
					temp_read_bookmark -= 116;
				}
				temp_read_bookmark = 12004; //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_117[a] += simulated_function[temp_read_bookmark];
					compression_117[a] *= 7;
					compression_117[a] %= 10000000000;
					temp_read_bookmark -= 117;
				}
				temp_read_bookmark = 12004; //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_118[a] += simulated_function[temp_read_bookmark];
					compression_118[a] *= 8;
					compression_118[a] %= 10000000000;
					temp_read_bookmark -= 118;
				}
				temp_read_bookmark = 12004; //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_119[a] += simulated_function[temp_read_bookmark];
					compression_119[a] *= 9;
					compression_119[a] %= 10000000000;
					temp_read_bookmark -= 119;
				}
				
				read_bookmark++;
			}
			
			else
			{	read_bookmark += 12006;
				
				compression_119[0] += compression_119[99];
				compression_119[0] %= 10000000000;
				
				int temp_read_bookmark;
				temp_read_bookmark = (read_bookmark - 2);
				
				for(int a = 0; a < 100; a++)
				{	compression_115[a] += Authorship_public[temp_read_bookmark];
					compression_115[a] *= 5;
					compression_115[a] %= 10000000000;
					temp_read_bookmark -= 115;
				}
				temp_read_bookmark = (read_bookmark - 2); //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_116[a] += Authorship_public[temp_read_bookmark];
					compression_116[a] *= 6;
					compression_116[a] %= 10000000000;
					temp_read_bookmark -= 116;
				}
				temp_read_bookmark = (read_bookmark - 2); //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_117[a] += Authorship_public[temp_read_bookmark];
					compression_117[a] *= 7;
					compression_117[a] %= 10000000000;
					temp_read_bookmark -= 117;
				}
				temp_read_bookmark = (read_bookmark - 2); //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_118[a] += Authorship_public[temp_read_bookmark];
					compression_118[a] *= 8;
					compression_118[a] %= 10000000000;
					temp_read_bookmark -= 118;
				}
				temp_read_bookmark = (read_bookmark - 2); //Resetting the temporary variable.
				
				for(int a = 0; a < 100; a++)
				{	compression_119[a] += Authorship_public[temp_read_bookmark];
					compression_119[a] *= 9;
					compression_119[a] %= 10000000000;
					temp_read_bookmark -= 119;
				}
			}
			
			//Compression snapshots are active in early stages of Authorship number evolution. They are applied to the compression in the end.
			if((f == 1000) || (f == 2000) || (f == 3000) || (f == 4000) || (f == 5000) || (f == 6000) || (f == 7000) || (f == 8000))
			{	for(int a = 0; a < 100; a++)
				{	snapshot_115[a] += compression_115[a];
					snapshot_115[a] %= 10000000000; //(10^10, results in last ten digits shown.)
					
					snapshot_116[a] += compression_116[a];
					snapshot_116[a] %= 10000000000;
					
					snapshot_117[a] += compression_117[a];
					snapshot_117[a] %= 10000000000;
					
					snapshot_118[a] += compression_118[a];
					snapshot_118[a] %= 10000000000;
					
					snapshot_119[a] += compression_119[a];
					snapshot_119[a] %= 10000000000;
				}
			}
			
			if(Authorship_public[read_bookmark] == 'x') //Navigates to the next contiguous function.
			{	read_bookmark += 2;
			}
			
			else //Skips through the solution ingredients (not utilized for generating deductive lossy compression.)
			{	for(int a = 0; a < 5; a++)
				{	while(Authorship_public[read_bookmark] != '.')
					{	read_bookmark++;
					}
					
					read_bookmark++;
				}
			}
		}
		
		//Constructively combines the compression tables. compression_119[] will hold it all.
		for(int a = 0; a < 100; a++)
		{	compression_119[a] += compression_115[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 2;}
			
			compression_119[a] += compression_116[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 3;}
			
			compression_119[a] += compression_117[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 5;}
			
			compression_119[a] += compression_118[a];
			if((compression_119[a] % 2) == 0) {compression_119[a] *= 7;}
			
			compression_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		//Constructively combines the snapshot tables. snapshot_119[] will hold it all.
		for(int a = 0; a < 100; a++)
		{	snapshot_119[a] += snapshot_115[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 2;}
			
			snapshot_119[a] += snapshot_116[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 3;}
			
			snapshot_119[a] += snapshot_117[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 5;}
			
			snapshot_119[a] += snapshot_118[a];
			if((snapshot_119[a] % 2) == 0) {snapshot_119[a] *= 7;}
			
			snapshot_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		//Applies the snapshots to the last stage in compression. (As the Authorship number evolved over time, snapshots made a record of its early stages.)
		for(int a = 0; a < 100; a++)
		{	compression_119[a] += snapshot_119[a];
			compression_119[a] %= 10000000000; //(10^10, results in last ten digits shown.)
		}
		
		for(int a = 0; a < 100; a++) //Ensures each constituent compression integer is 10 digits long. The Authorship number is now complete.
		{	if(compression_119[a]   < 1000000000)
			{	compression_119[a] += 1000000000;
			}
		}
		
		//The following block-bunch compares the generated number with the given number.
		//Converts the here-generated number (100 integers in compression_119[]) to type array for loading into compression[].
		cout << "Comparing compression to Authorship.number...\n";
		int compression[1000] = {0};
		int compression_write_bookmark = 0;
		for(int a = 0; a < 100; a++)
		{	compression[compression_write_bookmark] =  (compression_119[a] / 1000000000);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 100000000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 10000000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 1000000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 100000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 10000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 1000) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 100) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] = ((compression_119[a] / 10) % 10);
			compression_write_bookmark++;
			compression[compression_write_bookmark] =  (compression_119[a]      % 10);
			compression_write_bookmark++;
		}
		
		//Loads file Authorship.number into Authorship_number[].
		char Authorship_number[1000];
		in_stream.open("Authorship.number");
		for(int a = 0; a < 1000; a++)
		{	in_stream >> Authorship_number[a];
			
			     if(Authorship_number[a] == 48) {Authorship_number[a] = 0;} //(Loaded ASCII characters from file) so converting them to our familiar numbers!
			else if(Authorship_number[a] == 49) {Authorship_number[a] = 1;} //Look to the ASCII table & character assignment in option 2.
			else if(Authorship_number[a] == 50) {Authorship_number[a] = 2;}
			else if(Authorship_number[a] == 51) {Authorship_number[a] = 3;}
			else if(Authorship_number[a] == 52) {Authorship_number[a] = 4;}
			else if(Authorship_number[a] == 53) {Authorship_number[a] = 5;}
			else if(Authorship_number[a] == 54) {Authorship_number[a] = 6;}
			else if(Authorship_number[a] == 55) {Authorship_number[a] = 7;}
			else if(Authorship_number[a] == 56) {Authorship_number[a] = 8;}
			else if(Authorship_number[a] == 57) {Authorship_number[a] = 9;}
			else {cout << "\n\nCosmic ray file corruption.     gx1\n\n"; return 0;}
		}
		in_stream.close();
		
		//Compares the given number with the generated number.
		bool existence_after_comparison = false;
		for(int a = 0; a < 1000; a++)
		{	if(compression[a] != Authorship_number[a]) {cout << "\n\n\nVerification FAILED! Numbers mismatch!\n\n\n"; return 0;}
			
			if(a == 999) {existence_after_comparison = true;} //Is set to true if and only if comparison succeeds to the last iteration
		}                                                     //where each and every test would end the program on mismatch.
		
		
		
		
		
		//The following block-bunch tests the transformation determinants, sub-keys and their five transformations, and the
		//hot zones. (Testing only the functions to which solution ingredients are included in the file Authorship.public.)
		//This is a boolean sieve of Eratosthenes. Zeros are prime, conveniently mapped to their element index.
		//(It is used here like the following example: if(sieve[my_candidate] == 0) then my_candidate is prime.)
		bool sieve[100000] = {1, 1};
		for(int prime = 2; prime < 317; prime++) //317 is sqrt(100000)
		{	for(int a = prime + prime; a < 100000; a += prime) {sieve[a] = 1;}
		}
		
		//Preparation table for the next block-bunch.
		bool b[13500]; //b for binary, will hold the final binary super-string.
		int zeros_counter = 0; //6,000 functions of 13,500 must remain unsolved.  (4/9)
		int ones_counter = 0;  //7,500 functions of 13,500 must be solved.        (5/9)
		
		int read_bookmark_crypt = 0; //Reads from Authorship_public[] but for the purpose of testing solution ingredients.
		bool existence_after_keys = false;
		cout << "Testing solutions to 7,500 multi-way functions...\n";
		for(int f = 0; f < 13500; f++) //Chronologically reads through 13,500 functions in Authorship_public[]. This for loop contains three items.
		{	/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/// If no solution ingredients, skips to the contiguous function ahead. //////////////////////////////////////////////////////////////////////
			if(Authorship_public[read_bookmark_crypt + 496] == 'x')
			{	read_bookmark_crypt += 498;
				
				b[f] = 0;
				zeros_counter++;
			}
			
			/// //////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			/// If solution ingredients are present, they are tested against the current function. ///////////////////////////////////////////////////////
			else
			{	b[f] = 1;
				ones_counter++;
				
				//Reads & grabs the ciphertext, transformation determinant, first sub-key, and the prime-lengths-in-order (identifying properties.)
				int sub_ciphertext_SUB2[2000];
				int sub_ciphertext_SUB4[2000];
				int sub_ciphertext_SUB6[2000];
				
				int transformation_determinant[2000];
				int sub_key[2000];
				int prime_lengths_in_order_SUB2[1000] = {0};
				int prime_lengths_in_order_SUB4[1000] = {0};
				int prime_lengths_in_order_SUB6[1000] = {0};
				
				read_bookmark_crypt += 2001; //Skips through 1st sub-ciphertext.
				
				for(int a = 0; a < 2000; a++) //Loads sub_ciphertext_SUB2[].
				{	sub_ciphertext_SUB2[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				read_bookmark_crypt += 2001; //Skips through 3rd sub-ciphertext.
				
				for(int a = 0; a < 2000; a++) //Loads sub_ciphertext_SUB4[].
				{	sub_ciphertext_SUB4[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				read_bookmark_crypt += 2001; //Skips through 5th sub-ciphertext.
				
				for(int a = 0; a < 2000; a++) //Loads sub_ciphertext_SUB6[].
				{	sub_ciphertext_SUB6[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				for(int a = 0; a < 2000; a++) //Loads transformation_determinant[].
				{	transformation_determinant[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				long long assembled_seed_for_transformation[200] = {0}; //Prepares 200 10-digit seeds from transformation_determinant[]
				int transformation_determinant_read_bookmark = 0;       //for further key transformation.
				for(int a = 0; a < 200; a++)
				{	long long multiplier = 1000000000;
					for(int b = 0; b < 10; b++)
					{	assembled_seed_for_transformation[a] += (transformation_determinant[transformation_determinant_read_bookmark] * multiplier);
						transformation_determinant_read_bookmark++;
						multiplier /= 10;
					}
				}
				
				for(int a = 0; a < 2000; a++) //Loads sub_key[].
				{	sub_key[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				for(int a = 0; Authorship_public[read_bookmark_crypt] != '.'; a++) //Loads prime_lengths_in_order_SUB2[].
				{	prime_lengths_in_order_SUB2[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				for(int a = 0; Authorship_public[read_bookmark_crypt] != '.'; a++) //Loads prime_lengths_in_order_SUB4[].
				{	prime_lengths_in_order_SUB4[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				for(int a = 0; Authorship_public[read_bookmark_crypt] != '.'; a++) //Loads prime_lengths_in_order_SUB6[].
				{	prime_lengths_in_order_SUB6[a] = Authorship_public[read_bookmark_crypt];
					read_bookmark_crypt++;
				}
				read_bookmark_crypt++;
				
				
				
				
				
				//Now that the function and its solution ingredients have been loaded, the testing begins.
				//The sub-key is transformed once for sub-function 2.
				for(int a = 0; a < 1999; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 2.)
				{	sub_key[a] += transformation_determinant[a];
					sub_key[a] = ((sub_key[a] + transformation_determinant[a + 1]) % 10); //[a + 1] means do up to 1998 or seg fault.
				}
				sub_key[1999] = ((sub_key[1999] + transformation_determinant[1000]) % 10); //Last element was not transformed so here it is.
				
				for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
				{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
					
					if((assembled_seed_for_transformation[a] % 2) == 0)
					{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
					else
					{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
				}
				//(1st of 5 total transformations per function.) Each one is different.
				
				
				
				
				
				//Generates 2nd sub-plaintext (hot zone) through deductive reasoning since the key
				//and output are present. The following formula helps extract plaintext quickly.
				//      ______________________________________________ ________________________________________________
				//     |                                              |                                                |
				//     |          if sub-key <= ciphertext            |                     else                       |
				//     |   then plaintext = (ciphertext - sub-key)    |    plaintext = ((10 - sub-key) + ciphertext)   |
				//     |______________________________________________|________________________________________________|
				//
				int sub_plaintext_SUB2[2000];
				for(int a = 0; a < 2000; a++)
				{	if(sub_key[a] <= sub_ciphertext_SUB2[a]) {sub_plaintext_SUB2[a] = (sub_ciphertext_SUB2[a] - sub_key[a]);}
					else {sub_plaintext_SUB2[a] = ((10 - sub_key[a]) + sub_ciphertext_SUB2[a]);}
				}
				
				
				
				
				
				//Checks if sub_ciphertext_SUB2[] is composed entirely of whatever quantity of contiguous primes of digit lengths one to five.
				int read_bookmark_sub_plaintext_SUB2 = 0;
				for(int assembled_candidate, a = 0; prime_lengths_in_order_SUB2[a] > 0; a++) //(prime_lengths_in_order[] contains positive integers 1-5 then all zeros.)
				{	if(prime_lengths_in_order_SUB2[a] == 1) //If expected prime length is 1, grabs 1 digit from sub_plaintext_SUB2[].
					{	assembled_candidate = sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p01\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB2++;
					}
					
					if(prime_lengths_in_order_SUB2[a] == 2) //If expected prime length is 2, assembles 2-digit integer from 2 elements in sub_plaintext_SUB2[].
					{	assembled_candidate = sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 1];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p02\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB2 += 2;
					}
					
					if(prime_lengths_in_order_SUB2[a] == 3) //If expected prime length is 3, assembles 3-digit integer from 3 elements in sub_plaintext_SUB2[].
					{	assembled_candidate = sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 2];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p03\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB2 += 3;
					}
					
					if(prime_lengths_in_order_SUB2[a] == 4) //If expected prime length is 4, assembles 4-digit integer from 4 elements in sub_plaintext_SUB2[].
					{	assembled_candidate = sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 3];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p04\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB2 += 4;
					}
					
					if(prime_lengths_in_order_SUB2[a] == 5) //If expected prime length is 5, assembles 5-digit integer from 5 elements in sub_plaintext_SUB2[].
					{	assembled_candidate = sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 3];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB2[read_bookmark_sub_plaintext_SUB2 + 4];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p05\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB2 += 5;
					}
				}
				
				
				
				
				
				for(int a = 0; a < 1998; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 3.)
				{	sub_key[a] += transformation_determinant[a];
					sub_key[a] = ((sub_key[a] + transformation_determinant[a + 2]) % 10); //[a + 2] means do up to 1997 or seg fault.
				}
				sub_key[1998] = ((sub_key[1998] + transformation_determinant[1005]) % 10); //Last two elements were not transformed so here it is.
				sub_key[1999] = ((sub_key[1999] + transformation_determinant[1010]) % 10);
				
				for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
				{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
					
					if((assembled_seed_for_transformation[a] % 2) == 0)
					{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
					else
					{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
				}
				//(2nd of 5 total transformations per function.) Each one is different.
				//
				//
				//        (Since only the hot zones are checked, transformation continues in preparation for the next hot zone.)
				//
				//
				for(int a = 0; a < 1997; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 4.)
				{	sub_key[a] += transformation_determinant[a];
					sub_key[a] = ((sub_key[a] + transformation_determinant[a + 3]) % 10); //[a + 3] means do up to 1996 or seg fault.
				}
				sub_key[1997] = ((sub_key[1997] + transformation_determinant[1015]) % 10); //Last three elements were not transformed so here it is.
				sub_key[1998] = ((sub_key[1998] + transformation_determinant[1020]) % 10);
				sub_key[1999] = ((sub_key[1999] + transformation_determinant[1025]) % 10);
				
				for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
				{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
					
					if((assembled_seed_for_transformation[a] % 2) == 0)
					{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
					else
					{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
				}
				//(3rd of 5 total transformations per function.) Each one is different.
				
				
				
				
				
				//Generates 4th sub-plaintext (hot zone) through deductive reasoning since the key
				//and output are present. The following formula helps extract plaintext quickly.
				//      ______________________________________________ ________________________________________________
				//     |                                              |                                                |
				//     |          if sub-key <= ciphertext            |                     else                       |
				//     |   then plaintext = (ciphertext - sub-key)    |    plaintext = ((10 - sub-key) + ciphertext)   |
				//     |______________________________________________|________________________________________________|
				//
				int sub_plaintext_SUB4[2000];
				for(int a = 0; a < 2000; a++)
				{	if(sub_key[a] <= sub_ciphertext_SUB4[a]) {sub_plaintext_SUB4[a] = (sub_ciphertext_SUB4[a] - sub_key[a]);}
					else {sub_plaintext_SUB4[a] = ((10 - sub_key[a]) + sub_ciphertext_SUB4[a]);}
				}
				
				
				
				
				
				//Checks if sub_ciphertext_SUB4[] is composed entirely of whatever quantity of contiguous primes of digit lengths one to five.
				int read_bookmark_sub_plaintext_SUB4 = 0;
				for(int assembled_candidate, a = 0; prime_lengths_in_order_SUB4[a] > 0; a++) //(prime_lengths_in_order[] contains positive integers 1-5 then all zeros.)
				{	if(prime_lengths_in_order_SUB4[a] == 1) //If expected prime length is 1, grabs 1 digit from sub_plaintext_SUB4[].
					{	assembled_candidate = sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p06\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB4++;
					}
					
					if(prime_lengths_in_order_SUB4[a] == 2) //If expected prime length is 2, assembles 2-digit integer from 2 elements in sub_plaintext_SUB4[].
					{	assembled_candidate = sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 1];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p07\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB4 += 2;
					}
					
					if(prime_lengths_in_order_SUB4[a] == 3) //If expected prime length is 3, assembles 3-digit integer from 3 elements in sub_plaintext_SUB4[].
					{	assembled_candidate = sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 2];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p08\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB4 += 3;
					}
					
					if(prime_lengths_in_order_SUB4[a] == 4) //If expected prime length is 4, assembles 4-digit integer from 4 elements in sub_plaintext_SUB4[].
					{	assembled_candidate = sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 3];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p09\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB4 += 4;
					}
					
					if(prime_lengths_in_order_SUB4[a] == 5) //If expected prime length is 5, assembles 5-digit integer from 5 elements in sub_plaintext_SUB4[].
					{	assembled_candidate = sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 3];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB4[read_bookmark_sub_plaintext_SUB4 + 4];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p10\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB4 += 5;
					}
				}
				
				
				
				
				
				for(int a = 0; a < 1996; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 5.)
				{	sub_key[a] += transformation_determinant[a];
					sub_key[a] = ((sub_key[a] + transformation_determinant[a + 4]) % 10); //[a + 4] means do up to 1995 or seg fault.
				}
				sub_key[1996] = ((sub_key[1996] + transformation_determinant[1030]) % 10); //Last four elements were not transformed so here it is.
				sub_key[1997] = ((sub_key[1997] + transformation_determinant[1035]) % 10);
				sub_key[1998] = ((sub_key[1998] + transformation_determinant[1040]) % 10);
				sub_key[1999] = ((sub_key[1999] + transformation_determinant[1045]) % 10);
				
				for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
				{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
					
					if((assembled_seed_for_transformation[a] % 2) == 0)
					{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
					else
					{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
				}
				//(4th of 5 total transformations per function.) Each one is different.
				//
				//
				//        (Since only the hot zones are checked, transformation continues in preparation for the next hot zone.)
				//
				//
				for(int a = 0; a < 1995; a++) //Transformation determinant transforms sub-key at current stage (preparation for sub-function 6.)
				{	sub_key[a] += transformation_determinant[a];
					sub_key[a] = ((sub_key[a] + transformation_determinant[a + 5]) % 10); //[a + 5] means do up to 1994 or seg fault.
				}
				sub_key[1995] = ((sub_key[1995] + transformation_determinant[1050]) % 10); //Last five elements were not transformed so here it is.
				sub_key[1996] = ((sub_key[1996] + transformation_determinant[1055]) % 10);
				sub_key[1997] = ((sub_key[1997] + transformation_determinant[1060]) % 10);
				sub_key[1998] = ((sub_key[1998] + transformation_determinant[1065]) % 10);
				sub_key[1999] = ((sub_key[1999] + transformation_determinant[1070]) % 10);
				
				for(int a = 0; a < 200; a++) //Additional constructive transformation of sub_key[] based on the extracted 200 seeds from transformation_determinant[].
				{	srand(assembled_seed_for_transformation[a]); //WRITES ALTERNATING BETWEEN LEFT TO RIGHT & RIGHT TO LEFT. Alternation is based on the 200 seeds.
					
					if((assembled_seed_for_transformation[a] % 2) == 0)
					{	for(int b = 0; b < 2000; b++) //WRITES LEFT TO RIGHT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
					else
					{	for(int b = 1999; b >= 0; b--) //WRITES RIGHT TO LEFT.
						{	sub_key[b] = (sub_key[b] + (rand() % 10));
							sub_key[b] %= 10;
						}
					}
				}
				//(5th of 5 total transformations per function.) Each one is different.
				
				
				
				
				
				//Generates 6th sub-plaintext (hot zone) through deductive reasoning since the key
				//and output are present. The following formula helps extract plaintext quickly.
				//      ______________________________________________ ________________________________________________
				//     |                                              |                                                |
				//     |          if sub-key <= ciphertext            |                     else                       |
				//     |   then plaintext = (ciphertext - sub-key)    |    plaintext = ((10 - sub-key) + ciphertext)   |
				//     |______________________________________________|________________________________________________|
				//
				int sub_plaintext_SUB6[2000];
				for(int a = 0; a < 2000; a++)
				{	if(sub_key[a] <= sub_ciphertext_SUB6[a]) {sub_plaintext_SUB6[a] = (sub_ciphertext_SUB6[a] - sub_key[a]);}
					else {sub_plaintext_SUB6[a] = ((10 - sub_key[a]) + sub_ciphertext_SUB6[a]);}
				}
				
				
				
				
				
				//Checks if sub_ciphertext_SUB6[] is composed entirely of whatever quantity of contiguous primes of digit lengths one to five.
				int read_bookmark_sub_plaintext_SUB6 = 0;
				for(int assembled_candidate, a = 0; prime_lengths_in_order_SUB6[a] > 0; a++) //(prime_lengths_in_order[] contains positive integers 1-5 then all zeros.)
				{	if(prime_lengths_in_order_SUB6[a] == 1) //If expected prime length is 1, grabs 1 digit from sub_plaintext_SUB6[].
					{	assembled_candidate = sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p11\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB6++;
					}
					
					if(prime_lengths_in_order_SUB6[a] == 2) //If expected prime length is 2, assembles 2-digit integer from 2 elements in sub_plaintext_SUB6[].
					{	assembled_candidate = sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 1];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p12\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB6 += 2;
					}
					
					if(prime_lengths_in_order_SUB6[a] == 3) //If expected prime length is 3, assembles 3-digit integer from 3 elements in sub_plaintext_SUB6[].
					{	assembled_candidate = sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 2];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p13\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB6 += 3;
					}
					
					if(prime_lengths_in_order_SUB6[a] == 4) //If expected prime length is 4, assembles 4-digit integer from 4 elements in sub_plaintext_SUB6[].
					{	assembled_candidate = sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 3];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p14\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB6 += 4;
					}
					
					if(prime_lengths_in_order_SUB6[a] == 5) //If expected prime length is 5, assembles 5-digit integer from 5 elements in sub_plaintext_SUB6[].
					{	assembled_candidate = sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 1];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 2];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 3];
						assembled_candidate *= 10;
						assembled_candidate += sub_plaintext_SUB6[read_bookmark_sub_plaintext_SUB6 + 4];
						
						if(sieve[assembled_candidate] != 0) {cout << "\n\n\nVerification FAILED!     p15\n\n\n"; return 0;} //Tests if prime.
						read_bookmark_sub_plaintext_SUB6 += 5;
					}
				}
			}
			
			//You might wonder why then even include cool zones in the Authorship files
			//if they hold only random plaintext, and are excluded in the key_pass test.
			//The ciphertext is produced via (sub_key[a] + plaintext[a]) mod 10.
			//Cool zones utilize random numbers for their plaintext which are then
			//reproduced exactly and as expected. This leaves quite the space for
			//those who need to stuff as much data into these files as possible.
			//And everyone's file being ~138MB, who inserted data and who didn't?
			
			//The read/write_bookmarks and little templates make editing a breeze.
			//Authorship provides these subtle expansion possibilities--awaiting
			//the many problems and needs of heroes yet to come.
			
			if(f == 13499) {existence_after_keys = true;} //Is set to true if and only if the testing of these items succeeds to the last iteration.
		}
		
		//Please refer to the table of digit pair and character assignment from Authorship option 2: "Modify Authorship number."
		if(zeros_counter != 6000) {cout << "\n\n\nVerification FAILED!     0cn\n\n\n"; return 0;} //6,000 functions of 13,500 must remain unsolved.  (4/9)
		if(ones_counter  != 7500) {cout << "\n\n\nVerification FAILED!     1cn\n\n\n"; return 0;} //7,500 functions of 13,500 must be solved.        (5/9)
		
		
		
		
		
		
		
		//The following block-bunch extracts the new number & message, and tests the symbol assignments and correspondence to 5/9.
		//REMINDER: b[] was properly filled at the beginning of the above block-bunch, b[] is a binary representation of solved/unsolved functions.
		//Extracts the new number from b[] and applies it to extracted_number[].
		cout << "Extracts new number & message in binary based on missing solutions...\n";
		int extracted_number[500];
		int r = 0;  //Read bookmark for b[]. Here, it reads the first 500 groups of nine contiguous functions.
		bool existence_after_digits = false;
		for(int a = 0; a < 500; a++)
		{	
			//                                                                                                                                                              number
			//              |              |              |              |              |              |              |              |              |                      fragment
			     if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]= 0; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]= 1; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]= 2; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]= 3; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]= 4; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]= 5; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]= 6; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]= 7; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]= 8; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]= 9; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=10; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=11; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=12; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=13; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=14; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=15; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=16; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=17; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=18; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=19; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=20; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=21; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=22; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=23; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=24; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=25; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=26; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=27; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=28; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=29; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=30; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=31; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=32; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=33; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=34; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=35; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=36; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=37; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=38; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=39; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=40; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=41; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=42; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=43; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=44; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=45; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=46; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=47; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=48; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=49; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=50; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=51; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=52; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=53; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=54; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=55; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=56; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=57; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=58; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=59; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=60; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=61; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=62; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=63; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=64; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=65; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=66; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=67; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=68; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=69; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=70; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=71; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=72; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=73; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=74; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=75; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=76; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=77; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=78; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=79; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=80; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=81; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=82; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=83; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=84; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=85; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=86; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=87; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=88; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=89; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_number[a]=90; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=91; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=92; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=93; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=94; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_number[a]=95; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=96; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=97; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_number[a]=98; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_number[a]=99; r+=9;} //This is 100th (00 - 99.)
			//              |              |              |              |              |              |              |              |              |
			
			else {cout << "\n\n\nVerification FAILED!     ry0\n\n\n"; return 0;}
			
			if(a == 499) {existence_after_digits = true;} //Is set to true if and only if the testing/extraction of these items succeeds to the last iteration.
		}
		
		
		
		
		
		//Reminder: the read bookmark 'r' for b[] is useful here and is not reset.
		//It continues reading the remaining 1,000 groups of nine contiguous functions.
		
		//The following block-bunch extracts the user's message, and tests the symbol assignments and correspondence to 5/9.
		//Extracts the message from b[]
		char extracted_message[1001]; //This, thing, is filled in the following loop (first 1,000 elements.)
		bool existence_after_characters = false;
		for(int a = 0; a < 1000; a++)
		{	
			// Note the first symbol is reference # 96 (the Authorship null symbol.) It being first, speeds up the process. (Ref #96 = 1 1 0 0 1 0 0 1 1)
			//                                                                                                                                                                message
			//              |              |              |              |              |              |              |              |              |                        character
			     if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]='\0'; r+=9;} ///Note the "no char symbol" (reference # 96.)
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= ' '; r+=9;} //(Blank or space.)
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '!'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '"'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '#'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '$'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '%'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '&'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]='\''; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '('; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= ')'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '*'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '+'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= ','; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '-'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '.'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '/'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '0'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '1'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '2'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '3'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= '4'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '5'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '6'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '7'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '8'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '9'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= ':'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= ';'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '<'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '='; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '>'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '?'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '@'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'A'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'B'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'C'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'D'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'E'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'F'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'G'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'H'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'I'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'J'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'K'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'L'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'M'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'N'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'O'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'P'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'Q'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'R'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'S'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'T'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'U'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'V'; r+=9;}
			else if((b[r]== 0 )&&(b[r+1]== 1 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'W'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'X'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'Y'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'Z'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '['; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]='\\'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= ']'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '^'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '_'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '`'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'a'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'b'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'c'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'd'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'e'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 0 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'f'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'g'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'h'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'i'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'j'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'k'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'l'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'm'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'n'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'o'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 0 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'p'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= 'q'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'r'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 's'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 't'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'u'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'v'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= 'w'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= 'x'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'y'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 0 )&&(b[r+2]== 1 )&&(b[r+3]== 1 )&&(b[r+4]== 1 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 0 )&&(b[r+8]== 0 )) {extracted_message[a]= 'z'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 0 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '{'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 0 )&&(b[r+7]== 1 )&&(b[r+8]== 1 )) {extracted_message[a]= '|'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 0 )&&(b[r+8]== 1 )) {extracted_message[a]= '}'; r+=9;}
			else if((b[r]== 1 )&&(b[r+1]== 1 )&&(b[r+2]== 0 )&&(b[r+3]== 0 )&&(b[r+4]== 0 )&&(b[r+5]== 1 )&&(b[r+6]== 1 )&&(b[r+7]== 1 )&&(b[r+8]== 0 )) {extracted_message[a]= '~'; r+=9;} //This makes all 95 printable ASCII characters (but only printable.)
			//              |              |              |              |              |              |              |              |              |
			
			else {cout << "\n\n\nVerification FAILED!     db6\n\n\n"; return 0;}
			
			if(a == 999) {existence_after_characters = true;} //Is set to true if and only if the testing/extraction of these items succeeds to the last iteration.
		}
		
		
		
		
		
		//The following safety procedure attempts to prevent side-channel and block-skipping attacks. These "existence" variables must have
		//been initialized in the last iterations of their testing loops, surpassing many termination commands for failed verification.
		cout << "\n\n\n\n\n\n\n\n\n\n\n";
		
		if(existence_after_comparison == true) {comparison = true; cout << "\n\tCompression matches old number.       (1 of 4)";}
		if(existence_after_keys       == true) {keys       = true; cout << "\n\tKeys satisfy 5/9 of 13,500 functions. (2 of 4)";}
		if(existence_after_digits     == true) {digits     = true; cout << "\n\tNew number corresponds to assignment. (3 of 4)";}
		if(existence_after_characters == true) {characters = true; cout << "\n\tCharacters correspond to assignment.  (4 of 4)";}
		
		if((comparison == true) &&
		   (keys       == true) &&
		   (digits     == true) &&
		   (characters == true))
		{	
			//Writes the new number to file Authorship.number (overwrites.)
			out_stream.open("Authorship.number");
			for(int a = 0; a < 500; a++)
			{	if(extracted_number[a] < 10) {out_stream << '0';} //This ensures for example, "4" turns into "04" (digit pair.)
				out_stream << extracted_number[a];
			}
			out_stream.close();
			
			cout << "\n\n\tVerification SUCCESSFUL!\n\n"
			
			     << "Authorship.number has been overwritten with their new number.\n"
			     << "You can discard any and all old modification information.\n";
			
			if(extracted_message[0] != '\0')
			{	cout << "The user included a message for this authentication event: \n\n";
				
				for(int a = 0; a < 1000; a++) {cout << extracted_message[a];}
				cout << "\n\n";
			}
			else {cout << "The user omitted a message for this authentication event.\n";}
		}
		else {cout << "\n\n\nVerification FAILED!\n\n\n"; return 0;}
		
		
		
		
		
		//Checks if new number is held intact by the storage device.
		//Loads file Authorship.number into Authorship_number[].
		in_stream.open("Authorship.number");
		for(int a = 0; a < 1000; a++)
		{	in_stream >> Authorship_number[a];
			
			     if(Authorship_number[a] == 48) {Authorship_number[a] = 0;} //(Loaded ASCII characters from file) so converting them to our familiar numbers!
			else if(Authorship_number[a] == 49) {Authorship_number[a] = 1;} //Look to the ASCII table & character assignment in option 2.
			else if(Authorship_number[a] == 50) {Authorship_number[a] = 2;}
			else if(Authorship_number[a] == 51) {Authorship_number[a] = 3;}
			else if(Authorship_number[a] == 52) {Authorship_number[a] = 4;}
			else if(Authorship_number[a] == 53) {Authorship_number[a] = 5;}
			else if(Authorship_number[a] == 54) {Authorship_number[a] = 6;}
			else if(Authorship_number[a] == 55) {Authorship_number[a] = 7;}
			else if(Authorship_number[a] == 56) {Authorship_number[a] = 8;}
			else if(Authorship_number[a] == 57) {Authorship_number[a] = 9;}
			else {cout << "\n\nCosmic ray file corruption. Verify again!     SV10\n\n"; remove("Authorship.number"); return 0;}
		}
		in_stream.close();
		
		//Converts extracted_number[] to type array and loads it into sector_accident_reference[].
		int new_number_for_sector_accident_reference[1000];
		int sector_accident_write_bookmark = 0;
		for(int a = 0; a < 500; a++)
		{	new_number_for_sector_accident_reference[sector_accident_write_bookmark    ] = (extracted_number[a] / 10);
			new_number_for_sector_accident_reference[sector_accident_write_bookmark + 1] = (extracted_number[a] % 10);
			sector_accident_write_bookmark += 2;
		}
		
		//Compares the number from file with the number in RAM.
		bool Authorship_number_sector_accident = false;
		for(int a = 0; a < 1000; a++)
		{	if(new_number_for_sector_accident_reference[a] != Authorship_number[a]) {Authorship_number_sector_accident = true; break;}
		}
		
		if(Authorship_number_sector_accident == true)
		{	remove("Authorship.number");
			
			cout << "\n\n\nBad sectors! There's something wrong with your storage device.\n\n"
			
			     << "Verification may have been successful, but your drive could not retain the\n"
			     << "user's new Authorship number. You must verify again to get that new number\n"
			     << "For a quick fix, fill your storage device with a few gigabytes worth of any\n"
			     << "data then try this again. And do not disturb that dummy data as its purpose\n"
			     << "is to consume bad sectors and abused parts of the storage device.\n\n";
			
			return 0;
		}
	}
}
