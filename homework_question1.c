#include<time.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAXGUESSES 6
//NAME : Athanasios Bubulinis
//ID: 114801485
//Lab 6 Homework 6 Question 1

//INPUT FILE MUST BE NAMED "InputFile4.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile4.txt" TO FUNCTION
//INPUT FILE MUST BE NAMED "InputFile4.txt" TO FUNCTION


char lowerCaser(char thischar){ //returns char, takes char input
    if(thischar>='A'&&thischar<='Z'){   return(thischar+32);  }     //adds ascii value to equate to lower
    else{   return(thischar);}                                      //else returns value
}
char upperCaser(char thischar){ //returns char, takes char input
    if(thischar>='a'&&thischar<='z'){   return(thischar-32);  }     //subtracts ascii value to equate to lower
    else{   return(thischar);}                                      //else returns value
}

int main() {
    char word[6], guess[6], progress[6] = "xxxxx"; FILE *file;             //new char and file 
    int fileWords = 0, randIndex, guessCount = 0;           //total words in file and random word index
    srand(time(NULL));                      //rand num generator

    file = fopen("InputFile4.txt", "r");    //opens file
    if(file == NULL) {                     //if unopened
        printf("FILE COULD NOT BE OPENED; CHECK ROOT DIRECTORY;!\n");
        exit(1);                            //exits
    }
    while(fscanf(file, "%s", word) != EOF){   fileWords++;    }   //counts all words in file
    randIndex = rand() % fileWords;         //getting random file using total words
    rewind(file);                           //moves to pointer

    for(int i = 0; i < randIndex; i++){   fscanf(file, "%s", word);   }     //sets word as guesses word
    fclose(file);                                                           //closes file
    for (int i = 0; i < 5; i++) {word[i] = lowerCaser(word[i]); }                     //makes word all lower case
    printf("Random word: %s\n", word);                                      //prints word


    printf("\nWILDDLE(Wordle): You have 6 guesses to guess the 5 letter word. If the letter you inputted was in the correct spot, it will be UPPERCASE. If the letter is in the word, but in the wrong spot it will be LOWERCASE(may only be one of this letter in word). All else are discarded. Have fun\n\n\n");      //prints word
    while((strcmp(word, progress) != 0) && guessCount < MAXGUESSES)     //if word and progress are the same or guesscount is surpassed then  ends loop
    {
        printf("Input a 5 letter guess : "); scanf(" %s", &guess);      //getting guess
        for (int i = 0; guess[i] != '\0'; i++) { guess[i] = lowerCaser(guess[i]); }   //makes guess all lower case

        if(strcmp(word, guess) == 0){   //if first try guess
            strcpy(progress, word);     //sets word and progress to be equal
        }
        else{
            for(int i = 0; i < 5; i++){ //loops through each char in word
                for(int j = 0; j < 5; j++){ //loops through each char in guess
                    if(word[i]==guess[j]){      //if any similar characters
                        progress[j] = lowerCaser(guess[j]); //adds it to progress in same pos in guess as lower case(wrong spot but in word)
                    }                           //end logic
                }                           //end loop
            }                           //end loop
            for(int i = 0; i < 5; i++){ //loops through each char in word and guess
                if(word[i]==guess[i]){  //if same 
                    progress[i] = upperCaser(word[i]);  //set as uppercase version of letter in progress at same pos(correct spot in word)
                }
            }printf("Current guess:                                                         %s\n", progress);      //prints word
        }guessCount++;  //adds to amount of guesses
    }
    if(strcmp(word, guess) == 0){   //if word and guess is same, give ending message
        printf("Conrgats, you got the word, %s\n", word);
    }
    else{                           //else give losing message
        printf("Sorry, you're out of guesses, try again.");
        printf("\nWord was %s.", word);

    }
}
