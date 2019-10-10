#include <stdio.h>
#include <stdbool.h>


int main(int argc, const char* argv[])
{

	int n = 0;
	printf("%s\n", "Enter a number between 1 and 64");
	while(n < 1 || n > 64)
	{
		scanf("%d", &n);
	}
	int array[n];
	int temp;
	int binary[n];
	int sbinary[n];
	int reversed[n];
	int sdecimal = 0;
	int digit = 1;
	int usdecimal = 0;
	bool first1 = true;

	for (int i = 0; i < n; ++i)
	{
		printf("%s %d %s\n", "Enter bit ", i, ":");
		scanf("%d", &temp);
		while(temp != 1 && temp!= 0)
		{
			printf("%s %d %s\n", "Bad input. Enter bit ", i, ":");
			scanf("%d", &temp);
		}	
		array[i] = temp;	
	}



	for (int i = 0; i < n; ++i)
	{
		binary[i] = array[n-1-i];
	}
	printf("%s", "Binary: ");
	for (int i = 0; i < n; ++i)
	{
		printf("%d", binary[i]);
	}
	printf("%s\n", "");
	for (int i = 0; i < n; ++i)
	{
		while (first1)
		{
			while(array[i] == 0 && i < n)
				{
					sbinary[i] = array[i];
					i++;
				}
			if (i < n && array[i] == 1)
			{
				sbinary[i] = 1;
				i++;
			}
			first1 = false;
		}
		if (i < n)
		{
			if (array[i] == 0)
			{
				sbinary[i] = 1;
			}
			else
			{
				sbinary[i] = 0;
			}
		}
	}
	for (int i = 0; i < n; ++i)
	{
		reversed[i] = sbinary[n-1-i];
	}
	for (int i = 0; i < n; ++i)
	{
		if (binary[i] == 1)
		{
			for (int j = 0; j < n-1-i; ++j)
			{
				digit = digit * 2;
			}
			usdecimal = usdecimal + digit;
			digit = 1;		
		}
	}
	int tempdecimal = usdecimal;

	if (n % 4 == 0)
	{
		printf("%s", "Hexadecimal: 0x");
		int arraylength = n/4;
		char hex[arraylength];
		for (int i = 0; i < arraylength; ++i)
		{
			if(tempdecimal%16 < 10)
				hex[i] = 48 + (char)tempdecimal%16;
			else if (tempdecimal%16 == 10)
				hex[i] = 'A';
			else if (tempdecimal%16 == 11)
				hex[i] = 'B';
			else if (tempdecimal%16 == 12)
				hex[i] = 'C';
			else if (tempdecimal%16 == 13)
				hex[i] = 'D';
			else if (tempdecimal%16 == 14)
				hex[i] = 'E';
			else
				hex[i] = 'F';
			tempdecimal = tempdecimal/16;
		}
		for (int i = 0; i < arraylength; ++i)
		{
			printf("%c", hex[arraylength-i-1]);
		}
	}
	else
	{
		printf("%s", "Hexadecimal: 0x");
		int arraylength = n/4 + 1;
		char hex[arraylength];
		for (int i = 0; i < arraylength; ++i)
		{
			if(tempdecimal%16 < 10)
				hex[i] = 48 + (char)tempdecimal%16;
			else if (tempdecimal%16 == 10)
				hex[i] = 'A';
			else if (tempdecimal%16 == 11)
				hex[i] = 'B';
			else if (tempdecimal%16 == 12)
				hex[i] = 'C';
			else if (tempdecimal%16 == 13)
				hex[i] = 'D';
			else if (tempdecimal%16 == 14)
				hex[i] = 'E';
			else
				hex[i] = 'F';
			tempdecimal = tempdecimal/16;
		}


		for(int i = 0; i < arraylength; i++)
		{
			printf("%c", hex[arraylength-i-1]);
		}
		
	}

	printf("%s\n", "");
	if (binary[0] == 0)
	{
		printf("%s%d\n", "Decimal (signed): +", usdecimal);
	}
	else
	{
		for (int i = 0; i < n; i++)
		{
			if (reversed[i] == 1)
			{
				for (int j = 0; j < n-1-i; ++j)
				{
					digit = digit * 2;
				}
				sdecimal = sdecimal + digit;
				printf("%d\n", sdecimal);
				digit = 1;
			}
		}
		printf("%s%d\n", "Decimal (signed): -", sdecimal);
	}
	printf("%s%d\n", "Decimal (unsigned): ", usdecimal);

	return 0;
}