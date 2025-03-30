#include <string>
using namespace std;

const int MAX_ROOMS = 100;
const int MAX_BOOKINGS = 200;

struct Date {
    int day;
    int month;
    int year;
};

class Booking;

class Room {
private:
    int id;
    string number;
    string type;
    double pricePerNight;

    Booking* bookings[MAX_BOOKINGS];
    int bookingCount;

public:
    Room(int id, const string& number, const string& type, double price);
    bool isAvailable(const Date& checkIn, const Date& checkOut) const;
    void addBooking(Booking* booking);
    double getPrice() const;
};

class Guest {
private:
    int id;
    string fullName;
    string email;
    string phone;

    Booking* bookings[MAX_BOOKINGS];
    int bookingCount;

public:
    Guest(int id, const string& name, const string& email, const string& phone);
    Booking* makeBooking(Room* room, const Date& checkIn, const Date& checkOut);
    bool cancelBooking(int bookingId);
};

class Booking {
private:
    int id;
    Guest* guest;
    Room* room;
    Date checkIn;
    Date checkOut;
    string status; // "active", "cancelled"

public:
    Booking(int id, Guest* guest, Room* room, const Date& checkIn, const Date& checkOut);
    bool overlaps(const Date& otherCheckIn, const Date& otherCheckOut) const;
    void cancel();
    int getId() const;
    string getStatus() const;
};

class Hotel {
private:
    int id;
    string name;
    string address;

    Room* rooms[MAX_ROOMS];
    int roomCount;

public:
    Hotel(int id, const string& name, const string& address);
    void addRoom(Room* room);
    Room** getAvailableRooms(const Date& checkIn, const Date& checkOut, int& count) const;
};

