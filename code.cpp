#include <iostream>
#include <string>
#include <cctype>
#include <ctime>
#include <vector>
#include <sstream>

using namespace std;

// Welcome Message for the customer.
void welcomeMessage() {
    cout << "                                        ******************************************" << endl;
    cout << "                                        *                                        *" << endl;
    cout << "                                        *          Welcome to RevoMotive!        *" << endl;
    cout << "                                        *  Your Ultimate Car Customization Hub!  *" << endl;
    cout << "                                        *                                        *" << endl;
    cout << "                                        ******************************************" << endl;
}

// Goodbye message for the customer when they choose not to book
void exitMessage()
{
    cout <<"                                         -----------------------------------------------------------------------\n";
    cout <<"                                             Thank you for reaching out to us. We appreciate your interest!\n";
    cout <<"                                             Visit us next time when you're ready to customize your vehicle.\n";
    cout <<"                                                                   Have a great day ahead!\n";
    cout <<"                                         -----------------------------------------------------------------------\n";
}

// Goodbye message for the customer after completing the process
void goodbyeMessage()
{
    cout << "                                        -----------------------------------------------------------------------\n";
    cout << "                                         Thank you for choosing RevoMotive! Your dream car is just a step away. \n";
    cout << "                                            We hope you had a great experience customizing your vehicle. \n";
    cout << "                                           Drive safe and stay stylish! We look forward to your next visit. \n";
    cout << "                                         Don't forget to check out our special deals during festive seasons! \n";
    cout << "                                        -----------------------------------------------------------------------\n";
}

// Function to check if a date is within 2 months from today
bool isValidDate(const string& date)
{
    // Current date
    time_t now = time(0);
    tm* current = localtime(&now);
    int currentYear = current->tm_year + 1900;
    int currentMonth = current->tm_mon + 1;
    int currentDay = current->tm_mday;

    // Parse input date
    int day, month, year;
    char sep1, sep2;
    istringstream iss(date);
    if (!(iss >> day >> sep1 >> month >> sep2 >> year) || sep1 != '/' || sep2 != '/')
    {
        return false;
    }

    // Basic date validation
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < currentYear)
    {
        return false;
    }

    // Check for valid days in each month
    if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30)
        return false;

    if (month == 2)
    {
        bool isLeap = (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0));
        if (day > (isLeap ? 29 : 28))
            return false;
    }

    // Check if date is in the future but within 2 months
    if (year > currentYear)
        return false; // Not within current year

    if (year == currentYear)
    {
        if (month < currentMonth)
            return false;
        if (month > currentMonth + 2)
            return false;
        if (month == currentMonth && day < currentDay)
            return false;
    }

    return true;
}

// Function to format time in 24-hour format with am/pm
string formatTime(const string& timeStr)
{
    int hour, minute;
    char colon;
    istringstream ss(timeStr);
    if (!(ss >> hour >> colon >> minute) || colon != ':' || hour < 0 || hour > 23 || minute < 0 || minute > 59)
    {
        return "Invalid Time";
    }

    string period = (hour < 12) ? " am" : " pm";
    int displayHour = (hour == 0 || hour == 12) ? 12 : hour % 12;
    return (displayHour < 10 ? "0" : "") + to_string(displayHour) + ":" +
           (minute < 10 ? "0" : "") + to_string(minute) + period;
}

// Online Booking for customer
class Booking
{
public:
    bool makeAppointment(string& customerName, string& pickupDate, string& pickupTime)
    {
        string choice;
        cout << "\nWould you like to customize your car? (Y/N): ";
        cin >> choice;

        if (choice == "Y" || choice == "y")
        {
            string time;
            cout << "\n----------------------------------------\n";
            cout << "      Online Customization Booking        \n";
            cout << "----------------------------------------\n";
            cin.ignore();

            // Get customer name
            cout << "Enter your name for booking: ";
            getline(cin, customerName);

            // Get preferred appointment date
            bool validDate = false;
            do
            {
                cout << "Enter preferred appointment date (DD/MM/YYYY) within next 2 months: ";
                getline(cin, pickupDate);
                validDate = isValidDate(pickupDate);
                if (!validDate)
                {
                    cout << "Invalid date. Please enter a date within the next 2 months in DD/MM/YYYY format.\n";
                }
            }
            while (!validDate);

            // Get preferred appointment time
            bool validTime = false;
            string formattedTime;
            do
            {
                cout << "Enter preferred time (HH:MM in 24-hour format, e.g., 14:30): ";
                getline(cin, time);
                formattedTime = formatTime(time);
                if (formattedTime == "Invalid Time")
                {
                    cout << "Invalid time format. Please use HH:MM in 24-hour format (e.g., 09:00 or 15:45).";
                }
                else
                {
                    validTime = true;
                }
            }
            while (!validTime);

            pickupTime = time;  // Store raw pickup time if needed.

            cout << "Thank you, " << customerName << ". Your delivery partner will come to you for picking up your car on " << pickupDate << " at " << formattedTime << ".\n";
            cout << "Continue with the further details!\n";

            return true;
        }
        else
        {
            exitMessage();
            return false;
        }
    }
};

