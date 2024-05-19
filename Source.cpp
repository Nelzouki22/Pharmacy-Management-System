#include <iostream>
#include <vector>
#include <string>
#include <iomanip>  // for std::setw

using namespace std;

struct Drug {
    int id;
    string name;
    double price;
    int quantity;
};

class Pharmacy {
private:
    vector<Drug> inventory;
    int next_id;

public:
    Pharmacy() : next_id(1) {}

    void addDrug() {
        Drug drug;
        drug.id = next_id++;
        cout << "Enter drug name: ";
        cin >> drug.name;
        cout << "Enter drug price: ";
        cin >> drug.price;
        cout << "Enter drug quantity: ";
        cin >> drug.quantity;
        inventory.push_back(drug);
        cout << "Drug added successfully.\n";
    }

    void updateDrug() {
        int id;
        cout << "Enter drug ID to update: ";
        cin >> id;
        for (auto& drug : inventory) {
            if (drug.id == id) {
                cout << "Enter new drug name: ";
                cin >> drug.name;
                cout << "Enter new drug price: ";
                cin >> drug.price;
                cout << "Enter new drug quantity: ";
                cin >> drug.quantity;
                cout << "Drug updated successfully.\n";
                return;
            }
        }
        cout << "Drug not found.\n";
    }

    void deleteDrug() {
        int id;
        cout << "Enter drug ID to delete: ";
        cin >> id;
        for (auto it = inventory.begin(); it != inventory.end(); ++it) {
            if (it->id == id) {
                inventory.erase(it);
                cout << "Drug deleted successfully.\n";
                return;
            }
        }
        cout << "Drug not found.\n";
    }

    void searchDrug() {
        string name;
        cout << "Enter drug name to search: ";
        cin >> name;
        for (const auto& drug : inventory) {
            if (drug.name == name) {
                cout << "ID: " << drug.id << ", Name: " << drug.name << ", Price: " << drug.price << ", Quantity: " << drug.quantity << '\n';
                return;
            }
        }
        cout << "Drug not found.\n";
    }

    void listDrugs() {
        cout << setw(10) << "ID" << setw(20) << "Name" << setw(10) << "Price" << setw(10) << "Quantity" << '\n';
        for (const auto& drug : inventory) {
            cout << setw(10) << drug.id << setw(20) << drug.name << setw(10) << drug.price << setw(10) << drug.quantity << '\n';
        }
    }
};

int main() {
    Pharmacy pharmacy;
    int choice;

    do {
        cout << "\nPharmacy Management System\n";
        cout << "1. Add Drug\n";
        cout << "2. Update Drug\n";
        cout << "3. Delete Drug\n";
        cout << "4. Search Drug\n";
        cout << "5. List All Drugs\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            pharmacy.addDrug();
            break;
        case 2:
            pharmacy.updateDrug();
            break;
        case 3:
            pharmacy.deleteDrug();
            break;
        case 4:
            pharmacy.searchDrug();
            break;
        case 5:
            pharmacy.listDrugs();
            break;
        case 0:
            cout << "Exiting...\n";
            break;
        default:
            cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}
