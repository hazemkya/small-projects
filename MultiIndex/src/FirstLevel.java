import java.util.ArrayList;

public class FirstLevel {
	
	int key;
	int level;
	
	ArrayList<SecondLevel> levels = new ArrayList<SecondLevel>();


    FirstLevel(int level, int data) {

    	this.level = level;
    	this.key = data;
    	
    	levels.add(new SecondLevel(0));
	    levels.add(new SecondLevel(1));
	    levels.add(new SecondLevel(2));
	    levels.add(new SecondLevel(3));
	    levels.add(new SecondLevel(4));
	    levels.add(new SecondLevel(5));
	    levels.add(new SecondLevel(6));
	    levels.add(new SecondLevel(7));
	    levels.add(new SecondLevel(8));
	    levels.add(new SecondLevel(9));
    	
    }
    
    public SecondLevel getLevel(int num) {
    	int tens =(num / 10)%10;
    	
    	for(int i=0;i< this.levels.size();i++) {
    		if(this.levels.get(i).level == tens)
    			return this.levels.get(i);
    	}
    	return null; 	
    }
    
    public void printSecond(Boolean printEmpty) {
    	// print list in a second level
    	for(int i=0;i< levels.size();i++) {
    		if(printEmpty && levels.get(i).isEmpty()) {
    			System.out.println("Second Level "+ levels.get(i).key +" is empty!");
    			continue;
    		}else {
    			if(levels.get(i).isEmpty() && !printEmpty) {
            		continue;
    			}
    			else {
    			System.out.println("Second Level "+ levels.get(i).key +": ");
        		levels.get(i).printList();	}
    		}

    	}
    }
    
    public Boolean isEmpty() {
    	Boolean empty= true;
    	
    		for(int i =0; i< levels.size();i++) {
    			if(!levels.get(i).isEmpty()) {
    				empty =false;
    				break;
    			}
    		}    	
    	return empty;
    }
    
    public Boolean isEmpty(FirstLevel first) {
    	Boolean empty= true;
    		for(int i =0; i< first.levels.size();i++) {
    			if(!first.levels.get(i).isEmpty()) {
    				empty =false;
    				break;
    			}
    		}    	
    	return empty;
    }
    
    
}



