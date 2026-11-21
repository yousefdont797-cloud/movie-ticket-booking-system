
#include <iostream>
#include <string>
using namespace std;

// Base Class
class Movie {
protected:
    string movieName;
    double ticketPrice;

public:
    // Constructor
    Movie(string name, double price) {
        movieName = name;
        ticketPrice = price;
    }

    // Virtual Function (Polymorphism)
    virtual void displayMovie() {
        cout << "Movie: " << movieName << endl;
        cout << "Ticket Price: $" << ticketPrice << endl;
    }

    // Function Overloading
    double calculatePrice(int tickets) {
        return ticketPrice * tickets;
    }

    double calculatePrice(int tickets, double discount) {
        return (ticketPrice * tickets) - discount;
    }

    // Destructor
    virtual ~Movie() {
        cout << "Movie object destroyed." << endl;
    }
};

// Derived Class
class Booking : public Movie {
private:
    string customerName;
    int numberOfTickets;

public:
    // Constructor
    Booking(string name, double price,
            string customer, int tickets)
        : Movie(name, price) {

        customerName = customer;
        numberOfTickets = tickets;
    }

    // Override Function (Polymorphism)
    void displayMovie() override {
        cout << "\n----- Booking Details -----" << endl;
        cout << "Customer: " << customerName << endl;
        cout << "Movie: " << movieName << endl;
        cout << "Ticket Price: $" << ticketPrice << endl;
        cout << "Number of Tickets: "
             << numberOfTickets << endl;
        cout << "Total Price: $"
             << calculatePrice(numberOfTickets) << endl;
    }

    // Destructor
    ~Booking() {
        cout << "Booking object destroyed." << endl;
    }
};

// Main Function
int main() {

    string movie, customer;
    double price;
    int tickets;

    cout << "===== Movie Ticket Booking System =====" << endl;

    cout << "Enter Movie Name: ";
    getline(cin, movie);

    cout << "Enter Ticket Price: ";
    cin >> price;

    cin.ignore();

    cout << "Enter Customer Name: ";
    getline(cin, customer);

    cout << "Enter Number of Tickets: ";
    cin >> tickets;

    // Creating an Object
    Booking booking(movie, price, customer, tickets);

    // Polymorphism using Base Class Pointer
    Movie* ptr = &booking;

    ptr->displayMovie();

    // Function Overloading Example
    cout << "\nTotal with $5 discount: $"
         << booking.calculatePrice(tickets, 5) << endl;

    cout << "\nThank you for booking!" << endl;

    return 0;
}
