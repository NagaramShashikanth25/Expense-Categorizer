#include <stdio.h>
#include <string.h>
#include <regex.h>

int matchRegex(const char *pattern, const char *text) {
    regex_t regex;
    int result;

    regcomp(&regex, pattern, REG_ICASE);
    result = regexec(&regex, text, 0, NULL, 0);
    regfree(&regex);

    return (result == 0); 
}

int main() {
    int n, i;
    char name[50], category[20];
    float amount;
    float totalFood = 0, totalTravel = 0, totalShopping = 0, totalBills = 0, totalOthers = 0, total = 0;

    printf("===== Expense Categorizer =====\n");
    printf("Enter number of expenses: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++) {
        printf("\nEnter expense name: ");
        scanf(" %[^\n]", name);

        printf("Enter amount: ");
        scanf("%f", &amount);

        printf("Enter category (Food/Travel/Shopping/Bills/Others): ");
        scanf("%s", category);

        if (matchRegex("food", category))
            totalFood += amount;
        else if (matchRegex("travel", category))
            totalTravel += amount;
        else if (matchRegex("shopping", category))
            totalShopping += amount;
        else if (matchRegex("bills?", category)) 
            totalBills += amount;
        else
            totalOthers += amount;

        total += amount;
    }

    printf("\n===== Expense Summary =====\n");
    printf("Food: ₹%.2f\n", totalFood);
    printf("Travel: ₹%.2f\n", totalTravel);
    printf("Shopping: ₹%.2f\n", totalShopping);
    printf("Bills: ₹%.2f\n", totalBills);
    printf("Others: ₹%.2f\n", totalOthers);
    printf("---------------------------\n");
    printf("Total Spent: ₹%.2f\n", total);

    return 0;
}