// Customer Details
class Customer
{
protected:
    string name;
    string mobileNumber;
    int usageDuration;
    string location;
public:
    void setCustomerName(const string& n)
    {
        name = n;
    }

    void getMobileNumberInput()
    {
        cout << "Enter your mobile number: ";
        cin.ignore();
        getline(cin, mobileNumber);
        // Simple validation
        while (mobileNumber.length() < 10)
        {
            cout << "Invalid mobile number. Please enter at least 10 digits: ";
            getline(cin, mobileNumber);
        }
    }

    void getUsageDurationInput()
    {
        cout << "Enter usage duration (in years): ";
        cin >> usageDuration;
    }

    void getLocationInput()
    {
        cout << "Enter your location for car pickup:\n ";
        cin.ignore();
        getline(cin, location);
    }

    void showCustomerDetails()
    {
        cout << "-----------------------------------------\n";
        cout << "Customer Name: " << name << "\n";
        cout << "Mobile Number: " << mobileNumber << "\n";
        cout << "Usage Duration: " << usageDuration << " years\n";
        cout << "Pickup Location: " << location << "\n";
        cout << "-----------------------------------------\n";
    }

    int getUsageDuration() const
    {
        return usageDuration;
    }

    string getLocation() const
    {
        return location;
    }

    void editCustomerDetails()
    {
        int choice;
        do
        {
            cout << "\nEdit Customer Details:\n";
            cout << "1. Name (" << name << ")\n";
            cout << "2. Mobile Number (" << mobileNumber << ")\n";
            cout << "3. Usage Duration (" << usageDuration << " years)\n";
            cout << "4. Location (" << location << ")\n";
            cout << "0. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                {
                    cout << "Enter new name: ";
                    cin.ignore();
                    getline(cin, name);
                    break;
                }
                case 2:
                {
                    getMobileNumberInput();
                    break;
                }
                case 3:
                {
                    getUsageDurationInput();
                    break;
                }
                case 4:
                {
                    getLocationInput();
                    break;
                }
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 0);
    }
};

// Model class for selecting car brand and model
class Model
{
public:
    vector<string> brands = {"Tesla", "BMW", "Audi", "Mercedes", "Toyota", "Ford", "Honda", "Nissan"};
    vector<string> models;

    string selectedBrand;
    string selectedModel;

    void selectBrand()
    {
        cout << "\nAvailable Car Brands:\n";
        for (int i = 0; i < brands.size(); i++)
        {
            cout << i + 1 << ". " << brands[i] << "\n";
        }
        int brandChoice;

        cout << "Enter the number of your selected brand: ";
        cin >> brandChoice;

        if (brandChoice >= 1 && brandChoice <= brands.size())
        {
            selectedBrand = brands[brandChoice - 1];
            selectModel();
        }
        else
        {
            cout << "Invalid brand choice.\n";
        }
    }

