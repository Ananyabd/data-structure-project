#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// Structure to represent a bus
typedef struct Bus
{
    int id;
    char currentRoute[100];
    struct Bus* next;
} Bus;

// Queue data structure for managing departure order
typedef struct Queue
{
    Bus* front;
    Bus* rear;
} Queue;

// Structure to represent a released bus node
typedef struct StackNode
{
    Bus* bus;
    struct StackNode* next;
} StackNode;

StackNode *top = NULL;

// Function to create a new bus node
Bus* createBus(int id,char route[])
{
    Bus* newBus = (Bus*)malloc(sizeof(Bus));
    if (newBus != NULL)
    {
        newBus->id = id;
        strcpy(newBus->currentRoute, route);
        newBus->next = NULL;
    }
    return newBus;
}


// Function to Add a bus in the departure route
void enqueue(Queue* q, Bus* bus)
{
    if (q->rear == NULL)
    {
        q->front = q->rear = bus;
    }
    else
    {
        q->rear->next = bus; //linking next new bus
        q->rear = bus;
    }
}

// Function to Release a bus from the departure route
Bus* dequeue(Queue* q)
{
    if (q->front == NULL)
    {
        return NULL;
    }
    Bus* bus;
    bus = q->front;
    q->front = q->front->next;

    if (q->front == NULL)
    {
        q->rear = NULL;
    }

    return bus;
}

// Function to display buses in a queue
void displayQueue(Queue* q)
{
    Bus* current = q->front;

    // Display a message if the queue is empty
    if (current == NULL)
    {
        printf("+-------------------------------------+\n");
        printf("|        No Bus in this Route         |\n");
        printf("+-------------------------------------+\n");
        printf("\n");
        return;
    }

    // Display a header for the bus information
    printf("+-------------------------------------+\n");
    printf("|   Bus ID    |       Route           |\n");
    printf("+-------------------------------------+\n");

    // Display each bus in the route
    while (current != NULL)
    {
        printf("|    %-9d| %-20s  |\n", current->id, current->currentRoute);
        current = current->next;
    }

    // Display a footer for the bus information
    printf("+-------------------------------------+\n");
    printf("\n");
}

// Function to save departing orders to a file
void saveDepartingOrdersToFile(Queue* DhanmondiQueue, Queue* MirpurECBQueue, Queue* UttaraQueue, Queue* TongiCollegegateQueue, Queue* ZiraboQueue, Queue* BaipailQueue, Queue* DhamraiBusStandQueue, Queue* SavarQueue, Queue* NarayanganjQueue, Queue* MugdhaModelThanaQueue, Queue* SonyCinemaHallQueue, Queue* UttaraMoylarMorQueue)
{
    FILE* file = fopen("departing_orders.txt", "w");
    if (file == NULL)
    {
        printf("Error opening file for writing.\n");
        return;
    }

    Bus* current;

    fprintf(file, "Departing orders for Route Dhanmondi:\n");
    current = DhanmondiQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Mirpur:\n");
    current = MirpurECBQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Uttara:\n");
    current = UttaraQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Tongi College gate:\n");
    current = TongiCollegegateQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Zirabo:\n");
    current = ZiraboQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Baipail:\n");
    current = BaipailQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Dhamrai Bus Stand:\n");
    current = DhamraiBusStandQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Savar:\n");
    current = SavarQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Narayanganj:\n");
    current = NarayanganjQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Sony Cinema Hall:\n");
    current = SonyCinemaHallQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Mugdha Model Thana:\n");
    current = MugdhaModelThanaQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fprintf(file, "Departing orders for Route Uttara Moylar Mor:\n");
    current = UttaraMoylarMorQueue->front;
    while (current != NULL)
    {
        fprintf(file, "Bus ID: %d\n", current->id);
        current = current->next;
    }

    fclose(file);
}

// Function to read departing orders from a file
void readDepartingOrdersFromFile(Queue* DhanmondiQueue, Queue* MirpurECBQueue, Queue* UttaraQueue, Queue* TongiCollegegateQueue, Queue* ZiraboQueue, Queue* BaipailQueue, Queue* DhamraiBusStandQueue, Queue* SavarQueue, Queue* NarayanganjQueue, Queue* MugdhaModelThanaQueue, Queue* SonyCinemaHallQueue, Queue* UttaraMoylarMorQueue)

