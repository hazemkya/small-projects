package simpledb;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.Iterator;
import java.util.List;
import java.util.ListIterator;

import simpledb.TupleDesc.TDItem;


/**
 * Tuple maintains information about the contents of a tuple. Tuples have a
 * specified schema specified by a TupleDesc object and contain Field objects
 * with the data for each field.
 */
public class Tuple implements Serializable {
	//1- a tuple consists of an array of fields, TupleDesc and RecordId
	private List<Field> fields = new ArrayList<Field>();
    private TupleDesc tupleDesc;
    private RecordId recordId;
	
    private static final long serialVersionUID = 1L;

    /**
     * Create a new tuple with the specified schema (type).
     *
     * @param td
     *            the schema of this tuple. It must be a valid TupleDesc
     *            instance with at least one field.
     */
    public Tuple(TupleDesc td) {
        // some code goes here
    	//2- assign td and initialize the array of fields
    	tupleDesc = td;
    	fields = new ArrayList<Field>(tupleDesc.numFields());;
    }

    /**
     * @return The TupleDesc representing the schema of this tuple.
     */
    public TupleDesc getTupleDesc() {
        // some code goes here
        return tupleDesc;
    }

    /**
     * @return The RecordId representing the location of this tuple on disk. May
     *         be null.
     */
    public RecordId getRecordId() {
        // some code goes here
        return recordId;
    }

    /**
     * Set the RecordId information for this tuple.
     *
     * @param rid
     *            the new RecordId for this tuple.
     */
    public void setRecordId(RecordId rid) {
        // some code goes here
    	recordId = rid;
    }

    /**
     * Change the value of the i_th field of this tuple.
     *
     * @param i
     *            index of the field to change. It must be a valid index.
     * @param f
     *            new value for the field.
     */
    public void setField(int i, Field f) {
        // some code goes here
    	// 3- set Field of i index to f
    	if (i < 0) return;
    	if(i > fields.size()) return;
    	
    	fields.add(i, f);
    }

    /**
     * @return the value of the i_th field, or null if it has not been set.
     *
     * @param i
     *            field index to return. Must be a valid index.
     */
    public Field getField(int i) {
        // some code goes here
    	if(fields.isEmpty())return null;
    	if (i < 0) return null;
    	if (i > fields.size() ) return null;

        return fields.get(i);
    }

    /**
     * Returns the contents of this Tuple as a string. Note that to pass the
     * system tests, the format needs to be as follows:
     *
     * column1\tcolumn2\tcolumn3\t...\tcolumnN
     *
     * where \t is any whitespace (except a newline)
     */
    public String toString() {
    	
        // some code goes here
    	if(fields.isEmpty()) return null;
    	
    	StringBuilder str = new StringBuilder();
    	
    	for (int i = 0; i < fields.size(); i++) {
			str.append(fields.get(i)+"\t");
		}
    	
       return str.toString();
    }

    /**
     * @return
     *        An iterator which iterates over all the fields of this tuple
     * */
    public Iterator<Field> fields()
    {
        // some code goes here
    	// 4- return an iterator of fields
    	ListIterator<Field> iter = fields.listIterator();
    	return iter;

    }

    /**
     * reset the TupleDesc of this tuple (only affecting the TupleDesc)
     * */
    public void resetTupleDesc(TupleDesc td)
    {
        // some code goes here
    	//5- reassign TupleDesc to td
    	tupleDesc = td;
    }
}
