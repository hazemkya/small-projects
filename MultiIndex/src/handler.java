import java.util.ArrayList;

public class handler {
	
	ArrayList<FirstLevel> levels = new ArrayList<FirstLevel>();
	
	
	handler(){
	    levels.add(new FirstLevel(0, 0));
	    levels.add(new FirstLevel(1, 100));
	    levels.add(new FirstLevel(2, 200));
	    levels.add(new FirstLevel(3, 300));
	    levels.add(new FirstLevel(4, 400));
	    levels.add(new FirstLevel(5, 500));
	    levels.add(new FirstLevel(6, 600));
	    levels.add(new FirstLevel(7, 700));
	    levels.add(new FirstLevel(8, 800));
	    levels.add(new FirstLevel(9, 900));
	}

	
    FirstLevel getLevel(int num) {
    	//return the level object for the specified hundred position
        int hundred =(num / 100)%10;
        
    	for(int i=0;i< levels.size();i++) {
    		if(levels.get(i).level == hundred)
    			return levels.get(i);
    	}
    	return null;
    	
    }
    
    void printAll(Boolean printEmpty) {
    	for(int i=0;i < this.levels.size() ;i++) {
    		if(printEmpty) {
        		System.out.println("First Level "+ levels.get(i).key +": ");
        		this.levels.get(i).printSecond(printEmpty);
        		continue;
    		}
    		else {
    			if(!this.levels.get(i).isEmpty()) {
            		System.out.println("First Level "+ levels.get(i).key +": ");
            		this.levels.get(i).printSecond(printEmpty);
    			} 
    		}
    	}
    }

    
}
