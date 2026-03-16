#include "addressbook.h"

int main() 
{
    int choice;

    struct AddressBook addressBook;
    addressBook.contact_count = 0;
    addressBook.ir_size = 0;

	pull_file_data(&addressBook);                     
    do 
    {
	printf("\n========== ADDRESS BOOK MENU ==========\n");
	printf("1. Add/Create contact\n");
	printf("2. Search contact\n");
	printf("3. Edit contact\n");
	printf("4. Delete contact\n");
	printf("5. List all contacts\n");
	printf("6. Save and Exit\n");
	printf("Enter your choice: ");

	scanf("%d", &choice);

	switch (choice) 
	{
	    case 1:
		add_contact(&addressBook);
		break;
	    case 2:
		search_contact(&addressBook);
		break;
	    case 3:
		edit_contact(&addressBook);
		break;
	    case 4:
		delete_contact(&addressBook);
		break;
	    case 5:
		list_contacts(&addressBook);
		break;
	    case 6:
		printf("Saving and Exiting...\n");
		push_data_to_file(&addressBook);
		break;
	    default:
		printf("Invalid choice. Please try again.\n");
	}
    } while (choice != 6);

    return 0;
}
