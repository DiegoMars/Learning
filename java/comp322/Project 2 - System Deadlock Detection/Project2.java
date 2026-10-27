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
            option = input.nextInt();
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
                                    " is not requesting to use resource " + resourceIndex + ".");
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
            default:
                System.out.println("Invalid relation value.");
        }
    }

    public static void detectDeadlock() {
        System.out.println("DETECT DEADLOCK");
    }

    public static boolean detectDeadlockRecursively(int targetIndex, int currentIndex) {
        System.out.println("DETECT DEADLOCK RECURSIVELY");
        return false;
    }
}