    void selectModel()
    {
        if (selectedBrand == "Tesla")
            models = {"Model S", "Model 3", "Model X", "Model Y"};
        else if (selectedBrand == "BMW")
            models = {"BMW X5", "BMW 3 Series", "BMW 5 Series", "BMW M4"};
        else if (selectedBrand == "Audi")
            models = {"Audi A4", "Audi Q5", "Audi Q7", "Audi R8"};
        else if (selectedBrand == "Mercedes")
            models = {"Mercedes-Benz A-Class", "Mercedes-Benz S-Class", "Mercedes-Benz GLA", "Mercedes-Benz GLC"};
        else if (selectedBrand == "Toyota")
            models = {"Toyota Corolla", "Toyota Camry", "Toyota Prius", "Toyota Land Cruiser"};
        else if (selectedBrand == "Ford")
            models = {"Ford Mustang", "Ford F-150", "Ford Focus", "Ford Explorer"};
        else if (selectedBrand == "Honda")
            models = {"Honda Civic", "Honda Accord", "Honda CR-V", "Honda Pilot"};
        else if (selectedBrand == "Nissan")
            models = {"Nissan Altima", "Nissan Maxima", "Nissan Rogue", "Nissan Leaf"};

        cout << "\nAvailable models for " << selectedBrand << ":\n";
        for (int i = 0; i < models.size(); i++)
        {
            cout << i + 1 << ". " << models[i] << "\n";
        }

        int modelChoice;
        cout << "Enter the number of your selected model: ";
        cin >> modelChoice;

        if (modelChoice >= 1 && modelChoice <= models.size())
        {
            selectedModel = models[modelChoice - 1];
        }
        else
        {
            cout << "Invalid model choice.\n";
        }
    }

    void showBrandAndModel()
    {
        cout << "\nSelected Brand: " << selectedBrand;
        cout << "\nSelected Model: " << selectedModel << "\n";
    }

    void editModelSelection()
    {
        int choice;
        do
        {
            cout << "\nEdit Vehicle Selection:\n";
            cout << "1. Brand (" << selectedBrand << ")\n";
            cout << "2. Model (" << selectedModel << ")\n";
            cout << "0. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    selectBrand();
                    break;
                case 2:
                    selectModel();
                    break;
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        }
        while (choice != 0);
    }
};

// Customization options
class Customization
{
public:
    string selectedColor;
    string selectedTyre;
    string selectedInterior;
    string selectedFramework;
    string selectedPerformance;
    vector<string> selectedAddOns;
    int tyreCost = 0, interiorCost = 0, frameworkCost = 0, performanceCost = 0, addonCost = 0;

    void chooseColor()
    {
        cout << "\nAvailable Colors:\n";
        cout << "1. White - Rs. 0\n2. Red - Rs. 5000\n3. Blue - Rs. 7000\n4. Black - Rs. 8000\n5. Silver - Rs. 6000\nEnter your color choice (1-5): ";
        int colorChoice;
        cin >> colorChoice;

        switch (colorChoice)
        {
            case 1: selectedColor = "White";
                break;
            case 2: selectedColor = "Red (Rs. 5000)";
                break;
            case 3: selectedColor = "Blue (Rs. 7000)";
                break;
            case 4: selectedColor = "Black (Rs. 8000)";
                break;
            case 5: selectedColor = "Silver (Rs. 6000)";
                break;
            default: cout << "Invalid color choice.\n";
                break;
        }
    }

    void chooseTyre()
    {
        cout << "\nAvailable Tyre Types:\n";
        cout << "1. Standard - Rs. 10000\n2. Sport - Rs. 15000\n3. Off-road - Rs. 20000\n4. All-season - Rs. 12000\n5. Performance - Rs. 18000\nEnter your tyre choice (1-5): ";
        int tyreChoice;
        cin >> tyreChoice;

        switch (tyreChoice)
        {
            case 1: selectedTyre = "Standard"; tyreCost = 10000;
                break;
            case 2: selectedTyre = "Sport"; tyreCost = 15000;
                break;
            case 3: selectedTyre = "Off-road"; tyreCost = 20000;
                break;
            case 4: selectedTyre = "All-season"; tyreCost = 12000;
                break;
            case 5: selectedTyre = "Performance"; tyreCost = 18000;
                break;
            default: cout << "Invalid tyre choice.\n";
                break;
        }
    }

    void chooseInterior()
    {
        cout << "\nAvailable Interior Types:\n";
        cout << "1. Leather - Rs. 20000\n2. Fabric - Rs. 15000\n3. Vinyl - Rs. 10000\nEnter your interior choice: ";
        int interiorChoice;
        cin >> interiorChoice;

        switch (interiorChoice)
        {
            case 1: selectedInterior = "Leather"; interiorCost = 20000;
                break;
            case 2: selectedInterior = "Fabric"; interiorCost = 15000;
                break;
            case 3: selectedInterior = "Vinyl"; interiorCost = 10000;
                break;
            default: cout << "Invalid interior choice.\n";
                break;
        }
    }

