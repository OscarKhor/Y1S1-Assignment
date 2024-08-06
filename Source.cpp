#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip> // for std::setw
using namespace std;

class Service {
public:
    string name;
    double price;
    Service(string n, double p) : name(n), price(p) {}
};

class Expert {
public:
    string name;
    int maxHoursPerWeek;
    int hoursWorked;
    map<string, vector<string>> schedule;
    Expert(string n) : name(n), maxHoursPerWeek(30), hoursWorked(0) {}
};

class Customer {
public:
    string name;
    vector<string> bookedServices;
    Customer(string n) : name(n) {}
};

class BeautyServiceApp {
private:
    vector<Service> services;
    vector<Expert> experts;
    vector<Customer> customers;

public:
    BeautyServiceApp() {
        // Initialize services and experts
        services.push_back(Service("Facial", 50.0));
        services.push_back(Service("Makeup Application", 70.0));
        services.push_back(Service("Manicure", 30.0));
        experts.push_back(Expert("Alice"));
        experts.push_back(Expert("Bob"));
        experts.push_back(Expert("Cathy"));
    }

    void showLogo() {
        // Set color to cyan for 'Beauty'
        std::cout << "\033[1;36m";
        std::cout << "*****   *****     ****      **  **  ******  **  **\n";
        std::cout << "**  **  **       **  **     **  **    **     **** \n";
        std::cout << "*****   ****    ********    **  **    **      **  \n";
        std::cout << "**  **  **     **      **   **  **    **      **  \n";
        std::cout << "*****   ***** **        **   ****     **      **  \n";
        std::cout << "\033[0m"; // Reset color

        std::cout << std::endl;

        // Set color to magenta for 'Services'
        std::cout << "\033[1;35m";
        std::cout << "*****  *****  ****    **   **  ******  ******  *****   *****\n";
        std::cout << "**     **     **  **   ** **     **    **      **      **   \n";
        std::cout << "*****  ****   ******    ***      **    **      ****    *****\n";
        std::cout << "   **  **     ** **     ***      **    **      **         **\n";
        std::cout << "*****  *****  **  **     *     ******  ******  *****   *****\n";
        std::cout << "\033[0m"; // Reset color
        std::cout << "\n";
    }

    void showMainMenu() {
        int choice;
        do {
            cout << "1. Customer Menu" << endl;
            cout << "2. Admin/Expert Menu" << endl;
            cout << "3. Exit" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: customerMenu(); break;
            case 2: adminExpertMenu(); break;
            case 3: cout << "Exiting..." << endl; break;
            default: cout << "Invalid choice. Please Try again." << endl;
            }
        } while (choice != 3);
    }

    void customerMenu() {
        int choice;
        do {
            cout << "1. View Organization Details" << endl;
            cout << "2. View Services and Experts" << endl;
            cout << "3. Check Schedule" << endl;
            cout << "4. Book Service" << endl;
            cout << "5. View Booked Schedule" << endl;
            cout << "6. Back to Main Menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: viewOrganizationDetails(); break;
            case 2: viewServicesAndExperts(); break;
            case 3: checkSchedule(); break;
            case 4: bookService(); break;
            case 5: viewBookedSchedule(); break;
            case 6: break;
            default: cout << "Invalid choice. Please Try again." << endl;
            }
        } while (choice != 6);
    }

    void adminExpertMenu() {
        int choice;
        do {
            cout << "1. View Individual Schedule" << endl;
            cout << "2. View Overall Schedule" << endl;
            cout << "3. View Customers" << endl;
            cout << "4. Generate Sales Report" << endl;
            cout << "5. Back to Main Menu" << endl;
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
            case 1: viewIndividualSchedule(); break;
            case 2: viewOverallSchedule(); break;
            case 3: viewCustomers(); break;
            case 4: generateSalesReport(); break;
            case 5: break;
            default: cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 5);
    }

    void viewOrganizationDetails() {
        std::cout << std::endl;
        cout << "Welcome to Beauty Services!" << endl;
        std::cout << std::endl;
        cout << "About Us:" << endl;
        cout << "Beauty Services, founded in 2010, focuses on delivering cutting-edge skincare and beauty solutions." << endl;
        cout << "Our mission is to prioritize quality, safety, and efficacy in all our services." << endl;
        std::cout << std::endl;
        cout << "Our services:" << endl;
        cout << "Facials           : Rejuvenate your skin with our custom facials." << endl;
        cout << "Makeup Application: Perfect your look for any occasion with our expert makeup artists." << endl;
        cout << "Manicure          : Improves the overall look of your nails and hands." << endl;
        std::cout << std::endl;
        cout << "Location          : 123 Beauty St." << endl;
        std::cout << std::endl;
        cout << "Online Presence:" << endl;
        cout << "Google            : www.Beautyservices.com" << endl;
        cout << "Instagram         : @Beautyservices" << endl;
        cout << "Facebook          : /Beautyservices" << endl;
        std::cout << std::endl;
        cout << "Customer Support:" << endl;
        cout << "Contact           : 555-1234" << endl;
        cout << "Email             : BeautyServices@gmail.com" << endl;
        std::cout << std::endl;
        std::cout << std::endl;
    }

    void viewServicesAndExperts() {
        std::cout << std::endl;
        cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;
        cout << left << setw(20) << "Service Name"
            << setw(20) << "Expert Name"
            << setw(10) << "Price" << endl;
        cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;

        // Display services, experts, and prices
        for (size_t i = 0; i < services.size(); ++i) {
            cout << left << setw(20) << services[i].name;
            if (i < experts.size()) {
                cout << setw(20) << experts[i].name;
            }
            else {
                cout << setw(20) << "N/A";
            }
            if (i < services.size()) {
                cout << fixed << setprecision(2) << setw(10) << services[i].price << endl;
            }
            else {
                cout << setw(10) << "N/A" << endl;
            }
        }

        std::cout << std::endl;
    }

    void checkSchedule() {
        // For simplicity, showing a static schedule
        cout << "Schedule for July:" << endl;
        for (auto& expert : experts) {
            cout << expert.name << " - Available slots: " << endl;
            for (auto& slot : expert.schedule["July"]) {
                cout << slot << " ";
            }
            cout << endl;
        }
    }

    void bookService() {
        string customerName, serviceName, expertName, slot;
        cout << "Enter your name: ";
        cin >> customerName;
        cout << "Enter service name: ";
        cin >> serviceName;
        cout << "Enter expert name: ";
        cin >> expertName;
        cout << "Enter slot: ";
        cin >> slot;

        // Check if slot is available and book it
        for (auto& expert : experts) {
            if (expert.name == expertName) {
                if (expert.hoursWorked >= expert.maxHoursPerWeek) {
                    cout << "This expert is fully booked for the week." << endl;
                    return;
                }
                for (auto& s : expert.schedule["July"]) {
                    if (s == slot) {
                        cout << "Slot already booked." << endl;
                        return;
                    }
                }
                expert.schedule["July"].push_back(slot);
                expert.hoursWorked += 2; // Assume each booking is 2 hours
                customers.push_back(Customer(customerName));
                customers.back().bookedServices.push_back(serviceName);
                cout << "Booking successful." << endl;
                std::cout << std::endl;
                cout << "Thank you for choosing Beauty Service, where beauty meets confidence!" << endl;
                return;
            }
        }
        cout << "Expert not found." << endl;
    }

    void viewBookedSchedule() {
        string customerName;
        cout << "Enter your name: ";
        cin >> customerName;
        for (auto& customer : customers) {
            if (customer.name == customerName) {
                cout << "Booked services: " << endl;
                for (auto& service : customer.bookedServices) {
                    cout << "- " << service << endl;
                }
                return;
            }
        }
        cout << "Customer not found." << endl;
    }
