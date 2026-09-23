// Diego Martinez
// COMP 322 Fall 2026
// Project 1

import java.util.Scanner;

public class Project1 {
    private static Scanner input = new Scanner(System.in);
    private static Process[] table;

    public static void main(String[] args) {
        System.out.println("Enter the table size:");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input.");
            System.exit(0);
        }
        int tableSize = input.nextInt();
        input.nextLine();

        if (tableSize <= 0) {
            System.out.println("Invalid table size.");
            System.exit(0);
        }
        table = new Process[tableSize];
        for (int i = 0; i < table.length; i++) {
            table[i] = new Process();
        }
        table[0].setParentIndex(0); // Add first process to the table

        int option = 0;
        while (option != 4) {
            System.out.println();
            System.out.println("1) Print the hierarchy from the table");
            System.out.println("2) Add a child process to the hierarchy");
            System.out.println("3) Remove a process's descendants from the hierarchy");
            System.out.println("4) Quit the program");
            System.out.println("Enter selection:");
            if (input.hasNextInt()) {
                option = input.nextInt();
            } else {
                option = 0;
            }
            input.nextLine();
            switch (option) {
                case 1:
                    printHierarchy();
                    break;
                case 2:
                    addProcess();
                    break;
                case 3:
                    removeProcess();
                    break;
                case 4:
                    System.out.println("Goodbye.");
                    break;
                default:
                    System.out.println("Invalid option, try again.");
            }
        }
    }

    public static void printHierarchy() {
        System.out.println("Index\tParent\tFirst\tYounger");
        for (int i = 0; i < table.length; i++) {
            if (table[i].getParentIndex() == -1) {
                continue;
            }
            System.out.print(i + "\t" + table[i].getParentIndex() + "\t");
            if (table[i].getFirstChildIndex() != -1) {
                System.out.print(table[i].getFirstChildIndex());
            }
            System.out.print("\t");
            if (table[i].getYoungerSiblingIndex() != -1) {
                System.out.print(table[i].getYoungerSiblingIndex());
            }
            System.out.println();
        }
    }

    public static void addProcess() {
        System.out.println("Enter the parent process index for the child process:");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input.");
            input.nextLine();
            return;
        }
        int parentIndex = input.nextInt();
        input.nextLine();
        if (parentIndex < 0 || parentIndex >= table.length) {
            System.out.println("Invalid process index");
            return;
        }
        if (table[parentIndex].getParentIndex() == -1) {
            System.out.println("Process index is not active.");
            return;
        }
        int childIndex = 1;
        while (table[childIndex].getParentIndex() != -1) {
            childIndex++;
            if (childIndex == table.length) {
                System.out.println("Unable to assign an index for the child process.");
                return;
            }
        }
        table[childIndex].setParentIndex(parentIndex);
        if (table[parentIndex].getFirstChildIndex() == -1) {
            table[parentIndex].setFirstChildIndex(childIndex);
        } else {
            int youngestIndex = table[parentIndex].getFirstChildIndex();
            while (table[youngestIndex].getYoungerSiblingIndex() != -1) {
                youngestIndex = table[youngestIndex].getYoungerSiblingIndex();
            }
            table[youngestIndex].setYoungerSiblingIndex(childIndex);
        }
        System.out.println("Process " + childIndex + " was added as a child of process " + 
            parentIndex + ".");
    }

    public static void removeProcess() {
        System.out.println("Enter the parent process index whose descendants will be removed:");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input.");
            input.nextLine();
            return;
        }
        int index = input.nextInt();
        input.nextLine();
        if (index < 0 || index >= table.length) {
            System.out.println("Invalid process index");
            return;
        }
        if (table[index].getParentIndex() == -1) {
            System.out.println("Process index is not active.");
            return;
        }
        int parentIndex = table[index].getParentIndex();
        removeProcessRecursively(index);
        table[index].setParentIndex(parentIndex);
        System.out.println("All descendants of process " + index + " were removed.");
    }

    // Something is weird here, removes initial process as well
    public static void removeProcessRecursively(int currentIndex) {
        if (currentIndex == -1 || table[currentIndex].getParentIndex() == -1) {
            return;
        }
        removeProcessRecursively(table[currentIndex].getYoungerSiblingIndex());
        removeProcessRecursively(table[currentIndex].getFirstChildIndex());
        table[currentIndex].setParentIndex(-1);
        table[currentIndex].setFirstChildIndex(-1);
        table[currentIndex].setYoungerSiblingIndex(-1);
    }
}
