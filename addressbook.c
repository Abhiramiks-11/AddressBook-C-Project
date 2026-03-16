#include "addressbook.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>


void add_contact(struct AddressBook *addressBook)
{
	printf("\n========== ADD CONTACT ==========\n");
    //logic to create new contact
    char name[30];
    //print and read a name
    printf("\nEnter Name: ");
    scanf(" %29[^\n]", name);
    strcpy(addressBook-> contacts[addressBook-> contact_count]. name, name);

    char phone[20];
    int ret;
    do
    {
        //print and read a mobile number (if validated)
        printf("Enter Phone Number: ");
        scanf("%s", phone);
        //validate a number
        ret = mobile_validation(addressBook, phone);
        //print error message
        if(ret == 0)
            printf("Error: Invalid phone number. Please enter a valid 10-digit mobile number.\n");
    
    } while(ret == 0);
    strcpy(addressBook-> contacts[addressBook-> contact_count]. phone, phone);

    char email[30];
    do
    {
        //print and read email id (if validated)
        printf("Enter Email Address: ");
        scanf("%s", email);
        //validate a mail
        ret = email_validation(addressBook, email);
        //print error message
        if(ret == 0)
            printf("Error: Invalid email address. Please enter a valid Gmail ID.\n");
    } while(ret == 0);
    strcpy(addressBook-> contacts[addressBook-> contact_count]. email, email);
    //increment the contact count
    addressBook-> contact_count++;
    printf("Contact added successfully.\n");
}

void search_contact(struct AddressBook *addressBook)
{
    int i, ret, choice;
    char search_name[30];
    char search_phone[20];
    char search_email[30];
	printf("\n========== SEARCH CONTACT ==========\n");

    //display the menu
    printf("\nSearch Contact By:\n");               
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Email Address\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    addressBook-> ir_size = 0;

    switch(choice)
    {
        //1-search by name
        case 1: 
            printf("Enter Name to search: ");
            scanf(" %29[^\n]", search_name);
            for(i = 0; i < addressBook-> contact_count; i++)                                        //to search
            {
                if(strcmp(addressBook-> contacts[i].name, search_name) == 0)
                {
                    addressBook-> index_record[addressBook-> ir_size] = i;                          //to store index
                    addressBook-> ir_size++;
                }
            }
            if (addressBook-> ir_size == 0)
            {
                printf("No contact found with the given name.\n");
            }
            else
            {
                printf("Contact(s) found:\n");
                for(i = 0; i <addressBook-> ir_size; i++)
                {
                    printf("Name  : %s\n", addressBook-> contacts[i].name);
                    printf("Phone : %s\n", addressBook-> contacts[i].phone);
                    printf("Email : %s\n", addressBook-> contacts[i].email);                         //no break to print
                }
            }
        break;
        //2-search by phone
        case 2:
        do
        {
            printf("Enter Phone Number: ");
            scanf("%s", search_phone);
            ret = mobile_validation(addressBook, search_phone);
            if(ret == 0)
                printf("Invalid phone number. Please re-enter.\n");
        }
            while(ret == 0);
            for(i = 0; i < addressBook-> contact_count; i++)
            {
                if(strcmp(addressBook-> contacts[i].phone, search_phone) == 0)
                {
                    printf("Contact found:\n");
                    printf("Name  : %s\n", addressBook-> contacts[i].name);
                    printf("Phone : %s\n", addressBook-> contacts[i].phone);
                    printf("Email : %s\n", addressBook-> contacts[i].email);
                    return;
                }
            }
            printf("No contact found with the given phone number.\n");
            break;

        //3-search by email
        case 3:
        do
        {
            printf("Enter Email Address: ");
            scanf("%s", search_email);
            ret = mobile_validation(addressBook, search_email);
            if(ret == 0)
                printf("Invalid email address. Please re-enter.\n");
        }
            while(ret == 0);
            for(i = 0; i < addressBook-> contact_count; i++)
            {
                if(strcmp(addressBook-> contacts[i].email, search_email) == 0)
                {
                    printf("Contact found:\n");
                    printf("Name  : %s\n", addressBook-> contacts[i].name);
                    printf("Phone : %s\n", addressBook-> contacts[i].phone);
                    printf("Email : %s\n", addressBook-> contacts[i].email);
                    return;
                }
            }
            printf("No contact found with the given email address.\n");
            break;
        default:
        printf("Invalid choice. Please select a valid option.\n");
    }
}

void edit_contact(struct AddressBook *addressBook)
{
    int s_no, ret, choice;
    char new_name[30];
    char new_phone[20];
    char new_email[30];
	printf("\n========== EDIT CONTACT ==========\n");

    //1-call the search contact function
    search_contact(addressBook);
    if(addressBook-> ir_size == 0)
    {
        printf("No contacts available to edit.\n");
        return ;
    }

    //2-print and read a serial number
    printf("Enter the serial number of the contact to edit: ");
    scanf("%d", &s_no);

    //3-Display the menu
    printf("\nSelect the field to edit:\n");
    printf("1. Name\n");
    printf("2. Phone Number\n");
    printf("3. Email Address\n");
    printf("4. Exit\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
        //1-Edit by name
        case 1:
        printf("Enter the new name: ");
        scanf(" %29[^\n]", new_name);
        strcpy(addressBook-> contacts[addressBook->index_record[s_no-1]].name, new_name);
        printf("Name updated successfully.\n");
        break;
        
        //2-Edit by phone number
        case 2:
        do
        {
            printf("Enter the new phone number: ");
            scanf("%s", new_phone);
            ret = mobile_validation(addressBook, new_phone);
            if(ret == 0)
            {
                printf("Invalid phone number. Please try again.\n");
            }
        }
        while(ret == 0);
        strcpy(addressBook-> contacts[addressBook->index_record[s_no-1]].phone, new_phone);
        printf("Phone number updated successfully.\n");
        break;

        //3-Edit by email
        case 3:
        do
        {
            printf("Enter the new email address: ");
            scanf("%s", new_email);
            ret = email_validation(addressBook, new_email);
            if(ret == 0)
            {
                printf("Invalid email address. Please try again.\n");
            }
        }
        while(ret == 0);
        strcpy(addressBook-> contacts[addressBook->index_record[s_no-1]].email, new_email);
        printf("Email address updated successfully.\n");
        break;

        case 4:
        return;

        default:
        printf("Invalid choice. Please select a valid option.\n");
    }
}

