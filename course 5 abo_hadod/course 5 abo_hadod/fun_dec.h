#pragma once
#include"includes.h"



/// ************************	problem 1	***********************///


void TableHead(int,int);
int GetPosNum(string message);
void show_table(int,int);
string separator(int num);


/// ************************	problem 2	***********************///

bool isPrimenum(int num);
void showPrimeNumbersFrom1(int num);

void printInvertedLetters(int number);
void printLetters(int number);

void printFromAAAtoZZZ();
int findPass(string word);
string get3Letters();
int binarySearch(string a, char letter);
string fillArray();
int findTrialsbyBinarySearch(string word);
char generateRandomNum(int start,int end);
string generateKey(int length, int separator);
void generateIP(int num);
void readArray(int arr[],int& size);
void printArray(int arr[], int size);

void getPrimeNumInArray(int arr1[],int arr2[],int arr1length,int& arr2length);
void FillArrayWithRandomNumbers(int arr[],int& arrlength);
void fillArrayfrom1toN(int arr[],int& arrlength);
void arrayShuffling(int arr[],int arrlength);
void reverseArrayByCopy(int arr1[], int arr2[], int arrlength);
void inputInArray(int arr[], int& arrlength,int num );




///----------------------  project math game --------------------///


enum operation { plus = 1, minus, cross, division, mix };
enum level { easy = 1, med, hard, mix };
struct stats
{
	short true_answers = 0;
	short false_answers = 0;
};
struct stQuestion
{
	level question_Level;
	operation question_Operation;
	int correct_answer = 0;
	int user_answer = 0;
	bool true_ans = false;
};