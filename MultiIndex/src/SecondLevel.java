import java.util.LinkedList;

public class SecondLevel {

	int key;
	int level;
	LinkedList<Integer> list = new LinkedList<Integer>();

	
	SecondLevel(int level) {
		this.level =  level;
		this.key = -1;
	}
	
	public Boolean isEmpty() {
		if(this.key == -1)
			return true;
		
		return false;
	}
	
	public void insert(int num) {
		// 342  341 345
		if(this.list.isEmpty()) {
			this.list.add(num);
			this.key = num;
			return;
		}
		else {
			if(num < this.key) {
				this.list.addFirst(num);
				this.key = num;
				return;
			}
			else {
				for (int i =0; i < list.size(); i++) {
					if(list.get(i) > num) {
						list.add(i, num);
						return;
					}
				}
				list.addLast(num);
			}
			
		}

	}

	public void printList() {
		for(int i=0; i <list.size();i++) {
			System.out.println(list.get(i));
		}
	}

	public void delete(int num) {
		int index = list.indexOf(num);
		
		if(list.getFirst() == list.get(index)) {
			list.remove(index);
			if(!list.isEmpty())
				this.key = list.getFirst();
		}
		else{ 
			list.remove(index);
			if(list.isEmpty()) {
				this.key =-1;
			}
		}

	}
	

	public Boolean lookup(int num, Boolean find) {
		if(this.list.isEmpty()) {
			System.out.println("Number "+ num+" not found");
			return false;
		}
		else {
			for(int i=0; i <list.size();i++) {
				System.out.println(list.get(i));
				if(list.get(i) == num) 
					return true;
			}
			if(find)
			System.out.println("Number "+ num+" not found");
			return false;
		}

	}
	

}

	