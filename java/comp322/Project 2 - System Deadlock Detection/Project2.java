// Diego Martinez
// COMP 322 Fall 2026
// Project 2

import java.util.Scanner;

public class Project2 {
    public static final int EMPTY = 0;
    public static final int REQUEST = 1;
    public static final int ALLOCATE = 2;

    private static Scanner input = new Scanner(System.in);
    private static Relation[] process;

    public static void main(String[] args) {
        System.out.println("Enter the number of processes:");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input");
            System.exit(0);
        }
        int processes = input.nextInt();
        input.nextLine();

        System.out.println("Enter the number of resources:");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input");
            System.exit(0);
        }
        int resources = input.nextInt();
        input.nextLine();
        if (resources <= 0) {
            System.out.println("Invalid number of resources");
            System.exit(0);
        }

        process = new Relation[processes];
        for (int i = 0; i < process.length; i++) {
            process[i] = new Relation(resources);
        }

        // Main Loop
        int option = 0;
        while (option != 4) {
            System.out.println();
            System.out.println("1) Print the process-to-resource relations");
            System.out.println("2) Change a process-to-resource relation");
            System.out.println("3) Detect the system for deadlock");
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
                    printRelations();
                    break;
                case 2:
                    changeRelation();
                    break;
                case 3:
                    detectDeadlock();
                    break;
                case 4:
                    System.out.println("Goodbye.");
                    break;
                default:
                    System.out.println("Invalid option, try again.");
            }
        }
    }

    public static void printRelations() {
        for (int j = 0; j < process[0].getResourceLength(); j++) {
            System.out.print("\tr" + j);
        }
        System.out.println();
        for (int i = 0; i < process.length; i++) {
            System.out.print("p" + i);
            for (int j = 0; j < process[0].getResourceLength(); j++) {
                System.out.print("\t");
                if (process[i].getResource(j) != EMPTY) {
                    System.out.print(process[i].getResource(j));
                }
            }
            System.out.println();
        }
    }

    public static void changeRelation() {
        System.out.println("Enter the process index:");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input.");
            input.nextLine();
            return;
        }
        int processIndex = input.nextInt();
        input.nextLine();
        if (processIndex < 0 || processIndex >= process.length) {
            System.out.println("Invalid process index.");
            return;
        }

        System.out.println("Enter the resource index:");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input.");
            input.nextLine();
            return;
        }
        int resourceIndex = input.nextInt();
        input.nextLine();
        if (resourceIndex < 0 || resourceIndex >= process[0].getResourceLength()) {
            System.out.println("Invalid resource index.");
            return;
        }

        System.out.println("Enter the new relation (0: None, 1: P requests R, 2: P allocated R):");
        if (!input.hasNextInt()) {
            System.out.println("Invalid input.");
            input.nextLine();
            return;
        }
        int newRelation = input.nextInt();
        input.nextLine();
        switch (newRelation) {
            case EMPTY:
                process[processIndex].setResource(resourceIndex, EMPTY);
                System.out.println("There is now no relation between process " + processIndex +
                                    " and resource " + resourceIndex + ".");
                break;
            case REQUEST:
                process[processIndex].setResource(resourceIndex, REQUEST);
                System.out.println("Process " + processIndex +
                                    " is now requesting to use resource " + resourceIndex + ".");
                break;
            case ALLOCATE:
                for (int i = 0; i < process.length; i++) {
                    if (i != processIndex && process[i].getResource(resourceIndex) == ALLOCATE) {
                        System.out.println("Process " + processIndex + 
                            " cannot be allocated resource " + resourceIndex + 
                            " because process " + i + " is using it.");
                        return;
                    }
                }
                process[processIndex].setResource(resourceIndex, ALLOCATE);
                System.out.println("Process " + processIndex + " has been allocated resource " + resourceIndex + " for usage.");
                break;
            default:
                System.out.println("Invalid relation value.");
        }
    }

    public static void detectDeadlock() {
        for (int i = 0; i < process.length; i++) {
            for (int j = 0; j < process[0].getResourceLength(); j++) {
                if (process[i].getResource(j) == ALLOCATE) {
                    for (int k = 0; k < process.length; k++) {
                        if (process[k].getResource(j) == REQUEST && detectDeadlockRecursively(i, k)) {
                            System.out.println("Base:");
                            System.out.println("Process " + k + " is requesting resource " + j + ".");
                            System.out.println("Process " + i + " is allocated resource " + j + ".");
                            return;
                        }
                    }
                }
            }
        }
        System.out.println("The system is not deadlocked, and is currently safe.");
    }

    public static boolean detectDeadlockRecursively(int targetIndex, int currentIndex) {
        for (int j = 0; j < process[0].getResourceLength(); j++) {
            if (process[currentIndex].getResource(j) == ALLOCATE) {
                for (int k = 0; k < process.length; k++) {
                    if (process[k].getResource(j) == REQUEST) {
                        if (k == targetIndex) {
                            System.out.println("The system is deadlocked due to the following relations:");
                            System.out.println("Process " + k + " is requesting resource " + j + ".");
                            System.out.println("Process " + currentIndex + " is alloacted resource " + j + ".");
                            return true;
                        } else if (detectDeadlockRecursively(targetIndex, k)) {
                            System.out.println("Backtrack:");
                            System.out.println("Process " + k + " is requesting resource " + j + ".");
                            System.out.println("Process " + currentIndex + " is alloacted resource " + j + ".");
                            return true;
                        }
                    }
                }
            }
        }
        return false;
    }
}