{
    FILE* file = fopen("departing_orders.txt", "r");
    if (file == NULL)
    {
        printf("Error opening file for reading.\n");
        return;
    }

    char Line[256];
    int currentRoute = '\0';  // Variable to track the current route being read

    while (fgets(Line, sizeof(Line), file) != NULL)
    {
        // Convert the Line to lowercase for case-insensitive comparison
        for (int i = 0; Line[i]; i++)
        {
            Line[i] = tolower(Line[i]);
        }

        if (strstr(Line, "departing orders for route dhanmondi:") != NULL)
        {
            currentRoute = 1;
        }
        else if (strstr(Line, "departing orders for route mirpur:") != NULL)
        {
            currentRoute = 2;
        }
        else if (strstr(Line, "departing orders for route uttara:") != NULL)
        {
            currentRoute = 3;
        }
        else if (strstr(Line, "departing orders for route tongi college gate:") != NULL)
        {
            currentRoute = 4;
        }
        else if (strstr(Line, "departing orders for route zirabo:") != NULL)
        {
            currentRoute = 5;
        }
        else if (strstr(Line, "departing orders for route baipail:") != NULL)
        {
            currentRoute = 6;
        }
        else if (strstr(Line, "departing orders for route dhamrai bus stand:") != NULL)
        {
            currentRoute = 7;
        }
        else if (strstr(Line, "departing orders for route savar:") != NULL)
        {
            currentRoute = 8;
        }
        else if (strstr(Line, "departing orders for route narayanganj:") != NULL)
        {
            currentRoute = 9;
        }
        else if (strstr(Line, "departing orders for route sony cinema hall:") != NULL)
        {
            currentRoute = 10;
        }
        else if (strstr(Line, "departing orders for route mugdha model thana:") != NULL)
        {
            currentRoute = 11;
        }
        else if (strstr(Line, "departing orders for route uttara moylar mor:") != NULL)
        {
            currentRoute = 12;
        }
        else if (sscanf(Line, "bus id: %*d") == 0)
        {
            // This line starts with "bus id:" indicating a departing order
            int busID;
            sscanf(Line, "bus id: %d", &busID);

            // Enqueue the bus based on the current route
            switch (currentRoute)
            {
            case 1:
            {
                enqueue(DhanmondiQueue, createBus(busID,"Dhanmondi"));
                break;
            }
            case 2:
            {
                enqueue(MirpurECBQueue, createBus(busID,"Mirpur"));
                break;
            }
            case 3:
            {
                enqueue(UttaraQueue, createBus(busID,"Uttara"));
                break;
            }
            case 4:
            {
                enqueue(TongiCollegegateQueue, createBus(busID,"Tongi College gate"));
                break;
            }
            case 5:
            {
                enqueue(ZiraboQueue, createBus(busID,"Zirabo"));
                break;
            }
            case 6:
            {
                enqueue(BaipailQueue, createBus(busID,"Baipail"));
                break;
            }
            case 7:
            {
                enqueue(DhamraiBusStandQueue, createBus(busID,"Dhamrai Bus Stand"));
                break;
            }
            case 8:
            {
                enqueue(SavarQueue, createBus(busID,"Savar"));
                break;
            }
            case 9:
            {
                enqueue(NarayanganjQueue, createBus(busID,"Narayanganj"));
                break;
            }
            case 10:
            {
                enqueue(SonyCinemaHallQueue, createBus(busID,"Sony Cinema Hall"));
                break;
            }
            case 11:
            {
                enqueue(MugdhaModelThanaQueue, createBus(busID,"Mugdha Model Thana"));
                break;
            }
            case 12:
            {
                enqueue(UttaraMoylarMorQueue, createBus(busID,"Uttara Moylar Mor"));
                break;
            }
            default:
            {
                printf("Error: Unknown route for departing order.\n");
                break;
            }
            }
        }
    }

    fclose(file);
}
// Function to push a bus onto the stack
void push(StackNode** top, Bus* bus)
{
    StackNode* newNode = (StackNode*)malloc(sizeof(StackNode));
    if (newNode != NULL)
    {
        newNode->bus = bus;
        newNode->next = *top;
        *top = newNode;
    }
}

