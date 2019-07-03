Purpose: This program displays a menu
to the user containing information
about a politician. If the menu item is
unknown, the user is allowed to enter
that information.
Assumptions: It is assumed that the user 
knows what they can and cannot input from
the given directions provides. The program
accepts characted and integer inputs.
Bugs: When the user enters something invalid,
sometimes the program gets stuck in the while 
loop and the user is not allowed to input 
anything else. 
Please compile with the -lm link.*/

// Header File

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
void menu();
int check();

// This function prints the menu to the user
void menu() {
	printf("(1) Enter Name\t\t\t\t\t(6) Display the Data\n");
        printf("(2) Enter Years, Party, Office, and State\t");
        printf("(7) Clear all Data\n");
        printf("(3) Enter Age and Sex\t\t\t\t(8) Quit\n");
        printf("(4) Enter Contacts\n(5) Enter Contributions and Lies\n");
        printf("Select a menu option: ");

	
}
// This function allows the user to select a menu option
// and checks to make sure the input is a valid selection.
int check() {
        int choice, invalid;
	// User Selection
        	invalid = 0;
		scanf("%d", &choice);
        	while (invalid == 0) {
                	if (choice < 1 || choice > 8) {
                        	printf("Not a valid selection. Please try again: ");
				scanf("%d", &choice);
                		invalid = 0;
			}
                	else {
                        	invalid = 1;
                	}
        	}
		return choice;
}
 