//Expert Menu function
    void viewIndividualSchedule() {
        string expertName;
        cout << "Enter expert name: ";
        cin >> expertName;
        for (auto& expert : experts) {
            if (expert.name == expertName) {
                cout << expert.name << " - Schedule for July:" << endl;
                for (auto& slot : expert.schedule["July"]) {
                    cout << slot << " ";
                }
                cout << endl;
                return;
            }
        }
        cout << "Expert not found." << endl;
    }

    void viewOverallSchedule() {
        cout << "Overall Schedule for July:" << endl;
        for (auto& expert : experts) {
            cout << expert.name << " - Available slots: " << endl;
            for (auto& slot : expert.schedule["July"]) {
                cout << slot << " ";
            }
            cout << endl;
        }
    }

    void viewCustomers() {
        cout << "Customers:" << endl;
        for (auto& customer : customers) {
            cout << "- " << customer.name << endl;
        }
    }

     void generateSalesReport() {
     double totalSales = 0.0;
     map<string, double> serviceSales; // Stores the total revenue for each service
     map<string, double> customerSales; // Stores the total revenue from each customer

     // Iterate through all customers
     for (auto& customer : customers) {
         double customerTotal = 0.0; // The total revenue for the current customer
         // Iterate through all services booked by the customer
         for (auto& service : customer.bookedServices) {
             // Iterate through all services to match the service name
             for (auto& s : services) {
                 if (s.name == service) {
                     totalSales += s.price; // Accumulate the total sales
                     customerTotal += s.price; // Accumulate the total revenue for the current customer
                     serviceSales[s.name] += s.price; // Accumulate the total revenue for the current service
                 }
             }
         }
         customerSales[customer.name] = customerTotal; // Record the total revenue for the current customer
     }

     // Output the revenue for each service
     cout << "Service Sales Breakdown:" << endl;
     for (auto& entry : serviceSales) {
         cout << "- " << setw(10) << left << entry.first << ": $" << fixed << setprecision(2) << entry.second << endl;
     }

     // Output the total sales
     cout << "Total Sales : $" << fixed << setprecision(2) << totalSales << endl;
     cout << "=====================" << endl;

     // Output the revenue from each customer
     cout << "Customer Sales Breakdown:" << endl;
     for (auto& entry : customerSales) {
         cout << "- " << setw(10) << left << entry.first << ": $" << fixed << setprecision(2) << entry.second << endl;
     }

     // Output the total sales again
     cout << "Total Sales : $" << fixed << setprecision(2) << totalSales << endl;
     cout << endl;
 }
};

int main() {
    BeautyServiceApp app;
    app.showLogo();
    app.showMainMenu();
    return 0;
}
