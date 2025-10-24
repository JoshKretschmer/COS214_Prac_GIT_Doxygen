#ifndef ORDER_H
#define ORDER_H

#include "Plant.h"
#include "Memento.h"
#include <string>
#include <vector>
using namespace std;

/**
 * @file Order.h
 * @brief Implements the Order class using the Memento design pattern.
 *
 * The Order class manages a collection of Plant objects and tracks changes
 * to allow undo/redo operations. Each state snapshot is stored in a Memento.
 * @author Palesa
 * @date 2025-10-22
 */

class Memento;

/**
 * @class Order
 * @brief Represents a customer's order containing plants.
 *
 * Supports undo/redo of plant additions using Memento snapshots.
 */
class Order {
    private:
        string orderId;                  /**< Unique identifier for the order */
        vector<Plant*> plants;           /**< Plants currently in the order */
        double totalCost;                /**< Total cost of plants in the order */
        vector<Memento*> history;        /**< History of order states */
        int currIndex;                   /**< Current index in history for undo/redo */

    public:
        /** @brief Default constructor */
        Order();

        /** @brief Destructor. Cleans up plants and mementos */
        ~Order();

        /**
         * @brief Adds a plant to the order.
         * @param plant Pointer to Plant to add. The Order takes ownership.
         */
        void addPlant(Plant* plant);

        /**
         * @brief Creates a snapshot of the current order state.
         * @return Pointer to a newly allocated Memento.
         */
        Memento* createMemento();

        /**
         * @brief Returns the history of mementos.
         * @return Vector of pointers to Memento objects.
         */
        vector<Memento*>& getMementos();

        /**
         * @brief Restores the order to a previous state.
         * @param memento Pointer to Memento containing the state.
         */
        void restoreMemento(Memento* memento);

        /**
         * @brief Returns a formatted string with order details.
         * @return String containing order ID, plant list, and total cost.
         */
        string getDetails();

        /** @brief Recalculates the total cost of the order. */
        void updateCost();

        /** @brief Undoes the last addition of a plant. */
        void undoLastAddition();

        /** @brief Redoes the last undone addition of a plant. */
        void redoLastAddition();
};

#endif // ORDER_H
