#include <stdio.h>

#define MAX_SEATS 10

int seats[MAX_SEATS];  // Booking status of each seat

void display_seats() {
    printf("\nSeating Arrangement:\n");
    for (int i = 0; i < MAX_SEATS; i++) {
        printf("Seat %d: %s\n", i + 1, seats[i] ? "Booked" : "Available");
    }
}

void book_seat() {
    int seat_num;
    printf("Enter seat number to book (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_num);

    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    if (seats[seat_num - 1]) {
        printf("Seat %d is already booked.\n", seat_num);
    } else {
        seats[seat_num - 1] = 1;
        printf("Seat %d has been booked successfully.\n", seat_num);
    }
}

void cancel_seat() {
    int seat_num;
    printf("Enter seat number to cancel booking (1-%d): ", MAX_SEATS);
    scanf("%d", &seat_num);

    if (seat_num < 1 || seat_num > MAX_SEATS) {
        printf("Invalid seat number! Please try again.\n");
        return;
    }

    if (seats[seat_num - 1] == 0) {
        printf("Seat %d is not booked yet.\n", seat_num);
    } else {
        seats[seat_num - 1] = 0;
        printf("Booking for seat %d has been canceled.\n", seat_num);
    }
}

int main() {
    for (int i = 0; i < MAX_SEATS; i++) {
        seats[i] = 0;
    }

    while (1) {
        int choice;
        printf("\n--- Seat Booking System ---\n");
        printf("1. Display Seating Arrangement\n");
        printf("2. Book a Seat\n");
        printf("3. Cancel a Booking\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                display_seats();
                break;
            case 2:
                book_seat();
                break;
            case 3:
                cancel_seat();
                break;
            case 4:
                printf("Exiting... Thank you!\n");
                return 0;
            default:
                printf("Invalid choice! Please enter a valid option.\n");
        }
    }
}
