#include <iostream>

using namespace std;

class Character {
public:
    int herbs;
    int manaPot;
    int hpPot;
    int swords[4]; // Mengubah ukuran array menjadi 4 untuk menampung pedang Excalibur
    int equippedSword;
    int hp;
    int mana;
    int damage;

    // Constructor
    Character() {
        herbs = 5;
        manaPot = 5;
        hpPot = 5;
        swords[0] = 100; // Stock sword
        swords[1] = 200; // Iron sword
        swords[2] = 300; // Mythril sword
        swords[3] = 500; // Excalibur sword
        equippedSword = 0;
        hp = 900;
        mana = 900;
        damage = swords[equippedSword];
    }

    void useHerb() {
        if (herbs > 0 && hp < 1000) {
            herbs--;
            hp += 10;
            cout << "You used herbs. HP +10." << endl;
        } else if (herbs < 1) {
            cout << "You don't have herbs." << endl;
        } else {
            cout << "You don't need to use herbs." << endl;
        }
    }

    void useHpPot() {
        if (hpPot > 1 && hp < 1000) {
            hpPot--;
            hp += 50;
            cout << "You used hp pot. HP +50." << endl;
        } else if (hpPot <= 1) {
            cout << "You don't have hp pot." << endl;
        } else {
            cout << "You don't need to use hp pot." << endl;
        }
    }

    void useManaPot() {
        if (manaPot > 1 && mana < 1000) {
            manaPot--;
            mana += 50;
            cout << "You used mana pot. Mana +50." << endl;
        } else if (manaPot <= 1) {
            cout << "You don't have mana pot." << endl;
        } else {
            cout << "You don't need to use mana pot." << endl;
        }
    }

    void changeSword(int a) {
        if (a >= 0 && a < 4) { // Mengubah batas atas menjadi 4 untuk mengakomodasi pedang Excalibur
            damage = swords[a];
            equippedSword = a;
            cout << "You equipped ";
            if(a == 0) cout << "stock sword.";
            else if(a == 1) cout << "iron sword.";
            else if(a == 2) cout << "mythril sword.";
            else if(a == 3) cout << "Excalibur sword.";
            cout << " New damage: " << damage << endl;
        } else {
            cout << "Invalid sword number." << endl;
        }
    }

    void showCharStats() { // Mengubah nama fungsi menjadi showCharStats
        cout << "=== Char Stats ===" << endl; // Mengubah nama karakter menjadi "Char"
        cout << "HP: " << hp << endl;
        cout << "Mana: " << mana << endl;
        cout << "Damage: " << damage << endl;
        cout << "Equipped Sword: ";
        if(equippedSword == 0) cout << "stock sword." << endl;
        else if(equippedSword == 1) cout << "iron sword." << endl;
        else if(equippedSword == 2) cout << "mythril sword." << endl;
        else if(equippedSword == 3) cout << "Excalibur sword." << endl;
        cout << endl;
    }

    void showCharInventory() { // Mengubah nama fungsi menjadi showCharInventory
        cout << "=== Char Inventory ===" << endl; // Mengubah nama karakter menjadi "Char"
        cout << "Herbs: " << herbs << endl;
        cout << "Mana Pot: " << manaPot << endl;
        cout << "HP Pot: " << hpPot << endl;
        cout << "Sword Inventory:" << endl;
        for (int i = 0; i < 4; ++i) {
            cout << "Sword " << i+1 << ": ";
            if (i == equippedSword)
                cout << "Used";
            else
                cout << "Not Used";
            cout << endl;
        }
        cout << endl;
    }
};

int main() {
    Character ilham;
    ilham.showCharStats(); // Menggunakan fungsi showCharStats
    ilham.showCharInventory(); // Menggunakan fungsi showCharInventory

    ilham.useHerb();
    ilham.useManaPot();
    ilham.useHpPot();

    cout << "Enter the number of the sword you want to equip (2 - 4): ";
    int choice;
    cin >> choice;
    ilham.changeSword(choice - 1);

    cout << endl;

    ilham.showCharStats(); // Menggunakan fungsi showCharStats
    ilham.showCharInventory(); // Menggunakan fungsi showCharInventory

    return 0;
}