    void chooseAddOns()
    {
        cout << "\nAvailable Add-Ons:\n";
        cout << "1. Sunroof - Rs. 12000\n2. GPS Navigation - Rs. 8000\n3. Rear Camera - Rs. 6000\n4. Premium Sound System - Rs. 15000\nEnter your add-on choice (1-4), or 0 to finish: ";
        int addonChoice;
        while (true)
        {
            cin >> addonChoice;
            if (addonChoice == 0)
                break;
            switch (addonChoice)
            {
                case 1: selectedAddOns.push_back("Sunroof (Rs. 12000)"); addonCost += 12000;
                    break;
                case 2: selectedAddOns.push_back("GPS Navigation (Rs. 8000)"); addonCost += 8000;
                    break;
                case 3: selectedAddOns.push_back("Rear Camera (Rs. 6000)"); addonCost += 6000;
                    break;
                case 4: selectedAddOns.push_back("Premium Sound System (Rs. 15000)"); addonCost += 15000;
                    break;
                default: cout << "Invalid add-on choice.\n";
                    break;
            }
            cout << "\nEnter your next add-on choice (1-4), or 0 to finish: ";
        }
    }

    void choosePerformance()
    {
        cout << "\nAvailable Performance Upgrades:\n";
        cout << "1. Turbocharge - Rs. 25000\n2. Nitrous Oxide System - Rs. 30000\n3. Supercharger - Rs. 35000\nEnter your performance upgrade choice: ";
        int performanceChoice;
        cin >> performanceChoice;

        switch (performanceChoice)
        {
            case 1: selectedPerformance = "Turbocharge"; performanceCost = 25000;
                break;
            case 2: selectedPerformance = "Nitrous Oxide System"; performanceCost = 30000;
                break;
            case 3: selectedPerformance = "Supercharger"; performanceCost = 35000;
                break;
            default: cout << "Invalid performance upgrade choice.\n";
                break;
        }
    }

    void chooseFramework()
    {
        cout << "\nAvailable Framework Upgrades:\n";
        cout << "1. Lightweight Carbon Fiber - Rs. 20000\n2. Reinforced Steel - Rs. 15000\n3. Off-road Suspension - Rs. 25000\nEnter your framework upgrade choice: ";
        int frameworkChoice;
        cin >> frameworkChoice;

        switch (frameworkChoice)
        {
            case 1: selectedFramework = "Lightweight Carbon Fiber"; frameworkCost = 20000;
                break;
            case 2: selectedFramework = "Reinforced Steel"; frameworkCost = 15000;
                break;
            case 3: selectedFramework = "Off-road Suspension"; frameworkCost = 25000;
                break;
            default: cout << "Invalid framework upgrade choice.\n";
                break;
        }
    }

    void customize()
    {
        int modChoice;
        do
        {
            cout << "\nCustomization Options:\n";
            cout << "1. Tyre\n2. Interior\n3. Framework\n4. Performance\n5. Add-ons\n6. Color\n0. Done\nEnter choice: ";
            cin >> modChoice;

            switch (modChoice)
            {
                case 1: chooseTyre(); cout << "Tyre customized to: " << selectedTyre << "\n";
                    break;
                case 2: chooseInterior(); cout << "Interior customized to: " << selectedInterior << "\n";
                    break;
                case 3: chooseFramework(); cout << "Framework customized to: " << selectedFramework << "\n";
                    break;
                case 4: choosePerformance(); cout << "Performance upgraded to: " << selectedPerformance << "\n";
                    break;
                case 5: chooseAddOns(); cout << "Add-ons selected.\n";
                    break;
                case 6: chooseColor(); cout << "Color " << selectedColor << " selected.\n";
                    break;
                case 0: cout << "Finished customization.\n";
                    break;
                default: cout << "Invalid choice.\n";
                    break;
            }
        }
        while (modChoice != 0);
    }

