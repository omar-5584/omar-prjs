#include"includes.h"
#include "fun_dec.h"


int GetPosNum(string message)
{
	cout << message;
	int num;
	do 
	{
		cin >> num;
		if (num < 1)
		{
			cout << "Enter a correct number:";
		}
	} while (num<1);

	return num;

}
void TableHead(int from,int to)
{
	string HorLine(11*(to-from),'_');
	cout << "\n\t\t\tMultiplication Table from " << from << " to " << to<<endl<<endl;

	for (int i = from;i <= to;i++)
	{
		cout << "\t" << i;
	}
	cout << endl << HorLine<<endl;

}
string separator(int num)
{
	if (num > 9)
		return"  |";
	else
		return"   |";

}
void show_table(int from ,int to)
{
	for (int i = from;i <= to;i++)
	{
		cout << i << separator(i);
		for (int j = from;j <= to;j++)
		{
			cout << "\t" << i * j;

		}
		cout << endl;
	}
}


bool isPrimenum(int num)
{
	for (int i = 2;i <= num / 2;i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}
void showPrimeNumbersFrom1(int num)
{

	for (int i = 1;i <= num;i++)
	{
		if (isPrimenum(i))
		{
			cout << i << endl;
		}
		
	}
}


void printInvertedLetters(int number)
{
	for (int i = 65 + number - 1;i >= 65;i--)
	{
		for (int j = 65;j <= i;j++)
		{
			cout << (char)i;
		}
		cout << endl;
	}
}
void printLetters(int number)
{
	for (int i = 65;i < 65 + number;i++)
	{
		for (int j = i;j >= 65;j--)
		{
			cout << (char)i;
		}
		cout << endl;

	}


}

void printFromAAAtoZZZ()
{

	for (int i = 65;i <= 90;i++)
	{

		for (int j = 65;j < 90;j++)
		{

			for (int k = 65;k < 90;k++)
			{
				cout << (char)i << (char)j << (char)k << endl;
			}
		}
	}
}

string get3Letters()
{
	string word;
	do
	{
		cout << "Please Enter 3 letters:";
		cin >> word;

	} while (word.size()!=3);
	return word;
}

int findPass(string word)
{
	int cnt = 0;
	string wordinloop = "";
	for (int i = 65;i <= 90;i++)
	{

		for (int j = 65;j <= 90;j++)
		{

			for (int k = 65;k <= 90;k++)
			{
				wordinloop.clear();
				wordinloop += (char)i;
					wordinloop += (char)j;
					 wordinloop += (char)k;
				 cout << "Trial[" << cnt + 1 << "]: " << wordinloop<<endl;
				 if (wordinloop == word)
				 {
					 cout << "\n\npassword is " << word << endl;
					 system("color 2F");
					 return cnt+1;
				 }
				 cnt++;
			}
		}
	}
	
}

string fillArray()
{
	string letters;
	for (int i = 65;i <= 90;i++)
	{
		letters.push_back((char)i);
	}
	return letters;
}
int binarySearch(string a, char letter)
{
	int start = 0, end = 25,mid,ans=0,cnt=0;
	while (start <= end)
	{
		mid = (start + end) / 2;
		if (a[mid] == letter)
		{
			ans = mid;
			break;
		}
		else if (a[mid] > letter)
		{
			end = mid - 1;
		}
		else if (a[mid] < letter)
		{
			start = mid + 1;
		}
		cnt++;
	}
	return cnt;
}
int findTrialsbyBinarySearch(string word)
{
	int cnt = 0;
	string array = fillArray();
	for (int i = 0;i < 3;i++)
	{
		cnt += binarySearch(array,word[i]);
	}

	return cnt;
}


char generateRandomNum(int start, int end)
{
	 return rand() % (end - start + 1) + start;
}

string generateKey(int length,int separator)
{
	string word="";
	for (int i = 1;i <= length;i++)
	{
		if (i % separator == 0)
		{
			word += "-";
			continue;
		}
		word += generateRandomNum(65,90);
	}

	return word;
}

void generateIP(int num)
{
	for (int i = 1;i <= num;i++)
	{
		cout << "Key [ " << i << " ] ---> " << generateKey(19,5)<<endl;
	}
}

void readArray(int arr[], int& size)
{
	cout << "Enter the array size:";
	cin >> size;
	cout << "\nEnter array elements:";
	
	for (int i = 0;i < size;i++)
	{
		cin >> arr[i];
	}
}

void printArray(int arr[], int size)
{
	cout << "Array elements:  \n";
	for (int i = 0;i < size;i++)
	{
		cout<< arr[i]<<"\t";
	}
	cout << endl;
}
void getPrimeNumInArray(int arr1[], int arr2[], int arr1length, int& arr2length)
{
	int cnt = 0;
	for (int i = 0;i < arr1length;i++)
	{
		if (isPrimenum(arr1[i]))
		{
			arr2[cnt] = arr1[i];
			cnt++;
		}
	}

	arr2length = cnt;

}

void FillArrayWithRandomNumbers(int arr[], int& arrlength)
{
	
	
	for (int i = 0;i < arrlength;i++)
	{
		arr[i] = generateRandomNum(1,10);
	}
}

void fillArrayfrom1toN(int arr[], int& arrlength)
{
	cout << "Enter how many numbers do you want :";
	cin >> arrlength;
	for (int i = 0;i < arrlength;i++)
	{
		arr[i] = i + 1;
	}
}

void arrayShuffling(int arr[], int arrlength)
{
	for (int i = 0;i < arrlength;i++)
	{
		swap(arr[generateRandomNum(0,arrlength)], arr[generateRandomNum(0, arrlength)]);
	}
}



void reverseArrayByCopy(int arr1[], int arr2[], int arrlength)
{
	for (int i = 0;i < arrlength;i++)
	{
		arr2[i] = arr1[arrlength - i - 1];
	}
}

void inputInArray(int arr[], int& arrlength, int num)
{
	arr[arrlength] = num;
	arrlength++;
}
