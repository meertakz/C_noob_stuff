#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    int i = 0;
    char city1[10], city2[10];
    char column1_cities[10][10], column2_cities[10][10];
    float price, total_price = 0;
    float prices[10];
    int found_index, last_index;

    /// file stuff
    FILE *fp = fopen("tolls.txt", "r");


    /// reading stuff into arrays
    while (fscanf(fp, "%s\t%s\t%f", &city1, &city2, &price) != EOF) {
        strcpy(column1_cities[i], city1);
        strcpy(column2_cities[i], city2);
        prices[i] = price;
        i++;
    }

    /// closing the file
    fclose(fp);

    char entry_city[10];
    char exit_city[10];


  
    /// input formatting
    printf("Please enter starting destination       #");
    scanf("%s", entry_city);
    for (int t=0; t<strlen(entry_city); t++)
    {
        if (t==0)
        {
            entry_city[t] = toupper(entry_city[t]);
        }
        else entry_city[t] = tolower(entry_city[t]);
    }

    /// input formatting
    printf("Please enter desired destination        #");
    scanf("%s", exit_city);
    for (int t=0; t<strlen(exit_city); t++)
    {
        if (t==0)
        {
            exit_city[t] = toupper(exit_city[t]);
        }
        else exit_city[t] = tolower(exit_city[t]);
    }



    /// city search loop
    for (int y = 0; y <= 7; y++) {
        /// finding the first city in the first column
        if (strcmp(entry_city, column1_cities[y]) == 0) {
            found_index = y;
        }
    }

    /// first arrived city check
    if (strcmp(column2_cities[found_index], exit_city) == 0) {
        total_price = (float) prices[found_index];
        printf("\nBravo, you started from %s and reached\n", entry_city);
        printf("%s in 1 ride with a price of %.2f\n", exit_city, total_price);
        return 0;
    }
    else
    {
        total_price += prices[found_index];
        for (int y = 0; y <= 7; y++)
        {
            /// finding the first arrived city in the first column
            if (strcmp(column2_cities[found_index], column1_cities[y]) == 0)
            {
                found_index = y;
            }
        }
    }
    /// second arrived city check
    if (strcmp(column2_cities[found_index], exit_city) == 0)
    {
        total_price += (float) prices[found_index];
        printf("\nBravo, you started from %s and reached\n", entry_city);
        printf("%s in 2 rides with a price of %.2f\n", exit_city, total_price);
        return 0;

    }
    else
    {
        total_price += (float) prices[found_index];
        for (int y = 0; y <= 7; y++)
        {
            /// finding the second arrived city in the first column
            if (strcmp(column2_cities[found_index], column1_cities[y]) == 0)
            {
                last_index = y;
            }
        }
    }

    /// final check
    if (strcmp(column2_cities[last_index],exit_city)==0)
    {
        total_price += (float) prices[last_index];
        printf("\nBravo, you started from %s and reached\n", entry_city);
        printf("%s in 3 rides with a price of %.2f\n", exit_city, total_price);
        return 0;
    }
    else
    {
        printf("scusi non puoi vedere la città %s perche sei in %s",entry_city, exit_city);
        return 1;
    }
}
