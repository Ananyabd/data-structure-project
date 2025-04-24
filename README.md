# data-structure-project
🔹 Project Title
Transportation System (DIU Bus Terminal Simulation)

🔹 Objective
*To simulate a university bus terminal using data structures to manage bus schedules, departures, and releases on various routes effectively.

🔹 Key Functionalities
1.Admin Dashboard
2.Add buses to different routes.
3.Release (dequeue) buses from specific routes.
4.View and manage all route schedules.
5.Save and read data from files for persistence.
6.General Viewer Dashboard
7.View the current bus schedules for all routes.
8.Display the fixed bus departure times.
9.Data Persistence
10.Reads from and writes to a file named departing_orders.txt to store bus queue data persistently across runs.

🔹 Data Structures Used
1.Struct Bus
*Stores bus ID and route information.
*Linked list structure to facilitate queue operations.

2,Struct Queue
*Used to represent buses in a particular route.
*Implements FIFO logic using front and rear pointers.

3.Struct StackNode
*Used to manage released buses using a stack (LIFO) approach.

🔹 Operations
1.Enqueue (Add Bus): Adds a bus to the end of a specific route's queue.

2.Dequeue (Release Bus): Removes the front bus from a selected route queue and pushes it onto a stack.

3.Display Queue: Shows the current buses in a particular route.

4.Push/Pop Stack: Stack used for managing released buses.

5.File Read/Write: Saves and loads bus queues to/from a file.

🔹 Routes Supported
12 predefined routes including:

Dhanmondi
Mirpur
Uttara
Tongi College Gate
Zirabo
Baipail
Dhamrai Bus Stand
Savar
Narayanganj
Sony Cinema Hall
Mugdha Model Thana
Uttara Moylar Mor

🔹 Fixed Departure Times
10:30 AM
1:30 PM
4:20 PM
6:30 PM
9:30 PM (Only for Faculty)

🔹 Admin Access
Protected by a password: "AnisBhai"

🔹 File Handling
File: departing_orders.txt

Stores bus IDs under corresponding routes for persistence.

🔹 Highlights
1.Practical use of queues and stacks to model real-life transportation operations.

2.File I/O for saving and retrieving data.

3.Modular code structure with functions for each operation.

4.Interactive CLI for both admin and general users.