void delete_contact(struct AddressBook *addressBook)
{
    int s_no, i, pos;
	printf("\n========== DELETE CONTACT ==========\n");

    //1-Call The Search Function
    search_contact(addressBook);
    //2-Check To Contact Found
    if (addressBook->ir_size == 0)
    {
        printf("No contacts available to delete.\n");
        return;
    }
    //3-choose the serial number
    printf("Enter the serial number of the contact to delete: ");
    scanf("%d", &s_no);
    //4-move contacts after deleted
    pos = addressBook-> index_record[s_no - 1];
    for (i = pos; i < addressBook->contact_count - 1; i++)
    {
        addressBook->contacts[i] = addressBook->contacts[i + 1];
    }
    addressBook->contact_count--;
    printf("Contact deleted successfully.\n");
}

void list_contacts(struct AddressBook *addressBook)
{
    int i;
    printf("\n========== LIST ALL CONTACT ==========\n");

    if(addressBook-> contact_count == 0)
    {
        printf("No contacts available.\n");
        return;
    }
    printf("\nContact List:\n");
    for(i = 0; i < addressBook-> contact_count; i++)
    {
        printf("Name  : %s\n", addressBook-> contacts[i].name);
        printf("Phone : %s\n", addressBook-> contacts[i].phone);
        printf("Email : %s\n", addressBook-> contacts[i].email);
    }
}

//mobile validations
int mobile_validation(struct AddressBook *addressBook, char *phone)
{
    int i;
    //1-find and check length
    if(strlen(phone) != 10)
    {
        return 0;
    }
    //2-check whether the number starts with 6 to 9
    if(!(phone[0] >= '6' && phone[0] <= '9'))
        {
            return 0;
        }
    //3-check string containing non numerical char or not
    for(i = 0; i < strlen(phone); i++)
    {
        if(!(phone[i] >= '0' && phone[i] <= '9'))
        {
            return 0;
        }
    }
    //4-check number is unique or not
    for(i = 0; i < addressBook-> contact_count; i++)
    {
        if(strcmp(addressBook-> contacts[i].phone, phone)==0)
        return 0;
    }
    return 1;                                                                            // if number is valid
}

//email validations
int email_validation(struct AddressBook *addressBook, char *email)
{
    int i, at_count = 0;
    //1-check @gmai.com should be present at last
    char *ret = strstr(email, "@gmail.com");
    if(ret == NULL)
    {
        return 0;
    }
    //2-check only one @ is allowed
    for(i = 0; email[i] != '\0'; i++)                                                    //run loop for once and check every char is @ or not
    {
        if(email[i] == '@')
        {
            at_count++;
        }
    }
    if(at_count > 1)                                                                     //to check if more than 1@ is present or not
    { 
        return 0;
    }   
    //3-check spaces should not be there
    if(email[i] == ' ')
    {
        return 0;
    }
    //4-check before the char @, 1 alnum should be present
    if(email[0] == '@')
    {
        return 0;
    }
    //5-check gmail should be unique
    for(i = 0; i < addressBook-> contact_count; i++)
    {
        if(strcmp(addressBook-> contacts[i].email, email) == 0)
        return 0;
    }
    return 1;
}

//save contacts to database
void push_data_to_file(struct AddressBook *addressBook)
{
    FILE *fp;
    int i;
    //open file
    fp = fopen("database.csv", "w");
    //file doesnt exist
    if(fp == NULL)
    {
        printf("Error: Unable to open database file.\n");
        return;
    }
    //write contacts
    for(i=0; i < addressBook-> contact_count; i++)
    {
        fprintf(fp, "%s,%s,%s\n", addressBook-> contacts[i].name, addressBook-> contacts[i].phone, addressBook-> contacts[i].email);
    }
    //close and print file
    fclose(fp);
    printf("Contacts saved successfully.\n");
}
//load contacts from database
void pull_file_data(struct AddressBook *addressBook)
{
    FILE *fp;
    int i = 0;
    //open file
    fp = fopen("database.csv", "r");
    //file doesnt exist
    if(fp == NULL)
    {
        printf("Database file not found.\n");
        return;
    }
    //read contacts
    while(fscanf(fp, "%[^,],%[^,],%[^\n]\n", addressBook-> contacts[i].name, addressBook-> contacts[i].phone, addressBook-> contacts[i].email) != EOF)
    {
        i++;
    }
    addressBook-> contact_count = i;
    //close and print file
    fclose(fp);
    printf("Contacts loaded successfully.\n");
}
