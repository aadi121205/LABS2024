#include<iostream>
using namespace std;

class Item {
    int item_id;
public:
    // Constructor with default item_id
    Item() {
        item_id = 1001;
    }
    // Constructor with parameter
    Item(int id) {
        item_id = id;
    }
    void printItemId() {
        cout << "Item ID: " << item_id << endl;
    }
};

int main() {
    Item item1;
    Item item2(5000);

    item1.printItemId();  // Should print 1001
    item2.printItemId();  // Should print 5000

    return 0;
}
