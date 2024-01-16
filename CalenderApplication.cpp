#include <iostream>
#include <vector>
#include <algorithm>

struct Event {
    std::string title;
    std::string date;
    std::string time;
};

std::vector<Event> events;

void displayMenu() {
    std::cout << "1. Add Event\n";
    std::cout << "2. Edit Event\n";
    std::cout << "3. Delete Event\n";
    std::cout << "4. View Events\n";
    std::cout << "5. Exit\n";
}

void addEvent() {
    Event newEvent;
    std::cout << "Enter event title: ";
    std::cin.ignore();
    std::getline(std::cin, newEvent.title);
    std::cout << "Enter date (YYYY-MM-DD): ";
    std::cin >> newEvent.date;
    std::cout << "Enter time: ";
    std::cin >> newEvent.time;

    events.push_back(newEvent);
    std::cout << "Event added successfully!\n";
}

void editEvent() {
    int index;
    std::cout << "Enter the index of the event to edit: ";
    std::cin >> index;

    if (index >= 0 && index < events.size()) {
        std::cout << "Enter new title: ";
        std::cin.ignore();
        std::getline(std::cin, events[index].title);
        std::cout << "Enter new date (YYYY-MM-DD): ";
        std::cin >> events[index].date;
        std::cout << "Enter new time: ";
        std::cin >> events[index].time;
        std::cout << "Event edited successfully!\n";
    } else {
        std::cout << "Invalid index\n";
    }
}

void deleteEvent() {
    int index;
    std::cout << "Enter the index of the event to delete: ";
    std::cin >> index;

    if (index >= 0 && index < events.size()) {
        events.erase(events.begin() + index);
        std::cout << "Event deleted successfully!\n";
    } else {
        std::cout << "Invalid index\n";
    }
}

void viewEvents() {
    if (events.empty()) {
        std::cout << "No events to display\n";
    } else {
        std::cout << "Events:\n";
        for (int i = 0; i < events.size(); ++i) {
            std::cout << i << ". Title: " << events[i].title << " | Date: " << events[i].date << " | Time: " << events[i].time << "\n";
        }
    }
}

int main() {
    int choice;

    do {
        displayMenu();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                addEvent();
                break;
            case 2:
                editEvent();
                break;
            case 3:
                deleteEvent();
                break;
            case 4:
                viewEvents();
                break;
            case 5:
                std::cout << "Exiting the application\n";
                break;
            default:
                std::cout << "Invalid choice\n";
        }
    } while (choice != 5);

    return 0;
}