#include <stdio.h>
#include <string.h>

#define MAX_CONTACTS 100
#define MAX_NAME_LENGTH 50
#define MAX_PHONE_LENGTH 15

struct Contact {
    char first_name[MAX_NAME_LENGTH];
    char last_name[MAX_NAME_LENGTH];
    char phone_number[MAX_PHONE_LENGTH];
};

struct Contact contacts[MAX_CONTACTS];
int num_contacts = 0;

void addContact() {
    if (num_contacts >= MAX_CONTACTS) {
        printf("Książka adresowa jest pełna.\n");
        return;
    }

    struct Contact new_contact;

    printf("Podaj imię: ");
    scanf("%s", new_contact.first_name);

    printf("Podaj nazwisko: ");
    scanf("%s", new_contact.last_name);

    printf("Podaj numer telefonu: ");
    scanf("%s", new_contact.phone_number);

    contacts[num_contacts++] = new_contact;
    printf("Kontakt został dodany.\n");
}

void findContact(const char *last_name) {
    int found = 0;
    for (int i = 0; i < num_contacts; ++i) {
        if (strcmp(contacts[i].last_name, last_name) == 0) {
            printf("Znaleziono kontakt:\n");
            printf("Imię: %s\n", contacts[i].first_name);
            printf("Nazwisko: %s\n", contacts[i].last_name);
            printf("Numer telefonu: %s\n", contacts[i].phone_number);
            found = 1;
        }
    }
    if (!found) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", last_name);
    }
}

void removeContact(const char *last_name) {
    int found = 0;
    for (int i = 0; i < num_contacts; ++i) {
        if (strcmp(contacts[i].last_name, last_name) == 0) {
            found = 1;
            for (int j = i; j < num_contacts - 1; ++j) {
                contacts[j] = contacts[j + 1];
            }
            num_contacts--;
            printf("Kontakt o nazwisku %s został usunięty.\n", last_name);
            break;
        }
    }
    if (!found) {
        printf("Nie znaleziono kontaktu o nazwisku %s.\n", last_name);
    }
}

void printContacts() {
    if (num_contacts == 0) {
        printf("Książka adresowa jest pusta.\n");
        return;
    }
    printf("Książka adresowa:\n");
    for (int i = 0; i < num_contacts; ++i) {
        printf("%d. %s %s - %s\n", i + 1, contacts[i].first_name, contacts[i].last_name, contacts[i].phone_number);
    }
}

int main() {
    int choice;
    char last_name[MAX_NAME_LENGTH];

    while (1) {
        printf("\nWybierz opcję:\n");
        printf("1. Dodaj kontakt\n");
        printf("2. Znajdź kontakt\n");
        printf("3. Usuń kontakt\n");
        printf("4. Wyświetl wszystkie kontakty\n");
        printf("5. Wyjdź\n");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                printf("Podaj nazwisko do wyszukania: ");
                scanf("%s", last_name);
                findContact(last_name);
                break;
            case 3:
                printf("Podaj nazwisko do usunięcia: ");
                scanf("%s", last_name);
                removeContact(last_name);
                break;
            case 4:
                printContacts();
                break;
            case 5:
                printf("Zamykanie programu.\n");
                return 0;
            default:
                printf("Nieprawidłowy wybór.\n");
        }
    }

    return 0;
}