    void showCustomizationSummary() const
    {
        cout << "\n----------------------------------------\n";
        cout << "              BILL SUMMARY\n";
        cout << "----------------------------------------\n";
        cout << "Color: " << selectedColor << "\n";
        cout << "Tyres: " << selectedTyre << " (Rs. " << tyreCost << ")\n";
        cout << "Interior: " << selectedInterior << " (Rs. " << interiorCost << ")\n";
        if (!selectedFramework.empty())
            cout << "Framework: " << selectedFramework << " (Rs. " << frameworkCost << ")\n";
        if (!selectedPerformance.empty())
            cout << "Performance: " << selectedPerformance << " (Rs. " << performanceCost << ")\n";

        if (!selectedAddOns.empty())
        {
            cout << "Add-ons:\n";
            for (const auto& addon : selectedAddOns)
            {
                cout << " - " << addon << "\n";
            }
            cout << "Total Add-ons Cost: Rs. " << addonCost << "\n";
        }

        int total = tyreCost + interiorCost + frameworkCost + performanceCost + addonCost;
        cout << "----------------------------------------\n";
        cout << "    TOTAL BILL COST: Rs. " << total << "\n";
        cout << "----------------------------------------\n";
    }

    void editCustomization()
    {
        int choice;
        do
        {
            cout << "\nEdit Customization:\n";
            cout << "1. Color (" << selectedColor << ")\n";
            cout << "2. Tyres (" << selectedTyre << ")\n";
            cout << "3. Interior (" << selectedInterior << ")\n";
            cout << "4. Framework (" << selectedFramework << ")\n";
            cout << "5. Performance (" << selectedPerformance << ")\n";
            cout << "6. Add-ons (" << selectedAddOns.size() << " items)\n";
            cout << "0. Back to main menu\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice)
            {
                case 1:
                    chooseColor();
                    break;
                case 2:
                    chooseTyre();
                    break;
                case 3:
                    chooseInterior();
                    break;
                case 4:
                    chooseFramework();
                    break;
                case 5:
                    choosePerformance();
                    break;
                case 6:
                {
                    selectedAddOns.clear();
                    addonCost = 0;
                    chooseAddOns();
                    break;
                }
                case 0:
                    break;
                default:
                    cout << "Invalid choice. Please try again.\n";
            }
        } while (choice != 0);
    }
};

// Billing class
class Billing
{
public:
    int calculateBill(int tyre, int interior, int framework, int performance, int addon)
    {
        return tyre + interior + framework + performance + addon;
    }

    int applyPromoCode(int totalBill, const string &promoCode)
    {
        if (promoCode == "DIWALI10")
        {
            cout << "Promo code applied! You get a 10% discount.\n";
            return totalBill * 0.9;
        }
        else if (!promoCode.empty())
        {
            cout << "Invalid promo code.\n";
        }
        return totalBill;
    }

    void processPayment(int totalBill)
    {
        int paymentChoice;
        cout << "\nSelect payment method:\n";
        cout << "1. Card\n2. UPI\n3. Cash on Delivery\n";
        cout << "Enter choice: ";
        cin >> paymentChoice;

        if (paymentChoice == 1)
        {
            string cardNumber;
            cout << "Enter your card number (16 digits): ";
            cin >> cardNumber;

            while (cardNumber.length() != 16)
            {
                cout << "Invalid card number! Please enter a valid 16-digit card number: ";
                cin >> cardNumber;
            }
            cout << "Card payment of Rs. " << totalBill << " scheduled at the time of delivery.\n";
        }
        else if (paymentChoice == 2)
        {
            string upiID;
            cout << "Enter your UPI ID: ";
            cin >> upiID;
            cout << "UPI payment of Rs. " << totalBill << " scheduled at the time of delivery.\n";
        }
        else if (paymentChoice == 3)
        {
            cout << "Cash on Delivery selected. Pay Rs. " << totalBill << " at the time of delivery.\n";
        }
        else
        {
            cout << "Invalid payment method.\n";
        }
    }
};

// Financing class
class Financing
{
public:
    void financingOptions()
    {
        cout << "\nChoose Financing Option:\n";
        cout << "1. 3 Months EMI (5% Interest)\n";
        cout << "2. 6 Months EMI (8% Interest)\n";
        cout << "3. Full Payment at Once\n";
        cout << "Enter your choice: ";
        int emiChoice;
        cin >> emiChoice;

        if (emiChoice == 1)
            cout << "3 months EMI selected. 5% interest added.\nEnter bank details.\n";
        else if (emiChoice == 2)
            cout << "6 months EMI selected. 8% interest added.\nEnter bank details.\n";
        else if (emiChoice == 3)
            cout << "Full Payment option selected. Proceeding to payment.\n";
        else
            cout << "Invalid choice.\n";
    }
};

