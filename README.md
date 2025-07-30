# Concert Ticket Booking System

This is a simple C++ console application for booking concert tickets. The project demonstrates the use of functions, struct arrays, file I/O, and basic user interaction in C++. It allows users to view the concert stage layout, enter customer details, select seat types, and generate receipts.

## Features

- **Stage Layout Display:** View a visual representation of the concert stage from `stage.txt`.
- **Customer Registration:** Enter customer name, phone number, email, number of tickets, and seat type.
- **Seat Options:**
  - **A (Premium):** RM 50
  - **B (Medium):** RM 35
  - **C (Budget):** RM 20
- **Receipt Generation:** Automatically generates a receipt and saves customer info to files.
- **Multiple Purchases:** Option to continue booking for multiple customers.

## File Structure

- [`main.cpp`](main.cpp): Main source code for the application.
- [`stage.txt`](stage.txt): ASCII art layout of the concert stage.
- [`Introduction`](Introduction): Brief description of the project.
- `customerInfo.txt`: Generated file containing customer information.
- `receipt.txt`: Generated file containing ticket receipts.

## How to Run

1. **Compile the program:**
   ```sh
   g++ main.cpp -o concert_ticket