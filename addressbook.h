#ifndef CONTACT_H
#define CONTACT_H
#include<stdio.h>

struct Contact{
    char name[50];
    char phone[15];
    char email[50];
};

struct AddressBook {
    struct Contact contacts[100];
    int contact_count;
    int index_record[100];
    int ir_size;
};

void add_contact(struct AddressBook *addressBook);
void search_contact(struct AddressBook *addressBook);
void edit_contact(struct AddressBook *addressBook);
void delete_contact(struct AddressBook *addressBook);
void list_contacts(struct AddressBook *addressBook);

int mobile_validation(struct AddressBook *addressBook, char *phone);
int email_validation(struct AddressBook *addressBook, char *email);

void push_data_to_file(struct AddressBook *addressBook);
void pull_file_data(struct AddressBook *addressBook);

#endif
