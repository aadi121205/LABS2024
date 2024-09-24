#include <iostream>
#include <string>

class TravelPlan {
private:
    long PlanCode;
    std::string Place;
    int NumberOfTravellers;
    int NumberOfBuses;

public:
    // Constructor with default values
    TravelPlan() {
        PlanCode = 1001;
        Place = "Agra";
        NumberOfTravellers = 5;
        NumberOfBuses = 1;
    }

    // Function to input new plan details
    void NewPlan() {
        std::cout << "Enter Plan Code: ";
        std::cin >> PlanCode;
        std::cout << "Enter Place: ";
        std::cin >> Place;
        std::cout << "Enter Number of Travellers: ";
        std::cin >> NumberOfTravellers;
        
        // Determine number of buses based on number of travellers
        if (NumberOfTravellers < 20) {
            NumberOfBuses = 1;
        } else if (NumberOfTravellers >= 20 && NumberOfTravellers < 40) {
            NumberOfBuses = 2;
        } else if (NumberOfTravellers >= 40) {
            NumberOfBuses = 3;
        }
    }

    // Function to display plan details
    void ShowPlan() const {
        std::cout << "Plan Code: " << PlanCode
                  << "\nPlace: " << Place
                  << "\nNumber of Travellers: " << NumberOfTravellers
                  << "\nNumber of Buses: " << NumberOfBuses << std::endl;
    }
};

int main() {
    TravelPlan tp;
    tp.ShowPlan();  // Display default values
    tp.NewPlan();   // Input new plan
    tp.ShowPlan();  // Display new plan

    return 0;
}
