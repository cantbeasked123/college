#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

class Medicine {
public:
    Medicine(string name, int quantity, double price) : name(name), quantity(quantity), price(price) {}

    string getName() const {
        return name;
    }

    int getQuantity() const {
        return quantity;
    }

    double getPrice() const {
        return price;
    }

    void displayDetails() const {
        cout << "Name: " << name << "\tQuantity: " << quantity << "\tPrice: $" << fixed << setprecision(2) << price << endl;
    }

private:
    string name;
    int quantity;
    double price;
};

class Pharmacy {
public:
    void addMedicine(const Medicine& medicine) {
        medicines.push_back(medicine);
    }

    void displayInventory() const {
        cout << "Pharmacy Inventory:" << endl;
        for (const auto& medicine : medicines) {
            medicine.displayDetails();
        }
    }

    bool sellMedicine(const string& medicineName, int quantity) {
        for (auto& medicine : medicines) {
            if (medicine.getName() == medicineName) {
                if (medicine.getQuantity() >= quantity) {
                    cout << "Sold " << quantity << " units of " << medicineName << " for $" << fixed << setprecision(2) << medicine.getPrice() * quantity << endl;
                    medicine.displayDetails();
                    int medicineQuantity=quantity;
                    return true;
                } else {
                    cout << "Insufficient quantity of " << medicineName << " in stock." << endl;
                    return false;
                }
            }
        }
        cout << "Medicine not found: " << medicineName << endl;
        return false;
    }

private:
    vector<Medicine> medicines;
};

int main() {
    Pharmacy pharmacy;

    Medicine med1("Paracetamol", 100, 1.50);
    Medicine med2("Aspirin", 50, 2.00);
    Medicine med3("Cough Syrup", 75, 5.50);

    pharmacy.addMedicine(med1);
    pharmacy.addMedicine(med2);
    pharmacy.addMedicine(med3);

    pharmacy.displayInventory();

    pharmacy.sellMedicine("Paracetamol", 20);
    pharmacy.sellMedicine("Aspirin", 60);

    return 0;
}
