#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm> // For transform and equal

using namespace std;

// Define a class for Service
class Service {
public:
    string name;
    double price;
    Service(string n, double p) : name(n), price(p) {}
};

// Define a class for Expert
class Expert {
public:
    string name;
    int maxHoursPerWeek;
    int hoursWorked;
    map<int, vector<int>> schedule; // <month, days booked>

    Expert(string n) : name(n), maxHoursPerWeek(30), hoursWorked(0) {}
};

// Define a class for Customer
class Customer {
public:
    string name;
    vector<string> bookedServices;

    Customer(string n) : name(n) {}
};

// Define the main application class
class BeautyServiceApp {
private:
    vector<Service> services;
    vector<Expert> experts;
    vector<Customer> customers;

    // Case-insensitive string comparison
    static bool caseInsensitiveCompare(char a, char b) {
        return tolower(a) == tolower(b);
    }

    static bool caseInsensitiveEqual(const string& str1, const string& str2) {
        if (str1.size() != str2.size()) return false;
        return equal(str1.begin(), str1.end(), str2.begin(), caseInsensitiveCompare);
    }

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
        cout << "\033[1;36m";
        cout << "*****   *****     ****      **  **  ******  **  **\n";
        cout << "**  **  **       **  **     **  **    **     **** \n";
        cout << "*****   ****    ********    **  **    **      **  \n";
        cout << "**  **  **     **      **   **  **    **      **  \n";
        cout << "*****   ***** **        **   ****     **      **  \n";
        cout << "\033[0m";

        cout << endl;

