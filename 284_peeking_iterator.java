// Java Iterator interface reference:
// https://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html
import java.util.*;
class PeekingIterator implements Iterator<Integer> {

    private Integer next;
    private Iterator<Integer> iter;

    public PeekingIterator(Iterator<Integer> iterator) {
        // initialize any member here.
        if (iterator.hasNext())
            next = iterator.next();
        else
            next = null;
        iter = iterator;
    }

    // Returns the next element in the iteration without advancing the iterator.
    public Integer peek() {
        return next;
    }

    // hasNext() and next() should behave the same as in the Iterator interface.
    // Override them if needed.
    @Override
    public Integer next() {
        Integer ret = null;

        if (next == null)
            return ret;

        ret = next;
        if (iter.hasNext())
            next = iter.next();
        else
            next = null;
        return ret;
    }

    @Override
    public boolean hasNext() {
        return next != null;
    }
}
