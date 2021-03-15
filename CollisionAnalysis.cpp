/// Number collision probe - proof of exquisite deductive lossy compression.


/* Place file Authorship.private in the running directory.  This probe generates
the hash of only the  1,008  50-character functions: 3rd line in plaintext file.
Now that you have its hash, save it and compare it to another hash generated for
any slightly-modified version of that .private file;  open the file and manually
replace any character on line 3. Inputs endure other tests upon verification. */

#include <fstream>
#include <iostream>
using namespace std;

int main()
{	ifstream in_stream;
	ofstream out_stream;
	
	//Loads file Authorship.private (must have been generated normally where bulk_verification_efficiency = false.)
	char functions[50400];
	char header_waste;
	in_stream.open("Authorship.private");
	for(int a = 0; a < 46; a++) {in_stream.get(header_waste);}
	for(int a = 0; a < 50400; a++) {in_stream.get(functions[a]); functions[a] -= 32;}
	in_stream.close();
	
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
	
	//Prints number. The last 32 characters of the last function makes this number appear permissive.
	cout << "\n"; for(int a = 0; a < 32; a++) {cout << char(number[a] + 32);}
}