int main()
{
    const int DELIVERY_CHARGE = 500;

    welcomeMessage();

    string customerNameFromOnline;
    string pickupDate;
    string pickupTime;
    Booking booking;
    bool wantsToContinue = booking.makeAppointment(customerNameFromOnline, pickupDate, pickupTime);

    if (!wantsToContinue)
    {
        return 0;
    }

    Customer customer;
    customer.setCustomerName(customerNameFromOnline);
    customer.getMobileNumberInput();
    customer.getUsageDurationInput();
    customer.getLocationInput();
    customer.showCustomerDetails();

    Model model;
    model.selectBrand();
    model.showBrandAndModel();

    Customization customization;
    customization.customize();
    customization.showCustomizationSummary();

    Billing billing;
    Financing financing;

    // Edit menu
    int editChoice;
    do
    {
        cout << "\nEDIT MENU (Select any option to edit or 0 to proceed to payment)\n";
        cout << "1. Edit Customer Details\n";
        cout << "2. Edit Vehicle Selection\n";
        cout << "3. Edit Customizations\n";
        cout << "0. Proceed to Payment\n";
        cout << "Enter your choice: ";
        cin >> editChoice;

        switch (editChoice)
        {
            case 1:
                customer.editCustomerDetails();
                customer.showCustomerDetails();
                break;
            case 2:
                model.editModelSelection();
                model.showBrandAndModel();
                break;
            case 3:
                customization.editCustomization();
                customization.showCustomizationSummary();
                break;
            case 0:
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }
    while (editChoice != 0);

    int total = billing.calculateBill(customization.tyreCost, customization.interiorCost,
                                    customization.frameworkCost, customization.performanceCost,
                                    customization.addonCost);
    cout << "\nTotal bill before discount and delivery: Rs. " << total << endl;

    // Add delivery charge
    total += DELIVERY_CHARGE;
    cout << "Delivery charge: Rs. " << DELIVERY_CHARGE << endl;
    cout << "Subtotal before discount: Rs. " << total << endl;

    string promoCode;
    cout << "Enter promo code for discount (if any, or press Enter to skip): ";
    cin.ignore();
    getline(cin, promoCode);
    total = billing.applyPromoCode(total, promoCode);
    cout << "\n----------------------------------------\n";
    cout << "Total bill after discount: Rs. " << total << endl;
    cout << "----------------------------------------\n";

    financing.financingOptions();
    billing.processPayment(total);

    // Display pickup information
    cout << "\n----------------------------------------\n";
    cout << "            PICKUP INFORMATION\n";
    cout << "----------------------------------------\n";
    cout << "Customer Name: " << customerNameFromOnline << "\n";
    cout << "Pickup Date: " << pickupDate << "\n";
    cout << "Pickup Time: " << formatTime(pickupTime) << "\n";
    cout << "Pickup Location: " << customer.getLocation() << "\n";
    cout << "----------------------------------------\n";

    // Display final order summary
    cout << "\n         FINAL ORDER SUMMARY:\n";
    customer.showCustomerDetails();
    model.showBrandAndModel();
    customization.showCustomizationSummary();
    cout << "---------------------------------------------------\n";
    cout << "Total Amount: Rs. " << total << " (including delivery charges)\n";
    cout << "---------------------------------------------------\n";

    int rating;
    cout << "\nPlease rate your experience (1-5 stars): ";
    cin >> rating;

    if(rating==1)
    {
        cout<<" We're sorry to hear about your experience. Please contact our customer service."<<endl;
    }
    if(rating==2)
    {
        cout<<"We'll work harder to improve your experience next time."<<endl;
    }
    if(rating==3)
    {
        cout<<"We'll strive to do better next time."<<endl;
    }
    if(rating==4)
    {
        cout<<"We're glad you enjoyed your experience with us!"<<endl;
    }
    if(rating==5)
    {
        cout<<"We're thrilled you loved your experience! Thank you for your perfect rating!"<<endl;
    }

    goodbyeMessage();

    return 0;
}
