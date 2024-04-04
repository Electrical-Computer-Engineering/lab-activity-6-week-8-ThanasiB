#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//NAME : Athanasios Bubulinis
//ID: 114801485
//Lab 6 Part 1 Exersize 1

//INPUT FILE MUST BE NAMED "InputFile3.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile3.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile3.txt" TO FUNCTION

int main() {
    int x = 0, y = 0, dPos;							//inital x, y, distance values as ints
    char input[10];										//input value as string
    FILE *file = fopen("InputFile3.txt", "r");			//initialized input file
    if(file == NULL){									//if cant find input file
        printf("\nERROR - FILE COULD NOT BE FOUND; TRY CHECKING ROOT FOLDER");
        exit(1);										//error msg and exit status 1
    }
    while(fscanf(file, "%s %d", input, &dPos) != EOF){	//fscan syntax(for me)fscanf(FILENAME, " %s %d ", string, &intval)
        if(strcmp(input, "LEFT") == 0){	x -= dPos;	}			//if left, subtract x val
        else if(strcmp(input, "RIGHT") == 0){	x += dPos;	}		//if right, add x val
		else if(strcmp(input, "UP") == 0){	y += dPos;  }		//if up, add y val
		else if(strcmp(input, "DOWN") == 0){	y -= dPos;  } 		//if down, subtract y val
		else if(strcmp(input, "INITIAL") == 0){x = dPos;	fscanf(file, "%d", &y);}	//if initial, get from file and set
        printf("Pos: %d %d\n", x, y);		//print it out
    }	fclose(file);	//closes file
}

