/*
https://www.geeksforgeeks.org/a-program-to-check-if-strings-are-rotations-of-each-other/
Geeks solution uses strstr built-in function(which uses KMP), has the complexity O(len(a) + len(b))

DOUBT: Why allot the char pointer 'temp' a space of (size*2 + 1) ? Wouldn't size1*2 suffice? 
Is it for the \0 character in char arrays in C?  

========================================================================================


Question 2 (optional):
Given 2 strings, check whether one of the strings is a rotation of the other.
Ex: 
1) compsoc occomps
Function returns TRUE as the words are rotations of each other

2) codebuddy cobuddyde
Function returns FALSE as the words are permutations of each other but not rotations.

3) ABCD CDAB ; O/P = 1

4) ABCD ACBD  ;  O/P = 0

*/

// Append the second string with it's own copy, then search for the presence of the first string within the modified second string.
// O((length of first-string) ^ 2) without strstr built-in function

#include<bits/stdc++.h>
using namespace std;

bool check(char *a, char *b);

int main()
{
	char *a, *b;
	
	// trouble in input of strings.
	scanf ("%s", a);

	// the second string is not being input. When printed, null is seen and hence seg-fault is caused.
	fflush(stdin);
	scanf ("%s", b);

	printf("%s %s\n", a, b);

	cout << check(a, b) << "\n";

	return 0;
}

bool check(char *a, char *b)
{
	 
/*
	instead of using the below loop to search for a substring,
	it's more appropriate to use the built-in C function strstr
*/

	// Decl in string.h: char* strstr(const char *haystack, const char *needle);
	// FUNFACT: strcasestr() does the same thing, IGNORING the case-sensitivity

	strcat(b, b);
	void *ptr = strstr(b, a); // Time complexity of strstr: O(len(a) + len(b))

	return (ptr == NULL ? 0 : 1);


/*
	b = b + b;
	int l = a.size(), i = 0;
	while(i < l) 
	{
		// time complecity of substr is linear in the length of the returned object
		if(a == b.substr(i, l))
			return 1;
		++i;
	}

	return 0; 
*/

}