#include<stdio.h>
#include<stdlib.h>
#include<math.h>

//NAME : Athanasios Bubulinis
//ID: 114801485
//Lab 6 Part 1 Exersize 1

//INPUT FILE MUST BE NAMED "InputFile2.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile2.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile2.txt" TO FUNCTION

int main(){
	
	float runtime = 0, total = 0, average = 1, current = 0, currentDecPlac = 0;	//defines all needed floats
	char ch;	int in, isNeg = 1, eVal = -1;		//creates an empty char	and an empty int
	FILE *input_file;								//creates FILE for input
	input_file = fopen("InputFile2.txt","r");		//opens input as READ (r)
	if(input_file==NULL){							//if a file failed to open 
		printf("NULL/FAILED");						//prints FAILED
		exit(1);									//program ends
	}
	printf("\nNumbers Read - ");
	while((ch=fgetc(input_file))!=EOF){				//fgetc gets current charavyer in given file and increments per run
		if(ch=='-'){	isNeg = -1;	}
		else if(ch == 'e' || ch == 'E'){	eVal = 0;	}
		else if(ch >= '0' && ch <= '9' && runtime!=2){		//if ch is between 1 and 9 
		in = ch - '0';							//converts to int
			if(eVal==-1){
				if(runtime==1){	currentDecPlac++;	}	//if a decimal place was present prior, currentDecPlacc++
				current = (current * 10) + in;	}		//current value updates	
			else{
				eVal = (eVal * 10) + in;
			}
		}	
		else if(ch=='.'){	runtime++;			}	//else if .1 added to runtime and average(used to divide total)
		else{current = current / pow(10, currentDecPlac);//makes current value decimally accurate
			printf(" %f ", (current*isNeg));							//pritns for debugging
			printf(" %f ", eVal);
			current = current * pow(10, eVal);
			total = total + (current*isNeg);					//adds it to total
			average++; currentDecPlac = 0;	current = 0; runtime = 0; isNeg = 1; eVal = -1;//resets values
		}
	}
	if(current!=0){current = current / pow(10, currentDecPlac);//makes current value decimally accurate
			printf(" %f ", (current*isNeg));							//pritns for debugging
			printf(" %f ", eVal);
			current = current * pow(10, eVal);
			total = total + (current*isNeg);					//adds it to total
			currentDecPlac = 0;	current = 0; runtime = 0; isNeg = 1; eVal = -1;	}//resets values
	average = total / average;						//creates average
	printf("\nThe total was %f", total);			//prints total
	printf("\nThe average was %f", average);		//prints average
	fclose(input_file);								//done with input so closes input file
}