// Function to pop a bus from the stack
void pop(StackNode** top)
{
    if ((*top) == NULL)
    {
        return NULL; // Stack is empty
    }

    StackNode* temp = *top;
    while((*top)!=NULL)
    {
    *top = temp->next;
    Bus* bus = temp->bus;
    free(bus);
    free(temp);
    }

    printf("Successfully release buses\n");
}

// Function to display buses in a stack
void displayStack(StackNode* top)
{
    StackNode* current = top;

    // Display a message if the stack is empty
    if (current == NULL)
    {
        printf("No Buses in the stack.\n");
        printf("\n");
        return;
    }

    // Display a header for the stack content
    printf("+-----------------------------+\n");
    printf("|    Bus ID   |    Route      |\n");
    printf("+-----------------------------+\n");

    // Display each node in the stack
    while (current != NULL)
    {
        printf("|   %-9d | %-13s |\n", current->bus->id, current->bus->currentRoute);
        current = current->next;
    }

    // Display a footer for the stack content
    printf("+-----------------------------+\n");
    printf("\n");
}

void adminDashboard()
{
    // Code for the admin dashboard
    char password[50];
    int choice;

    printf("Enter password: ");
    scanf("%s", password);
    // Check the password for access to the admin dashboard
    if (strcmp(password, "AnisBhai") == 0)
    {
        // Admin functionalities go here

        printf("+---------------------------------+\n");
        printf("| Welcome to the admin dashboard! |\n");
        printf("+---------------------------------+\n");

        Queue DhanmondiQueue = {NULL, NULL};
        Queue MirpurECBQueue = {NULL, NULL};
        Queue UttaraQueue = {NULL, NULL};
        Queue TongiCollegegateQueue = {NULL, NULL};
        Queue ZiraboQueue = {NULL, NULL};
        Queue BaipailQueue = {NULL, NULL};
        Queue DhamraiBusStandQueue = {NULL, NULL};
        Queue SavarQueue = {NULL, NULL};
        Queue NarayanganjQueue = {NULL, NULL};
        Queue MugdhaModelThanaQueue = {NULL, NULL};
        Queue SonyCinemaHallQueue = {NULL, NULL};
        Queue UttaraMoylarMorQueue = {NULL, NULL};

        readDepartingOrdersFromFile(&DhanmondiQueue, &MirpurECBQueue, &UttaraQueue, &TongiCollegegateQueue, &ZiraboQueue, &BaipailQueue, &DhamraiBusStandQueue, &SavarQueue, &NarayanganjQueue, &MugdhaModelThanaQueue, &SonyCinemaHallQueue, &UttaraMoylarMorQueue);

        printf("1.Add Buses\n");
        printf("2.Release Buses\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        printf("\n");
        if(choice == 1)
        {

            int numBuses;
            printf("How many buses you want to add to the terminal : ");
            scanf("%d", &numBuses);
            printf("\n");

            for (int i = 0; i < numBuses; i++)
            {
                int busID;
                int route;

                printf("Enter Bus ID for bus %d: ", i + 1);
                scanf("%d", &busID);

                printf("1. Assign Route Dhanmondi for bus %d: \n", i + 1);
                printf("2. Assign Route Mirpur for bus %d: \n", i + 1);
                printf("3. Assign Route Uttara for bus %d: \n", i + 1);
                printf("4. Assign Route Tongi College Gate for bus %d: \n", i + 1);
                printf("5. Assign Route Zirabo for bus %d: \n", i + 1);
                printf("6. Assign Route Baipail for bus %d: \n", i + 1);
                printf("7. Assign Route Dhamrai Bus Stand for bus %d: \n", i + 1);
                printf("8. Assign Route Savar for bus %d: \n", i + 1);
                printf("9. Assign Route Narayanganj for bus %d: \n", i + 1);
                printf("10. Assign Route Sony Cinema Hall for bus %d: \n", i + 1);
                printf("11. Assign Route Mugdha Model Thana for bus %d: \n", i + 1);
                printf("12. Assign Route Uttara Moylar Mor for bus %d: \n", i + 1);
                printf("\n");
                printf("Enter your Route number: ");
                scanf(" %d", &route);


                // Store the buses in each route using the enqueue function
                // Create a new bus node and assign the bus ID and route
                switch (route)
                {
                case 1:
                {
                    enqueue(&DhanmondiQueue, createBus(busID,"Dhanmondi"));
                    break;
                }
                case 2:
                {
                    enqueue(&MirpurECBQueue, createBus(busID,"Mirpur"));
                    break;
                }
                case 3:
                {
                    enqueue(&UttaraQueue, createBus(busID,"Uttara"));
                    break;
                }
                case 4:
                {
                    enqueue(&TongiCollegegateQueue, createBus(busID,"Tongi College gate"));
                    break;
                }
                case 5:
                {
                    enqueue(&ZiraboQueue, createBus(busID,"Zirabo"));
                    break;
                }
                case 6:
                {
                    enqueue(&BaipailQueue, createBus(busID,"Baipail"));
                    break;
                }
                case 7:
                {
                    enqueue(&DhamraiBusStandQueue, createBus(busID,"Dhamrai Bus Stand"));
                    break;
                }
                case 8:
                {
                    enqueue(&SavarQueue, createBus(busID,"Savar"));
                    break;
                }
                case 9:
                {
                    enqueue(&NarayanganjQueue, createBus(busID,"Narayanganj"));
                    break;
                }
                case 10:
                {
                    enqueue(&SonyCinemaHallQueue, createBus(busID,"Sony Cinema Hall"));
                    break;
                }
                case 11:
                {
                    enqueue(&MugdhaModelThanaQueue, createBus(busID,"Mugdha Model Thana"));
                    break;
                }
                case 12:
                {
                    enqueue(&UttaraMoylarMorQueue, createBus(busID,"Uttara Moylar Mor"));
                    break;
                }
                default:
                {
                    printf("Error: Unknown route for departing order.\n");
                    break;
                }
                }

                // Save departing orders to file
                saveDepartingOrdersToFile(&DhanmondiQueue, &MirpurECBQueue, &UttaraQueue, &TongiCollegegateQueue, &ZiraboQueue, &BaipailQueue, &DhamraiBusStandQueue, &SavarQueue, &NarayanganjQueue, &MugdhaModelThanaQueue, &SonyCinemaHallQueue, &UttaraMoylarMorQueue);

            }
            // Displaying the buses in the queues
            printf("Departing orders for Route Dhanmondi\n");
            displayQueue(&DhanmondiQueue);
            printf("Departing orders for Route Mirpur\n");
            displayQueue(&MirpurECBQueue);
            printf("Departing orders for Route Uttara\n");
            displayQueue(&UttaraQueue);
            printf("Departing orders for Route Tongi College gate\n");
            displayQueue(&TongiCollegegateQueue);
            printf("Departing orders for Route Zirabo\n");
            displayQueue(&ZiraboQueue);
            printf("Departing orders for Route Baipail\n");
            displayQueue(&BaipailQueue);
            printf("Departing orders for Route Dhamrai Bus Stand\n");
            displayQueue(&DhamraiBusStandQueue);
            printf("Departing orders for Route Savar\n");
            displayQueue(&SavarQueue);
            printf("Departing orders for Route Narayanganj\n");
            displayQueue(&NarayanganjQueue);
            printf("Departing orders for Route Mugdha Model Thana\n");
            displayQueue(&MugdhaModelThanaQueue);
            printf("Departing orders for Route Sony Cinema Hall\n");
            displayQueue(&SonyCinemaHallQueue);
            printf("Departing orders for Route Uttara Moylar Mor\n");
            displayQueue(&UttaraMoylarMorQueue);
        }
        else if (choice == 2)
        {
            printf("Available Buses to release\n");
            printf("\n");
             // Displaying the buses in the queues
            printf("Departing orders for Route Dhanmondi\n");
            displayQueue(&DhanmondiQueue);
            printf("Departing orders for Route Mirpur\n");
            displayQueue(&MirpurECBQueue);
            printf("Departing orders for Route Uttara\n");
            displayQueue(&UttaraQueue);
            printf("Departing orders for Route Tongi College gate\n");
            displayQueue(&TongiCollegegateQueue);
            printf("Departing orders for Route Zirabo\n");
            displayQueue(&ZiraboQueue);
            printf("Departing orders for Route Baipail\n");
            displayQueue(&BaipailQueue);
            printf("Departing orders for Route Dhamrai Bus Stand\n");
            displayQueue(&DhamraiBusStandQueue);
            printf("Departing orders for Route Savar\n");
            displayQueue(&SavarQueue);
            printf("Departing orders for Route Narayanganj\n");
            displayQueue(&NarayanganjQueue);
            printf("Departing orders for Route Mugdha Model Thana\n");
            displayQueue(&MugdhaModelThanaQueue);
            printf("Departing orders for Route Sony Cinema Hall\n");
            displayQueue(&SonyCinemaHallQueue);
            printf("Departing orders for Route Uttara Moylar Mor\n");
            displayQueue(&UttaraMoylarMorQueue);

            //printf("Select the route to leave the bus \n");

            int routeToDequeue;
            printf("1. Release Buses for route Dhanmondi : \n");
            printf("2. Release Buses for route Mirpur : \n" );
            printf("3. Release Buses for route Uttara : \n");
            printf("4. Release Buses for route Tongi College Gate for bus : \n");
            printf("5. Release Buses for route Zirabo : \n" );
            printf("6. Release Buses for route Baipail : \n");
            printf("7. Release Buses for route Dhamrai Bus Stand : \n");
            printf("8. Release Buses for route Savar : \n" );
            printf("9. Release Buses for route Narayanganj : \n");
            printf("10. Release Buses for route Sony Cinema Hall : \n");
            printf("11. Release Buses for route Mugdha Model Thana : \n" );
            printf("12. Release Buses for route Uttara Moylar Mor : \n");
            printf("Select the route to leave the bus : \n");
            scanf(" %d", &routeToDequeue);

            Queue* routeQueue; // Pointer to the selected route's queue

            // Choose the queue based on the entered route
            switch (routeToDequeue)
            {
            case 1:
            {
                routeQueue = &DhanmondiQueue;
                break;
            }
            case 2:
            {
                routeQueue = &MirpurECBQueue;
                break;
            }
            case 3:
            {
                routeQueue = &UttaraQueue;
                break;
            }
            case 4:
            {
                routeQueue = &TongiCollegegateQueue;
                break;
            }
            case 5:
            {
                routeQueue = &ZiraboQueue;
                break;
            }
            case 6:
            {
                routeQueue = &BaipailQueue;
                break;
            }
            case 7:
            {
                routeQueue = &DhamraiBusStandQueue;
                break;
            }
            case 8:
            {
                routeQueue = &SavarQueue;
                break;
            }
            case 9:
            {
                routeQueue = &NarayanganjQueue;
                break;
            }
            case 10:
            {
                routeQueue = &SonyCinemaHallQueue;
                break;
            }
            case 11:
            {
                routeQueue = &MugdhaModelThanaQueue;
                break;
            }
            case 12:
            {
                routeQueue = &UttaraMoylarMorQueue;
                break;
            }
            default:
            {
                printf("Invalid route entered for dequeuing buses.\n");
                return;
            }
            }

            int n;
            // Dequeue buses and store them in a separate array for display
            printf("How many buses do you want to release?: ");
            scanf(" %d", &n);
            Bus* dequeuedBuses[n];
            for (int i = 0; i < n; i++)
            {
                Bus* dequeuedBus = dequeue(routeQueue);
                if (dequeuedBus != NULL)
                {
                    push(&top, dequeuedBus);
                }
            }
            printf("\n");
            // Display the dequeued buses for the selected route
            printf("Departed Buses for Route %d:\n", routeToDequeue);
            displayStack(top);

            printf("\n");



            // Displaying the buses in the queues after dequeue
            printf("Departing orders for Route Dhanmondi\n");
            displayQueue(&DhanmondiQueue);
            printf("Departing orders for Route Mirpur\n");
            displayQueue(&MirpurECBQueue);
            printf("Departing orders for Route Uttara\n");
            displayQueue(&UttaraQueue);
            printf("Departing orders for Route Tongi College gate\n");
            displayQueue(&TongiCollegegateQueue);
            printf("Departing orders for Route Zirabo\n");
            displayQueue(&ZiraboQueue);
            printf("Departing orders for Route Baipail\n");
            displayQueue(&BaipailQueue);
            printf("Departing orders for Route Dhamrai Bus Stand\n");
            displayQueue(&DhamraiBusStandQueue);
            printf("Departing orders for Route Savar\n");
            displayQueue(&SavarQueue);
            printf("Departing orders for Route Narayanganj\n");
            displayQueue(&NarayanganjQueue);
            printf("Departing orders for Route Mugdha Model Thana\n");
            displayQueue(&MugdhaModelThanaQueue);
            printf("Departing orders for Route Sony Cinema Hall\n");
            displayQueue(&SonyCinemaHallQueue);
            printf("Departing orders for Route Uttara Moylar Mor\n");
            displayQueue(&UttaraMoylarMorQueue);

            // Save departing orders to file after dequeue
            saveDepartingOrdersToFile(&DhanmondiQueue, &MirpurECBQueue, &UttaraQueue, &TongiCollegegateQueue, &ZiraboQueue, &BaipailQueue, &DhamraiBusStandQueue, &SavarQueue, &NarayanganjQueue, &MugdhaModelThanaQueue, &SonyCinemaHallQueue, &UttaraMoylarMorQueue);
        }
        else
        {
            printf("Incorrect Access denied.\n");
        }
    }
    else
    {
        printf("Incorrect password. Access denied.\n");
        // If the password is incorrect, deny access to admin functionalities
    }


}

int main()
{
    Queue DhanmondiQueue = {NULL, NULL};
    Queue MirpurECBQueue = {NULL, NULL};
    Queue UttaraQueue = {NULL, NULL};
    Queue TongiCollegegateQueue = {NULL, NULL};
    Queue ZiraboQueue = {NULL, NULL};
    Queue BaipailQueue = {NULL, NULL};
    Queue DhamraiBusStandQueue = {NULL, NULL};
    Queue SavarQueue = {NULL, NULL};
    Queue NarayanganjQueue = {NULL, NULL};
    Queue MugdhaModelThanaQueue = {NULL, NULL};
    Queue SonyCinemaHallQueue = {NULL, NULL};
    Queue UttaraMoylarMorQueue = {NULL, NULL};

    // Print the top border of the table
    printf("+-----------------------------+\n");
    printf("| Welcome to DIU Bus Terminal |\n");
    printf("+-----------------------------+\n");
    int choice;
    do
    {
        printf("Choose Dashboard:\n");
        printf("1. Admin Dashboard\n");
        printf("2. General Viewer Dashboard\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        printf("\n");

        if (choice == 1)
        {
            // Admin Dashboard
            adminDashboard();

        }
        else if (choice == 2)
        {
            // General Viewer Dashboard
            readDepartingOrdersFromFile(&DhanmondiQueue, &MirpurECBQueue, &UttaraQueue, &TongiCollegegateQueue, &ZiraboQueue, &BaipailQueue, &DhamraiBusStandQueue, &SavarQueue, &NarayanganjQueue, &MugdhaModelThanaQueue, &SonyCinemaHallQueue, &UttaraMoylarMorQueue);
            printf ("Departing Time\n");
            printf ("From DSC to every ROUTE\n");

            printf ("10.30 AM\n");
            printf ("01.30 PM\n");
            printf ("04.20 PM\n");
            printf ("06.30 PM\n");
            printf ("09.30 PM (Only for Faculty)\n");

            printf("\n");
            printf("Departing orders for Route Dhanmondi\n");
            displayQueue(&DhanmondiQueue);

            printf("Departing orders for Route Mirpur\n");
            displayQueue(&MirpurECBQueue);
            printf("Departing orders for Route Uttara\n");
            displayQueue(&UttaraQueue);
            printf("Departing orders for Route Tongi College gate\n");
            displayQueue(&TongiCollegegateQueue);
            printf("Departing orders for Route Zirabo\n");
            displayQueue(&ZiraboQueue);
            printf("Departing orders for Route Baipail\n");
            displayQueue(&BaipailQueue);
            printf("Departing orders for Route Dhamrai Bus Stand\n");
            displayQueue(&DhamraiBusStandQueue);
            printf("Departing orders for Route Savar\n");
            displayQueue(&SavarQueue);
            printf("Departing orders for Route Narayanganj\n");
            displayQueue(&NarayanganjQueue);
            printf("Departing orders for Route Mugdha Model Thana\n");
            displayQueue(&MugdhaModelThanaQueue);
            printf("Departing orders for Route Sony Cinema Hall\n");
            displayQueue(&SonyCinemaHallQueue);
            printf("Departing orders for Route Uttara Moylar Mor\n");
            displayQueue(&UttaraMoylarMorQueue);

        }
        else if(choice==3)
        {
            pop(&top);
            break;
        }
        else
        {
            printf("Invalid choice.\n");
        }
        printf("\n");
    }
    while(choice != 4);


    return 0;
}
