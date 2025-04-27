#ifndef INVENTORY
#define INVENTORY
#include <iostream>
#include <exception>
class NegativeQuantityException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot add a negative quantity of items.";
    }
};

class InsufficientStockException : public std::exception {
public:
    const char* what() const noexcept override {
        return "Cannot remove more items than available in stock.";
    }
};

class Inventory {
    private:
        int stock;
    public:
        Inventory(int initial_stock = 0) : stock(initial_stock) {
            if (initial_stock < 0) {
                throw NegativeQuantityException();
            }
        }
        void add_items(int quantity) {
            if (quantity < 0) {
                throw NegativeQuantityException();
            }
            stock += quantity;
        }
        void remove_items(int quantity) {
            if (quantity > stock) {
                throw InsufficientStockException();
            }
            stock -= quantity;
        }

        int get_stock() const {
            return stock;
        }
};
#endif