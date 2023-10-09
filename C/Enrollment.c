#include <stdio.h>
#include <stdlib.h>

int main(){
    //this two line of code is the declaration of the two variable used
    int year;
    char clearance;

    //asked the student of what is her/his year
     printf("Input Year Level: ");
     scanf("%d", &year);


    //check the year of the student that is inputed above
    if (year == 1) {
       printf("Available subjects for this year level (1) are the following:\n\n\tMATHEMATICAL APPLICATIONS FOR ITE\n\tSOCIAL ISSUES AND PROFESSIONAL ISSUES\n\tINTRODUCTION TO COMPUTING\n\tCWTS/LTS/ROTC I\n\tPURPOSIVE COMMUNICATION\n\tWEB SYSTEM AND TECHNOLOGIES\n");
    } else {
        //this will display if the student did not input 1
        printf("\"CLEARANCE NEEDED\"\n");
        printf("Is her/his clearance already cleared? (y/n): ");
        scanf(" %c", &clearance);
        if (clearance == 'y' || clearance == 'Y') {
            //this will display if the student is cleared
            printf("Available subjects for this year level (3) are the following:\n\tCWTS/LTS/ROTC I\n\tPURPOSIVE COMMUNICATION\n\tETHICS\n\tSOFTWARE ENGINEERING\n\tWEB SYSTEM AND TECHNOLOGIES\n\tLIFE AND WORKS OF RIZAL\n\tCARRER READINESS\n\tADVANCE DATABASE");
            if (year == 4) {
                printf("- ADVANCE DATABASE\n");
            }
        } else {
            //this will display if the student did not cleared the clearnce
            printf("Please clear your clearance first!\n");
        }
    }

    return 0;
}