int main() {
	// Variables
	int choice, i, invalid = 0, partyNum = 0; 
	// Menu
	menu();
	choice = check();
	
	// Input
	char firstName[33] = "?????";
	char middleName = '?';
	char lastName[34] = "?????";
	char suffix[3] = "???";
	char years[2] = "??";
	char office[33] = "?????";
	char state[2] = "??";
	char age[2] = "??";
	int ageD[1];
	char sex = '?';
	char twitter[15] = "?????";
	char phone[10] = "??????????";
	float contributions = 0;
	float lies = 0;
	int loop = 0;
	float ratio = 0;
	while (loop == 0) { 
	switch (choice) {
	case 1: {
		// First Name
			invalid = 0;
			printf("Please enter a first name: ");
		// Loops until a valid first name is input
			while (invalid == 0) {
				scanf("%32s",firstName);
				for (i=0; i<32; i++) {
					if (firstName[i] == '\0') {
						invalid = 1;
						break;
					}
					if (firstName[31] != '\0') {
						printf("Your input has too many characters. ");
						printf("Please try again: ");
						invalid = 0;
						break;
					}
				}
			}	 
		// Middle Initial	
			printf("Please enter a middle initial. If there is no middle");
			printf(" initial, enter '?': ");
			scanf(" %c", &middleName);
		// Last Name
			invalid = 0;
			printf("Please enter a last name: ");
			while (invalid == 0) {
                                scanf("%s",lastName);
                                for (i=0; i<32; i++) {
                                        if (lastName[i] == '\0') {
                                                invalid = 1;
                                                break;
                                        }
                                        if (lastName[31] != '\0') {
                                                printf("Your input has too many characters. ");
                                                printf("Please try again: ");
                                                invalid = 0;
                                                break;
                                        }
                                }
                        }
		// Suffix
			invalid = 0;
			printf("Please enter a suffix. If you wish to not enter a suffix,");
			printf(" then enter ""???"": ");
			while (invalid == 0) {
				scanf("%s", suffix);
					if (suffix[3] != '\0') {
						printf("Your input has too many characters. ");
						printf("Please try again: ");
						invalid = 0;
					}
					else {
						invalid = 1;
					}
			}
			
                        printf("\n");
		// Display menu
		menu();
		choice = check();
		loop = 0;
		break;
	}
	case 2: { // Years, Party, Office, and State
		// Years
		invalid = 0;
		printf("Enter the number of years served (0 to 99): ");
		while (invalid == 0) {
			scanf("%s", years);
			for(i = 0; i<=2; i++) {
				if (years[i] == '\0') {
					invalid = 1;
					break;
				}
			}
			// checks if it is a two digit input
			if (years[2] == '\0'){
                	//	digit[0] = years[0] - '0';
                	//	digit[1] = years[1] - '0';
				invalid = 1;
			}
			else {
				printf("You did not enter a two digit number. Please try again: ");
				invalid = 0;
			}


		}
		// Political Party
		printf("\n1 - Constitution\t\t2 - Democrat\n3 - Green\t\t\t4 - Libertarian\n");
		printf("5 - Republican");
		printf("\nPlease select a party affiliation: ");
		invalid = 0;
		while (invalid == 0){
			scanf("%d%*c", &partyNum);
			if (partyNum < 1 || partyNum > 5) {
				printf("Invalid selection. Please try again: ");
				invalid = 0;
			}
			else {
				invalid = 1;
			}
		}
		// Office Held
		printf("Please enter the political office held: ");
		invalid = 0;
		while (invalid == 0){
			fgets(office, 34, stdin);
			if (office[33] == '\0') {
				printf("You entered too many characters. Please try again: ");
				invalid = 0;
			}
			else {
				invalid = 1;
			}
		}
		// State
		printf("AL\tAK\tAZ\tAR\tCA\nCO\tCT\tDE\tFL\tGA\nHI\tID\tIL\tIN\tIA");
		printf("\nKS\tKY\tLA\tME\tMD\nMA\tMI\tMN\tMS\tMO\nMT\tNE\tNV\tNH\tNJ");
		printf("\nNM\tNY\tNC\tND\tOH\nOK\tOR\tPA\tRI\tSC\nSD\tTN\tTX\tUT\tVT");
		printf("\nVA\tWA\tWV\tWI\tWY");
		printf("\nPlease select a home state: ");
		invalid = 0;
		// loops until 2 characters are entered
		while (invalid == 0) {
				fgets(state, 3, stdin);
                                if (state[2] == '\0') {
					invalid = 1;
				}
                                else {
				printf("Invalid selection. Please try again: ");
				}
                        }
		// show menu
		menu();
		choice = check();
		loop = 0;
		break;
	}
	case 3: { //Age and Sex
		//Age
		invalid = 0;
                printf("Enter age: ");
                while (invalid == 0) {
                        scanf("%s", age);
                        for(i = 0; i<=2; i++) {
                                if (age[i] == '\0') {
                                        invalid = 1;
                                        break;
                                }
                        }
                        // checks if it is a two digit input
                        if (age[2] == '\0'){
                                ageD[0] = age[0] - '0';
                                ageD[1] = age[1] - '0';
			}
			else{ 
                                printf("You did not enter a two digit number between");
                                printf(" 21 and 99. Please try again: ");
                                invalid = 0;
                        
                        }
			if ((ageD[0] == 2 && ageD[1] == 0)|| ageD[0] < 2) {
				printf("You did not enter a two digit number between");
				printf(" 21 and 99. Please try again: ");
				invalid = 0;
			}
		}
		//Sex
		invalid = 0;
		printf("Enter sex with either M or F: ");
		// loops until F or M is entered
		while (invalid == 0) {
			scanf(" %c%*c", &sex);
			if (sex == 'F' || sex == 'M') {
				invalid = 1;
			}
			else {
				printf("Not a valid input. Please try again: ");
				invalid = 0;
			}
		}
		// Display Menu
		menu();
                choice = check();
                loop = 0;
		break;
	}
	case 4: {
		// Phone Number
		printf("Please enter a phone number in the form XXXXXXXXXX: ");
		scanf("%s",phone);		
		
		// Twitter Account
		printf("Please enter a twitter account: ");
		invalid = 0;
		while (invalid == 0) {
				scanf("%s", twitter);
                                for (i=0; i<=15; i++) {
                                        if (twitter[i] == '\0') {
                                                invalid = 1;
                                                break;
                                        }
                                        if (twitter[15] != '\0') {
                                                printf("Your input has too many characters. ");
                                                printf("Please try again: ");
                                                invalid = 0;
                                                break;
                                        }
                                }
                        }
		// Display Menu
		menu();
                choice = check();
                loop = 0;
		break;
	}
	case 5: { // Contributions and Lies
		// Contributions
		printf("Please enter the amount of contributions received (MAX: 10^50): ");
		invalid = 0;
		float max1 = pow(10,50);
		while (invalid == 0) {
			scanf("%f", &contributions);
			if (contributions >= 0 && contributions <= max1){
				invalid = 1;
			}
			else {
				printf("Invalid input. Please try again: ");
				invalid = 0;
			}
		}

		// Number of Lies Told
		printf("Please enter the number of lies told (MAX: 10^100): ");
		invalid = 0; 
		float max2 = pow(10,100);
		while (invalid == 0) {
			scanf("%f", &lies);
			if (lies >= 0 && lies <= max2) {
				invalid = 1;
			}
			else {
				printf("Invalid input. Please try again: ");
				invalid = 0;
			}
		}
		// Ratio
		ratio = contributions/lies;
		// Display Menu
		menu();
		choice = check();
		loop = 0;
		break;
	}

	case 6: { // Display the Data
		// Name
		printf("\nName: %s %s %c %s", suffix, firstName,middleName,lastName);
		// Years Served
		printf("\nYears Served: %c%c\n", years[0], years[1]);
		// Party Affiliation
		switch(partyNum) {
		case 0: {
			printf("Party Affiliation: Unknown\n");
			break;
		}
		case 1: {
			printf("Party Affiliation: Constitution\n");
			break;
		}
		case 2: {
			printf("Party Affiliation: Democrat\n");
			break;
		}
		case 3: {
			printf("Party Affiliation: Green\n");
			break;
		}
		case 4: {
			printf("Party Affiliation: Libertarian\n");
			break;
		}
		case 5: {
			printf("Party Affiliation: Republican\n");
			break;
		}
		}
		// Office Held
		printf("Office Held: %s", office);
		// Home State
		printf("\nHome State: %c%c", state[0],state[1]);
		// Age
		printf("\nAge: %c%c\n",age[0], age[1]);
		// Sex
		if (sex == 'M'){
			printf("Sex: Male\n");
		}
		else if (sex == 'F'){
			printf("Sex: Female\n");
		}
		else {
			printf("Sex: ?\n");
		}
		// Phone Number
		printf("Phone Number: (%c%c%c)",phone[0], phone[1], phone[2]);
		printf(" %c%c%c", phone[3], phone[4], phone[5]);
		printf("-%c%c%c%c\n", phone[6], phone[7], phone[8], phone[9]);
		// Twitter
		printf("Twitter: @%s\n", twitter);
		// Contributions
		printf("US Dollars Received: $%.2f\n", contributions);
		// Lies Told
		printf("Number of Lies Told: %.2f\n", lies);
		// Ratio of contributions to lies told
		printf("Ratio of contributions to lies told: %.2f:1\n", ratio);
		// Menu
		menu();
		choice = check();
		loop = 0;
		break;
	}
	case 7: { // Clear Data
		memset(firstName,0,34);
		middleName = '?';	
		memset(lastName,0,35);
		memset(suffix, 0, 4);
		memset(office,0, 34);
		memset(years, 0, 3);
		memset(state, 0 , 3);
		memset(age, 0 , 3);
		sex = '?';
		memset(twitter, 0 , 16);
		memset(phone, 0, 11);
		contributions = 0;
		lies = 0;
		ratio = 0;               	
		partyNum = 0;
		// Display Menu
                menu();
                choice = check();
                loop = 0;
                break;
	} 
	case 8: { // Exit program
		exit(1);
	}
	}
	}
return 0;
}

