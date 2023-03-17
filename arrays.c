#include <stdio.h> //iclusion of standard library input/output
#include <stdlib.h> // iclusion of <stdlib.h> library - I did some reserach and found this library to be able to use exit() function
#include <ctype.h> // inclusion od <ctype.h> library - another my own reserach giveme possibility to use fuction to change lowercases to uppercases, and becouse of this I am able to use both letters in menu selection.

int main(void) {
  char opt;    // variable to read menu option
  int arr[30]; // array declaration
  int i, value1, temp;


  printf("How many values would you like to add to the array? Confirm each one by enter (1-30): ");//asking user for amount of numbers to type into the array
  scanf("%d", &value1);//reading users input

  printf("Enter values to add to the array: \n");//asking user to type in values which want to add
  for (i = 0; i < value1; i++) {// for loop to print off current array values
    printf("Enter value %d: ", i+1);
    scanf("%d", &arr[i]);
  }
  // adding -1 to last element of the array
  arr[value1] = -1;

 

  while (1) { /*  while loop to always display menu until appropriate action
                       taken to stop program */

    int ch;// this line and line below are helpul with multiple char issues becouse of this part of code menu is below is diplayed stable
    while ((ch = getchar()) != '\n' && ch != EOF);
    
    // menu options
    printf("\n\n---------------------------------------------------------------"
           "----\nPlease enter your choice from the following menu: \n\nA - "
           "Display all numbers\nB - Calculate the mean and range\nC - Swap "
           "two numbers\nD - Replace a single number\nE - Repopulate full "
           "array\nF - Find the MEDIAN value in the array\nX - "
           "Exit\n-------------------------------------------------------------"
           "------\n");

        opt = getchar();//The getchar() function is used to receive input from the user. It reads a single character from the standard input (usually the keyboard) and returns it as an int value. In this case, the value is then stored in the variable opt
        opt = toupper(opt);//as mentioned above toupper() function changing lowercases int upper cases, and now I can eassily use both letters as a menu selection

    /* below are few "if" statements to to create logic for ach option in the
       menu including uppercases and lowercases */
    
        switch (opt)
          {
            case 'A':
              i=0;
              printf("\n\nCurrent array values are:\n");
              while(arr[i] != -1) { //while loop using terminator -1 finish looping
                printf("%d ", arr[i]);
                i++;
              }
            break;
            case 'B':
            {
              // below are variable declarations
              float sum = 0;
              float mean;
        
               printf("\n\nCurrent array:\n");//for loop to print current array 
                for (int i = 0; i < value1; i++) 
                  {
                    printf("%d\t", arr[i]);
                  }
        
              for (int i = 0; i < value1; i++) //"for" loop to sum all array elements
              {
                sum += arr[i];
              }
        
              mean = sum / value1; //calculation of mean and saving into variable "mean"
        
              printf("\n\nThe MEAN of array elements above is: %.2f\n", mean);
              //Below code has been modified to be able to use terminator -1 in while loop
              int max = arr[0];
              int min = arr[0];
              i = 0;
              
              while (arr[i] != -1) {//while loop using -1 terminator to find out the range 
                if (arr[i] < min) 
                {
                  min = arr[i];
                }
                
              if (arr[i] > max) 
                {
                  max = arr[i];
                }
                i++;
              }
          
              printf("The RANGE of elements above is %d to %d  = %d\n", min, max, max - min); //calculation of the "Range" what is maximum value minus minimum value
        
            }
            break;
            case 'C':
            {
                 printf("\n\nCurrent array:\n");//for better user experience printing off current array values
                for (int i = 0; i < value1; i++) 
                  {
                    printf("%d\t", arr[i]);
                  }
              
              //Variable declarations
              int sel1, sel2, next, i = 0;
        
              printf("\n\nEnter 1st number to swap: "); //asking user for 1st number to swap
              scanf("%d", &sel1);// reading user answer
              printf("Enter 2nd number to swap: ");//asking user for 2nd number to swap                                         
              scanf("%d", &sel2);// asking for user answer
        
              
              //Below code has been modified to be able to use terminator -1 in while loop
              while (arr[i] != -1)// while loop using terminator -1 to finish the loop
              {
                //code below swapping numbers chosen above
                if (arr[i] == sel1) 
                {
                 temp = arr[i];
                 arr[i] = sel2;
                }
                else if (arr[i] == sel2) 
                {
                  arr[i] = temp;
                }
                i++;
              }
        
              printf("\n\nBelow are new array elements - SWAP COMPLETED \n"); //for better user experience printing off updated array after changes inputted before
              for (int i = 0; i <= value1-1; i++) //"for" loop to print off new updated array elements when swap completed
              {
                printf("%d\t", arr[i]);
              }
        
            }
            break;
            case 'D':
            {
              // variable declarations
              int num1;
        
              /* printing off array elements and them indexes for better user experience
               while using this option in the program */
              printf("\n\n\nCurrent array elements are: \n");
              for (int i = 0; i < value1; i++) { //for loop to print off array elements
                printf("%d\t", arr[i]);
              }
        
              printf(
                  "\n\nEnter element value you want to replace: "); /* asking user for a
                                                                       current element
                                                                       value to replace */
              scanf("%d", &num1); // reading user selection
           
              i = 0;
              while (arr[i] != -1) //while loop using -1 as a terminator to replace a single number in the array
                {
                    if(arr[i] == num1)
                    {
                        printf("Enter a new value to replace %d: ", num1);
                        scanf("%d", &arr[i]);
                    }
                    i++;
                }
        
              
              printf("\n\nUpdated array as per below: \n"); //for better user experience printing off updated array after changes
              for (int i = 0; i < value1;
                   i++) /*"for" loop to print off new updated array elements when
                        replacement completed*/
              {
                printf("%d\t", arr[i]);
              }
            break;
            case 'E':
            {
              // variable declarations
        
              int num;
        
              /*printing off array elements and them indexes for better user experience 
              while using this option in the program*/
              printf("\n\n\nCurrent array elements are: \n");//for better user experience printing off current array
              for (int i = 0; i < value1; i++) { //for loop to print off all array elements
                printf("%d\t", arr[i]);
              }
              /*asking user to provide new set of 9 elements values to replace all
              elements in the array printed above*/
              printf("\n\nTo change above set of numbers, please enter %d values to "
                     "change current values of the array above. \nEach number confirm "
                     "by ENTER\n", value1);
              //code below has been modified to be able to use -1 as a terminator in while loop
                i = 0;
                while (arr[i] != -1) //while loop using -1 as a terminator and to read new array values
                {
                  printf("Enter value: ");
                  scanf("%d", &value1);
                  arr[i] = value1;
                  i++;
                }
              
              printf("\n\nNew updated array elements values are as per below: \n");//for better user experience printing off updated array after changes
              for (int i = 0; i < value1;
                   i++) /*"for" loop to print all current array elements values after
                        all previous one has been replaced*/
              {
                printf("%d\t", arr[i]);
              }
        
            }
            break;
            case 'F':
            {
              int j, k;
              float temp = 0, median;
        
              i = 0;
              while (arr[i] != -1) // while loop using -1 as a terminator 
              {
               //sort the array using bubble sort algorithm
                for (int j = 0; j < value1-i-1; j++) 
                {
                  if (arr[j] > arr[j+1]) 
                  {
                      temp = arr[j];
                      arr[j] = arr[j+1];
                      arr[j+1] = temp;
                  }
                }
                i++;
              }
        
              //median calculation
              if (value1 % 2 == 0)
                median = (arr[(value1 / 2) - 1] + arr[(value1 / 2)]) / 2.00 ;
              else
                median = arr[(value1 / 2)];
        
              // printing results 
              printf("\n\n");
              for (k = 0; k < value1; k++)
                printf("%d\t", arr[k]);
              
              printf("\nMedian is %.2f\n", median);
        
            }
            break;
            case 'X':
            {
              exit(0); // ending program on the user request if "F" or "f" selected
            }
        
            default:
            printf("Sorry, your input is invalid. Please enter either A, B, C, D or E");
            }
        }
  }
}

// used the library <stdlib.h> to be able to use exit() function to terminate program this. It was my individual research. This library contains functions for memory management, process control, conversions, and random number generation. Popular and good to know functions from this library are: malloc(), calloc(), realloc(), free(), atoi(), atof(), rand(), srand(), and exit()
/* used the library <ctype.h> to be able to use toupper() function for menu purposes. It was my individual research as well. This library contains functions for classifying and transforming indyvidual characters, most popular ones good to know are:
-isdigit()- checking for a decimal digit 
-character islower()- checking for a lowercase letter
-isupper()- checking for an uppercase letter
-tolower()- converting an uppercase letter to lowercase equivalent.
-toupper()- converting a lowercase letter to uppercase equivalent.*/
// used switch to choose menu options instead of loops or if statements 
// used getchar() function as a menu selection 