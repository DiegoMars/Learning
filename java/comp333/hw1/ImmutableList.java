public interface ImmutableList {
    public boolean equals(final Object other);
    public int length(); // Need to implement
    public int sum(); // empty list sum is defined as 0, need to implment
    public ImmutableList append(final ImmutableList other); // Need to implement
    public boolean contains(final int value); // Need to implement
    public String toString();
    public int hashCode();
} // ImmutableList