        cout << "\033[1;35m";
        cout << "*****  *****  ****    **   **  ******  ******  *****   *****\n";
        cout << "**     **     **  **   ** **     **    **      **      **   \n";
        cout << "*****  ****   ******    ***      **    **      ****    *****\n";
        cout << "   **  **     ** **     ***      **    **      **         **\n";
        cout << "*****  *****  **  **     *     ******  ******  *****   *****\n";
        cout << "\033[0m";
        cout << "\n";
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
            default: cout << "Invalid choice. Please try again." << endl;
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
            default: cout << "Invalid choice. Please try again." << endl;
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
            case 1: {
                string expertName;
                cout << "Enter the expert's name: ";
                cin >> expertName;
                viewIndividualSchedule(expertName);
                break;
            }
            case 2: viewOverallSchedule(); break;
            case 3: viewCustomers(); break;
            case 4: generateSalesReport(); break;
            case 5: break;
            default: cout << "Invalid choice. Try again." << endl;
            }
        } while (choice != 5);
    }

    void viewOrganizationDetails() {
        cout << endl;
        cout << "Welcome to Beauty Services!" << endl;
        cout << endl;
        cout << "About Us:" << endl;
        cout << "Beauty Services, founded in 2010, focuses on delivering cutting-edge skincare and beauty solutions." << endl;
        cout << "Our mission is to prioritize quality, safety, and efficacy in all our services." << endl;
        cout << endl;
        cout << "Our services:" << endl;
        cout << "Facials           : Rejuvenate your skin with our custom facials." << endl;
        cout << "Makeup Application: Perfect your look for any occasion with our expert makeup artists." << endl;
        cout << "Manicure          : Improves the overall look of your nails and hands." << endl;
        cout << endl;
        cout << "Location          : 123 Beauty St." << endl;
        cout << endl;
        cout << "Online Presence:" << endl;
        cout << "Google            : www.Beautyservices.com" << endl;
        cout << "Instagram         : @Beautyservices" << endl;
        cout << "Facebook          : /Beautyservices" << endl;
        cout << endl;
        cout << "Customer Support:" << endl;
        cout << "Contact           : 555-1234" << endl;
        cout << "Email             : BeautyServices@gmail.com" << endl;
        cout << endl;
        cout << endl;
    }

    void viewServicesAndExperts() {
        cout << endl;
        cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;
        cout << left << setw(20) << "Service Name" << setw(20) << "Expert Name" << setw(10) << "Price" << endl;
        cout << setfill('-') << setw(45) << "" << setfill(' ') << endl;

        // Display services, experts, and prices
        size_t i;
        for (i = 0; i < services.size(); ++i) {
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

        cout << endl;
    }

    void showCalendar(int month) {
        const int daysInMonth = 30; // Simplified month length
        cout << "Sun Mon Tue Wed Thu Fri Sat\n";
        for (int i = 1; i <= daysInMonth; ++i) {
            bool booked = false;
            for (const auto& expert : experts) {
                if (expert.schedule.find(month) != expert.schedule.end()) {
                    if (find(expert.schedule.at(month).begin(), expert.schedule.at(month).end(), i) != expert.schedule.at(month).end()) {
                        booked = true;
                        break;
                    }
                }
            }
            cout << setw(3) << i << (booked ? "*" : " ") << " ";
            if (i % 7 == 0) cout << "\n";
        }
        cout << "\n";
    }

    void checkSchedule() {
        int month;
        cout << "Enter month (1-12): ";
        cin >> month;

        if (month < 1 || month > 12) {
            cout << "Invalid month. Please try again." << endl;
            return;
        }

        showCalendar(month);
    }

    void bookService() {
        string customerName;
        cout << "Enter your name: ";
        cin >> customerName;

        // Check if customer already exists
        auto customerIt = find_if(customers.begin(), customers.end(), [&](const Customer& c) {
            return caseInsensitiveEqual(c.name, customerName);
            });

        Customer* customer;
        if (customerIt == customers.end()) {
            customers.push_back(Customer(customerName));
            customer = &customers.back();
        }
        else {
            customer = &(*customerIt);
        }

        int serviceIndex;
        cout << "Available services:\n";
        for (size_t i = 0; i < services.size(); ++i) {
            cout << i + 1 << ". " << services[i].name << " - $" << services[i].price << endl;
        }
        cout << "Enter the service number you want to book: ";
        cin >> serviceIndex;

        if (serviceIndex < 1 || serviceIndex > services.size()) {
            cout << "Invalid service number. Please try again." << endl;
            return;
        }

        int expertIndex;
        cout << "Available experts:\n";
        for (size_t i = 0; i < experts.size(); ++i) {
            cout << i + 1 << ". " << experts[i].name << endl;
        }
        cout << "Enter the expert number you want to book: ";
        cin >> expertIndex;

        if (expertIndex < 1 || expertIndex > experts.size()) {
            cout << "Invalid expert number. Please try again." << endl;
            return;
        }

        int month, day;
        cout << "Enter the month (1-12): ";
        cin >> month;
        cout << "Enter the day (1-30): ";
        cin >> day;

        if (month < 1 || month > 12 || day < 1 || day > 30) {
            cout << "Invalid date. Please try again." << endl;
            return;
        }

        Expert& expert = experts[expertIndex - 1];
        expert.schedule[month].push_back(day);
        expert.hoursWorked += 1;

        customer->bookedServices.push_back(services[serviceIndex - 1].name);

        cout << "Booking successful for " << services[serviceIndex - 1].name << " with " << expert.name << " on " << month << "/" << day << "." << endl;
    }

    void viewBookedSchedule() {
        string customerName;
        cout << "Enter your name: ";
        cin >> customerName;

        // Check if customer exists
        auto customerIt = find_if(customers.begin(), customers.end(), [&](const Customer& c) {
            return caseInsensitiveEqual(c.name, customerName);
            });

        if (customerIt == customers.end()) {
            cout << "Customer not found." << endl;
            return;
        }

        const Customer& customer = *customerIt;
        cout << "Booked services for " << customer.name << ":\n";
        for (const auto& serviceName : customer.bookedServices) {
            cout << "- " << serviceName << endl;
        }
    }

    void viewIndividualSchedule(const string& expertName) {
        // Display individual schedule for the expert
        for (size_t i = 0; i < experts.size(); ++i) {
            if (experts[i].name == expertName) {
                cout << "Schedule for " << experts[i].name << ":\n";
                for (const auto& month : experts[i].schedule) {
                    cout << "Month: " << month.first << "\nDays: ";
                    for (size_t j = 0; j < month.second.size(); ++j) {
                        cout << month.second[j] << " ";
                    }
                    cout << "\n";
                }
                return;
            }
        }
        cout << "Expert not found." << endl;
    }

    void viewOverallSchedule() {
        // Display the overall schedule for all experts
        cout << "Overall schedule for all experts:\n";
        for (size_t i = 0; i < experts.size(); ++i) {
            cout << "Expert: " << experts[i].name << "\n";
            for (const auto& month : experts[i].schedule) {
                cout << "Month: " << month.first << "\nDays: ";
                for (size_t j = 0; j < month.second.size(); ++j) {
                    cout << month.second[j] << " ";
                }
                cout << "\n";
            }
            cout << "\n";
        }
    }

    void viewCustomers() {
        cout << "Customer list:" << endl;
        for (const auto& customer : customers) {
            cout << customer.name << endl;
        }
    }

    void generateSalesReport() {
        double totalSales = 0.0;
        for (const auto& customer : customers) {
            for (const auto& serviceName : customer.bookedServices) {
                auto serviceIt = find_if(services.begin(), services.end(), [&](const Service& s) {
                    return caseInsensitiveEqual(s.name, serviceName);
                    });
                if (serviceIt != services.end()) {
                    totalSales += serviceIt->price;
                }
            }
        }
        cout << "Total sales: $" << fixed << setprecision(2) << totalSales << endl;
    }
};

int main() {
    BeautyServiceApp app;
    app.showLogo();
    app.showMainMenu();
    return 0;
}
