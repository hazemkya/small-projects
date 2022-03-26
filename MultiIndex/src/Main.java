import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException;
public class Main {


    public static void main(String[] args) {
    	
    	handler index = new handler();
    	
    	Boolean printEmpty = false;
    	Boolean find = true;
    	String input;
    	String path;
    	
    	int num;
        
		Scanner scanner = new Scanner(System.in);
		
		        
        printMenu();
        
       
        do {
        	System.out.println("=====================");
        	System.out.print("Input: ");
        	input = scanner.next();
        	
        	switch (input) {
        	case "insert":
        		System.out.print("Enter the element to insert: ");
        		num =scanner.nextInt();
        		if(num < 0 || num > 999) {
        			System.out.println("Number must be between 0-999");
        			break;
        		}
        		
        		insert(index, num);
        		break;
        		
        	case "file":
        		System.out.print("Type the file path: ");
        		path = scanner.next();
        		insertFile(index,path);
        		
        	case "delete":
        		System.out.print("Enter the element to delete: ");
        		num =scanner.nextInt();
        		if(num < 0 || num > 999) {
        			System.out.println("Number must be between 0-999");
        			break;
        		}
        		
        		delete(index,num);
        		break;
        		
        	case "lookup":
        		System.out.print("Enter the element to lookup: ");
        		num =scanner.nextInt();
        		if(num < 0 || num > 999) {
        			System.out.println("Number must be between 0-999");
        			break;
        		}
  
        		lookup(index, num, true);
        		break;

        	case "print":
        		System.out.print("Do you want to print empty elements (y/n)?");
        		String decision = scanner.next();
        		
        		switch (decision){
        			case "y":
        			case "Y":
        				index.printAll(true);
        				break;
        			case "n":
        			case "N":
        				index.printAll(false);
        				break;
        			default :
        		         System.out.println("Incorrect Input!");
        		         break;
        		}
        		
        		break;
        		
        	case "menu":
        		printMenu();
        		break;
        		
        	case "exit":
        		System.out.println("GOOD BYE!");
        		return;
        		
        	default :
                System.out.println("Incorrect Input!");
        	
        	}
			
		} while (true);

    }
    
    static void insert(handler ind,int num) {
    	
        FirstLevel first = ind.getLevel(num);
        SecondLevel second = first.getLevel(num);
        
        lookup(ind, num,false);

    	second.insert(num);
        System.out.println("Inserted "+ num);

    }
    
    static void delete(handler ind,int num) {
    	FirstLevel first = ind.getLevel(num);
        SecondLevel second = first.getLevel(num);
        
        Boolean found = lookup(ind, num, false);
        if(found) {
        	second.delete(num);
        	System.out.println("Deleted "+ num);
        }
        else {
        	System.out.println("Number "+num+" was not found!");
        }

    }

    static Boolean lookup(handler ind,int num, Boolean find) {
    	FirstLevel first = ind.getLevel(num);
    	
    	if(find) System.out.println("Lookup "+num);
    	
    	System.out.println("First leve key: "+ first.key);
        SecondLevel second = first.getLevel(num);
        if(second.isEmpty()) {
        	System.out.println("Second level key not found");
        	return false;
        }
        else {
            System.out.println("Second level key: "+ second.key);
            return second.lookup(num, find);
        }
        
    }

    static void printMenu() {
    	System.out.println("(insert) to insert a new element");
    	System.out.println("(file) to insert elements from a file");
    	System.out.println("(delete) to delete an element");
    	System.out.println("(lookup) to lookup an element");
    	System.out.println("(print) to print all levels");
    	System.out.println("(menu) to print this menu");
    	System.out.println("(exit) to exit");
    	
    }
    
    static void insertFile(handler ind, String path) {
    	try {
        	File file = new File(path);
        	Scanner fileReader = new Scanner(file);
        	while(fileReader.hasNextLine()) {
        		int temp = fileReader.nextInt();
        		insert(ind, temp);
        	}
        	fileReader.close();
    	} 
    	
    	catch(FileNotFoundException e) {
    		System.out.println("Coulnd't find the file.");
    		
    	}
    }
}
