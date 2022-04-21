package simpledb;

import java.io.Serializable;
import java.util.*;

/**
 * TupleDesc describes the schema of a tuple.
 */
public class TupleDesc implements Serializable {
	

//1- create a list of TDItems
	
	private List<TDItem> items = new ArrayList<TDItem>();
	
    /**
     * A help class to facilitate organizing the information of each field
     * */
    public static class TDItem implements Serializable {

        private static final long serialVersionUID = 1L;

        /**
         * The type of the field
         * */
        public final Type fieldType;
        
        /**
         * The name of the field
         * */
        public final String fieldName;

        public TDItem(Type t, String n) {
            this.fieldName = n;
            this.fieldType = t;
        }

        public String toString() {
            return fieldName + "(" + fieldType + ")";
        }
    }

    /**
     * @return
     *        An iterator which iterates over all the field TDItems
     *        that are included in this TupleDesc
     * */
    public Iterator<TDItem> iterator() {
        // some code goes here
    	//return an iterator
    	ListIterator<TDItem> lits = items.listIterator();
    	return lits;
    }

    private static final long serialVersionUID = 1L;

    /**
     * Create a new TupleDesc with typeAr.length fields with fields of the
     * specified types, with associated named fields.
     * 
     * @param typeAr
     *            array specifying the number of and types of fields in this
     *            TupleDesc. It must contain at least one entry.
     * @param fieldAr
     *            array specifying the names of the fields. Note that names may
     *            be null.
     */
    public TupleDesc(Type[] typeAr, String[] fieldAr) {
        // some code goes here
    	//2- populate the list of TDItems
    	// check for any invalid input
    	if(typeAr.length <= 0 || 
    	   fieldAr.length <=0 ||
    	   typeAr.length != fieldAr.length) return;
    	// populate items
    	for (int i = 0; i < typeAr.length; i++) {
    		items.add(new TDItem(typeAr[i], fieldAr[i]));
		}
    	
    }

    /**
     * Constructor. Create a new tuple desc with typeAr.length fields with
     * fields of the specified types, with anonymous (unnamed) fields.
     * 
     * @param typeAr
     *            array specifying the number of and types of fields in this
     *            TupleDesc. It must contain at least one entry.
     */
    public TupleDesc(Type[] typeAr) {
        // some code goes here
    	//3- populate the list of TDItems
    	// check for any invalid input
    	if(typeAr.length <= 0) return;
    	// populate items
    	for (int i = 0; i < typeAr.length; i++) {
    		items.add(new TDItem(typeAr[i], null));
		}
    }

    /**
     * @return the number of fields in this TupleDesc
     */
    public int numFields() {
        // some code goes here
        return items.size();
    }

    /**
     * Gets the (possibly null) field name of the ith field of this TupleDesc.
     * 
     * @param i
     *            index of the field name to return. It must be a valid index.
     * @return the name of the ith field
     * @throws NoSuchElementException
     *             if i is not a valid field reference.
     */
    public String getFieldName(int i) throws NoSuchElementException {
        // some code goes here
    	//4- return field name of item at index i
    	// if i is not valid, throw NoSuchElementException
    	if(i < 0 || i > items.size()) throw new NoSuchElementException();
 
    	return items.get(i).fieldName;
    }

    /**
     * Gets the type of the ith field of this TupleDesc.
     * 
     * @param i
     *            The index of the field to get the type of. It must be a valid
     *            index.
     * @return the type of the ith field
     * @throws NoSuchElementException
     *             if i is not a valid field reference.
     */
    public Type getFieldType(int i) throws NoSuchElementException {
        // some code goes here
    	//5- return field type of item at index i
    	// if i is not valid, throw NoSuchElementException
    	if(i < 0 || i > items.size()) throw new NoSuchElementException();
    	 
    	return items.get(i).fieldType;
    }

    /**
     * Find the index of the field with a given name.
     * 
     * @param name
     *            name of the field.
     * @return the index of the field that is first to have the given name.
     * @throws NoSuchElementException
     *             if no field with a matching name is found.
     */
    public int fieldNameToIndex(String name) throws NoSuchElementException {
        // some code goes here
    	// 6- return the index of item with name
    	// throw NoSuchElementException if not exist
    	if(name == null) throw new NoSuchElementException();
    	if(numFields() <= 0) throw new NoSuchElementException();
    	
    	for (int i = 0; i < items.size(); i++) {
    		if((items.get(i).fieldName != null)){
    			if(items.get(i).fieldName.equals(name)) return i;
    		}
		}
    	throw new NoSuchElementException();
    }

    /**
     * @return The size (in bytes) of tuples corresponding to this TupleDesc.
     *         Note that tuples from a given TupleDesc are of a fixed size.
     */
    public int getSize() {
    	 // some code goes here
    	//7- hint: use fieldType.getLen()    	
    	if(items.size() <= 0) return 0;
    	int totalSize = 0;
    	for (int i = 0; i < items.size(); i++) {
			totalSize += items.get(i).fieldType.getLen();	
		}
       return totalSize;
    }

    /**
     * Merge two TupleDescs into one, with td1.numFields + td2.numFields fields,
     * with the first td1.numFields coming from td1 and the remaining from td2.
     * 
     * @param td1
     *            The TupleDesc with the first fields of the new TupleDesc
     * @param td2
     *            The TupleDesc with the last fields of the TupleDesc
     * @return the new TupleDesc
     */
    public static TupleDesc merge(TupleDesc td1, TupleDesc td2) {
        // some code goes here
    	//8- Create new TupleDesc that merge both td1 and td2
    	int size = td1.numFields() + td2.numFields();
    	
    	TupleDesc mergedTuples = new TupleDesc(new Type[size]);
    	mergedTuples.items = new ArrayList<TDItem>(size);
    	
    	for (int i = 0; i < td1.numFields(); i++) {
			mergedTuples.items.add(td1.items.get(i));
		}
    	
    	for (int i = 0; i < td2.numFields(); i++) {
			mergedTuples.items.add(td2.items.get(i));
		}
    	
    	System.out.println(mergedTuples.numFields());
    	return mergedTuples;
    }

    /**
     * Compares the specified object with this TupleDesc for equality. Two
     * TupleDescs are considered equal if they have the same number of items
     * and if the i-th type in this TupleDesc is equal to the i-th type in o
     * for every i.
     * 
     * @param o
     *            the Object to be compared for equality with this TupleDesc.
     * @return true if the object is equal to this TupleDesc.
     */

    public boolean equals(Object o) {
        // some code goes here
    	//9- check type of o 
    	if(o == null) return false;
    	TupleDesc casted;
    	
    	try {
    		casted = (TupleDesc)o;
    	}catch (Exception e ) {
    		return false;
    	}
    	if(numFields() != casted.numFields()) return false;
    	
    	for (int i = 0; i < numFields(); i++) {
			if(!getFieldType(i).equals(casted.getFieldType(i))) return false;
		}
        return true;
        
        
   }

    public int hashCode() {
    	// not required for lab1
        // If you want to use TupleDesc as keys for HashMap, implement this so
        // that equal objects have equals hashCode() results
        throw new UnsupportedOperationException("unimplemented");
    }

    /**
     * Returns a String describing this descriptor. It should be of the form
     * "fieldType[0](fieldName[0]), ..., fieldType[M](fieldName[M])", although
     * the exact format does not matter.
     * 
     * @return String describing this descriptor.
     */
    public String toString() {
        // some code goes here
    	StringBuilder all = new StringBuilder();
    	for (int i = 0; i < numFields(); i++) {
			all.append(getFieldType(i) + "("+ getFieldName(i) + "), ");
		}
    	return all.toString();
    }
}
